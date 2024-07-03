#ifndef _STRINGHELPER_
#define _STRINGHELPER_

#include <stdlib.h>
#include <iostream>

template<typename T>
class NameObject1
{
    public:
        NameObject1(const char* name, const T& value)
        {
            printf("NameObject1(const char* name, const T& value)\n");
            nameValue = name;
            objectValue = value;
        }
        NameObject1(const std::string& name, const T& value)
        {
            printf("NameObject1(const std::string& name, const T& value)\n");
            nameValue = name;
            objectValue = value;
        }
        std::string nameValue;
        T objectValue;
};

template<class T>
class NameObject2
{
    public:
        NameObject2(const std::string& nameValue, const T& obectValue)
        {

        }
        std::string& nameValue;
        T objectValue;
};

#endif