#ifndef   __ROBOT_H
#define	__ROBOT_H

#include "stm32f10x.h"


void Servo1_pos(u8 dir,u8 angle);

void Servo2_pos(u8 dir,u8 angle);

void Servo3_pos(u8 dir,u8 angle);

void Servo4_pos(u8 dir,u8 angle);

void Forward(void);

void  Dance(void);

void shake(void);

void Turn_Right(void);

void Turn_Left(void);
#endif
