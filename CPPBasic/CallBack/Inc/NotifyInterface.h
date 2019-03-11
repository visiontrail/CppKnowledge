#ifndef NOTIFYINTERFACE
#define NOTIFYINTERFACE

#include <stdlib.h>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

/*
 * 说明：
*/
class NotifyInterface
{
  private:
    static std::map<int, bool (*)(void *)> NotifyLogic; // 保存了MOCode对应的处理函数
  public:
    NotifyInterface();
    ~NotifyInterface();

    // 设置观察，在必要的时候，会得到通知
    bool SetNotify_ByMOCode(int MO_Code, bool (*func)(void *param));

    // 统一通知方法
    bool NotifySubScriber(int MO_Code, void *param);
};

#endif