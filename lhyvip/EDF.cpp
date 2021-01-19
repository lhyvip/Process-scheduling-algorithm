#include"AL.h"
#include<iostream>
#include<fstream>
using namespace std;
#define closetime 200
#define PERIOD1 10 /*任务1的周期*/
#define PERIOD2 40 /*任务2的周期*/
#define CPUTIME1 5 /*任务1需要的CPU时间*/
#define CPUTIME2 20 /*任务2需要的CPU时间*/

typedef struct TCB { int period; /*周期*/
                     int cputime;/*需要的cpu时间*/
                     int remain; /*剩余的cpu时间*/
                     int pnum; /*所处周期数*/
                     int laxity; /*松弛度*/
                   } TCB;
TCB tcb[2]; /*任务控制块，容易扩充为多个*/

int curtime; /*当前时间，初始为0*/

void init(void)
{
	int i;float f;
	curtime=0;/*当前时间为0*/

	tcb[0].period=PERIOD1;tcb[0].cputime=CPUTIME1;/*周期与*/
	tcb[1].period=PERIOD2;tcb[1].cputime=CPUTIME2;/*CPU时间*/

	f=(float)tcb[0].cputime/tcb[0].period+(float)tcb[1].cputime/tcb[1].period;/*数据合法性检查*/
	if(f>1)
	{
		cout<<"非法周期！";
		return;
	}

   	for(i=0;i<2;++i){ tcb[i].pnum=1;/*初始周期号*/
   	tcb[i].remain=tcb[i].cputime;/*初始剩余时间*/
	}
}

void schedule(void)/*调度程序*/
{
	int i,p;/*i是被调度运行任务，p是当前周期值*/
	int duration;/*本次运行持续时间*/

	i=tcb[0].period*tcb[0].pnum<=tcb[1].period*tcb[1].pnum?0:1;/*选最早截止时间的的任务*/
	if(curtime<tcb[i].period*(tcb[i].pnum-1))/*尚未进入该周期*/
	{
		p=tcb[i].period*(tcb[i].pnum-1);
		i=(i+1)%2;/*选另一个任务*/

		if(curtime<tcb[i].period*(tcb[i].pnum-1))/*尚未进入该周期*/
			curtime=p;
		else if(tcb[i].remain<=p-curtime)
			duration=tcb[i].remain; /*让它运行到结束*/
		else
			duration=p-curtime;/*只能运行到下个周期到来时刻*/

		tcb[i].remain-=duration;/*修改剩余时间*/
		cout<<"任务号="<<i<<"   周期序号="<<tcb[i].pnum<<"   调度时刻="<<curtime<<"   运行时间长度"<<duration<<"\n";
		curtime+=duration;/*时间推进到下一调度时刻*/
		if(tcb[i].remain==0)
		{/*本周期的任务已完成*/
			tcb[i].pnum++;/*向前推进一个周期*/
			tcb[i].remain=tcb[i].cputime;/*设置初始剩余时间*/
		}
	}
	else
	{
		p=tcb[i].period*tcb[i].pnum;
		if(tcb[i].remain<=p-curtime)
			duration=tcb[i].remain; /*让它运行到结束*/
		else
			duration=p-curtime;/*只能运行到下个周期到来时刻*/

		tcb[i].remain-=duration;/*修改剩余时间*/
		cout<<"任务号="<<i<<"   周期序号="<<tcb[i].pnum<<"   调度时刻="<<curtime<<"   运行时间长度"<<duration<<"\n";

		curtime+=duration;/*时间推进到下一调度时刻*/
		if(tcb[i].remain==0)
		{/*本周期的任务已完成*/
			tcb[i].pnum++;/*向前推进一个周期*/
			tcb[i].remain=tcb[i].cputime;/*设置初始剩余时间*/
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
