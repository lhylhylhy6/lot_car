


#include "my_pwm.h"
#include "stdlib.h"

struct rt_device_pwm * pwm1 = RT_NULL;
struct rt_device_pwm * pwm2 = RT_NULL;

rt_uint32_t pwm1_period = 1000000;
rt_uint32_t pwm1_pulse = 500000;

rt_uint32_t pwm2_period = 1000000;
rt_uint32_t pwm2_pulse = 500000;

int my_pwm_init(void)
{
    rt_err_t ret;
    pwm1 = (struct rt_device_pwm *)rt_device_find(PWM1_DEV_NAME);
    pwm2 = (struct rt_device_pwm *)rt_device_find(PWM2_DEV_NAME);
    if(pwm1)
    {
        ret = rt_pwm_set(pwm1, PWM1_CH, pwm1_period, pwm1_pulse);
        if(ret<0)
            rt_kprintf("ret1: %d\r\n",ret);
        //rt_pwm_enable(pwm1, PWM1_CH);
    }
    ret = RT_EOK;
    if(pwm2)
    {
        ret = rt_pwm_set(pwm2, PWM2_CH, pwm2_period, pwm2_pulse);
        if(ret<0)
            rt_kprintf("ret2: %d\r\n",ret);
        //rt_pwm_enable(pwm2, PWM2_CH);
    }
    return ret;
}

int my_pwm_ex_set_pulse(int argc,char **argv)
{
    rt_uint32_t now_pulse=0;
    rt_err_t err = RT_EOK;
    if(argc == 1)
    {
        err = RT_EOK;
        return err;
    }
    else if(argc == 2)
    {
       rt_kprintf("please input :my_pwm_set_pulse <pwm_dev> <percent>\r\n");
       err = - RT_ERROR;
       return err;
    }
    else
    {
        if(strcmp(argv[1],"pwm8")==0)
        {
            now_pulse = pwm1_period * atoi(argv[2]) / 100;
            rt_pwm_set(pwm1, 0, pwm1_period, now_pulse);
            rt_kprintf("set %s ok\r\n",pwm1);
        }
        else if(strcmp(argv[1],"pwm7")==0)
        {
            now_pulse = pwm2_period * atoi(argv[2]) / 100;
            rt_pwm_set(pwm2, 0, pwm2_period, now_pulse);
            rt_kprintf("set %s ok\r\n",pwm2);
        }
        else {
            err = RT_EOK;
            return err;
        }
        return err;
    }
}
MSH_CMD_EXPORT(my_pwm_ex_set_pulse , <input percent(%)>to set the pwm pulse);

rt_err_t my_pwm_set_pulse(struct rt_device_pwm * pwm_dev,rt_uint32_t pulse_val)
{
    rt_err_t ret=RT_EOK;

    RT_ASSERT(pwm_dev);

    ret = rt_pwm_set(pwm_dev, 0, PWM_PERIOD, pulse_val);
    return ret;
}

rt_err_t my_pwm_enable(struct rt_device_pwm * pwm_dev)
{
    rt_err_t ret = RT_EOK;
    ret = rt_pwm_enable(pwm_dev, 0);
    return ret;
}
rt_err_t my_pwm_disable(struct rt_device_pwm * pwm_dev)
{
    rt_err_t ret = RT_EOK;
    ret = rt_pwm_disable(pwm_dev, 0);
    return ret;
}










