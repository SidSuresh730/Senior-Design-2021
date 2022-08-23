//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: acvh_controller_mark1.h
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
#ifndef RTW_HEADER_acvh_controller_mark1_h_
#define RTW_HEADER_acvh_controller_mark1_h_
#include <math.h>
#include <float.h>
#include <stddef.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "MW_PX4_PWM.h"
#include "acvh_controller_mark1_types.h"

// Shared type includes
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

// Block signals (default storage)
typedef struct {
  px4_Bus_vehicle_odometry In1;        // '<S315>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_manual_control_setpoint In1_f;// '<S326>/In1'
  px4_Bus_manual_control_setpoint b_varargout_2_m;
  px4_Bus_sensor_baro In1_p;           // '<S316>/In1'
  px4_Bus_sensor_baro b_varargout_2_c;
  px4_Bus_actuator_armed In1_a;        // '<S8>/In1'
  px4_Bus_actuator_armed BusAssignment;// '<S1>/Bus Assignment'
  uint16_T b_pwmValue[8];
  real_T DataTypeConversion4;          // '<S3>/Data Type Conversion4'
  real_T Sum;                          // '<S5>/Sum'
  real_T des_vx;                       // '<S2>/Saturation2'
  real_T Sum1;                         // '<S5>/Sum1'
  real_T des_vy;                       // '<S2>/Saturation3'
  real_T VectorConcatenate[3];         // '<S317>/Vector Concatenate'
  real_T MatrixMultiply[2];            // '<S13>/Matrix Multiply'
  real_T Saturation;                   // '<S157>/Saturation'
  real_T u;                            // '<S2>/-1'
  real_T tau_roll_k;                   // '<S2>/MATLAB Function1'
  real_T tau_pitch_k;                  // '<S2>/MATLAB Function1'
  real_T denAccum;
  real_T Filter_f;                     // '<S145>/Filter'
  real_T SignPreSat_c;                 // '<S141>/SignPreSat'
  real_T Integrator_e;                 // '<S247>/Integrator'
  real_T roll_err;                     // '<S2>/Sum4'
  real_T pitch_err;                    // '<S2>/Sum3'
  real_T SignPreSat;                   // '<S91>/SignPreSat'
  real_T IntegralGain_j;               // '<S97>/Integral Gain'
  real_T FilterCoefficient_pi;         // '<S202>/Filter Coefficient'
  real_T FilterCoefficient_d;          // '<S103>/Filter Coefficient'
  uint16_T Add1[4];                    // '<S4>/Add1'
  real32_T z;
  real32_T Gain;                       // '<S5>/Gain'
  real32_T des_z;                      // '<S2>/Saturation4'
  real32_T x;
  real32_T y;
  real32_T r;
  real32_T pressure;
  boolean_T NOT;                       // '<S312>/NOT'
  boolean_T NOT_a;                     // '<S325>/NOT'
  boolean_T NOT_m;                     // '<S6>/NOT'
} B_acvh_controller_mark1_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  px4_internal_block_Subscriber_T obj; // '<S325>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S313>/SourceBlock'
  px4_internal_block_Subscriber_T obj_ji;// '<S312>/SourceBlock'
  px4_internal_block_Subscriber_T obj_l;// '<S6>/SourceBlock'
  px4_internal_block_PWM_acvh_c_T obj_e;// '<S4>/PX4 PWM Output'
  px4_internal_block_Publisher__T obj_en;// '<S7>/SinkBlock'
  real_T Integrator_DSTATE;            // '<S50>/Integrator'
  real_T FilterDifferentiatorTF_states;// '<S43>/Filter Differentiator TF'
  real_T Integrator_DSTATE_m;          // '<S150>/Integrator'
  real_T Filter_DSTATE;                // '<S145>/Filter'
  real_T Integrator_DSTATE_j;          // '<S247>/Integrator'
  real_T Filter_DSTATE_d;              // '<S242>/Filter'
  real_T Integrator_DSTATE_e;          // '<S100>/Integrator'
  real_T Filter_DSTATE_d4;             // '<S95>/Filter'
  real_T Integrator_DSTATE_ji;         // '<S199>/Integrator'
  real_T Filter_DSTATE_b;              // '<S194>/Filter'
  real_T PrevY;                        // '<S2>/Rate Limiter4'
  real_T PrevY_d;                      // '<S2>/Rate Limiter3'
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      // '<S2>/Scope1'

  struct {
    void *LoggedData[2];
  } Scope5_PWORK;                      // '<S2>/Scope5'

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      // '<S2>/Scope3'

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      // '<S2>/Scope2'

  struct {
    void *LoggedData[2];
  } Scope6_PWORK;                      // '<S2>/Scope6'

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      // '<S2>/Scope4'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S325>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S319>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S319>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S319>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_g;// '<S313>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_o;// '<S312>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_c;// '<S6>/Enabled Subsystem'
} DW_acvh_controller_mark1_T;

// Parameters (default storage)
struct P_acvh_controller_mark1_T_ {
  real_T DiscretePIDController1_D;   // Mask Parameter: DiscretePIDController1_D
                                        //  Referenced by: '<S42>/Derivative Gain'

  real_T Kfy_D;                        // Mask Parameter: Kfy_D
                                          //  Referenced by: '<S144>/Derivative Gain'

  real_T tau_roll1_D;                  // Mask Parameter: tau_roll1_D
                                          //  Referenced by: '<S241>/Derivative Gain'

  real_T Kfx_D;                        // Mask Parameter: Kfx_D
                                          //  Referenced by: '<S94>/Derivative Gain'

  real_T tau_pitch1_D;                 // Mask Parameter: tau_pitch1_D
                                          //  Referenced by: '<S193>/Derivative Gain'

  real_T DiscretePIDController1_I;   // Mask Parameter: DiscretePIDController1_I
                                        //  Referenced by: '<S47>/Integral Gain'

  real_T tau_pitch1_I;                 // Mask Parameter: tau_pitch1_I
                                          //  Referenced by: '<S196>/Integral Gain'

  real_T Kfx_I;                        // Mask Parameter: Kfx_I
                                          //  Referenced by: '<S97>/Integral Gain'

  real_T tau_roll1_I;                  // Mask Parameter: tau_roll1_I
                                          //  Referenced by: '<S244>/Integral Gain'

  real_T Kfy_I;                        // Mask Parameter: Kfy_I
                                          //  Referenced by: '<S147>/Integral Gain'

  real_T DiscretePIDController1_InitialC;
                              // Mask Parameter: DiscretePIDController1_InitialC
                                 //  Referenced by: '<S43>/Filter Differentiator TF'

  real_T Kfy_InitialConditionForFilter;
                                // Mask Parameter: Kfy_InitialConditionForFilter
                                   //  Referenced by: '<S145>/Filter'

  real_T tau_roll1_InitialConditionForFi;
                              // Mask Parameter: tau_roll1_InitialConditionForFi
                                 //  Referenced by: '<S242>/Filter'

  real_T Kfx_InitialConditionForFilter;
                                // Mask Parameter: Kfx_InitialConditionForFilter
                                   //  Referenced by: '<S95>/Filter'

  real_T tau_pitch1_InitialConditionForF;
                              // Mask Parameter: tau_pitch1_InitialConditionForF
                                 //  Referenced by: '<S194>/Filter'

  real_T DiscretePIDController1_Initia_j;
                              // Mask Parameter: DiscretePIDController1_Initia_j
                                 //  Referenced by: '<S50>/Integrator'

  real_T Kfy_InitialConditionForIntegrat;
                              // Mask Parameter: Kfy_InitialConditionForIntegrat
                                 //  Referenced by: '<S150>/Integrator'

  real_T tau_roll1_InitialConditionForIn;
                              // Mask Parameter: tau_roll1_InitialConditionForIn
                                 //  Referenced by: '<S247>/Integrator'

  real_T Kfx_InitialConditionForIntegrat;
                              // Mask Parameter: Kfx_InitialConditionForIntegrat
                                 //  Referenced by: '<S100>/Integrator'

  real_T tau_pitch1_InitialConditionForI;
                              // Mask Parameter: tau_pitch1_InitialConditionForI
                                 //  Referenced by: '<S199>/Integrator'

  real_T Kfy_LowerSaturationLimit;   // Mask Parameter: Kfy_LowerSaturationLimit
                                        //  Referenced by:
                                        //    '<S157>/Saturation'
                                        //    '<S143>/DeadZone'

  real_T tau_roll1_LowerSaturationLimit;
                               // Mask Parameter: tau_roll1_LowerSaturationLimit
                                  //  Referenced by: '<S254>/Saturation'

  real_T Kfx_LowerSaturationLimit;   // Mask Parameter: Kfx_LowerSaturationLimit
                                        //  Referenced by:
                                        //    '<S107>/Saturation'
                                        //    '<S93>/DeadZone'

  real_T tau_pitch1_LowerSaturationLimit;
                              // Mask Parameter: tau_pitch1_LowerSaturationLimit
                                 //  Referenced by: '<S206>/Saturation'

  real_T DiscretePIDController1_N;   // Mask Parameter: DiscretePIDController1_N
                                        //  Referenced by:
                                        //    '<S52>/N Copy'
                                        //    '<S53>/Filter Coefficient'

  real_T Kfy_N;                        // Mask Parameter: Kfy_N
                                          //  Referenced by: '<S153>/Filter Coefficient'

  real_T tau_roll1_N;                  // Mask Parameter: tau_roll1_N
                                          //  Referenced by: '<S250>/Filter Coefficient'

  real_T Kfx_N;                        // Mask Parameter: Kfx_N
                                          //  Referenced by: '<S103>/Filter Coefficient'

  real_T tau_pitch1_N;                 // Mask Parameter: tau_pitch1_N
                                          //  Referenced by: '<S202>/Filter Coefficient'

  real_T DiscretePIDController1_P;   // Mask Parameter: DiscretePIDController1_P
                                        //  Referenced by: '<S55>/Proportional Gain'

  real_T Kfy_P;                        // Mask Parameter: Kfy_P
                                          //  Referenced by: '<S155>/Proportional Gain'

  real_T tau_roll1_P;                  // Mask Parameter: tau_roll1_P
                                          //  Referenced by: '<S252>/Proportional Gain'

  real_T Kfx_P;                        // Mask Parameter: Kfx_P
                                          //  Referenced by: '<S105>/Proportional Gain'

  real_T tau_pitch1_P;                 // Mask Parameter: tau_pitch1_P
                                          //  Referenced by: '<S204>/Proportional Gain'

  real_T Kfy_UpperSaturationLimit;   // Mask Parameter: Kfy_UpperSaturationLimit
                                        //  Referenced by:
                                        //    '<S157>/Saturation'
                                        //    '<S143>/DeadZone'

  real_T tau_roll1_UpperSaturationLimit;
                               // Mask Parameter: tau_roll1_UpperSaturationLimit
                                  //  Referenced by: '<S254>/Saturation'

  real_T Kfx_UpperSaturationLimit;   // Mask Parameter: Kfx_UpperSaturationLimit
                                        //  Referenced by:
                                        //    '<S107>/Saturation'
                                        //    '<S93>/DeadZone'

  real_T tau_pitch1_UpperSaturationLimit;
                              // Mask Parameter: tau_pitch1_UpperSaturationLimit
                                 //  Referenced by: '<S206>/Saturation'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S315>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S312>/Constant'

  px4_Bus_manual_control_setpoint Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                               //  Referenced by: '<S326>/Out1'

  px4_Bus_manual_control_setpoint Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                      //  Referenced by: '<S325>/Constant'

  px4_Bus_sensor_baro Out1_Y0_l;       // Computed Parameter: Out1_Y0_l
                                          //  Referenced by: '<S316>/Out1'

  px4_Bus_sensor_baro Constant_Value_j;// Computed Parameter: Constant_Value_j
                                          //  Referenced by: '<S313>/Constant'

  px4_Bus_actuator_armed Out1_Y0_n;    // Computed Parameter: Out1_Y0_n
                                          //  Referenced by: '<S8>/Out1'

  px4_Bus_actuator_armed Constant_Value_l;// Computed Parameter: Constant_Value_l
                                             //  Referenced by: '<S6>/Constant'

  real_T Constant_Value_p;             // Expression: 1
                                          //  Referenced by: '<S320>/Constant'

  real_T Constant_Value_o;             // Expression: 1
                                          //  Referenced by: '<S321>/Constant'

  real_T Constant_Value_na;            // Expression: 1
                                          //  Referenced by: '<S43>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S91>/Constant1'

  real_T Constant1_Value_o;            // Expression: 0
                                          //  Referenced by: '<S141>/Constant1'

  real_T Mixermatrix_Value[16];
                          // Expression: [1 -1 1 1;1 1 -1 1;1 -1 -1 -1;1 1 1 -1]
                             //  Referenced by: '<S4>/Mixer matrix'

  real_T Constant_Value_n2;            // Expression: 1
                                          //  Referenced by: '<S4>/Constant'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S50>/Integrator'

  real_T Tsamp_WtEt;                   // Computed Parameter: Tsamp_WtEt
                                          //  Referenced by: '<S45>/Tsamp'

  real_T FilterDifferentiatorTF_NumCoef[2];// Expression: [1 -1]
                                              //  Referenced by: '<S43>/Filter Differentiator TF'

  real_T Constant1_Value_i;            // Expression: 0
                                          //  Referenced by: '<S5>/Constant1'

  real_T Saturation2_UpperSat;         // Expression: 8
                                          //  Referenced by: '<S2>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -8
                                          //  Referenced by: '<S2>/Saturation2'

  real_T Saturation3_UpperSat;         // Expression: 8
                                          //  Referenced by: '<S2>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -8
                                          //  Referenced by: '<S2>/Saturation3'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S167>/Gain'

  real_T Integrator_gainval_i;       // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S150>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S145>/Filter'

  real_T Integrator_gainval_n;       // Computed Parameter: Integrator_gainval_n
                                        //  Referenced by: '<S247>/Integrator'

  real_T Filter_gainval_p;             // Computed Parameter: Filter_gainval_p
                                          //  Referenced by: '<S242>/Filter'

  real_T RateLimiter4_RisingLim;   // Computed Parameter: RateLimiter4_RisingLim
                                      //  Referenced by: '<S2>/Rate Limiter4'

  real_T RateLimiter4_FallingLim; // Computed Parameter: RateLimiter4_FallingLim
                                     //  Referenced by: '<S2>/Rate Limiter4'

  real_T RateLimiter4_IC;              // Expression: 0
                                          //  Referenced by: '<S2>/Rate Limiter4'

  real_T Integrator_gainval_c;       // Computed Parameter: Integrator_gainval_c
                                        //  Referenced by: '<S100>/Integrator'

  real_T Filter_gainval_f;             // Computed Parameter: Filter_gainval_f
                                          //  Referenced by: '<S95>/Filter'

  real_T u_Gain;                       // Expression: -1
                                          //  Referenced by: '<S2>/-1'

  real_T Integrator_gainval_p;       // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S199>/Integrator'

  real_T Filter_gainval_n;             // Computed Parameter: Filter_gainval_n
                                          //  Referenced by: '<S194>/Filter'

  real_T RateLimiter3_RisingLim;   // Computed Parameter: RateLimiter3_RisingLim
                                      //  Referenced by: '<S2>/Rate Limiter3'

  real_T RateLimiter3_FallingLim; // Computed Parameter: RateLimiter3_FallingLim
                                     //  Referenced by: '<S2>/Rate Limiter3'

  real_T RateLimiter3_IC;              // Expression: 0
                                          //  Referenced by: '<S2>/Rate Limiter3'

  real_T Gain1_Gain;                   // Expression: 1000
                                          //  Referenced by: '<S4>/Gain1'

  real_T ZeroGain_Gain;                // Expression: 0
                                          //  Referenced by: '<S91>/ZeroGain'

  real_T ZeroGain_Gain_b;              // Expression: 0
                                          //  Referenced by: '<S141>/ZeroGain'

  real32_T Deadband3_Start;            // Computed Parameter: Deadband3_Start
                                          //  Referenced by: '<S5>/Deadband3'

  real32_T Deadband3_End;              // Computed Parameter: Deadband3_End
                                          //  Referenced by: '<S5>/Deadband3'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S5>/Gain'

  real32_T Saturation4_UpperSat;     // Computed Parameter: Saturation4_UpperSat
                                        //  Referenced by: '<S2>/Saturation4'

  real32_T Saturation4_LowerSat;     // Computed Parameter: Saturation4_LowerSat
                                        //  Referenced by: '<S2>/Saturation4'

  real32_T Deadband_Start;             // Computed Parameter: Deadband_Start
                                          //  Referenced by: '<S5>/Deadband'

  real32_T Deadband_End;               // Computed Parameter: Deadband_End
                                          //  Referenced by: '<S5>/Deadband'

  real32_T Deadband1_Start;            // Computed Parameter: Deadband1_Start
                                          //  Referenced by: '<S5>/Deadband1'

  real32_T Deadband1_End;              // Computed Parameter: Deadband1_End
                                          //  Referenced by: '<S5>/Deadband1'

  boolean_T Reset_Value;               // Computed Parameter: Reset_Value
                                          //  Referenced by: '<S4>/Reset'

  boolean_T Constant_Value_a;          // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S1>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_acvh_controller_mark1_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_acvh_controller_mark1_T acvh_controller_mark1_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_acvh_controller_mark1_T acvh_controller_mark1_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_acvh_controller_mark1_T acvh_controller_mark1_DW;

//
//  Exported Global Signals
//
//  Note: Exported global signals are block signals with an exported global
//  storage class designation.  Code generation will declare the memory for
//  these signals and export their symbols.
//

#ifdef __cplusplus

extern "C" {

#endif

  extern real_T tau_thrust;            // '<S59>/Sum'
  extern real_T tau_roll;              // '<S254>/Saturation'
  extern real_T tau_pitch;             // '<S206>/Saturation'

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void acvh_controller_mark1_initialize(void);
  extern void acvh_controller_mark1_step(void);
  extern void acvh_controller_mark1_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_acvh_controller_mark_T *const acvh_controller_mark1_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Sum5' : Unused code path elimination
//  Block '<S289>/Derivative Gain' : Unused code path elimination
//  Block '<S290>/Filter' : Unused code path elimination
//  Block '<S290>/SumD' : Unused code path elimination
//  Block '<S292>/Integral Gain' : Unused code path elimination
//  Block '<S295>/Integrator' : Unused code path elimination
//  Block '<S298>/Filter Coefficient' : Unused code path elimination
//  Block '<S300>/Proportional Gain' : Unused code path elimination
//  Block '<S302>/Saturation' : Unused code path elimination
//  Block '<S304>/Sum' : Unused code path elimination
//  Block '<S313>/NOT' : Unused code path elimination
//  Block '<S5>/Deadband2' : Unused code path elimination
//  Block '<S43>/Passthrough for tuning' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'acvh_controller_mark1'
//  '<S1>'   : 'acvh_controller_mark1/Arm'
//  '<S2>'   : 'acvh_controller_mark1/Controller'
//  '<S3>'   : 'acvh_controller_mark1/ISM'
//  '<S4>'   : 'acvh_controller_mark1/OSM'
//  '<S5>'   : 'acvh_controller_mark1/Setpoint'
//  '<S6>'   : 'acvh_controller_mark1/Arm/PX4 uORB Read'
//  '<S7>'   : 'acvh_controller_mark1/Arm/PX4 uORB Write'
//  '<S8>'   : 'acvh_controller_mark1/Arm/PX4 uORB Read/Enabled Subsystem'
//  '<S9>'   : 'acvh_controller_mark1/Controller/Discrete PID Controller1'
//  '<S10>'  : 'acvh_controller_mark1/Controller/Kfx'
//  '<S11>'  : 'acvh_controller_mark1/Controller/Kfy'
//  '<S12>'  : 'acvh_controller_mark1/Controller/MATLAB Function1'
//  '<S13>'  : 'acvh_controller_mark1/Controller/Velocity conversion to body axes1'
//  '<S14>'  : 'acvh_controller_mark1/Controller/tau_pitch1'
//  '<S15>'  : 'acvh_controller_mark1/Controller/tau_roll1'
//  '<S16>'  : 'acvh_controller_mark1/Controller/tau_yaw1'
//  '<S17>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Anti-windup'
//  '<S18>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/D Gain'
//  '<S19>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Filter'
//  '<S20>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Filter ICs'
//  '<S21>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/I Gain'
//  '<S22>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Ideal P Gain'
//  '<S23>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S24>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Integrator'
//  '<S25>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Integrator ICs'
//  '<S26>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/N Copy'
//  '<S27>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/N Gain'
//  '<S28>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/P Copy'
//  '<S29>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Parallel P Gain'
//  '<S30>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Reset Signal'
//  '<S31>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Saturation'
//  '<S32>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S33>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Sum'
//  '<S34>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Sum Fdbk'
//  '<S35>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Tracking Mode'
//  '<S36>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S37>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S38>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S39>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/postSat Signal'
//  '<S40>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/preSat Signal'
//  '<S41>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Anti-windup/Passthrough'
//  '<S42>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/D Gain/Internal Parameters'
//  '<S43>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Filter/Disc. Trapezoidal Filter'
//  '<S44>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Filter/Disc. Trapezoidal Filter/Tsamp'
//  '<S45>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Filter/Disc. Trapezoidal Filter/Tsamp/Internal Ts'
//  '<S46>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S47>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/I Gain/Internal Parameters'
//  '<S48>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S49>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S50>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Integrator/Discrete'
//  '<S51>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Integrator ICs/Internal IC'
//  '<S52>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/N Copy/Internal Parameters'
//  '<S53>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/N Gain/Internal Parameters'
//  '<S54>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S55>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S56>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S57>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Saturation/Passthrough'
//  '<S58>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S59>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Sum/Sum_PID'
//  '<S60>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S61>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S62>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S63>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Tsamp - Integral/Passthrough'
//  '<S64>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S65>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S66>'  : 'acvh_controller_mark1/Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S67>'  : 'acvh_controller_mark1/Controller/Kfx/Anti-windup'
//  '<S68>'  : 'acvh_controller_mark1/Controller/Kfx/D Gain'
//  '<S69>'  : 'acvh_controller_mark1/Controller/Kfx/Filter'
//  '<S70>'  : 'acvh_controller_mark1/Controller/Kfx/Filter ICs'
//  '<S71>'  : 'acvh_controller_mark1/Controller/Kfx/I Gain'
//  '<S72>'  : 'acvh_controller_mark1/Controller/Kfx/Ideal P Gain'
//  '<S73>'  : 'acvh_controller_mark1/Controller/Kfx/Ideal P Gain Fdbk'
//  '<S74>'  : 'acvh_controller_mark1/Controller/Kfx/Integrator'
//  '<S75>'  : 'acvh_controller_mark1/Controller/Kfx/Integrator ICs'
//  '<S76>'  : 'acvh_controller_mark1/Controller/Kfx/N Copy'
//  '<S77>'  : 'acvh_controller_mark1/Controller/Kfx/N Gain'
//  '<S78>'  : 'acvh_controller_mark1/Controller/Kfx/P Copy'
//  '<S79>'  : 'acvh_controller_mark1/Controller/Kfx/Parallel P Gain'
//  '<S80>'  : 'acvh_controller_mark1/Controller/Kfx/Reset Signal'
//  '<S81>'  : 'acvh_controller_mark1/Controller/Kfx/Saturation'
//  '<S82>'  : 'acvh_controller_mark1/Controller/Kfx/Saturation Fdbk'
//  '<S83>'  : 'acvh_controller_mark1/Controller/Kfx/Sum'
//  '<S84>'  : 'acvh_controller_mark1/Controller/Kfx/Sum Fdbk'
//  '<S85>'  : 'acvh_controller_mark1/Controller/Kfx/Tracking Mode'
//  '<S86>'  : 'acvh_controller_mark1/Controller/Kfx/Tracking Mode Sum'
//  '<S87>'  : 'acvh_controller_mark1/Controller/Kfx/Tsamp - Integral'
//  '<S88>'  : 'acvh_controller_mark1/Controller/Kfx/Tsamp - Ngain'
//  '<S89>'  : 'acvh_controller_mark1/Controller/Kfx/postSat Signal'
//  '<S90>'  : 'acvh_controller_mark1/Controller/Kfx/preSat Signal'
//  '<S91>'  : 'acvh_controller_mark1/Controller/Kfx/Anti-windup/Disc. Clamping Parallel'
//  '<S92>'  : 'acvh_controller_mark1/Controller/Kfx/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S93>'  : 'acvh_controller_mark1/Controller/Kfx/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S94>'  : 'acvh_controller_mark1/Controller/Kfx/D Gain/Internal Parameters'
//  '<S95>'  : 'acvh_controller_mark1/Controller/Kfx/Filter/Disc. Forward Euler Filter'
//  '<S96>'  : 'acvh_controller_mark1/Controller/Kfx/Filter ICs/Internal IC - Filter'
//  '<S97>'  : 'acvh_controller_mark1/Controller/Kfx/I Gain/Internal Parameters'
//  '<S98>'  : 'acvh_controller_mark1/Controller/Kfx/Ideal P Gain/Passthrough'
//  '<S99>'  : 'acvh_controller_mark1/Controller/Kfx/Ideal P Gain Fdbk/Disabled'
//  '<S100>' : 'acvh_controller_mark1/Controller/Kfx/Integrator/Discrete'
//  '<S101>' : 'acvh_controller_mark1/Controller/Kfx/Integrator ICs/Internal IC'
//  '<S102>' : 'acvh_controller_mark1/Controller/Kfx/N Copy/Disabled'
//  '<S103>' : 'acvh_controller_mark1/Controller/Kfx/N Gain/Internal Parameters'
//  '<S104>' : 'acvh_controller_mark1/Controller/Kfx/P Copy/Disabled'
//  '<S105>' : 'acvh_controller_mark1/Controller/Kfx/Parallel P Gain/Internal Parameters'
//  '<S106>' : 'acvh_controller_mark1/Controller/Kfx/Reset Signal/Disabled'
//  '<S107>' : 'acvh_controller_mark1/Controller/Kfx/Saturation/Enabled'
//  '<S108>' : 'acvh_controller_mark1/Controller/Kfx/Saturation Fdbk/Disabled'
//  '<S109>' : 'acvh_controller_mark1/Controller/Kfx/Sum/Sum_PID'
//  '<S110>' : 'acvh_controller_mark1/Controller/Kfx/Sum Fdbk/Disabled'
//  '<S111>' : 'acvh_controller_mark1/Controller/Kfx/Tracking Mode/Disabled'
//  '<S112>' : 'acvh_controller_mark1/Controller/Kfx/Tracking Mode Sum/Passthrough'
//  '<S113>' : 'acvh_controller_mark1/Controller/Kfx/Tsamp - Integral/Passthrough'
//  '<S114>' : 'acvh_controller_mark1/Controller/Kfx/Tsamp - Ngain/Passthrough'
//  '<S115>' : 'acvh_controller_mark1/Controller/Kfx/postSat Signal/Forward_Path'
//  '<S116>' : 'acvh_controller_mark1/Controller/Kfx/preSat Signal/Forward_Path'
//  '<S117>' : 'acvh_controller_mark1/Controller/Kfy/Anti-windup'
//  '<S118>' : 'acvh_controller_mark1/Controller/Kfy/D Gain'
//  '<S119>' : 'acvh_controller_mark1/Controller/Kfy/Filter'
//  '<S120>' : 'acvh_controller_mark1/Controller/Kfy/Filter ICs'
//  '<S121>' : 'acvh_controller_mark1/Controller/Kfy/I Gain'
//  '<S122>' : 'acvh_controller_mark1/Controller/Kfy/Ideal P Gain'
//  '<S123>' : 'acvh_controller_mark1/Controller/Kfy/Ideal P Gain Fdbk'
//  '<S124>' : 'acvh_controller_mark1/Controller/Kfy/Integrator'
//  '<S125>' : 'acvh_controller_mark1/Controller/Kfy/Integrator ICs'
//  '<S126>' : 'acvh_controller_mark1/Controller/Kfy/N Copy'
//  '<S127>' : 'acvh_controller_mark1/Controller/Kfy/N Gain'
//  '<S128>' : 'acvh_controller_mark1/Controller/Kfy/P Copy'
//  '<S129>' : 'acvh_controller_mark1/Controller/Kfy/Parallel P Gain'
//  '<S130>' : 'acvh_controller_mark1/Controller/Kfy/Reset Signal'
//  '<S131>' : 'acvh_controller_mark1/Controller/Kfy/Saturation'
//  '<S132>' : 'acvh_controller_mark1/Controller/Kfy/Saturation Fdbk'
//  '<S133>' : 'acvh_controller_mark1/Controller/Kfy/Sum'
//  '<S134>' : 'acvh_controller_mark1/Controller/Kfy/Sum Fdbk'
//  '<S135>' : 'acvh_controller_mark1/Controller/Kfy/Tracking Mode'
//  '<S136>' : 'acvh_controller_mark1/Controller/Kfy/Tracking Mode Sum'
//  '<S137>' : 'acvh_controller_mark1/Controller/Kfy/Tsamp - Integral'
//  '<S138>' : 'acvh_controller_mark1/Controller/Kfy/Tsamp - Ngain'
//  '<S139>' : 'acvh_controller_mark1/Controller/Kfy/postSat Signal'
//  '<S140>' : 'acvh_controller_mark1/Controller/Kfy/preSat Signal'
//  '<S141>' : 'acvh_controller_mark1/Controller/Kfy/Anti-windup/Disc. Clamping Parallel'
//  '<S142>' : 'acvh_controller_mark1/Controller/Kfy/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S143>' : 'acvh_controller_mark1/Controller/Kfy/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S144>' : 'acvh_controller_mark1/Controller/Kfy/D Gain/Internal Parameters'
//  '<S145>' : 'acvh_controller_mark1/Controller/Kfy/Filter/Disc. Forward Euler Filter'
//  '<S146>' : 'acvh_controller_mark1/Controller/Kfy/Filter ICs/Internal IC - Filter'
//  '<S147>' : 'acvh_controller_mark1/Controller/Kfy/I Gain/Internal Parameters'
//  '<S148>' : 'acvh_controller_mark1/Controller/Kfy/Ideal P Gain/Passthrough'
//  '<S149>' : 'acvh_controller_mark1/Controller/Kfy/Ideal P Gain Fdbk/Disabled'
//  '<S150>' : 'acvh_controller_mark1/Controller/Kfy/Integrator/Discrete'
//  '<S151>' : 'acvh_controller_mark1/Controller/Kfy/Integrator ICs/Internal IC'
//  '<S152>' : 'acvh_controller_mark1/Controller/Kfy/N Copy/Disabled'
//  '<S153>' : 'acvh_controller_mark1/Controller/Kfy/N Gain/Internal Parameters'
//  '<S154>' : 'acvh_controller_mark1/Controller/Kfy/P Copy/Disabled'
//  '<S155>' : 'acvh_controller_mark1/Controller/Kfy/Parallel P Gain/Internal Parameters'
//  '<S156>' : 'acvh_controller_mark1/Controller/Kfy/Reset Signal/Disabled'
//  '<S157>' : 'acvh_controller_mark1/Controller/Kfy/Saturation/Enabled'
//  '<S158>' : 'acvh_controller_mark1/Controller/Kfy/Saturation Fdbk/Disabled'
//  '<S159>' : 'acvh_controller_mark1/Controller/Kfy/Sum/Sum_PID'
//  '<S160>' : 'acvh_controller_mark1/Controller/Kfy/Sum Fdbk/Disabled'
//  '<S161>' : 'acvh_controller_mark1/Controller/Kfy/Tracking Mode/Disabled'
//  '<S162>' : 'acvh_controller_mark1/Controller/Kfy/Tracking Mode Sum/Passthrough'
//  '<S163>' : 'acvh_controller_mark1/Controller/Kfy/Tsamp - Integral/Passthrough'
//  '<S164>' : 'acvh_controller_mark1/Controller/Kfy/Tsamp - Ngain/Passthrough'
//  '<S165>' : 'acvh_controller_mark1/Controller/Kfy/postSat Signal/Forward_Path'
//  '<S166>' : 'acvh_controller_mark1/Controller/Kfy/preSat Signal/Forward_Path'
//  '<S167>' : 'acvh_controller_mark1/Controller/Velocity conversion to body axes1/rotation matrix'
//  '<S168>' : 'acvh_controller_mark1/Controller/tau_pitch1/Anti-windup'
//  '<S169>' : 'acvh_controller_mark1/Controller/tau_pitch1/D Gain'
//  '<S170>' : 'acvh_controller_mark1/Controller/tau_pitch1/Filter'
//  '<S171>' : 'acvh_controller_mark1/Controller/tau_pitch1/Filter ICs'
//  '<S172>' : 'acvh_controller_mark1/Controller/tau_pitch1/I Gain'
//  '<S173>' : 'acvh_controller_mark1/Controller/tau_pitch1/Ideal P Gain'
//  '<S174>' : 'acvh_controller_mark1/Controller/tau_pitch1/Ideal P Gain Fdbk'
//  '<S175>' : 'acvh_controller_mark1/Controller/tau_pitch1/Integrator'
//  '<S176>' : 'acvh_controller_mark1/Controller/tau_pitch1/Integrator ICs'
//  '<S177>' : 'acvh_controller_mark1/Controller/tau_pitch1/N Copy'
//  '<S178>' : 'acvh_controller_mark1/Controller/tau_pitch1/N Gain'
//  '<S179>' : 'acvh_controller_mark1/Controller/tau_pitch1/P Copy'
//  '<S180>' : 'acvh_controller_mark1/Controller/tau_pitch1/Parallel P Gain'
//  '<S181>' : 'acvh_controller_mark1/Controller/tau_pitch1/Reset Signal'
//  '<S182>' : 'acvh_controller_mark1/Controller/tau_pitch1/Saturation'
//  '<S183>' : 'acvh_controller_mark1/Controller/tau_pitch1/Saturation Fdbk'
//  '<S184>' : 'acvh_controller_mark1/Controller/tau_pitch1/Sum'
//  '<S185>' : 'acvh_controller_mark1/Controller/tau_pitch1/Sum Fdbk'
//  '<S186>' : 'acvh_controller_mark1/Controller/tau_pitch1/Tracking Mode'
//  '<S187>' : 'acvh_controller_mark1/Controller/tau_pitch1/Tracking Mode Sum'
//  '<S188>' : 'acvh_controller_mark1/Controller/tau_pitch1/Tsamp - Integral'
//  '<S189>' : 'acvh_controller_mark1/Controller/tau_pitch1/Tsamp - Ngain'
//  '<S190>' : 'acvh_controller_mark1/Controller/tau_pitch1/postSat Signal'
//  '<S191>' : 'acvh_controller_mark1/Controller/tau_pitch1/preSat Signal'
//  '<S192>' : 'acvh_controller_mark1/Controller/tau_pitch1/Anti-windup/Passthrough'
//  '<S193>' : 'acvh_controller_mark1/Controller/tau_pitch1/D Gain/Internal Parameters'
//  '<S194>' : 'acvh_controller_mark1/Controller/tau_pitch1/Filter/Disc. Forward Euler Filter'
//  '<S195>' : 'acvh_controller_mark1/Controller/tau_pitch1/Filter ICs/Internal IC - Filter'
//  '<S196>' : 'acvh_controller_mark1/Controller/tau_pitch1/I Gain/Internal Parameters'
//  '<S197>' : 'acvh_controller_mark1/Controller/tau_pitch1/Ideal P Gain/Passthrough'
//  '<S198>' : 'acvh_controller_mark1/Controller/tau_pitch1/Ideal P Gain Fdbk/Disabled'
//  '<S199>' : 'acvh_controller_mark1/Controller/tau_pitch1/Integrator/Discrete'
//  '<S200>' : 'acvh_controller_mark1/Controller/tau_pitch1/Integrator ICs/Internal IC'
//  '<S201>' : 'acvh_controller_mark1/Controller/tau_pitch1/N Copy/Disabled'
//  '<S202>' : 'acvh_controller_mark1/Controller/tau_pitch1/N Gain/Internal Parameters'
//  '<S203>' : 'acvh_controller_mark1/Controller/tau_pitch1/P Copy/Disabled'
//  '<S204>' : 'acvh_controller_mark1/Controller/tau_pitch1/Parallel P Gain/Internal Parameters'
//  '<S205>' : 'acvh_controller_mark1/Controller/tau_pitch1/Reset Signal/Disabled'
//  '<S206>' : 'acvh_controller_mark1/Controller/tau_pitch1/Saturation/Enabled'
//  '<S207>' : 'acvh_controller_mark1/Controller/tau_pitch1/Saturation Fdbk/Disabled'
//  '<S208>' : 'acvh_controller_mark1/Controller/tau_pitch1/Sum/Sum_PID'
//  '<S209>' : 'acvh_controller_mark1/Controller/tau_pitch1/Sum Fdbk/Disabled'
//  '<S210>' : 'acvh_controller_mark1/Controller/tau_pitch1/Tracking Mode/Disabled'
//  '<S211>' : 'acvh_controller_mark1/Controller/tau_pitch1/Tracking Mode Sum/Passthrough'
//  '<S212>' : 'acvh_controller_mark1/Controller/tau_pitch1/Tsamp - Integral/Passthrough'
//  '<S213>' : 'acvh_controller_mark1/Controller/tau_pitch1/Tsamp - Ngain/Passthrough'
//  '<S214>' : 'acvh_controller_mark1/Controller/tau_pitch1/postSat Signal/Forward_Path'
//  '<S215>' : 'acvh_controller_mark1/Controller/tau_pitch1/preSat Signal/Forward_Path'
//  '<S216>' : 'acvh_controller_mark1/Controller/tau_roll1/Anti-windup'
//  '<S217>' : 'acvh_controller_mark1/Controller/tau_roll1/D Gain'
//  '<S218>' : 'acvh_controller_mark1/Controller/tau_roll1/Filter'
//  '<S219>' : 'acvh_controller_mark1/Controller/tau_roll1/Filter ICs'
//  '<S220>' : 'acvh_controller_mark1/Controller/tau_roll1/I Gain'
//  '<S221>' : 'acvh_controller_mark1/Controller/tau_roll1/Ideal P Gain'
//  '<S222>' : 'acvh_controller_mark1/Controller/tau_roll1/Ideal P Gain Fdbk'
//  '<S223>' : 'acvh_controller_mark1/Controller/tau_roll1/Integrator'
//  '<S224>' : 'acvh_controller_mark1/Controller/tau_roll1/Integrator ICs'
//  '<S225>' : 'acvh_controller_mark1/Controller/tau_roll1/N Copy'
//  '<S226>' : 'acvh_controller_mark1/Controller/tau_roll1/N Gain'
//  '<S227>' : 'acvh_controller_mark1/Controller/tau_roll1/P Copy'
//  '<S228>' : 'acvh_controller_mark1/Controller/tau_roll1/Parallel P Gain'
//  '<S229>' : 'acvh_controller_mark1/Controller/tau_roll1/Reset Signal'
//  '<S230>' : 'acvh_controller_mark1/Controller/tau_roll1/Saturation'
//  '<S231>' : 'acvh_controller_mark1/Controller/tau_roll1/Saturation Fdbk'
//  '<S232>' : 'acvh_controller_mark1/Controller/tau_roll1/Sum'
//  '<S233>' : 'acvh_controller_mark1/Controller/tau_roll1/Sum Fdbk'
//  '<S234>' : 'acvh_controller_mark1/Controller/tau_roll1/Tracking Mode'
//  '<S235>' : 'acvh_controller_mark1/Controller/tau_roll1/Tracking Mode Sum'
//  '<S236>' : 'acvh_controller_mark1/Controller/tau_roll1/Tsamp - Integral'
//  '<S237>' : 'acvh_controller_mark1/Controller/tau_roll1/Tsamp - Ngain'
//  '<S238>' : 'acvh_controller_mark1/Controller/tau_roll1/postSat Signal'
//  '<S239>' : 'acvh_controller_mark1/Controller/tau_roll1/preSat Signal'
//  '<S240>' : 'acvh_controller_mark1/Controller/tau_roll1/Anti-windup/Passthrough'
//  '<S241>' : 'acvh_controller_mark1/Controller/tau_roll1/D Gain/Internal Parameters'
//  '<S242>' : 'acvh_controller_mark1/Controller/tau_roll1/Filter/Disc. Forward Euler Filter'
//  '<S243>' : 'acvh_controller_mark1/Controller/tau_roll1/Filter ICs/Internal IC - Filter'
//  '<S244>' : 'acvh_controller_mark1/Controller/tau_roll1/I Gain/Internal Parameters'
//  '<S245>' : 'acvh_controller_mark1/Controller/tau_roll1/Ideal P Gain/Passthrough'
//  '<S246>' : 'acvh_controller_mark1/Controller/tau_roll1/Ideal P Gain Fdbk/Disabled'
//  '<S247>' : 'acvh_controller_mark1/Controller/tau_roll1/Integrator/Discrete'
//  '<S248>' : 'acvh_controller_mark1/Controller/tau_roll1/Integrator ICs/Internal IC'
//  '<S249>' : 'acvh_controller_mark1/Controller/tau_roll1/N Copy/Disabled'
//  '<S250>' : 'acvh_controller_mark1/Controller/tau_roll1/N Gain/Internal Parameters'
//  '<S251>' : 'acvh_controller_mark1/Controller/tau_roll1/P Copy/Disabled'
//  '<S252>' : 'acvh_controller_mark1/Controller/tau_roll1/Parallel P Gain/Internal Parameters'
//  '<S253>' : 'acvh_controller_mark1/Controller/tau_roll1/Reset Signal/Disabled'
//  '<S254>' : 'acvh_controller_mark1/Controller/tau_roll1/Saturation/Enabled'
//  '<S255>' : 'acvh_controller_mark1/Controller/tau_roll1/Saturation Fdbk/Disabled'
//  '<S256>' : 'acvh_controller_mark1/Controller/tau_roll1/Sum/Sum_PID'
//  '<S257>' : 'acvh_controller_mark1/Controller/tau_roll1/Sum Fdbk/Disabled'
//  '<S258>' : 'acvh_controller_mark1/Controller/tau_roll1/Tracking Mode/Disabled'
//  '<S259>' : 'acvh_controller_mark1/Controller/tau_roll1/Tracking Mode Sum/Passthrough'
//  '<S260>' : 'acvh_controller_mark1/Controller/tau_roll1/Tsamp - Integral/Passthrough'
//  '<S261>' : 'acvh_controller_mark1/Controller/tau_roll1/Tsamp - Ngain/Passthrough'
//  '<S262>' : 'acvh_controller_mark1/Controller/tau_roll1/postSat Signal/Forward_Path'
//  '<S263>' : 'acvh_controller_mark1/Controller/tau_roll1/preSat Signal/Forward_Path'
//  '<S264>' : 'acvh_controller_mark1/Controller/tau_yaw1/Anti-windup'
//  '<S265>' : 'acvh_controller_mark1/Controller/tau_yaw1/D Gain'
//  '<S266>' : 'acvh_controller_mark1/Controller/tau_yaw1/Filter'
//  '<S267>' : 'acvh_controller_mark1/Controller/tau_yaw1/Filter ICs'
//  '<S268>' : 'acvh_controller_mark1/Controller/tau_yaw1/I Gain'
//  '<S269>' : 'acvh_controller_mark1/Controller/tau_yaw1/Ideal P Gain'
//  '<S270>' : 'acvh_controller_mark1/Controller/tau_yaw1/Ideal P Gain Fdbk'
//  '<S271>' : 'acvh_controller_mark1/Controller/tau_yaw1/Integrator'
//  '<S272>' : 'acvh_controller_mark1/Controller/tau_yaw1/Integrator ICs'
//  '<S273>' : 'acvh_controller_mark1/Controller/tau_yaw1/N Copy'
//  '<S274>' : 'acvh_controller_mark1/Controller/tau_yaw1/N Gain'
//  '<S275>' : 'acvh_controller_mark1/Controller/tau_yaw1/P Copy'
//  '<S276>' : 'acvh_controller_mark1/Controller/tau_yaw1/Parallel P Gain'
//  '<S277>' : 'acvh_controller_mark1/Controller/tau_yaw1/Reset Signal'
//  '<S278>' : 'acvh_controller_mark1/Controller/tau_yaw1/Saturation'
//  '<S279>' : 'acvh_controller_mark1/Controller/tau_yaw1/Saturation Fdbk'
//  '<S280>' : 'acvh_controller_mark1/Controller/tau_yaw1/Sum'
//  '<S281>' : 'acvh_controller_mark1/Controller/tau_yaw1/Sum Fdbk'
//  '<S282>' : 'acvh_controller_mark1/Controller/tau_yaw1/Tracking Mode'
//  '<S283>' : 'acvh_controller_mark1/Controller/tau_yaw1/Tracking Mode Sum'
//  '<S284>' : 'acvh_controller_mark1/Controller/tau_yaw1/Tsamp - Integral'
//  '<S285>' : 'acvh_controller_mark1/Controller/tau_yaw1/Tsamp - Ngain'
//  '<S286>' : 'acvh_controller_mark1/Controller/tau_yaw1/postSat Signal'
//  '<S287>' : 'acvh_controller_mark1/Controller/tau_yaw1/preSat Signal'
//  '<S288>' : 'acvh_controller_mark1/Controller/tau_yaw1/Anti-windup/Passthrough'
//  '<S289>' : 'acvh_controller_mark1/Controller/tau_yaw1/D Gain/Internal Parameters'
//  '<S290>' : 'acvh_controller_mark1/Controller/tau_yaw1/Filter/Disc. Forward Euler Filter'
//  '<S291>' : 'acvh_controller_mark1/Controller/tau_yaw1/Filter ICs/Internal IC - Filter'
//  '<S292>' : 'acvh_controller_mark1/Controller/tau_yaw1/I Gain/Internal Parameters'
//  '<S293>' : 'acvh_controller_mark1/Controller/tau_yaw1/Ideal P Gain/Passthrough'
//  '<S294>' : 'acvh_controller_mark1/Controller/tau_yaw1/Ideal P Gain Fdbk/Disabled'
//  '<S295>' : 'acvh_controller_mark1/Controller/tau_yaw1/Integrator/Discrete'
//  '<S296>' : 'acvh_controller_mark1/Controller/tau_yaw1/Integrator ICs/Internal IC'
//  '<S297>' : 'acvh_controller_mark1/Controller/tau_yaw1/N Copy/Disabled'
//  '<S298>' : 'acvh_controller_mark1/Controller/tau_yaw1/N Gain/Internal Parameters'
//  '<S299>' : 'acvh_controller_mark1/Controller/tau_yaw1/P Copy/Disabled'
//  '<S300>' : 'acvh_controller_mark1/Controller/tau_yaw1/Parallel P Gain/Internal Parameters'
//  '<S301>' : 'acvh_controller_mark1/Controller/tau_yaw1/Reset Signal/Disabled'
//  '<S302>' : 'acvh_controller_mark1/Controller/tau_yaw1/Saturation/Enabled'
//  '<S303>' : 'acvh_controller_mark1/Controller/tau_yaw1/Saturation Fdbk/Disabled'
//  '<S304>' : 'acvh_controller_mark1/Controller/tau_yaw1/Sum/Sum_PID'
//  '<S305>' : 'acvh_controller_mark1/Controller/tau_yaw1/Sum Fdbk/Disabled'
//  '<S306>' : 'acvh_controller_mark1/Controller/tau_yaw1/Tracking Mode/Disabled'
//  '<S307>' : 'acvh_controller_mark1/Controller/tau_yaw1/Tracking Mode Sum/Passthrough'
//  '<S308>' : 'acvh_controller_mark1/Controller/tau_yaw1/Tsamp - Integral/Passthrough'
//  '<S309>' : 'acvh_controller_mark1/Controller/tau_yaw1/Tsamp - Ngain/Passthrough'
//  '<S310>' : 'acvh_controller_mark1/Controller/tau_yaw1/postSat Signal/Forward_Path'
//  '<S311>' : 'acvh_controller_mark1/Controller/tau_yaw1/preSat Signal/Forward_Path'
//  '<S312>' : 'acvh_controller_mark1/ISM/PX4 uORB Read1'
//  '<S313>' : 'acvh_controller_mark1/ISM/PX4 uORB Read2'
//  '<S314>' : 'acvh_controller_mark1/ISM/Quaternions to Rotation Angles'
//  '<S315>' : 'acvh_controller_mark1/ISM/PX4 uORB Read1/Enabled Subsystem'
//  '<S316>' : 'acvh_controller_mark1/ISM/PX4 uORB Read2/Enabled Subsystem'
//  '<S317>' : 'acvh_controller_mark1/ISM/Quaternions to Rotation Angles/Angle Calculation'
//  '<S318>' : 'acvh_controller_mark1/ISM/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S319>' : 'acvh_controller_mark1/ISM/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S320>' : 'acvh_controller_mark1/ISM/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S321>' : 'acvh_controller_mark1/ISM/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S322>' : 'acvh_controller_mark1/ISM/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S323>' : 'acvh_controller_mark1/ISM/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S324>' : 'acvh_controller_mark1/ISM/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S325>' : 'acvh_controller_mark1/Setpoint/PX4 uORB Read2'
//  '<S326>' : 'acvh_controller_mark1/Setpoint/PX4 uORB Read2/Enabled Subsystem'

#endif                                 // RTW_HEADER_acvh_controller_mark1_h_

//
// File trailer for generated code.
//
// [EOF]
//
