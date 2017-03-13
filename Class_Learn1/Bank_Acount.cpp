#include "stdafx.h"
#include "Bank_Acount.h"

double Bank_Acount::interestRate = initRate();
double Bank_Acount::newrate = 0.04;

double Bank_Acount::GetRate()
{
	return interestRate;
}

void Bank_Acount::SetRate(double rate)
{
	interestRate = rate;
}

double Bank_Acount::initRate()
{
	return 0.03;
}

double Bank_Acount::GetAmount()
{
	amount += amount*interestRate;
	return amount;
}

Bank_Acount::~Bank_Acount()
{
}