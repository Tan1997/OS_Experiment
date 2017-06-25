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
#include <vector>
#include <string>
using namespace std;

class processSchma
{
	void readFromFile(string fileName);//从文件读取进程调度实例
public:
	vector<process> processVec;//存储进程
	processSchma();
	processSchma(string fileName);
	void disp();//打印所有进程信息
    void dispResult();//打印所有进程结果信息
};
#endif // PROCESSSCHMA_H
