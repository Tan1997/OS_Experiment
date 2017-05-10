#include <stdio.h>
#include <unistd.h>
int main()
{
	if(fork()==0){
		printf("This is the son process.\n");
		printf("The process ID is %d.\n",getpid());
		if(fork()==0){
			printf("This is grandson process.\n");
			printf("The process ID is %d.\n",getpid());
		}
	}
	else{
		printf("This is father Process.\n");
		printf("The process ID is %d.\n",getpid());
	}
	return 0;
}
