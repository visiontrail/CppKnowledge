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
	Str_Sales_data ProductA;
	const Str_Sales_data con_strSalesData;    //con_strSalesData是一个底层const,也就是其地址非常量;

	strSalesData.Book_Isbn = "00001";
	strSalesData.NumOfSale = 100;
	strSalesData.TotalIncome = 1000.4;

	// 一个非常量对象访问了const修饰的成员函数;
	std::string PrintBook = strSalesData.GetIsbn();
	// 一个常量对象访问了const修饰的成员函数;
	std::string PrintBook2 = con_strSalesData.GetIsbn();

	// 一个非常量对象访问了普通的成员函数;
	strSalesData.Average_Price();

	// 一个常量对象访问了普通的成员函数会产生错误;
	//con_strSalesData.Average_Price();
	std::cout << "str_Sales_data's BookIsbn:" << PrintBook << std::endl;

	//-----------Sales_data----------------
	Sales_data ProductB;
	Sales_data total;
	Sales_data *total2 = &total;

	total.NumOfSale = 100;
	total.TotalIncome = 100.43;

	ProductB.NumOfSale = 200;
	ProductB.TotalIncome = 99.57;

	total = total.CombineTwo(ProductB);
	std::cout << "After combine is:" << total.NumOfSale << std::endl;

	total2 = total2->CombineTwo2(&ProductB);
	std::cout << "After combine is:" << total2->NumOfSale << std::endl;
	std::cout << "After combine is:" << total.NumOfSale << std::endl;

	// 构造函数A,带有初始化参数列表;
	std::string abc = "abc";
	Sales_data SdInit(abc, 11.1);
	std::cout << "利用构造函数初始化;" << SdInit.GetIsbn() << "," << SdInit.TotalIncome << std::endl;

	// 构造函数B，调用了一个类外函数;
	string abc2;
	Sales_data SdInit2(cin>>abc2);
	std::cout << "利用istream输入参数初始化;" << SdInit2.GetIsbn() << "," << SdInit2.TotalIncome << std::endl;

	// 类外的函数;

	//-----------Sales_data----------------


	std::system("pause");
	return 0;
}
