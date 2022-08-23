## This cmakelist.txt file was generated from
## the UAV Toolbox Support Package for PX4 Autopilots

add_definitions(
-DMODEL=acvh_controller_mark1 -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DON_TARGET_WAIT_FOR_START=1 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=0 -DPX4 -DHOST_TARGET -DNULL=0 -DMW_PX4_POSIX_BUILD -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DPORTABLE_WORDSIZES )

px4_add_module(
    MODULE modules__px4_simulink_app
    MAIN px4_simulink_app
    STACK_MAIN 2000
SRCS
   MW_uORB_Read.cpp
   MW_uORB_Write.cpp
   MW_PX4_PWM.cpp
   ert_main.cpp
   acvh_controller_mark1.cpp
   acvh_controller_mark1_data.cpp
   rtGetInf.cpp
   rtGetNaN.cpp
   rt_nonfinite.cpp
   ext_svr.c
   updown.c
   ext_work.c
   rtiostream_utils.c
   MW_PX4_TaskControl.cpp
   nuttxinitialize.cpp
   MW_PX4_rtiostream_tcpip.cpp
   rtiostream_interface.c
    COMPILE_FLAGS
       -fpermissive
       -Wno-narrowing
    INCLUDES
       ${PX4_SOURCE_DIR}/src/modules/mavlink
       ${PX4_SOURCE_DIR}/mavlink/include/mavlink
       /home/sid/PX4_Simulink
       /home/sid/Documents/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/px4/include
       /home/sid/PX4_Simulink/acvh_controller_mark1_ert_rtw
       /usr/local/MATLAB/R2020b/extern/include
       /usr/local/MATLAB/R2020b/simulink/include
       /usr/local/MATLAB/R2020b/rtw/c/src
       /usr/local/MATLAB/R2020b/rtw/c/src/ext_mode/common
       /usr/local/MATLAB/R2020b/rtw/c/ert
       /usr/local/MATLAB/R2020b/toolbox/coder/rtiostream/src
       /usr/local/MATLAB/R2020b/toolbox/coder/rtiostream/src/utils
)

get_target_property(PX4_SL_APP_COMPILE_FLAGS modules__px4_simulink_app COMPILE_OPTIONS)
list(REMOVE_ITEM PX4_SL_APP_COMPILE_FLAGS -Werror)
set_target_properties(modules__px4_simulink_app PROPERTIES COMPILE_OPTIONS "${PX4_SL_APP_COMPILE_FLAGS}")

