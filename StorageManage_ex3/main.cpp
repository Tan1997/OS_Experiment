/**
 * 
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-06-05 18:21:20
 * @description: 	
 */

#include <iostream>
#include "memoryexpression.h"
#include <queue>
using namespace std;


void FIFO(memoryExpression& m)
{
	int missingPageNum =0;
	queue<int> blocks;
	for(auto i = m.pageAccessOrder.begin(); i != m.pageAccessOrder.end(); i++)
	{
		cout<<"------------------------------------------------------------------------------"<<endl;
		cout<<"access page "<<*i<<endl;
		if(m.pageList[*i])
			continue;
		missingPageNum ++;
		if(blocks.size()<m.blockNum)
		{
			blocks.push(*i);
			m.pageList[*i] = true;
			cout<<"put page "<<*i<<" into memory block"<<endl;
			continue;
		}
		m.pageList[blocks.front()] = false;
		m.pageList[*i] = true;
		cout <<"move page "<<blocks.front()<<" out, and " <<"put page "<<*i<<" into memory block"<<endl;
		blocks.pop();
		blocks.push(*i);
	}
	cout<<"\n\ntotal missing page number: "<<missingPageNum<<endl<<"missing page rate: "<<((double)missingPageNum/m.pageAccessOrder.size())<<endl;
}

void LRU(memoryExpression& m)
{
	int missingPageNum =0;
	vector<int> blocks;
	for(auto i = m.pageAccessOrder.begin(); i != m.pageAccessOrder.end(); i++)
	{
		cout<<"------------------------------------------------------------------------------"<<endl;
		cout<<"access page "<<*i<<endl;
		if(m.pageList[*i])
		{
			for(auto it = blocks.begin(); it != blocks.end(); it++)
			{
				if(*it == *i)
				{
					blocks.erase(it);
					blocks.push_back(*i);
					break;
				}
			}
			continue;	
		}
		missingPageNum ++;
		if(blocks.size()<m.blockNum)
		{
			blocks.push_back(*i);
			m.pageList[*i] = true;
			cout<<"put page "<<*i<<" into memory block"<<endl;
			continue;
		}
		m.pageList[blocks.front()] = false;
		m.pageList[*i] = true;
		cout <<"move page "<<blocks.front()<<" out, and " <<"put page "<<*i<<" into memory block"<<endl;
		blocks.erase(blocks.begin());
		blocks.push_back(*i);
	}
	cout<<"\n\ntotal missing page number: "<<missingPageNum<<endl<<"missing page rate: "<<((double)missingPageNum/m.pageAccessOrder.size())<<endl;
}

 int main(int argc, char const *argv[])
 {
	 memoryExpression m("../pageAccessList.txt");
//	FIFO(m);
	 LRU(m);
 	return 0;
 }
