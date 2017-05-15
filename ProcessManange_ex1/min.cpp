/**
 * 
 * @author:		胡文博
 * @email:		huwenbo@mail.dlut.edu.cn
 * @dateTime:		2017-05-15 19:32:52
 * @description: 	
 */
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream> 

using namespace std;

template <typename T>  
inline T const& myMin (T const& a, T const& b)  
{  
    return  a < b ? a : b;  
}
bool isInt(string s)
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
	if (argc != 3)
	{
		cout << "the number of parameters is error!" << endl;
		exit(-1);
	}
	string s1 = argv[1], s2 = argv[2];
	if(isInt(s1) && isInt(s2))
	{
		// cout<<"h"<<endl;
		cout<<"among "<<s1<<" and "<<s2<<", "<<"the smaller is: "<<myMin(atoi(s1.data()),atoi(s2.data()))<<endl;
	}
	else
	{
		cout<<"among "<<s1<<" and "<<s2<<", "<<"the smaller is: "<<myMin(atof(s1.data()),atof(s2.data()))<<endl;
	}
	return 0;
}
