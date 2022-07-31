

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_


#include <rtthread.h>
#include "hal_data.h"
#include <rtdevice.h>
#include "my_pwm.h"

#define ENABLE_CAR_MSH 1

#define AIN1_PIN "P403"
#define AIN2_PIN "P404"
#define BIN1_PIN "P405"
#define BIN2_PIN "P406"


#define PATH_INF_MAX 10
#define PWM_PERCENT_INIT   50

#define UPLOAD_EVENT (1<<8)
#define UPLOAD_EVENT_1 (1<<7)

enum CAR_S{
  CAR_RUN,
  CAR_STOP,
  CAR_ARRIVE,
  CAR_ERR
};

struct Controller{
    enum CAR_S car_status;       //车当前状态

    rt_uint8_t arrive_flag;      //到达FLAG
    int path_inf[PATH_INF_MAX];  //路径信息

    rt_uint8_t left_pulse;       //左占空比
    rt_uint8_t rignt_pulse;      //右占空比

    rt_err_t (*start)(int argc,char **argv);
    rt_err_t (*stop)(void);
    rt_err_t (*left)(void);
    rt_err_t (*right)(void);
    rt_err_t (*turn)(void);

};

int car_init(void);
rt_err_t car_start(int argc,char **argv);
rt_err_t car_stop(void);
rt_err_t car_left(void);
rt_err_t car_right(void);
rt_err_t car_turn(void);








#endif /* _CONTROLLER_H_ */

