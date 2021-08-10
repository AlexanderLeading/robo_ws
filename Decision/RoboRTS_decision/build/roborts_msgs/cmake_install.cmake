# Install script for directory: /home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roborts_msgs/action" TYPE FILE FILES
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/action/LocalPlanner.action"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/action/GlobalPlanner.action"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/action/ArmorDetection.action"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roborts_msgs/msg" TYPE FILE FILES
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/LocalPlannerAction.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/LocalPlannerActionGoal.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/LocalPlannerActionResult.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/LocalPlannerActionFeedback.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/LocalPlannerGoal.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/LocalPlannerResult.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/LocalPlannerFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roborts_msgs/msg" TYPE FILE FILES
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/GlobalPlannerAction.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/GlobalPlannerActionGoal.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/GlobalPlannerActionResult.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/GlobalPlannerActionFeedback.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/GlobalPlannerGoal.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/GlobalPlannerResult.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/GlobalPlannerFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roborts_msgs/msg" TYPE FILE FILES
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/ArmorDetectionAction.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/ArmorDetectionActionGoal.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/ArmorDetectionActionResult.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/ArmorDetectionActionFeedback.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/ArmorDetectionGoal.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/ArmorDetectionResult.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roborts_msgs/msg/ArmorDetectionFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roborts_msgs/msg" TYPE FILE FILES
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/TwistAccel.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/GimbalAngle.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/GimbalRate.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/ObstacleMsg.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/ShootInfo.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/ShootState.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/ShooterCmd.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/ArmorPos.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/ArmorsPos.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/AllyPose.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/Distance.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/GimbalPID.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/TargetInfo.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/FVector.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/FusionTarget.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/Target.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/LaserTarget.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/DodgeMode.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/GimbalInfo.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/BallCollision.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roborts_msgs/msg/referee_system" TYPE FILE FILES
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system/BonusStatus.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system/GameResult.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system/GameStatus.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system/GameSurvivor.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system/ProjectileSupply.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system/RobotBonus.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system/RobotDamage.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system/RobotHeat.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system/RobotShoot.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system/RobotStatus.msg"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/msg/referee_system/SupplierStatus.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roborts_msgs/srv" TYPE FILE FILES
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/srv/GimbalMode.srv"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/srv/FricWhl.srv"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/srv/ShootCmd.srv"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roborts_msgs/cmake" TYPE FILE FILES "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/build/roborts_msgs/catkin_generated/installspace/roborts_msgs-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/include/roborts_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/roseus/ros/roborts_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/common-lisp/ros/roborts_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/share/gennodejs/ros/roborts_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/lib/python2.7/dist-packages/roborts_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/devel/lib/python2.7/dist-packages/roborts_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/build/roborts_msgs/catkin_generated/installspace/roborts_msgs.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roborts_msgs/cmake" TYPE FILE FILES "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/build/roborts_msgs/catkin_generated/installspace/roborts_msgs-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roborts_msgs/cmake" TYPE FILE FILES
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/build/roborts_msgs/catkin_generated/installspace/roborts_msgsConfig.cmake"
    "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/build/roborts_msgs/catkin_generated/installspace/roborts_msgsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roborts_msgs" TYPE FILE FILES "/home/lichangheng/robo_ws/Decision/RoboRTS_decision/src/roborts_msgs/package.xml")
endif()

