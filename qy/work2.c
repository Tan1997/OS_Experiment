#include <stdio.h>
#include <unistd.h>
int main()
{
	if(fork()==0){
		printf("This is son1 process.\n");
		printf("The process ID is %d.\n",getpid());
	}
	else{
		if(fork()==0){
			printf("This is son2 process.\n");
			printf("The process ID is %d.\n",getpid());
		}
		else{
			printf("This is father process.\n");
			printf("The process ID is %d.\n",getpid());
		}
	}
	return 0;
}
