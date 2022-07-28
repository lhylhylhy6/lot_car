

#include "uart0_t.h"
#include "pid.h"

rt_uint32_t number = 0;
rt_device_t uart0_dev=RT_NULL;
rt_sem_t uart0_rx_sem=RT_NULL;
rt_sem_t uart0_dispose_sem=RT_NULL;
rt_thread_t uart0_read_thread=RT_NULL;
rt_thread_t uart0_dispose_thread=RT_NULL;
char rx_buffer[100]={0};
rt_uint16_t rx_count=0;

extern rt_mutex_t number_protect;


rt_err_t uart0_cbk(rt_device_t dev,rt_size_t size)
{
    rt_err_t ret = RT_EOK ;
    ret = rt_sem_release(uart0_rx_sem);
    if(ret!=RT_EOK)
        rt_kprintf("error inter 1 \r\n");
    return ret;
    //return RT_EOK;
}
void uart0_read_thread_entry(void *parameter)
{
    char ch=0;

    while(1)
    {
        while(rt_device_read(uart0_dev, -1, &ch, 1)!=1)
        {
            rt_sem_take(uart0_rx_sem, RT_WAITING_FOREVER);
        }
        rx_buffer[rx_count++] = ch;
        //rt_kprintf("%c",ch);
        if(ch == ']')
        {
            rt_err_t ret = RT_EOK;
            ret = rt_sem_release(uart0_dispose_sem);
            rt_thread_mdelay(300);
            if(ret!=RT_EOK)
                rt_kprintf("error inter 1 \r\n");
        }
        if(rx_count>=64)
        {
            rx_count=0;
            memset(rx_buffer,0,64);
        }
    }
}
void uart0_dispose_thread_entry(void *parameter)
{
    while(1)
    {
        rt_sem_take(uart0_dispose_sem, RT_WAITING_FOREVER);
        char s_num[10]={0};
        rt_uint8_t num_c = 0;
        for(rt_uint8_t i=0;i<rx_count;i++)
        {
            if(rx_buffer[i]=='['||rx_buffer[i]==']')
            {
                ;
            }
            else if(rx_buffer[i]=='c')
            {
                //¹ÕÍä´¦

            }
            else {
                s_num[num_c++]=rx_buffer[i];
            }
        }

        rt_mutex_take(number_protect, RT_WAITING_FOREVER);
        number = atoi(s_num);
        memset(s_num,0,10);
        num_c=0;
        rt_mutex_release(number_protect);

    }

}
int uart0_init(void)
{
    uart0_dev = rt_device_find("uart0");
    rt_device_open(uart0_dev, RT_DEVICE_FLAG_INT_RX);
    rt_device_set_rx_indicate(uart0_dev, uart0_cbk);

    rt_device_write(uart0_dev, 0, "hello uart0\r\n", 13);

    uart0_rx_sem = rt_sem_create("uart0_rx_sem", 0, RT_IPC_FLAG_FIFO);
    uart0_dispose_sem = rt_sem_create("uart0_dispose_sem", 0, RT_IPC_FLAG_FIFO);
    number_protect = rt_mutex_create("number_protect", RT_IPC_FLAG_FIFO);

    uart0_read_thread = rt_thread_create("uart0_read", uart0_read_thread_entry, 0, 512, 5, 300);
    if(uart0_read_thread)
    {
        rt_thread_startup(uart0_read_thread);
    }
    else {
        rt_kprintf("uart0_read_thread cread error\r\n");
        return -1;
    }

    uart0_dispose_thread = rt_thread_create("uart0_dispose", uart0_dispose_thread_entry, 0, 1024, 7, 300);
    if(uart0_dispose_thread)
    {
        rt_thread_startup(uart0_dispose_thread);
    }
    else {
        rt_kprintf("uart0_dispose_thread cread error\r\n");
        return -1;
    }
    return 0;

}


