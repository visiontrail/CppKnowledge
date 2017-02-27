#include "stdafx.h"
#include "Sales_data.h"

void printSalesData(const Sales_data& Obj)
{
	std::cout << Obj.GetIsbn() << std::endl;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.Book_Isbn >> item.NumOfSale >> item.TotalIncome;
	return is;
}

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}

double Sales_data::Average_Price2()
{
	double ret = 10;
	return ret;
}

Sales_data& Sales_data::CombineTwo(const Sales_data &res)
{
	this->NumOfSale += res.NumOfSale;
	this->TotalIncome += res.TotalIncome;
	return *this;
}

Sales_data* Sales_data::CombineTwo2(Sales_data *const res)
{
	this->NumOfSale += res->NumOfSale;
	this->TotalIncome += res->TotalIncome;
	return this;
}