//
//  acvh_controller_mark0_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "acvh_controller_mark0".
//
//  Model version              : 1.30
//  Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
//  C++ source code generated on : Sat Apr  3 13:57:55 2021
//
//  Target selection: ert.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "ext_types.h"

// data type size table
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(uint64_T),
  sizeof(px4_Bus_actuator_armed),
  sizeof(px4_Bus_manual_control_setpoint),
  sizeof(px4_Bus_vehicle_odometry),
  sizeof(px4_Bus_sensor_baro),
  sizeof(px4_internal_block_Subscriber_T),
  sizeof(px4_internal_block_Publisher__T),
  sizeof(px4_internal_block_PWM_acvh_c_T),
  sizeof(int64_T),
  sizeof(uint64_T)
};

// data type name table
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "uint64_T",
  "px4_Bus_actuator_armed",
  "px4_Bus_manual_control_setpoint",
  "px4_Bus_vehicle_odometry",
  "px4_Bus_sensor_baro",
  "px4_internal_block_Subscriber_T",
  "px4_internal_block_Publisher__T",
  "px4_internal_block_PWM_acvh_c_T",
  "int64_T",
  "uint64_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&acvh_controller_mark0_B.In1), 17, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_B.In1_m), 16, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_B.In1_o), 18, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_B.In1_b), 15, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_B.des_yaw), 0, 0, 4 },

  { (char_T *)(&acvh_controller_mark0_B.x), 1, 0, 8 },

  { (char_T *)(&acvh_controller_mark0_B.NOT), 8, 0, 3 }
  ,

  { (char_T *)(&acvh_controller_mark0_DW.obj), 19, 0, 4 },

  { (char_T *)(&acvh_controller_mark0_DW.obj_no), 21, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_DW.obj_fm), 20, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_DW.Integrator_DSTATE), 0, 0, 12 },

  { (char_T *)(&acvh_controller_mark0_DW.IfActionSubsystem2_SubsysRanBC), 2, 0,
    8 },

  { (char_T *)(&acvh_controller_mark0_DW.Commands_MODE), 8, 0, 1 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  13U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&acvh_controller_mark0_P.DiscretePIDController1_D), 0, 0, 42 },

  { (char_T *)(&acvh_controller_mark0_P.Out1_Y0), 17, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_P.Constant_Value), 17, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_P.Out1_Y0_o), 16, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_P.Constant_Value_f), 16, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_P.Out1_Y0_p), 18, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_P.Constant_Value_i), 18, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_P.Out1_Y0_oq), 15, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_P.Constant_Value_n), 15, 0, 1 },

  { (char_T *)(&acvh_controller_mark0_P.des_yaw_Y0), 0, 0, 49 },

  { (char_T *)(&acvh_controller_mark0_P.Deadband_Start), 1, 0, 9 },

  { (char_T *)(&acvh_controller_mark0_P.Reset_Value), 8, 0, 2 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  12U,
  rtPTransitions
};

// [EOF] acvh_controller_mark0_dt.h
