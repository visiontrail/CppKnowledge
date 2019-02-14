// CmakeTry_1.cpp
//

#include "cmake_try.h"
#include <iostream>
#include "hello.h"
#include "calc.h"
using namespace std;

int main()
{
	int temp;
	func(&temp);
	cout << temp << endl;
	cout << "The Max Number is" << Get_Max(10, 20) << endl;
	printhello();
	return 0;
}

void func(int *a)
{
	*a = PRINTDEFINE;
}
