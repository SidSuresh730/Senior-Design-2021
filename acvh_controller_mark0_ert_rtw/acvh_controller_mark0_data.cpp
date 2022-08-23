//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: acvh_controller_mark0_data.cpp
//
// Code generated for Simulink model 'acvh_controller_mark0'.
//
// Model version                  : 1.30
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Sat Apr  3 13:57:55 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "acvh_controller_mark0.h"
#include "acvh_controller_mark0_private.h"

// Block parameters (default storage)
P_acvh_controller_mark0_T acvh_controller_mark0_P = {
  // Mask Parameter: DiscretePIDController1_D
  //  Referenced by: '<S191>/Derivative Gain'

  0.0,

  // Mask Parameter: Kfx_D
  //  Referenced by: '<S239>/Derivative Gain'

  0.0,

  // Mask Parameter: DiscretePIDController3_D
  //  Referenced by: '<S40>/Derivative Gain'

  0.0,

  // Mask Parameter: Kfy_D
  //  Referenced by: '<S287>/Derivative Gain'

  0.0,

  // Mask Parameter: DiscretePIDController4_D
  //  Referenced by: '<S88>/Derivative Gain'

  0.0,

  // Mask Parameter: DiscretePIDController5_D
  //  Referenced by: '<S136>/Derivative Gain'

  0.0,

  // Mask Parameter: DiscretePIDController5_I
  //  Referenced by: '<S139>/Integral Gain'

  1.0,

  // Mask Parameter: DiscretePIDController4_I
  //  Referenced by: '<S91>/Integral Gain'

  1.0,

  // Mask Parameter: Kfy_I
  //  Referenced by: '<S290>/Integral Gain'

  0.0,

  // Mask Parameter: DiscretePIDController3_I
  //  Referenced by: '<S43>/Integral Gain'

  1.0,

  // Mask Parameter: Kfx_I
  //  Referenced by: '<S242>/Integral Gain'

  0.0,

  // Mask Parameter: DiscretePIDController1_I
  //  Referenced by: '<S194>/Integral Gain'

  2.0,

  // Mask Parameter: DiscretePIDController1_InitialC
  //  Referenced by: '<S192>/Filter'

  0.0,

  // Mask Parameter: Kfx_InitialConditionForFilter
  //  Referenced by: '<S240>/Filter'

  0.0,

  // Mask Parameter: DiscretePIDController3_InitialC
  //  Referenced by: '<S41>/Filter'

  0.0,

  // Mask Parameter: Kfy_InitialConditionForFilter
  //  Referenced by: '<S288>/Filter'

  0.0,

  // Mask Parameter: DiscretePIDController4_InitialC
  //  Referenced by: '<S89>/Filter'

  0.0,

  // Mask Parameter: DiscretePIDController5_InitialC
  //  Referenced by: '<S137>/Filter'

  0.0,

  // Mask Parameter: DiscretePIDController1_Initia_g
  //  Referenced by: '<S197>/Integrator'

  0.0,

  // Mask Parameter: Kfx_InitialConditionForIntegrat
  //  Referenced by: '<S245>/Integrator'

  0.0,

  // Mask Parameter: DiscretePIDController3_Initia_k
  //  Referenced by: '<S46>/Integrator'

  0.0,

  // Mask Parameter: Kfy_InitialConditionForIntegrat
  //  Referenced by: '<S293>/Integrator'

  0.0,

  // Mask Parameter: DiscretePIDController4_Initia_p
  //  Referenced by: '<S94>/Integrator'

  0.0,

  // Mask Parameter: DiscretePIDController5_Initia_e
  //  Referenced by: '<S142>/Integrator'

  0.0,

  // Mask Parameter: DiscretePIDController3_LowerSat
  //  Referenced by: '<S53>/Saturation'

  -0.05,

  // Mask Parameter: DiscretePIDController4_LowerSat
  //  Referenced by: '<S101>/Saturation'

  -0.05,

  // Mask Parameter: DiscretePIDController5_LowerSat
  //  Referenced by: '<S149>/Saturation'

  -0.1,

  // Mask Parameter: DiscretePIDController1_N
  //  Referenced by: '<S200>/Filter Coefficient'

  100.0,

  // Mask Parameter: Kfx_N
  //  Referenced by: '<S248>/Filter Coefficient'

  100.0,

  // Mask Parameter: DiscretePIDController3_N
  //  Referenced by: '<S49>/Filter Coefficient'

  100.0,

  // Mask Parameter: Kfy_N
  //  Referenced by: '<S296>/Filter Coefficient'

  100.0,

  // Mask Parameter: DiscretePIDController4_N
  //  Referenced by: '<S97>/Filter Coefficient'

  100.0,

  // Mask Parameter: DiscretePIDController5_N
  //  Referenced by: '<S145>/Filter Coefficient'

  100.0,

  // Mask Parameter: DiscretePIDController1_P
  //  Referenced by: '<S202>/Proportional Gain'

  4.0,

  // Mask Parameter: Kfx_P
  //  Referenced by: '<S250>/Proportional Gain'

  1.8,

  // Mask Parameter: DiscretePIDController3_P
  //  Referenced by: '<S51>/Proportional Gain'

  1.0,

  // Mask Parameter: Kfy_P
  //  Referenced by: '<S298>/Proportional Gain'

  1.8,

  // Mask Parameter: DiscretePIDController4_P
  //  Referenced by: '<S99>/Proportional Gain'

  1.0,

  // Mask Parameter: DiscretePIDController5_P
  //  Referenced by: '<S147>/Proportional Gain'

  1.0,

  // Mask Parameter: DiscretePIDController3_UpperSat
  //  Referenced by: '<S53>/Saturation'

  0.05,

  // Mask Parameter: DiscretePIDController4_UpperSat
  //  Referenced by: '<S101>/Saturation'

  0.05,

  // Mask Parameter: DiscretePIDController5_UpperSat
  //  Referenced by: '<S149>/Saturation'

  0.1,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S314>/Out1'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S311>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S162>/Out1'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // r
    0.0F,                              // flaps
    0.0F,                              // aux1
    0.0F,                              // aux2
    0.0F,                              // aux3
    0.0F,                              // aux4
    0.0F,                              // aux5
    0.0F,                              // aux6
    0U,                                // mode_switch
    0U,                                // return_switch
    0U,                                // rattitude_switch
    0U,                                // posctl_switch
    0U,                                // loiter_switch
    0U,                                // acro_switch
    0U,                                // offboard_switch
    0U,                                // kill_switch
    0U,                                // arm_switch
    0U,                                // transition_switch
    0U,                                // gear_switch
    0U,                                // mode_slot
    0U,                                // data_source
    0U,                                // stab_switch
    0U,                                // man_switch

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S161>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // r
    0.0F,                              // flaps
    0.0F,                              // aux1
    0.0F,                              // aux2
    0.0F,                              // aux3
    0.0F,                              // aux4
    0.0F,                              // aux5
    0.0F,                              // aux6
    0U,                                // mode_switch
    0U,                                // return_switch
    0U,                                // rattitude_switch
    0U,                                // posctl_switch
    0U,                                // loiter_switch
    0U,                                // acro_switch
    0U,                                // offboard_switch
    0U,                                // kill_switch
    0U,                                // arm_switch
    0U,                                // transition_switch
    0U,                                // gear_switch
    0U,                                // mode_slot
    0U,                                // data_source
    0U,                                // stab_switch
    0U,                                // man_switch

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S315>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // error_count
    0U,                                // device_id
    0.0F,                              // pressure
    0.0F,                              // temperature

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S312>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // error_count
    0U,                                // device_id
    0.0F,                              // pressure
    0.0F,                              // temperature

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_oq
  //  Referenced by: '<S7>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // armed_time_ms
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    false,                             // soft_stop

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S5>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // armed_time_ms
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    false,                             // soft_stop

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: des_yaw_Y0
  //  Referenced by: '<S159>/des_yaw'

  0.0,

  // Computed Parameter: des_vx_Y0
  //  Referenced by: '<S159>/des_vx'

  0.0,

  // Computed Parameter: des_vy_Y0
  //  Referenced by: '<S159>/des_vy'

  0.0,

  // Expression: 0
  //  Referenced by: '<S159>/Constant'

  0.0,

  // Expression: 1
  //  Referenced by: '<S319>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S320>/Constant'

  1.0,

  // Expression: [1 -1 1 1;1 1 -1 1;1 -1 -1 -1;1 1 1 -1]
  //  Referenced by: '<S4>/Mixer matrix'

  { 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, 1.0,
    -1.0, -1.0 },

  // Expression: 1
  //  Referenced by: '<S4>/Constant'

  1.0,

  // Expression: -1
  //  Referenced by: '<S310>/Gain'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S10>/Saturation4'

  1.0,

  // Expression: -3
  //  Referenced by: '<S10>/Saturation4'

  -3.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S197>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S192>/Filter'

  0.001,

  // Expression: 12
  //  Referenced by: '<S10>/Saturation2'

  12.0,

  // Expression: -12
  //  Referenced by: '<S10>/Saturation2'

  -12.0,

  // Expression: 1/9.8
  //  Referenced by: '<S10>/1//g'

  0.1020408163265306,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S245>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_n
  //  Referenced by: '<S240>/Filter'

  0.001,

  // Expression: pi/4
  //  Referenced by: '<S8>/Saturation'

  0.78539816339744828,

  // Expression: -pi/4
  //  Referenced by: '<S8>/Saturation'

  -0.78539816339744828,

  // Computed Parameter: Integrator_gainval_f
  //  Referenced by: '<S46>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_e
  //  Referenced by: '<S41>/Filter'

  0.001,

  // Expression: 12
  //  Referenced by: '<S10>/Saturation3'

  12.0,

  // Expression: -12
  //  Referenced by: '<S10>/Saturation3'

  -12.0,

  // Expression: 1/9.8
  //  Referenced by: '<S10>/1//g1'

  0.1020408163265306,

  // Computed Parameter: Integrator_gainval_l
  //  Referenced by: '<S293>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_d
  //  Referenced by: '<S288>/Filter'

  0.001,

  // Expression: pi/4
  //  Referenced by: '<S8>/Saturation1'

  0.78539816339744828,

  // Expression: -pi/4
  //  Referenced by: '<S8>/Saturation1'

  -0.78539816339744828,

  // Computed Parameter: Integrator_gainval_ld
  //  Referenced by: '<S94>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_i
  //  Referenced by: '<S89>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S142>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_l
  //  Referenced by: '<S137>/Filter'

  0.001,

  // Expression: 1000
  //  Referenced by: '<S4>/Gain1'

  1000.0,

  // Computed Parameter: Deadband_Start
  //  Referenced by: '<S160>/Deadband'

  -0.05F,

  // Computed Parameter: Deadband_End
  //  Referenced by: '<S160>/Deadband'

  0.05F,

  // Computed Parameter: Gain1_Gain_p
  //  Referenced by: '<S9>/Gain1'

  0.001F,

  // Computed Parameter: Deadband1_Start
  //  Referenced by: '<S160>/Deadband1'

  -0.05F,

  // Computed Parameter: Deadband1_End
  //  Referenced by: '<S160>/Deadband1'

  0.05F,

  // Computed Parameter: Gain_Gain_n
  //  Referenced by: '<S9>/Gain'

  0.001F,

  // Computed Parameter: Deadband2_Start
  //  Referenced by: '<S160>/Deadband2'

  -0.05F,

  // Computed Parameter: Deadband2_End
  //  Referenced by: '<S160>/Deadband2'

  0.05F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S9>/Gain2'

  0.001F,

  // Computed Parameter: Reset_Value
  //  Referenced by: '<S4>/Reset'

  0,

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S1>/Constant'

  1
};

//
// File trailer for generated code.
//
// [EOF]
//
