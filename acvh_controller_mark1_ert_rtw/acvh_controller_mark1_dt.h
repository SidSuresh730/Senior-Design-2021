//
//  acvh_controller_mark1_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "acvh_controller_mark1".
//
//  Model version              : 1.14
//  Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
//  C++ source code generated on : Mon Apr 26 23:59:32 2021
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
  sizeof(px4_Bus_vehicle_odometry),
  sizeof(px4_Bus_sensor_baro),
  sizeof(px4_Bus_manual_control_setpoint),
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
  "px4_Bus_vehicle_odometry",
  "px4_Bus_sensor_baro",
  "px4_Bus_manual_control_setpoint",
  "px4_internal_block_Subscriber_T",
  "px4_internal_block_Publisher__T",
  "px4_internal_block_PWM_acvh_c_T",
  "int64_T",
  "uint64_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&acvh_controller_mark1_B.In1), 16, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_B.In1_f), 18, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_B.In1_p), 17, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_B.In1_a), 15, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_B.DataTypeConversion4), 0, 0, 14 },

  { (char_T *)(&acvh_controller_mark1_B.z), 1, 0, 7 },

  { (char_T *)(&acvh_controller_mark1_B.NOT), 8, 0, 3 }
  ,

  { (char_T *)(&tau_thrust), 0, 0, 1 }
  ,

  { (char_T *)(&tau_roll), 0, 0, 1 }
  ,

  { (char_T *)(&tau_pitch), 0, 0, 1 }
  ,

  { (char_T *)(&acvh_controller_mark1_DW.obj), 19, 0, 4 },

  { (char_T *)(&acvh_controller_mark1_DW.obj_e), 21, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_DW.obj_en), 20, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_DW.Integrator_DSTATE), 0, 0, 12 },

  { (char_T *)(&acvh_controller_mark1_DW.Scope1_PWORK.LoggedData[0]), 11, 0, 12
  },

  { (char_T *)(&acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC), 2, 0, 7
  }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  16U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&acvh_controller_mark1_P.DiscretePIDController1_D), 0, 0, 38 },

  { (char_T *)(&acvh_controller_mark1_P.Out1_Y0), 16, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_P.Constant_Value), 16, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_P.Out1_Y0_f), 18, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_P.Constant_Value_n), 18, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_P.Out1_Y0_l), 17, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_P.Constant_Value_j), 17, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_P.Out1_Y0_n), 15, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_P.Constant_Value_l), 15, 0, 1 },

  { (char_T *)(&acvh_controller_mark1_P.Constant_Value_p), 0, 0, 50 },

  { (char_T *)(&acvh_controller_mark1_P.Deadband3_Start), 1, 0, 9 },

  { (char_T *)(&acvh_controller_mark1_P.Reset_Value), 8, 0, 2 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  12U,
  rtPTransitions
};

// [EOF] acvh_controller_mark1_dt.h
