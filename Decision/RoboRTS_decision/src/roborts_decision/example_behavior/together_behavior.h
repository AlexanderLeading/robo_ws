#ifndef ROBORTS_DECISION_TOGETHER_BEHAVIOR_H
#define ROBORTS_DECISION_TOGETHER_BEHAVIOR_H

#include "io/io.h"
#include "math.h"
#include "geometry_msgs/Quaternion.h"
#include "../blackboard/blackboard.h"
#include "../executor/chassis_executor.h"
#include "../behavior_tree/behavior_state.h"
#include "../proto/decision.pb.h"

#include "line_iterator.h"

namespace roborts_decision {
class TogetherBehavior {
 public:
  TogetherBehavior(ChassisExecutor* &chassis_executor,
                Blackboard* &blackboard,
                const std::string & proto_file_path) : chassis_executor_(chassis_executor),
                                                       blackboard_(blackboard) {


    last_position_.header.frame_id = "map";
    last_position_.pose.orientation.x = 0;
    last_position_.pose.orientation.y = 0;
    last_position_.pose.orientation.z = 0;
    last_position_.pose.orientation.w = 1;

    last_position_.pose.position.x = 0;
    last_position_.pose.position.y = 0;
    last_position_.pose.position.z = 0;

    search_index_ = 0;
    search_count_ = 0;
    SearchBegin = true;
    if (!LoadParam(proto_file_path)) {
      ROS_ERROR("%s can't open file", __FUNCTION__);
    }

  }

  void Run() {

    auto executor_state = Update();
    // infos 
    int mx_, my_;
    blackboard_->GetCostMap2D()->World2MapWithBoundary(blackboard_->info.my_goal.pose.position.x, blackboard_->info.my_goal.pose.position.y, mx_, my_);

    if (blackboard_->GetCostMap2D()->GetCost(mx_,my_)>=253  && executor_state == BehaviorState::RUNNING){
        chassis_executor_->Cancel();
        search_index_ = (search_index_ + 1) % search_region_1_.size();

    }

    if (executor_state != BehaviorState::RUNNING&&is_master) {
      // got enemy
         geometry_msgs::PoseStamped goal;
        // printf("===============is_master")
        float move_dst = 0.20;               //车身左右移动的距离
        geometry_msgs::PoseStamped swing_goal;

   // boot_position_.header.frame_id = "map";
   // boot_position_.pose.orientation.x = 0;
   // boot_position_.pose.orientation.y = 0;
   // boot_position_.pose.orientation.z = 0;
   // boot_position_.pose.orientation.w = 1;

   // boot_position_.pose.position.x = 0;
  //  boot_position_.pose.position.y = 0;
   // boot_position_.pose.position.z = 0;



      swing_goal.header.frame_id = "map";
      swing_goal = blackboard_->GetRobotMapPose();
      ROS_INFO("-----swing_goal.x:%f",swing_goal.pose.position.x);
      ROS_INFO("------swing_goal.y:%f",swing_goal.pose.position.y);
  
      ROS_INFO("Got pose.");
      tf::Quaternion cur_q;
      tf::quaternionMsgToTF(swing_goal.pose.orientation, cur_q);
      double r, p, y;

      tf::Matrix3x3(cur_q).getRPY(r, p, y); // 从位置信息中获取车身的角度
      ROS_INFO("Get Y:%f;%f;%f;",r,p,y);
   
    //  float move_x = asin(y) * move_dst;    // x轴方向上移动距离
   //   float move_y = -acos(y) * move_dst;   // y轴方向上移动距离
     float move_x = sin(y)* move_dst ;    // x轴方向上移动距离
      float move_y = -cos(y)* move_dst;   // y轴方向上移动距离
      swing_goal.pose.position.z = 0;
ROS_INFO("===move_x.x:%f",move_x);
      ROS_INFO("===move_y.y:%f",move_y);
      ros::Rate rate(20);

      while (ros::ok())
      {
        ROS_INFO("Is swing");
 
        // 更新 x, y 轴坐标
        swing_goal.pose.position.x += move_x;
        swing_goal.pose.position.y += move_y;
      ROS_INFO("===swing_goal.x:%f",swing_goal.pose.position.x);
      ROS_INFO("===swing_goal.y:%f",swing_goal.pose.position.y);
        chassis_executor_->Execute(swing_goal);
         blackboard_->SetMyGoal(swing_goal);
        rate.sleep();
        swing_goal.pose.position.x -= move_x;
        swing_goal.pose.position.y -= move_y;
        chassis_executor_->Execute(swing_goal);
  
      ROS_INFO("3333333swing_goal.x:%f",swing_goal.pose.position.x);
      ROS_INFO("33333333swing_goal.y:%f",swing_goal.pose.position.y);
         blackboard_->SetMyGoal(swing_goal);
        rate.sleep();
      }
        // if (is_master){
	//	goal = search_region_1_[1];
      //   }else{
      //          goal = search_region_1_[0];
      //   }
      //    if (!blackboard_->IsBombAllyGoal(goal)){
       //       chassis_executor_->Execute(goal);
      //        blackboard_->SetMyGoal(goal);
       //}
      
    }else{
        geometry_msgs::PoseStamped swing_goal;

      swing_goal.header.frame_id = "map";
      swing_goal = blackboard_->GetRobotMapPose();
      ROS_INFO("wing-----swing_goal.x:%f",swing_goal.pose.position.x);
      ROS_INFO("wing------swing_goal.y:%f",swing_goal.pose.position.y);
  
      ROS_INFO("wing-Got pose.");
      tf::Quaternion cur_q;
      tf::quaternionMsgToTF(swing_goal.pose.orientation, cur_q);
      double r, p, y;

      tf::Matrix3x3(cur_q).getRPY(r, p, y); // 从位置信息中获取车身的角度
      ROS_INFO("wing-Get Y:%f;%f;%f;",r,p,y); 
    }
  }

  void Cancel() {
    chassis_executor_->Cancel();
    SearchBegin = true;
  }

  BehaviorState Update() {
    return chassis_executor_->Update();
  }

  bool LoadParam(const std::string &proto_file_path) {
    roborts_decision::DecisionConfig decision_config;
    if (!roborts_common::ReadProtoFromTextFile(proto_file_path, &decision_config)) {
      return false;
    }
     is_master=decision_config.master();
    for (int i=0; i<decision_config.search_region_4().size();i++)
        search_region_1_.push_back(blackboard_->Point2PoseStamped(decision_config.search_region_4(i)));
    return true;
  }

  void SetLastPosition(geometry_msgs::PoseStamped last_position) {
    last_position_ = last_position;
    search_count_ = 5;
  }

  ~TogetherBehavior() = default;

 private:
  //! executor
  ChassisExecutor* const chassis_executor_;

  //! perception information
  Blackboard* const blackboard_;

  //! chase goal
  geometry_msgs::PoseStamped last_position_;

  //! search buffer
  std::vector<geometry_msgs::PoseStamped> search_region_1_;
  std::vector<geometry_msgs::PoseStamped> search_region_2_;
  std::vector<geometry_msgs::PoseStamped> search_region_3_;
  std::vector<geometry_msgs::PoseStamped> search_region_4_;
  std::vector<geometry_msgs::PoseStamped> search_region_;
  unsigned int search_count_;
  unsigned int search_index_;
  bool SearchBegin;
  bool is_master;

};
}

#endif //ROBORTS_DECISION_SEARCH_BEHAVIOR_H
