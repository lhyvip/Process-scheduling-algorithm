#include"AL.h"
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp4(PCB a,PCB b){
return a.at<b.at;
}

void AL::SJF(){
int n=this->read("yuansjf.txt");
//排序，按到达时间升序排序
sort(&process[1],&process[1]+n,cmp4);
	int time =process[1].at;//当前时刻
	int sum=0;
	process[1].ct=time+process[1].st;
	process[1].sc=1;
	process[1].st1=0;
	process[1].bt=time;
	time=process[1].ct;
	sum+=1;
	while(sum!=n){
	int tmp=100000;//记录服务时间
	int t=0; //记录进程名字
		for(int i=2;i<=n;i++){
			if(process[i].sc!=1){
				if(process[i].at<=time){
					if(process[i].st<tmp){
					tmp=process[i].st;
					t=i;
					}
				}

			}

		}
		if(t!=0){
	    process[t].ct=time+process[t].st;
		time=process[t].ct;
		process[t].sc=1;
		process[t].st1=0;
		process[t].bt=time-process[t].st;
		sum++;
		}else{
		for(int i=2;i<=n;i++){
			if(process[i].sc!=1){
			time=process[i].at;
			process[i].ct=time+process[i].st;
			time=process[i].ct;
			process[i].sc=1;
			process[i].st1=0;
		    process[i].bt=time-process[i].st;
		    sum++;
	    }
		}
		}



	}


this->print_process_information(n);
this->write("mudisjf.txt",n);




}
