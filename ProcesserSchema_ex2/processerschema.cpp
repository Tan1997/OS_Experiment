#include<iostream>
#include "process.h"
using namespace std;

int main(int argc, char *argv[])
{
	process p1(1,5,0,"p1");
	while(!p1.isFinished())
	{
		p1.run();
		p1.disp();
	}
	cout<<"test"<<endl;
	return 0;
}
