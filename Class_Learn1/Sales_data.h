#pragma once
#ifndef SALES_DATA_H
#define  SALES_DATA_H

#include <string>
#include "stdafx.h"

using namespace std;
using std::string;

class Sales_data
{
public:
protected:
private:
};

struct Str_Sales_data
{
	// 方法成员;
	string GetIsbn()         // 获取Isbn;
	{
		return Book_Isbn;
	}
	double Average_Price();  // 获取平均价格;
	
	// 数据成员;
	string Book_Isbn;        // 图书编号;
	unsigned int NumOfSale;  // 销售总量;
	double TotalIncome;      // 销售总额;

};

#endif