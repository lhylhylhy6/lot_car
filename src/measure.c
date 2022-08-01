
#include "measure.h"

#include <board.h>
#include "dhtxx.h"
#include "hal_data.h"
#include "onenet.h"
#define DATA_PIN   BSP_IO_PORT_01_PIN_02
/* cat_dhtxx sensor data by dynamic */

rt_thread_t measure_thread = RT_NULL ;

extern struct rt_completion measure_completion;

void measure_dhtxx(void *parameter)
{
    while(1)
    {
        rt_completion_wait(&measure_completion, RT_WAITING_FOREVER);
        dht_device_t sensor = dht_create(DATA_PIN);
        if(dht_read(sensor)) {
            rt_int32_t temp = dht_get_temperature(sensor);
            rt_int32_t humi = dht_get_humidity(sensor);
            rt_kprintf("Temp: %d.%d 'C,  Humi: %d '% \n", temp/10, temp%10, humi/10);
            onenet_mqtt_upload_digit("dht_temp", ((float)temp)/10.0);
        }
        else {
            rt_kprintf("Read dht sensor failed.\n");
        }
        dht_delete(sensor);
    }

}

void measure_init(void)
{
    measure_thread = rt_thread_create("mreasure", measure_dhtxx, 0, 2048, 1, 300);
    if(measure_thread)
    {
        rt_thread_startup(measure_thread);
    }
    else {
        rt_kprintf("create error\r\n");
    }
}



