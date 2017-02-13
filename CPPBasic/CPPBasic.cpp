// CPPBasic.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// 函数声明;
/* 声明const.cpp中的函数 */
void pointer1();
void ConstDefineInitPrint();
void ConstDefinePrint();

/* 声明auto.cpp中的函数 */
void autoUsing_JudgeType();

/* 声明function.cpp中的函数 */
string &refStringA(string&);
// 给定了一个默认参数;
int factorial(int val = 5);


int main()
{
	//----const类型相关;start------
	pointer1();
	ConstDefineInitPrint();
	ConstDefinePrint();
	//----const类型相关;end ------

	//----auto关键字;---------
	autoUsing_JudgeType();
	//----auto关键字;---------

	//----返回值为引用的函数;---
	std::string strA = "function";
	refStringA(strA) = "FunctioN";
	std::cout << "函数返回了引用strA;" << strA << std::endl;
	//----返回值为引用的函数;---

	//---函数的递归调用;---
	int ret = factorial();
	//---函数的递归调用;---
	
	//----指向指针的指针;------

	//----指向指针的指针;------

	std::system("pause");
	return 0;
}
