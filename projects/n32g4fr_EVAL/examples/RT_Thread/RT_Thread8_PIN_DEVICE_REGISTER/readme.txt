1. 功能说明
    此例程展示在 RT_Thread 系统创建 PIN 设备

2. 使用环境
    硬件环境：工程对应的开发硬件平台 
    开发板：   N32G4FRH_STB V1.1

3. 使用说明
    描述相关模块配置方法；例如:时钟，I/O等 
         1. SystemClock：144MHz
         2. GPIO：PA8 控制 LED(D1) 闪烁;PB5 控制 LED(D3) 闪烁;
                        KEY1--PA4，KEY2--PA5, KEY3--PA6
                        日志：TX--PA9  RX--PA10，波特率：115200

    描述Demo的测试步骤和现象 
         1. 编译后下载程序复位运行
         2. 本例程创建三个线程，led0 线程、led1 线程 key 线程，led0 线程用于控制 D1 500ms闪烁，led1 线程用于控制 D3 250ms闪烁，
            key 线程检测 KEY1、KEY2和KEY3，其中KEY3开启中断功能，当KEY3按下时，调用中断回调函数，有按键按下时打印相应日志

4. 注意事项
    无

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