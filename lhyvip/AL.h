#ifndef AL_H
#define AL_H
#include<iostream>
#include<string>
using namespace std;
#define D 50
typedef struct PCB{
    int pn;//process name��������
	int at;//arrival time����ʱ��
	int st;//service time����ʱ��
	int bt;//begin time��ʼʱ��
	int ct;//completion time���ʱ��
	int sc;//yes or no completion�Ƿ����
	int zt;//��תʱ��
	double dt;// ��Ȩ��תʱ��
	int st1;//ʣ�����ʱ��
	double xyb;//��Ӧ��
	int rr;//�����ж�
};

class AL
{
    public:
        AL();
        virtual ~AL();
        PCB process[D];
        int read(char a[]);//��txt�ж�ȡ���ݷ�������ͬʱʵ�������㷨
        void write(char a[],int n);//�����ַ�ͽ�����
        void print_process_information(int n);//���ݽ�����Ϣ
        void print_choose();
        void choose();
        void FCFS();
        void RR(int a);
        void SRT();
        void SJF();
        void HRRN();
        void EDF();//����ռ
        void LLF();//����ɳڶ��㷨
        void banker();//���м��㷨

    private:
};

#endif // AL_H
