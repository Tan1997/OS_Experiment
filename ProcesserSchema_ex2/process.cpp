#include "process.h"
#include<iostream>
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
	cout << "\t" << this->name << "\t" << this->ID << "\t" << this->comeTime << "\t\t" << this->serviceTime << endl;
	// <<"\t"<<this->workTime<<"\t"<< this->finishTime<< endl;
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
