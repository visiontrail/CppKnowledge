// CPPBasic.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// 函数声明;
/* 声明const.cpp中的函数 */
void pointer1();
void ConstDefineInitPrint();
void ConstDefinePrint();

/* 声明auto.cpp中的函数 */
void autoUsing_JudgeType();
void UseAutoMultiply(T t, U u);

int main()
{
	//----const类型相关;start------
	pointer1();
	ConstDefineInitPrint();
	ConstDefinePrint();
	//----const类型相关;end ------

	//----auto关键字;---------
	autoUsing_JudgeType();
	UseAutoMultiply(3.14, 10);
	//----auto关键字;---------

	std::system("pause");
	return 0;
}
