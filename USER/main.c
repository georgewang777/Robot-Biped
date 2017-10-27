#include "stm32f10x.h"
#include "timer.h"
#include "usart.h"
#include "usart2.h"
#include "sys.h"
#include "delay.h"
#include "robot.h"

char RxBuffer[15];     //���մ�����������
u8 RxCount;                //Index
u8 pre_cnt_rs2=0; 	//���ݱ�־
u8 tim2_count;    		//��ʱ��3������־
u8 Mk_Usart1All=0;	//����1����һ��������ɱ�־
u8 status;                     //������־λ

int main(void)
{
	SystemInit();  //����ϵͳʱ��Ϊ72M
	delay_init(72);	    	 //��ʱ������ʼ��	  
	NVIC_Configuration();
	uart_init(115200);
	uart2_init(115200);
   TIM2_Int_Init(50-1,7200-1);          //��ʱ��ʱ��72M����Ƶϵ��7200������72M/7200=10Khz�ļ���Ƶ�ʣ�����50��Ϊ5ms  
   TIM3_PWM_Init(2000-1,720-1);      //72M/720=100k�ļ���Ƶ�ʣ��Զ���װ��Ϊ2000����ôPWMƵ��Ϊ100k/2000=50HZ������Ϊ20ms
//	Servo1(150);
//	delay_ms(1000);
//	Servo2(150);
//	delay_ms(1000);
//	Servo3(150);
//	delay_ms(1000);
//	Servo4(130);
//	
//	delay_ms(2000);
	
	while(1)
	{
		if (status==0)
		{
			step1();     //ֱ��״̬�������ҽ�
			status = 1;
		}
		if(status==1)
		{
			step2();
			step3();
		}
		if(Mk_Usart1All==1)
		{
			Mk_Usart1All=0;
			RxCount=0;
//			//printf("yumeiren:%s\n",RxBuffer);
//			USART2_Puts(RxBuffer);
//			USART2_Puts("beauty!\n");
			UsartRace_Data();
			ClearUart2();
		}
	}
}

//��ʱ��3�жϷ�����
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET) //����ж�
	{
		if(RxCount!=0)  //�����ݽ���
		{
			if(RxCount == pre_cnt_rs2)    //�������
			{
				tim2_count++;
				if(tim2_count>=4)
				{
					  Mk_Usart1All=1;             //��������������
					  tim2_count=0;
				}
			}
			else
			{
				tim2_count = 0;
				pre_cnt_rs2 = RxCount;
			}
		}
		
	}
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //����жϱ�־λ
}
