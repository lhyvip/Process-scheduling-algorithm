#include "AL.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
AL::AL()
{
    //ctor
}

AL::~AL()
{
    //dtor
}

bool cmp3(PCB a,PCB b){
return a.at<b.at;
}
//打印菜单
void AL::print_choose(){
cout<<"\n\n\t\t-----进程调度算法菜单-------\n";
cout<<"1. FCFS  :先来先服务\n";
cout<<"2. SJF   :短作业优先调度算法\n";
cout<<"3. HRRN  :高响应比算法\n";
cout<<"4. SRT   :最短剩余时间调度算法\n";
cout<<"5. RR    :时间片轮转调度算法\n";
cout<<"6. EDF   :最早截止时间优先算法\n";
cout<<"7. LLF   :最低松弛度算法\n";
cout<<"8. banker:银行家算法\n";
cout<<"9. EXIT  :退出！！\n";
cout<<"please input:";
    }

//菜单选项
void AL::choose(){
while(true){
    print_choose();
    int c;
    cin>>c;
    switch(c){
        case 1:this->FCFS();
        break;
        case 2:this->SJF();
            break;
        case 3:this->HRRN();
            break;
        case 4:this->SRT();
            break;
        case 5:this->RR(1);
               this->RR(4);
            break;
        case 6:this->EDF();
            break;
        case 7:this->LLF();
            break;
        case 8:this->banker();
            break;
        case 9:exit(0);
            break;
        default :cout<<"error:please choose again \n";
            break;

    }


}


}


//从txt中读取数据返回行数
int  AL::read(char a[]){
int num=0;//记录进程数
ifstream file1(a);
if(!file1){
    cout<<"打开失败\n";

}else{
//获取第一行的文字
string processname;
string processarriver;
string processservice;
file1>>processname;
file1>>processarriver;
file1>>processservice;
//获取信息
int i=1;

while(!file1.eof()){
    file1>>process[i].pn;
    file1>>process[i].at;
    file1>>process[i].st;
    process[i].sc=0;
    num++;
    i++;
}
num--;


}

/*for(int i=1;i<=num;i++){
    cout<<process[i].pn<<"  ";
    cout<<process[i].at<<"  ";
    cout<<process[i].st<<endl;
}*/

file1.close();
return num;
}

void AL::write(char a[],int n){
sort(&process[1],&process[1]+n,cmp3);
ofstream file2(a);
file2<<"运行的进程号 到达时间  服务时间 开始时间   结束时间   周转时间    带权周转时间 \n";
for(int i=1;i<=n;i++){//打印各进程的信息
int zhou=process[i].ct-process[i].at;
double daiquan=(zhou*1.0)/(process[i].st*1.0);
    file2<<process[i].pn<<"            "<<process[i].at<<"          "<<process[i].st<<"        ";
    file2<<process[i].bt<<"         "<<process[i].ct<<"           "<<zhou<<"           "<<daiquan<<endl;

	}



file2.close();

}


void AL::print_process_information(int n){
sort(&process[1],&process[1]+n,cmp3);
//打印信息
cout<<"\n运行的进程号 到达时间  服务时间 开始时间   结束时间   周转时间    带权周转时间 \n";
for(int i=1;i<=n;i++){//打印各进程的信息
int zhou=process[i].ct-process[i].at;
double daiquan=(zhou*1.0)/(process[i].st*1.0);
		cout<<process[i].pn<<"            "<<process[i].at<<"          "<<process[i].st<<"        ";
		cout<<process[i].bt<<"         "<<process[i].ct<<"           "<<zhou<<"           "<<daiquan<<endl;

	}



}

