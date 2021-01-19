#ifndef AL_H
#define AL_H
#include<iostream>
#include<string>
using namespace std;
#define D 50
typedef struct PCB{
    int pn;//process name进程名字
	int at;//arrival time到达时间
	int st;//service time服务时间
	int bt;//begin time开始时间
	int ct;//completion time完成时间
	int sc;//yes or no completion是否完成
	int zt;//周转时间
	double dt;// 带权周转时间
	int st1;//剩余服务时间
	double xyb;//响应比
	int rr;//用于判断
};

class AL
{
    public:
        AL();
        virtual ~AL();
        PCB process[D];
        int read(char a[]);//从txt中读取数据返回行数同时实现如下算法
        void write(char a[],int n);//传入地址和进程数
        void print_process_information(int n);//传递进程信息
        void print_choose();
        void choose();
        void FCFS();
        void RR(int a);
        void SRT();
        void SJF();
        void HRRN();
        void EDF();//非抢占
        void LLF();//最低松弛度算法
        void banker();//银行家算法

    private:
};

#endif // AL_H
