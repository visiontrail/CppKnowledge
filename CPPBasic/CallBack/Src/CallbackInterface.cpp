#include "CallBackInterface.h"
#include "MO.h"

/*
 * 第一种方式：BOSS通过直接发送指令的方式获取信息
 * 参数1：指定一个需要获取的管理对象（MO）编号
 * 参数2：
*/
bool CallBackInterface::GetVal_ByMOCode(int MO_Code, int Dest, bool (*func)(void *param))
{
    switch (MO_Code)
    {
    case OAM_SUBSYSA_GETXXX:
        emp01.Do_SomeWork(func);
        break;

    case OAM_SUBSYSB_SETXXX:
        break;

    default:
        break;
    }

    return true;
}

CallBackInterface::CallBackInterface()
{
}

CallBackInterface::~CallBackInterface()
{
}