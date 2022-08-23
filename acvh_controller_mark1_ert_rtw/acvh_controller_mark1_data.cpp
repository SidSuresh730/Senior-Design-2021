//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: acvh_controller_mark1_data.cpp
//
// Code generated for Simulink model 'acvh_controller_mark1'.
//
// Model version                  : 1.14
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Mon Apr 26 23:59:32 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "acvh_controller_mark1.h"
#include "acvh_controller_mark1_private.h"

// Block parameters (default storage)
P_acvh_controller_mark1_T acvh_controller_mark1_P = {
  // Mask Parameter: DiscretePIDController1_D
  //  Referenced by: '<S42>/Derivative Gain'

  -0.123220888476467,

  // Mask Parameter: Kfy_D
  //  Referenced by: '<S144>/Derivative Gain'

  -0.0240316574704006,

  // Mask Parameter: tau_roll1_D
  //  Referenced by: '<S241>/Derivative Gain'

  -0.0263229670839572,

  // Mask Parameter: Kfx_D
  //  Referenced by: '<S94>/Derivative Gain'

  -0.024031657470412,

  // Mask Parameter: tau_pitch1_D
  //  Referenced by: '<S193>/Derivative Gain'

  0.0263229670839572,

  // Mask Parameter: DiscretePIDController1_I
  //  Referenced by: '<S47>/Integral Gain'

  -0.00566953766767209,

  // Mask Parameter: tau_pitch1_I
  //  Referenced by: '<S196>/Integral Gain'

  0.0109980209644375,

  // Mask Parameter: Kfx_I
  //  Referenced by: '<S97>/Integral Gain'

  0.0739424315877928,

  // Mask Parameter: tau_roll1_I
  //  Referenced by: '<S244>/Integral Gain'

  -0.0109980209644375,

  // Mask Parameter: Kfy_I
  //  Referenced by: '<S147>/Integral Gain'

  0.0739424315877666,

  // Mask Parameter: DiscretePIDController1_InitialC
  //  Referenced by: '<S43>/Filter Differentiator TF'

  0.0,

  // Mask Parameter: Kfy_InitialConditionForFilter
  //  Referenced by: '<S145>/Filter'

  0.0,

  // Mask Parameter: tau_roll1_InitialConditionForFi
  //  Referenced by: '<S242>/Filter'

  0.0,

  // Mask Parameter: Kfx_InitialConditionForFilter
  //  Referenced by: '<S95>/Filter'

  0.0,

  // Mask Parameter: tau_pitch1_InitialConditionForF
  //  Referenced by: '<S194>/Filter'

  0.0,

  // Mask Parameter: DiscretePIDController1_Initia_j
  //  Referenced by: '<S50>/Integrator'

  0.0,

  // Mask Parameter: Kfy_InitialConditionForIntegrat
  //  Referenced by: '<S150>/Integrator'

  0.0,

  // Mask Parameter: tau_roll1_InitialConditionForIn
  //  Referenced by: '<S247>/Integrator'

  0.0,

  // Mask Parameter: Kfx_InitialConditionForIntegrat
  //  Referenced by: '<S100>/Integrator'

  0.0,

  // Mask Parameter: tau_pitch1_InitialConditionForI
  //  Referenced by: '<S199>/Integrator'

  0.0,

  // Mask Parameter: Kfy_LowerSaturationLimit
  //  Referenced by:
  //    '<S157>/Saturation'
  //    '<S143>/DeadZone'

  -0.39269908169872414,

  // Mask Parameter: tau_roll1_LowerSaturationLimit
  //  Referenced by: '<S254>/Saturation'

  -0.0005,

  // Mask Parameter: Kfx_LowerSaturationLimit
  //  Referenced by:
  //    '<S107>/Saturation'
  //    '<S93>/DeadZone'

  -0.39269908169872414,

  // Mask Parameter: tau_pitch1_LowerSaturationLimit
  //  Referenced by: '<S206>/Saturation'

  -0.0005,

  // Mask Parameter: DiscretePIDController1_N
  //  Referenced by:
  //    '<S52>/N Copy'
  //    '<S53>/Filter Coefficient'

  26.3491959083223,

  // Mask Parameter: Kfy_N
  //  Referenced by: '<S153>/Filter Coefficient'

  7.50922781087257,

  // Mask Parameter: tau_roll1_N
  //  Referenced by: '<S250>/Filter Coefficient'

  347.83750102845,

  // Mask Parameter: Kfx_N
  //  Referenced by: '<S103>/Filter Coefficient'

  7.50922781087257,

  // Mask Parameter: tau_pitch1_N
  //  Referenced by: '<S202>/Filter Coefficient'

  347.83750102845,

  // Mask Parameter: DiscretePIDController1_P
  //  Referenced by: '<S55>/Proportional Gain'

  -0.0534535340221691,

  // Mask Parameter: Kfy_P
  //  Referenced by: '<S155>/Proportional Gain'

  0.183358617742446,

  // Mask Parameter: tau_roll1_P
  //  Referenced by: '<S252>/Proportional Gain'

  -0.0543673511512337,

  // Mask Parameter: Kfx_P
  //  Referenced by: '<S105>/Proportional Gain'

  0.183358617742533,

  // Mask Parameter: tau_pitch1_P
  //  Referenced by: '<S204>/Proportional Gain'

  0.0543673511512337,

  // Mask Parameter: Kfy_UpperSaturationLimit
  //  Referenced by:
  //    '<S157>/Saturation'
  //    '<S143>/DeadZone'

  0.39269908169872414,

  // Mask Parameter: tau_roll1_UpperSaturationLimit
  //  Referenced by: '<S254>/Saturation'

  0.0005,

  // Mask Parameter: Kfx_UpperSaturationLimit
  //  Referenced by:
  //    '<S107>/Saturation'
  //    '<S93>/DeadZone'

  0.39269908169872414,

  // Mask Parameter: tau_pitch1_UpperSaturationLimit
  //  Referenced by: '<S206>/Saturation'

  0.0005,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S315>/Out1'

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
  //  Referenced by: '<S312>/Constant'

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

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S326>/Out1'

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

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S325>/Constant'

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

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S316>/Out1'

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

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S313>/Constant'

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

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S8>/Out1'

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

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S6>/Constant'

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

  // Expression: 1
  //  Referenced by: '<S320>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S321>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S43>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S91>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S141>/Constant1'

  0.0,

  // Expression: [1 -1 1 1;1 1 -1 1;1 -1 -1 -1;1 1 1 -1]
  //  Referenced by: '<S4>/Mixer matrix'

  { 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, 1.0,
    -1.0, -1.0 },

  // Expression: 1
  //  Referenced by: '<S4>/Constant'

  1.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S50>/Integrator'

  0.0005,

  // Computed Parameter: Tsamp_WtEt
  //  Referenced by: '<S45>/Tsamp'

  0.0005,

  // Expression: [1 -1]
  //  Referenced by: '<S43>/Filter Differentiator TF'

  { 1.0, -1.0 },

  // Expression: 0
  //  Referenced by: '<S5>/Constant1'

  0.0,

  // Expression: 8
  //  Referenced by: '<S2>/Saturation2'

  8.0,

  // Expression: -8
  //  Referenced by: '<S2>/Saturation2'

  -8.0,

  // Expression: 8
  //  Referenced by: '<S2>/Saturation3'

  8.0,

  // Expression: -8
  //  Referenced by: '<S2>/Saturation3'

  -8.0,

  // Expression: -1
  //  Referenced by: '<S167>/Gain'

  -1.0,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S150>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S145>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_n
  //  Referenced by: '<S247>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_p
  //  Referenced by: '<S242>/Filter'

  0.001,

  // Computed Parameter: RateLimiter4_RisingLim
  //  Referenced by: '<S2>/Rate Limiter4'

  1.0E-6,

  // Computed Parameter: RateLimiter4_FallingLim
  //  Referenced by: '<S2>/Rate Limiter4'

  -1.0E-6,

  // Expression: 0
  //  Referenced by: '<S2>/Rate Limiter4'

  0.0,

  // Computed Parameter: Integrator_gainval_c
  //  Referenced by: '<S100>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_f
  //  Referenced by: '<S95>/Filter'

  0.001,

  // Expression: -1
  //  Referenced by: '<S2>/-1'

  -1.0,

  // Computed Parameter: Integrator_gainval_p
  //  Referenced by: '<S199>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_n
  //  Referenced by: '<S194>/Filter'

  0.001,

  // Computed Parameter: RateLimiter3_RisingLim
  //  Referenced by: '<S2>/Rate Limiter3'

  1.0E-6,

  // Computed Parameter: RateLimiter3_FallingLim
  //  Referenced by: '<S2>/Rate Limiter3'

  -1.0E-6,

  // Expression: 0
  //  Referenced by: '<S2>/Rate Limiter3'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S4>/Gain1'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S91>/ZeroGain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S141>/ZeroGain'

  0.0,

  // Computed Parameter: Deadband3_Start
  //  Referenced by: '<S5>/Deadband3'

  -0.05F,

  // Computed Parameter: Deadband3_End
  //  Referenced by: '<S5>/Deadband3'

  0.05F,

  // Computed Parameter: Gain_Gain_o
  //  Referenced by: '<S5>/Gain'

  -30.0F,

  // Computed Parameter: Saturation4_UpperSat
  //  Referenced by: '<S2>/Saturation4'

  0.0F,

  // Computed Parameter: Saturation4_LowerSat
  //  Referenced by: '<S2>/Saturation4'

  -6.0F,

  // Computed Parameter: Deadband_Start
  //  Referenced by: '<S5>/Deadband'

  -0.05F,

  // Computed Parameter: Deadband_End
  //  Referenced by: '<S5>/Deadband'

  0.05F,

  // Computed Parameter: Deadband1_Start
  //  Referenced by: '<S5>/Deadband1'

  -0.05F,

  // Computed Parameter: Deadband1_End
  //  Referenced by: '<S5>/Deadband1'

  0.05F,

  // Computed Parameter: Reset_Value
  //  Referenced by: '<S4>/Reset'

  0,

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S1>/Constant'

  1
};

//
// File trailer for generated code.
//
// [EOF]
//
