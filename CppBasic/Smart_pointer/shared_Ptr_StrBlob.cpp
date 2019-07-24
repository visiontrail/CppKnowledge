#include "shared_Ptr_StrBlob.h"

StrBlob::StrBlob()
    : data(std::make_shared<std::vector<std::string>>())
{
}
StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>())
{
}
