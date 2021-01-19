#include"AL.h"
#include<iostream>
#include<queue>
using namespace std;
void AL::RR(int a){
cout<<"时间片为"<<a<<"\n";
int n=this->read("yuanrr.txt");
for(int i=1;i<=n;++i){
    process[i].st1=process[i].st;
    process[i].bt=1000;
    process[i].rr=0;
}
int t=a;//t为时间片
queue <int> q;
process[1].rr=1;
int name=1;
int time=process[1].at;
int num=0;
while(num!=n){
int pd=0;//用来判断的
    for(int i=1;i<=n;++i){
        if(process[i].sc==0){
            if(process[i].at<=time){
                if(process[i].rr==0){
                    q.push(i);
                    process[i].rr=1;
                }

            }
        }

    }

if(process[name].sc==0){
        q.push(name);
    }

if(q.empty()){
    time++;
}else{
    name=q.front();
    q.pop();
    if(process[name].st1<=t){

        if(process[name].bt==1000){
            process[name].bt=time;
        }


        process[name].ct=time+process[name].st1;
        process[name].sc=1;
        time=process[name].ct;
        process[name].st1=0;
        num++;
    }else{

    if(process[name].bt==1000){
        process[name].bt=time;
    }
    process[name].st1=process[name].st1-t;
    time=time+t;

    }
}



}
this->print_process_information(n);
this->write("mudirr.txt",n);
}
