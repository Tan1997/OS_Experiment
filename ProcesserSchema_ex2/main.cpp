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
//检查是否有进程到来，进程采用queue存储
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
//重载checkComeProcess函数，区别是进程采用vector存储
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
//先来先服务算法的调度实现
void FCFS(processSchma& schema)
{
	int time = 0;
	queue<process*> comeonProcess;
	int processNum = schema.processVec.size();
	checkComeProcess(comeonProcess, schema, time);
	while (processNum)//进程还未执行完便继续
	{
		if (comeonProcess.empty())//执行队列为空
		{
			time ++;
			checkComeProcess(comeonProcess, schema, time);
			continue;
		}
		comeonProcess.front()->run();//执行队首程序
		time ++;
		checkComeProcess(comeonProcess, schema, time);
		if (comeonProcess.front()->isFinished())//队首程序执行完毕
		{
			comeonProcess.front()->finishTime = time;
			comeonProcess.pop();
			processNum --;
		}
	}
}
//时间片轮转法调度算法实现，时间片为1
void RR(processSchma& schema)
{
	int time = 0;
	int processNum = schema.processVec.size();
	queue<process*> comeonProcess;
	checkComeProcess(comeonProcess, schema, time);
	while (processNum)//进程还未执行完便继续
	{
		if (comeonProcess.empty())//执行队列为空
		{
			time ++;
			checkComeProcess(comeonProcess, schema, time);
			continue;
		}
		auto tmp = comeonProcess.front();//执行队首程序
		comeonProcess.pop();
		tmp->run();
		time++;
		checkComeProcess(comeonProcess, schema, time);
		if (tmp->isFinished())//队首程序执行完毕
		{
			tmp->finishTime = time;
			processNum --;
		}
		else//将未执行完的队首程序置于队尾
			comeonProcess.push(tmp);
	}
}
//短进程优先调度算法实现
void SJF(processSchma& schema)
{
	int time = 0;
	vector<process*> comeonProcess;
	int processNum = schema.processVec.size();
	checkComeProcess(comeonProcess, schema, time);
	while (processNum)//进程还未执行完便继续
	{
		if (comeonProcess.empty())//执行队列为空
		{
			checkComeProcess(comeonProcess, schema, ++time);
			continue;
		}
		auto tmp = comeonProcess.begin();
		//寻找服务时间最短的进程
		for (auto index = tmp; index != comeonProcess.end(); index++)
		{
			if ((*index)->serviceTime < (*tmp)->serviceTime)
				tmp = index;
		}
		auto tmpProcess = *tmp;
		comeonProcess.erase(tmp);
		while (!tmpProcess->isFinished() )//直到该进程执行完毕
		{
			tmpProcess->run();
			checkComeProcess(comeonProcess, schema, ++time);
		}
		processNum--;
		tmpProcess->finishTime = time;
	}
}
//高响应比优先调度算法的实现
void HRN(processSchma& schema)
{
	int time = 0;
	vector<process*> comeonProcess;
	int processNum = schema.processVec.size();
	checkComeProcess(comeonProcess, schema, time);
	while (processNum)//进程还未执行完便继续
	{
		if (comeonProcess.empty())//执行队列为空
		{
			checkComeProcess(comeonProcess, schema, ++time);
			continue;
		}
		auto tmp = comeonProcess.begin();
		// 寻找优先级最高的进程
		for (auto index = tmp; index != comeonProcess.end(); index++)
		{
			if ( ((time - (*index)->comeTime) / (double)(*index)->serviceTime ) > ((time - (*tmp)->comeTime) / (double)(*tmp)->serviceTime ) )		//compare waittingtime/servicetime
				tmp = index;
		}
		auto tmpProcess = *tmp;
		comeonProcess.erase(tmp);
		while (!tmpProcess->isFinished() )//直到该进程执行完毕
		{
			tmpProcess->run();
			checkComeProcess(comeonProcess, schema, ++time);
		}
		processNum--;
		tmpProcess->finishTime = time;
	}
}
// 主函数
int main(int argc, const char *argv[])
{
	if (argc != 3)//输入格式不对，并提醒
	{
		cout << "please use the format: ProcesserSchema_ex2 [process list file] [schema algorithm]" << endl;
		return -1;
	}
	processSchma pS(argv[1]);
	cout << "the given process list is:" << endl;
	pS.disp();
	map<string, function<void(processSchma&)> > myEval;//建立字符串到函数的映射
	myEval["FCFS"] = FCFS;
	myEval["RR"] = RR;
	myEval["SJF"] = SJF;
	myEval["HRN"] = HRN;
	string comand(argv[2]);
	myEval[comand](pS);
	cout << "\n\n\nwork over, and the result is:" << endl;
	pS.dispResult();//打印结果
	return 0;
}

