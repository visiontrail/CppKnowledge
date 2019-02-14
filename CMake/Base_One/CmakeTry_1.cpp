// CmakeTry_1.cpp
//

#include "cmake_try.h"
#include <iostream>
#include "hello.h"
using namespace std;

int main()
{
	int temp = 0;
	func(&temp);
	cout << temp << endl;
	printhello();
   	return 0;
}

void func(int *a)
{
	*a = PRINTDEFINE;
}

