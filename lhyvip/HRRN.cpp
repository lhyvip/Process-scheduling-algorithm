#include"AL.h"
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp2(PCB a,PCB b){
    return a.xyb>b.xyb;

}
void AL::HRRN(){
//从文件读取
int n=this->read("yuanhrrn.txt");
for(int i=1;i<=n;++i){
    process[i].bt=1000;
}
//算法

int time=process[1].at;
int num=0;
cout<<"n="<<n<<endl;
while(num!=n){
int t=0;
//计算相应比
for(int i=1;i<=n;i++){
    process[i].xyb=(time-process[i].at+process[i].st)*1.0/(process[i].st*1.0);
}
sort(&process[1],&process[1]+n,cmp2);

for(int i=1;i<=n;i++){
    if(process[i].sc==0){
        if(process[i].at<=time){
            if(process[i].bt==1000){
                process[i].bt=time;
            }
            process[i].ct=time+process[i].st;
            process[i].sc=1;
            num++;
            t=1;
            time=process[i].ct;
            break;
        }
    }

}

if(t==1){
}else{
time++;
}

}
this->print_process_information(n);
this->write("mudihrrn.txt",n);
}
