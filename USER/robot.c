#include "robot.h"
#include "timer.h"
#include "delay.h"

u8 i=0;
u8 zhenzhen = 200;
//直立状态下迈出右脚
void step1()    
{
	for(i=0;i<6;i++)    //抬右脚
	{
		Servo4(130-6*i); 
		//delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)   //立左脚
	{
		Servo3(150-6*i); 
		//delay_ms(30);
	}
	delay_ms(zhenzhen);

	Servo2(135-6*i);  //转右脚
	delay_ms(zhenzhen);
	Servo1(140-30); 
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)    //收左脚
	{
		Servo3(120+6*i); 
		delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)  //放右脚
	{
		Servo4(100+6*i); 
		delay_ms(30);
	}
	delay_ms(zhenzhen);
}
//右脚在前，左脚在后状态下迈出左脚
void step2()
{
	
	for(i=0;i<6;i++)  //抬左脚
	{
		Servo3(150+6*i); 
	//	delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)  //立右脚
	{
		Servo4(130+6*i); 
	//	delay_ms(30);
	}
	delay_ms(zhenzhen);
	Servo1(110+50); 
	delay_ms(zhenzhen);

	Servo2(105+50);  //转右脚
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)    //收右脚
	{
		Servo4(160-6*i); 
	    delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)  //收左脚
	{
		Servo3(180-6*i); 
		delay_ms(30);
	}
	delay_ms(zhenzhen);
}
//左脚在前右脚在后
void step3(void)
{
	for(i=0;i<6;i++)    //抬右脚
	{
		Servo4(130-6*i); 
		//delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)   //立左脚
	{
		Servo3(150-6*i); 
		//delay_ms(30);
	}
	delay_ms(zhenzhen);
	Servo2(155-50); //转右脚
	delay_ms(zhenzhen);
	
	Servo1(160-50);  //转左脚
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)    //收左脚
	{
		Servo3(120+6*i); 
		delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)  //放右脚
	{
		Servo4(100+6*i); 
		delay_ms(30);
	}
	delay_ms(zhenzhen);
}
