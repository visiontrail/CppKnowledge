#include "stdafx.h"
#include "StrVec.h"
#include <memory>

StrVec::StrVec(const StrVec &s)
{
	auto new_Data = alloc_n_copy(s.begin(), s.end());
	first_elem = new_Data.first;
	first_free = cap = new_Data.second;
}

StrVec & StrVec::operator=(const StrVec &strvec)
{
	StrVec Vec;
	return Vec;
}

StrVec::~StrVec()
{
}

void StrVec::push_back(const string& str)
{
	chk_n_alloc();
	alloc.construct(first_free++, str);
}

void StrVec::reallocator()
{
}

void StrVec::free()
{
}
