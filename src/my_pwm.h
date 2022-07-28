#ifndef _MY_PWM_H_
#define _MY_PWM_H_


#include <rtthread.h>
#include "hal_data.h"
#include <rtdevice.h>

#define PWM_PERIOD 1000000

#define PWM1_DEV_NAME ("pwm8")
#define PWM1_CH           (0)


#define PWM2_DEV_NAME ("pwm7")
#define PWM2_CH           (0)





int my_pwm_init(void);
rt_err_t my_pwm_set_pulse(struct rt_device_pwm * pwm_dev,rt_uint32_t pulse_val);
rt_err_t my_pwm_enable(struct rt_device_pwm * pwm_dev);
rt_err_t my_pwm_disable(struct rt_device_pwm * pwm_dev);






#endif /* _MY_PWM_H_ */
