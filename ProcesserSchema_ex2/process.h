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
	int ID;
	int workTime = 0;
public:
	int serviceTime, comeTime,finishTime;
	string name;
	process();
	process(int ID, int serviceTime, int comeTime, string name);
	void run();
	bool isFinished();
	void disp();
    void dispResult();
    int getTurnaroundTime();
    double getWeightedTurnaroundTime();
};

#endif // PROCESS_H
