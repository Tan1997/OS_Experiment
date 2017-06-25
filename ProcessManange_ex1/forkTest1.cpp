/**
 *
 * @author:   胡文博
 * @email:    huwenbo@mail.dlut.edu.cn
 * @dateTime:   2017-05-15 18:37:23
 * @description:  father -> son -> grandson
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
        cout << "creat son process error!" << endl;
        exit(-1);
    }
    else if ( pid == 0)//pid为0代表该进程为子进程
    {
        pid_t pid2 = fork();//子进程创建孙子进程
        if (pid2 == 0)//pid2为0代表该进程为孙子进程
        {
            cout << "I am the grandson process, my ID is: " << getpid() << endl;
        }
        else if (pid2 < 0)//创建失败
        {
            cout << "creat grandson process error!" << endl;
            exit(-1);
        }
        else//pid2不为0代表该进程为孙子进程的父进程，即子进程
        {
            cout << "I am the son process, my ID is: " << getpid() << ", and my son process (grandson process) ID is:" << pid2 << endl;
        }
    }
    else//pid不为0代表该进程为父进程
    {
        cout << "I am the father process, my ID is: " << getpid() << ", and my son process ID is:" << pid << endl;;
    }
    return 0;
}
