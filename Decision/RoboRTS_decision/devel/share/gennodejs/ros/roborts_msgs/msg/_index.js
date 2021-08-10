
"use strict";

let LocalPlannerActionGoal = require('./LocalPlannerActionGoal.js');
let ArmorDetectionFeedback = require('./ArmorDetectionFeedback.js');
let LocalPlannerActionFeedback = require('./LocalPlannerActionFeedback.js');
let ArmorDetectionGoal = require('./ArmorDetectionGoal.js');
let ArmorDetectionActionResult = require('./ArmorDetectionActionResult.js');
let GlobalPlannerActionGoal = require('./GlobalPlannerActionGoal.js');
let LocalPlannerFeedback = require('./LocalPlannerFeedback.js');
let ArmorDetectionActionFeedback = require('./ArmorDetectionActionFeedback.js');
let LocalPlannerGoal = require('./LocalPlannerGoal.js');
let GlobalPlannerFeedback = require('./GlobalPlannerFeedback.js');
let ArmorDetectionResult = require('./ArmorDetectionResult.js');
let LocalPlannerAction = require('./LocalPlannerAction.js');
let LocalPlannerActionResult = require('./LocalPlannerActionResult.js');
let GlobalPlannerAction = require('./GlobalPlannerAction.js');
let GlobalPlannerActionResult = require('./GlobalPlannerActionResult.js');
let ArmorDetectionAction = require('./ArmorDetectionAction.js');
let GlobalPlannerActionFeedback = require('./GlobalPlannerActionFeedback.js');
let LocalPlannerResult = require('./LocalPlannerResult.js');
let GlobalPlannerResult = require('./GlobalPlannerResult.js');
let ArmorDetectionActionGoal = require('./ArmorDetectionActionGoal.js');
let GlobalPlannerGoal = require('./GlobalPlannerGoal.js');
let ArmorsPos = require('./ArmorsPos.js');
let ArmorPos = require('./ArmorPos.js');
let GimbalPID = require('./GimbalPID.js');
let FVector = require('./FVector.js');
let GimbalAngle = require('./GimbalAngle.js');
let TwistAccel = require('./TwistAccel.js');
let TargetInfo = require('./TargetInfo.js');
let ShootState = require('./ShootState.js');
let ShooterCmd = require('./ShooterCmd.js');
let ObstacleMsg = require('./ObstacleMsg.js');
let BallCollision = require('./BallCollision.js');
let DodgeMode = require('./DodgeMode.js');
let ShootInfo = require('./ShootInfo.js');
let Distance = require('./Distance.js');
let AllyPose = require('./AllyPose.js');
let LaserTarget = require('./LaserTarget.js');
let GimbalInfo = require('./GimbalInfo.js');
let GimbalRate = require('./GimbalRate.js');
let Target = require('./Target.js');
let FusionTarget = require('./FusionTarget.js');
let SupplierStatus = require('./SupplierStatus.js');
let GameResult = require('./GameResult.js');
let RobotHeat = require('./RobotHeat.js');
let RobotShoot = require('./RobotShoot.js');
let ProjectileSupply = require('./ProjectileSupply.js');
let RobotBonus = require('./RobotBonus.js');
let GameSurvivor = require('./GameSurvivor.js');
let BonusStatus = require('./BonusStatus.js');
let RobotStatus = require('./RobotStatus.js');
let RobotDamage = require('./RobotDamage.js');
let GameStatus = require('./GameStatus.js');

module.exports = {
  LocalPlannerActionGoal: LocalPlannerActionGoal,
  ArmorDetectionFeedback: ArmorDetectionFeedback,
  LocalPlannerActionFeedback: LocalPlannerActionFeedback,
  ArmorDetectionGoal: ArmorDetectionGoal,
  ArmorDetectionActionResult: ArmorDetectionActionResult,
  GlobalPlannerActionGoal: GlobalPlannerActionGoal,
  LocalPlannerFeedback: LocalPlannerFeedback,
  ArmorDetectionActionFeedback: ArmorDetectionActionFeedback,
  LocalPlannerGoal: LocalPlannerGoal,
  GlobalPlannerFeedback: GlobalPlannerFeedback,
  ArmorDetectionResult: ArmorDetectionResult,
  LocalPlannerAction: LocalPlannerAction,
  LocalPlannerActionResult: LocalPlannerActionResult,
  GlobalPlannerAction: GlobalPlannerAction,
  GlobalPlannerActionResult: GlobalPlannerActionResult,
  ArmorDetectionAction: ArmorDetectionAction,
  GlobalPlannerActionFeedback: GlobalPlannerActionFeedback,
  LocalPlannerResult: LocalPlannerResult,
  GlobalPlannerResult: GlobalPlannerResult,
  ArmorDetectionActionGoal: ArmorDetectionActionGoal,
  GlobalPlannerGoal: GlobalPlannerGoal,
  ArmorsPos: ArmorsPos,
  ArmorPos: ArmorPos,
  GimbalPID: GimbalPID,
  FVector: FVector,
  GimbalAngle: GimbalAngle,
  TwistAccel: TwistAccel,
  TargetInfo: TargetInfo,
  ShootState: ShootState,
  ShooterCmd: ShooterCmd,
  ObstacleMsg: ObstacleMsg,
  BallCollision: BallCollision,
  DodgeMode: DodgeMode,
  ShootInfo: ShootInfo,
  Distance: Distance,
  AllyPose: AllyPose,
  LaserTarget: LaserTarget,
  GimbalInfo: GimbalInfo,
  GimbalRate: GimbalRate,
  Target: Target,
  FusionTarget: FusionTarget,
  SupplierStatus: SupplierStatus,
  GameResult: GameResult,
  RobotHeat: RobotHeat,
  RobotShoot: RobotShoot,
  ProjectileSupply: ProjectileSupply,
  RobotBonus: RobotBonus,
  GameSurvivor: GameSurvivor,
  BonusStatus: BonusStatus,
  RobotStatus: RobotStatus,
  RobotDamage: RobotDamage,
  GameStatus: GameStatus,
};
