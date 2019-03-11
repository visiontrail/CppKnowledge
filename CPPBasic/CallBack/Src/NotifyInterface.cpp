#include "NotifyInterface.h"

std::map<int, bool (*)(void *)> NotifyInterface::NotifyLogic;
/*
 * 如果Boss订阅了某一个消息，那么在某个时刻，Employee会主动向Boss发起通知
*/
bool NotifyInterface::SetNotify_ByMOCode(int MO_Code, bool (*func)(void *param))
{
    cout << "add " << MO_Code << endl;
    NotifyLogic.insert(pair<int, bool (*)(void *)>(MO_Code, func));
}

/*
 * 根据不同的MO_Code，通知给Boss
*/
bool NotifyInterface::NotifySubScriber(int MO_Code, void *param)
{
    map<int, bool (*)(void *)>::iterator iter;

    iter = NotifyLogic.find(MO_Code);
    if (iter != NotifyLogic.end())
    {
        iter->second(param);
    }
    else
    {
        cout << "Do not Find" << endl;
    }
}

NotifyInterface::NotifyInterface()
{
}

NotifyInterface::~NotifyInterface()
{
}