/*
 * ˵������������Ҫ˵�������¼���֪ʶ�㣺
 * 1��ʲô�ǿ������캯������������
 * 2���������͵������
*/

#include "stdafx.h"
#include "Sales_data.h"

void printSalesData(const Sales_data& Obj)
{
	std::cout << Obj.GetIsbn() << std::endl;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	std::cout << "Please Type in Information(Isbn,NumOfSale,Price,TotalInCome)";
	is >> item.Book_Isbn >> item.NumOfSale >> item.price >> item.TotalIncome;
	return is;
}

// istream��һ���������ͣ���ʵ����cin;
Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}

Sales_data::Sales_data(const Sales_data &copyobj) :
	Book_Isbn(copyobj.Book_Isbn),
	price(copyobj.price),
	TotalIncome(copyobj.TotalIncome)
{
	std::cout << "����ͨ���������캯����ֵ���ɵ�;" << std::endl;
}

/*
 * ���ã����ص��������
 * ˵����
*/
Sales_data& Sales_data::operator=(const Sales_data &obj)
{
	this->Book_Isbn = "Copyfromoperator;";
	return *this;
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

double Sales_data::GetTotalIncome()
{
	this->TotalIncome = this->NumOfSale * this->price;
	return TotalIncome;
}

Sales_data::~Sales_data()
{
	std::cout << this->Book_Isbn << "Sales_data��������;" << std::endl;
}

double dictionary::GetTotalIncome()
{
	std::cout << "This is class dictionary override function" << std::endl;
	return 1;
}