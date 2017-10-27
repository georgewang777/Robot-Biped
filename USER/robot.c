#include "robot.h"
#include "timer.h"
#include "delay.h"
#include "usart.h"
u8 i=0;
u8 zhenzhen = 200;
u8 tim1 =10;
extern u8 Pulse1,Pulse2,Pulse3,Pulse4;

/*************************************
----dir:0 À≥ ±’Î-------
----dir:1 ƒÊ ±’Î-------
************************************/
void Servo4_pos(u8 dir,u8 angle)
{
	for(i=0;i<angle;i++)
	{
		if(dir==0) {Pulse4 = Pulse4 -1;}
		else {Pulse4 = Pulse4 +1;}
		Servo4(Pulse4);
		delay_ms(tim1);
	}
}

void Servo3_pos(u8 dir,u8 angle)
{
	for(i=0;i<angle;i++)
	{
		if(dir==0) {Pulse3 = Pulse3 - 1;}
		else {Pulse3 = Pulse3 +1;}
		Servo3(Pulse3);
		delay_ms(tim1);
	}
	printf("beauty:%d",Pulse3);
}

void Servo2_pos(u8 dir,u8 angle)
{
	for(i=0;i<angle;i++)
	{
		if(dir==0) {Pulse2 = Pulse2 + 1;}
		else {Pulse2 = Pulse2 -1;}
		Servo2(Pulse2);
		delay_ms(tim1);
	}
	printf("beauty:%d",Pulse2);
}

void Servo1_pos(u8 dir,u8 angle)
{
	for(i=0;i<angle;i++)
	{
		if(dir==0) {Pulse1 = Pulse1 + 1;}
		else {Pulse1 = Pulse1 -1;}
		Servo1(Pulse1);
		delay_ms(tim1);
	}
	printf("beauty:%d",Pulse1);
}

