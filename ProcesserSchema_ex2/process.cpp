/**
 * 
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-06-04 15:27:50
 * @description: 	
 */
#include "process.h"
#include <iostream>
using namespace std;
process::process()
{
	this->workTime = 0;
	this->name = "process";
}
process::process(int ID, int serviceTime, int comeTime, string name = "process")
{
	this->ID = ID;
	this->serviceTime = serviceTime;
	this->comeTime = comeTime;
	this->name = name;
	this->workTime = 0;
	this->finishTime = 0;
}
void process::disp()//打印进程信息
{
	cout << "" << this->name << "     " << this->ID << "      " << this->comeTime << "           " << this->serviceTime << endl;
}
void process::dispResult()
{
    cout << "" << this->name << "     " << this->ID << "      " << this->finishTime << "\t\t\t\b\b\b\b" << this->getTurnaroundTime() <<"\t\t\t"<< this->getWeightedTurnaroundTime()<<endl;
}
void process::run()//执行进程
{
	workTime++;
}
bool process::isFinished()//查询进程是否执行完毕
{
	if (workTime >= serviceTime)
	{
		return true;
	}
	return false;
}
int process::getTurnaroundTime()//计算周转时间
{
    return finishTime-comeTime;
}
double process::getWeightedTurnaroundTime()//计算带权周转时间
{
    return (double)getTurnaroundTime()/serviceTime;
}
