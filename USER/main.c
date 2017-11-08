#include "george_system.h"

extern u8 RxCount;    //Index
u8 Mk_UsartAll=0;	   //接收一组数据完成标志
u8 status;           //动作标志位

void process(void)
{
	switch(status)
	{
		case 1: Forward();break;    //前进
		case 2: Backward();break;   //后退
		case 3: Turn_Right();break; //右转
		case 4: Turn_Left();break;  //左转
		case 5: Dance();    break;  //跳舞
		case 6: Shake();    break;  //摇摆
		case 7: Head_Action();break;//头部
		default: status = 0;break;
	}
}
int main(void)
{
	Init(); //System Init
	while(1)
	{	
		Tm1624_Dispaly();  //灯光效果
		if(Mk_UsartAll==1) //接收到数据
		{
			Mk_UsartAll=0;
			RxCount=0;
			UsartRace_Data();//处理接收到的数据
			process();       //机器人动作
			ClearUart2();
		}
	}
}

