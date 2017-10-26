#include "robot.h"
#include "timer.h"
#include "delay.h"

u8 i=0;
u8 zhenzhen = 200;
//ֱ��״̬�������ҽ�
void step1()    
{
	for(i=0;i<6;i++)    //̧�ҽ�
	{
		Servo4(130-6*i); 
		//delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)   //�����
	{
		Servo3(150-6*i); 
		//delay_ms(30);
	}
	delay_ms(zhenzhen);

	Servo2(135-6*i);  //ת�ҽ�
	delay_ms(zhenzhen);
	Servo1(140-30); 
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)    //�����
	{
		Servo3(120+6*i); 
		delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)  //���ҽ�
	{
		Servo4(100+6*i); 
		delay_ms(30);
	}
	delay_ms(zhenzhen);
}
//�ҽ���ǰ������ں�״̬���������
void step2()
{
	
	for(i=0;i<6;i++)  //̧���
	{
		Servo3(150+6*i); 
	//	delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)  //���ҽ�
	{
		Servo4(130+6*i); 
	//	delay_ms(30);
	}
	delay_ms(zhenzhen);
	Servo1(110+50); 
	delay_ms(zhenzhen);

	Servo2(105+50);  //ת�ҽ�
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)    //���ҽ�
	{
		Servo4(160-6*i); 
	    delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)  //�����
	{
		Servo3(180-6*i); 
		delay_ms(30);
	}
	delay_ms(zhenzhen);
}
//�����ǰ�ҽ��ں�
void step3(void)
{
	for(i=0;i<6;i++)    //̧�ҽ�
	{
		Servo4(130-6*i); 
		//delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)   //�����
	{
		Servo3(150-6*i); 
		//delay_ms(30);
	}
	delay_ms(zhenzhen);
	Servo2(155-50); //ת�ҽ�
	delay_ms(zhenzhen);
	
	Servo1(160-50);  //ת���
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)    //�����
	{
		Servo3(120+6*i); 
		delay_ms(30);
	}
	delay_ms(zhenzhen);
	for(i=0;i<6;i++)  //���ҽ�
	{
		Servo4(100+6*i); 
		delay_ms(30);
	}
	delay_ms(zhenzhen);
}
