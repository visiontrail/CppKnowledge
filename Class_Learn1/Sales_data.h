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
protected:
private:
};


/*
对于C++标准来说，结构中是支持成员函数的;
*/
typedef struct Tag_Str_Sales_data
{
	// 方法成员;
	string GetIsbn()const    // 获取Isbn;
	{
		return Book_Isbn;
	}
	double Average_Price();  // 获取平均价格;
	
	// 数据成员;
	string Book_Isbn;        // 图书编号;
	unsigned int NumOfSale;  // 销售总量;
	double TotalIncome;      // 销售总额;

}Str_Sales_data, *pStr_Sales_data;

#endif