#include "CPPBasic.h"
#include "stdafx.h"
#include <iostream>

using namespace std;

/*
*  递归的使用说明
*/

int Jiecheng(const int n)
{
	if (0 >= n)
	{
		std::cout << "Wrong Parameter n Please Check!" << std::endl;
		return n;
	}
	else if (1 == n)
	{
		return 1;
	}
	else
	{
		// 递归的本质是将问题拆解，即将n!拆解为n*!(n-1);
		return n * Jiecheng(n - 1);
	}
}