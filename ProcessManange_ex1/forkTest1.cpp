/**
 *
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-05-15 18:37:23
 * @description: 	father -> son -> grandson
 */

#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;
int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();
	if (pid < 0)
	{
		cout << "creat son process error!" << endl;
		exit(-1);
	}
	else if ( pid == 0)
	{
		pid_t pid2 = fork();
		if (pid2 == 0)
		{
			cout << "I am the grandson process, my ID is: " << getpid() << endl;
		}
		else if (pid2 < 0)
		{
			cout << "creat grandson process error!" << endl;
			exit(-1);
		}
		else
		{
			cout << "I am the son process, my ID is: " << getpid() << ", and my son process (grandson process) ID is:"<<pid2<<endl;
		}
	}
	else
	{
		cout << "I am the father process, my ID is: " << getpid() << ", and my son process ID is:" << pid << endl;;
	}
	return 0;
}
