#include "george_system.h"
u8 Pulse1,Pulse2,Pulse3,Pulse4;

void Init(void)
{
	SystemInit();  //配置系统时钟为72M
	delay_init(72);	    	 //延时函数初始化	  
	NVIC_Configuration();
	uart_init(115200);
	uart2_init(115200);
	Pulse1 = 140;
	Pulse2 = 130;
	Pulse3 = 150;
	Pulse4 = 130;
  TIM2_Int_Init(50-1,7200-1);     //定时器时钟72M，分频系数7200，所以72M/7200=10Khz的计数频率，计数50次为5ms  
  Servo_Init();  
	Step_Motor_GPIO_Init();
	Tm1624_Init();
}
