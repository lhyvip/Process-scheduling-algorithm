#include"AL.h"
#include<stdio.h>
void AL::SRT(){
int i,j;
int n=this->read("yuanfile.txt");
//补从各进程的信息
for(i=1;i<=n;i++){
process[i].st1=process[i].st;
process[i].bt=1000;
}

cout<<"\n运行的进程号 到达时间  服务时间 开始时间   结束时间   周转时间    带权周转时间 \n";
int sum=0;
int h=n+2;
int atime[h];//存储所有进程的到达时间 由小到大
int c=2;

for(i=1;i<=n;i++){
atime[i]=process[i].at;
}
int time=atime[1];//记录当前时间
while(sum!=n){
for(i=1;i<n;i++){//排序，按到达时间升序排序
for(j=1;j<n;j++){
if(process[j].at>process[j+1].at){
process[0]=process[j];
process[j]=process[j+1];
process[j+1]=process[0];

    }
}
}


for(i=1;i<n;i++){//按照最短执行时间排序
    for(j=1;j<n;j++){
        if(process[j].st1>process[j+1].st1){
            process[0]=process[j];
            process[j]=process[j+1];
            process[j+1]=process[0];
        }
    }

}

int pd=0;//用于判断
for( i=1;i<=n;i++){
    if(process[i].sc!=1){
        if(process[i].at<=time){

            if(process[i].bt==1000){
                    process[i].bt=time;
                }
        if(c!=6){

            if(process[i].st1<=(atime[c]-time)){//待执行时间小
                process[i].sc=1;
                process[i].ct=time+process[i].st1;
                process[i].st1=0;
                time=process[i].ct;
                sum++;
                pd=1;
                break;
                }else{
                process[i].st1=process[i].st1-(atime[c]-time);
                time=atime[c];
                pd=1;
                c++;
                break;
                }

				}else{
				   	process[i].sc=1;
				   	process[i].ct=time+process[i].st1;
				   	process[i].st1=0;
				   	time=process[i].ct;
				   	sum++;
				     pd=1;
				     break;
				   }

			  }

		  }

	  	  }
	  	  if(pd==0){
	  	  	time=atime[c];
			c++;

			}
		   pd==0;


	}

for(i=1;i<n;i++){//排序，按到达时间升序排序
    for(j=1;j<n;j++){
    if(process[j].at>process[j+1].at){
	     	 process[0]=process[j];
			 process[j]=process[j+1];
	     	process[j+1]=process[0];

		 }
		}
	}




for(i=1;i<=n;i++){//打印各进程的信息
int zhou=process[i].ct-process[i].at;
double daiquan=(zhou*1.0)/(process[i].st*1.0);
		cout<<process[i].pn<<"            "<<process[i].at<<"          "<<process[i].st<<"        ";
		cout<<process[i].bt<<"         "<<process[i].ct<<"           "<<zhou<<"           "<<daiquan<<endl;

	}


}
