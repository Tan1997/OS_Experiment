#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
	if(argc!=3){
		printf("您输入的参数个数有误！\n");
		return 0;
	}
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	if(a>b){
		printf("%d and %d . %d is max.\n",a,b,a);
	}
	else{
		if(a<b){
			printf("%d and %d . %d is max.\n",a,b,b);
		}
		else{
			printf("%d and %d is equal!.\n",a,b);
		}
	}
	return 0;
}
