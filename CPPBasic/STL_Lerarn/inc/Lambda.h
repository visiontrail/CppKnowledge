#pragma once
#include "stdafx.h"
#include <vector>
#include <string>

class AddressBook
{
public:
	// using a template allows us to ignore the differences between functors, function pointers   
	// and lambda  
	template<typename Func>
	std::vector<std::string> findMatchingAddresses(Func func)
	{
		std::vector<std::string> results;
		for (auto itr = _addresses.begin(), end = _addresses.end(); itr != end; ++itr)
		{
			// call the function passed into findMatchingAddresses and see if it matches  
			//int aaa = itr->find("www.baidu.org");
			if (func(*itr))
			{
				results.push_back(*itr);
			}
		}
		return results;
	}

	void initVec_Addresses();

private:
	std::vector<std::string> _addresses;
};
