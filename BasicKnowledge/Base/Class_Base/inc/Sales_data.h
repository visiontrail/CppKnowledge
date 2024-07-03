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
	// ���캯��,ֱ��ʹ��Ĭ�ϵĹ��캯��;
	Sales_data() = default;

	// ���캯��,ð�ź���ǹ��캯����ʼֵ�б�;
	Sales_data(const std::string &str, const double &str2) 
		: Book_Isbn(str), price(str2){}

	// ���캯����Ҳ����ֱ�ӵ�����֮��ĺ���;
	Sales_data(std::istream &is);

	// ί�й��캯����Ҳ���������������Ĺ��캯������ʼ���Լ��Ĳ����б�;
	Sales_data(string BookIsbn)
		: Sales_data(BookIsbn, 33) {}

	// �������캯��;
	Sales_data(const Sales_data&);

	~Sales_data();

	// ������Ա;
	string GetIsbn()const     // ��ȡIsbn;
	{
		return Book_Isbn;
	}

	double GetTotalIncome();  // ��ȡ�����ܶ�;

	Sales_data& CombineTwo(const Sales_data &res);
	Sales_data* CombineTwo2(Sales_data *const res);

	Sales_data& operator=(const Sales_data&);
	friend const Sales_data operator+(const Sales_data& rhs, const Sales_data& lhs)
	{
		Sales_data obj;
		obj.NumOfSale = rhs.NumOfSale + lhs.NumOfSale;
		obj.Book_Isbn = rhs.Book_Isbn + "And" + lhs.Book_Isbn;
		return obj;
	}

	// ���ݳ�Ա;
	double price;             // �ۼ�;
	string Book_Isbn;         // ͼ����;
	unsigned int NumOfSale;   // ��������;
protected:
private:
	double TotalIncome;       // �����ܶ�;
};

/*
����C++��׼��˵��structҲ�ǿ��Զ�����ģ���������԰�����Ա����;
��class����������;
�ڷ����޶���֮ǰ����ĳ�ԱĬ��Ϊpublic;class��Ϊprivate;
*/
typedef struct Tag_Str_Sales_data
{
	string publicMember;
public:
	// ������Ա;
	string GetIsbn()const    // ��ȡIsbn;
	{
		return Book_Isbn;
	}

	double Average_Price()
	{
		double ret = 20;
		std::cout << "str_Average_Price" << std::endl;
		return ret;
	}

	// ���ݳ�Ա;
	string Book_Isbn;        // ͼ����;
	unsigned int NumOfSale;  // ��������;
	double TotalIncome;      // �����ܶ�;

}Str_Sales_data, *pStr_Sales_data;


istream &read(istream &is, Sales_data &item);


class dictionary : public Sales_data
{
public:
	double GetTotalIncome();
};

#endif