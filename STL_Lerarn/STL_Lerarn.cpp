// STL_Lerarn.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "STL_Learn.h"
#include "Vector_etc.h"
#include "String_l.h"
#include "Sales_data.h"


using namespace std;
using std::string;

int main(int argc, char* args[])
{

	//-----------------vector-----------------------
	// 利用字符串拆分学习了下vector;
	std::string inputstr = "123//324//345/56";
	std::string splitstr = "//";
	std::vector<std::string> res = SplitStr(inputstr, splitstr);
	for (int i = 0; i < (int)res.size(); ++i)
	{
		std::cout << "Split result is " << res[i].c_str() << endl;
	}

	strvec vec1;

	// vector中使用迭代器进行迭代;
	vec1.vectorinit();
	for (vector<std::string>::iterator iter = vec1.strvector.begin(); iter != vec1.strvector.end();++iter)
	{
		std::cout << "使用iterator迭代;" << iter->c_str() << endl;
	}
	for (auto c : vec1.strvector)
	{
		std::cout << "新的迭代方法;" << c.c_str() << endl;
	}
	//-----------------vector-----------------------


	// ----------------string------------------
	// 使用string中字典排序对string内容进行比较;
	Bookinfo BKList;
	auto Booklist = BKList.Strinit();
	if (Booklist[1] > Booklist[2])
	{
		std::cout << "11" << std::endl;
	}

	// 通过Getline获取用户输入
// 	std::cout << "Input Something:";
// 	BKList.GetUserInput();
	//-----------------string------------------

	//---------------类的学习;-----------------
	//-----------str_Sales_data----------------
	Str_Sales_data strSalesData;
	const Str_Sales_data con_strSalesData;    //con_strSalesData是一个底层const,也就是其地址非常量;

	strSalesData.Book_Isbn = "00001";

	// 一个非常量对象访问了const修饰的成员函数;
	std::string PrintBook = strSalesData.GetIsbn();
	// 隐含了this指针的实际调用是;
	// Sales_data::GetIsbn(&strSalesData);
	// 一个常量对象访问了const修饰的成员函数;

	std::string PrintBook2 = con_strSalesData.GetIsbn();
	// 隐含了this指针的实际调用是;
	// Sales_data::GetIsbn(&con_strSalesData);


	// 那么用const修饰的成员函数起到了什么作用?;
	// const修饰符起到了修改隐式this指针的类型;


	// 一个非常量对象访问了普通的成员函数;
	strSalesData.Average_Price();
	// 一个常量对象访问了普通的成员函数;
	con_strSalesData.Average_Price();
	std::cout << "str_Sales_data's BookIsbn:" << PrintBook << std::endl;

	//-----------str_Sales_data----------------


	//-----------str_Sales_data----------------
	system("pause");
    return 0;
}


