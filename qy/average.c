#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
	if(argc!=4){
		printf("您输入的参数个数有误！\n");
		return 0;
	}
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int c=atoi(argv[3]);
	int num;
	num=(a+b+c)/3;
	printf("%d , %d and %d average is %d .\n",a,b,c,num);
	return 0;
}
