#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define N 10
int main()
{
	char num1[N];
	char num2[N];
	char num3[N];
	char command[N];
	int flag=0;
	printf("please input your operation:(max,min,average)\n");
	scanf("%s",command);
	if(strcmp(command,"max")==0){
		printf("please input 2 arguments:\n");
		scanf("%s",num1);
		scanf("%s",num2);
		flag=1;
	}
	if(strcmp(command,"min")==0){
		printf("please input 2 arguments:\n");
		scanf("%s",num1);
		scanf("%s",num2);
		flag=2;
	}
	if(strcmp(command,"average")==0){
		printf("please input 3 arguments:\n");
		scanf("%s",num1);
		scanf("%s",num2);
		scanf("%s",num3);
		flag=3;
	}
	if(fork()==0){
		switch(flag){
//文件路径，命令名，参数，结束标志，参数列表
		case 1:execl("/home/robot/操作系统试验/max","./max",num1,num2,NULL);
			break;
		case 2:execl("/home/robot/操作系统试验/min","./min",num1,num2,NULL);
			break;
		case 3:execl("/home/robot/操作系统试验/average","./average",num1,num2,num3,NULL);
			break;

		default:printf("请输入正确的操作.\n");
			break;
		}
	}
	return 0;
}
