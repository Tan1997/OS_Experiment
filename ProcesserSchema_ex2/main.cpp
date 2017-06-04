/**
 *
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-06-03 21:18:17
 * @description:
 */
#include <iostream>
#include "process.h"
#include "processschma.h"
#include <queue>
#include <boost/circular_buffer.hpp>
#include <map>
using namespace std;

void checkComeProcess( queue<process*> &comeonProcess, processSchma& schema, int time )
{
	for (vector<process>::iterator iter = schema.processVec.begin(); iter != schema.processVec.end(); iter++)
	{
		if ( iter->comeTime == time )
		{
			comeonProcess.push(&(*iter));
		}
	}
}
void checkComeProcess( vector<process*> &comeonProcess, processSchma& schema, int time )
{
	for (vector<process>::iterator iter = schema.processVec.begin(); iter != schema.processVec.end(); iter++)
	{
		if ( iter->comeTime == time )
		{
			comeonProcess.push_back( &(*iter));
		}
	}
}

void FCFS(processSchma& schema)
{
	int time = 0;
	queue<process*> comeonProcess;
	int processNum = schema.processVec.size();
	checkComeProcess(comeonProcess, schema, time);
	while (processNum)
	{
		if (comeonProcess.empty())
		{
			time ++;
			checkComeProcess(comeonProcess, schema, time);
			continue;
		}
		comeonProcess.front()->run();
		// comeonProcess.front()->disp();
		time ++;
		checkComeProcess(comeonProcess, schema, time);
		if (comeonProcess.front()->isFinished())
		{
			comeonProcess.front()->finishTime = time;
			comeonProcess.pop();
			processNum --;
		}
	}
}

void RR(processSchma& schema)
{
	int time = 0;
	int processNum = schema.processVec.size();
	queue<process*> comeonProcess;
	checkComeProcess(comeonProcess, schema, time);
	while (processNum)
	{
		if (comeonProcess.empty())
		{
			time ++;
			checkComeProcess(comeonProcess, schema, time);
			continue;
		}
		auto tmp = comeonProcess.front();
		comeonProcess.pop();
		tmp->run();
		time++;
		checkComeProcess(comeonProcess, schema, time);
		if (tmp->isFinished())
		{
			tmp->finishTime = time;
			processNum --;
		}
		else
			comeonProcess.push(tmp);
	}
}

void SJF(processSchma& schema)
{
	int time = 0;
	vector<process*> comeonProcess;
	int processNum = schema.processVec.size();
	checkComeProcess(comeonProcess, schema, time);
	while (processNum)
	{
		if (comeonProcess.empty())
		{
			checkComeProcess(comeonProcess, schema, ++time);
			continue;
		}
		auto tmp = comeonProcess.begin();
		for (auto index = tmp; index != comeonProcess.end(); index++)
		{
			if ((*index)->serviceTime < (*tmp)->serviceTime)
				tmp = index;
		}
		auto tmpProcess = *tmp;
		comeonProcess.erase(tmp);
		while (!tmpProcess->isFinished() )
		{
			tmpProcess->run();
			checkComeProcess(comeonProcess, schema, ++time);
		}
		processNum--;
		tmpProcess->finishTime = time;
	}
}

void HRN(processSchma& schema)
{
	int time = 0;
	vector<process*> comeonProcess;
	int processNum = schema.processVec.size();
	checkComeProcess(comeonProcess, schema, time);
	while (processNum)
	{
		if (comeonProcess.empty())
		{
			checkComeProcess(comeonProcess, schema, ++time);
			continue;
		}
		auto tmp = comeonProcess.begin();
		for (auto index = tmp; index != comeonProcess.end(); index++)
		{
			if ( ((time - (*index)->comeTime) / (double)(*index)->serviceTime ) > ((time - (*tmp)->comeTime) / (double)(*tmp)->serviceTime ) )		//compare waittingtime/servicetime
				tmp = index;
		}
		auto tmpProcess = *tmp;
		comeonProcess.erase(tmp);
		while (!tmpProcess->isFinished() )
		{
			tmpProcess->run();
			checkComeProcess(comeonProcess, schema, ++time);
		}
		processNum--;
		tmpProcess->finishTime = time;
	}
}


int main(int argc, const char *argv[])
{
	if (argc != 3)
	{
		cout << "please use the format: ProcesserSchema_ex2 [process list file] [schema algorithm]" << endl;
		return -1;
	}
	processSchma pS(argv[1]);
	cout << "the given process list is:" << endl;
	pS.disp();
	map<string, function<void(processSchma&)> > myEval;
	myEval["FCFS"] = FCFS;
	myEval["RR"] = RR;
	myEval["SJF"] = SJF;
	myEval["HRN"] = HRN;
	string comand(argv[2]);
	myEval[comand](pS);
	cout << "\n\n\nwork over, and the result is:" << endl;
	pS.dispResult();
	return 0;
}

