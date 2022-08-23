//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: acvh_controller_mark0.h
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
#ifndef RTW_HEADER_acvh_controller_mark0_h_
#define RTW_HEADER_acvh_controller_mark0_h_
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
#include "acvh_controller_mark0_types.h"

// Shared type includes
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
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
  px4_Bus_vehicle_odometry In1;        // '<S314>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_manual_control_setpoint In1_m;// '<S162>/In1'
  px4_Bus_manual_control_setpoint b_varargout_2_m;
  px4_Bus_sensor_baro In1_o;           // '<S315>/In1'
  px4_Bus_sensor_baro b_varargout_2_c;
  px4_Bus_actuator_armed In1_b;        // '<S7>/In1'
  px4_Bus_actuator_armed BusAssignment;// '<S1>/Bus Assignment'
  uint16_T b_pwmValue[8];
  real_T des_yaw;                      // '<S159>/yaw'
  real_T des_vx;                       // '<S159>/vx'
  real_T des_vy;                       // '<S159>/vy'
  real_T des_vz;                       // '<S159>/Constant'
  real_T Filter_k;                     // '<S192>/Filter'
  real_T Filter_h;                     // '<S240>/Filter'
  real_T Integrator_dp;                // '<S245>/Integrator'
  real_T ug;                           // '<S10>/1//g'
  real_T ug1;                          // '<S10>/1//g1'
  real_T pitch_err;                    // '<S8>/Sum3'
  real_T FilterCoefficient_n;          // '<S145>/Filter Coefficient'
  real_T FilterCoefficient_h;          // '<S97>/Filter Coefficient'
  real_T FilterCoefficient_p;          // '<S296>/Filter Coefficient'
  real_T FilterCoefficient_k;          // '<S49>/Filter Coefficient'
  real_T FilterCoefficient_o;          // '<S248>/Filter Coefficient'
  real_T fcn3;                         // '<S313>/fcn3'
  uint16_T Gain1_k[4];                 // '<S4>/Gain1'
  real32_T x;
  real32_T Gain1;                      // '<S9>/Gain1'
  real32_T y;
  real32_T Gain;                       // '<S9>/Gain'
  real32_T r;
  real32_T Gain2;                      // '<S9>/Gain2'
  real32_T z;
  real32_T pressure;
  boolean_T NOT;                       // '<S161>/NOT'
  boolean_T NOT_l;                     // '<S311>/NOT'
  boolean_T NOT_n;                     // '<S5>/NOT'
} B_acvh_controller_mark0_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  px4_internal_block_Subscriber_T obj; // '<S312>/SourceBlock'
  px4_internal_block_Subscriber_T obj_n;// '<S311>/SourceBlock'
  px4_internal_block_Subscriber_T obj_f;// '<S161>/SourceBlock'
  px4_internal_block_Subscriber_T obj_m;// '<S5>/SourceBlock'
  px4_internal_block_PWM_acvh_c_T obj_no;// '<S4>/PX4 PWM Output'
  px4_internal_block_Publisher__T obj_fm;// '<S6>/SinkBlock'
  real_T Integrator_DSTATE;            // '<S197>/Integrator'
  real_T Filter_DSTATE;                // '<S192>/Filter'
  real_T Integrator_DSTATE_b;          // '<S245>/Integrator'
  real_T Filter_DSTATE_o;              // '<S240>/Filter'
  real_T Integrator_DSTATE_c;          // '<S46>/Integrator'
  real_T Filter_DSTATE_g;              // '<S41>/Filter'
  real_T Integrator_DSTATE_cz;         // '<S293>/Integrator'
  real_T Filter_DSTATE_d;              // '<S288>/Filter'
  real_T Integrator_DSTATE_f;          // '<S94>/Integrator'
  real_T Filter_DSTATE_k;              // '<S89>/Filter'
  real_T Integrator_DSTATE_l;          // '<S142>/Integrator'
  real_T Filter_DSTATE_l;              // '<S137>/Filter'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S318>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S318>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S318>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S312>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_h;// '<S311>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_f;// '<S161>/Enabled Subsystem'
  int8_T Commands_SubsysRanBC;         // '<S9>/Commands '
  int8_T EnabledSubsystem_SubsysRanBC_n;// '<S5>/Enabled Subsystem'
  boolean_T Commands_MODE;             // '<S9>/Commands '
} DW_acvh_controller_mark0_T;

// Parameters (default storage)
struct P_acvh_controller_mark0_T_ {
  real_T DiscretePIDController1_D;   // Mask Parameter: DiscretePIDController1_D
                                        //  Referenced by: '<S191>/Derivative Gain'

  real_T Kfx_D;                        // Mask Parameter: Kfx_D
                                          //  Referenced by: '<S239>/Derivative Gain'

  real_T DiscretePIDController3_D;   // Mask Parameter: DiscretePIDController3_D
                                        //  Referenced by: '<S40>/Derivative Gain'

  real_T Kfy_D;                        // Mask Parameter: Kfy_D
                                          //  Referenced by: '<S287>/Derivative Gain'

  real_T DiscretePIDController4_D;   // Mask Parameter: DiscretePIDController4_D
                                        //  Referenced by: '<S88>/Derivative Gain'

  real_T DiscretePIDController5_D;   // Mask Parameter: DiscretePIDController5_D
                                        //  Referenced by: '<S136>/Derivative Gain'

  real_T DiscretePIDController5_I;   // Mask Parameter: DiscretePIDController5_I
                                        //  Referenced by: '<S139>/Integral Gain'

  real_T DiscretePIDController4_I;   // Mask Parameter: DiscretePIDController4_I
                                        //  Referenced by: '<S91>/Integral Gain'

  real_T Kfy_I;                        // Mask Parameter: Kfy_I
                                          //  Referenced by: '<S290>/Integral Gain'

  real_T DiscretePIDController3_I;   // Mask Parameter: DiscretePIDController3_I
                                        //  Referenced by: '<S43>/Integral Gain'

  real_T Kfx_I;                        // Mask Parameter: Kfx_I
                                          //  Referenced by: '<S242>/Integral Gain'

  real_T DiscretePIDController1_I;   // Mask Parameter: DiscretePIDController1_I
                                        //  Referenced by: '<S194>/Integral Gain'

  real_T DiscretePIDController1_InitialC;
                              // Mask Parameter: DiscretePIDController1_InitialC
                                 //  Referenced by: '<S192>/Filter'

  real_T Kfx_InitialConditionForFilter;
                                // Mask Parameter: Kfx_InitialConditionForFilter
                                   //  Referenced by: '<S240>/Filter'

  real_T DiscretePIDController3_InitialC;
                              // Mask Parameter: DiscretePIDController3_InitialC
                                 //  Referenced by: '<S41>/Filter'

  real_T Kfy_InitialConditionForFilter;
                                // Mask Parameter: Kfy_InitialConditionForFilter
                                   //  Referenced by: '<S288>/Filter'

  real_T DiscretePIDController4_InitialC;
                              // Mask Parameter: DiscretePIDController4_InitialC
                                 //  Referenced by: '<S89>/Filter'

  real_T DiscretePIDController5_InitialC;
                              // Mask Parameter: DiscretePIDController5_InitialC
                                 //  Referenced by: '<S137>/Filter'

  real_T DiscretePIDController1_Initia_g;
                              // Mask Parameter: DiscretePIDController1_Initia_g
                                 //  Referenced by: '<S197>/Integrator'

  real_T Kfx_InitialConditionForIntegrat;
                              // Mask Parameter: Kfx_InitialConditionForIntegrat
                                 //  Referenced by: '<S245>/Integrator'

  real_T DiscretePIDController3_Initia_k;
                              // Mask Parameter: DiscretePIDController3_Initia_k
                                 //  Referenced by: '<S46>/Integrator'

  real_T Kfy_InitialConditionForIntegrat;
                              // Mask Parameter: Kfy_InitialConditionForIntegrat
                                 //  Referenced by: '<S293>/Integrator'

  real_T DiscretePIDController4_Initia_p;
                              // Mask Parameter: DiscretePIDController4_Initia_p
                                 //  Referenced by: '<S94>/Integrator'

  real_T DiscretePIDController5_Initia_e;
                              // Mask Parameter: DiscretePIDController5_Initia_e
                                 //  Referenced by: '<S142>/Integrator'

  real_T DiscretePIDController3_LowerSat;
                              // Mask Parameter: DiscretePIDController3_LowerSat
                                 //  Referenced by: '<S53>/Saturation'

  real_T DiscretePIDController4_LowerSat;
                              // Mask Parameter: DiscretePIDController4_LowerSat
                                 //  Referenced by: '<S101>/Saturation'

  real_T DiscretePIDController5_LowerSat;
                              // Mask Parameter: DiscretePIDController5_LowerSat
                                 //  Referenced by: '<S149>/Saturation'

  real_T DiscretePIDController1_N;   // Mask Parameter: DiscretePIDController1_N
                                        //  Referenced by: '<S200>/Filter Coefficient'

  real_T Kfx_N;                        // Mask Parameter: Kfx_N
                                          //  Referenced by: '<S248>/Filter Coefficient'

  real_T DiscretePIDController3_N;   // Mask Parameter: DiscretePIDController3_N
                                        //  Referenced by: '<S49>/Filter Coefficient'

  real_T Kfy_N;                        // Mask Parameter: Kfy_N
                                          //  Referenced by: '<S296>/Filter Coefficient'

  real_T DiscretePIDController4_N;   // Mask Parameter: DiscretePIDController4_N
                                        //  Referenced by: '<S97>/Filter Coefficient'

  real_T DiscretePIDController5_N;   // Mask Parameter: DiscretePIDController5_N
                                        //  Referenced by: '<S145>/Filter Coefficient'

  real_T DiscretePIDController1_P;   // Mask Parameter: DiscretePIDController1_P
                                        //  Referenced by: '<S202>/Proportional Gain'

  real_T Kfx_P;                        // Mask Parameter: Kfx_P
                                          //  Referenced by: '<S250>/Proportional Gain'

  real_T DiscretePIDController3_P;   // Mask Parameter: DiscretePIDController3_P
                                        //  Referenced by: '<S51>/Proportional Gain'

  real_T Kfy_P;                        // Mask Parameter: Kfy_P
                                          //  Referenced by: '<S298>/Proportional Gain'

  real_T DiscretePIDController4_P;   // Mask Parameter: DiscretePIDController4_P
                                        //  Referenced by: '<S99>/Proportional Gain'

  real_T DiscretePIDController5_P;   // Mask Parameter: DiscretePIDController5_P
                                        //  Referenced by: '<S147>/Proportional Gain'

  real_T DiscretePIDController3_UpperSat;
                              // Mask Parameter: DiscretePIDController3_UpperSat
                                 //  Referenced by: '<S53>/Saturation'

  real_T DiscretePIDController4_UpperSat;
                              // Mask Parameter: DiscretePIDController4_UpperSat
                                 //  Referenced by: '<S101>/Saturation'

  real_T DiscretePIDController5_UpperSat;
                              // Mask Parameter: DiscretePIDController5_UpperSat
                                 //  Referenced by: '<S149>/Saturation'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S314>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S311>/Constant'

  px4_Bus_manual_control_setpoint Out1_Y0_o;// Computed Parameter: Out1_Y0_o
                                               //  Referenced by: '<S162>/Out1'

  px4_Bus_manual_control_setpoint Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                      //  Referenced by: '<S161>/Constant'

  px4_Bus_sensor_baro Out1_Y0_p;       // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S315>/Out1'

  px4_Bus_sensor_baro Constant_Value_i;// Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S312>/Constant'

  px4_Bus_actuator_armed Out1_Y0_oq;   // Computed Parameter: Out1_Y0_oq
                                          //  Referenced by: '<S7>/Out1'

  px4_Bus_actuator_armed Constant_Value_n;// Computed Parameter: Constant_Value_n
                                             //  Referenced by: '<S5>/Constant'

  real_T des_yaw_Y0;                   // Computed Parameter: des_yaw_Y0
                                          //  Referenced by: '<S159>/des_yaw'

  real_T des_vx_Y0;                    // Computed Parameter: des_vx_Y0
                                          //  Referenced by: '<S159>/des_vx'

  real_T des_vy_Y0;                    // Computed Parameter: des_vy_Y0
                                          //  Referenced by: '<S159>/des_vy'

  real_T Constant_Value_o;             // Expression: 0
                                          //  Referenced by: '<S159>/Constant'

  real_T Constant_Value_l;             // Expression: 1
                                          //  Referenced by: '<S319>/Constant'

  real_T Constant_Value_k;             // Expression: 1
                                          //  Referenced by: '<S320>/Constant'

  real_T Mixermatrix_Value[16];
                          // Expression: [1 -1 1 1;1 1 -1 1;1 -1 -1 -1;1 1 1 -1]
                             //  Referenced by: '<S4>/Mixer matrix'

  real_T Constant_Value_c;             // Expression: 1
                                          //  Referenced by: '<S4>/Constant'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S310>/Gain'

  real_T Saturation4_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S10>/Saturation4'

  real_T Saturation4_LowerSat;         // Expression: -3
                                          //  Referenced by: '<S10>/Saturation4'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S197>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S192>/Filter'

  real_T Saturation2_UpperSat;         // Expression: 12
                                          //  Referenced by: '<S10>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -12
                                          //  Referenced by: '<S10>/Saturation2'

  real_T ug_Gain;                      // Expression: 1/9.8
                                          //  Referenced by: '<S10>/1//g'

  real_T Integrator_gainval_i;       // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S245>/Integrator'

  real_T Filter_gainval_n;             // Computed Parameter: Filter_gainval_n
                                          //  Referenced by: '<S240>/Filter'

  real_T Saturation_UpperSat;          // Expression: pi/4
                                          //  Referenced by: '<S8>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -pi/4
                                          //  Referenced by: '<S8>/Saturation'

  real_T Integrator_gainval_f;       // Computed Parameter: Integrator_gainval_f
                                        //  Referenced by: '<S46>/Integrator'

  real_T Filter_gainval_e;             // Computed Parameter: Filter_gainval_e
                                          //  Referenced by: '<S41>/Filter'

  real_T Saturation3_UpperSat;         // Expression: 12
                                          //  Referenced by: '<S10>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -12
                                          //  Referenced by: '<S10>/Saturation3'

  real_T ug1_Gain;                     // Expression: 1/9.8
                                          //  Referenced by: '<S10>/1//g1'

  real_T Integrator_gainval_l;       // Computed Parameter: Integrator_gainval_l
                                        //  Referenced by: '<S293>/Integrator'

  real_T Filter_gainval_d;             // Computed Parameter: Filter_gainval_d
                                          //  Referenced by: '<S288>/Filter'

  real_T Saturation1_UpperSat;         // Expression: pi/4
                                          //  Referenced by: '<S8>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -pi/4
                                          //  Referenced by: '<S8>/Saturation1'

  real_T Integrator_gainval_ld;     // Computed Parameter: Integrator_gainval_ld
                                       //  Referenced by: '<S94>/Integrator'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                          //  Referenced by: '<S89>/Filter'

  real_T Integrator_gainval_b;       // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S142>/Integrator'

  real_T Filter_gainval_l;             // Computed Parameter: Filter_gainval_l
                                          //  Referenced by: '<S137>/Filter'

  real_T Gain1_Gain;                   // Expression: 1000
                                          //  Referenced by: '<S4>/Gain1'

  real32_T Deadband_Start;             // Computed Parameter: Deadband_Start
                                          //  Referenced by: '<S160>/Deadband'

  real32_T Deadband_End;               // Computed Parameter: Deadband_End
                                          //  Referenced by: '<S160>/Deadband'

  real32_T Gain1_Gain_p;               // Computed Parameter: Gain1_Gain_p
                                          //  Referenced by: '<S9>/Gain1'

  real32_T Deadband1_Start;            // Computed Parameter: Deadband1_Start
                                          //  Referenced by: '<S160>/Deadband1'

  real32_T Deadband1_End;              // Computed Parameter: Deadband1_End
                                          //  Referenced by: '<S160>/Deadband1'

  real32_T Gain_Gain_n;                // Computed Parameter: Gain_Gain_n
                                          //  Referenced by: '<S9>/Gain'

  real32_T Deadband2_Start;            // Computed Parameter: Deadband2_Start
                                          //  Referenced by: '<S160>/Deadband2'

  real32_T Deadband2_End;              // Computed Parameter: Deadband2_End
                                          //  Referenced by: '<S160>/Deadband2'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S9>/Gain2'

  boolean_T Reset_Value;               // Computed Parameter: Reset_Value
                                          //  Referenced by: '<S4>/Reset'

  boolean_T Constant_Value_b;          // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S1>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_acvh_controller_mark0_T {
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
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_acvh_controller_mark0_T acvh_controller_mark0_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_acvh_controller_mark0_T acvh_controller_mark0_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_acvh_controller_mark0_T acvh_controller_mark0_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void acvh_controller_mark0_initialize(void);
  extern void acvh_controller_mark0_step(void);
  extern void acvh_controller_mark0_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_acvh_controller_mark_T *const acvh_controller_mark0_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S312>/NOT' : Unused code path elimination


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
//  '<Root>' : 'acvh_controller_mark0'
//  '<S1>'   : 'acvh_controller_mark0/Arm'
//  '<S2>'   : 'acvh_controller_mark0/Controller'
//  '<S3>'   : 'acvh_controller_mark0/ISM'
//  '<S4>'   : 'acvh_controller_mark0/OSM'
//  '<S5>'   : 'acvh_controller_mark0/Arm/PX4 uORB Read'
//  '<S6>'   : 'acvh_controller_mark0/Arm/PX4 uORB Write'
//  '<S7>'   : 'acvh_controller_mark0/Arm/PX4 uORB Read/Enabled Subsystem'
//  '<S8>'   : 'acvh_controller_mark0/Controller/Attitude commands'
//  '<S9>'   : 'acvh_controller_mark0/Controller/Commands'
//  '<S10>'  : 'acvh_controller_mark0/Controller/Velocity Controller'
//  '<S11>'  : 'acvh_controller_mark0/Controller/Velocity conversion to body axes'
//  '<S12>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3'
//  '<S13>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4'
//  '<S14>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5'
//  '<S15>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Anti-windup'
//  '<S16>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/D Gain'
//  '<S17>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Filter'
//  '<S18>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Filter ICs'
//  '<S19>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/I Gain'
//  '<S20>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Ideal P Gain'
//  '<S21>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Ideal P Gain Fdbk'
//  '<S22>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Integrator'
//  '<S23>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Integrator ICs'
//  '<S24>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/N Copy'
//  '<S25>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/N Gain'
//  '<S26>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/P Copy'
//  '<S27>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Parallel P Gain'
//  '<S28>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Reset Signal'
//  '<S29>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Saturation'
//  '<S30>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Saturation Fdbk'
//  '<S31>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Sum'
//  '<S32>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Sum Fdbk'
//  '<S33>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Tracking Mode'
//  '<S34>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Tracking Mode Sum'
//  '<S35>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Tsamp - Integral'
//  '<S36>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Tsamp - Ngain'
//  '<S37>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/postSat Signal'
//  '<S38>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/preSat Signal'
//  '<S39>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Anti-windup/Passthrough'
//  '<S40>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/D Gain/Internal Parameters'
//  '<S41>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Filter/Disc. Forward Euler Filter'
//  '<S42>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Filter ICs/Internal IC - Filter'
//  '<S43>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/I Gain/Internal Parameters'
//  '<S44>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Ideal P Gain/Passthrough'
//  '<S45>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S46>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Integrator/Discrete'
//  '<S47>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Integrator ICs/Internal IC'
//  '<S48>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/N Copy/Disabled'
//  '<S49>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/N Gain/Internal Parameters'
//  '<S50>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/P Copy/Disabled'
//  '<S51>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S52>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Reset Signal/Disabled'
//  '<S53>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Saturation/Enabled'
//  '<S54>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Saturation Fdbk/Disabled'
//  '<S55>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Sum/Sum_PID'
//  '<S56>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Sum Fdbk/Disabled'
//  '<S57>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Tracking Mode/Disabled'
//  '<S58>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S59>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Tsamp - Integral/Passthrough'
//  '<S60>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S61>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/postSat Signal/Forward_Path'
//  '<S62>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller3/preSat Signal/Forward_Path'
//  '<S63>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Anti-windup'
//  '<S64>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/D Gain'
//  '<S65>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Filter'
//  '<S66>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Filter ICs'
//  '<S67>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/I Gain'
//  '<S68>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Ideal P Gain'
//  '<S69>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Ideal P Gain Fdbk'
//  '<S70>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Integrator'
//  '<S71>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Integrator ICs'
//  '<S72>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/N Copy'
//  '<S73>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/N Gain'
//  '<S74>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/P Copy'
//  '<S75>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Parallel P Gain'
//  '<S76>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Reset Signal'
//  '<S77>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Saturation'
//  '<S78>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Saturation Fdbk'
//  '<S79>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Sum'
//  '<S80>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Sum Fdbk'
//  '<S81>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Tracking Mode'
//  '<S82>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Tracking Mode Sum'
//  '<S83>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Tsamp - Integral'
//  '<S84>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Tsamp - Ngain'
//  '<S85>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/postSat Signal'
//  '<S86>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/preSat Signal'
//  '<S87>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Anti-windup/Passthrough'
//  '<S88>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/D Gain/Internal Parameters'
//  '<S89>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S90>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S91>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/I Gain/Internal Parameters'
//  '<S92>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Ideal P Gain/Passthrough'
//  '<S93>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S94>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Integrator/Discrete'
//  '<S95>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Integrator ICs/Internal IC'
//  '<S96>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/N Copy/Disabled'
//  '<S97>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/N Gain/Internal Parameters'
//  '<S98>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/P Copy/Disabled'
//  '<S99>'  : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S100>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Reset Signal/Disabled'
//  '<S101>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Saturation/Enabled'
//  '<S102>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Saturation Fdbk/Disabled'
//  '<S103>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Sum/Sum_PID'
//  '<S104>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Sum Fdbk/Disabled'
//  '<S105>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Tracking Mode/Disabled'
//  '<S106>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S107>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Tsamp - Integral/Passthrough'
//  '<S108>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S109>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/postSat Signal/Forward_Path'
//  '<S110>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller4/preSat Signal/Forward_Path'
//  '<S111>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Anti-windup'
//  '<S112>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/D Gain'
//  '<S113>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Filter'
//  '<S114>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Filter ICs'
//  '<S115>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/I Gain'
//  '<S116>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Ideal P Gain'
//  '<S117>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Ideal P Gain Fdbk'
//  '<S118>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Integrator'
//  '<S119>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Integrator ICs'
//  '<S120>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/N Copy'
//  '<S121>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/N Gain'
//  '<S122>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/P Copy'
//  '<S123>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Parallel P Gain'
//  '<S124>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Reset Signal'
//  '<S125>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Saturation'
//  '<S126>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Saturation Fdbk'
//  '<S127>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Sum'
//  '<S128>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Sum Fdbk'
//  '<S129>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Tracking Mode'
//  '<S130>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Tracking Mode Sum'
//  '<S131>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Tsamp - Integral'
//  '<S132>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Tsamp - Ngain'
//  '<S133>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/postSat Signal'
//  '<S134>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/preSat Signal'
//  '<S135>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Anti-windup/Passthrough'
//  '<S136>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/D Gain/Internal Parameters'
//  '<S137>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Filter/Disc. Forward Euler Filter'
//  '<S138>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Filter ICs/Internal IC - Filter'
//  '<S139>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/I Gain/Internal Parameters'
//  '<S140>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Ideal P Gain/Passthrough'
//  '<S141>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S142>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Integrator/Discrete'
//  '<S143>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Integrator ICs/Internal IC'
//  '<S144>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/N Copy/Disabled'
//  '<S145>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/N Gain/Internal Parameters'
//  '<S146>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/P Copy/Disabled'
//  '<S147>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Parallel P Gain/Internal Parameters'
//  '<S148>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Reset Signal/Disabled'
//  '<S149>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Saturation/Enabled'
//  '<S150>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Saturation Fdbk/Disabled'
//  '<S151>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Sum/Sum_PID'
//  '<S152>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Sum Fdbk/Disabled'
//  '<S153>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Tracking Mode/Disabled'
//  '<S154>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S155>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Tsamp - Integral/Passthrough'
//  '<S156>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S157>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/postSat Signal/Forward_Path'
//  '<S158>' : 'acvh_controller_mark0/Controller/Attitude commands/Discrete PID Controller5/preSat Signal/Forward_Path'
//  '<S159>' : 'acvh_controller_mark0/Controller/Commands/Commands '
//  '<S160>' : 'acvh_controller_mark0/Controller/Commands/Manual controls'
//  '<S161>' : 'acvh_controller_mark0/Controller/Commands/Manual controls/PX4 uORB Read2'
//  '<S162>' : 'acvh_controller_mark0/Controller/Commands/Manual controls/PX4 uORB Read2/Enabled Subsystem'
//  '<S163>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1'
//  '<S164>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx'
//  '<S165>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy'
//  '<S166>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Anti-windup'
//  '<S167>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/D Gain'
//  '<S168>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Filter'
//  '<S169>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Filter ICs'
//  '<S170>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/I Gain'
//  '<S171>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Ideal P Gain'
//  '<S172>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S173>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Integrator'
//  '<S174>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Integrator ICs'
//  '<S175>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/N Copy'
//  '<S176>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/N Gain'
//  '<S177>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/P Copy'
//  '<S178>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Parallel P Gain'
//  '<S179>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Reset Signal'
//  '<S180>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Saturation'
//  '<S181>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S182>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Sum'
//  '<S183>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Sum Fdbk'
//  '<S184>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Tracking Mode'
//  '<S185>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S186>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S187>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S188>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/postSat Signal'
//  '<S189>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/preSat Signal'
//  '<S190>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Anti-windup/Passthrough'
//  '<S191>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/D Gain/Internal Parameters'
//  '<S192>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S193>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S194>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/I Gain/Internal Parameters'
//  '<S195>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S196>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S197>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Integrator/Discrete'
//  '<S198>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Integrator ICs/Internal IC'
//  '<S199>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/N Copy/Disabled'
//  '<S200>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/N Gain/Internal Parameters'
//  '<S201>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S202>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S203>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S204>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Saturation/Passthrough'
//  '<S205>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S206>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Sum/Sum_PID'
//  '<S207>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S208>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S209>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S210>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Tsamp - Integral/Passthrough'
//  '<S211>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S212>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S213>' : 'acvh_controller_mark0/Controller/Velocity Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S214>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Anti-windup'
//  '<S215>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/D Gain'
//  '<S216>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Filter'
//  '<S217>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Filter ICs'
//  '<S218>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/I Gain'
//  '<S219>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Ideal P Gain'
//  '<S220>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Ideal P Gain Fdbk'
//  '<S221>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Integrator'
//  '<S222>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Integrator ICs'
//  '<S223>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/N Copy'
//  '<S224>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/N Gain'
//  '<S225>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/P Copy'
//  '<S226>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Parallel P Gain'
//  '<S227>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Reset Signal'
//  '<S228>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Saturation'
//  '<S229>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Saturation Fdbk'
//  '<S230>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Sum'
//  '<S231>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Sum Fdbk'
//  '<S232>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Tracking Mode'
//  '<S233>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Tracking Mode Sum'
//  '<S234>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Tsamp - Integral'
//  '<S235>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Tsamp - Ngain'
//  '<S236>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/postSat Signal'
//  '<S237>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/preSat Signal'
//  '<S238>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Anti-windup/Passthrough'
//  '<S239>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/D Gain/Internal Parameters'
//  '<S240>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Filter/Disc. Forward Euler Filter'
//  '<S241>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Filter ICs/Internal IC - Filter'
//  '<S242>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/I Gain/Internal Parameters'
//  '<S243>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Ideal P Gain/Passthrough'
//  '<S244>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Ideal P Gain Fdbk/Disabled'
//  '<S245>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Integrator/Discrete'
//  '<S246>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Integrator ICs/Internal IC'
//  '<S247>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/N Copy/Disabled'
//  '<S248>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/N Gain/Internal Parameters'
//  '<S249>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/P Copy/Disabled'
//  '<S250>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Parallel P Gain/Internal Parameters'
//  '<S251>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Reset Signal/Disabled'
//  '<S252>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Saturation/Passthrough'
//  '<S253>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Saturation Fdbk/Disabled'
//  '<S254>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Sum/Sum_PID'
//  '<S255>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Sum Fdbk/Disabled'
//  '<S256>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Tracking Mode/Disabled'
//  '<S257>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Tracking Mode Sum/Passthrough'
//  '<S258>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Tsamp - Integral/Passthrough'
//  '<S259>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/Tsamp - Ngain/Passthrough'
//  '<S260>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/postSat Signal/Forward_Path'
//  '<S261>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfx/preSat Signal/Forward_Path'
//  '<S262>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Anti-windup'
//  '<S263>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/D Gain'
//  '<S264>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Filter'
//  '<S265>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Filter ICs'
//  '<S266>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/I Gain'
//  '<S267>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Ideal P Gain'
//  '<S268>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Ideal P Gain Fdbk'
//  '<S269>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Integrator'
//  '<S270>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Integrator ICs'
//  '<S271>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/N Copy'
//  '<S272>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/N Gain'
//  '<S273>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/P Copy'
//  '<S274>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Parallel P Gain'
//  '<S275>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Reset Signal'
//  '<S276>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Saturation'
//  '<S277>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Saturation Fdbk'
//  '<S278>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Sum'
//  '<S279>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Sum Fdbk'
//  '<S280>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Tracking Mode'
//  '<S281>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Tracking Mode Sum'
//  '<S282>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Tsamp - Integral'
//  '<S283>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Tsamp - Ngain'
//  '<S284>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/postSat Signal'
//  '<S285>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/preSat Signal'
//  '<S286>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Anti-windup/Passthrough'
//  '<S287>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/D Gain/Internal Parameters'
//  '<S288>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Filter/Disc. Forward Euler Filter'
//  '<S289>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Filter ICs/Internal IC - Filter'
//  '<S290>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/I Gain/Internal Parameters'
//  '<S291>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Ideal P Gain/Passthrough'
//  '<S292>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Ideal P Gain Fdbk/Disabled'
//  '<S293>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Integrator/Discrete'
//  '<S294>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Integrator ICs/Internal IC'
//  '<S295>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/N Copy/Disabled'
//  '<S296>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/N Gain/Internal Parameters'
//  '<S297>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/P Copy/Disabled'
//  '<S298>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Parallel P Gain/Internal Parameters'
//  '<S299>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Reset Signal/Disabled'
//  '<S300>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Saturation/Passthrough'
//  '<S301>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Saturation Fdbk/Disabled'
//  '<S302>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Sum/Sum_PID'
//  '<S303>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Sum Fdbk/Disabled'
//  '<S304>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Tracking Mode/Disabled'
//  '<S305>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Tracking Mode Sum/Passthrough'
//  '<S306>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Tsamp - Integral/Passthrough'
//  '<S307>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/Tsamp - Ngain/Passthrough'
//  '<S308>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/postSat Signal/Forward_Path'
//  '<S309>' : 'acvh_controller_mark0/Controller/Velocity Controller/Kfy/preSat Signal/Forward_Path'
//  '<S310>' : 'acvh_controller_mark0/Controller/Velocity conversion to body axes/rotation matrix'
//  '<S311>' : 'acvh_controller_mark0/ISM/PX4 uORB Read1'
//  '<S312>' : 'acvh_controller_mark0/ISM/PX4 uORB Read2'
//  '<S313>' : 'acvh_controller_mark0/ISM/Quaternions to Rotation Angles'
//  '<S314>' : 'acvh_controller_mark0/ISM/PX4 uORB Read1/Enabled Subsystem'
//  '<S315>' : 'acvh_controller_mark0/ISM/PX4 uORB Read2/Enabled Subsystem'
//  '<S316>' : 'acvh_controller_mark0/ISM/Quaternions to Rotation Angles/Angle Calculation'
//  '<S317>' : 'acvh_controller_mark0/ISM/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S318>' : 'acvh_controller_mark0/ISM/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S319>' : 'acvh_controller_mark0/ISM/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S320>' : 'acvh_controller_mark0/ISM/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S321>' : 'acvh_controller_mark0/ISM/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S322>' : 'acvh_controller_mark0/ISM/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S323>' : 'acvh_controller_mark0/ISM/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // RTW_HEADER_acvh_controller_mark0_h_

//
// File trailer for generated code.
//
// [EOF]
//
