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
class memoryExpression//内存表示类
{
public:
	vector<bool> pageList;//页表，bool值表示该页是否在内存中
	vector<int> pageAccessOrder;//页面访问序列
	int blockNum = 0 ;//系统为进程分配的内存块数，可由配置文件更改
	memoryExpression(string fileName);
	void dispPageAccessOrder();//打印页面访问序列
	void disppageList();//打印页表
};
#endif // MEMORYEXPRESSION_H
