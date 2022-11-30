1、功能说明

    1、此例程展示控制 LED（D6、D17）闪烁

2、使用环境

        /* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32G4FRRL-STB_V1.1

3、使用说明
    
    /* 描述相关模块配置方法；例如:时钟，I/O等 */
        SystemClock：144MHz
        GPIO：PB10 控制 LED(D6) 常亮；PB15 控制 LED(D17) 闪烁；PA5、PA6、PA9 IO 电平翻转


    /* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行
        2.D6常亮，D17 闪烁

4、注意事项
    无
	
	
	
1. Function description
    1. This example shows the control LED (D6, D17) blinking.
	
2. Use environment
    /*Hardware environment: Project corresponding development hardware platform*/
	1.Developed based on the evaluation board N32G4XR-STB V1.1
	
3. Instructions for use
    /* Describe the related module configuration method; For example: clock, I/O, etc. */
	1. SystemClock: 144 MHZ
	2. PB10 control LED (D6) is always on; PB15 control LED (D17) is flashing; PA5, PA6, PA9 IO level flip.
	
	/* Describes the test steps and symptoms of Demo */
	1. The downloaded program is reset and running after compilation
	2. D6 is steady on, and D17 is blinking.
		
4. Matters needing attention
   None.
   
