#include "george_system.h"

char RxBuffer[15];     //接收串口数据数组
u8 RxCount;           //Index
u8 pre_cnt_rs2=0;    //数据标志
u8 tim2_count;    	//定时器3计数标志
u8 Mk_Usart1All=0;	 //串口1接收一组数据完成标志
u8 status;           //动作标志位

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

//定时器3中断服务函数
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET) //溢出中断
	{
		if(RxCount!=0)  //有数据接收
		{
			if(RxCount == pre_cnt_rs2)    //接收完成
			{
				tim2_count++;
				if(tim2_count>=4)
				{
					  Mk_Usart1All=1;             //交给主函数处理
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
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //清除中断标志位
}
