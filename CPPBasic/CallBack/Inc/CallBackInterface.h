#ifndef CALLBACKINTERFACE
#define CALLBACKINTERFACE

#include <stdlib.h>
#include <vector>
#include <map>
#include <iostream>
#include "Employee.h"

using namespace std;

/*
 * 说明：回调函数的对外接口类，通过该类型进行消息的分发工作
*/
class CallBackInterface
{
  private:
    Employee emp01; // 注册所有的Employee类型

  public:
    CallBackInterface();
    ~CallBackInterface();

    // 通过MO_Code进行交互，立即获取数据
    bool GetVal_ByMOCode(int MO_Code, int Dest, bool (*func)(void *param));

    // 通过YANG_Code直接获取ConfD的CDB数据库中的数据
    bool GetVal_ByYANGCode(int Yang_Code, bool (*func)(void *param));
};

#endif