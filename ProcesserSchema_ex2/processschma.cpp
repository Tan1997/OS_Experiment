/**
 * 
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-06-04 14:58:47
 * @description: 	
 */
#include "processschma.h"
#include <fstream>
#include <iostream>
using namespace std;
processSchma::processSchma()
{}
processSchma::processSchma(string fileName)
{
	readFromFile(fileName);
}
void processSchma::readFromFile(string fileName)//从文件读取进程调度实例
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
void processSchma::disp()//打印所有进程信息
{
	cout<<"-----------------------------------------"<<endl
		<<"Name  ID  createTime  serviceTime"<<endl
		<<"-----------------------------------------"<<endl;
	for(vector<process>::iterator iter = processVec.begin(); iter != processVec.end(); ++iter)
	{
		iter->disp();
	}
	cout<<"-----------------------------------------"<<endl;
}
void processSchma::dispResult()//打印所有进程结果信息
{
    cout<<"------------------------------------------------------------------"<<endl
        <<"Name  ID  finishTime  turnaroundTime  weightedTurnaroundTime"<<endl
        <<"------------------------------------------------------------------"<<endl;
    for(vector<process>::iterator iter = processVec.begin(); iter != processVec.end(); ++iter)
    {
        iter->dispResult();
    }
    cout<<"------------------------------------------------------------------"<<endl;
}
