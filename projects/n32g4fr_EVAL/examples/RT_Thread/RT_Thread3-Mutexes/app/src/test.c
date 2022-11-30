/**********************************************************************************************************
*
*   ģ������ : ������ʾ
*   �ļ����� : test.c
*   ��    �� : V1.0
*   ˵    �� :
*   �޸ļ�¼ :
*       �汾��  ����        ����                        ˵��
*
*       v1.0    2013-4-20   jiezhi320(UP MCU ������)    ��ʾ�ź�����ʵ��ʹ��
*
*   Copyright (C), 2012-2013,
*   �Ա��꣺   http://shop73275611.taobao.com
*   QQ����Ⱥ�� 258043068
*
**********************************************************************************************************/
#include <rtthread.h>
#include <n32g4fr.h>
#include "test.h"
#include "key.h"
#include "led.h"

/*  ��������4�ֽڶ��� */
ALIGN(RT_ALIGN_SIZE)

/*  ��̬�̵߳� �̶߳�ջ*/
static rt_uint8_t led_stack[512];
static rt_uint8_t key_stack[512];
/* ��̬�̵߳� �߳̿��ƿ� */
static struct rt_thread led_thread;
static struct rt_thread key_thread;

/* �ź������ƿ� */
struct rt_semaphore key_sem;

rt_err_t demo_thread_creat(void)
{
    rt_err_t result;

    /* ��ʼ����̬�ź�������ʼֵ��0 */
    result = rt_sem_init(&key_sem, "keysem", 0, RT_IPC_FLAG_FIFO);
    if (result != RT_EOK)
    {
        rt_kprintf("init keysem failed.\n");
        return -1;
    }

    /* ����key�߳� �� ���ȼ� 15 ��ʱ��Ƭ 5��ϵͳ�δ� */
    result = rt_thread_init(&key_thread,
                            "key",
                            key_thread_entry, RT_NULL,
                            (rt_uint8_t*)&key_stack[0], sizeof(key_stack), 15, 5);

    if (result == RT_EOK)
    {
        rt_thread_startup(&key_thread);
    }
    return 0;
}



