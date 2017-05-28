#include "processschma.h"
#include<fstream>
#include<iostream>
using namespace std;
processSchma::processSchma()
{
	
}
processSchma::processSchma(string fileName)
{
	readFromFile(fileName);
}

void processSchma::readFromFile(string fileName)
{
	fstream f;
	f.open(fileName);
	string s;
	getline(f,s);
	int ID = 1;
	while(f>>s)
	{
		string name = s;
		f>>s;
		int comeTime = atoi(s.data());
		f>>s;
		int serviceTime = atoi(s.data());
		process indexP(ID++,serviceTime,comeTime,name);
		this->processVec.push_back(indexP);
	}
}

void processSchma::disp()
{
	for(vector<process>::iterator iter = processVec.begin(); iter != processVec.end(); ++iter)
	{
		iter->disp();
	}
}
