1. ����˵��
    ������չʾ�� RT_Thread �ź����Ĵ�������ȡ���ͷ�

2. ʹ�û���
    Ӳ�����������̶�Ӧ�Ŀ���Ӳ��ƽ̨ 
    �����壺   N32G4FRH_STB V1.1

3. ʹ��˵��
    �������ģ�����÷���������:ʱ�ӣ�I/O�� 
         1. SystemClock��144MHz
         2. GPIO��PA8 ���� LED(D1) ��˸��PB5 ���� LED(D3) ��˸
                        KEY1--PA4
                        ��־:   TX--PA9  RX--PA10    �����ʣ�115200

    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ���У�
         2. ��������main()���������̣߳�led0 �̡߳� led1 �߳� �� key �̣߳�led �߳����ڿ��� D1 ����led1 �߳����ڿ��� D3 500ms��˸��
             key �߳�ɨ�谴������ KEY1 ��⵽����ʱ���ͷ��ź�����led0 �̻߳�ȡ�ź�������ȡ�ɹ��󣬷�ת D1

4. ע������
    ��

1. Function description
    This example shows the creation, acquisition and release of the RT_Thread semaphore

2. Use environment
    Hardware environment: development hardware platform corresponding to the project 
    Development board:      N32G4FRH_STB V1.1

3. Instructions for use
    Describe the configuration method of related modules; for example: clock, I/O, etc. 
        1. SystemClock: 144MHz
        2. GPIO: 
                    PA8 controls the LED (D1) to blink; PB5 controls the LED (D3) to blink;
                    KEY1--PA4
                    Log: TX--PA9 RX--PA10 Baud rate: 115200

    Describe the test steps and phenomena of Demo 
        1. After compiling, download the program to reset and run;
        2. This routine creates three threads in main(), led0 thread, led1 thread and key thread, led0 thread is used to control D1 on and off, led1 thread is used to control D3 500ms blink, 
            key thread scans the KEY, when KEY1 detects that it is pressed, release the semaphore, led0 thread obtains the semaphore, and after obtaining it successfully, reverses D1

4. Matters needing attention
    None.