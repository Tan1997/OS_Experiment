/**
 * 
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-06-04 15:28:33
 * @description: 	
 */
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
    void dispResult();
};

#endif // PROCESSSCHMA_H
