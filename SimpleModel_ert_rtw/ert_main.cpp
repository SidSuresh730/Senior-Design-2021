//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
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
#include <stdio.h>
#include <stdlib.h>
#include "SimpleModel.h"
#include "SimpleModel_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "MW_PX4_TaskControl.h"
#include "nuttxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

// Function prototype declaration
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
pthread_t backgroundThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(SimpleModel_M) == (NULL)) &&
    !rtmGetStopRequested(SimpleModel_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);

    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(SimpleModel_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(SimpleModel_M, true);
      }

      if (rtmGetStopRequested(SimpleModel_M) == true) {
        rtmSetErrorStatus(SimpleModel_M, "Simulation finished");
        break;
      }
    }

    SimpleModel_step();

    // Get model outputs here
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(SimpleModel_M) == (NULL)) &&
                      !rtmGetStopRequested(SimpleModel_M));
    runModel = !stopRequested;
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(SimpleModel_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;

    // Wait for background task to complete
    CHECK_STATUS(pthread_join(backgroundThread, &threadJoinStatus), 0,
                 "pthread_join");
  }

  MW_PX4_Terminate();

  // Disable rt_OneStep() here

  // Terminate model
  SimpleModel_terminate();
  rtExtModeShutdown(1);
  sem_post(&stopSem);
  return NULL;
}

void *backgroundTask(void *arg)
{
  while (runModel) {
    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(SimpleModel_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(SimpleModel_M, true);
      }
    }
  }

  return NULL;
}

int px4_simulink_app_task_main (int argc, char *argv[])
{
  rtmSetErrorStatus(SimpleModel_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  // Initialize model
  SimpleModel_initialize();

  // External mode
  rtSetTFinalForExtMode(&rtmGetTFinal(SimpleModel_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(SimpleModel_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(SimpleModel_M, true);
    }
  }

  rtERTExtModeStartMsg();

  // Call RTOS Initialization function
  nuttxRTOSInit(0.001, 0);

  // Wait for stop semaphore
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
