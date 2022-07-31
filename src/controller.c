#include "controller.h"
#include "stdlib.h"
#include "pid.h"
//#include "measure.h"
rt_uint32_t ain1_pin,ain2_pin,bin1_pin,bin2_pin;




extern struct rt_device_pwm * pwm1 ;
extern struct rt_device_pwm * pwm2 ;

extern rt_uint8_t path_num;

struct Controller controller = {
      .car_status = CAR_STOP,
      .arrive_flag = 0,
      .path_inf = {1,1},
      .left_pulse = PWM_PERCENT_INIT,
      .rignt_pulse = PWM_PERCENT_INIT,
      .start = car_start,
      .stop = car_stop,
      .left = car_left,
      .right = car_right,
      .turn = car_turn
};

int car_init(void)
{
    rt_err_t ret = RT_EOK;

    controller.car_status = CAR_STOP ;
    ain1_pin = rt_pin_get(AIN1_PIN);
    ain2_pin = rt_pin_get(AIN2_PIN);
    bin1_pin = rt_pin_get(BIN1_PIN);
    bin2_pin = rt_pin_get(BIN2_PIN);
    rt_pin_mode(ain1_pin, PIN_MODE_OUTPUT);
    rt_pin_mode(ain2_pin, PIN_MODE_OUTPUT);
    rt_pin_mode(bin1_pin, PIN_MODE_OUTPUT);
    rt_pin_mode(bin2_pin, PIN_MODE_OUTPUT);

    rt_pin_write(ain1_pin, PIN_LOW);
    rt_pin_write(ain2_pin, PIN_LOW);
    rt_pin_write(bin1_pin, PIN_LOW);
    rt_pin_write(bin2_pin, PIN_LOW);



    ret = my_pwm_init();
    pid_init();
    //my_pwm_set_pulse(pwm1,PWM_PERIOD * controller.left_pulse / 100);
    //my_pwm_set_pulse(pwm2,PWM_PERIOD * controller.rignt_pulse / 100);

    return ret;
}

//INIT_APP_EXPORT(car_init);

rt_err_t car_start(int argc,char **argv)
{
    rt_err_t ret = RT_EOK;
    controller.car_status = CAR_RUN ;
    if(argc==2)
    {
        path_num = atoi(argv[1]);
        rt_kprintf("now path is %d\r\n",path_num);
    }
    rt_pwm_enable(pwm1, 0);
    rt_pwm_enable(pwm2, 0);

    return ret;
}

rt_err_t car_stop(void)
{
    rt_err_t ret = RT_EOK;
    controller.car_status = CAR_STOP ;
    rt_pwm_disable(pwm1, 0);
    rt_pwm_disable(pwm2, 0);
    return ret;
}

rt_err_t car_left(void)
{
    rt_err_t ret = RT_EOK;
    my_pwm_set_pulse(pwm1, 350000);
    my_pwm_set_pulse(pwm2, PWM_PERIOD);
    rt_kprintf("left\r\n");
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
                for(int k=0;k<5;k++)
                {
                    int hhhh = 0;
                    hhhh++ ;
                }

    }
    rt_kprintf("exti left\r\n");
    my_pwm_set_pulse(pwm1, PWM_PERIOD * controller.left_pulse / 100);
    my_pwm_set_pulse(pwm2, PWM_PERIOD * controller.rignt_pulse / 100);

    return ret;
}
rt_err_t car_right(void)
{
    rt_err_t ret = RT_EOK;

    my_pwm_set_pulse(pwm1, PWM_PERIOD );
    my_pwm_set_pulse(pwm2, 350000);

    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
            for(int k=0;k<5;k++)
            {
                int hhhh = 0;
                hhhh++ ;
            }
    }

    my_pwm_set_pulse(pwm1, PWM_PERIOD * controller.left_pulse / 100);
    my_pwm_set_pulse(pwm2, PWM_PERIOD * controller.rignt_pulse / 100);

    return ret;
}
extern rt_uint8_t a;
rt_err_t car_turn(void)
{
    rt_err_t ret = RT_EOK;
    rt_enter_critical();

    rt_pin_write(ain1_pin, PIN_LOW);
    rt_pin_write(ain2_pin, PIN_HIGH);
    rt_pin_write(bin1_pin, PIN_HIGH);
    rt_pin_write(bin2_pin, PIN_LOW);
    my_pwm_set_pulse(pwm1, 800000);
    my_pwm_set_pulse(pwm2, 800000);
    rt_pwm_enable(pwm1, 0);
    rt_pwm_enable(pwm2, 0);

    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1105;j++)
            for(int k=0;k<5;k++)
        {
            int hhhh = 0;
            hhhh++ ;
        }
    }

    rt_pin_write(ain1_pin, PIN_HIGH);
    rt_pin_write(ain2_pin, PIN_LOW);
    rt_pin_write(bin1_pin, PIN_HIGH);
    rt_pin_write(bin2_pin, PIN_LOW);



    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1230;j++)
            for(int k=0;k<4;k++)
        {
            int hhhh = 0;
            hhhh++ ;
        }
    }
    a = 0;
    rt_exit_critical();
    return ret;
}

//rt_err_t car_ex_left(int argc,char **argv)
//{
//    rt_err_t ret = RT_EOK;
//    static rt_uint32_t ms = 1100;
//
//    if(argc==2)
//    {
//        ms = atoi(argv[1]);
//    }
//
//    my_pwm_set_pulse(pwm1, PWM_PERIOD * 50 / 100);
//    my_pwm_set_pulse(pwm2, PWM_PERIOD * 100 / 100);
//
//    rt_thread_mdelay(ms);
//
//    my_pwm_set_pulse(pwm1, PWM_PERIOD * controller.left_pulse / 100);
//    my_pwm_set_pulse(pwm2, PWM_PERIOD * controller.rignt_pulse / 100);
//
//    return ret;
//}
//
//rt_err_t car_ex_right(int argc,char **argv)
//{
//    rt_err_t ret = RT_EOK;
//    static rt_uint32_t ms = 1200;
//
//    if(argc==2)
//    {
//        ms = atoi(argv[1]);
//    }
//
//    my_pwm_set_pulse(pwm1, PWM_PERIOD * 100 / 100);
//    my_pwm_set_pulse(pwm2, PWM_PERIOD * 50 / 100);
//
//    rt_thread_mdelay(ms);
//
//    my_pwm_set_pulse(pwm1, PWM_PERIOD * controller.left_pulse / 100);
//    my_pwm_set_pulse(pwm2, PWM_PERIOD * controller.rignt_pulse / 100);
//
//    return ret;
//}
//
//rt_err_t car_ex_turn(int argc,char **argv)
//{
//    rt_err_t ret = RT_EOK;
//    static rt_uint32_t ms = 1450;
//
//    if(argc==2)
//    {
//        ms = atoi(argv[1]);
//    }
//
//    rt_pin_write(ain1_pin, PIN_LOW);
//    rt_pin_write(ain2_pin, PIN_HIGH);
//    rt_pin_write(bin1_pin, PIN_HIGH);
//    rt_pin_write(bin2_pin, PIN_LOW);
//
//    rt_thread_mdelay(ms);
//
//    rt_pin_write(ain1_pin, PIN_HIGH);
//    rt_pin_write(ain2_pin, PIN_LOW);
//    rt_pin_write(bin1_pin, PIN_HIGH);
//    rt_pin_write(bin2_pin, PIN_LOW);
//
//    return ret;
//}


#if(ENABLE_CAR_MSH)
MSH_CMD_EXPORT(car_start,make car start);
MSH_CMD_EXPORT(car_stop,make car stop);
//MSH_CMD_EXPORT(car_right,make car right);
//MSH_CMD_EXPORT(car_left,make car left);
MSH_CMD_EXPORT(car_turn,make car turn);
//MSH_CMD_EXPORT(car_ex_left,car_ex_left);
//MSH_CMD_EXPORT(car_ex_right,make car left);
//MSH_CMD_EXPORT(car_ex_turn,make car turn);
#endif


