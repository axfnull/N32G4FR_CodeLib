1. 功能说明
    此例程展示在 RT_Thread 系统创建线程

2. 使用环境
    硬件环境：工程对应的开发硬件平台 
    开发板：    N32G4FRH_STB V1.1

3. 使用说明
    描述相关模块配置方法；例如:时钟，I/O等 
         1. SystemClock：144MHz
         2. GPIO：PA8 控制 LED(D1) 闪烁；PB5 控制 LED(D3) 闪烁；
                        日志:   TX--PA9  RX--PA10    波特率：115200

    描述Demo的测试步骤和现象 
         1. 编译后下载程序复位运行；
         2. 本例程在main()里面创建两个线程，led0 线程和 led1 线程，led0 线程用于控制 D1 1s闪烁，led1 线程用于控制 D3 500ms闪烁，以此循环

4. 注意事项
    无

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