#ifndef PROCESSSCHMA_H
#define PROCESSSCHMA_H
#include"process.h"
#include<vector>
#include<string>

using namespace std;
class processSchma
{
	void readFromFile(string fileName);
public:
	vector<process> processVec;
	processSchma();
	processSchma(string fileName);
	void disp();
};

#endif // PROCESSSCHMA_H
