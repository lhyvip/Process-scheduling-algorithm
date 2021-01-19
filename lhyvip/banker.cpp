#include"AL.h"
#include<iostream>
#include<stdio.h>
using namespace std;
#define resourceNum 3
#define processNum  5
//系统可用（剩余）资源
int available[resourceNum]={3,3,2};
//进程的最大需求
int maxRequest[processNum][resourceNum]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
//进程已经占有（分配）资源
int allocation[processNum][resourceNum]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
//进程还需要资源
int need[processNum][resourceNum]={{7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1}};
//是否安全
bool Finish[processNum];
//安全序列号
int safeSeries[processNum]={0,0,0,0,0};
//进程请求资源量
int request[resourceNum];
//资源数量计数
int num;

//打印输出系统信息
void showInfo()
{
	cout<<"\n------------------------------------------------------------------------------------\n";
	cout<<"当前系统各类资源剩余：";
    for(int j = 0; j < resourceNum; j++)
	{
        cout<<available[j]<<" ";
    }
    cout<<"\n\n当前系统资源情况：\n";
    cout<<" PID\t Max\t\t\tAllocation\t\t Need\n";
    for(int i = 0; i < processNum; i++)
	{
        cout<<" P"<<i<<"\t";
        for(int j = 0; j < resourceNum; j++)
		{
            cout<<"  "<<maxRequest[i][j];
        }
        cout<<"\t\t";
        for(int j = 0; j < resourceNum; j++)
		{
            cout<<"  "<<allocation[i][j];
        }
        cout<<"\t\t";
        for(int j = 0; j < resourceNum; j++)
		{
            cout<<"  "<<need[i][j];
        }
        cout<<"\n";
    }
}


//判断一个进程的资源是否全为零
bool isAllZero(int kang)
{
	num = 0;
	for(int i = 0; i < resourceNum; i++ )
	{
		if(need[kang][i] == 0)
		{
			num ++;
		}
	}
	if(num == resourceNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}



//打印安全检查信息
void SafeInfo(int *work, int i)
{
    int j;
    cout<<" P"<<i<<"\t";
    for(j = 0; j < resourceNum; j++)
	{
        cout<<"  "<<work[j];
    }
    cout<<"\t\t";
    for(j = 0; j < resourceNum; j++)
	{
        cout<<"  "<<allocation[i][j];
    }
	cout<<"\t\t";
    for(j = 0; j < resourceNum; j++)
	{
        cout<<"  "<<need[i][j];
    }
    cout<<"\t\t";
    for(j = 0; j < resourceNum; j++)
	{
        cout<<"  "<<allocation[i][j]+work[j];
    }
    cout<<"\n";
}

//安全检查
bool isSafe()
{
	//int resourceNumFinish = 0;
	int safeIndex = 0;
	int allFinish = 0;
    int work[resourceNum] = {0};
	int r = 0;
	int temp = 0;
	int pNum = 0;
	//预分配为了保护available[]
    for(int i = 0; i < resourceNum; i++)
	{
        work[i] = available[i];
    }
	//把未完成进程置为false
    for(int i = 0; i < processNum; i++)
	{
		bool result = isAllZero(i);
		if(result == true)
		{
			Finish[i] = true;
			allFinish++;
		}
		else
		{
			Finish[i] = false;
		}

    }
	//预分配开始
    while(allFinish != processNum)
	{
		num = 0;
        for(int i = 0; i < resourceNum; i++)
		{
			if(need[r][i] <= work[i] && Finish[r] == false)
			{
				num ++;
			}
		}
		if(num == resourceNum)
		{
			for(int i = 0; i < resourceNum; i++ )
			{
				work[i] = work[i] + allocation[r][i];
			}
			allFinish ++;
			SafeInfo(work,r);
			safeSeries[safeIndex] = r;
			safeIndex ++;
			Finish[r] = true;
		}
		r ++;//该式必须在此处
		if(r >= processNum)
		{
			r = r % processNum;
			if(temp == allFinish)
			{
				break;
			}
			temp = allFinish;
		}
		pNum = allFinish;
    }
	//判断系统是否安全
	for(int i = 0; i < processNum; i++)
	{
		if(Finish[i] == false)
		{
			cout<<"\n当前系统不安全！\n\n";
			return false;
		}
	}
	//打印安全序列
	cout<<"\n当前系统安全！\n\n安全序列为：";
	for(int i = 0; i < processNum; i++)
	{
		bool result = isAllZero(i);
		if(result == true)
		{
			pNum --;
		}
    }
	for(int i = 0; i < pNum; i++)
	{
		cout<<"  "<<safeSeries[i];
	}
    return true;
}



void AL::banker(){
int curProcess = 0;
	int a = -1;
       showInfo();
	cout<<"\n系统安全情况分析\n";
	cout<<" PID\t Work\t\t\tAllocation\t\t Need\t\tWork+Allocation\n";
	bool isStart = isSafe();
	//用户输入或者预设系统资源分配合理才能继续进行进程分配工作
    while(isStart)
	{
		//限制用户输入，以防用户输入大于进程数量的数字，以及输入其他字符（乱输是不允许的）
      	do
		{
			if(curProcess >= processNum || a == 0)
			{
				cout<<"\n请不要输入超出进程数量的值或者其他字符：\n";
				while(getchar() != '\n'){};//清空缓冲区
				a = -1;
			}
			cout<<"\n------------------------------------------------------------------------------------\n";
			cout<<"\n输入要分配的进程：";
			a = scanf("%d",&curProcess);
			printf("\n");

		}while(curProcess >= processNum || a == 0);

		//限制用户输入，此处只接受数字，以防用户输入其他字符（乱输是不允许的）
		for(int i = 0; i < resourceNum; i++)
		{
			do
			{
				if(a == 0)
				{
					cout<<"\n请不要输入除数字以外的其他字符，请重新输入：\n";
					while(getchar() != '\n'){};//清空缓冲区
					a = -1;
				}
				cout<<"请输入要分配给进程 "<<curProcess<<"的第 "<<i+1<<" 类资源：";

				a = scanf("%d", &request[i]);
			}while( a == 0);
		}

		//判断用户输入的分配是否合理，如果合理，开始进行预分配
		num  = 0;
        for(int i = 0; i < resourceNum; i++)
		{
            if(request[i] <= need[curProcess][i] && request[i] <= available[i])
			{
				num ++;
			}
            else
			{
				printf("\n发生错误！可能原因如下：\n(1)您请求分配的资源可能大于该进程的某些资源的最大需要！\n(2)系统所剩的资源已经不足了！\n");
				break;
			}
        }
        if(num == resourceNum)
		{
			num = 0;
            for(int j = 0; j < resourceNum; j++)
			{
				//分配资源
                available[j] = available[j] - request[j];
                allocation[curProcess][j] = allocation[curProcess][j] + request[j];
                need[curProcess][j] = need[curProcess][j] - request[j];
				//记录分配以后，是否该进程需要值为0了
				if(need[curProcess][j] == 0)
				{
					num ++;
				}
            }
			//如果分配以后出现该进程对所有资源的需求为0了，即刻释放该进程占用资源（视为完成）
			if(num == resourceNum)
			{
				//释放已完成资源
				for(int i = 0; i < resourceNum; i++ )
				{
					available[i] = available[i] + allocation[curProcess][i];
				}
				printf("\n\n本次分配进程 P%d 完成,该进程占用资源全部释放完毕！\n",curProcess);
			}
			else
			{
				//资源分配可以不用一次性满足进程需求
				printf("\n\n本次分配进程 P%d 未完成！\n",curProcess);
			}

			showInfo();
           	printf("\n系统安全情况分析\n");
			printf(" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation\n");

			//预分配完成以后，判断该系统是否安全，若安全，则可继续进行分配，若不安全，将已经分配的资源换回来
            if(!isSafe())
			{
				for(int j = 0; j < resourceNum; j++)
				{
					available[j] = available[j] + request[j];
					allocation[curProcess][j] = allocation[curProcess][j] - request[j];
					need[curProcess][j] = need[curProcess][j] +request[j];
				}
				printf("资源不足，等待中...\n\n分配失败！\n");
            }
        }
    }
}



