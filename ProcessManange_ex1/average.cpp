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
inline T  myAverage (T a, T b, T c)
{
	return  (a + b + c)/3;
}
bool isInt(string s)
{
	stringstream sin(s);
	char c;
	while (sin >> c)
	{
		if (c == '.')
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		cout << "the number of parameters is error, average func need 3 parameters!" << endl;
		exit(-1);
	}
	string s1 = argv[1], s2 = argv[2], s3 = argv[3];
	if (isInt(s1) && isInt(s2) && isInt(s3))
	{
		// cout<<"h"<<endl;
		cout << "the average of  " << s1 << ", " << s2 << " and " << s3 << " is: " << myAverage(atoi(s1.data()), atoi(s2.data()),atoi(s3.data())) << endl;
	}
	else
	{
		cout << "the average of  " << s1 << ", " << s2 << " and " << s3 << " is: " << myAverage(atof(s1.data()), atof(s2.data()),atof(s3.data())) << endl;
	}
	return 0;
}
