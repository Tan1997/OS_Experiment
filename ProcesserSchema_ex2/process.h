/**
 * 
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-06-04 15:28:14
 * @description: 	
 */
#ifndef PROCESS_H
#define PROCESS_H
#include<string>
using namespace std;
class process
{
	int ID;//进程ID号
	int workTime = 0;//已经执行的时间
public:
	int serviceTime,//进程需要的服务时间
		comeTime,//进程到来的时间
		finishTime;//进程执行结束的时间点
	string name;//进程名
	process();
	process(int ID, int serviceTime, int comeTime, string name);
	void run();//执行进程
	bool isFinished();//查询进程是否执行完毕
	void disp();//打印进程信息
    void dispResult();//打印执行结果
    int getTurnaroundTime();//计算周转时间
    double getWeightedTurnaroundTime();//计算带权周转时间
};

#endif // PROCESS_H
