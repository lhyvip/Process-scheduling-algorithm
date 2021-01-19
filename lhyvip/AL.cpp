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
//��ӡ�˵�
void AL::print_choose(){
cout<<"\n\n\t\t-----���̵����㷨�˵�-------\n";
cout<<"1. FCFS  :�����ȷ���\n";
cout<<"2. SJF   :����ҵ���ȵ����㷨\n";
cout<<"3. HRRN  :����Ӧ���㷨\n";
cout<<"4. SRT   :���ʣ��ʱ������㷨\n";
cout<<"5. RR    :ʱ��Ƭ��ת�����㷨\n";
cout<<"6. EDF   :�����ֹʱ�������㷨\n";
cout<<"7. LLF   :����ɳڶ��㷨\n";
cout<<"8. banker:���м��㷨\n";
cout<<"9. EXIT  :�˳�����\n";
cout<<"please input:";
    }

//�˵�ѡ��
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


//��txt�ж�ȡ���ݷ�������
int  AL::read(char a[]){
int num=0;//��¼������
ifstream file1(a);
if(!file1){
    cout<<"��ʧ��\n";

}else{
//��ȡ��һ�е�����
string processname;
string processarriver;
string processservice;
file1>>processname;
file1>>processarriver;
file1>>processservice;
//��ȡ��Ϣ
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
file2<<"���еĽ��̺� ����ʱ��  ����ʱ�� ��ʼʱ��   ����ʱ��   ��תʱ��    ��Ȩ��תʱ�� \n";
for(int i=1;i<=n;i++){//��ӡ�����̵���Ϣ
int zhou=process[i].ct-process[i].at;
double daiquan=(zhou*1.0)/(process[i].st*1.0);
    file2<<process[i].pn<<"            "<<process[i].at<<"          "<<process[i].st<<"        ";
    file2<<process[i].bt<<"         "<<process[i].ct<<"           "<<zhou<<"           "<<daiquan<<endl;

	}



file2.close();

}


void AL::print_process_information(int n){
sort(&process[1],&process[1]+n,cmp3);
//��ӡ��Ϣ
cout<<"\n���еĽ��̺� ����ʱ��  ����ʱ�� ��ʼʱ��   ����ʱ��   ��תʱ��    ��Ȩ��תʱ�� \n";
for(int i=1;i<=n;i++){//��ӡ�����̵���Ϣ
int zhou=process[i].ct-process[i].at;
double daiquan=(zhou*1.0)/(process[i].st*1.0);
		cout<<process[i].pn<<"            "<<process[i].at<<"          "<<process[i].st<<"        ";
		cout<<process[i].bt<<"         "<<process[i].ct<<"           "<<zhou<<"           "<<daiquan<<endl;

	}



}

