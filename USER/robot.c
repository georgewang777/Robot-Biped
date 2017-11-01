#include "robot.h"
#include "timer.h"
#include "delay.h"
#include "usart.h"
#define n 1

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
		delay_ms(7);
	}
	//printf("beauty:%d",Pulse2);
}

void Servo1_pos(u8 dir,u8 angle)
{
	for(i=0;i<angle;i++)
	{
		if(dir==0) {Pulse1 = Pulse1 + 1;}
		else {Pulse1 = Pulse1 -1;}
		Servo1(Pulse1);
		delay_ms(7);
	}
	//printf("beauty:%d",Pulse1);
}
void  Dance(void)
{
	u8 j;
	for(j=0;j<5;j++)
	{
		Servo3_pos(1,30);
		Servo4_pos(0,30);
		delay_ms(50);
		Servo3_pos(0,30);
		Servo4_pos(1,30);
	}
}

void Forward(void)
{
	int k = 0;
	Servo4_pos(0,30);
	delay_ms(n);
	Servo3_pos(0,30);
	delay_ms(n);
	Servo2_pos(1,20);
	delay_ms(n);
	Servo1_pos(1,20);
	delay_ms(n);
	Servo3_pos(1,30);
	delay_ms(n);
	Servo4_pos(1,30);
	
	for(k=0;k<5;k++)
	{
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
		Servo1_pos(0,30);
		delay_ms(n);
		Servo2_pos(0,30);
		delay_ms(n);
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
		
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
		Servo2_pos(1,30);
		delay_ms(n);
		Servo1_pos(1,30);
		delay_ms(n);
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
	}
	Servo2_pos(0,20);
	delay_ms(n);
	Servo1_pos(0,20);
	delay_ms(n);
}
void Back(void)
{
	int k = 0;
	Servo3_pos(1,30);
	delay_ms(n);
	Servo4_pos(1,30);
	delay_ms(n);
	Servo1_pos(1,20);
	delay_ms(n);
	Servo2_pos(1,20);
	delay_ms(n);
	Servo4_pos(0,30);
	delay_ms(n);
	Servo3_pos(0,30);
	
	for(k=0;k<5;k++)
	{
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
		Servo2_pos(0,30);
		delay_ms(n);
		Servo1_pos(0,30);
		delay_ms(n);
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
		
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
		Servo1_pos(1,30);
		delay_ms(n);
		Servo2_pos(1,30);
		delay_ms(n);
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
	}
	Servo1_pos(0,20);
	delay_ms(n);
	Servo2_pos(0,20);
	delay_ms(n);
}
void shake(void)
{
	u8 k=0;
	Servo4_pos(0,20);
	delay_ms(n);
	Servo3_pos(0,20);
	delay_ms(n);
	Servo1_pos(0,20);
	delay_ms(n);
	for(k=0;k<10;k++)
	{
		Servo1_pos(1,40);
		delay_ms(n);
		Servo1_pos(0,40);
		delay_ms(n);
	}
	Servo1_pos(1,20);
	delay_ms(n);
	Servo4_pos(1,20);
	delay_ms(n);
	Servo3_pos(1,20);
	delay_ms(2000);
	
	Servo3_pos(1,20);
	delay_ms(n);
	Servo4_pos(1,20);
	delay_ms(n);
	Servo2_pos(0,20);
	delay_ms(n);
	for(k=0;k<10;k++)
	{
		Servo2_pos(1,40);
		delay_ms(n);
		Servo2_pos(0,40);
		delay_ms(n);
	}
	Servo2_pos(1,20);
	delay_ms(n);
	Servo4_pos(0,20);
	delay_ms(n);
	Servo3_pos(0,20);
	delay_ms(n);
}

void Turn_Right(void)
{
	u8 i =0;
	for(i=0;i<3;i++)
	{
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
		Servo2_pos(1,20);
		delay_ms(n);
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
		Servo2_pos(0,20);
		delay_ms(n);
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
	 }
	
}

void Turn_Left(void)
{
	u8 i =0;
	for(i=0;i<3;i++)
	{
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
		Servo1_pos(0,20);
		delay_ms(n);
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
		Servo1_pos(1,20);
		delay_ms(n);
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
	}
	
}

