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
	pid = fork();
	if (pid < 0)
	{
		cout << "creat son1 process error!" << endl;
		exit(-1);
	}
	else if ( pid == 0)
	{
		cout << "I am the son1 process, my ID is: " << getpid() << endl;
	}
	else
	{
		pid_t pid2 = fork();
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
