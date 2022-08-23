//
//  px4demo_AttitudeControllerWithJoystick_quadrotor_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "px4demo_AttitudeControllerWithJoystick_quadrotor".
//
//  Model version              : 1.19
//  Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
//  C++ source code generated on : Mon Apr 19 16:28:17 2021
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
  sizeof(px4_Bus_manual_control_setpoint),
  sizeof(px4_internal_block_Subscriber_T),
  sizeof(px4_internal_block_Publisher__T),
  sizeof(px4_internal_block_PWM_px4dem_T),
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
  "px4_Bus_manual_control_setpoint",
  "px4_internal_block_Subscriber_T",
  "px4_internal_block_Publisher__T",
  "px4_internal_block_PWM_px4dem_T",
  "int64_T",
  "uint64_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&px4demo_AttitudeControllerWit_B.In1), 16, 0, 1 },

  { (char_T *)(&px4demo_AttitudeControllerWit_B.In1_p), 17, 0, 1 },

  { (char_T *)(&px4demo_AttitudeControllerWit_B.In1_a), 15, 0, 1 },

  { (char_T *)(&px4demo_AttitudeControllerWit_B.Saturation), 0, 0, 3 },

  { (char_T *)(&px4demo_AttitudeControllerWit_B.z), 1, 0, 4 },

  { (char_T *)(&px4demo_AttitudeControllerWit_B.NOT), 8, 0, 3 }
  ,

  { (char_T *)(&px4demo_AttitudeControllerWi_DW.obj), 18, 0, 3 },

  { (char_T *)(&px4demo_AttitudeControllerWi_DW.obj_dx), 20, 0, 1 },

  { (char_T *)(&px4demo_AttitudeControllerWi_DW.obj_e), 19, 0, 1 },

  { (char_T *)(&px4demo_AttitudeControllerWi_DW.Integrator_DSTATE), 0, 0, 6 },

  { (char_T *)(&px4demo_AttitudeControllerWi_DW.IfActionSubsystem2_SubsysRanBC),
    2, 0, 6 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&px4demo_AttitudeControllerWit_P.PID_pitch_D), 0, 0, 24 },

  { (char_T *)(&px4demo_AttitudeControllerWit_P.Out1_Y0), 16, 0, 1 },

  { (char_T *)(&px4demo_AttitudeControllerWit_P.Constant_Value), 16, 0, 1 },

  { (char_T *)(&px4demo_AttitudeControllerWit_P.Out1_Y0_p), 17, 0, 1 },

  { (char_T *)(&px4demo_AttitudeControllerWit_P.Constant_Value_h), 17, 0, 1 },

  { (char_T *)(&px4demo_AttitudeControllerWit_P.Out1_Y0_n), 15, 0, 1 },

  { (char_T *)(&px4demo_AttitudeControllerWit_P.Constant_Value_l), 15, 0, 1 },

  { (char_T *)(&px4demo_AttitudeControllerWit_P.Constant_Value_lz), 0, 0, 26 },

  { (char_T *)(&px4demo_AttitudeControllerWit_P.Deadband_Start), 1, 0, 10 },

  { (char_T *)(&px4demo_AttitudeControllerWit_P.Reset_Value), 8, 0, 2 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  10U,
  rtPTransitions
};

// [EOF] px4demo_AttitudeControllerWithJoystick_quadrotor_dt.h
