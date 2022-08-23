//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: acvh_controller_mark0.cpp
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
#include "acvh_controller_mark0_dt.h"

// Block signals (default storage)
B_acvh_controller_mark0_T acvh_controller_mark0_B;

// Block states (default storage)
DW_acvh_controller_mark0_T acvh_controller_mark0_DW;

// Real-time model
RT_MODEL_acvh_controller_mark_T acvh_controller_mark0_M_ =
  RT_MODEL_acvh_controller_mark_T();
RT_MODEL_acvh_controller_mark_T *const acvh_controller_mark0_M =
  &acvh_controller_mark0_M_;

// Forward declaration for local functions
static void acvh_controlle_SystemCore_setup(px4_internal_block_PWM_acvh_c_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void rate_scheduler(void);

//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (acvh_controller_mark0_M->Timing.TaskCounters.TID[1])++;
  if ((acvh_controller_mark0_M->Timing.TaskCounters.TID[1]) > 3) {// Sample time: [0.004s, 0.0s] 
    acvh_controller_mark0_M->Timing.TaskCounters.TID[1] = 0;
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

static void acvh_controlle_SystemCore_setup(px4_internal_block_PWM_acvh_c_T *obj,
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

// Model step function
void acvh_controller_mark0_step(void)
{
  real_T rtb_VectorConcatenate_idx_0;
  real_T rtb_VectorConcatenate_idx_2;
  real_T tmp;
  real_T u0;
  real_T u0_0;
  int32_T i;
  real32_T tmp_0;
  uint16_T status;
  boolean_T b_varargout_1;
  boolean_T rtb_SourceBlock_o1_p;

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC_n);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark0_DW.Commands_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC_h);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark0_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark0_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark0_DW.IfActionSubsystem2_SubsysRanBC);

  // MATLABSystem: '<S311>/SourceBlock' incorporates:
  //   Inport: '<S314>/In1'

  b_varargout_1 = uORB_read_step(acvh_controller_mark0_DW.obj_n.orbMetadataObj,
    &acvh_controller_mark0_DW.obj_n.eventStructObj,
    &acvh_controller_mark0_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S311>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S314>/Enable'

  if (b_varargout_1) {
    acvh_controller_mark0_B.In1 = acvh_controller_mark0_B.b_varargout_2;
    srUpdateBC(acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC_h);
  }

  // End of Outputs for SubSystem: '<S311>/Enabled Subsystem'

  // Sqrt: '<S322>/sqrt' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion1'
  //   Product: '<S323>/Product'
  //   Product: '<S323>/Product1'
  //   Product: '<S323>/Product2'
  //   Product: '<S323>/Product3'
  //   Sum: '<S323>/Sum'

  acvh_controller_mark0_B.Filter_h = sqrt(((static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[0]) * static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[0]) + static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[1]) * static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[1])) + static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[2]) * static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[2])) + static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[3]) * static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[3]));

  // Product: '<S317>/Product' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion1'

  acvh_controller_mark0_B.Filter_k = static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[0]) / acvh_controller_mark0_B.Filter_h;

  // Product: '<S317>/Product1' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion1'

  acvh_controller_mark0_B.ug = static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[1]) / acvh_controller_mark0_B.Filter_h;

  // Product: '<S317>/Product2' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion1'

  acvh_controller_mark0_B.Integrator_dp = static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[2]) / acvh_controller_mark0_B.Filter_h;

  // Product: '<S317>/Product3' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion1'

  acvh_controller_mark0_B.Filter_h = static_cast<real_T>
    (acvh_controller_mark0_B.In1.q[3]) / acvh_controller_mark0_B.Filter_h;

  // Fcn: '<S313>/fcn2' incorporates:
  //   Fcn: '<S313>/fcn5'

  acvh_controller_mark0_B.FilterCoefficient_o = acvh_controller_mark0_B.Filter_k
    * acvh_controller_mark0_B.Filter_k;
  acvh_controller_mark0_B.FilterCoefficient_k = acvh_controller_mark0_B.ug *
    acvh_controller_mark0_B.ug;
  acvh_controller_mark0_B.ug1 = acvh_controller_mark0_B.Integrator_dp *
    acvh_controller_mark0_B.Integrator_dp;
  acvh_controller_mark0_B.FilterCoefficient_p = acvh_controller_mark0_B.Filter_h
    * acvh_controller_mark0_B.Filter_h;

  // Trigonometry: '<S316>/Trigonometric Function1' incorporates:
  //   Fcn: '<S313>/fcn1'
  //   Fcn: '<S313>/fcn2'

  rtb_VectorConcatenate_idx_0 = rt_atan2d_snf
    ((acvh_controller_mark0_B.Integrator_dp * acvh_controller_mark0_B.Filter_h -
      acvh_controller_mark0_B.Filter_k * acvh_controller_mark0_B.ug) * -2.0,
     ((acvh_controller_mark0_B.FilterCoefficient_o -
       acvh_controller_mark0_B.FilterCoefficient_k) -
      acvh_controller_mark0_B.ug1) + acvh_controller_mark0_B.FilterCoefficient_p);

  // Fcn: '<S313>/fcn3'
  acvh_controller_mark0_B.fcn3 = (acvh_controller_mark0_B.ug *
    acvh_controller_mark0_B.Filter_h + acvh_controller_mark0_B.Filter_k *
    acvh_controller_mark0_B.Integrator_dp) * 2.0;

  // If: '<S318>/If' incorporates:
  //   Constant: '<S319>/Constant'
  //   Constant: '<S320>/Constant'

  if (acvh_controller_mark0_B.fcn3 > 1.0) {
    // Outputs for IfAction SubSystem: '<S318>/If Action Subsystem' incorporates:
    //   ActionPort: '<S319>/Action Port'

    acvh_controller_mark0_B.fcn3 = acvh_controller_mark0_P.Constant_Value_l;

    // End of Outputs for SubSystem: '<S318>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S318>/If Action Subsystem' incorporates:
    //   ActionPort: '<S319>/Action Port'

    // Update for If: '<S318>/If' incorporates:
    //   Constant: '<S319>/Constant'

    srUpdateBC(acvh_controller_mark0_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S318>/If Action Subsystem'
  } else if (acvh_controller_mark0_B.fcn3 < -1.0) {
    // Outputs for IfAction SubSystem: '<S318>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S320>/Action Port'

    acvh_controller_mark0_B.fcn3 = acvh_controller_mark0_P.Constant_Value_k;

    // End of Outputs for SubSystem: '<S318>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S318>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S320>/Action Port'

    // Update for If: '<S318>/If' incorporates:
    //   Constant: '<S320>/Constant'

    srUpdateBC(acvh_controller_mark0_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S318>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S318>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S321>/Action Port'

    // Update for If: '<S318>/If'
    srUpdateBC(acvh_controller_mark0_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S318>/If Action Subsystem2'
  }

  // End of If: '<S318>/If'

  // Trigonometry: '<S316>/trigFcn'
  if (acvh_controller_mark0_B.fcn3 > 1.0) {
    acvh_controller_mark0_B.pitch_err = 1.0;
  } else if (acvh_controller_mark0_B.fcn3 < -1.0) {
    acvh_controller_mark0_B.pitch_err = -1.0;
  } else {
    acvh_controller_mark0_B.pitch_err = acvh_controller_mark0_B.fcn3;
  }

  // Trigonometry: '<S316>/Trigonometric Function3' incorporates:
  //   Fcn: '<S313>/fcn4'
  //   Fcn: '<S313>/fcn5'

  rtb_VectorConcatenate_idx_2 = rt_atan2d_snf((acvh_controller_mark0_B.ug *
    acvh_controller_mark0_B.Integrator_dp - acvh_controller_mark0_B.Filter_k *
    acvh_controller_mark0_B.Filter_h) * -2.0,
    ((acvh_controller_mark0_B.FilterCoefficient_o +
      acvh_controller_mark0_B.FilterCoefficient_k) - acvh_controller_mark0_B.ug1)
    - acvh_controller_mark0_B.FilterCoefficient_p);

  // Trigonometry: '<S310>/Trigonometric Function1'
  acvh_controller_mark0_B.fcn3 = cos(rtb_VectorConcatenate_idx_2);

  // Trigonometry: '<S310>/Trigonometric Function'
  acvh_controller_mark0_B.Filter_h = sin(rtb_VectorConcatenate_idx_2);

  // Product: '<S11>/Matrix Multiply' incorporates:
  //   Gain: '<S310>/Gain'
  //   SignalConversion generated from: '<S11>/Matrix Multiply'
  //   SignalConversion generated from: '<S310>/Matrix Concatenate'
  //
  acvh_controller_mark0_B.ug = acvh_controller_mark0_B.fcn3 * static_cast<real_T>
    (acvh_controller_mark0_B.In1.vx) + acvh_controller_mark0_B.Filter_h *
    static_cast<real_T>(acvh_controller_mark0_B.In1.vy);
  acvh_controller_mark0_B.ug1 = acvh_controller_mark0_P.Gain_Gain *
    acvh_controller_mark0_B.Filter_h * static_cast<real_T>
    (acvh_controller_mark0_B.In1.vx) + acvh_controller_mark0_B.fcn3 *
    static_cast<real_T>(acvh_controller_mark0_B.In1.vy);
  if (acvh_controller_mark0_M->Timing.TaskCounters.TID[1] == 0) {
    // MATLABSystem: '<S161>/SourceBlock' incorporates:
    //   Inport: '<S162>/In1'

    rtb_SourceBlock_o1_p = uORB_read_step
      (acvh_controller_mark0_DW.obj_f.orbMetadataObj,
       &acvh_controller_mark0_DW.obj_f.eventStructObj,
       &acvh_controller_mark0_B.b_varargout_2_m, false, 1.0);

    // Outputs for Enabled SubSystem: '<S161>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S162>/Enable'

    if (rtb_SourceBlock_o1_p) {
      acvh_controller_mark0_B.In1_m = acvh_controller_mark0_B.b_varargout_2_m;
      srUpdateBC(acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC_f);
    }

    // End of MATLABSystem: '<S161>/SourceBlock'
    // End of Outputs for SubSystem: '<S161>/Enabled Subsystem'

    // Outputs for Enabled SubSystem: '<S9>/Commands ' incorporates:
    //   EnablePort: '<S159>/Enable'

    acvh_controller_mark0_DW.Commands_MODE = (static_cast<int32_T>
      (acvh_controller_mark0_B.In1_m.mode_switch) > 0);

    // End of Outputs for SubSystem: '<S9>/Commands '
  }

  // Outputs for Enabled SubSystem: '<S9>/Commands ' incorporates:
  //   EnablePort: '<S159>/Enable'

  if (acvh_controller_mark0_DW.Commands_MODE) {
    // Inport: '<S159>/yaw'
    acvh_controller_mark0_B.des_yaw = rtb_VectorConcatenate_idx_2;

    // Inport: '<S159>/vx'
    acvh_controller_mark0_B.des_vx = acvh_controller_mark0_B.ug;

    // Inport: '<S159>/vy'
    acvh_controller_mark0_B.des_vy = acvh_controller_mark0_B.ug1;

    // SignalConversion generated from: '<S159>/des_vz' incorporates:
    //   Constant: '<S159>/Constant'

    acvh_controller_mark0_B.des_vz = acvh_controller_mark0_P.Constant_Value_o;
    srUpdateBC(acvh_controller_mark0_DW.Commands_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S9>/Commands '

  // Saturate: '<S10>/Saturation4'
  if (acvh_controller_mark0_B.des_vz >
      acvh_controller_mark0_P.Saturation4_UpperSat) {
    acvh_controller_mark0_B.fcn3 = acvh_controller_mark0_P.Saturation4_UpperSat;
  } else if (acvh_controller_mark0_B.des_vz <
             acvh_controller_mark0_P.Saturation4_LowerSat) {
    acvh_controller_mark0_B.fcn3 = acvh_controller_mark0_P.Saturation4_LowerSat;
  } else {
    acvh_controller_mark0_B.fcn3 = acvh_controller_mark0_B.des_vz;
  }

  // End of Saturate: '<S10>/Saturation4'

  // Sum: '<S10>/Sum1'
  acvh_controller_mark0_B.Filter_h = acvh_controller_mark0_B.fcn3 -
    static_cast<real_T>(acvh_controller_mark0_B.In1.vz);

  // Gain: '<S200>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S192>/Filter'
  //   Gain: '<S191>/Derivative Gain'
  //   Sum: '<S192>/SumD'

  acvh_controller_mark0_B.Filter_k =
    (acvh_controller_mark0_P.DiscretePIDController1_D *
     acvh_controller_mark0_B.Filter_h - acvh_controller_mark0_DW.Filter_DSTATE) *
    acvh_controller_mark0_P.DiscretePIDController1_N;
  if (acvh_controller_mark0_M->Timing.TaskCounters.TID[1] == 0) {
    // SignalConversion generated from: '<S160>/Bus Selector'
    acvh_controller_mark0_B.x = acvh_controller_mark0_B.In1_m.x;

    // DeadZone: '<S160>/Deadband'
    if (acvh_controller_mark0_B.x > acvh_controller_mark0_P.Deadband_End) {
      tmp_0 = acvh_controller_mark0_B.x - acvh_controller_mark0_P.Deadband_End;
    } else if (acvh_controller_mark0_B.x >=
               acvh_controller_mark0_P.Deadband_Start) {
      tmp_0 = 0.0F;
    } else {
      tmp_0 = acvh_controller_mark0_B.x - acvh_controller_mark0_P.Deadband_Start;
    }

    // End of DeadZone: '<S160>/Deadband'

    // Gain: '<S9>/Gain1'
    acvh_controller_mark0_B.Gain1 = acvh_controller_mark0_P.Gain1_Gain_p * tmp_0;
  }

  // Sum: '<S9>/Sum1'
  acvh_controller_mark0_B.Integrator_dp = static_cast<real_T>
    (acvh_controller_mark0_B.Gain1) + acvh_controller_mark0_B.des_vx;

  // Saturate: '<S10>/Saturation2'
  if (acvh_controller_mark0_B.Integrator_dp >
      acvh_controller_mark0_P.Saturation2_UpperSat) {
    acvh_controller_mark0_B.Integrator_dp =
      acvh_controller_mark0_P.Saturation2_UpperSat;
  } else {
    if (acvh_controller_mark0_B.Integrator_dp <
        acvh_controller_mark0_P.Saturation2_LowerSat) {
      acvh_controller_mark0_B.Integrator_dp =
        acvh_controller_mark0_P.Saturation2_LowerSat;
    }
  }

  // End of Saturate: '<S10>/Saturation2'

  // Gain: '<S10>/1//g' incorporates:
  //   Sum: '<S10>/Sum2'

  acvh_controller_mark0_B.ug = (acvh_controller_mark0_B.Integrator_dp -
    acvh_controller_mark0_B.ug) * acvh_controller_mark0_P.ug_Gain;

  // Gain: '<S248>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S240>/Filter'
  //   Gain: '<S239>/Derivative Gain'
  //   Sum: '<S240>/SumD'

  acvh_controller_mark0_B.FilterCoefficient_o = (acvh_controller_mark0_P.Kfx_D *
    acvh_controller_mark0_B.ug - acvh_controller_mark0_DW.Filter_DSTATE_o) *
    acvh_controller_mark0_P.Kfx_N;

  // Sum: '<S254>/Sum' incorporates:
  //   DiscreteIntegrator: '<S245>/Integrator'
  //   Gain: '<S250>/Proportional Gain'

  acvh_controller_mark0_B.Integrator_dp = (acvh_controller_mark0_P.Kfx_P *
    acvh_controller_mark0_B.ug + acvh_controller_mark0_DW.Integrator_DSTATE_b) +
    acvh_controller_mark0_B.FilterCoefficient_o;

  // Saturate: '<S8>/Saturation'
  if (acvh_controller_mark0_B.Integrator_dp >
      acvh_controller_mark0_P.Saturation_UpperSat) {
    acvh_controller_mark0_B.Integrator_dp =
      acvh_controller_mark0_P.Saturation_UpperSat;
  } else {
    if (acvh_controller_mark0_B.Integrator_dp <
        acvh_controller_mark0_P.Saturation_LowerSat) {
      acvh_controller_mark0_B.Integrator_dp =
        acvh_controller_mark0_P.Saturation_LowerSat;
    }
  }

  // End of Saturate: '<S8>/Saturation'

  // Sum: '<S8>/Sum3' incorporates:
  //   Trigonometry: '<S316>/trigFcn'

  acvh_controller_mark0_B.pitch_err = acvh_controller_mark0_B.Integrator_dp -
    asin(acvh_controller_mark0_B.pitch_err);

  // Gain: '<S49>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S41>/Filter'
  //   Gain: '<S40>/Derivative Gain'
  //   Sum: '<S41>/SumD'

  acvh_controller_mark0_B.FilterCoefficient_k =
    (acvh_controller_mark0_P.DiscretePIDController3_D *
     acvh_controller_mark0_B.pitch_err -
     acvh_controller_mark0_DW.Filter_DSTATE_g) *
    acvh_controller_mark0_P.DiscretePIDController3_N;
  if (acvh_controller_mark0_M->Timing.TaskCounters.TID[1] == 0) {
    // SignalConversion generated from: '<S160>/Bus Selector'
    acvh_controller_mark0_B.y = acvh_controller_mark0_B.In1_m.y;

    // DeadZone: '<S160>/Deadband1'
    if (acvh_controller_mark0_B.y > acvh_controller_mark0_P.Deadband1_End) {
      tmp_0 = acvh_controller_mark0_B.y - acvh_controller_mark0_P.Deadband1_End;
    } else if (acvh_controller_mark0_B.y >=
               acvh_controller_mark0_P.Deadband1_Start) {
      tmp_0 = 0.0F;
    } else {
      tmp_0 = acvh_controller_mark0_B.y -
        acvh_controller_mark0_P.Deadband1_Start;
    }

    // End of DeadZone: '<S160>/Deadband1'

    // Gain: '<S9>/Gain'
    acvh_controller_mark0_B.Gain = acvh_controller_mark0_P.Gain_Gain_n * tmp_0;
  }

  // Sum: '<S9>/Sum3'
  acvh_controller_mark0_B.Integrator_dp = static_cast<real_T>
    (acvh_controller_mark0_B.Gain) + acvh_controller_mark0_B.des_vy;

  // Saturate: '<S10>/Saturation3'
  if (acvh_controller_mark0_B.Integrator_dp >
      acvh_controller_mark0_P.Saturation3_UpperSat) {
    acvh_controller_mark0_B.Integrator_dp =
      acvh_controller_mark0_P.Saturation3_UpperSat;
  } else {
    if (acvh_controller_mark0_B.Integrator_dp <
        acvh_controller_mark0_P.Saturation3_LowerSat) {
      acvh_controller_mark0_B.Integrator_dp =
        acvh_controller_mark0_P.Saturation3_LowerSat;
    }
  }

  // End of Saturate: '<S10>/Saturation3'

  // Gain: '<S10>/1//g1' incorporates:
  //   Sum: '<S10>/Sum'

  acvh_controller_mark0_B.ug1 = (acvh_controller_mark0_B.Integrator_dp -
    acvh_controller_mark0_B.ug1) * acvh_controller_mark0_P.ug1_Gain;

  // Gain: '<S296>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S288>/Filter'
  //   Gain: '<S287>/Derivative Gain'
  //   Sum: '<S288>/SumD'

  acvh_controller_mark0_B.FilterCoefficient_p = (acvh_controller_mark0_P.Kfy_D *
    acvh_controller_mark0_B.ug1 - acvh_controller_mark0_DW.Filter_DSTATE_d) *
    acvh_controller_mark0_P.Kfy_N;

  // Sum: '<S302>/Sum' incorporates:
  //   DiscreteIntegrator: '<S293>/Integrator'
  //   Gain: '<S298>/Proportional Gain'

  acvh_controller_mark0_B.Integrator_dp = (acvh_controller_mark0_P.Kfy_P *
    acvh_controller_mark0_B.ug1 + acvh_controller_mark0_DW.Integrator_DSTATE_cz)
    + acvh_controller_mark0_B.FilterCoefficient_p;

  // Saturate: '<S8>/Saturation1'
  if (acvh_controller_mark0_B.Integrator_dp >
      acvh_controller_mark0_P.Saturation1_UpperSat) {
    acvh_controller_mark0_B.Integrator_dp =
      acvh_controller_mark0_P.Saturation1_UpperSat;
  } else {
    if (acvh_controller_mark0_B.Integrator_dp <
        acvh_controller_mark0_P.Saturation1_LowerSat) {
      acvh_controller_mark0_B.Integrator_dp =
        acvh_controller_mark0_P.Saturation1_LowerSat;
    }
  }

  // End of Saturate: '<S8>/Saturation1'

  // Sum: '<S8>/Sum4'
  rtb_VectorConcatenate_idx_0 = acvh_controller_mark0_B.Integrator_dp -
    rtb_VectorConcatenate_idx_0;

  // Gain: '<S97>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S89>/Filter'
  //   Gain: '<S88>/Derivative Gain'
  //   Sum: '<S89>/SumD'

  acvh_controller_mark0_B.FilterCoefficient_h =
    (acvh_controller_mark0_P.DiscretePIDController4_D *
     rtb_VectorConcatenate_idx_0 - acvh_controller_mark0_DW.Filter_DSTATE_k) *
    acvh_controller_mark0_P.DiscretePIDController4_N;
  if (acvh_controller_mark0_M->Timing.TaskCounters.TID[1] == 0) {
    // SignalConversion generated from: '<S160>/Bus Selector'
    acvh_controller_mark0_B.r = acvh_controller_mark0_B.In1_m.r;

    // DeadZone: '<S160>/Deadband2'
    if (acvh_controller_mark0_B.r > acvh_controller_mark0_P.Deadband2_End) {
      tmp_0 = acvh_controller_mark0_B.r - acvh_controller_mark0_P.Deadband2_End;
    } else if (acvh_controller_mark0_B.r >=
               acvh_controller_mark0_P.Deadband2_Start) {
      tmp_0 = 0.0F;
    } else {
      tmp_0 = acvh_controller_mark0_B.r -
        acvh_controller_mark0_P.Deadband2_Start;
    }

    // End of DeadZone: '<S160>/Deadband2'

    // Gain: '<S9>/Gain2'
    acvh_controller_mark0_B.Gain2 = acvh_controller_mark0_P.Gain2_Gain * tmp_0;
  }

  // Sum: '<S8>/Sum5' incorporates:
  //   Sum: '<S9>/Sum'

  rtb_VectorConcatenate_idx_2 = (static_cast<real_T>
    (acvh_controller_mark0_B.Gain2) + acvh_controller_mark0_B.des_yaw) -
    rtb_VectorConcatenate_idx_2;

  // Gain: '<S145>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S137>/Filter'
  //   Gain: '<S136>/Derivative Gain'
  //   Sum: '<S137>/SumD'

  acvh_controller_mark0_B.FilterCoefficient_n =
    (acvh_controller_mark0_P.DiscretePIDController5_D *
     rtb_VectorConcatenate_idx_2 - acvh_controller_mark0_DW.Filter_DSTATE_l) *
    acvh_controller_mark0_P.DiscretePIDController5_N;

  // Sum: '<S55>/Sum' incorporates:
  //   DiscreteIntegrator: '<S46>/Integrator'
  //   Gain: '<S51>/Proportional Gain'

  acvh_controller_mark0_B.Integrator_dp =
    (acvh_controller_mark0_P.DiscretePIDController3_P *
     acvh_controller_mark0_B.pitch_err +
     acvh_controller_mark0_DW.Integrator_DSTATE_c) +
    acvh_controller_mark0_B.FilterCoefficient_k;

  // Saturate: '<S53>/Saturation'
  if (acvh_controller_mark0_B.Integrator_dp >
      acvh_controller_mark0_P.DiscretePIDController3_UpperSat) {
    acvh_controller_mark0_B.Integrator_dp =
      acvh_controller_mark0_P.DiscretePIDController3_UpperSat;
  } else {
    if (acvh_controller_mark0_B.Integrator_dp <
        acvh_controller_mark0_P.DiscretePIDController3_LowerSat) {
      acvh_controller_mark0_B.Integrator_dp =
        acvh_controller_mark0_P.DiscretePIDController3_LowerSat;
    }
  }

  // Sum: '<S103>/Sum' incorporates:
  //   DiscreteIntegrator: '<S94>/Integrator'
  //   Gain: '<S99>/Proportional Gain'

  u0 = (acvh_controller_mark0_P.DiscretePIDController4_P *
        rtb_VectorConcatenate_idx_0 +
        acvh_controller_mark0_DW.Integrator_DSTATE_f) +
    acvh_controller_mark0_B.FilterCoefficient_h;

  // Saturate: '<S101>/Saturation'
  if (u0 > acvh_controller_mark0_P.DiscretePIDController4_UpperSat) {
    u0 = acvh_controller_mark0_P.DiscretePIDController4_UpperSat;
  } else {
    if (u0 < acvh_controller_mark0_P.DiscretePIDController4_LowerSat) {
      u0 = acvh_controller_mark0_P.DiscretePIDController4_LowerSat;
    }
  }

  // Sum: '<S151>/Sum' incorporates:
  //   DiscreteIntegrator: '<S142>/Integrator'
  //   Gain: '<S147>/Proportional Gain'

  u0_0 = (acvh_controller_mark0_P.DiscretePIDController5_P *
          rtb_VectorConcatenate_idx_2 +
          acvh_controller_mark0_DW.Integrator_DSTATE_l) +
    acvh_controller_mark0_B.FilterCoefficient_n;

  // Saturate: '<S149>/Saturation'
  if (u0_0 > acvh_controller_mark0_P.DiscretePIDController5_UpperSat) {
    u0_0 = acvh_controller_mark0_P.DiscretePIDController5_UpperSat;
  } else {
    if (u0_0 < acvh_controller_mark0_P.DiscretePIDController5_LowerSat) {
      u0_0 = acvh_controller_mark0_P.DiscretePIDController5_LowerSat;
    }
  }

  // SignalConversion generated from: '<S4>/Product1' incorporates:
  //   Constant: '<S4>/Constant'
  //   DiscreteIntegrator: '<S197>/Integrator'
  //   Gain: '<S202>/Proportional Gain'
  //   Sum: '<S206>/Sum'
  //   Sum: '<S4>/Add'

  tmp = ((acvh_controller_mark0_P.DiscretePIDController1_P *
          acvh_controller_mark0_B.Filter_h +
          acvh_controller_mark0_DW.Integrator_DSTATE) +
         acvh_controller_mark0_B.Filter_k) +
    acvh_controller_mark0_P.Constant_Value_c;
  for (i = 0; i < 4; i++) {
    // Product: '<S4>/Product1' incorporates:
    //   Constant: '<S4>/Mixer matrix'
    //   Saturate: '<S101>/Saturation'
    //   Saturate: '<S149>/Saturation'
    //   Saturate: '<S53>/Saturation'

    acvh_controller_mark0_B.fcn3 = acvh_controller_mark0_P.Mixermatrix_Value[
      static_cast<int32_T>(i + 12)] * u0_0 +
      (acvh_controller_mark0_P.Mixermatrix_Value[static_cast<int32_T>(i + 8)] *
       u0 + (acvh_controller_mark0_P.Mixermatrix_Value[static_cast<int32_T>(i +
         4)] * acvh_controller_mark0_B.Integrator_dp +
             acvh_controller_mark0_P.Mixermatrix_Value[i] * tmp));

    // Gain: '<S4>/Gain1'
    acvh_controller_mark0_B.fcn3 = floor(acvh_controller_mark0_P.Gain1_Gain *
      acvh_controller_mark0_B.fcn3);
    if (rtIsNaN(acvh_controller_mark0_B.fcn3) || rtIsInf
        (acvh_controller_mark0_B.fcn3)) {
      acvh_controller_mark0_B.fcn3 = 0.0;
    } else {
      acvh_controller_mark0_B.fcn3 = fmod(acvh_controller_mark0_B.fcn3, 65536.0);
    }

    acvh_controller_mark0_B.Gain1_k[i] = static_cast<uint16_T>
      (acvh_controller_mark0_B.fcn3 < 0.0 ? static_cast<int32_T>
       (static_cast<uint16_T>(static_cast<int32_T>(-static_cast<int32_T>(
           static_cast<int16_T>(static_cast<uint16_T>
            (-acvh_controller_mark0_B.fcn3)))))) : static_cast<int32_T>(
        static_cast<uint16_T>(acvh_controller_mark0_B.fcn3)));

    // End of Gain: '<S4>/Gain1'
  }

  // MATLABSystem: '<S4>/PX4 PWM Output' incorporates:
  //   Constant: '<S4>/Reset'
  //   Logic: '<S4>/NOT'

  if (!acvh_controller_mark0_P.Reset_Value) {
    if (!acvh_controller_mark0_DW.obj_no.isArmed) {
      acvh_controller_mark0_DW.obj_no.isArmed = true;
      status = pwm_arm(&acvh_controller_mark0_DW.obj_no.pwmDevHandler,
                       &acvh_controller_mark0_DW.obj_no.armAdvertiseObj);
      acvh_controller_mark0_DW.obj_no.errorStatus = static_cast<uint16_T>(
        static_cast<int32_T>(static_cast<int32_T>
        (acvh_controller_mark0_DW.obj_no.errorStatus) | static_cast<int32_T>
        (status)));
    }

    for (i = 0; i < 8; i++) {
      acvh_controller_mark0_B.b_pwmValue[i] = 0U;
    }

    acvh_controller_mark0_B.b_pwmValue[0] = acvh_controller_mark0_B.Gain1_k[0];
    acvh_controller_mark0_B.b_pwmValue[1] = acvh_controller_mark0_B.Gain1_k[1];
    acvh_controller_mark0_B.b_pwmValue[2] = acvh_controller_mark0_B.Gain1_k[2];
    acvh_controller_mark0_B.b_pwmValue[3] = acvh_controller_mark0_B.Gain1_k[3];
    status = pwm_setServo(&acvh_controller_mark0_DW.obj_no.pwmDevHandler,
                          acvh_controller_mark0_DW.obj_no.servoCount,
                          acvh_controller_mark0_DW.obj_no.channelMask,
                          &acvh_controller_mark0_B.b_pwmValue[0],
                          acvh_controller_mark0_DW.obj_no.isMain,
                          &acvh_controller_mark0_DW.obj_no.actuatorAdvertiseObj);
    acvh_controller_mark0_DW.obj_no.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (acvh_controller_mark0_DW.obj_no.errorStatus) | static_cast<int32_T>
      (status)));
  } else {
    status = pwm_disarm(&acvh_controller_mark0_DW.obj_no.pwmDevHandler,
                        &acvh_controller_mark0_DW.obj_no.armAdvertiseObj);
    acvh_controller_mark0_DW.obj_no.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (acvh_controller_mark0_DW.obj_no.errorStatus) | static_cast<int32_T>
      (status)));
    acvh_controller_mark0_DW.obj_no.isArmed = false;
    status = pwm_resetServo(&acvh_controller_mark0_DW.obj_no.pwmDevHandler,
      acvh_controller_mark0_DW.obj_no.servoCount,
      acvh_controller_mark0_DW.obj_no.channelMask,
      acvh_controller_mark0_DW.obj_no.isMain,
      &acvh_controller_mark0_DW.obj_no.actuatorAdvertiseObj);
    acvh_controller_mark0_DW.obj_no.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (acvh_controller_mark0_DW.obj_no.errorStatus) | static_cast<int32_T>
      (status)));
  }

  if (acvh_controller_mark0_DW.obj_no.isMain) {
    status = pwm_forceFailsafe(&acvh_controller_mark0_DW.obj_no.pwmDevHandler,
      acvh_controller_mark0_P.Reset_Value);
    acvh_controller_mark0_DW.obj_no.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (acvh_controller_mark0_DW.obj_no.errorStatus) | static_cast<int32_T>
      (status)));
  }

  // End of MATLABSystem: '<S4>/PX4 PWM Output'
  if (acvh_controller_mark0_M->Timing.TaskCounters.TID[1] == 0) {
    // SignalConversion generated from: '<S160>/Bus Selector'
    acvh_controller_mark0_B.z = acvh_controller_mark0_B.In1_m.z;

    // Logic: '<S161>/NOT'
    acvh_controller_mark0_B.NOT = !rtb_SourceBlock_o1_p;
  }

  // Logic: '<S311>/NOT' incorporates:
  //   MATLABSystem: '<S311>/SourceBlock'

  acvh_controller_mark0_B.NOT_l = !b_varargout_1;

  // MATLABSystem: '<S312>/SourceBlock' incorporates:
  //   Inport: '<S315>/In1'

  b_varargout_1 = uORB_read_step(acvh_controller_mark0_DW.obj.orbMetadataObj,
    &acvh_controller_mark0_DW.obj.eventStructObj,
    &acvh_controller_mark0_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S312>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S315>/Enable'

  if (b_varargout_1) {
    acvh_controller_mark0_B.In1_o = acvh_controller_mark0_B.b_varargout_2_c;
    srUpdateBC(acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S312>/SourceBlock'
  // End of Outputs for SubSystem: '<S312>/Enabled Subsystem'

  // SignalConversion generated from: '<S3>/Bus Selector1'
  acvh_controller_mark0_B.pressure = acvh_controller_mark0_B.In1_o.pressure;
  if (acvh_controller_mark0_M->Timing.TaskCounters.TID[1] == 0) {
    // MATLABSystem: '<S5>/SourceBlock'
    b_varargout_1 = uORB_read_step(acvh_controller_mark0_DW.obj_m.orbMetadataObj,
      &acvh_controller_mark0_DW.obj_m.eventStructObj,
      &acvh_controller_mark0_B.BusAssignment, false, 1.0);

    // Logic: '<S5>/NOT' incorporates:
    //   MATLABSystem: '<S5>/SourceBlock'

    acvh_controller_mark0_B.NOT_n = !b_varargout_1;

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S7>/Enable'

    // MATLABSystem: '<S5>/SourceBlock' incorporates:
    //   Inport: '<S7>/In1'

    if (b_varargout_1) {
      acvh_controller_mark0_B.In1_b = acvh_controller_mark0_B.BusAssignment;
      srUpdateBC(acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC_n);
    }

    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

    // BusAssignment: '<S1>/Bus Assignment' incorporates:
    //   Constant: '<S1>/Constant'
    //   Inport: '<S7>/In1'

    acvh_controller_mark0_B.BusAssignment = acvh_controller_mark0_B.In1_b;
    acvh_controller_mark0_B.BusAssignment.armed =
      acvh_controller_mark0_P.Constant_Value_b;

    // MATLABSystem: '<S6>/SinkBlock' incorporates:
    //   BusAssignment: '<S1>/Bus Assignment'

    uORB_write_step(acvh_controller_mark0_DW.obj_fm.orbMetadataObj,
                    &acvh_controller_mark0_DW.obj_fm.orbAdvertiseObj,
                    &acvh_controller_mark0_B.BusAssignment);
  }

  // Update for DiscreteIntegrator: '<S197>/Integrator' incorporates:
  //   Gain: '<S194>/Integral Gain'

  acvh_controller_mark0_DW.Integrator_DSTATE +=
    acvh_controller_mark0_P.DiscretePIDController1_I *
    acvh_controller_mark0_B.Filter_h *
    acvh_controller_mark0_P.Integrator_gainval;

  // Update for DiscreteIntegrator: '<S192>/Filter'
  acvh_controller_mark0_DW.Filter_DSTATE +=
    acvh_controller_mark0_P.Filter_gainval * acvh_controller_mark0_B.Filter_k;

  // Update for DiscreteIntegrator: '<S245>/Integrator' incorporates:
  //   Gain: '<S242>/Integral Gain'

  acvh_controller_mark0_DW.Integrator_DSTATE_b += acvh_controller_mark0_P.Kfx_I *
    acvh_controller_mark0_B.ug * acvh_controller_mark0_P.Integrator_gainval_i;

  // Update for DiscreteIntegrator: '<S240>/Filter'
  acvh_controller_mark0_DW.Filter_DSTATE_o +=
    acvh_controller_mark0_P.Filter_gainval_n *
    acvh_controller_mark0_B.FilterCoefficient_o;

  // Update for DiscreteIntegrator: '<S46>/Integrator' incorporates:
  //   Gain: '<S43>/Integral Gain'

  acvh_controller_mark0_DW.Integrator_DSTATE_c +=
    acvh_controller_mark0_P.DiscretePIDController3_I *
    acvh_controller_mark0_B.pitch_err *
    acvh_controller_mark0_P.Integrator_gainval_f;

  // Update for DiscreteIntegrator: '<S41>/Filter'
  acvh_controller_mark0_DW.Filter_DSTATE_g +=
    acvh_controller_mark0_P.Filter_gainval_e *
    acvh_controller_mark0_B.FilterCoefficient_k;

  // Update for DiscreteIntegrator: '<S293>/Integrator' incorporates:
  //   Gain: '<S290>/Integral Gain'

  acvh_controller_mark0_DW.Integrator_DSTATE_cz += acvh_controller_mark0_P.Kfy_I
    * acvh_controller_mark0_B.ug1 * acvh_controller_mark0_P.Integrator_gainval_l;

  // Update for DiscreteIntegrator: '<S288>/Filter'
  acvh_controller_mark0_DW.Filter_DSTATE_d +=
    acvh_controller_mark0_P.Filter_gainval_d *
    acvh_controller_mark0_B.FilterCoefficient_p;

  // Update for DiscreteIntegrator: '<S94>/Integrator' incorporates:
  //   Gain: '<S91>/Integral Gain'

  acvh_controller_mark0_DW.Integrator_DSTATE_f +=
    acvh_controller_mark0_P.DiscretePIDController4_I *
    rtb_VectorConcatenate_idx_0 * acvh_controller_mark0_P.Integrator_gainval_ld;

  // Update for DiscreteIntegrator: '<S89>/Filter'
  acvh_controller_mark0_DW.Filter_DSTATE_k +=
    acvh_controller_mark0_P.Filter_gainval_i *
    acvh_controller_mark0_B.FilterCoefficient_h;

  // Update for DiscreteIntegrator: '<S142>/Integrator' incorporates:
  //   Gain: '<S139>/Integral Gain'

  acvh_controller_mark0_DW.Integrator_DSTATE_l +=
    acvh_controller_mark0_P.DiscretePIDController5_I *
    rtb_VectorConcatenate_idx_2 * acvh_controller_mark0_P.Integrator_gainval_b;

  // Update for DiscreteIntegrator: '<S137>/Filter'
  acvh_controller_mark0_DW.Filter_DSTATE_l +=
    acvh_controller_mark0_P.Filter_gainval_l *
    acvh_controller_mark0_B.FilterCoefficient_n;

  // External mode
  rtExtModeUploadCheckTrigger(2);

  {                                    // Sample time: [0.001s, 0.0s]
    rtExtModeUpload(0, (real_T)acvh_controller_mark0_M->Timing.taskTime0);
  }

  if (acvh_controller_mark0_M->Timing.TaskCounters.TID[1] == 0) {// Sample time: [0.004s, 0.0s] 
    rtExtModeUpload(1, (real_T)((acvh_controller_mark0_M->Timing.clockTick1) *
      0.004));
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.001s, 0.0s]
    if ((rtmGetTFinal(acvh_controller_mark0_M)!=-1) &&
        !((rtmGetTFinal(acvh_controller_mark0_M)-
           acvh_controller_mark0_M->Timing.taskTime0) >
          acvh_controller_mark0_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(acvh_controller_mark0_M, "Simulation finished");
    }

    if (rtmGetStopRequested(acvh_controller_mark0_M)) {
      rtmSetErrorStatus(acvh_controller_mark0_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  acvh_controller_mark0_M->Timing.taskTime0 =
    ((time_T)(++acvh_controller_mark0_M->Timing.clockTick0)) *
    acvh_controller_mark0_M->Timing.stepSize0;
  if (acvh_controller_mark0_M->Timing.TaskCounters.TID[1] == 0) {
    // Update absolute timer for sample time: [0.004s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.004, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    acvh_controller_mark0_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

// Model initialize function
void acvh_controller_mark0_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(acvh_controller_mark0_M, -1);
  acvh_controller_mark0_M->Timing.stepSize0 = 0.001;

  // External mode info
  acvh_controller_mark0_M->Sizes.checksums[0] = (3920002765U);
  acvh_controller_mark0_M->Sizes.checksums[1] = (3964379827U);
  acvh_controller_mark0_M->Sizes.checksums[2] = (2924481382U);
  acvh_controller_mark0_M->Sizes.checksums[3] = (2202783672U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    acvh_controller_mark0_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC_n;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&acvh_controller_mark0_DW.Commands_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC_f;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)
      &acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC_h;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &acvh_controller_mark0_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = (sysRanDType *)
      &acvh_controller_mark0_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &acvh_controller_mark0_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &acvh_controller_mark0_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(acvh_controller_mark0_M->extModeInfo,
      &acvh_controller_mark0_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(acvh_controller_mark0_M->extModeInfo,
                        acvh_controller_mark0_M->Sizes.checksums);
    rteiSetTPtr(acvh_controller_mark0_M->extModeInfo, rtmGetTPtr
                (acvh_controller_mark0_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    acvh_controller_mark0_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 24;
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

    // InitializeConditions for DiscreteIntegrator: '<S197>/Integrator'
    acvh_controller_mark0_DW.Integrator_DSTATE =
      acvh_controller_mark0_P.DiscretePIDController1_Initia_g;

    // InitializeConditions for DiscreteIntegrator: '<S192>/Filter'
    acvh_controller_mark0_DW.Filter_DSTATE =
      acvh_controller_mark0_P.DiscretePIDController1_InitialC;

    // InitializeConditions for DiscreteIntegrator: '<S245>/Integrator'
    acvh_controller_mark0_DW.Integrator_DSTATE_b =
      acvh_controller_mark0_P.Kfx_InitialConditionForIntegrat;

    // InitializeConditions for DiscreteIntegrator: '<S240>/Filter'
    acvh_controller_mark0_DW.Filter_DSTATE_o =
      acvh_controller_mark0_P.Kfx_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S46>/Integrator'
    acvh_controller_mark0_DW.Integrator_DSTATE_c =
      acvh_controller_mark0_P.DiscretePIDController3_Initia_k;

    // InitializeConditions for DiscreteIntegrator: '<S41>/Filter'
    acvh_controller_mark0_DW.Filter_DSTATE_g =
      acvh_controller_mark0_P.DiscretePIDController3_InitialC;

    // InitializeConditions for DiscreteIntegrator: '<S293>/Integrator'
    acvh_controller_mark0_DW.Integrator_DSTATE_cz =
      acvh_controller_mark0_P.Kfy_InitialConditionForIntegrat;

    // InitializeConditions for DiscreteIntegrator: '<S288>/Filter'
    acvh_controller_mark0_DW.Filter_DSTATE_d =
      acvh_controller_mark0_P.Kfy_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S94>/Integrator'
    acvh_controller_mark0_DW.Integrator_DSTATE_f =
      acvh_controller_mark0_P.DiscretePIDController4_Initia_p;

    // InitializeConditions for DiscreteIntegrator: '<S89>/Filter'
    acvh_controller_mark0_DW.Filter_DSTATE_k =
      acvh_controller_mark0_P.DiscretePIDController4_InitialC;

    // InitializeConditions for DiscreteIntegrator: '<S142>/Integrator'
    acvh_controller_mark0_DW.Integrator_DSTATE_l =
      acvh_controller_mark0_P.DiscretePIDController5_Initia_e;

    // InitializeConditions for DiscreteIntegrator: '<S137>/Filter'
    acvh_controller_mark0_DW.Filter_DSTATE_l =
      acvh_controller_mark0_P.DiscretePIDController5_InitialC;

    // SystemInitialize for Enabled SubSystem: '<S311>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S314>/Out1' incorporates:
    //   Inport: '<S314>/In1'

    acvh_controller_mark0_B.In1 = acvh_controller_mark0_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S311>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S161>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S162>/Out1' incorporates:
    //   Inport: '<S162>/In1'

    acvh_controller_mark0_B.In1_m = acvh_controller_mark0_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S161>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S9>/Commands '
    // SystemInitialize for SignalConversion generated from: '<S159>/des_vz' incorporates:
    //   Constant: '<S159>/Constant'

    acvh_controller_mark0_B.des_vz = acvh_controller_mark0_P.Constant_Value_o;

    // SystemInitialize for Outport: '<S159>/des_yaw' incorporates:
    //   Inport: '<S159>/yaw'

    acvh_controller_mark0_B.des_yaw = acvh_controller_mark0_P.des_yaw_Y0;

    // SystemInitialize for Outport: '<S159>/des_vx' incorporates:
    //   Inport: '<S159>/vx'

    acvh_controller_mark0_B.des_vx = acvh_controller_mark0_P.des_vx_Y0;

    // SystemInitialize for Outport: '<S159>/des_vy' incorporates:
    //   Inport: '<S159>/vy'

    acvh_controller_mark0_B.des_vy = acvh_controller_mark0_P.des_vy_Y0;

    // End of SystemInitialize for SubSystem: '<S9>/Commands '

    // SystemInitialize for Enabled SubSystem: '<S312>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S315>/Out1' incorporates:
    //   Inport: '<S315>/In1'

    acvh_controller_mark0_B.In1_o = acvh_controller_mark0_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S312>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S7>/Out1' incorporates:
    //   Inport: '<S7>/In1'

    acvh_controller_mark0_B.In1_b = acvh_controller_mark0_P.Out1_Y0_oq;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S311>/SourceBlock'
    acvh_controller_mark0_DW.obj_n.matlabCodegenIsDeleted = false;
    acvh_controller_mark0_DW.obj_n.isSetupComplete = false;
    acvh_controller_mark0_DW.obj_n.isInitialized = 1;
    acvh_controller_mark0_DW.obj_n.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(acvh_controller_mark0_DW.obj_n.orbMetadataObj,
                         &acvh_controller_mark0_DW.obj_n.eventStructObj);
    acvh_controller_mark0_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S161>/SourceBlock'
    acvh_controller_mark0_DW.obj_f.matlabCodegenIsDeleted = false;
    acvh_controller_mark0_DW.obj_f.isSetupComplete = false;
    acvh_controller_mark0_DW.obj_f.isInitialized = 1;
    acvh_controller_mark0_DW.obj_f.orbMetadataObj = ORB_ID
      (manual_control_setpoint);
    uORB_read_initialize(acvh_controller_mark0_DW.obj_f.orbMetadataObj,
                         &acvh_controller_mark0_DW.obj_f.eventStructObj);
    acvh_controller_mark0_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<S4>/PX4 PWM Output' incorporates:
    //   Constant: '<S4>/Reset'

    acvh_controller_mark0_DW.obj_no.errorStatus = 0U;
    acvh_controller_mark0_DW.obj_no.isInitialized = 0;
    acvh_controller_mark0_DW.obj_no.matlabCodegenIsDeleted = false;
    acvh_controlle_SystemCore_setup(&acvh_controller_mark0_DW.obj_no, rtb_NOT,
      acvh_controller_mark0_P.Reset_Value);

    // Start for MATLABSystem: '<S312>/SourceBlock'
    acvh_controller_mark0_DW.obj.matlabCodegenIsDeleted = false;
    acvh_controller_mark0_DW.obj.isSetupComplete = false;
    acvh_controller_mark0_DW.obj.isInitialized = 1;
    acvh_controller_mark0_DW.obj.orbMetadataObj = ORB_ID(sensor_baro);
    uORB_read_initialize(acvh_controller_mark0_DW.obj.orbMetadataObj,
                         &acvh_controller_mark0_DW.obj.eventStructObj);
    acvh_controller_mark0_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/SourceBlock'
    acvh_controller_mark0_DW.obj_m.matlabCodegenIsDeleted = false;
    acvh_controller_mark0_DW.obj_m.isSetupComplete = false;
    acvh_controller_mark0_DW.obj_m.isInitialized = 1;
    acvh_controller_mark0_DW.obj_m.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(acvh_controller_mark0_DW.obj_m.orbMetadataObj,
                         &acvh_controller_mark0_DW.obj_m.eventStructObj);
    acvh_controller_mark0_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/SinkBlock' incorporates:
    //   BusAssignment: '<S1>/Bus Assignment'

    acvh_controller_mark0_DW.obj_fm.matlabCodegenIsDeleted = false;
    acvh_controller_mark0_DW.obj_fm.isSetupComplete = false;
    acvh_controller_mark0_DW.obj_fm.isInitialized = 1;
    acvh_controller_mark0_DW.obj_fm.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_write_initialize(acvh_controller_mark0_DW.obj_fm.orbMetadataObj,
                          &acvh_controller_mark0_DW.obj_fm.orbAdvertiseObj,
                          &rtb_BusAssignment, 1);
    acvh_controller_mark0_DW.obj_fm.isSetupComplete = true;
  }
}

// Model terminate function
void acvh_controller_mark0_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S311>/SourceBlock'
  if (!acvh_controller_mark0_DW.obj_n.matlabCodegenIsDeleted) {
    acvh_controller_mark0_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark0_DW.obj_n.isInitialized == 1) &&
        acvh_controller_mark0_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&acvh_controller_mark0_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S311>/SourceBlock'

  // Terminate for MATLABSystem: '<S161>/SourceBlock'
  if (!acvh_controller_mark0_DW.obj_f.matlabCodegenIsDeleted) {
    acvh_controller_mark0_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark0_DW.obj_f.isInitialized == 1) &&
        acvh_controller_mark0_DW.obj_f.isSetupComplete) {
      uORB_read_terminate(&acvh_controller_mark0_DW.obj_f.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S161>/SourceBlock'

  // Terminate for MATLABSystem: '<S4>/PX4 PWM Output'
  if (!acvh_controller_mark0_DW.obj_no.matlabCodegenIsDeleted) {
    acvh_controller_mark0_DW.obj_no.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark0_DW.obj_no.isInitialized == 1) &&
        acvh_controller_mark0_DW.obj_no.isSetupComplete) {
      status = pwm_disarm(&acvh_controller_mark0_DW.obj_no.pwmDevHandler,
                          &acvh_controller_mark0_DW.obj_no.armAdvertiseObj);
      acvh_controller_mark0_DW.obj_no.errorStatus = static_cast<uint16_T>(
        static_cast<int32_T>(static_cast<int32_T>
        (acvh_controller_mark0_DW.obj_no.errorStatus) | static_cast<int32_T>
        (status)));
      status = pwm_resetServo(&acvh_controller_mark0_DW.obj_no.pwmDevHandler,
        acvh_controller_mark0_DW.obj_no.servoCount,
        acvh_controller_mark0_DW.obj_no.channelMask,
        acvh_controller_mark0_DW.obj_no.isMain,
        &acvh_controller_mark0_DW.obj_no.actuatorAdvertiseObj);
      acvh_controller_mark0_DW.obj_no.errorStatus = static_cast<uint16_T>(
        static_cast<int32_T>(static_cast<int32_T>
        (acvh_controller_mark0_DW.obj_no.errorStatus) | static_cast<int32_T>
        (status)));
      status = pwm_close(&acvh_controller_mark0_DW.obj_no.pwmDevHandler,
                         &acvh_controller_mark0_DW.obj_no.actuatorAdvertiseObj,
                         &acvh_controller_mark0_DW.obj_no.armAdvertiseObj);
      acvh_controller_mark0_DW.obj_no.errorStatus = static_cast<uint16_T>(
        static_cast<int32_T>(static_cast<int32_T>
        (acvh_controller_mark0_DW.obj_no.errorStatus) | static_cast<int32_T>
        (status)));
    }
  }

  // End of Terminate for MATLABSystem: '<S4>/PX4 PWM Output'

  // Terminate for MATLABSystem: '<S312>/SourceBlock'
  if (!acvh_controller_mark0_DW.obj.matlabCodegenIsDeleted) {
    acvh_controller_mark0_DW.obj.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark0_DW.obj.isInitialized == 1) &&
        acvh_controller_mark0_DW.obj.isSetupComplete) {
      uORB_read_terminate(&acvh_controller_mark0_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S312>/SourceBlock'

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!acvh_controller_mark0_DW.obj_m.matlabCodegenIsDeleted) {
    acvh_controller_mark0_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark0_DW.obj_m.isInitialized == 1) &&
        acvh_controller_mark0_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&acvh_controller_mark0_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  if (!acvh_controller_mark0_DW.obj_fm.matlabCodegenIsDeleted) {
    acvh_controller_mark0_DW.obj_fm.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark0_DW.obj_fm.isInitialized == 1) &&
        acvh_controller_mark0_DW.obj_fm.isSetupComplete) {
      uORB_write_terminate(&acvh_controller_mark0_DW.obj_fm.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
