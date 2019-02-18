// CmakeTry_1.cpp
//

#include "cmake_try.h"
#include <iostream>
#include "hello.h"
#include "calc.h"
#include "calc2.h"
#include "stringHelper.h"

using namespace std;

int main()
{
	int temp;
	func(&temp);
	cout << temp << endl;
	cout << "The Max Number is " << Get_Max(10, 20) << endl;
	cout << "The Min Number is " << Get_Min(10, 20) << endl;
	printhello();
	char *str;
	str = "Abc";
	ToLower(str);

	return 0;
}

void func(int *a)
{
	*a = PRINTDEFINE;
}

void func2(int *a)
{
	*a = 100;
}
