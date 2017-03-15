#pragma once
#ifndef BK_ACOUNT_H
#define BK_ACOUNT_H

#include "stdafx.h"
#include <string>

using namespace std;

// 1

class Bank_Acount
{
public:
	Bank_Acount() = default;

	~Bank_Acount();

	static double GetRate();
	static double newrate;
	static void SetRate(double);

	double GetAmount();

private:

	std::string OwnerName;
	double amount;
	static double interestRate;
	static double initRate();
};

#endif