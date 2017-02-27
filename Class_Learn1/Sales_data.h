#pragma once
#ifndef SALES_DATA_H
#define  SALES_DATA_H

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
using std::string; using std::cout; using std::endl;

class Sales_data
{
public:
	// 构造函数;
	Sales_data() = default;

	// 构造函数,冒号后边是构造函数初始值列表;
	Sales_data(const std::string &str, const double &str2) 
		: Book_Isbn(str), TotalIncome(str2)
	{
	}
	Sales_data(std::istream &is);

	// 方法成员;
	string GetIsbn()const     // 获取Isbn;
	{
		return Book_Isbn;
	}
	double Average_Price2();  // 获取平均价格;

	Sales_data& CombineTwo(const Sales_data &res);
	Sales_data* CombineTwo2(Sales_data *const res);

	// 数据成员;
	string Book_Isbn;         // 图书编号;
	unsigned int NumOfSale;   // 销售总量;
	double TotalIncome;       // 销售总额;
protected:
private:
};


/*
对于C++标准来说，结构中是支持成员函数的，但是这个函数必须定义在结构内;
*/
typedef struct Tag_Str_Sales_data
{
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