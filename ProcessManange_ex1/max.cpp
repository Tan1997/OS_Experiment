/**
 * 
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-05-15 19:32:46
 * @description: 	
 */
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream> 
using namespace std;

template <typename T>  
inline T const& myMax (T const& a, T const& b)//模板函数实现任意数据类型的数据求最大值  
{  
    return  a < b ? b : a;  
}
bool isInt(string s)//根据输入数据是否小数点来判断是整形数还是浮点数
{
	stringstream sin(s);
	char c;
	while(sin>>c)
	{
		if(c == '.')
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	if (argc != 3)//参数个数不对
	{
		cout << "the number of parameters is error!" << endl;
		exit(-1);
	}
	string s1 = argv[1], s2 = argv[2];
	if(isInt(s1) && isInt(s2))//整形输入
	{
		cout<<"among "<<s1<<" and "<<s2<<", "<<"the bigger is: "<<myMax(atoi(s1.data()),atoi(s2.data()))<<endl;
	}
	else//浮点型输入
	{
		cout<<"among "<<s1<<" and "<<s2<<", "<<"the bigger is: "<<myMax(atof(s1.data()),atof(s2.data()))<<endl;
	}
	return 0;
}
