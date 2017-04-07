// Smart_pointer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "smart_pointer.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
using std::string;
using std::vector;

void ProcessString(string *str)
{
	*str = "asdad";
}

class processString
{
public:
	processString(const string str)
		: str(str)
	{
		std::cout << "Object is create!" << std::endl;
	}
	~processString()
	{
		std::cout << "Object is delete!" << std::endl;
	}

	void printstr()
	{
		std::cout << "str is:" << str << std::endl;
	}
private:
	string str;
};

int main()
{
	shared_ptr<string> pstring;
	auto_ptr<processString> atp2;

	processString *normstr = new processString("str_normalPrintor");
	normstr->printstr();

	std::auto_ptr<processString> atp(new processString("str_auto"));
	atp->printstr();
	atp2 = atp;

	std::shared_ptr<processString> shp(new processString("str_share"));
	shp->printstr();

	std::unique_ptr<processString> unqp(new processString("str_unique"));
	unqp->printstr();

	delete(normstr);

	shared_ptr<string> filmlist[5]
	{
		shared_ptr<string>(new string("Film1")),
		shared_ptr<string>(new string("Film2")),
		shared_ptr<string>(new string("Film3")),
		shared_ptr<string>(new string("Film4")),
		shared_ptr<string>(new string("Film5"))
	};

	shared_ptr<string> winer;
	winer = filmlist[2];

	for (int i = 0; i <= 4; i++)
	{
		std::cout << *filmlist[i] << std::endl;
	}

	std::cout << "Winner is " << *winer << std::endl;
	//system("pause");

	//std::shared_ptr<>
    return 0;
}

