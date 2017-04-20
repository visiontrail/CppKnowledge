#pragma once
#ifndef STRVEC_H
#define STRVEC_H

#include "stdafx.h"
#include <string>
#include <memory>

using namespace std;
using std::string;

class StrVec
{
public:
	StrVec() : first_elem(nullptr), first_free(nullptr), cap(nullptr) 
	{
		alloc.allocate(100);
	}
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);
	size_t size() const
	{
		return first_free - first_elem;
	}
	size_t capcity() const
	{
		return cap - first_elem;
	}
	string* begin()
	{
		return first_elem;
	}
	string* end()
	{
		return first_free;
	}
protected:
private:
	void chk_n_alloc()
	{
		if (this->size() == this->capcity())
		{
			reallocator();
		}
	}
	std::pair<string*, string*> alloc_n_copy(const string*, const string*);
	void reallocator();
	void free();
	string *first_elem;                     // 指向第一个元素;
	string *first_free;                     // 指向最后一个元素之后;
	string *cap;                            // 指向所分配内存之后;
	std::allocator<string> alloc;    // 所分配的内存;
};

#endif