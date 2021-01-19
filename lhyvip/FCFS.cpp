#include"AL.h"
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

bool cmp1(PCB a,PCB b){
return a.at<b.at;
}

void AL::FCFS(){

int n=this->read("yuanfcfs.txt");
for(int i=1;i<=n;++i){
    process[i].bt=1000;
}

//算法
sort(&process[1],&process[1]+n,cmp1);//时间由小到大排序
int time=process[1].at;
int num=0;
int i=1;
while(num!=5){
    if(process[i].at<=time){
        if(process[i].bt==1000){
            process[i].bt=time;
        }
        process[i].ct=time+process[i].st;
        time=process[i].ct;
        process[i].sc=1;
        i++;
        num++;
    }else{
    time=process[i].at;
    }

}
//写入到文件
this->write("mudifcfs.txt",n);

//打印信息
this->print_process_information(n);

}
