/*
���ļ�ѧϰ����Ҫ������;
1��string�Ļ����÷�
2��stream�Ļ����÷�
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

#include "String_l.h"

using namespace std;
using std::string;

// ��ʼ�������Ա�ʵ��;
vector<Bookinfo> Bookinfo::Strinit()
{
	std::vector<Bookinfo> BKinfo;

	BKinfo.push_back(Bookinfo("Book1", 110001, 100));
	BKinfo.push_back(Bookinfo("Book3", 110003, 300));
	BKinfo.push_back(Bookinfo("Book2", 110003, 50));

	return BKinfo;
}

// ʹ��getline��ȡ�û�����;
void Bookinfo::GetUserInput()
{
	string line;
	string::size_type len;

	while (getline(std::cin, line))
	{
		for (auto &c : line)
		{
			c = toupper(c);
		}

		std::cout << line << std::endl;
		len = line.size();
		auto len2 = line.size();
		// �ӡ�size_t��ת������int�������ܶ�ʧ����;
		//int len3 = line.size();
		std::cout << "������ַ�����Ϊ;" << len2 << std::endl;

		return;
	}

	return;
}