

#include "uart0_t.h"
#include "controller.h"

rt_uint32_t number = 0;

rt_device_t uart0_dev=RT_NULL;

rt_sem_t uart0_rx_sem=RT_NULL;

rt_thread_t uart0_read_thread=RT_NULL;

rt_uint16_t rx_count=0;

rt_mutex_t number_protect = RT_NULL;



rt_uint8_t path_num=5;

int path[8][4]={
        {1,1,1,1},
        {2,2,2,2},
        {0,1,0,1},
        {0,2,0,2},
        {0,0,1,1},
        {0,0,1,2},
        {0,0,2,1},
        {0,0,2,2}
};



rt_err_t uart0_cbk(rt_device_t dev,rt_size_t size)
{
    rt_err_t ret = RT_EOK ;
    ret = rt_sem_release(uart0_rx_sem);
    if(ret!=RT_EOK)
        rt_kprintf("error inter 1 \r\n");
    return ret;
}
int turn_flag=0;
void uart0_read_thread_entry(void *parameter)
{
    char ch=0;
    static rt_uint32_t temp_number=0;
    static rt_uint8_t flag=0;

    while(1)
    {
        while(rt_device_read(uart0_dev, -1, &ch, 1)!=1)
        {
            rt_sem_take(uart0_rx_sem, RT_WAITING_FOREVER);
        }
        if(ch=='[')
        {
            flag=0;
        }
        else if(ch==']')
        {
            if(flag==0)
            {
                rt_mutex_take(number_protect, RT_WAITING_FOREVER);
                number = temp_number;
                temp_number = 0 ;
                rt_mutex_release(number_protect);
            }
        }
        else if(ch=='c')
        {
            flag=1;
            rt_kprintf("is turn\r\n");
            rt_kprintf("%d\r\n",path[path_num][turn_flag]);

            switch(path[path_num][turn_flag])
            {
                case 0:break;
                case 1:rt_enter_critical();car_left();rt_exit_critical();break;
                case 2:rt_enter_critical();car_right();rt_exit_critical();break;
            }
            turn_flag++;
            if(turn_flag >=4)
                turn_flag = 0;
        }
        else if(ch>='0'&&ch<='9')
        {
            temp_number=temp_number *10 + ch-'0';
        }
        ch=0;
    }

}

int uart0_init(void)
{
    uart0_dev = rt_device_find("uart0");
    rt_device_open(uart0_dev, RT_DEVICE_FLAG_INT_RX);
    rt_device_set_rx_indicate(uart0_dev, uart0_cbk);

    rt_device_write(uart0_dev, 0, "hello uart0\r\n", 13);

    uart0_rx_sem = rt_sem_create("uart0_rx_sem", 0, RT_IPC_FLAG_FIFO);

    number_protect = rt_mutex_create("number_protect", RT_IPC_FLAG_FIFO);

    uart0_read_thread = rt_thread_create("uart0_read", uart0_read_thread_entry, 0, 1024, 5, 300);
    if(uart0_read_thread)
    {
        rt_thread_startup(uart0_read_thread);
    }
    else {
        rt_kprintf("uart0_read_thread create error\r\n");
        return -1;
    }
    return 0;

}


