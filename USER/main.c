#include "george_system.h"

extern u8 RxCount;    //Index
u8 Mk_UsartAll=0;	   //����һ��������ɱ�־
u8 status;           //������־λ

void process(void)
{
	switch(status)
	{
		case 1: Forward();break;    //ǰ��
		case 2: Backward();break;   //����
		case 3: Turn_Right();break; //��ת
		case 4: Turn_Left();break;  //��ת
		case 5: Dance();    break;  //����
		case 6: Shake();    break;  //ҡ��
		case 7: Head_Action();break;//ͷ��
		default: status = 0;break;
	}
}
int main(void)
{
	Init(); //System Init
	while(1)
	{	
		Tm1624_Dispaly();  //�ƹ�Ч��
		if(Mk_UsartAll==1) //���յ�����
		{
			Mk_UsartAll=0;
			RxCount=0;
			UsartRace_Data();//������յ�������
			process();       //�����˶���
			ClearUart2();
		}
	}
}

