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

	// Ĭ�ϵĹ��캯��;
	Bookinfo(){}

	// �ڶ������캯����ֱ�ӳ�ʼ��Bookinfo������������Ϣ;
	Bookinfo(string BKName, int isbn, int price)
	{
		this->BookName = BKName;
		this->ISBN = isbn;
		this->Price = price;
	}

	// ��������;
	~Bookinfo()
	{
	}
	
	// ��ʼ��һ��BookList����ʵ��;
	vector<Bookinfo> Strinit();

	// ʹ��getline��ȡ�û�����;
	void GetUserInput();

	// ����string֧���ֵ�����;
	// ���ش���С�������;
	// ����һ����Bookinfo����ʹ��>��<ֱ�ӱȽ�
	bool operator >(const Bookinfo Bi) const
	{
		return this->BookName > Bi.BookName;
	}

	bool operator <(const Bookinfo Bi) const
	{
		return this->BookName < Bi.BookName;
	}
};
