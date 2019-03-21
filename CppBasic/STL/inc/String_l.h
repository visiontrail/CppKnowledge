#pragma once
#include <string>
using namespace std;
using std::string;

class Bookinfo
{
public:
	string BookName;
	int ISBN;
	int Price;

	// 默认的构造函数;
	Bookinfo(){}

	// 第二个构造函数，直接初始化Bookinfo的所有属性信息;
	Bookinfo(string BKName, int isbn, int price)
	{
		this->BookName = BKName;
		this->ISBN = isbn;
		this->Price = price;
	}

	// 析构函数;
	~Bookinfo()
	{
	}
	
	// 初始化一个BookList用于实验;
	vector<Bookinfo> Strinit();

	// 使用getline获取用户输入;
	void GetUserInput();

	// 由于string支持字典排序;
	// 重载大于小于运算符;
	// 这样一来，Bookinfo可以使用>或<直接比较
	bool operator >(const Bookinfo Bi) const
	{
		return this->BookName > Bi.BookName;
	}

	bool operator <(const Bookinfo Bi) const
	{
		return this->BookName < Bi.BookName;
	}
};
