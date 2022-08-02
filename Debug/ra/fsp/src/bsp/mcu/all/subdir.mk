################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/bsp/mcu/all/bsp_clocks.c \
../ra/fsp/src/bsp/mcu/all/bsp_common.c \
../ra/fsp/src/bsp/mcu/all/bsp_delay.c \
../ra/fsp/src/bsp/mcu/all/bsp_group_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_guard.c \
../ra/fsp/src/bsp/mcu/all/bsp_io.c \
../ra/fsp/src/bsp/mcu/all/bsp_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_register_protection.c \
../ra/fsp/src/bsp/mcu/all/bsp_rom_registers.c \
../ra/fsp/src/bsp/mcu/all/bsp_sbrk.c \
../ra/fsp/src/bsp/mcu/all/bsp_security.c 

OBJS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.o \
./ra/fsp/src/bsp/mcu/all/bsp_common.o \
./ra/fsp/src/bsp/mcu/all/bsp_delay.o \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_guard.o \
./ra/fsp/src/bsp/mcu/all/bsp_io.o \
./ra/fsp/src/bsp/mcu/all/bsp_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.o \
./ra/fsp/src/bsp/mcu/all/bsp_rom_registers.o \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.o \
./ra/fsp/src/bsp/mcu/all/bsp_security.o 

C_DEPS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.d \
./ra/fsp/src/bsp/mcu/all/bsp_common.d \
./ra/fsp/src/bsp/mcu/all/bsp_delay.d \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_guard.d \
./ra/fsp/src/bsp/mcu/all/bsp_io.d \
./ra/fsp/src/bsp/mcu/all/bsp_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.d \
./ra/fsp/src/bsp/mcu/all/bsp_rom_registers.d \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.d \
./ra/fsp/src/bsp/mcu/all/bsp_security.d 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/bsp/mcu/all/%.o: ../ra/fsp/src/bsp/mcu/all/%.c
	arm-none-eabi-gcc -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\board\ports" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\board" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\libraries\HAL_Drivers\config" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\libraries\HAL_Drivers" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\packages\at_device-latest\class\esp8266" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\packages\at_device-latest\inc" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\packages\cJSON-latest" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\packages\dhtxx-latest\inc" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\packages\onenet-latest\inc" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\packages\pahomqtt-latest\MQTTClient-RT" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\packages\pahomqtt-latest\MQTTPacket\src" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\ra\fsp\inc\api" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\ra\fsp\inc\instances" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\ra\fsp\inc" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\ra_cfg\fsp_cfg\bsp" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\ra_cfg\fsp_cfg" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\ra_gen" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\dfs\filesystems\devfs" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\dfs\include" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\drivers\include" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\drivers\sensors" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\finsh" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\compilers\common" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\compilers\newlib" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\posix\io\poll" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\posix\io\stdio" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\posix\ipc" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\net\at\at_socket" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\net\at\include" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\net\netdev\include" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\net\sal\impl" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\net\sal\include\dfs_net" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\net\sal\include\socket\sys_socket" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\net\sal\include\socket" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\net\sal\include" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\utilities\ulog" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\include" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\libcpu\arm\common" -I"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rt-thread\libcpu\arm\cortex-m4" -include"G:\RT-ThreadStudio\RT-ThreadStudio\workspace\PWWWWM\rtconfig_preinc.h" -std=gnu11 -mcpu=cortex-m33 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Dgcc -O0 -gdwarf-2 -g -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

