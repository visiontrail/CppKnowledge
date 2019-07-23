#include <memory>
#include <iostream>
#include <vector>
#include <string>

#ifndef __SHARED_PRT_STRBLOB__
#define __SHARED_PRT_STRBLOB__

class StrBlob
{
public:
StrBlob();
StrBlob(std::initializer_list<std::string> il);
void push_back(const std::string &d)
{
    data->push_back(d);
}

private:
std::shared_ptr<std::vector<std::string>> data;
};

#endif
