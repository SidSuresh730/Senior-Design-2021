//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4demo_AttitudeControllerWithJoystick_quadrotor.cpp
//
// Code generated for Simulink model 'px4demo_AttitudeControllerWithJoystick_quadrotor'.
//
// Model version                  : 1.19
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Mon Apr 19 16:28:17 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px4demo_AttitudeControllerWithJoystick_quadrotor.h"
#include "px4demo_AttitudeControllerWithJoystick_quadrotor_private.h"
#include "px4demo_AttitudeControllerWithJoystick_quadrotor_dt.h"

// Block signals (default storage)
B_px4demo_AttitudeControllerW_T px4demo_AttitudeControllerWit_B;

// Block states (default storage)
DW_px4demo_AttitudeController_T px4demo_AttitudeControllerWi_DW;

// Real-time model
RT_MODEL_px4demo_AttitudeCont_T px4demo_AttitudeControllerWi_M_ =
  RT_MODEL_px4demo_AttitudeCont_T();
RT_MODEL_px4demo_AttitudeCont_T *const px4demo_AttitudeControllerWi_M =
  &px4demo_AttitudeControllerWi_M_;

// Forward declaration for local functions
static void px4demo_Attitu_SystemCore_setup(px4_internal_block_PWM_px4dem_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to "remember" which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void px4demo_AttitudeControllerWithJoystick_quadrotor_SetEventsForThisBaseStep
  (boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(px4demo_AttitudeControllerWi_M, 1));
}

//
//   This function updates active task flag for each subrate
// and rate transition flags for tasks that exchange data.
// The function assumes rate-monotonic multitasking scheduler.
// The function must be called at model base rate so that
// the generated code self-manages all its subrates and rate
// transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (px4demo_AttitudeControllerWi_M->Timing.TaskCounters.TID[1])++;
  if ((px4demo_AttitudeControllerWi_M->Timing.TaskCounters.TID[1]) > 9) {// Sample time: [0.01s, 0.0s] 
    px4demo_AttitudeControllerWi_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void px4demo_Attitu_SystemCore_setup(px4_internal_block_PWM_px4dem_T *obj,
  boolean_T varargin_1, boolean_T varargin_2)
{
  uint16_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->isMain = true;
  obj->pwmDevObj = MW_PWM_OUTPUT_MAIN_DEVICE_PATH;
  status = pwm_open(&obj->pwmDevHandler, obj->pwmDevObj,
                    &obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(static_cast<int32_T>
    (static_cast<int32_T>(obj->errorStatus) | static_cast<int32_T>(status)));
  obj->servoCount = 0;
  status = pwm_getServoCount(&obj->pwmDevHandler, &obj->servoCount);
  obj->errorStatus = static_cast<uint16_T>(static_cast<int32_T>
    (static_cast<int32_T>(obj->errorStatus) | static_cast<int32_T>(status)));
  if (varargin_1) {
    status = pwm_arm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    status = pwm_disarm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->errorStatus = static_cast<uint16_T>(static_cast<int32_T>
    (static_cast<int32_T>(obj->errorStatus) | static_cast<int32_T>(status)));
  status = pwm_setPWMRate(&obj->pwmDevHandler, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(static_cast<int32_T>
    (static_cast<int32_T>(obj->errorStatus) | static_cast<int32_T>(status)));
  obj->channelMask = 15;
  status = pwm_setChannelMask(&obj->pwmDevHandler, obj->channelMask);
  obj->errorStatus = static_cast<uint16_T>(static_cast<int32_T>
    (static_cast<int32_T>(obj->errorStatus) | static_cast<int32_T>(status)));
  status = pwm_setFailsafePWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(static_cast<int32_T>
    (static_cast<int32_T>(obj->errorStatus) | static_cast<int32_T>(status)));
  status = pwm_setDisarmedPWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain, &obj->actuatorAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(static_cast<int32_T>
    (static_cast<int32_T>(obj->errorStatus) | static_cast<int32_T>(status)));
  if (obj->isMain) {
    status = pwm_forceFailsafe(&obj->pwmDevHandler, varargin_2);
    obj->errorStatus = static_cast<uint16_T>(static_cast<int32_T>(static_cast<
      int32_T>(obj->errorStatus) | static_cast<int32_T>(status)));
    status = pwm_forceTerminateFailsafe(&obj->pwmDevHandler, false);
    obj->errorStatus = static_cast<uint16_T>(static_cast<int32_T>(static_cast<
      int32_T>(obj->errorStatus) | static_cast<int32_T>(status)));
  }

  obj->isSetupComplete = true;
}

// Model step function for TID0
void px4demo_AttitudeControllerWithJoystick_quadrotor_step0(void) // Sample time: [0.001s, 0.0s] 
{
  real_T rtb_FilterCoefficient;
  real_T rtb_Filter_m;
  real_T rtb_Product2;
  real_T rtb_Sum;
  real_T rtb_fcn3;
  int32_T i;
  real32_T tmp;
  uint16_T status;
  boolean_T b_varargout_1;
  boolean_T b_varargout_1_0;

  {                                    // Sample time: [0.001s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Reset subsysRan breadcrumbs
  srClearBC(px4demo_AttitudeControllerWi_DW.EnabledSubsystem_SubsysRanBC_g);

  // Reset subsysRan breadcrumbs
  srClearBC(px4demo_AttitudeControllerWi_DW.EnabledSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4demo_AttitudeControllerWi_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4demo_AttitudeControllerWi_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4demo_AttitudeControllerWi_DW.IfActionSubsystem2_SubsysRanBC);

  // MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S160>/In1'

  b_varargout_1 = uORB_read_step
    (px4demo_AttitudeControllerWi_DW.obj.orbMetadataObj,
     &px4demo_AttitudeControllerWi_DW.obj.eventStructObj,
     &px4demo_AttitudeControllerWit_B.b_varargout_2_m, false, 1.0);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S160>/Enable'

  if (b_varargout_1) {
    px4demo_AttitudeControllerWit_B.In1_p =
      px4demo_AttitudeControllerWit_B.b_varargout_2_m;
    srUpdateBC(px4demo_AttitudeControllerWi_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'

  // SignalConversion generated from: '<Root>/Bus Selector'
  px4demo_AttitudeControllerWit_B.z = px4demo_AttitudeControllerWit_B.In1_p.z;

  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S159>/In1'

  b_varargout_1_0 = uORB_read_step
    (px4demo_AttitudeControllerWi_DW.obj_d.orbMetadataObj,
     &px4demo_AttitudeControllerWi_DW.obj_d.eventStructObj,
     &px4demo_AttitudeControllerWit_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S159>/Enable'

  if (b_varargout_1_0) {
    px4demo_AttitudeControllerWit_B.In1 =
      px4demo_AttitudeControllerWit_B.b_varargout_2;
    srUpdateBC(px4demo_AttitudeControllerWi_DW.EnabledSubsystem_SubsysRanBC_g);
  }

  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'

  // Sqrt: '<S167>/sqrt' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S168>/Product'
  //   Product: '<S168>/Product1'
  //   Product: '<S168>/Product2'
  //   Product: '<S168>/Product3'
  //   Sum: '<S168>/Sum'

  px4demo_AttitudeControllerWit_B.Product3 = sqrt(((static_cast<real_T>
    (px4demo_AttitudeControllerWit_B.In1.q[0]) * static_cast<real_T>
    (px4demo_AttitudeControllerWit_B.In1.q[0]) + static_cast<real_T>
    (px4demo_AttitudeControllerWit_B.In1.q[1]) * static_cast<real_T>
    (px4demo_AttitudeControllerWit_B.In1.q[1])) + static_cast<real_T>
    (px4demo_AttitudeControllerWit_B.In1.q[2]) * static_cast<real_T>
    (px4demo_AttitudeControllerWit_B.In1.q[2])) + static_cast<real_T>
    (px4demo_AttitudeControllerWit_B.In1.q[3]) * static_cast<real_T>
    (px4demo_AttitudeControllerWit_B.In1.q[3]));

  // Product: '<S162>/Product' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  rtb_Filter_m = static_cast<real_T>(px4demo_AttitudeControllerWit_B.In1.q[0]) /
    px4demo_AttitudeControllerWit_B.Product3;

  // Product: '<S162>/Product1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  rtb_Sum = static_cast<real_T>(px4demo_AttitudeControllerWit_B.In1.q[1]) /
    px4demo_AttitudeControllerWit_B.Product3;

  // Product: '<S162>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  rtb_Product2 = static_cast<real_T>(px4demo_AttitudeControllerWit_B.In1.q[2]) /
    px4demo_AttitudeControllerWit_B.Product3;

  // Product: '<S162>/Product3' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4demo_AttitudeControllerWit_B.Product3 = static_cast<real_T>
    (px4demo_AttitudeControllerWit_B.In1.q[3]) /
    px4demo_AttitudeControllerWit_B.Product3;

  // Fcn: '<S5>/fcn3'
  rtb_fcn3 = (rtb_Sum * px4demo_AttitudeControllerWit_B.Product3 - rtb_Filter_m *
              rtb_Product2) * -2.0;

  // If: '<S163>/If' incorporates:
  //   Constant: '<S164>/Constant'
  //   Constant: '<S165>/Constant'

  if (rtb_fcn3 > 1.0) {
    // Outputs for IfAction SubSystem: '<S163>/If Action Subsystem' incorporates:
    //   ActionPort: '<S164>/Action Port'

    rtb_fcn3 = px4demo_AttitudeControllerWit_P.Constant_Value_lz;

    // End of Outputs for SubSystem: '<S163>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S163>/If Action Subsystem' incorporates:
    //   ActionPort: '<S164>/Action Port'

    // Update for If: '<S163>/If' incorporates:
    //   Constant: '<S164>/Constant'

    srUpdateBC(px4demo_AttitudeControllerWi_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S163>/If Action Subsystem'
  } else if (rtb_fcn3 < -1.0) {
    // Outputs for IfAction SubSystem: '<S163>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S165>/Action Port'

    rtb_fcn3 = px4demo_AttitudeControllerWit_P.Constant_Value_i;

    // End of Outputs for SubSystem: '<S163>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S163>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S165>/Action Port'

    // Update for If: '<S163>/If' incorporates:
    //   Constant: '<S165>/Constant'

    srUpdateBC(px4demo_AttitudeControllerWi_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S163>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S163>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S166>/Action Port'

    // Update for If: '<S163>/If'
    srUpdateBC(px4demo_AttitudeControllerWi_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S163>/If Action Subsystem2'
  }

  // End of If: '<S163>/If'

  // Trigonometry: '<S161>/trigFcn'
  if (rtb_fcn3 > 1.0) {
    rtb_FilterCoefficient = 1.0;
  } else if (rtb_fcn3 < -1.0) {
    rtb_FilterCoefficient = -1.0;
  } else {
    rtb_FilterCoefficient = rtb_fcn3;
  }

  // Fcn: '<S5>/fcn4'
  rtb_fcn3 = (rtb_Product2 * px4demo_AttitudeControllerWit_B.Product3 +
              rtb_Filter_m * rtb_Sum) * 2.0;

  // Fcn: '<S5>/fcn5'
  rtb_Filter_m = ((rtb_Filter_m * rtb_Filter_m - rtb_Sum * rtb_Sum) -
                  rtb_Product2 * rtb_Product2) +
    px4demo_AttitudeControllerWit_B.Product3 *
    px4demo_AttitudeControllerWit_B.Product3;

  // Trigonometry: '<S161>/Trigonometric Function3'
  rtb_Sum = rt_atan2d_snf(rtb_fcn3, rtb_Filter_m);

  // SignalConversion generated from: '<Root>/Bus Selector'
  px4demo_AttitudeControllerWit_B.x = px4demo_AttitudeControllerWit_B.In1_p.x;

  // DeadZone: '<Root>/Deadband'
  if (px4demo_AttitudeControllerWit_B.x >
      px4demo_AttitudeControllerWit_P.Deadband_End) {
    tmp = px4demo_AttitudeControllerWit_B.x -
      px4demo_AttitudeControllerWit_P.Deadband_End;
  } else if (px4demo_AttitudeControllerWit_B.x >=
             px4demo_AttitudeControllerWit_P.Deadband_Start) {
    tmp = 0.0F;
  } else {
    tmp = px4demo_AttitudeControllerWit_B.x -
      px4demo_AttitudeControllerWit_P.Deadband_Start;
  }

  // End of DeadZone: '<Root>/Deadband'

  // Sum: '<S2>/Add2' incorporates:
  //   Gain: '<S10>/Gain1'
  //   Gain: '<S2>/Gain'
  //   Trigonometry: '<S161>/trigFcn'

  rtb_fcn3 = asin(rtb_FilterCoefficient) - static_cast<real_T>
    (px4demo_AttitudeControllerWit_P.Gain_Gain * tmp *
     px4demo_AttitudeControllerWit_P.Gain1_Gain_n);

  // DiscreteIntegrator: '<S46>/Integrator' incorporates:
  //   Gain: '<S43>/Integral Gain'

  px4demo_AttitudeControllerWi_DW.Integrator_DSTATE +=
    px4demo_AttitudeControllerWit_P.PID_pitch_I * rtb_fcn3 *
    px4demo_AttitudeControllerWit_P.Integrator_gainval;

  // Gain: '<S49>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S41>/Filter'
  //   Gain: '<S40>/Derivative Gain'
  //   Sum: '<S41>/SumD'

  rtb_FilterCoefficient = (px4demo_AttitudeControllerWit_P.PID_pitch_D *
    rtb_fcn3 - px4demo_AttitudeControllerWi_DW.Filter_DSTATE) *
    px4demo_AttitudeControllerWit_P.PID_pitch_N;

  // Sum: '<S55>/Sum' incorporates:
  //   Gain: '<S51>/Proportional Gain'

  px4demo_AttitudeControllerWit_B.Saturation =
    (px4demo_AttitudeControllerWit_P.PID_pitch_P * rtb_fcn3 +
     px4demo_AttitudeControllerWi_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  // Saturate: '<S53>/Saturation'
  if (px4demo_AttitudeControllerWit_B.Saturation >
      px4demo_AttitudeControllerWit_P.PID_pitch_UpperSaturationLimit) {
    // Sum: '<S55>/Sum' incorporates:
    //   Saturate: '<S53>/Saturation'

    px4demo_AttitudeControllerWit_B.Saturation =
      px4demo_AttitudeControllerWit_P.PID_pitch_UpperSaturationLimit;
  } else {
    if (px4demo_AttitudeControllerWit_B.Saturation <
        px4demo_AttitudeControllerWit_P.PID_pitch_LowerSaturationLimit) {
      // Sum: '<S55>/Sum' incorporates:
      //   Saturate: '<S53>/Saturation'

      px4demo_AttitudeControllerWit_B.Saturation =
        px4demo_AttitudeControllerWit_P.PID_pitch_LowerSaturationLimit;
    }
  }

  // End of Saturate: '<S53>/Saturation'

  // SignalConversion generated from: '<Root>/Bus Selector'
  px4demo_AttitudeControllerWit_B.y = px4demo_AttitudeControllerWit_B.In1_p.y;

  // DeadZone: '<Root>/Deadband1'
  if (px4demo_AttitudeControllerWit_B.y >
      px4demo_AttitudeControllerWit_P.Deadband1_End) {
    tmp = px4demo_AttitudeControllerWit_B.y -
      px4demo_AttitudeControllerWit_P.Deadband1_End;
  } else if (px4demo_AttitudeControllerWit_B.y >=
             px4demo_AttitudeControllerWit_P.Deadband1_Start) {
    tmp = 0.0F;
  } else {
    tmp = px4demo_AttitudeControllerWit_B.y -
      px4demo_AttitudeControllerWit_P.Deadband1_Start;
  }

  // End of DeadZone: '<Root>/Deadband1'

  // Sum: '<S2>/Add3' incorporates:
  //   Gain: '<S11>/Gain1'
  //   Gain: '<S2>/Gain1'

  rtb_Sum -= static_cast<real_T>(px4demo_AttitudeControllerWit_P.Gain1_Gain_g *
    tmp * px4demo_AttitudeControllerWit_P.Gain1_Gain_c);

  // DiscreteIntegrator: '<S94>/Integrator' incorporates:
  //   Gain: '<S91>/Integral Gain'

  px4demo_AttitudeControllerWi_DW.Integrator_DSTATE_m +=
    px4demo_AttitudeControllerWit_P.PID_roll_I * rtb_Sum *
    px4demo_AttitudeControllerWit_P.Integrator_gainval_e;

  // Gain: '<S97>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S89>/Filter'
  //   Gain: '<S88>/Derivative Gain'
  //   Sum: '<S89>/SumD'

  rtb_fcn3 = (px4demo_AttitudeControllerWit_P.PID_roll_D * rtb_Sum -
              px4demo_AttitudeControllerWi_DW.Filter_DSTATE_d) *
    px4demo_AttitudeControllerWit_P.PID_roll_N;

  // Sum: '<S103>/Sum' incorporates:
  //   Gain: '<S99>/Proportional Gain'

  px4demo_AttitudeControllerWit_B.Saturation_f =
    (px4demo_AttitudeControllerWit_P.PID_roll_P * rtb_Sum +
     px4demo_AttitudeControllerWi_DW.Integrator_DSTATE_m) + rtb_fcn3;

  // Saturate: '<S101>/Saturation'
  if (px4demo_AttitudeControllerWit_B.Saturation_f >
      px4demo_AttitudeControllerWit_P.PID_roll_UpperSaturationLimit) {
    // Sum: '<S103>/Sum' incorporates:
    //   Saturate: '<S101>/Saturation'

    px4demo_AttitudeControllerWit_B.Saturation_f =
      px4demo_AttitudeControllerWit_P.PID_roll_UpperSaturationLimit;
  } else {
    if (px4demo_AttitudeControllerWit_B.Saturation_f <
        px4demo_AttitudeControllerWit_P.PID_roll_LowerSaturationLimit) {
      // Sum: '<S103>/Sum' incorporates:
      //   Saturate: '<S101>/Saturation'

      px4demo_AttitudeControllerWit_B.Saturation_f =
        px4demo_AttitudeControllerWit_P.PID_roll_LowerSaturationLimit;
    }
  }

  // End of Saturate: '<S101>/Saturation'

  // SignalConversion generated from: '<Root>/Bus Selector'
  px4demo_AttitudeControllerWit_B.r = px4demo_AttitudeControllerWit_B.In1_p.r;

  // DeadZone: '<Root>/Deadband2'
  if (px4demo_AttitudeControllerWit_B.r >
      px4demo_AttitudeControllerWit_P.Deadband2_End) {
    tmp = px4demo_AttitudeControllerWit_B.r -
      px4demo_AttitudeControllerWit_P.Deadband2_End;
  } else if (px4demo_AttitudeControllerWit_B.r >=
             px4demo_AttitudeControllerWit_P.Deadband2_Start) {
    tmp = 0.0F;
  } else {
    tmp = px4demo_AttitudeControllerWit_B.r -
      px4demo_AttitudeControllerWit_P.Deadband2_Start;
  }

  // End of DeadZone: '<Root>/Deadband2'

  // Sum: '<S2>/Add1' incorporates:
  //   DataTypeConversion: '<S2>/Data Type Conversion2'

  rtb_Sum = static_cast<real_T>(tmp) - static_cast<real_T>
    (px4demo_AttitudeControllerWit_B.In1.yawspeed);

  // DiscreteIntegrator: '<S142>/Integrator' incorporates:
  //   Gain: '<S139>/Integral Gain'

  px4demo_AttitudeControllerWi_DW.Integrator_DSTATE_i +=
    px4demo_AttitudeControllerWit_P.PID_yaw_rate_I * rtb_Sum *
    px4demo_AttitudeControllerWit_P.Integrator_gainval_b;

  // Gain: '<S145>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S137>/Filter'
  //   Gain: '<S136>/Derivative Gain'
  //   Sum: '<S137>/SumD'

  px4demo_AttitudeControllerWit_B.Product3 =
    (px4demo_AttitudeControllerWit_P.PID_yaw_rate_D * rtb_Sum -
     px4demo_AttitudeControllerWi_DW.Filter_DSTATE_k) *
    px4demo_AttitudeControllerWit_P.PID_yaw_rate_N;

  // Sum: '<S151>/Sum' incorporates:
  //   Gain: '<S147>/Proportional Gain'

  px4demo_AttitudeControllerWit_B.Saturation_l =
    (px4demo_AttitudeControllerWit_P.PID_yaw_rate_P * rtb_Sum +
     px4demo_AttitudeControllerWi_DW.Integrator_DSTATE_i) +
    px4demo_AttitudeControllerWit_B.Product3;

  // Saturate: '<S149>/Saturation'
  if (px4demo_AttitudeControllerWit_B.Saturation_l >
      px4demo_AttitudeControllerWit_P.PID_yaw_rate_UpperSaturationLim) {
    // Sum: '<S151>/Sum' incorporates:
    //   Saturate: '<S149>/Saturation'

    px4demo_AttitudeControllerWit_B.Saturation_l =
      px4demo_AttitudeControllerWit_P.PID_yaw_rate_UpperSaturationLim;
  } else {
    if (px4demo_AttitudeControllerWit_B.Saturation_l <
        px4demo_AttitudeControllerWit_P.PID_yaw_rate_LowerSaturationLim) {
      // Sum: '<S151>/Sum' incorporates:
      //   Saturate: '<S149>/Saturation'

      px4demo_AttitudeControllerWit_B.Saturation_l =
        px4demo_AttitudeControllerWit_P.PID_yaw_rate_LowerSaturationLim;
    }
  }

  // End of Saturate: '<S149>/Saturation'

  // SignalConversion generated from: '<S6>/Product1' incorporates:
  //   Constant: '<S6>/Constant'
  //   Sum: '<S6>/Add'

  rtb_Sum = px4demo_AttitudeControllerWit_P.Constant_Value_m + static_cast<
    real_T>(px4demo_AttitudeControllerWit_B.z);
  for (i = 0; i < 4; i++) {
    // Product: '<S6>/Product1' incorporates:
    //   Constant: '<S6>/Mixer matrix'
    //   SignalConversion generated from: '<S6>/Product1'

    rtb_Filter_m = px4demo_AttitudeControllerWit_P.Mixermatrix_Value[
      static_cast<int32_T>(i + 12)] *
      px4demo_AttitudeControllerWit_B.Saturation_l +
      (px4demo_AttitudeControllerWit_P.Mixermatrix_Value[static_cast<int32_T>(i
        + 8)] * px4demo_AttitudeControllerWit_B.Saturation_f +
       (px4demo_AttitudeControllerWit_P.Mixermatrix_Value[static_cast<int32_T>(i
         + 4)] * px4demo_AttitudeControllerWit_B.Saturation +
        px4demo_AttitudeControllerWit_P.Mixermatrix_Value[i] * rtb_Sum));

    // Gain: '<S6>/Gain1'
    rtb_Filter_m = floor(px4demo_AttitudeControllerWit_P.Gain1_Gain *
                         rtb_Filter_m);
    if (rtIsNaN(rtb_Filter_m) || rtIsInf(rtb_Filter_m)) {
      rtb_Filter_m = 0.0;
    } else {
      rtb_Filter_m = fmod(rtb_Filter_m, 65536.0);
    }

    px4demo_AttitudeControllerWit_B.Gain1_g[i] = static_cast<uint16_T>
      (rtb_Filter_m < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(
         static_cast<int32_T>(-static_cast<int32_T>(static_cast<int16_T>(
            static_cast<uint16_T>(-rtb_Filter_m)))))) : static_cast<int32_T>(
        static_cast<uint16_T>(rtb_Filter_m)));

    // End of Gain: '<S6>/Gain1'
  }

  // MATLABSystem: '<S6>/PX4 PWM Output' incorporates:
  //   Constant: '<S6>/Reset'
  //   Logic: '<S6>/NOT'

  if (!px4demo_AttitudeControllerWit_P.Reset_Value) {
    if (!px4demo_AttitudeControllerWi_DW.obj_dx.isArmed) {
      px4demo_AttitudeControllerWi_DW.obj_dx.isArmed = true;
      status = pwm_arm(&px4demo_AttitudeControllerWi_DW.obj_dx.pwmDevHandler,
                       &px4demo_AttitudeControllerWi_DW.obj_dx.armAdvertiseObj);
      px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus = static_cast<uint16_T>
        (static_cast<int32_T>(static_cast<int32_T>
          (px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus) |
          static_cast<int32_T>(status)));
    }

    for (i = 0; i < 8; i++) {
      px4demo_AttitudeControllerWit_B.b_pwmValue[i] = 0U;
    }

    px4demo_AttitudeControllerWit_B.b_pwmValue[0] =
      px4demo_AttitudeControllerWit_B.Gain1_g[0];
    px4demo_AttitudeControllerWit_B.b_pwmValue[1] =
      px4demo_AttitudeControllerWit_B.Gain1_g[1];
    px4demo_AttitudeControllerWit_B.b_pwmValue[2] =
      px4demo_AttitudeControllerWit_B.Gain1_g[2];
    px4demo_AttitudeControllerWit_B.b_pwmValue[3] =
      px4demo_AttitudeControllerWit_B.Gain1_g[3];
    status = pwm_setServo(&px4demo_AttitudeControllerWi_DW.obj_dx.pwmDevHandler,
                          px4demo_AttitudeControllerWi_DW.obj_dx.servoCount,
                          px4demo_AttitudeControllerWi_DW.obj_dx.channelMask,
                          &px4demo_AttitudeControllerWit_B.b_pwmValue[0],
                          px4demo_AttitudeControllerWi_DW.obj_dx.isMain,
                          &px4demo_AttitudeControllerWi_DW.obj_dx.actuatorAdvertiseObj);
    px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus) | static_cast<int32_T>
      (status)));
  } else {
    status = pwm_disarm(&px4demo_AttitudeControllerWi_DW.obj_dx.pwmDevHandler,
                        &px4demo_AttitudeControllerWi_DW.obj_dx.armAdvertiseObj);
    px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus) | static_cast<int32_T>
      (status)));
    px4demo_AttitudeControllerWi_DW.obj_dx.isArmed = false;
    status = pwm_resetServo
      (&px4demo_AttitudeControllerWi_DW.obj_dx.pwmDevHandler,
       px4demo_AttitudeControllerWi_DW.obj_dx.servoCount,
       px4demo_AttitudeControllerWi_DW.obj_dx.channelMask,
       px4demo_AttitudeControllerWi_DW.obj_dx.isMain,
       &px4demo_AttitudeControllerWi_DW.obj_dx.actuatorAdvertiseObj);
    px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus) | static_cast<int32_T>
      (status)));
  }

  if (px4demo_AttitudeControllerWi_DW.obj_dx.isMain) {
    status = pwm_forceFailsafe
      (&px4demo_AttitudeControllerWi_DW.obj_dx.pwmDevHandler,
       px4demo_AttitudeControllerWit_P.Reset_Value);
    px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus) | static_cast<int32_T>
      (status)));
  }

  // End of MATLABSystem: '<S6>/PX4 PWM Output'

  // Logic: '<S3>/NOT' incorporates:
  //   MATLABSystem: '<S3>/SourceBlock'

  px4demo_AttitudeControllerWit_B.NOT = !b_varargout_1_0;

  // Logic: '<S4>/NOT' incorporates:
  //   MATLABSystem: '<S4>/SourceBlock'

  px4demo_AttitudeControllerWit_B.NOT_b = !b_varargout_1;

  // Update for DiscreteIntegrator: '<S41>/Filter'
  px4demo_AttitudeControllerWi_DW.Filter_DSTATE +=
    px4demo_AttitudeControllerWit_P.Filter_gainval * rtb_FilterCoefficient;

  // Update for DiscreteIntegrator: '<S89>/Filter'
  px4demo_AttitudeControllerWi_DW.Filter_DSTATE_d +=
    px4demo_AttitudeControllerWit_P.Filter_gainval_j * rtb_fcn3;

  // Update for DiscreteIntegrator: '<S137>/Filter'
  px4demo_AttitudeControllerWi_DW.Filter_DSTATE_k +=
    px4demo_AttitudeControllerWit_P.Filter_gainval_i *
    px4demo_AttitudeControllerWit_B.Product3;

  // External mode
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)px4demo_AttitudeControllerWi_M->Timing.taskTime0);

  // signal main to stop simulation
  {                                    // Sample time: [0.001s, 0.0s]
    if ((rtmGetTFinal(px4demo_AttitudeControllerWi_M)!=-1) &&
        !((rtmGetTFinal(px4demo_AttitudeControllerWi_M)-
           px4demo_AttitudeControllerWi_M->Timing.taskTime0) >
          px4demo_AttitudeControllerWi_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(px4demo_AttitudeControllerWi_M, "Simulation finished");
    }

    if (rtmGetStopRequested(px4demo_AttitudeControllerWi_M)) {
      rtmSetErrorStatus(px4demo_AttitudeControllerWi_M, "Simulation finished");
    }
  }

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  px4demo_AttitudeControllerWi_M->Timing.taskTime0 =
    ((time_T)(++px4demo_AttitudeControllerWi_M->Timing.clockTick0)) *
    px4demo_AttitudeControllerWi_M->Timing.stepSize0;
}

// Model step function for TID1
void px4demo_AttitudeControllerWithJoystick_quadrotor_step1(void) // Sample time: [0.01s, 0.0s] 
{
  px4_Bus_actuator_armed rtb_BusAssignment;
  boolean_T b_varargout_1;

  // Reset subsysRan breadcrumbs
  srClearBC(px4demo_AttitudeControllerWi_DW.EnabledSubsystem_SubsysRanBC_c);

  // MATLABSystem: '<S7>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (px4demo_AttitudeControllerWi_DW.obj_l.orbMetadataObj,
     &px4demo_AttitudeControllerWi_DW.obj_l.eventStructObj, &rtb_BusAssignment,
     false, 1.0);

  // Logic: '<S7>/NOT' incorporates:
  //   MATLABSystem: '<S7>/SourceBlock'

  px4demo_AttitudeControllerWit_B.NOT_m = !b_varargout_1;

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  // MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  if (b_varargout_1) {
    px4demo_AttitudeControllerWit_B.In1_a = rtb_BusAssignment;
    srUpdateBC(px4demo_AttitudeControllerWi_DW.EnabledSubsystem_SubsysRanBC_c);
  }

  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'

  // BusAssignment: '<S1>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'
  //   Inport: '<S9>/In1'

  rtb_BusAssignment = px4demo_AttitudeControllerWit_B.In1_a;
  rtb_BusAssignment.armed = px4demo_AttitudeControllerWit_P.Constant_Value_a;

  // MATLABSystem: '<S8>/SinkBlock' incorporates:
  //   BusAssignment: '<S1>/Bus Assignment'

  uORB_write_step(px4demo_AttitudeControllerWi_DW.obj_e.orbMetadataObj,
                  &px4demo_AttitudeControllerWi_DW.obj_e.orbAdvertiseObj,
                  &rtb_BusAssignment);
  rtExtModeUpload(1, (real_T)((px4demo_AttitudeControllerWi_M->Timing.clockTick1)
    * 0.01));

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.01, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  px4demo_AttitudeControllerWi_M->Timing.clockTick1++;
}

// Model step wrapper function for compatibility with a static main program
void px4demo_AttitudeControllerWithJoystick_quadrotor_step(int_T tid)
{
  switch (tid) {
   case 0 :
    px4demo_AttitudeControllerWithJoystick_quadrotor_step0();
    break;

   case 1 :
    px4demo_AttitudeControllerWithJoystick_quadrotor_step1();
    break;

   default :
    break;
  }
}

// Model initialize function
void px4demo_AttitudeControllerWithJoystick_quadrotor_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(px4demo_AttitudeControllerWi_M, -1);
  px4demo_AttitudeControllerWi_M->Timing.stepSize0 = 0.001;

  // External mode info
  px4demo_AttitudeControllerWi_M->Sizes.checksums[0] = (58841269U);
  px4demo_AttitudeControllerWi_M->Sizes.checksums[1] = (1875853826U);
  px4demo_AttitudeControllerWi_M->Sizes.checksums[2] = (1955367077U);
  px4demo_AttitudeControllerWi_M->Sizes.checksums[3] = (280503276U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    px4demo_AttitudeControllerWi_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &px4demo_AttitudeControllerWi_DW.EnabledSubsystem_SubsysRanBC_c;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &px4demo_AttitudeControllerWi_DW.EnabledSubsystem_SubsysRanBC_g;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &px4demo_AttitudeControllerWi_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)
      &px4demo_AttitudeControllerWi_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &px4demo_AttitudeControllerWi_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &px4demo_AttitudeControllerWi_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(px4demo_AttitudeControllerWi_M->extModeInfo,
      &px4demo_AttitudeControllerWi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(px4demo_AttitudeControllerWi_M->extModeInfo,
                        px4demo_AttitudeControllerWi_M->Sizes.checksums);
    rteiSetTPtr(px4demo_AttitudeControllerWi_M->extModeInfo, rtmGetTPtr
                (px4demo_AttitudeControllerWi_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    px4demo_AttitudeControllerWi_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    px4_Bus_actuator_armed rtb_BusAssignment;
    boolean_T rtb_NOT;

    // InitializeConditions for DiscreteIntegrator: '<S46>/Integrator'
    px4demo_AttitudeControllerWi_DW.Integrator_DSTATE =
      px4demo_AttitudeControllerWit_P.PID_pitch_InitialConditionForIn;

    // InitializeConditions for DiscreteIntegrator: '<S41>/Filter'
    px4demo_AttitudeControllerWi_DW.Filter_DSTATE =
      px4demo_AttitudeControllerWit_P.PID_pitch_InitialConditionForFi;

    // InitializeConditions for DiscreteIntegrator: '<S94>/Integrator'
    px4demo_AttitudeControllerWi_DW.Integrator_DSTATE_m =
      px4demo_AttitudeControllerWit_P.PID_roll_InitialConditionForInt;

    // InitializeConditions for DiscreteIntegrator: '<S89>/Filter'
    px4demo_AttitudeControllerWi_DW.Filter_DSTATE_d =
      px4demo_AttitudeControllerWit_P.PID_roll_InitialConditionForFil;

    // InitializeConditions for DiscreteIntegrator: '<S142>/Integrator'
    px4demo_AttitudeControllerWi_DW.Integrator_DSTATE_i =
      px4demo_AttitudeControllerWit_P.PID_yaw_rate_InitialCondition_l;

    // InitializeConditions for DiscreteIntegrator: '<S137>/Filter'
    px4demo_AttitudeControllerWi_DW.Filter_DSTATE_k =
      px4demo_AttitudeControllerWit_P.PID_yaw_rate_InitialConditionFo;

    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S159>/Out1' incorporates:
    //   Inport: '<S159>/In1'

    px4demo_AttitudeControllerWit_B.In1 =
      px4demo_AttitudeControllerWit_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S160>/Out1' incorporates:
    //   Inport: '<S160>/In1'

    px4demo_AttitudeControllerWit_B.In1_p =
      px4demo_AttitudeControllerWit_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S9>/Out1' incorporates:
    //   Inport: '<S9>/In1'

    px4demo_AttitudeControllerWit_B.In1_a =
      px4demo_AttitudeControllerWit_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    px4demo_AttitudeControllerWi_DW.obj.matlabCodegenIsDeleted = false;
    px4demo_AttitudeControllerWi_DW.obj.isSetupComplete = false;
    px4demo_AttitudeControllerWi_DW.obj.isInitialized = 1;
    px4demo_AttitudeControllerWi_DW.obj.orbMetadataObj = ORB_ID
      (manual_control_setpoint);
    uORB_read_initialize(px4demo_AttitudeControllerWi_DW.obj.orbMetadataObj,
                         &px4demo_AttitudeControllerWi_DW.obj.eventStructObj);
    px4demo_AttitudeControllerWi_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<S3>/SourceBlock'
    px4demo_AttitudeControllerWi_DW.obj_d.matlabCodegenIsDeleted = false;
    px4demo_AttitudeControllerWi_DW.obj_d.isSetupComplete = false;
    px4demo_AttitudeControllerWi_DW.obj_d.isInitialized = 1;
    px4demo_AttitudeControllerWi_DW.obj_d.orbMetadataObj = ORB_ID
      (vehicle_odometry);
    uORB_read_initialize(px4demo_AttitudeControllerWi_DW.obj_d.orbMetadataObj,
                         &px4demo_AttitudeControllerWi_DW.obj_d.eventStructObj);
    px4demo_AttitudeControllerWi_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/PX4 PWM Output' incorporates:
    //   Constant: '<S6>/Reset'

    px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus = 0U;
    px4demo_AttitudeControllerWi_DW.obj_dx.isInitialized = 0;
    px4demo_AttitudeControllerWi_DW.obj_dx.matlabCodegenIsDeleted = false;
    px4demo_Attitu_SystemCore_setup(&px4demo_AttitudeControllerWi_DW.obj_dx,
      rtb_NOT, px4demo_AttitudeControllerWit_P.Reset_Value);

    // Start for MATLABSystem: '<S7>/SourceBlock'
    px4demo_AttitudeControllerWi_DW.obj_l.matlabCodegenIsDeleted = false;
    px4demo_AttitudeControllerWi_DW.obj_l.isSetupComplete = false;
    px4demo_AttitudeControllerWi_DW.obj_l.isInitialized = 1;
    px4demo_AttitudeControllerWi_DW.obj_l.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(px4demo_AttitudeControllerWi_DW.obj_l.orbMetadataObj,
                         &px4demo_AttitudeControllerWi_DW.obj_l.eventStructObj);
    px4demo_AttitudeControllerWi_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S8>/SinkBlock' incorporates:
    //   BusAssignment: '<S1>/Bus Assignment'

    px4demo_AttitudeControllerWi_DW.obj_e.matlabCodegenIsDeleted = false;
    px4demo_AttitudeControllerWi_DW.obj_e.isSetupComplete = false;
    px4demo_AttitudeControllerWi_DW.obj_e.isInitialized = 1;
    px4demo_AttitudeControllerWi_DW.obj_e.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_write_initialize(px4demo_AttitudeControllerWi_DW.obj_e.orbMetadataObj,
                          &px4demo_AttitudeControllerWi_DW.obj_e.orbAdvertiseObj,
                          &rtb_BusAssignment, 1);
    px4demo_AttitudeControllerWi_DW.obj_e.isSetupComplete = true;
  }
}

// Model terminate function
void px4demo_AttitudeControllerWithJoystick_quadrotor_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!px4demo_AttitudeControllerWi_DW.obj.matlabCodegenIsDeleted) {
    px4demo_AttitudeControllerWi_DW.obj.matlabCodegenIsDeleted = true;
    if ((px4demo_AttitudeControllerWi_DW.obj.isInitialized == 1) &&
        px4demo_AttitudeControllerWi_DW.obj.isSetupComplete) {
      uORB_read_terminate(&px4demo_AttitudeControllerWi_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'

  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!px4demo_AttitudeControllerWi_DW.obj_d.matlabCodegenIsDeleted) {
    px4demo_AttitudeControllerWi_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((px4demo_AttitudeControllerWi_DW.obj_d.isInitialized == 1) &&
        px4demo_AttitudeControllerWi_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&px4demo_AttitudeControllerWi_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/PX4 PWM Output'
  if (!px4demo_AttitudeControllerWi_DW.obj_dx.matlabCodegenIsDeleted) {
    px4demo_AttitudeControllerWi_DW.obj_dx.matlabCodegenIsDeleted = true;
    if ((px4demo_AttitudeControllerWi_DW.obj_dx.isInitialized == 1) &&
        px4demo_AttitudeControllerWi_DW.obj_dx.isSetupComplete) {
      status = pwm_disarm(&px4demo_AttitudeControllerWi_DW.obj_dx.pwmDevHandler,
                          &px4demo_AttitudeControllerWi_DW.obj_dx.armAdvertiseObj);
      px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus = static_cast<uint16_T>
        (static_cast<int32_T>(static_cast<int32_T>
          (px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus) |
          static_cast<int32_T>(status)));
      status = pwm_resetServo
        (&px4demo_AttitudeControllerWi_DW.obj_dx.pwmDevHandler,
         px4demo_AttitudeControllerWi_DW.obj_dx.servoCount,
         px4demo_AttitudeControllerWi_DW.obj_dx.channelMask,
         px4demo_AttitudeControllerWi_DW.obj_dx.isMain,
         &px4demo_AttitudeControllerWi_DW.obj_dx.actuatorAdvertiseObj);
      px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus = static_cast<uint16_T>
        (static_cast<int32_T>(static_cast<int32_T>
          (px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus) |
          static_cast<int32_T>(status)));
      status = pwm_close(&px4demo_AttitudeControllerWi_DW.obj_dx.pwmDevHandler,
                         &px4demo_AttitudeControllerWi_DW.obj_dx.actuatorAdvertiseObj,
                         &px4demo_AttitudeControllerWi_DW.obj_dx.armAdvertiseObj);
      px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus = static_cast<uint16_T>
        (static_cast<int32_T>(static_cast<int32_T>
          (px4demo_AttitudeControllerWi_DW.obj_dx.errorStatus) |
          static_cast<int32_T>(status)));
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/PX4 PWM Output'

  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!px4demo_AttitudeControllerWi_DW.obj_l.matlabCodegenIsDeleted) {
    px4demo_AttitudeControllerWi_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((px4demo_AttitudeControllerWi_DW.obj_l.isInitialized == 1) &&
        px4demo_AttitudeControllerWi_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&px4demo_AttitudeControllerWi_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'

  // Terminate for MATLABSystem: '<S8>/SinkBlock'
  if (!px4demo_AttitudeControllerWi_DW.obj_e.matlabCodegenIsDeleted) {
    px4demo_AttitudeControllerWi_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((px4demo_AttitudeControllerWi_DW.obj_e.isInitialized == 1) &&
        px4demo_AttitudeControllerWi_DW.obj_e.isSetupComplete) {
      uORB_write_terminate
        (&px4demo_AttitudeControllerWi_DW.obj_e.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S8>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
