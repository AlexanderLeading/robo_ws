#ifndef ROBORTS_DECISION_TOGETHER_BEHAVIOR_H
#define ROBORTS_DECISION_TOGETHER_BEHAVIOR_H

#include "io/io.h"

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

    if (executor_state != BehaviorState::RUNNING) {
      // got enemy
         geometry_msgs::PoseStamped goal;
        // printf("===============is_master")
         if (is_master){
		goal = search_region_1_[1];
         }else{
                goal = search_region_1_[0];
         }
          if (!blackboard_->IsBombAllyGoal(goal)){
              chassis_executor_->Execute(goal);
              blackboard_->SetMyGoal(goal);
          }
      
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
