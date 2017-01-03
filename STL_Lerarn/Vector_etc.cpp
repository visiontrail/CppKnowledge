#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>

#include "STL_Learn.h"

using namespace std;

void int2str(const int &int_temp, string &string_temp)
{
	stringstream stream;
	stream << int_temp;
	string_temp = stream.str();
}

void strvec::vectorinit()
{
	for (int i = 0; i < 10; ++i)
	{
		string tempstr = "Strlist";
		string temp2;
		int2str(i, temp2);
		tempstr += temp2;

		strvector.push_back(tempstr);
	}

}

