1. ����˵��
    ������չʾ�� RT_Thread �ʼ��Ĵ��������ͺͽ���

2. ʹ�û���
    Ӳ�����������̶�Ӧ�Ŀ���Ӳ��ƽ̨ 
    �����壺   N32G4FRH_STB V1.1

3. ʹ��˵��
    �������ģ�����÷���������:ʱ�ӣ�I/O�� 
         1. SystemClock��144MHz
         2. GPIO��KEY1--PA4, KEY2--PA5, KEY3--PA6
                        ��־��TX--PA9  RX--PA10�������ʣ�115200

    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ����
         2. �Ӻô��ڴ�ӡ����
         3. �����̴��������̣߳�key �̺߳� test �̣߳�key �̼߳�ⰴ�������ʼ���test �߳̽����ʼ������°�����KEY1��KEY2��KEY3�������ʼ����鿴��ӡ��־

4. ע������
    ��

1. Function description
    This routine shows the creation, sending, and receiving of a mail  in RT_Thread

2. Use environment
    Hardware environment: development hardware platform corresponding to the project 
    Development board:      N32G4FRH_STB V1.1

3. Instructions for use
    Describe the configuration method of related modules; for example: clock, I/O, etc. 
        1. SystemClock: 144MHz
        2. GPIO: KEY1--PA4, KEY2--PA5, KEY3--PA6
                     Log: TX--PA9 RX--PA10 Baud rate: 115200

    Describe the test steps and phenomena of Demo 
        1. After compiling, download the program to reset and run;
        2. Connect the serial port printing tool;
        3. This routine creates two threads, key thread and test thread, key thread detects the key to send mail, test thread receives mail, press the key (KEY1,KEY2,KEY3) to send mail, and view the print log

4. Matters needing attention
    None.