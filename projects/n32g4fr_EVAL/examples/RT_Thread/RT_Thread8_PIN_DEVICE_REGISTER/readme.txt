1. ����˵��
    ������չʾ�� RT_Thread ϵͳ���� PIN �豸

2. ʹ�û���
    Ӳ�����������̶�Ӧ�Ŀ���Ӳ��ƽ̨ 
    �����壺   N32G4FRH_STB V1.1

3. ʹ��˵��
    �������ģ�����÷���������:ʱ�ӣ�I/O�� 
         1. SystemClock��144MHz
         2. GPIO��PA8 ���� LED(D1) ��˸;PB5 ���� LED(D3) ��˸;
                        KEY1--PA4��KEY2--PA5, KEY3--PA6
                        ��־��TX--PA9  RX--PA10�������ʣ�115200

    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ����
         2. �����̴��������̣߳�led0 �̡߳�led1 �߳� key �̣߳�led0 �߳����ڿ��� D1 500ms��˸��led1 �߳����ڿ��� D3 250ms��˸��
            key �̼߳�� KEY1��KEY2��KEY3������KEY3�����жϹ��ܣ���KEY3����ʱ�������жϻص��������а�������ʱ��ӡ��Ӧ��־

4. ע������
    ��

1. Function description
    This routine shows to create PIN devices on the RT_Thread system

2. Use environment
    Hardware environment: development hardware platform corresponding to the project 
    Development board:      N32G4FRH_STB V1.1

3. Instructions for use
    Describe the configuration method of related modules; for example: clock, I/O, etc. 
        1. SystemClock: 144MHz
        2. GPIO: PA8 controls LED(D1) flashing; The PB5 controls LED(D3) flashing
                     KEY1--PA4, KEY2--PA5, KEY3--PA6
                     Log: TX--PA9 RX--PA10 Baud rate: 115200

    Describe the test steps and phenomena of Demo 
        1. After compiling, download the program to reset and run;
        2. This routine creates three threads, led0 thread, led1 thread key thread, led0 thread is used to control D1 500ms flashing, led1 thread is used to control D3 250ms flashing, 
            key thread detects KEY1, KEY2 and KEY3, and the KEY3 opens the interrupt function, When KEY3 is pressed, the interrupt callback function is called, and the corresponding log is printed when a key is pressed

4. Matters needing attention
    None.