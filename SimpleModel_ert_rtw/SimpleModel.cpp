//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SimpleModel.cpp
//
// Code generated for Simulink model 'SimpleModel'.
//
// Model version                  : 1.2
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Mon Feb  8 14:30:56 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "SimpleModel.h"
#include "SimpleModel_private.h"
#include "SimpleModel_dt.h"

// Block signals (default storage)
B_SimpleModel_T SimpleModel_B;

// Block states (default storage)
DW_SimpleModel_T SimpleModel_DW;

// Real-time model
RT_MODEL_SimpleModel_T SimpleModel_M_ = RT_MODEL_SimpleModel_T();
RT_MODEL_SimpleModel_T *const SimpleModel_M = &SimpleModel_M_;

// Model step function
void SimpleModel_step(void)
{
  boolean_T b_varargout_1;

  // Reset subsysRan breadcrumbs
  srClearBC(SimpleModel_DW.EnabledSubsystem_SubsysRanBC);

  // MATLABSystem: '<S1>/SourceBlock' incorporates:
  //   Inport: '<S2>/In1'

  b_varargout_1 = uORB_read_step(SimpleModel_DW.obj.orbMetadataObj,
    &SimpleModel_DW.obj.eventStructObj, &SimpleModel_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S2>/Enable'

  if (b_varargout_1) {
    SimpleModel_B.In1 = SimpleModel_B.b_varargout_2;
    srUpdateBC(SimpleModel_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S1>/Enabled Subsystem'

  // SignalConversion generated from: '<Root>/Bus Selector'
  memcpy(&SimpleModel_B.channels[0], &SimpleModel_B.In1.channels[0],
         static_cast<uint32_T>(18U * sizeof(real32_T)));

  // Logic: '<S1>/NOT' incorporates:
  //   MATLABSystem: '<S1>/SourceBlock'

  SimpleModel_B.NOT = !b_varargout_1;

  // External mode
  rtExtModeUploadCheckTrigger(1);

  {                                    // Sample time: [0.001s, 0.0s]
    rtExtModeUpload(0, (real_T)SimpleModel_M->Timing.taskTime0);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.001s, 0.0s]
    if ((rtmGetTFinal(SimpleModel_M)!=-1) &&
        !((rtmGetTFinal(SimpleModel_M)-SimpleModel_M->Timing.taskTime0) >
          SimpleModel_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(SimpleModel_M, "Simulation finished");
    }

    if (rtmGetStopRequested(SimpleModel_M)) {
      rtmSetErrorStatus(SimpleModel_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  SimpleModel_M->Timing.taskTime0 =
    ((time_T)(++SimpleModel_M->Timing.clockTick0)) *
    SimpleModel_M->Timing.stepSize0;
}

// Model initialize function
void SimpleModel_initialize(void)
{
  // Registration code
  rtmSetTFinal(SimpleModel_M, -1);
  SimpleModel_M->Timing.stepSize0 = 0.001;

  // External mode info
  SimpleModel_M->Sizes.checksums[0] = (332470067U);
  SimpleModel_M->Sizes.checksums[1] = (1084728399U);
  SimpleModel_M->Sizes.checksums[2] = (3982594607U);
  SimpleModel_M->Sizes.checksums[3] = (167185295U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    SimpleModel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&SimpleModel_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SimpleModel_M->extModeInfo,
      &SimpleModel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SimpleModel_M->extModeInfo,
                        SimpleModel_M->Sizes.checksums);
    rteiSetTPtr(SimpleModel_M->extModeInfo, rtmGetTPtr(SimpleModel_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    SimpleModel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  // SystemInitialize for Enabled SubSystem: '<S1>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S2>/Out1' incorporates:
  //   Inport: '<S2>/In1'

  SimpleModel_B.In1 = SimpleModel_P.Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem'

  // Start for MATLABSystem: '<S1>/SourceBlock'
  SimpleModel_DW.obj.matlabCodegenIsDeleted = false;
  SimpleModel_DW.obj.isSetupComplete = false;
  SimpleModel_DW.obj.isInitialized = 1;
  SimpleModel_DW.obj.orbMetadataObj = ORB_ID(rc_channels);
  uORB_read_initialize(SimpleModel_DW.obj.orbMetadataObj,
                       &SimpleModel_DW.obj.eventStructObj);
  SimpleModel_DW.obj.isSetupComplete = true;
}

// Model terminate function
void SimpleModel_terminate(void)
{
  // Terminate for MATLABSystem: '<S1>/SourceBlock'
  if (!SimpleModel_DW.obj.matlabCodegenIsDeleted) {
    SimpleModel_DW.obj.matlabCodegenIsDeleted = true;
    if ((SimpleModel_DW.obj.isInitialized == 1) &&
        SimpleModel_DW.obj.isSetupComplete) {
      uORB_read_terminate(&SimpleModel_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
