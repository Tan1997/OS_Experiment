#ifndef PROCESS_H
#define PROCESS_H
#include<string>
using namespace std;
class process
{
	int ID;
	int workTime = 0;
public:
	int serviceTime, comeTime;
	string name;
	process();
	process(int ID, int serviceTime, int comeTime, string name);
	void run();
	bool isFinished();
	void disp();
};

#endif // PROCESS_H
