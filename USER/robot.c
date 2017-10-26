#include "robot.h"
#include "timer.h"
#include "delay.h"

u8 i=0;

//直立状态下迈出右脚
void step1()    
{
	for(i=0;i<11;i++)    //抬右脚
	{
		Servo4(130-3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)   //立左脚
	{
		Servo3(150-3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)   //转右脚
	{
		Servo2(150-3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //转左脚
	{
		Servo1(150-3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)    //收左脚
	{
		Servo3(120+3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //放右脚
	{
		Servo4(100+3*i); 
		delay_ms(50);
	}
}
//右脚在前，左脚在后状态下迈出左脚
void step2()
{
	
	for(i=0;i<11;i++)  //抬左脚
	{
		Servo3(150+4*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //立右脚
	{
		Servo4(130+3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //转左脚
	{
		Servo1(110+6*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //转右脚
	{
		Servo2(110+6*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)    //收右脚
	{
		Servo4(160-3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //收左脚
	{
		Servo3(190-4*i); 
		delay_ms(30);
	}
}
