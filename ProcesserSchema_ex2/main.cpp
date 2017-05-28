#include<iostream>
#include "process.h"
#include"processschma.h"
#include<queue>
#include <boost/circular_buffer.hpp>
using namespace std;

void FCFS(processSchma& schema)
{
	int time = 0;
	queue<process*> comeonProcess;
	int processNum = schema.processVec.size();
	while(processNum)
	{
		for(vector<process>::iterator iter = schema.processVec.begin(); iter != schema.processVec.end(); iter++)
		{
			if( iter->comeTime == time )
			{
				comeonProcess.push(&(*iter));
			}
		}
		if(!comeonProcess.empty())
		{
			comeonProcess.front()->run();
//			comeonProcess.front()->disp();
			if(comeonProcess.front()->isFinished())
			{
				comeonProcess.front()->finishTime = time;
				comeonProcess.pop();
				processNum --;
			}
		}
		time++;
	}
}

void RR(processSchma& schema)
{
	int time = 0;
	int processNum = schema.processVec.size();
	boost::circular_buffer<process*> comeonProcess(processNum);
	while(processNum)
	{
		for(vector<process>::iterator iter = schema.processVec.begin(); iter != schema.processVec.end(); iter++)
		{
			if( iter->comeTime == time )
			{
				comeonProcess.
			}
		}
		if(!comeonProcess.empty())
		{
			comeonProcess.front()->run();
//			comeonProcess.front()->disp();
			if(comeonProcess.front()->isFinished())
			{
				comeonProcess.front()->finishTime = time;
				comeonProcess.pop();
				processNum --;
			}
		}
		time++;
	}
}

int main(int argc, char *argv[])
{
	processSchma pS("../processList.txt");	
	pS.disp();
	cout<<"test"<<endl;
	FCFS(pS);
	pS.disp();
	return 0;
}

