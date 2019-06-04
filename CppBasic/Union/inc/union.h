#ifndef _UNION_
#define _UNION_


typedef union union_try1
{
    int a;
    char b;
}union_try_tag1;

union union_data
{
    int a;
    char b;
};

typedef struct stru_union_data
{
    union union_data a;
    union_try_tag1 *b;
    int c;
}data_tag;




#endif