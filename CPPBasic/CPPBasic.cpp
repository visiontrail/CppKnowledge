// CPPBasic.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "Sales_data.h"

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

void Printconst();


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

	//----常量指针;-------
	Printconst();
	//----常量指针;-------

	//---------------类的学习;-----------------
	//-----------str_Sales_data----------------
	Str_Sales_data strSalesData;
	const Str_Sales_data con_strSalesData;    //con_strSalesData是一个底层const,也就是其地址非常量;

	strSalesData.Book_Isbn = "00001";

	// 一个非常量对象访问了const修饰的成员函数;
	std::string PrintBook = strSalesData.GetIsbn();
	// 一个常量对象访问了const修饰的成员函数;
	std::string PrintBook2 = con_strSalesData.GetIsbn();

	// 一个非常量对象访问了普通的成员函数;
	strSalesData.Average_Price();
	// 一个常量对象访问了普通的成员函数会产生错误;
	//con_strSalesData.Average_Price();
	std::cout << "str_Sales_data's BookIsbn:" << PrintBook << std::endl;

	//-----------str_Sales_data----------------


	//-----------str_Sales_data----------------


	std::system("pause");
	return 0;
}
