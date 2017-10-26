#include "timer.h"
#include "usart.h"

//通用定时器3中断初始化
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
//这里使用的是定时器3!
void TIM2_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  					//使能TIM3时钟
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 									//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  								//定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);					//初始化TIM3
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);									 //允许定时器3更新中断
	TIM_Cmd(TIM2,ENABLE); 																			//使能定时器3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;							 //定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; 			//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void TIM3_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB , ENABLE); 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7 ; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1 ; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = arr; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc;
	TIM_TimeBaseStructure.TIM_ClockDivision =0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	//TIM3_CH1 PA6
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 140; //
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //TIM输出极性高
	TIM_OC1Init(TIM3, &TIM_OCInitStructure); 
	
	//TIM3_CH2  PA7
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 135; //
	TIM_OC2Init(TIM3, &TIM_OCInitStructure); 
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	//TIM3_CH3   PB0
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 150; //
	TIM_OC3Init(TIM3, &TIM_OCInitStructure); 
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	//TIM3_CH4   PB1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	//比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 130; //
	TIM_OC4Init(TIM3, &TIM_OCInitStructure); 
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);   					 //CH4预装载使能
	
	TIM_CtrlPWMOutputs(TIM3,ENABLE);                                						//MOE 主输出使能
	TIM_ARRPreloadConfig(TIM3, ENABLE); 													//使能TIM3在ARR上的预装载寄存器
	TIM_Cmd(TIM3, ENABLE);                       
}

//1号舵机
//compare: 50- 250  对应0.5ms--2.5ms
void Servo1(u32 compare)
{
	TIM_SetCompare1(TIM3,compare);
}

//2号舵机
void Servo2(u32 compare)
{
	TIM_SetCompare2(TIM3,compare);
}

//3号舵机
void Servo3(u32 compare)
{
	TIM_SetCompare3(TIM3,compare);
}

//4号舵机
void Servo4(u32 compare)
{
	TIM_SetCompare4(TIM3,compare);
}
