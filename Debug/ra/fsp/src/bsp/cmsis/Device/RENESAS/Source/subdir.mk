################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/startup.c \
../ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/system.c 

OBJS += \
./ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/startup.o \
./ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/system.o 

C_DEPS += \
./ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/startup.d \
./ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/system.d 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/%.o: ../ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/%.c
	arm-none-eabi-gcc -I"G:\RT-ThreadStudio\workspace\PWWWWM" -I"G:\RT-ThreadStudio\workspace\PWWWWM\board\ports" -I"G:\RT-ThreadStudio\workspace\PWWWWM\board" -I"G:\RT-ThreadStudio\workspace\PWWWWM\libraries\HAL_Drivers\config" -I"G:\RT-ThreadStudio\workspace\PWWWWM\libraries\HAL_Drivers" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra\fsp\inc\api" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra\fsp\inc\instances" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra\fsp\inc" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra_cfg\fsp_cfg\bsp" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra_cfg\fsp_cfg" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra_gen" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\drivers\include" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\finsh" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\compilers\common" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\compilers\newlib" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\posix\io\poll" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\posix\io\stdio" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\posix\ipc" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\utilities\ulog" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\include" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\libcpu\arm\common" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\libcpu\arm\cortex-m4" -include"G:\RT-ThreadStudio\workspace\PWWWWM\rtconfig_preinc.h" -std=gnu11 -mcpu=cortex-m33 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Dgcc -O0 -gdwarf-2 -g -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

