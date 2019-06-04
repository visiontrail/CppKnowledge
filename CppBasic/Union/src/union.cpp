#include <stdlib.h>
#include <iostream>
#include "union.h"


int main(int argc, char **argv)
{
    union_try_tag1 u1;
    data_tag data;
    union union_data ud;
    ud.a = 20;
    u1.a = 10;

    data.a = ud;
    data.b = &u1;

    printf("data:%d \n", data.b->a);
    return 0;
}

