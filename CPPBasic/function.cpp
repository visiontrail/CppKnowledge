#include "stdafx.h"
#include <string>

using namespace std;
using std::string;

string &refStringA(string &str)
{
	return str;
}

int factorial(int val)
{
	if (val > 1)
	{
		return factorial(val - 1) * val;
	}
	// 必须有个终止递归调用的条件;
	return 1;
}