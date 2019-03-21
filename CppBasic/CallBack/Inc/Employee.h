#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdlib.h>
#include "MO.h"
#include "NotifyInterface.h"

class Employee
{
private:
    NotifyInterface Secretary;

public:
    Employee();
    ~Employee();

    bool Do_SomeWork(bool (*func)(void *param));
    bool Notify_WhenDoSomework();
    void thread_routine(void *arg);

};


#endif