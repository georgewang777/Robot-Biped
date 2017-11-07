#include "george_system.h"

char RxBuffer[15];     //���մ�����������
u8 RxCount;           //Index
u8 pre_cnt_rs2=0;    //���ݱ�־
u8 tim2_count;    	//��ʱ��3������־
u8 Mk_Usart1All=0;	 //����1����һ��������ɱ�־
u8 status;           //������־λ

int main(void)
{
	Init(); //System Init
	Tm1624_Dispaly();
	while(1)
	{
		if(status==1)
		{
			Forward();
			status = 0;
		}
		if(status==2)
		{
			Dance();
			delay_ms(500);
			shake();
			status = 0 ;
		}
		if(status == 3)
		{
			shake();
			status = 0;
		}
		if(status ==4)
		{
		   Turn_Right();
			status  = 0 ;
		}
		if(status  ==5)
		{
			Turn_Left();
			status = 0;
		}
		if(status==6)
		{
			Back();
			status  = 0;
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
