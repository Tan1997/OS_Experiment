/**
 *
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-05-15 18:37:23
 * @description: 	father  	->   son1
 			            	->   son2
 */

#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;
int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();//创建子进程，并将返回值存入变量pid
	if (pid < 0)//创建失败
	{
		cout << "creat son1 process error!" << endl;
		exit(-1);
	}
	else if ( pid == 0)//pid为0代表该进程为子进程
	{
		cout << "I am the son1 process, my ID is: " << getpid() << endl;
	}
	else//pid不为0代表该进程为父进程
	{
		pid_t pid2 = fork();//父进程创建第二个子进程
		if (pid2 < 0)
		{
			cout << "creat son2 process error!" << endl;
			exit(-1);
		}
		else if (pid2 == 0)
		{
			cout << "I am the son2 process, my ID is: " << getpid() << endl;
		}
		else
		{
				cout << "I am the father process, my ID is: " << getpid() << ", my first son ID is:"<<pid<<", and my second son process ID is:"<<pid2<<endl;
		}
	}
	return 0;
}
