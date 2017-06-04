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


void process::disp()
{
	cout << "" << this->name << "     " << this->ID << "      " << this->comeTime << "           " << this->serviceTime << endl;
	// <<"\t"<<this->workTime<<"\t"<< this->finishTime<< endl;
}
void process::dispResult()
{
    cout << "" << this->name << "     " << this->ID << "      " << this->finishTime << "\t\t\t\b\b\b\b" << this->getTurnaroundTime() <<"\t\t\t"<< this->getWeightedTurnaroundTime()<<endl;
}

void process::run()
{
	workTime++;
}

bool process::isFinished()
{
	if (workTime >= serviceTime)
	{
		return true;
	}
	return false;
}

int process::getTurnaroundTime()
{
    return finishTime-comeTime;
}
double process::getWeightedTurnaroundTime()
{
    return (double)getTurnaroundTime()/serviceTime;
}
