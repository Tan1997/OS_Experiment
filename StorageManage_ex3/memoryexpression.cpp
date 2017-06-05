#include "memoryexpression.h"

using namespace std;


memoryExpression::memoryExpression( string fileName )
{
	fstream f;
	f.open(fileName);
	string s;
	f>>s;
	f>>s;
	f>>s;
	f >> this->blockNum;
	f>>s,f>>s,f>>s;
	int tmp = 0;
	int maxPage = 0;
	while (f >> tmp)
	{
		this->pageAccessOrder.push_back(tmp);
		if(tmp>maxPage)
			maxPage = tmp;
	}
	for(int i = 0; i<maxPage; i++)
	{
		this->pageList.push_back(false);
	}
}

void memoryExpression::dispPageAccessOrder()
{
	for (auto index = this->pageAccessOrder.begin(); index != pageAccessOrder.end(); index++)
	{
		cout << *index << endl;
	}
}

void memoryExpression::disppageList()
{
	for (auto index = pageList.begin(); index != pageList.end(); index++)
	{
		cout << *index << endl;
	}
}
