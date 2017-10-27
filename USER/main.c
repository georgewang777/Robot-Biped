#include "stm32f10x.h"
#include "timer.h"
#include "usart.h"
#include "usart2.h"
#include "sys.h"
#include "delay.h"
#include "robot.h"
char RxBuffer[15];     //���մ�����������
u8 RxCount;                //Index
u8 pre_cnt_rs2=0;      //���ݱ�־
u8 tim2_count;    		 //��ʱ��3������־
u8 Mk_Usart1All=0;	 //����1����һ��������ɱ�־
u8 status;                    //������־λ
u8 Pulse1,Pulse2,Pulse3,Pulse4;
u8 angle4,dir4;
//�������ݽ���
void UsartRace_Data(void)
{
	if(!(strcmp_str(RxBuffer,"pei",3)))
	{
		status = 1;
		angle4 = (RxBuffer[4]-'0')*10 + (RxBuffer[5]-'0');
		dir4 = RxBuffer[3]-'0';
	}
	else
	{
		status = 0;
	}
		
}
int main(void)
{
	u8 j;
	SystemInit();  //����ϵͳʱ��Ϊ72M
	delay_init(72);	    	 //��ʱ������ʼ��	  
	NVIC_Configuration();
	uart_init(115200);
	uart2_init(115200);
	Pulse1 = 140;
	Pulse2 = 135;
	Pulse3 = 150;
	Pulse4 = 130;
   TIM2_Int_Init(50-1,7200-1);          //��ʱ��ʱ��72M����Ƶϵ��7200������72M/7200=10Khz�ļ���Ƶ�ʣ�����50��Ϊ5ms  
   TIM3_PWM_Init(2000-1,720-1);      //72M/720=100k�ļ���Ƶ�ʣ��Զ���װ��Ϊ2000����ôPWMƵ��Ϊ100k/2000=50HZ������Ϊ20ms
	
	while(1)
	{
		
		if (status==1)
		{
			printf("dir:%d,angle:%d\r\n",dir4,angle4);
			for(j=0;j<20;j++)
			{
				Servo3_pos(1,30);
				Servo4_pos(0,30);
				delay_ms(100);
				Servo3_pos(0,30);
				Servo4_pos(1,30);
			}
			//printf("zhenzhen:%d\r\n",Pulse4);
			status = 0;
		}
		if(Mk_Usart1All==1)
		{
			Mk_Usart1All=0;
			RxCount=0;
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
