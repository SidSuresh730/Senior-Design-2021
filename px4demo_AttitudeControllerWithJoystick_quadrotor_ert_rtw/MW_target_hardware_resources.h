#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#define MW_MULTI_TASKING_MODE 1
#include "MW_PX4_TaskControl.h"

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE PX4 Host Target
#define MW_CONNECTIONINFO_TCPIP_IPADDRESS codertarget.pixhawk.registry.getLoopbackIP;
#define MW_CONNECTIONINFO_TCPIP_PORT 17725
#define MW_CONNECTIONINFO_TCPIP_VERBOSE 1
#define MW_EXTMODE_CONFIGURATION TCP/IP
#define MW_EXTMODE_RUNNING on
#define MW_RTOS NuttX
#define MW_RTOSBASERATETASKPRIORITY 250
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_RUNTIME_BUILDACTION 1
#define MW_CMAKECONFIG 0
#define MW_SIMULATOR 0
#define MW_GAZEBOSIMMODEL 0
#define MW_PWM_CH1_FAILSAFE 900
#define MW_PWM_CH1_DISARMED 900
#define MW_PWM_CH2_FAILSAFE 900
#define MW_PWM_CH2_DISARMED 900
#define MW_PWM_CH3_FAILSAFE 900
#define MW_PWM_CH3_DISARMED 900
#define MW_PWM_CH4_FAILSAFE 900
#define MW_PWM_CH4_DISARMED 900
#define MW_PWM_CH5_FAILSAFE 900
#define MW_PWM_CH5_DISARMED 900
#define MW_PWM_CH6_FAILSAFE 900
#define MW_PWM_CH6_DISARMED 900
#define MW_PWM_CH7_FAILSAFE 900
#define MW_PWM_CH7_DISARMED 900
#define MW_PWM_CH8_FAILSAFE 900
#define MW_PWM_CH8_DISARMED 900
#define MW_PWM_AUX_CH1_FAILSAFE 900
#define MW_PWM_AUX_CH1_DISARMED 900
#define MW_PWM_AUX_CH2_FAILSAFE 900
#define MW_PWM_AUX_CH2_DISARMED 900
#define MW_PWM_AUX_CH3_FAILSAFE 900
#define MW_PWM_AUX_CH3_DISARMED 900
#define MW_PWM_AUX_CH4_FAILSAFE 900
#define MW_PWM_AUX_CH4_DISARMED 900
#define MW_PWM_AUX_CH5_FAILSAFE 900
#define MW_PWM_AUX_CH5_DISARMED 900
#define MW_PWM_AUX_CH6_FAILSAFE 900
#define MW_PWM_AUX_CH6_DISARMED 900
#define MW_HRT_CONSTRAINT 0
#define MW_SEM_WATERMARK 20
#define MW_DATAVERSION 2016.02
#define MW_SIMULINKIO_ENABLE_SIMULINKIO 1

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
