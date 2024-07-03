// STL_Lerarn.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <functional>

#include "STL_Learn.h"
#include "Vector_etc.h"
#include "String_l.h"
#include "Sales_data.h"
#include "Lambda.h"

using namespace std;
using std::string;

//---------Lambda���ʽ;------------
auto f1 = []
{
	return 42;
};

auto PrintLambdaFunc = [](int a)
{
	std::cout << "print" << std::endl;
};

bool FindAssignSizeString(const string &str, const int &size)
{
	return str.size() > size;
}

bool FindSizeOver5String(const string &str)
{
	return str.size() > 5;
}


//---------Lambda���ʽ;------------

int main(int argc, char* args[])
{
	//-----------------vector-----------------------
	// �����ַ������ѧϰ����vector;
	std::string inputstr = "123//324//345/56";
	std::string splitstr = "//";
	std::vector<std::string> res = SplitStr(inputstr, splitstr);
	for (int i = 0; i < (int)res.size(); ++i)
	{
		std::cout << "Split result is " << res[i].c_str() << endl;
	}

	strvec vec1;

	// vector��ʹ�õ��������е���;
	vec1.vectorinit();
	for (vector<std::string>::iterator iter = vec1.strvector.begin(); iter != vec1.strvector.end();++iter)
	{
		std::cout << "ʹ��iterator����;" << iter->c_str() << endl;
	}
	for (auto c : vec1.strvector)
	{
		std::cout << "�µĵ�������;" << c.c_str() << endl;
	}
	std::string findval = "strlist3";
	std::vector<std::string>::iterator res3 = find(vec1.strvector.begin(), vec1.strvector.end(), findval);

	std::cout << "����" << findval << (res3 == vec1.strvector.end() ? "û���ҵ�;" : "�ҵ���;") << std::endl;
	//std::cout << res3->c_str() << std::endl;
	
	if (res3 != vec1.strvector.end())
	{
		int countn = count(vec1.strvector.begin(), vec1.strvector.end(), findval);
		std::cout << "���ҵ�" << countn << "��" << std::endl;

	}

	int findval2 = 110;
	auto res4 = find(vec1.vecint.begin(), vec1.vecint.end(), findval2);
	int sum = accumulate(vec1.vecint.begin(), vec1.vecint.end(), 10);

	for (auto itor : vec1.vecint)
	{
		if (itor == 0 || itor == 100)
		{
			std::cout << "Before sort:" << itor << std::endl;
		}
	}

	// ��Ԫν�ʵ�ʹ�÷���;
	sort(vec1.vecint.begin(), vec1.vecint.end(), SortFater50);

	for (auto itor : vec1.vecint)
	{

		std::cout << "(Two Predicate)After sort:" << itor << std::endl;

	}

	// lambda���ʽ��ʹ�÷���;
	stable_sort(vec1.vecint.begin(), vec1.vecint.end(), [](const int& a, const int& b) 
	{
		if (a > 50 || b > 50)
		{
			return a > b;
		}
		return a < b;
	});

	for (auto itor : vec1.vecint)
	{

		std::cout << "(Lambda)After sort:" << itor << std::endl;

	}

	std::cout << "Accumlate Result is" << sum << std::endl;
	std::cout << "����" << findval2 << (res4 == vec1.vecint.end() ? "û���ҵ�;" : "�ҵ���;") << std::endl;

	//-----------------vector-----------------------


	// ----------------string------------------
	// ʹ��string���ֵ������string���ݽ��бȽ�;
	Bookinfo BKList;
	auto Booklist = BKList.Strinit();
	if (Booklist[1] > Booklist[2])
	{
		std::cout << "11" << std::endl;
	}

	// ͨ��Getline��ȡ�û�����
// 	std::cout << "Input Something:";
// 	BKList.GetUserInput();
	//-----------------string------------------

	//--------------IOStream-------------------

	// ��������ļ�,ʹ��ofstream;
	ofstream fout;
	fout.open("out.txt");

	// ��ofstream�Ĺ��캯������ֱ�Ӵ���open�����Ĳ���;
	// ���ģʽΪappģʽ(append)�Ļ�����open��ʱ��,�����������open���ļ�;
	std::ofstream out("..//data//1.txt", ofstream::app);
	std::ifstream in("..//data//Sales_data.txt");

	if (out.is_open())
	{
		std::cout << "open!" << std::endl;
		out << "print \n";
		out << "print3 \n";
		out.close();
	}
	else
	{
		std::cout << "not open!" << std::endl;
	}

	char buff[265];
	if (in.is_open())
	{
		while (!in.eof())
		{
			in.getline(buff, 100);
			cout << buff << std::endl;
		}
	}
	else
	{
		cout << "open failed!" << endl;
	}
	
	//--------------IOStream-------------------


	//--------------lambda---------------------

	std::cout << "��򵥵ĵ���һ��Lambda���ʽ?:" << f1()<< std::endl;

	AddressBook global_address_book;
	global_address_book.initVec_Addresses();
	std::vector<std::string> res5 = global_address_book.findMatchingAddresses
	(
		[](const string& str) { return str.find(".org") != std::string::npos; }
	);

	int sz = 5;
	std::vector<std::string> res6 = global_address_book.findMatchingAddresses
	(
		[sz](const string& str) { return (str.find(".org") != std::string::npos) && (str.size() > sz); }
	);

	for (auto printtemp : res6)
	{
		std::cout << "Lambda after:" << printtemp << std::endl;
	}

	std::vector<string> words;
	words.push_back("www.baidu.com");
	words.push_back("www.baidu.org");
	words.push_back(".org");
	words.push_back("www.ling3d.org");
	words.push_back("www");

	auto wc2 = find_if(words.begin(), words.end(), FindSizeOver5String);
	std::cout << "ʹ��һԪν�ʵ�ʱ��;" << *wc2 << std::endl;

	auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {return a.size() <= sz; });
	std::cout << "ʹ��Lambda���ʽ��ʱ��;" << *wc << std::endl;

// 	auto checkoverSZstring = bind(FindAssignSizeString, _1, sz);

	struct MyStruct
	{
		int a;
		double b;
	};

	cout << "Sizeof MyStruct:" << sizeof(MyStruct) << std::endl;
	//--------------lambda---------------------

	system("pause");
    return 0;
}


