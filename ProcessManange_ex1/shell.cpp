/**
 *
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-05-15 19:52:46
 * @description:
 */
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost::algorithm;

int main(int argc, char const *argv[])
{
	cout << "welcome to young shell !" << endl;
	string s;
	cout << "young@shel: ->_->";
	vector<string> vecStr;
	while (getline(cin, s))//读入一行输入
	{
		cout << "young@shel: ->_->";//打印命令提示符
		vecStr.clear();
		boost::char_separator<char> sep("  ,()");
		typedef boost::tokenizer<boost::char_separator<char> >
		CustonTokenizer;
		CustonTokenizer tok(s, sep);//正则表达式将输入字符串分割为命令和参数
		for (CustonTokenizer::iterator beg = tok.begin(); beg != tok.end(); ++beg)
		{
			vecStr.push_back(*beg);
		}
		if (vecStr.size())//非空输入
		{
			if (fork() == 0)//判断是否位于子进程
			{
				if (vecStr[0] == "max")//子进程装入max(m,n)程序数据
				{
					execlp("/home/cris/gitRep/OS_Experiment/ProcessManange_ex1/build/max", "./max", vecStr[1].data(), vecStr[2].data(), NULL);
					exit(0);
				}
				else if (vecStr[0] == "min")//子进程装入min(m,n)程序数据
				{
					execlp("/home/cris/gitRep/OS_Experiment/ProcessManange_ex1/build/min", "./min", vecStr[1].data(), vecStr[2].data(), NULL);
					exit(0);
				}
				else if (vecStr[0] == "average")//子进程装入average(m,n,l)程序数据
				{
					execlp("/home/cris/gitRep/OS_Experiment/ProcessManange_ex1/build/average", "./average", vecStr[1].data(), vecStr[2].data(), vecStr[3].data(), NULL);
					exit(0);
				}
				else
					exit(0);
			}
		}
	}
	return 0;
}