/**
 * 
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-06-05 21:24:09
 * @description: 	
 */
#ifndef MEMORYEXPRESSION_H
#define MEMORYEXPRESSION_H
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <fstream>

 using namespace std;

class memoryExpression
{

public:
	vector<bool> pageList;
	vector<int> pageAccessOrder;
	int blockNum = 0 ;
//	memoryExpression();
	memoryExpression(string fileName);
	void dispPageAccessOrder();
	void disppageList();
};

#endif // MEMORYEXPRESSION_H
