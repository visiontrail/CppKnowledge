#include <stdlib.h>
#include <iostream>
#include "union.h"

using namespace std;

int main(int argc, char **argv)
{
    union_try_tag1 u1;
    data_tag data;
    union union_data ud;
    ud.a = 20;
    u1.a = 10;

    data.a = ud;
    data.b = &u1;

    cout << "print:" << data.b->a << endl;
    return 0;
}

