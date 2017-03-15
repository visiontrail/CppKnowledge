// CPPBasic.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "CPPBasic.h"
#include <string>

int main()
{
	//----1、const类型相关;------
	pointer1();
	ConstDefineInitPrint();
	ConstDefinePrint();
	//常量指针;
	Printconst();
	//----1、const类型相关;------

	//----2、auto关键字;---------
	autoUsing_JudgeType();
	//----2、auto关键字;---------


	// ---3、函数相关;-----------
	//返回值为引用的函数;
	std::string strA = "function";
	refStringA(strA) = "FunctioN";
	std::cout << "函数返回了引用strA;" << strA << std::endl;

	//函数的递归调用;
	int ret = factorial();

	// ---3、函数相关;-----------
	
	//----4、指针;------

	//----4、指针;------


	//----5、类的学习;-------------------------
	
	//struct:str_Sales_data
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

//--------------------------------------------------------------------------------------

	//class:Sales_data
	Sales_data ProductB;
	Sales_data total;
	Sales_data *total2 = &total;

	total.NumOfSale = 100;
	total.price = 100.43;

	ProductB.NumOfSale = 200;
	ProductB.price = 99.57;

	total = total.CombineTwo(ProductB);
	std::cout << "After combine is:" << total.NumOfSale << std::endl;

	total2 = total2->CombineTwo2(&ProductB);
	std::cout << "After combine is:" << total2->NumOfSale << std::endl;
	std::cout << "After combine is:" << total.NumOfSale << std::endl;

	// 构造函数A,带有初始化参数列表;
	std::string BookIsbn = "CppPrimer";
	Sales_data SdInit(BookIsbn, 55.9);
	std::cout << "利用构造函数初始化,图书ISBN;" << SdInit.GetIsbn() << ",图书价格;" << SdInit.price << std::endl;

	// 构造函数B，调用了类外的函数;
    // istream的实例就是cin;
	Sales_data B(cin);
	std::cout << "构造函数调用了Read函数，用户输入后,\nISBN;" << B.GetIsbn() << "\nPrice;" << B.price << "\nNumofSales;" << B.NumOfSale << std::endl;
	std::cout << "图书;" << B.GetIsbn() << "的销售总额为;" << B.GetTotalIncome() << std::endl;

	std::string nullbook = "99-99-99-99";
	SdInit.CombineTwo(nullbook);

	SdInit.CombineTwo(Sales_data(nullbook));

	read(cin,ProductB);

//----------------------------------------------------------------------------
	
	//Screen
	Screen screen1(8, 4, 'a');
	char ret2 = screen1.get();
	screen1.move(0, 0).set('b').move(1,1).set('c').display();

//----------------------------------------------------------------------------
	
	//Bank_Ancout
	Bank_Acount::SetRate(0.03);
	double rate = Bank_Acount::GetRate();
	std::cout << "Rate is:" << rate << std::endl;

	//----5、类的学习;-------------------------

	std::system("pause");
	return 0;
}
