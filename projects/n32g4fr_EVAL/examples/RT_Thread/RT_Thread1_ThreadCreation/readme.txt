1. ����˵��
    ������չʾ�� RT_Thread ϵͳ�����߳�

2. ʹ�û���
    Ӳ�����������̶�Ӧ�Ŀ���Ӳ��ƽ̨ 
    �����壺    N32G4FRH_STB V1.1

3. ʹ��˵��
    �������ģ�����÷���������:ʱ�ӣ�I/O�� 
         1. SystemClock��144MHz
         2. GPIO��PA8 ���� LED(D1) ��˸��PB5 ���� LED(D3) ��˸��
                        ��־:   TX--PA9  RX--PA10    �����ʣ�115200

    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ���У�
         2. ��������main()���洴�������̣߳�led0 �̺߳� led1 �̣߳�led0 �߳����ڿ��� D1 1s��˸��led1 �߳����ڿ��� D3 500ms��˸���Դ�ѭ��

4. ע������
    ��

1. Function description
    This example shows how to create a thread in the RT_Thread system

2. Use environment
    Hardware environment: development hardware platform corresponding to the project 
    Development board:      N32G4FRH_STB V1.1

3. Instructions for use
    Describe the configuration method of related modules; for example: clock, I/O, etc. 
        1. SystemClock: 144MHz
        2. GPIO: 
                    PA8 controls the LED (D1) to blink; PB5 controls the LED (D3) to blink;
                    Log: TX--PA9 RX--PA10 Baud rate: 115200

    Describe the test steps and phenomena of Demo 
        1. After compiling, download the program to reset and run;
        2. This routine creates two threads in main(), LED0 thread and LED1 thread. LED0 thread is used to control D1 1s flashing, and LED1 thread is used to control D3 500ms flashing, so as to cycle

4. Matters needing attention
    None.