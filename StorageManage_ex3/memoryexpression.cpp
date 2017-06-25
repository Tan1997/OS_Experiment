/**
 * 
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-06-05 21:24:01
 * @description: 	
 */
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
void memoryExpression::dispPageAccessOrder()//打印页面访问序列
{
	for (auto index = this->pageAccessOrder.begin(); index != pageAccessOrder.end(); index++)
	{
		cout << *index << endl;
	}
}
void memoryExpression::disppageList()//打印页表
{
	for (auto index = pageList.begin(); index != pageList.end(); index++)
	{
		cout << *index << endl;
	}
}
