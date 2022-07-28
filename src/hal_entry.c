/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2021-10-10     Sherman       first version
 * 2021-11-03     Sherman       Add icu_sample
 */

#include <rtthread.h>
#include "hal_data.h"
#include <rtdevice.h>
#include "controller.h"
#include "uart0_t.h"


#define LED3_PIN    BSP_IO_PORT_01_PIN_06
#define USER_INPUT  "P105"

extern rt_uint8_t path_num;
extern int path[8][4];

void hal_entry(void)
{
    rt_kprintf("\nHello RT-Thread!\n");
    uart0_init();
    car_init();
//    car_start();

    while (1)
    {
        rt_thread_mdelay(500);
    }
}
 rt_uint8_t a=0;
void irq_callback_test(void *args)
{
    if(a==0)
    {
        car_stop();
            int temp[4]={0};
            for(int i=0;i<4;i++)
            {
                if(path[path_num][i]==1)
                {
                    path[path_num][i]=2;
                }
                else if(path[path_num][i]==2)
                {
                    path[path_num][i]=1;
                }
                temp[i] = path[path_num][i];
            }
            for(int i=0;i<4;i++)
            {
                path[path_num][i] = temp[3-i];
            }
    }
    a=1;
}

int icu_sample(void)
{
    /* init */
    rt_uint32_t pin = rt_pin_get(USER_INPUT);
    //rt_kprintf("\n pin number : 0x%04X \n", pin);
    rt_err_t err = rt_pin_attach_irq(pin, PIN_IRQ_MODE_RISING, irq_callback_test, RT_NULL);
    if(RT_EOK != err)
    {
        rt_kprintf("\n attach irq failed. \n");
    }
    err = rt_pin_irq_enable(pin, PIN_IRQ_ENABLE);
    if(RT_EOK != err)
    {
        rt_kprintf("\n enable irq failed. \n");
    }
    return err;
}
INIT_APP_EXPORT(icu_sample);
