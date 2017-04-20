#include "stdafx.h"
#include "StrVec.h"
#include <memory>

StrVec::StrVec(const StrVec &)
{
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

std::pair<string*, string*> StrVec::alloc_n_copy(const string *, const string *)
{
	return std::pair<string*, string*>();
}

void StrVec::reallocator()
{
}

void StrVec::free()
{
}
