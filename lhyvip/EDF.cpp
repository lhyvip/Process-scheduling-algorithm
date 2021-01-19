#include"AL.h"
#include<iostream>
#include<fstream>
using namespace std;
#define closetime 200
#define PERIOD1 10 /*����1������*/
#define PERIOD2 40 /*����2������*/
#define CPUTIME1 5 /*����1��Ҫ��CPUʱ��*/
#define CPUTIME2 20 /*����2��Ҫ��CPUʱ��*/

typedef struct TCB { int period; /*����*/
                     int cputime;/*��Ҫ��cpuʱ��*/
                     int remain; /*ʣ���cpuʱ��*/
                     int pnum; /*����������*/
                     int laxity; /*�ɳڶ�*/
                   } TCB;
TCB tcb[2]; /*������ƿ飬��������Ϊ���*/

int curtime; /*��ǰʱ�䣬��ʼΪ0*/

void init(void)
{
	int i;float f;
	curtime=0;/*��ǰʱ��Ϊ0*/

	tcb[0].period=PERIOD1;tcb[0].cputime=CPUTIME1;/*������*/
	tcb[1].period=PERIOD2;tcb[1].cputime=CPUTIME2;/*CPUʱ��*/

	f=(float)tcb[0].cputime/tcb[0].period+(float)tcb[1].cputime/tcb[1].period;/*���ݺϷ��Լ��*/
	if(f>1)
	{
		cout<<"�Ƿ����ڣ�";
		return;
	}

   	for(i=0;i<2;++i){ tcb[i].pnum=1;/*��ʼ���ں�*/
   	tcb[i].remain=tcb[i].cputime;/*��ʼʣ��ʱ��*/
	}
}

void schedule(void)/*���ȳ���*/
{
	int i,p;/*i�Ǳ�������������p�ǵ�ǰ����ֵ*/
	int duration;/*�������г���ʱ��*/

	i=tcb[0].period*tcb[0].pnum<=tcb[1].period*tcb[1].pnum?0:1;/*ѡ�����ֹʱ��ĵ�����*/
	if(curtime<tcb[i].period*(tcb[i].pnum-1))/*��δ���������*/
	{
		p=tcb[i].period*(tcb[i].pnum-1);
		i=(i+1)%2;/*ѡ��һ������*/

		if(curtime<tcb[i].period*(tcb[i].pnum-1))/*��δ���������*/
			curtime=p;
		else if(tcb[i].remain<=p-curtime)
			duration=tcb[i].remain; /*�������е�����*/
		else
			duration=p-curtime;/*ֻ�����е��¸����ڵ���ʱ��*/

		tcb[i].remain-=duration;/*�޸�ʣ��ʱ��*/
		cout<<"�����="<<i<<"   �������="<<tcb[i].pnum<<"   ����ʱ��="<<curtime<<"   ����ʱ�䳤��"<<duration<<"\n";
		curtime+=duration;/*ʱ���ƽ�����һ����ʱ��*/
		if(tcb[i].remain==0)
		{/*�����ڵ����������*/
			tcb[i].pnum++;/*��ǰ�ƽ�һ������*/
			tcb[i].remain=tcb[i].cputime;/*���ó�ʼʣ��ʱ��*/
		}
	}
	else
	{
		p=tcb[i].period*tcb[i].pnum;
		if(tcb[i].remain<=p-curtime)
			duration=tcb[i].remain; /*�������е�����*/
		else
			duration=p-curtime;/*ֻ�����е��¸����ڵ���ʱ��*/

		tcb[i].remain-=duration;/*�޸�ʣ��ʱ��*/
		cout<<"�����="<<i<<"   �������="<<tcb[i].pnum<<"   ����ʱ��="<<curtime<<"   ����ʱ�䳤��"<<duration<<"\n";

		curtime+=duration;/*ʱ���ƽ�����һ����ʱ��*/
		if(tcb[i].remain==0)
		{/*�����ڵ����������*/
			tcb[i].pnum++;/*��ǰ�ƽ�һ������*/
			tcb[i].remain=tcb[i].cputime;/*���ó�ʼʣ��ʱ��*/
		}
	}
}

void AL::EDF()
{
	init();
	while(curtime<closetime){
	schedule();
	}
}
