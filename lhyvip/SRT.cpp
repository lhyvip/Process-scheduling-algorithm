#include"AL.h"
#include<stdio.h>
void AL::SRT(){
int i,j;
int n=this->read("yuanfile.txt");
//���Ӹ����̵���Ϣ
for(i=1;i<=n;i++){
process[i].st1=process[i].st;
process[i].bt=1000;
}

cout<<"\n���еĽ��̺� ����ʱ��  ����ʱ�� ��ʼʱ��   ����ʱ��   ��תʱ��    ��Ȩ��תʱ�� \n";
int sum=0;
int h=n+2;
int atime[h];//�洢���н��̵ĵ���ʱ�� ��С����
int c=2;

for(i=1;i<=n;i++){
atime[i]=process[i].at;
}
int time=atime[1];//��¼��ǰʱ��
while(sum!=n){
for(i=1;i<n;i++){//���򣬰�����ʱ����������
for(j=1;j<n;j++){
if(process[j].at>process[j+1].at){
process[0]=process[j];
process[j]=process[j+1];
process[j+1]=process[0];

    }
}
}


for(i=1;i<n;i++){//�������ִ��ʱ������
    for(j=1;j<n;j++){
        if(process[j].st1>process[j+1].st1){
            process[0]=process[j];
            process[j]=process[j+1];
            process[j+1]=process[0];
        }
    }

}

int pd=0;//�����ж�
for( i=1;i<=n;i++){
    if(process[i].sc!=1){
        if(process[i].at<=time){

            if(process[i].bt==1000){
                    process[i].bt=time;
                }
        if(c!=6){

            if(process[i].st1<=(atime[c]-time)){//��ִ��ʱ��С
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

for(i=1;i<n;i++){//���򣬰�����ʱ����������
    for(j=1;j<n;j++){
    if(process[j].at>process[j+1].at){
	     	 process[0]=process[j];
			 process[j]=process[j+1];
	     	process[j+1]=process[0];

		 }
		}
	}




for(i=1;i<=n;i++){//��ӡ�����̵���Ϣ
int zhou=process[i].ct-process[i].at;
double daiquan=(zhou*1.0)/(process[i].st*1.0);
		cout<<process[i].pn<<"            "<<process[i].at<<"          "<<process[i].st<<"        ";
		cout<<process[i].bt<<"         "<<process[i].ct<<"           "<<zhou<<"           "<<daiquan<<endl;

	}


}
