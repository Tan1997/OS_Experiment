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
#include <map>
#include <functional>
using namespace std;
// 先进先出算法实现
void FIFO(memoryExpression& m)
{
	int missingPageNum = 0;//缺页数
	queue<int> blocks;
	for (auto i = m.pageAccessOrder.begin(); i != m.pageAccessOrder.end(); i++)
	{
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "access page " << *i << endl;
		if (m.pageList[*i])//不缺页
			continue;
		// 产生缺页中断
		missingPageNum ++;
		if (blocks.size() < m.blockNum)//有空闲内存块，无需换出
		{
			blocks.push(*i);
			m.pageList[*i] = true;
			cout << "put page " << *i << " into memory block" << endl;
			continue;
		}
		m.pageList[blocks.front()] = false;//没有空闲内存块，需要换出
		m.pageList[*i] = true;
		cout << "move page " << blocks.front() << " out, and " << "put page " << *i << " into memory block" << endl;
		blocks.pop();
		blocks.push(*i);
	}
	cout << "\n\ntotal missing page number: " << missingPageNum << endl << "missing page rate: " << ((double)missingPageNum / m.pageAccessOrder.size()) << endl;
}
// 最近最久未使用算法实现
void LRU(memoryExpression& m)
{
	int missingPageNum = 0;
	vector<int> blocks;
	for (auto i = m.pageAccessOrder.begin(); i != m.pageAccessOrder.end(); i++)
	{
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "access page " << *i << endl;
		if (m.pageList[*i])//不缺页
		{
			for (auto it = blocks.begin(); it != blocks.end(); it++)
			{
				if (*it == *i)
				{
					blocks.erase(it);
					blocks.push_back(*i);
					break;
				}
			}
			continue;
		}
		// 产生缺页中断
		missingPageNum ++;
		if (blocks.size() < m.blockNum)//有空闲内存块，无需换出
		{
			blocks.push_back(*i);
			m.pageList[*i] = true;
			cout << "put page " << *i << " into memory block" << endl;
			continue;
		}
		m.pageList[blocks.front()] = false;//没有空闲内存块，需要换出
		m.pageList[*i] = true;
		cout << "move page " << blocks.front() << " out, and " << "put page " << *i << " into memory block" << endl;
		blocks.erase(blocks.begin());
		blocks.push_back(*i);
	}
	cout << "\n\ntotal missing page number: " << missingPageNum << endl << "missing page rate: " << ((double)missingPageNum / m.pageAccessOrder.size()) << endl;
}
// 主函数
int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		cout << "please use the format: ProcesserSchema_ex2 [process list file] [schema algorithm]" << endl;
		return -1;
	}
	memoryExpression m(argv[1]);//建立字符串到函数的映射
	map<string, function<void(memoryExpression& )> > myEval;
	myEval["FIFO"] = FIFO;
	myEval["LRU"] = LRU;
	string comand(argv[2]);
	myEval[comand](m);
	return 0;
}
