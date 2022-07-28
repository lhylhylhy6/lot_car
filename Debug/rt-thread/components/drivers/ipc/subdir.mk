################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/components/drivers/ipc/completion.c \
../rt-thread/components/drivers/ipc/dataqueue.c \
../rt-thread/components/drivers/ipc/pipe.c \
../rt-thread/components/drivers/ipc/ringblk_buf.c \
../rt-thread/components/drivers/ipc/ringbuffer.c \
../rt-thread/components/drivers/ipc/waitqueue.c \
../rt-thread/components/drivers/ipc/workqueue.c 

OBJS += \
./rt-thread/components/drivers/ipc/completion.o \
./rt-thread/components/drivers/ipc/dataqueue.o \
./rt-thread/components/drivers/ipc/pipe.o \
./rt-thread/components/drivers/ipc/ringblk_buf.o \
./rt-thread/components/drivers/ipc/ringbuffer.o \
./rt-thread/components/drivers/ipc/waitqueue.o \
./rt-thread/components/drivers/ipc/workqueue.o 

C_DEPS += \
./rt-thread/components/drivers/ipc/completion.d \
./rt-thread/components/drivers/ipc/dataqueue.d \
./rt-thread/components/drivers/ipc/pipe.d \
./rt-thread/components/drivers/ipc/ringblk_buf.d \
./rt-thread/components/drivers/ipc/ringbuffer.d \
./rt-thread/components/drivers/ipc/waitqueue.d \
./rt-thread/components/drivers/ipc/workqueue.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/components/drivers/ipc/%.o: ../rt-thread/components/drivers/ipc/%.c
	arm-none-eabi-gcc -I"G:\RT-ThreadStudio\workspace\PWWWWM" -I"G:\RT-ThreadStudio\workspace\PWWWWM\board\ports" -I"G:\RT-ThreadStudio\workspace\PWWWWM\board" -I"G:\RT-ThreadStudio\workspace\PWWWWM\libraries\HAL_Drivers\config" -I"G:\RT-ThreadStudio\workspace\PWWWWM\libraries\HAL_Drivers" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra\fsp\inc\api" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra\fsp\inc\instances" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra\fsp\inc" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra_cfg\fsp_cfg\bsp" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra_cfg\fsp_cfg" -I"G:\RT-ThreadStudio\workspace\PWWWWM\ra_gen" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\drivers\include" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\finsh" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\compilers\common" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\compilers\newlib" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\posix\io\poll" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\posix\io\stdio" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\libc\posix\ipc" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\components\utilities\ulog" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\include" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\libcpu\arm\common" -I"G:\RT-ThreadStudio\workspace\PWWWWM\rt-thread\libcpu\arm\cortex-m4" -include"G:\RT-ThreadStudio\workspace\PWWWWM\rtconfig_preinc.h" -std=gnu11 -mcpu=cortex-m33 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Dgcc -O0 -gdwarf-2 -g -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

