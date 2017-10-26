#include "robot.h"
#include "timer.h"
#include "delay.h"

u8 i=0;

//ֱ��״̬�������ҽ�
void step1()    
{
	for(i=0;i<11;i++)    //̧�ҽ�
	{
		Servo4(130-3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)   //�����
	{
		Servo3(150-3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)   //ת�ҽ�
	{
		Servo2(150-3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //ת���
	{
		Servo1(150-3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)    //�����
	{
		Servo3(120+3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //���ҽ�
	{
		Servo4(100+3*i); 
		delay_ms(50);
	}
}
//�ҽ���ǰ������ں�״̬���������
void step2()
{
	
	for(i=0;i<11;i++)  //̧���
	{
		Servo3(150+4*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //���ҽ�
	{
		Servo4(130+3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //ת���
	{
		Servo1(110+6*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //ת�ҽ�
	{
		Servo2(110+6*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)    //���ҽ�
	{
		Servo4(160-3*i); 
		delay_ms(30);
	}
	for(i=0;i<11;i++)  //�����
	{
		Servo3(190-4*i); 
		delay_ms(30);
	}
}
