#include <stdlib.h>
#include <iostream>

//编译错误时，无法显示标志名称
#define ASPECT_RATIO 1.653
//可以获取AspectRation地址，编译错误时也可以显示该常量的名称
const double AspectRation = 1.653;

class GamePlayer
{
private:
    static const int NumOfTurns = 5;
    int Score[NumOfTurns];
};

class GamePlayer
{
private:
    enum
    {
        NumOfTurns = 5
    };
    int Score[NumOfTurns];
};

#define CALL_WITH_MAX(A, B) func((A) < (B) ? (A) : (B))

void func(int a)
{
    printf("~%d~", a);
}

int main(int argc, char **argv)
{
    //该方法的问题
    int a = 0;
    int b = 10;

    CALL_WITH_MAX(++a, b);

    return 0;
}
