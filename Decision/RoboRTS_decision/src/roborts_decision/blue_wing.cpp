#include <ros/ros.h>

#include "executor/chassis_executor.h"


#include "example_behavior/back_boot_area_behavior.h"
#include "example_behavior/escape_behavior.h"
#include "example_behavior/chase_behavior.h"
#include "example_behavior/search_behavior.h"
#include "example_behavior/patrol_behavior.h"
#include "example_behavior/goal_behavior.h"
#include "example_behavior/reload_behavior.h"
#include "example_behavior/shield_behavior.h"
#include "example_behavior/test_behavior.h"
#include "example_behavior/ambush_behavior.h"
#include "example_behavior/attack_behavior.h"
#include "example_behavior/nn_behavior.h"
#include "example_behavior/together_behavior.h"

enum BehaviorStateEnum{
     INIT = -1,
     BACKBOOT = 0,
     CHASE=1,
     SEARCH=2,
     ESCAPE=3,
     PATROL=4,
     RELOAD=5,
     SHIELD=6,
     AMBUSH=7,
     ATTACK=8,
     NN = 9,
     TOGETHER=10

};

int main(int argc, char **argv) {
  ros::init(argc, argv, "blue_wing");
  
  
  std::string full_path = ros::package::getPath("roborts_decision") + "/config/blue_wing.prototxt";

  auto chassis_executor = new roborts_decision::ChassisExecutor;
  auto blackboard = new roborts_decision::Blackboard(full_path);

  // Behavior State Enum
  BehaviorStateEnum last_state, cur_state;
  last_state = BehaviorStateEnum::INIT;
  cur_state = BehaviorStateEnum::INIT;

  roborts_decision::BackBootAreaBehavior back_boot_area_behavior(chassis_executor, blackboard, full_path);
  roborts_decision::ChaseBehavior        chase_behavior(chassis_executor, blackboard, full_path);
  roborts_decision::SearchBehavior       search_behavior(chassis_executor, blackboard, full_path);
  roborts_decision::EscapeBehavior       escape_behavior(chassis_executor, blackboard, full_path);
  roborts_decision::PatrolBehavior       patrol_behavior(chassis_executor, blackboard, full_path);
  roborts_decision::GoalBehavior       goal_behavior(chassis_executor, blackboard);
  roborts_decision::ReloadBehavior     reload_behavior(chassis_executor, blackboard, full_path);
  roborts_decision::ShieldBehavior     shield_behavior(chassis_executor, blackboard, full_path);
  roborts_decision::TestBehavior      test_behavior(chassis_executor, blackboard, full_path);
  roborts_decision::AmbushBehavior    ambush_behavior(chassis_executor, blackboard, full_path);
  roborts_decision::AttackBehavior    attack_behavior(chassis_executor, blackboard, full_path);
  roborts_decision::NNBehavior        nn_behavior(chassis_executor, blackboard, full_path);
  roborts_decision::TogetherBehavior        together_behavior(chassis_executor, blackboard, full_path);
  ros::Rate rate(10);

  // for filter noise command
  unsigned int count=0;
  const unsigned int count_bound = 3;
  while(ros::ok()){
    ros::spinOnce();


    blackboard->IsInStuckArea();
    // shoot and dodge command when game is on!
    if (last_state != BehaviorStateEnum::ESCAPE){
        
        if (blackboard->CanDodge()) {blackboard->StartDodge(); printf("In Dodge!\n");}
        else printf("Not In Dodge!\n");
    }
    if (blackboard->CanShoot()) blackboard->Shoot(blackboard->info.shoot_hz);
    // my pose
    geometry_msgs::PoseStamped mypose = blackboard->GetRobotMapPose();
    
    // Defense with buff----------------------------------------------------------------------------------------------------------------
    if (blackboard->info.strategy == "go_buff"){
            // state decision behavior
            if (blackboard->info.remain_hp >= 400){
                // according bullet to the buff
                if (blackboard->info.remain_bullet > 0){
                    if ( (!blackboard->info.has_buff && blackboard->info.times_to_buff >0 
                        && blackboard->GetDistance(blackboard->info.ally, blackboard->info.my_shield)>= blackboard->threshold.near_dist)
                        || blackboard->info.is_shielding)
                        {
                            cur_state = BehaviorStateEnum::TOGETHER;
                      }
                    else if (!blackboard->info.has_my_enemy  && !blackboard->info.has_ally_enemy){
                        cur_state = BehaviorStateEnum::TOGETHER;
                    }
                    else{
                        if (blackboard->info.has_my_enemy || blackboard->info.valid_camera_armor ){
                            cur_state = BehaviorStateEnum::TOGETHER;
                    
                        }
                        else if(blackboard->info.has_ally_enemy){
                            cur_state = BehaviorStateEnum::TOGETHER;
                        }
                    }
                }
                // not enough bullet
                else{
                    if (last_state == BehaviorStateEnum::SHIELD  && !blackboard->info.has_buff && blackboard->info.times_to_buff>0
                       && blackboard->GetDistance(mypose, blackboard->info.my_shield)<=blackboard->threshold.near_dist
                       || blackboard->info.is_shielding){
                         cur_state = BehaviorStateEnum::TOGETHER;
                    }
                    else if ( ((blackboard->info.times_to_supply >0 
                       && (blackboard->GetDistance(blackboard->info.ally, blackboard->info.my_reload)>= blackboard->threshold.near_dist)) || blackboard->info.is_supplying
                       )
                       &&  !(blackboard->info.is_hitted && blackboard->info.remain_hp<=600)
                    ){
                        cur_state = BehaviorStateEnum::TOGETHER;
                    }
                    else{
                        cur_state = BehaviorStateEnum::TOGETHER;
                    }

                }
                
            }
            // not enought hp
            else{
                if (blackboard->info.remain_bullet > 0){
                    if (!blackboard->info.has_my_enemy  && !blackboard->info.has_ally_enemy){
                        cur_state = BehaviorStateEnum::TOGETHER;
                    }
                    else{
                        if (blackboard->info.has_my_enemy || blackboard->info.valid_camera_armor ){
                            cur_state = BehaviorStateEnum::TOGETHER;
                    
                        }
                        else if(blackboard->info.has_ally_enemy){
                            cur_state = BehaviorStateEnum::TOGETHER;
                        }
                    }
                
                }
                else if (blackboard->info.ally_remain_hp < blackboard->info.remain_hp && blackboard->info.times_to_supply >0  || blackboard->info.is_supplying){
                    cur_state = BehaviorStateEnum::TOGETHER;
                }
                else{
                    cur_state = BehaviorStateEnum::TOGETHER;
                }
            }
            
    } 
    
    
    
    // filter
    if (!(last_state == BehaviorStateEnum::RELOAD  ||  last_state == BehaviorStateEnum::SHIELD)){
        count = last_state != cur_state ? count + 1: 0;
        cur_state = count>=count_bound? cur_state: last_state;
    }
    
   
    // cancel last state
    if ( (last_state != BehaviorStateEnum::INIT && last_state != cur_state)  || blackboard->info.remain_hp<=0 ){
         switch (last_state){
            case BehaviorStateEnum::BACKBOOT:
                back_boot_area_behavior.Cancel();
                break;
            case BehaviorStateEnum::CHASE:
                chase_behavior.Cancel();
                break;
            case BehaviorStateEnum::ESCAPE:
                escape_behavior.Cancel();
                break;
            case BehaviorStateEnum::PATROL:
                patrol_behavior.Cancel();
                break;
            case BehaviorStateEnum::RELOAD:
                reload_behavior.Cancel();
                break;
            case BehaviorStateEnum::SHIELD:
                shield_behavior.Cancel();
                break;
            case BehaviorStateEnum::SEARCH:
                search_behavior.Cancel();
                break;
            case BehaviorStateEnum::AMBUSH:
                ambush_behavior.Cancel();
                break;
            case BehaviorStateEnum::ATTACK:
                attack_behavior.Cancel();
                break;
            case BehaviorStateEnum::NN:
                nn_behavior.Cancel();
                break;
			case BehaviorStateEnum::TOGETHER:
                together_behavior.Cancel();
                break;
         }
    }

    // remain hp is 0, them dead!
    if (blackboard->info.remain_hp <=0){
        ros::shutdown();
        break;
    }

    switch (cur_state){
      case BehaviorStateEnum::BACKBOOT:
          back_boot_area_behavior.Run();
          std::cout<<"BackBoot" << std::endl;
          break;
      case BehaviorStateEnum::CHASE:
          chase_behavior.Run();
          std::cout<<"CHASE" << std::endl;
          break;
      case BehaviorStateEnum::ESCAPE:
          escape_behavior.Run();
          std::cout<<"ESCAPE" << std::endl;
          break;
      case BehaviorStateEnum::PATROL:
          patrol_behavior.Run();
          std::cout<<"PATROL" << std::endl;
          break;
      case BehaviorStateEnum::RELOAD:
          reload_behavior.Run();
          std::cout<<"RELOAD" << std::endl;
          break;
      case BehaviorStateEnum::SHIELD:
          shield_behavior.Run();
          std::cout<<"SHIELD" << std::endl;
          break;
      case BehaviorStateEnum::SEARCH:
          search_behavior.Run();
          std::cout<<"SEARCH" << std::endl;
          break;
      case BehaviorStateEnum::AMBUSH:
          ambush_behavior.Run();
          std::cout<<"AMBUSH" << std::endl;
          break;
      case BehaviorStateEnum::ATTACK:
          attack_behavior.Run();
          std::cout<<"ATTACK" << std::endl;
          break;

        case BehaviorStateEnum::NN:
          nn_behavior.Run();
          std::cout<<"NN" << std::endl;
          break;
	 case BehaviorStateEnum::TOGETHER:
          together_behavior.Run();
          std::cout<<"TOGETHER" << std::endl;
          break;

    }

    last_state = cur_state;
    
    rate.sleep(); 
 
   
    
  }


  return 0;
}

