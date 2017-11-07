#include "george_system.h"
u8 Pulse1,Pulse2,Pulse3,Pulse4;

void Init(void)
{
	SystemInit();  //����ϵͳʱ��Ϊ72M
	delay_init(72);	    	 //��ʱ������ʼ��	  
	NVIC_Configuration();
	uart_init(115200);
	uart2_init(115200);
	Pulse1 = 140;
	Pulse2 = 130;
	Pulse3 = 150;
	Pulse4 = 130;
  TIM2_Int_Init(50-1,7200-1);     //��ʱ��ʱ��72M����Ƶϵ��7200������72M/7200=10Khz�ļ���Ƶ�ʣ�����50��Ϊ5ms  
  Servo_Init();  
	Step_Motor_GPIO_Init();
	Tm1624_Init();
}
