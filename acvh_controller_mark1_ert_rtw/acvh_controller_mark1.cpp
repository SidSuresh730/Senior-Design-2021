//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: acvh_controller_mark1.cpp
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
#include "acvh_controller_mark1_dt.h"

// Exported block signals
real_T tau_thrust;                     // '<S59>/Sum'
real_T tau_roll;                       // '<S254>/Saturation'
real_T tau_pitch;                      // '<S206>/Saturation'

// Block signals (default storage)
B_acvh_controller_mark1_T acvh_controller_mark1_B;

// Block states (default storage)
DW_acvh_controller_mark1_T acvh_controller_mark1_DW;

// Real-time model
RT_MODEL_acvh_controller_mark_T acvh_controller_mark1_M_ =
  RT_MODEL_acvh_controller_mark_T();
RT_MODEL_acvh_controller_mark_T *const acvh_controller_mark1_M =
  &acvh_controller_mark1_M_;

// Forward declaration for local functions
static void acvh_controlle_SystemCore_setup(px4_internal_block_PWM_acvh_c_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
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
void acvh_controller_mark1_step(void)
{
  real_T Integrator;
  real_T Integrator_tmp;
  real_T rtb_ZeroGain;
  real_T rtb_fcn3;
  real_T tmp;
  int32_T i;
  real32_T tmp_0;
  uint16_T status;
  boolean_T b_varargout_1;
  boolean_T b_varargout_1_0;
  boolean_T rtb_NotEqual;
  boolean_T rtb_NotEqual_k;

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_c);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_o);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_g);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark1_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark1_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark1_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC);

  // MATLABSystem: '<S325>/SourceBlock' incorporates:
  //   Inport: '<S326>/In1'

  b_varargout_1 = uORB_read_step(acvh_controller_mark1_DW.obj.orbMetadataObj,
    &acvh_controller_mark1_DW.obj.eventStructObj,
    &acvh_controller_mark1_B.b_varargout_2_m, false, 1.0);

  // Outputs for Enabled SubSystem: '<S325>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S326>/Enable'

  if (b_varargout_1) {
    acvh_controller_mark1_B.In1_f = acvh_controller_mark1_B.b_varargout_2_m;
    srUpdateBC(acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S325>/Enabled Subsystem'

  // SignalConversion generated from: '<S5>/Bus Selector'
  acvh_controller_mark1_B.z = acvh_controller_mark1_B.In1_f.z;

  // DeadZone: '<S5>/Deadband3'
  if (acvh_controller_mark1_B.z > acvh_controller_mark1_P.Deadband3_End) {
    tmp_0 = acvh_controller_mark1_B.z - acvh_controller_mark1_P.Deadband3_End;
  } else if (acvh_controller_mark1_B.z >=
             acvh_controller_mark1_P.Deadband3_Start) {
    tmp_0 = 0.0F;
  } else {
    tmp_0 = acvh_controller_mark1_B.z - acvh_controller_mark1_P.Deadband3_Start;
  }

  // End of DeadZone: '<S5>/Deadband3'

  // Gain: '<S5>/Gain'
  acvh_controller_mark1_B.Gain = acvh_controller_mark1_P.Gain_Gain_o * tmp_0;

  // Saturate: '<S2>/Saturation4'
  if (acvh_controller_mark1_B.Gain >
      acvh_controller_mark1_P.Saturation4_UpperSat) {
    // Saturate: '<S2>/Saturation4'
    acvh_controller_mark1_B.des_z = acvh_controller_mark1_P.Saturation4_UpperSat;
  } else if (acvh_controller_mark1_B.Gain <
             acvh_controller_mark1_P.Saturation4_LowerSat) {
    // Saturate: '<S2>/Saturation4'
    acvh_controller_mark1_B.des_z = acvh_controller_mark1_P.Saturation4_LowerSat;
  } else {
    // Saturate: '<S2>/Saturation4'
    acvh_controller_mark1_B.des_z = acvh_controller_mark1_B.Gain;
  }

  // End of Saturate: '<S2>/Saturation4'

  // MATLABSystem: '<S312>/SourceBlock' incorporates:
  //   Inport: '<S315>/In1'

  b_varargout_1_0 = uORB_read_step
    (acvh_controller_mark1_DW.obj_ji.orbMetadataObj,
     &acvh_controller_mark1_DW.obj_ji.eventStructObj,
     &acvh_controller_mark1_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S312>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S315>/Enable'

  if (b_varargout_1_0) {
    acvh_controller_mark1_B.In1 = acvh_controller_mark1_B.b_varargout_2;
    srUpdateBC(acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_o);
  }

  // End of Outputs for SubSystem: '<S312>/Enabled Subsystem'

  // DataTypeConversion: '<S3>/Data Type Conversion4'
  acvh_controller_mark1_B.DataTypeConversion4 = static_cast<real_T>
    (acvh_controller_mark1_B.In1.z);

  // Sum: '<S2>/Sum1'
  acvh_controller_mark1_B.Integrator_e = static_cast<real_T>
    (acvh_controller_mark1_B.des_z) -
    acvh_controller_mark1_B.DataTypeConversion4;

  // DiscreteIntegrator: '<S50>/Integrator' incorporates:
  //   Gain: '<S47>/Integral Gain'

  Integrator_tmp = acvh_controller_mark1_P.Integrator_gainval *
    (acvh_controller_mark1_P.DiscretePIDController1_I *
     acvh_controller_mark1_B.Integrator_e);

  // DiscreteIntegrator: '<S50>/Integrator'
  Integrator = Integrator_tmp + acvh_controller_mark1_DW.Integrator_DSTATE;

  // SampleTimeMath: '<S45>/Tsamp' incorporates:
  //   Constant: '<S52>/N Copy'
  //
  //  About '<S45>/Tsamp':
  //   y = u * K where K = ( w * Ts )

  acvh_controller_mark1_B.roll_err =
    acvh_controller_mark1_P.DiscretePIDController1_N *
    acvh_controller_mark1_P.Tsamp_WtEt;

  // Math: '<S43>/Reciprocal' incorporates:
  //   Constant: '<S43>/Constant'
  //   Sum: '<S43>/SumDen'
  //
  //  About '<S43>/Reciprocal':
  //   Operator: reciprocal

  acvh_controller_mark1_B.SignPreSat_c = 1.0 /
    (acvh_controller_mark1_P.Constant_Value_na +
     acvh_controller_mark1_B.roll_err);

  // DiscreteTransferFcn: '<S43>/Filter Differentiator TF' incorporates:
  //   Constant: '<S43>/Constant'
  //   Gain: '<S42>/Derivative Gain'
  //   Product: '<S43>/Divide'
  //   Sum: '<S43>/SumNum'

  acvh_controller_mark1_B.denAccum =
    acvh_controller_mark1_P.DiscretePIDController1_D *
    acvh_controller_mark1_B.Integrator_e - (acvh_controller_mark1_B.roll_err -
    acvh_controller_mark1_P.Constant_Value_na) *
    acvh_controller_mark1_B.SignPreSat_c *
    acvh_controller_mark1_DW.FilterDifferentiatorTF_states;

  // Sum: '<S59>/Sum' incorporates:
  //   DiscreteTransferFcn: '<S43>/Filter Differentiator TF'
  //   Gain: '<S53>/Filter Coefficient'
  //   Gain: '<S55>/Proportional Gain'
  //   Product: '<S43>/DenCoefOut'

  tau_thrust = (acvh_controller_mark1_P.FilterDifferentiatorTF_NumCoef[0] *
                acvh_controller_mark1_B.denAccum +
                acvh_controller_mark1_P.FilterDifferentiatorTF_NumCoef[1] *
                acvh_controller_mark1_DW.FilterDifferentiatorTF_states) *
    acvh_controller_mark1_B.SignPreSat_c *
    acvh_controller_mark1_P.DiscretePIDController1_N +
    (acvh_controller_mark1_P.DiscretePIDController1_P *
     acvh_controller_mark1_B.Integrator_e + Integrator);

  // SignalConversion generated from: '<S5>/Bus Selector'
  acvh_controller_mark1_B.x = acvh_controller_mark1_B.In1_f.x;

  // DeadZone: '<S5>/Deadband'
  if (acvh_controller_mark1_B.x > acvh_controller_mark1_P.Deadband_End) {
    tmp_0 = acvh_controller_mark1_B.x - acvh_controller_mark1_P.Deadband_End;
  } else if (acvh_controller_mark1_B.x >= acvh_controller_mark1_P.Deadband_Start)
  {
    tmp_0 = 0.0F;
  } else {
    tmp_0 = acvh_controller_mark1_B.x - acvh_controller_mark1_P.Deadband_Start;
  }

  // End of DeadZone: '<S5>/Deadband'

  // Sum: '<S5>/Sum' incorporates:
  //   Constant: '<S5>/Constant1'

  acvh_controller_mark1_B.Sum = static_cast<real_T>(tmp_0) +
    acvh_controller_mark1_P.Constant1_Value_i;

  // Saturate: '<S2>/Saturation2'
  if (acvh_controller_mark1_B.Sum > acvh_controller_mark1_P.Saturation2_UpperSat)
  {
    // Saturate: '<S2>/Saturation2'
    acvh_controller_mark1_B.des_vx =
      acvh_controller_mark1_P.Saturation2_UpperSat;
  } else if (acvh_controller_mark1_B.Sum <
             acvh_controller_mark1_P.Saturation2_LowerSat) {
    // Saturate: '<S2>/Saturation2'
    acvh_controller_mark1_B.des_vx =
      acvh_controller_mark1_P.Saturation2_LowerSat;
  } else {
    // Saturate: '<S2>/Saturation2'
    acvh_controller_mark1_B.des_vx = acvh_controller_mark1_B.Sum;
  }

  // End of Saturate: '<S2>/Saturation2'

  // SignalConversion generated from: '<S5>/Bus Selector'
  acvh_controller_mark1_B.y = acvh_controller_mark1_B.In1_f.y;

  // DeadZone: '<S5>/Deadband1'
  if (acvh_controller_mark1_B.y > acvh_controller_mark1_P.Deadband1_End) {
    tmp_0 = acvh_controller_mark1_B.y - acvh_controller_mark1_P.Deadband1_End;
  } else if (acvh_controller_mark1_B.y >=
             acvh_controller_mark1_P.Deadband1_Start) {
    tmp_0 = 0.0F;
  } else {
    tmp_0 = acvh_controller_mark1_B.y - acvh_controller_mark1_P.Deadband1_Start;
  }

  // End of DeadZone: '<S5>/Deadband1'

  // Sum: '<S5>/Sum1' incorporates:
  //   Constant: '<S5>/Constant1'

  acvh_controller_mark1_B.Sum1 = static_cast<real_T>(tmp_0) +
    acvh_controller_mark1_P.Constant1_Value_i;

  // Saturate: '<S2>/Saturation3'
  if (acvh_controller_mark1_B.Sum1 >
      acvh_controller_mark1_P.Saturation3_UpperSat) {
    // Saturate: '<S2>/Saturation3'
    acvh_controller_mark1_B.des_vy =
      acvh_controller_mark1_P.Saturation3_UpperSat;
  } else if (acvh_controller_mark1_B.Sum1 <
             acvh_controller_mark1_P.Saturation3_LowerSat) {
    // Saturate: '<S2>/Saturation3'
    acvh_controller_mark1_B.des_vy =
      acvh_controller_mark1_P.Saturation3_LowerSat;
  } else {
    // Saturate: '<S2>/Saturation3'
    acvh_controller_mark1_B.des_vy = acvh_controller_mark1_B.Sum1;
  }

  // End of Saturate: '<S2>/Saturation3'

  // Sqrt: '<S323>/sqrt' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion1'
  //   Product: '<S324>/Product'
  //   Product: '<S324>/Product1'
  //   Product: '<S324>/Product2'
  //   Product: '<S324>/Product3'
  //   Sum: '<S324>/Sum'

  acvh_controller_mark1_B.SignPreSat_c = sqrt(((static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[0]) * static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[0]) + static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[1]) * static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[1])) + static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[2]) * static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[2])) + static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[3]) * static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[3]));

  // Product: '<S318>/Product' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion1'

  acvh_controller_mark1_B.Filter_f = static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[0]) / acvh_controller_mark1_B.SignPreSat_c;

  // Product: '<S318>/Product1' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion1'

  acvh_controller_mark1_B.roll_err = static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[1]) / acvh_controller_mark1_B.SignPreSat_c;

  // Product: '<S318>/Product2' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion1'

  acvh_controller_mark1_B.Integrator_e = static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[2]) / acvh_controller_mark1_B.SignPreSat_c;

  // Product: '<S318>/Product3' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion1'

  acvh_controller_mark1_B.SignPreSat_c = static_cast<real_T>
    (acvh_controller_mark1_B.In1.q[3]) / acvh_controller_mark1_B.SignPreSat_c;

  // Fcn: '<S314>/fcn2' incorporates:
  //   Fcn: '<S314>/fcn5'

  acvh_controller_mark1_B.IntegralGain_j = acvh_controller_mark1_B.Filter_f *
    acvh_controller_mark1_B.Filter_f;
  acvh_controller_mark1_B.FilterCoefficient_d = acvh_controller_mark1_B.roll_err
    * acvh_controller_mark1_B.roll_err;
  acvh_controller_mark1_B.SignPreSat = acvh_controller_mark1_B.Integrator_e *
    acvh_controller_mark1_B.Integrator_e;
  acvh_controller_mark1_B.pitch_err = acvh_controller_mark1_B.SignPreSat_c *
    acvh_controller_mark1_B.SignPreSat_c;

  // Trigonometry: '<S317>/Trigonometric Function1' incorporates:
  //   Fcn: '<S314>/fcn1'
  //   Fcn: '<S314>/fcn2'

  acvh_controller_mark1_B.VectorConcatenate[0] = rt_atan2d_snf
    ((acvh_controller_mark1_B.Integrator_e *
      acvh_controller_mark1_B.SignPreSat_c - acvh_controller_mark1_B.Filter_f *
      acvh_controller_mark1_B.roll_err) * -2.0,
     ((acvh_controller_mark1_B.IntegralGain_j -
       acvh_controller_mark1_B.FilterCoefficient_d) -
      acvh_controller_mark1_B.SignPreSat) + acvh_controller_mark1_B.pitch_err);

  // Fcn: '<S314>/fcn3'
  rtb_fcn3 = (acvh_controller_mark1_B.roll_err *
              acvh_controller_mark1_B.SignPreSat_c +
              acvh_controller_mark1_B.Filter_f *
              acvh_controller_mark1_B.Integrator_e) * 2.0;

  // If: '<S319>/If' incorporates:
  //   Constant: '<S320>/Constant'
  //   Constant: '<S321>/Constant'

  if (rtb_fcn3 > 1.0) {
    // Outputs for IfAction SubSystem: '<S319>/If Action Subsystem' incorporates:
    //   ActionPort: '<S320>/Action Port'

    rtb_fcn3 = acvh_controller_mark1_P.Constant_Value_p;

    // End of Outputs for SubSystem: '<S319>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S319>/If Action Subsystem' incorporates:
    //   ActionPort: '<S320>/Action Port'

    // Update for If: '<S319>/If' incorporates:
    //   Constant: '<S320>/Constant'

    srUpdateBC(acvh_controller_mark1_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S319>/If Action Subsystem'
  } else if (rtb_fcn3 < -1.0) {
    // Outputs for IfAction SubSystem: '<S319>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S321>/Action Port'

    rtb_fcn3 = acvh_controller_mark1_P.Constant_Value_o;

    // End of Outputs for SubSystem: '<S319>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S319>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S321>/Action Port'

    // Update for If: '<S319>/If' incorporates:
    //   Constant: '<S321>/Constant'

    srUpdateBC(acvh_controller_mark1_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S319>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S319>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S322>/Action Port'

    // Update for If: '<S319>/If'
    srUpdateBC(acvh_controller_mark1_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S319>/If Action Subsystem2'
  }

  // End of If: '<S319>/If'

  // Trigonometry: '<S317>/trigFcn'
  if (rtb_fcn3 > 1.0) {
    rtb_fcn3 = 1.0;
  } else {
    if (rtb_fcn3 < -1.0) {
      rtb_fcn3 = -1.0;
    }
  }

  acvh_controller_mark1_B.VectorConcatenate[1] = asin(rtb_fcn3);

  // End of Trigonometry: '<S317>/trigFcn'

  // Trigonometry: '<S317>/Trigonometric Function3' incorporates:
  //   Fcn: '<S314>/fcn4'
  //   Fcn: '<S314>/fcn5'

  acvh_controller_mark1_B.VectorConcatenate[2] = rt_atan2d_snf
    ((acvh_controller_mark1_B.roll_err * acvh_controller_mark1_B.Integrator_e -
      acvh_controller_mark1_B.Filter_f * acvh_controller_mark1_B.SignPreSat_c) *
     -2.0, ((acvh_controller_mark1_B.IntegralGain_j +
             acvh_controller_mark1_B.FilterCoefficient_d) -
            acvh_controller_mark1_B.SignPreSat) -
     acvh_controller_mark1_B.pitch_err);

  // Trigonometry: '<S167>/Trigonometric Function1'
  rtb_fcn3 = cos(acvh_controller_mark1_B.VectorConcatenate[2]);

  // Trigonometry: '<S167>/Trigonometric Function'
  acvh_controller_mark1_B.roll_err = sin
    (acvh_controller_mark1_B.VectorConcatenate[2]);

  // Product: '<S13>/Matrix Multiply' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion2'
  //   DataTypeConversion: '<S3>/Data Type Conversion3'
  //   Gain: '<S167>/Gain'
  //   SignalConversion generated from: '<S167>/Matrix Concatenate'
  //
  acvh_controller_mark1_B.MatrixMultiply[0] = 0.0;
  acvh_controller_mark1_B.MatrixMultiply[0] += rtb_fcn3 * static_cast<real_T>
    (acvh_controller_mark1_B.In1.vx);
  acvh_controller_mark1_B.MatrixMultiply[0] += acvh_controller_mark1_B.roll_err *
    static_cast<real_T>(acvh_controller_mark1_B.In1.vy);
  acvh_controller_mark1_B.MatrixMultiply[1] = 0.0;
  acvh_controller_mark1_B.MatrixMultiply[1] += acvh_controller_mark1_P.Gain_Gain
    * acvh_controller_mark1_B.roll_err * static_cast<real_T>
    (acvh_controller_mark1_B.In1.vx);
  acvh_controller_mark1_B.MatrixMultiply[1] += rtb_fcn3 * static_cast<real_T>
    (acvh_controller_mark1_B.In1.vy);

  // Sum: '<S2>/Sum'
  rtb_fcn3 = acvh_controller_mark1_B.des_vy -
    acvh_controller_mark1_B.MatrixMultiply[1];

  // Gain: '<S153>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S145>/Filter'
  //   Gain: '<S144>/Derivative Gain'
  //   Sum: '<S145>/SumD'

  acvh_controller_mark1_B.Integrator_e = (acvh_controller_mark1_P.Kfy_D *
    rtb_fcn3 - acvh_controller_mark1_DW.Filter_DSTATE) *
    acvh_controller_mark1_P.Kfy_N;

  // Sum: '<S159>/Sum' incorporates:
  //   DiscreteIntegrator: '<S150>/Integrator'
  //   Gain: '<S155>/Proportional Gain'

  acvh_controller_mark1_B.SignPreSat_c = (acvh_controller_mark1_P.Kfy_P *
    rtb_fcn3 + acvh_controller_mark1_DW.Integrator_DSTATE_m) +
    acvh_controller_mark1_B.Integrator_e;

  // Saturate: '<S157>/Saturation'
  if (acvh_controller_mark1_B.SignPreSat_c >
      acvh_controller_mark1_P.Kfy_UpperSaturationLimit) {
    // Saturate: '<S157>/Saturation'
    acvh_controller_mark1_B.Saturation =
      acvh_controller_mark1_P.Kfy_UpperSaturationLimit;
  } else if (acvh_controller_mark1_B.SignPreSat_c <
             acvh_controller_mark1_P.Kfy_LowerSaturationLimit) {
    // Saturate: '<S157>/Saturation'
    acvh_controller_mark1_B.Saturation =
      acvh_controller_mark1_P.Kfy_LowerSaturationLimit;
  } else {
    // Saturate: '<S157>/Saturation'
    acvh_controller_mark1_B.Saturation = acvh_controller_mark1_B.SignPreSat_c;
  }

  // End of Saturate: '<S157>/Saturation'

  // Sum: '<S2>/Sum4'
  acvh_controller_mark1_B.roll_err = acvh_controller_mark1_B.Saturation -
    acvh_controller_mark1_B.VectorConcatenate[0];

  // Gain: '<S250>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S242>/Filter'
  //   Gain: '<S241>/Derivative Gain'
  //   Sum: '<S242>/SumD'

  acvh_controller_mark1_B.Filter_f = (acvh_controller_mark1_P.tau_roll1_D *
    acvh_controller_mark1_B.roll_err - acvh_controller_mark1_DW.Filter_DSTATE_d)
    * acvh_controller_mark1_P.tau_roll1_N;

  // Sum: '<S256>/Sum' incorporates:
  //   DiscreteIntegrator: '<S247>/Integrator'
  //   Gain: '<S252>/Proportional Gain'

  tau_roll = (acvh_controller_mark1_P.tau_roll1_P *
              acvh_controller_mark1_B.roll_err +
              acvh_controller_mark1_DW.Integrator_DSTATE_j) +
    acvh_controller_mark1_B.Filter_f;

  // Saturate: '<S254>/Saturation'
  if (tau_roll > acvh_controller_mark1_P.tau_roll1_UpperSaturationLimit) {
    // Sum: '<S256>/Sum' incorporates:
    //   Saturate: '<S254>/Saturation'

    tau_roll = acvh_controller_mark1_P.tau_roll1_UpperSaturationLimit;
  } else {
    if (tau_roll < acvh_controller_mark1_P.tau_roll1_LowerSaturationLimit) {
      // Sum: '<S256>/Sum' incorporates:
      //   Saturate: '<S254>/Saturation'

      tau_roll = acvh_controller_mark1_P.tau_roll1_LowerSaturationLimit;
    }
  }

  // End of Saturate: '<S254>/Saturation'

  // RateLimiter: '<S2>/Rate Limiter4'
  rtb_ZeroGain = tau_roll - acvh_controller_mark1_DW.PrevY;
  if (rtb_ZeroGain > acvh_controller_mark1_P.RateLimiter4_RisingLim) {
    // RateLimiter: '<S2>/Rate Limiter4'
    acvh_controller_mark1_DW.PrevY +=
      acvh_controller_mark1_P.RateLimiter4_RisingLim;
  } else if (rtb_ZeroGain < acvh_controller_mark1_P.RateLimiter4_FallingLim) {
    // RateLimiter: '<S2>/Rate Limiter4'
    acvh_controller_mark1_DW.PrevY +=
      acvh_controller_mark1_P.RateLimiter4_FallingLim;
  } else {
    // RateLimiter: '<S2>/Rate Limiter4'
    acvh_controller_mark1_DW.PrevY = tau_roll;
  }

  // End of RateLimiter: '<S2>/Rate Limiter4'

  // Sum: '<S2>/Sum2'
  acvh_controller_mark1_B.IntegralGain_j = acvh_controller_mark1_B.des_vx -
    acvh_controller_mark1_B.MatrixMultiply[0];

  // Gain: '<S103>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S95>/Filter'
  //   Gain: '<S94>/Derivative Gain'
  //   Sum: '<S95>/SumD'

  acvh_controller_mark1_B.FilterCoefficient_d = (acvh_controller_mark1_P.Kfx_D *
    acvh_controller_mark1_B.IntegralGain_j -
    acvh_controller_mark1_DW.Filter_DSTATE_d4) * acvh_controller_mark1_P.Kfx_N;

  // Sum: '<S109>/Sum' incorporates:
  //   DiscreteIntegrator: '<S100>/Integrator'
  //   Gain: '<S105>/Proportional Gain'

  acvh_controller_mark1_B.SignPreSat = (acvh_controller_mark1_P.Kfx_P *
    acvh_controller_mark1_B.IntegralGain_j +
    acvh_controller_mark1_DW.Integrator_DSTATE_e) +
    acvh_controller_mark1_B.FilterCoefficient_d;

  // Saturate: '<S107>/Saturation'
  if (acvh_controller_mark1_B.SignPreSat >
      acvh_controller_mark1_P.Kfx_UpperSaturationLimit) {
    acvh_controller_mark1_B.pitch_err =
      acvh_controller_mark1_P.Kfx_UpperSaturationLimit;
  } else if (acvh_controller_mark1_B.SignPreSat <
             acvh_controller_mark1_P.Kfx_LowerSaturationLimit) {
    acvh_controller_mark1_B.pitch_err =
      acvh_controller_mark1_P.Kfx_LowerSaturationLimit;
  } else {
    acvh_controller_mark1_B.pitch_err = acvh_controller_mark1_B.SignPreSat;
  }

  // End of Saturate: '<S107>/Saturation'

  // Gain: '<S2>/-1'
  acvh_controller_mark1_B.u = acvh_controller_mark1_P.u_Gain *
    acvh_controller_mark1_B.pitch_err;

  // Sum: '<S2>/Sum3'
  acvh_controller_mark1_B.pitch_err = acvh_controller_mark1_B.u -
    acvh_controller_mark1_B.VectorConcatenate[1];

  // Gain: '<S202>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S194>/Filter'
  //   Gain: '<S193>/Derivative Gain'
  //   Sum: '<S194>/SumD'

  acvh_controller_mark1_B.FilterCoefficient_pi =
    (acvh_controller_mark1_P.tau_pitch1_D * acvh_controller_mark1_B.pitch_err -
     acvh_controller_mark1_DW.Filter_DSTATE_b) *
    acvh_controller_mark1_P.tau_pitch1_N;

  // Sum: '<S208>/Sum' incorporates:
  //   DiscreteIntegrator: '<S199>/Integrator'
  //   Gain: '<S204>/Proportional Gain'

  tau_pitch = (acvh_controller_mark1_P.tau_pitch1_P *
               acvh_controller_mark1_B.pitch_err +
               acvh_controller_mark1_DW.Integrator_DSTATE_ji) +
    acvh_controller_mark1_B.FilterCoefficient_pi;

  // Saturate: '<S206>/Saturation'
  if (tau_pitch > acvh_controller_mark1_P.tau_pitch1_UpperSaturationLimit) {
    // Sum: '<S208>/Sum' incorporates:
    //   Saturate: '<S206>/Saturation'

    tau_pitch = acvh_controller_mark1_P.tau_pitch1_UpperSaturationLimit;
  } else {
    if (tau_pitch < acvh_controller_mark1_P.tau_pitch1_LowerSaturationLimit) {
      // Sum: '<S208>/Sum' incorporates:
      //   Saturate: '<S206>/Saturation'

      tau_pitch = acvh_controller_mark1_P.tau_pitch1_LowerSaturationLimit;
    }
  }

  // End of Saturate: '<S206>/Saturation'

  // RateLimiter: '<S2>/Rate Limiter3'
  rtb_ZeroGain = tau_pitch - acvh_controller_mark1_DW.PrevY_d;
  if (rtb_ZeroGain > acvh_controller_mark1_P.RateLimiter3_RisingLim) {
    // RateLimiter: '<S2>/Rate Limiter3'
    acvh_controller_mark1_DW.PrevY_d +=
      acvh_controller_mark1_P.RateLimiter3_RisingLim;
  } else if (rtb_ZeroGain < acvh_controller_mark1_P.RateLimiter3_FallingLim) {
    // RateLimiter: '<S2>/Rate Limiter3'
    acvh_controller_mark1_DW.PrevY_d +=
      acvh_controller_mark1_P.RateLimiter3_FallingLim;
  } else {
    // RateLimiter: '<S2>/Rate Limiter3'
    acvh_controller_mark1_DW.PrevY_d = tau_pitch;
  }

  // End of RateLimiter: '<S2>/Rate Limiter3'

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (acvh_controller_mark1_B.des_vx == 0.0) {
    acvh_controller_mark1_B.tau_pitch_k = 0.0;
  } else {
    acvh_controller_mark1_B.tau_pitch_k = acvh_controller_mark1_DW.PrevY_d;
  }

  if (acvh_controller_mark1_B.des_vy == 0.0) {
    acvh_controller_mark1_B.tau_roll_k = 0.0;
  } else {
    acvh_controller_mark1_B.tau_roll_k = acvh_controller_mark1_DW.PrevY;
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'

  // SignalConversion generated from: '<S4>/Product1' incorporates:
  //   Constant: '<S4>/Constant'
  //   Sum: '<S4>/Add'

  tmp = acvh_controller_mark1_P.Constant_Value_n2 + tau_thrust;
  for (i = 0; i < 4; i++) {
    // Product: '<S4>/Product1' incorporates:
    //   Constant: '<S4>/Mixer matrix'
    //   SignalConversion generated from: '<S4>/Product1'

    rtb_ZeroGain = acvh_controller_mark1_P.Mixermatrix_Value[static_cast<int32_T>
      (i + 12)] * 0.0 + (acvh_controller_mark1_P.Mixermatrix_Value
                         [static_cast<int32_T>(i + 8)] *
                         acvh_controller_mark1_B.tau_roll_k +
                         (acvh_controller_mark1_P.Mixermatrix_Value[static_cast<
                          int32_T>(i + 4)] * acvh_controller_mark1_B.tau_pitch_k
                          + acvh_controller_mark1_P.Mixermatrix_Value[i] * tmp));

    // Gain: '<S4>/Gain1'
    rtb_ZeroGain = floor(acvh_controller_mark1_P.Gain1_Gain * rtb_ZeroGain);
    if (rtIsNaN(rtb_ZeroGain) || rtIsInf(rtb_ZeroGain)) {
      rtb_ZeroGain = 0.0;
    } else {
      rtb_ZeroGain = fmod(rtb_ZeroGain, 65536.0);
    }

    // Sum: '<S4>/Add1' incorporates:
    //   Gain: '<S4>/Gain1'

    acvh_controller_mark1_B.Add1[i] = static_cast<uint16_T>(rtb_ZeroGain < 0.0 ?
      static_cast<int32_T>(static_cast<uint16_T>(static_cast<int32_T>(-
      static_cast<int32_T>(static_cast<int16_T>(static_cast<uint16_T>
      (-rtb_ZeroGain)))))) : static_cast<int32_T>(static_cast<uint16_T>
      (rtb_ZeroGain)));
  }

  // MATLABSystem: '<S4>/PX4 PWM Output' incorporates:
  //   Constant: '<S4>/Reset'
  //   Logic: '<S4>/NOT'

  if (!acvh_controller_mark1_P.Reset_Value) {
    if (!acvh_controller_mark1_DW.obj_e.isArmed) {
      acvh_controller_mark1_DW.obj_e.isArmed = true;
      status = pwm_arm(&acvh_controller_mark1_DW.obj_e.pwmDevHandler,
                       &acvh_controller_mark1_DW.obj_e.armAdvertiseObj);
      acvh_controller_mark1_DW.obj_e.errorStatus = static_cast<uint16_T>(
        static_cast<int32_T>(static_cast<int32_T>
        (acvh_controller_mark1_DW.obj_e.errorStatus) | static_cast<int32_T>
        (status)));
    }

    for (i = 0; i < 8; i++) {
      acvh_controller_mark1_B.b_pwmValue[i] = 0U;
    }

    acvh_controller_mark1_B.b_pwmValue[0] = acvh_controller_mark1_B.Add1[0];
    acvh_controller_mark1_B.b_pwmValue[1] = acvh_controller_mark1_B.Add1[1];
    acvh_controller_mark1_B.b_pwmValue[2] = acvh_controller_mark1_B.Add1[2];
    acvh_controller_mark1_B.b_pwmValue[3] = acvh_controller_mark1_B.Add1[3];
    status = pwm_setServo(&acvh_controller_mark1_DW.obj_e.pwmDevHandler,
                          acvh_controller_mark1_DW.obj_e.servoCount,
                          acvh_controller_mark1_DW.obj_e.channelMask,
                          &acvh_controller_mark1_B.b_pwmValue[0],
                          acvh_controller_mark1_DW.obj_e.isMain,
                          &acvh_controller_mark1_DW.obj_e.actuatorAdvertiseObj);
    acvh_controller_mark1_DW.obj_e.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (acvh_controller_mark1_DW.obj_e.errorStatus) | static_cast<int32_T>(status)));
  } else {
    status = pwm_disarm(&acvh_controller_mark1_DW.obj_e.pwmDevHandler,
                        &acvh_controller_mark1_DW.obj_e.armAdvertiseObj);
    acvh_controller_mark1_DW.obj_e.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (acvh_controller_mark1_DW.obj_e.errorStatus) | static_cast<int32_T>(status)));
    acvh_controller_mark1_DW.obj_e.isArmed = false;
    status = pwm_resetServo(&acvh_controller_mark1_DW.obj_e.pwmDevHandler,
      acvh_controller_mark1_DW.obj_e.servoCount,
      acvh_controller_mark1_DW.obj_e.channelMask,
      acvh_controller_mark1_DW.obj_e.isMain,
      &acvh_controller_mark1_DW.obj_e.actuatorAdvertiseObj);
    acvh_controller_mark1_DW.obj_e.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (acvh_controller_mark1_DW.obj_e.errorStatus) | static_cast<int32_T>(status)));
  }

  if (acvh_controller_mark1_DW.obj_e.isMain) {
    status = pwm_forceFailsafe(&acvh_controller_mark1_DW.obj_e.pwmDevHandler,
      acvh_controller_mark1_P.Reset_Value);
    acvh_controller_mark1_DW.obj_e.errorStatus = static_cast<uint16_T>(
      static_cast<int32_T>(static_cast<int32_T>
      (acvh_controller_mark1_DW.obj_e.errorStatus) | static_cast<int32_T>(status)));
  }

  // End of MATLABSystem: '<S4>/PX4 PWM Output'
  // Gain: '<S91>/ZeroGain'
  rtb_ZeroGain = acvh_controller_mark1_P.ZeroGain_Gain *
    acvh_controller_mark1_B.SignPreSat;

  // DeadZone: '<S93>/DeadZone'
  if (acvh_controller_mark1_B.SignPreSat >
      acvh_controller_mark1_P.Kfx_UpperSaturationLimit) {
    acvh_controller_mark1_B.SignPreSat -=
      acvh_controller_mark1_P.Kfx_UpperSaturationLimit;
  } else if (acvh_controller_mark1_B.SignPreSat >=
             acvh_controller_mark1_P.Kfx_LowerSaturationLimit) {
    acvh_controller_mark1_B.SignPreSat = 0.0;
  } else {
    acvh_controller_mark1_B.SignPreSat -=
      acvh_controller_mark1_P.Kfx_LowerSaturationLimit;
  }

  // End of DeadZone: '<S93>/DeadZone'

  // RelationalOperator: '<S91>/NotEqual'
  rtb_NotEqual = (rtb_ZeroGain != acvh_controller_mark1_B.SignPreSat);

  // Signum: '<S91>/SignPreSat'
  if (acvh_controller_mark1_B.SignPreSat < 0.0) {
    acvh_controller_mark1_B.SignPreSat = -1.0;
  } else if (acvh_controller_mark1_B.SignPreSat > 0.0) {
    acvh_controller_mark1_B.SignPreSat = 1.0;
  } else if (acvh_controller_mark1_B.SignPreSat == 0.0) {
    acvh_controller_mark1_B.SignPreSat = 0.0;
  } else {
    acvh_controller_mark1_B.SignPreSat = (rtNaN);
  }

  // End of Signum: '<S91>/SignPreSat'

  // Gain: '<S97>/Integral Gain'
  acvh_controller_mark1_B.IntegralGain_j *= acvh_controller_mark1_P.Kfx_I;

  // Gain: '<S141>/ZeroGain'
  rtb_ZeroGain = acvh_controller_mark1_P.ZeroGain_Gain_b *
    acvh_controller_mark1_B.SignPreSat_c;

  // DeadZone: '<S143>/DeadZone'
  if (acvh_controller_mark1_B.SignPreSat_c >
      acvh_controller_mark1_P.Kfy_UpperSaturationLimit) {
    acvh_controller_mark1_B.SignPreSat_c -=
      acvh_controller_mark1_P.Kfy_UpperSaturationLimit;
  } else if (acvh_controller_mark1_B.SignPreSat_c >=
             acvh_controller_mark1_P.Kfy_LowerSaturationLimit) {
    acvh_controller_mark1_B.SignPreSat_c = 0.0;
  } else {
    acvh_controller_mark1_B.SignPreSat_c -=
      acvh_controller_mark1_P.Kfy_LowerSaturationLimit;
  }

  // End of DeadZone: '<S143>/DeadZone'

  // RelationalOperator: '<S141>/NotEqual'
  rtb_NotEqual_k = (rtb_ZeroGain != acvh_controller_mark1_B.SignPreSat_c);

  // Signum: '<S141>/SignPreSat'
  if (acvh_controller_mark1_B.SignPreSat_c < 0.0) {
    acvh_controller_mark1_B.SignPreSat_c = -1.0;
  } else if (acvh_controller_mark1_B.SignPreSat_c > 0.0) {
    acvh_controller_mark1_B.SignPreSat_c = 1.0;
  } else if (acvh_controller_mark1_B.SignPreSat_c == 0.0) {
    acvh_controller_mark1_B.SignPreSat_c = 0.0;
  } else {
    acvh_controller_mark1_B.SignPreSat_c = (rtNaN);
  }

  // End of Signum: '<S141>/SignPreSat'

  // Gain: '<S147>/Integral Gain'
  rtb_fcn3 *= acvh_controller_mark1_P.Kfy_I;

  // Logic: '<S312>/NOT' incorporates:
  //   MATLABSystem: '<S312>/SourceBlock'

  acvh_controller_mark1_B.NOT = !b_varargout_1_0;

  // SignalConversion generated from: '<S5>/Bus Selector'
  acvh_controller_mark1_B.r = acvh_controller_mark1_B.In1_f.r;

  // Logic: '<S325>/NOT' incorporates:
  //   MATLABSystem: '<S325>/SourceBlock'

  acvh_controller_mark1_B.NOT_a = !b_varargout_1;

  // MATLABSystem: '<S313>/SourceBlock' incorporates:
  //   Inport: '<S316>/In1'

  b_varargout_1 = uORB_read_step(acvh_controller_mark1_DW.obj_j.orbMetadataObj,
    &acvh_controller_mark1_DW.obj_j.eventStructObj,
    &acvh_controller_mark1_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S313>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S316>/Enable'

  if (b_varargout_1) {
    acvh_controller_mark1_B.In1_p = acvh_controller_mark1_B.b_varargout_2_c;
    srUpdateBC(acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_g);
  }

  // End of MATLABSystem: '<S313>/SourceBlock'
  // End of Outputs for SubSystem: '<S313>/Enabled Subsystem'

  // SignalConversion generated from: '<S3>/Bus Selector1'
  acvh_controller_mark1_B.pressure = acvh_controller_mark1_B.In1_p.pressure;

  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = uORB_read_step(acvh_controller_mark1_DW.obj_l.orbMetadataObj,
    &acvh_controller_mark1_DW.obj_l.eventStructObj,
    &acvh_controller_mark1_B.BusAssignment, false, 1.0);

  // Logic: '<S6>/NOT' incorporates:
  //   MATLABSystem: '<S6>/SourceBlock'

  acvh_controller_mark1_B.NOT_m = !b_varargout_1;

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S8>/Enable'

  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S8>/In1'

  if (b_varargout_1) {
    acvh_controller_mark1_B.In1_a = acvh_controller_mark1_B.BusAssignment;
    srUpdateBC(acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_c);
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // BusAssignment: '<S1>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'
  //   Inport: '<S8>/In1'

  acvh_controller_mark1_B.BusAssignment = acvh_controller_mark1_B.In1_a;
  acvh_controller_mark1_B.BusAssignment.armed =
    acvh_controller_mark1_P.Constant_Value_a;

  // MATLABSystem: '<S7>/SinkBlock' incorporates:
  //   BusAssignment: '<S1>/Bus Assignment'

  uORB_write_step(acvh_controller_mark1_DW.obj_en.orbMetadataObj,
                  &acvh_controller_mark1_DW.obj_en.orbAdvertiseObj,
                  &acvh_controller_mark1_B.BusAssignment);

  // Update for DiscreteIntegrator: '<S50>/Integrator'
  acvh_controller_mark1_DW.Integrator_DSTATE = Integrator_tmp + Integrator;

  // Update for DiscreteTransferFcn: '<S43>/Filter Differentiator TF'
  acvh_controller_mark1_DW.FilterDifferentiatorTF_states =
    acvh_controller_mark1_B.denAccum;

  // DataTypeConversion: '<S141>/DataTypeConv1'
  if (rtIsNaN(acvh_controller_mark1_B.SignPreSat_c)) {
    rtb_ZeroGain = 0.0;
  } else {
    rtb_ZeroGain = fmod(acvh_controller_mark1_B.SignPreSat_c, 256.0);
  }

  // Signum: '<S141>/SignPreIntegrator'
  if (rtb_fcn3 < 0.0) {
    // DataTypeConversion: '<S141>/DataTypeConv2'
    Integrator_tmp = -1.0;
  } else if (rtb_fcn3 > 0.0) {
    // DataTypeConversion: '<S141>/DataTypeConv2'
    Integrator_tmp = 1.0;
  } else if (rtb_fcn3 == 0.0) {
    // DataTypeConversion: '<S141>/DataTypeConv2'
    Integrator_tmp = 0.0;
  } else {
    // DataTypeConversion: '<S141>/DataTypeConv2'
    Integrator_tmp = (rtNaN);
  }

  // End of Signum: '<S141>/SignPreIntegrator'

  // DataTypeConversion: '<S141>/DataTypeConv2'
  if (rtIsNaN(Integrator_tmp)) {
    Integrator_tmp = 0.0;
  } else {
    Integrator_tmp = fmod(Integrator_tmp, 256.0);
  }

  // Switch: '<S141>/Switch' incorporates:
  //   Constant: '<S141>/Constant1'
  //   DataTypeConversion: '<S141>/DataTypeConv1'
  //   DataTypeConversion: '<S141>/DataTypeConv2'
  //   Logic: '<S141>/AND3'
  //   RelationalOperator: '<S141>/Equal1'

  if (rtb_NotEqual_k && ((rtb_ZeroGain < 0.0 ? static_cast<int32_T>(static_cast<
         int8_T>(static_cast<int32_T>(-static_cast<int32_T>(static_cast<int8_T>(
             static_cast<uint8_T>(-rtb_ZeroGain)))))) : static_cast<int32_T>(
         static_cast<int8_T>(static_cast<uint8_T>(rtb_ZeroGain)))) ==
                         (Integrator_tmp < 0.0 ? static_cast<int32_T>(
         static_cast<int8_T>(static_cast<int32_T>(-static_cast<int32_T>(
            static_cast<int8_T>(static_cast<uint8_T>(-Integrator_tmp)))))) :
                          static_cast<int32_T>(static_cast<int8_T>
         (static_cast<uint8_T>(Integrator_tmp)))))) {
    rtb_fcn3 = acvh_controller_mark1_P.Constant1_Value_o;
  }

  // End of Switch: '<S141>/Switch'

  // Update for DiscreteIntegrator: '<S150>/Integrator'
  acvh_controller_mark1_DW.Integrator_DSTATE_m +=
    acvh_controller_mark1_P.Integrator_gainval_i * rtb_fcn3;

  // Update for DiscreteIntegrator: '<S145>/Filter'
  acvh_controller_mark1_DW.Filter_DSTATE +=
    acvh_controller_mark1_P.Filter_gainval *
    acvh_controller_mark1_B.Integrator_e;

  // Update for DiscreteIntegrator: '<S247>/Integrator' incorporates:
  //   Gain: '<S244>/Integral Gain'

  acvh_controller_mark1_DW.Integrator_DSTATE_j +=
    acvh_controller_mark1_P.tau_roll1_I * acvh_controller_mark1_B.roll_err *
    acvh_controller_mark1_P.Integrator_gainval_n;

  // Update for DiscreteIntegrator: '<S242>/Filter'
  acvh_controller_mark1_DW.Filter_DSTATE_d +=
    acvh_controller_mark1_P.Filter_gainval_p * acvh_controller_mark1_B.Filter_f;

  // DataTypeConversion: '<S91>/DataTypeConv1'
  if (rtIsNaN(acvh_controller_mark1_B.SignPreSat)) {
    rtb_ZeroGain = 0.0;
  } else {
    rtb_ZeroGain = fmod(acvh_controller_mark1_B.SignPreSat, 256.0);
  }

  // Signum: '<S91>/SignPreIntegrator'
  if (acvh_controller_mark1_B.IntegralGain_j < 0.0) {
    // DataTypeConversion: '<S91>/DataTypeConv2'
    Integrator_tmp = -1.0;
  } else if (acvh_controller_mark1_B.IntegralGain_j > 0.0) {
    // DataTypeConversion: '<S91>/DataTypeConv2'
    Integrator_tmp = 1.0;
  } else if (acvh_controller_mark1_B.IntegralGain_j == 0.0) {
    // DataTypeConversion: '<S91>/DataTypeConv2'
    Integrator_tmp = 0.0;
  } else {
    // DataTypeConversion: '<S91>/DataTypeConv2'
    Integrator_tmp = (rtNaN);
  }

  // End of Signum: '<S91>/SignPreIntegrator'

  // DataTypeConversion: '<S91>/DataTypeConv2'
  if (rtIsNaN(Integrator_tmp)) {
    Integrator_tmp = 0.0;
  } else {
    Integrator_tmp = fmod(Integrator_tmp, 256.0);
  }

  // Switch: '<S91>/Switch' incorporates:
  //   Constant: '<S91>/Constant1'
  //   DataTypeConversion: '<S91>/DataTypeConv1'
  //   DataTypeConversion: '<S91>/DataTypeConv2'
  //   Logic: '<S91>/AND3'
  //   RelationalOperator: '<S91>/Equal1'

  if (rtb_NotEqual && ((rtb_ZeroGain < 0.0 ? static_cast<int32_T>
                        (static_cast<int8_T>(static_cast<int32_T>
          (-static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>
             (-rtb_ZeroGain)))))) : static_cast<int32_T>(static_cast<int8_T>(
          static_cast<uint8_T>(rtb_ZeroGain)))) == (Integrator_tmp < 0.0 ?
        static_cast<int32_T>(static_cast<int8_T>(static_cast<int32_T>(-
           static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>
             (-Integrator_tmp)))))) : static_cast<int32_T>(static_cast<int8_T>(
          static_cast<uint8_T>(Integrator_tmp)))))) {
    acvh_controller_mark1_B.IntegralGain_j =
      acvh_controller_mark1_P.Constant1_Value;
  }

  // End of Switch: '<S91>/Switch'

  // Update for DiscreteIntegrator: '<S100>/Integrator'
  acvh_controller_mark1_DW.Integrator_DSTATE_e +=
    acvh_controller_mark1_P.Integrator_gainval_c *
    acvh_controller_mark1_B.IntegralGain_j;

  // Update for DiscreteIntegrator: '<S95>/Filter'
  acvh_controller_mark1_DW.Filter_DSTATE_d4 +=
    acvh_controller_mark1_P.Filter_gainval_f *
    acvh_controller_mark1_B.FilterCoefficient_d;

  // Update for DiscreteIntegrator: '<S199>/Integrator' incorporates:
  //   Gain: '<S196>/Integral Gain'

  acvh_controller_mark1_DW.Integrator_DSTATE_ji +=
    acvh_controller_mark1_P.tau_pitch1_I * acvh_controller_mark1_B.pitch_err *
    acvh_controller_mark1_P.Integrator_gainval_p;

  // Update for DiscreteIntegrator: '<S194>/Filter'
  acvh_controller_mark1_DW.Filter_DSTATE_b +=
    acvh_controller_mark1_P.Filter_gainval_n *
    acvh_controller_mark1_B.FilterCoefficient_pi;

  // External mode
  rtExtModeUploadCheckTrigger(1);

  {                                    // Sample time: [0.001s, 0.0s]
    rtExtModeUpload(0, (real_T)acvh_controller_mark1_M->Timing.taskTime0);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.001s, 0.0s]
    if ((rtmGetTFinal(acvh_controller_mark1_M)!=-1) &&
        !((rtmGetTFinal(acvh_controller_mark1_M)-
           acvh_controller_mark1_M->Timing.taskTime0) >
          acvh_controller_mark1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(acvh_controller_mark1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(acvh_controller_mark1_M)) {
      rtmSetErrorStatus(acvh_controller_mark1_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  acvh_controller_mark1_M->Timing.taskTime0 =
    ((time_T)(++acvh_controller_mark1_M->Timing.clockTick0)) *
    acvh_controller_mark1_M->Timing.stepSize0;
}

// Model initialize function
void acvh_controller_mark1_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(acvh_controller_mark1_M, -1);
  acvh_controller_mark1_M->Timing.stepSize0 = 0.001;

  // External mode info
  acvh_controller_mark1_M->Sizes.checksums[0] = (3879447087U);
  acvh_controller_mark1_M->Sizes.checksums[1] = (505237397U);
  acvh_controller_mark1_M->Sizes.checksums[2] = (2269478722U);
  acvh_controller_mark1_M->Sizes.checksums[3] = (2640668163U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    acvh_controller_mark1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_c;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_o;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)
      &acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_g;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &acvh_controller_mark1_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &acvh_controller_mark1_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &acvh_controller_mark1_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)
      &acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(acvh_controller_mark1_M->extModeInfo,
      &acvh_controller_mark1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(acvh_controller_mark1_M->extModeInfo,
                        acvh_controller_mark1_M->Sizes.checksums);
    rteiSetTPtr(acvh_controller_mark1_M->extModeInfo, rtmGetTPtr
                (acvh_controller_mark1_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    acvh_controller_mark1_M->SpecialInfo.mappingInfo = (&dtInfo);
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

    // InitializeConditions for DiscreteIntegrator: '<S50>/Integrator'
    acvh_controller_mark1_DW.Integrator_DSTATE =
      acvh_controller_mark1_P.DiscretePIDController1_Initia_j;

    // InitializeConditions for DiscreteTransferFcn: '<S43>/Filter Differentiator TF' 
    acvh_controller_mark1_DW.FilterDifferentiatorTF_states =
      acvh_controller_mark1_P.DiscretePIDController1_InitialC;

    // InitializeConditions for DiscreteIntegrator: '<S150>/Integrator'
    acvh_controller_mark1_DW.Integrator_DSTATE_m =
      acvh_controller_mark1_P.Kfy_InitialConditionForIntegrat;

    // InitializeConditions for DiscreteIntegrator: '<S145>/Filter'
    acvh_controller_mark1_DW.Filter_DSTATE =
      acvh_controller_mark1_P.Kfy_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S247>/Integrator'
    acvh_controller_mark1_DW.Integrator_DSTATE_j =
      acvh_controller_mark1_P.tau_roll1_InitialConditionForIn;

    // InitializeConditions for DiscreteIntegrator: '<S242>/Filter'
    acvh_controller_mark1_DW.Filter_DSTATE_d =
      acvh_controller_mark1_P.tau_roll1_InitialConditionForFi;

    // InitializeConditions for RateLimiter: '<S2>/Rate Limiter4'
    acvh_controller_mark1_DW.PrevY = acvh_controller_mark1_P.RateLimiter4_IC;

    // InitializeConditions for DiscreteIntegrator: '<S100>/Integrator'
    acvh_controller_mark1_DW.Integrator_DSTATE_e =
      acvh_controller_mark1_P.Kfx_InitialConditionForIntegrat;

    // InitializeConditions for DiscreteIntegrator: '<S95>/Filter'
    acvh_controller_mark1_DW.Filter_DSTATE_d4 =
      acvh_controller_mark1_P.Kfx_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S199>/Integrator'
    acvh_controller_mark1_DW.Integrator_DSTATE_ji =
      acvh_controller_mark1_P.tau_pitch1_InitialConditionForI;

    // InitializeConditions for DiscreteIntegrator: '<S194>/Filter'
    acvh_controller_mark1_DW.Filter_DSTATE_b =
      acvh_controller_mark1_P.tau_pitch1_InitialConditionForF;

    // InitializeConditions for RateLimiter: '<S2>/Rate Limiter3'
    acvh_controller_mark1_DW.PrevY_d = acvh_controller_mark1_P.RateLimiter3_IC;

    // SystemInitialize for Enabled SubSystem: '<S325>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S326>/Out1' incorporates:
    //   Inport: '<S326>/In1'

    acvh_controller_mark1_B.In1_f = acvh_controller_mark1_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S325>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S312>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S315>/Out1' incorporates:
    //   Inport: '<S315>/In1'

    acvh_controller_mark1_B.In1 = acvh_controller_mark1_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S312>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S313>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S316>/Out1' incorporates:
    //   Inport: '<S316>/In1'

    acvh_controller_mark1_B.In1_p = acvh_controller_mark1_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S313>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S8>/Out1' incorporates:
    //   Inport: '<S8>/In1'

    acvh_controller_mark1_B.In1_a = acvh_controller_mark1_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S325>/SourceBlock'
    acvh_controller_mark1_DW.obj.matlabCodegenIsDeleted = false;
    acvh_controller_mark1_DW.obj.isSetupComplete = false;
    acvh_controller_mark1_DW.obj.isInitialized = 1;
    acvh_controller_mark1_DW.obj.orbMetadataObj = ORB_ID(manual_control_setpoint);
    uORB_read_initialize(acvh_controller_mark1_DW.obj.orbMetadataObj,
                         &acvh_controller_mark1_DW.obj.eventStructObj);
    acvh_controller_mark1_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<S312>/SourceBlock'
    acvh_controller_mark1_DW.obj_ji.matlabCodegenIsDeleted = false;
    acvh_controller_mark1_DW.obj_ji.isSetupComplete = false;
    acvh_controller_mark1_DW.obj_ji.isInitialized = 1;
    acvh_controller_mark1_DW.obj_ji.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(acvh_controller_mark1_DW.obj_ji.orbMetadataObj,
                         &acvh_controller_mark1_DW.obj_ji.eventStructObj);
    acvh_controller_mark1_DW.obj_ji.isSetupComplete = true;

    // Start for MATLABSystem: '<S4>/PX4 PWM Output' incorporates:
    //   Constant: '<S4>/Reset'

    acvh_controller_mark1_DW.obj_e.errorStatus = 0U;
    acvh_controller_mark1_DW.obj_e.isInitialized = 0;
    acvh_controller_mark1_DW.obj_e.matlabCodegenIsDeleted = false;
    acvh_controlle_SystemCore_setup(&acvh_controller_mark1_DW.obj_e, rtb_NOT,
      acvh_controller_mark1_P.Reset_Value);

    // Start for MATLABSystem: '<S313>/SourceBlock'
    acvh_controller_mark1_DW.obj_j.matlabCodegenIsDeleted = false;
    acvh_controller_mark1_DW.obj_j.isSetupComplete = false;
    acvh_controller_mark1_DW.obj_j.isInitialized = 1;
    acvh_controller_mark1_DW.obj_j.orbMetadataObj = ORB_ID(sensor_baro);
    uORB_read_initialize(acvh_controller_mark1_DW.obj_j.orbMetadataObj,
                         &acvh_controller_mark1_DW.obj_j.eventStructObj);
    acvh_controller_mark1_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/SourceBlock'
    acvh_controller_mark1_DW.obj_l.matlabCodegenIsDeleted = false;
    acvh_controller_mark1_DW.obj_l.isSetupComplete = false;
    acvh_controller_mark1_DW.obj_l.isInitialized = 1;
    acvh_controller_mark1_DW.obj_l.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(acvh_controller_mark1_DW.obj_l.orbMetadataObj,
                         &acvh_controller_mark1_DW.obj_l.eventStructObj);
    acvh_controller_mark1_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S7>/SinkBlock' incorporates:
    //   BusAssignment: '<S1>/Bus Assignment'

    acvh_controller_mark1_DW.obj_en.matlabCodegenIsDeleted = false;
    acvh_controller_mark1_DW.obj_en.isSetupComplete = false;
    acvh_controller_mark1_DW.obj_en.isInitialized = 1;
    acvh_controller_mark1_DW.obj_en.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_write_initialize(acvh_controller_mark1_DW.obj_en.orbMetadataObj,
                          &acvh_controller_mark1_DW.obj_en.orbAdvertiseObj,
                          &rtb_BusAssignment, 1);
    acvh_controller_mark1_DW.obj_en.isSetupComplete = true;
  }
}

// Model terminate function
void acvh_controller_mark1_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S325>/SourceBlock'
  if (!acvh_controller_mark1_DW.obj.matlabCodegenIsDeleted) {
    acvh_controller_mark1_DW.obj.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark1_DW.obj.isInitialized == 1) &&
        acvh_controller_mark1_DW.obj.isSetupComplete) {
      uORB_read_terminate(&acvh_controller_mark1_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S325>/SourceBlock'

  // Terminate for MATLABSystem: '<S312>/SourceBlock'
  if (!acvh_controller_mark1_DW.obj_ji.matlabCodegenIsDeleted) {
    acvh_controller_mark1_DW.obj_ji.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark1_DW.obj_ji.isInitialized == 1) &&
        acvh_controller_mark1_DW.obj_ji.isSetupComplete) {
      uORB_read_terminate(&acvh_controller_mark1_DW.obj_ji.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S312>/SourceBlock'

  // Terminate for MATLABSystem: '<S4>/PX4 PWM Output'
  if (!acvh_controller_mark1_DW.obj_e.matlabCodegenIsDeleted) {
    acvh_controller_mark1_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark1_DW.obj_e.isInitialized == 1) &&
        acvh_controller_mark1_DW.obj_e.isSetupComplete) {
      status = pwm_disarm(&acvh_controller_mark1_DW.obj_e.pwmDevHandler,
                          &acvh_controller_mark1_DW.obj_e.armAdvertiseObj);
      acvh_controller_mark1_DW.obj_e.errorStatus = static_cast<uint16_T>(
        static_cast<int32_T>(static_cast<int32_T>
        (acvh_controller_mark1_DW.obj_e.errorStatus) | static_cast<int32_T>
        (status)));
      status = pwm_resetServo(&acvh_controller_mark1_DW.obj_e.pwmDevHandler,
        acvh_controller_mark1_DW.obj_e.servoCount,
        acvh_controller_mark1_DW.obj_e.channelMask,
        acvh_controller_mark1_DW.obj_e.isMain,
        &acvh_controller_mark1_DW.obj_e.actuatorAdvertiseObj);
      acvh_controller_mark1_DW.obj_e.errorStatus = static_cast<uint16_T>(
        static_cast<int32_T>(static_cast<int32_T>
        (acvh_controller_mark1_DW.obj_e.errorStatus) | static_cast<int32_T>
        (status)));
      status = pwm_close(&acvh_controller_mark1_DW.obj_e.pwmDevHandler,
                         &acvh_controller_mark1_DW.obj_e.actuatorAdvertiseObj,
                         &acvh_controller_mark1_DW.obj_e.armAdvertiseObj);
      acvh_controller_mark1_DW.obj_e.errorStatus = static_cast<uint16_T>(
        static_cast<int32_T>(static_cast<int32_T>
        (acvh_controller_mark1_DW.obj_e.errorStatus) | static_cast<int32_T>
        (status)));
    }
  }

  // End of Terminate for MATLABSystem: '<S4>/PX4 PWM Output'

  // Terminate for MATLABSystem: '<S313>/SourceBlock'
  if (!acvh_controller_mark1_DW.obj_j.matlabCodegenIsDeleted) {
    acvh_controller_mark1_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark1_DW.obj_j.isInitialized == 1) &&
        acvh_controller_mark1_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&acvh_controller_mark1_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S313>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!acvh_controller_mark1_DW.obj_l.matlabCodegenIsDeleted) {
    acvh_controller_mark1_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark1_DW.obj_l.isInitialized == 1) &&
        acvh_controller_mark1_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&acvh_controller_mark1_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<S7>/SinkBlock'
  if (!acvh_controller_mark1_DW.obj_en.matlabCodegenIsDeleted) {
    acvh_controller_mark1_DW.obj_en.matlabCodegenIsDeleted = true;
    if ((acvh_controller_mark1_DW.obj_en.isInitialized == 1) &&
        acvh_controller_mark1_DW.obj_en.isSetupComplete) {
      uORB_write_terminate(&acvh_controller_mark1_DW.obj_en.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S7>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
