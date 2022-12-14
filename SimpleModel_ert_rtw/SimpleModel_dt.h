//
//  SimpleModel_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "SimpleModel".
//
//  Model version              : 1.2
//  Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
//  C++ source code generated on : Mon Feb  8 14:30:56 2021
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
  sizeof(px4_Bus_rc_channels),
  sizeof(px4_internal_block_Subscriber_T),
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
  "px4_Bus_rc_channels",
  "px4_internal_block_Subscriber_T",
  "int64_T",
  "uint64_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&SimpleModel_B.In1), 15, 0, 1 },

  { (char_T *)(&SimpleModel_B.channels[0]), 1, 0, 18 },

  { (char_T *)(&SimpleModel_B.NOT), 8, 0, 1 }
  ,

  { (char_T *)(&SimpleModel_DW.obj), 16, 0, 1 },

  { (char_T *)(&SimpleModel_DW.EnabledSubsystem_SubsysRanBC), 2, 0, 1 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&SimpleModel_P.Out1_Y0), 15, 0, 1 },

  { (char_T *)(&SimpleModel_P.Constant_Value), 15, 0, 1 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

// [EOF] SimpleModel_dt.h
