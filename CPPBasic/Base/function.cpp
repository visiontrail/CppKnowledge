#include "stdafx.h"
#include <string>

using namespace std;
using std::string;

/*
函数作用：返回值为一个引用的函数;
*/
string &refStringA(string &str)
{
	return str;
}

/*
函数作用：递归函数;
*/
int factorial(int val)
{
	if (val > 1)
	{
		return factorial(val - 1) * val;
	}
	// 必须有个终止递归调用的条件;
	return 1;
}