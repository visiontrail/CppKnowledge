#include "NameObject.h"

int main(int argc, char **argv)
{
    NameObject1<int> no1("NO1", 1);
    NameObject1<int> no2(no1);

    printf("no1~!~! %s,%d \n", no1.nameValue.c_str(), no2.objectValue);
    printf("no2~!~! %s,%d \n", no2.nameValue.c_str(), no2.objectValue);

    // std::string newDog("D1");
    // std::string oldDog("D2");

    // NameObject2<int> p(newDog, 12);
    // NameObject2<int> s(oldDog, 22);

    // p = s;

    return 0;
}
