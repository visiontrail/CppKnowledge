#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
using std::string; using std::cout; using std::endl;

class Sales_data
{
	string PrivateMember;

	friend istream &read(istream &is, Sales_data &item);

public:
	// 构造函数,直接使用默认的构造函数;
	Sales_data() = default;

	// 构造函数,冒号后边是构造函数初始值列表;
	Sales_data(const std::string &str, const double &str2) 
		: Book_Isbn(str), price(str2){}

	// 构造函数，也可以直接调用类之外的函数;
	Sales_data(std::istream &is);

	// 委托构造函数，也就是利用了其他的构造函数来初始化自己的参数列表;
	Sales_data(string BookIsbn)
		: Sales_data(BookIsbn, 33) {}

	// 拷贝构造函数;
	Sales_data(const Sales_data&) = delete;

	~Sales_data();

	// 方法成员;
	string GetIsbn()const     // 获取Isbn;
	{
		return Book_Isbn;
	}

	double GetTotalIncome();  // 获取销售总额;

	Sales_data& CombineTwo(const Sales_data &res);
	Sales_data* CombineTwo2(Sales_data *const res);

	Sales_data& operator=(const Sales_data&);

	// 数据成员;
	double price;             // 售价;
	string Book_Isbn;         // 图书编号;
	unsigned int NumOfSale;   // 销售总量;
protected:
private:
	double TotalIncome;       // 销售总额;
};


/*
对于C++标准来说，struct也是可以定义类的，所以其可以包含成员函数;
与class的区别在于;
在访问限定符之前定义的成员默认为public;class则为private;
*/
typedef struct Tag_Str_Sales_data
{
	string publicMember;
public:
	// 方法成员;
	string GetIsbn()const    // 获取Isbn;
	{
		return Book_Isbn;
	}

	double Average_Price()
	{
		double ret = 20;
		std::cout << "str_Average_Price" << std::endl;
		return ret;
	}

	// 数据成员;
	string Book_Isbn;        // 图书编号;
	unsigned int NumOfSale;  // 销售总量;
	double TotalIncome;      // 销售总额;

}Str_Sales_data, *pStr_Sales_data;


istream &read(istream &is, Sales_data &item);

#endif