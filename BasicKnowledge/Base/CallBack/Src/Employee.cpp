/*
 * 
*/

#include <stdlib.h>
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

#include "Employee.h"

using namespace std;

void Employee::thread_routine(void *arg)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Do something! %d\n", i);
        sleep(1);
    }
    Notify_WhenDoSomework();
}

bool Employee::Do_SomeWork(bool (*func)(void *param))
{
    int status;
    oam_subsysa_cellconfig cellcfg;
    pthread_t thread1;
    void (Employee::*pmf)(void *arg);

    cellcfg.cell_id = 1;
    cellcfg.nr_pci = 0;
    cellcfg.prts_enable = false;
    cellcfg.tag_mcc1 = 10;
    cellcfg.tag_mcc2 = 20;

    func((void *)&cellcfg);

    pmf = &Employee::thread_routine;
    status = pthread_create(&thread1, NULL, (void *(*)(void *))pmf, (void *)"thread1");
    if (status != 0)
    {
        printf("Create thread 1 failed");
    }

    return true;
}

// 当某些工作需要主动通知的时候
bool Employee::Notify_WhenDoSomework()
{
    cout << "When do other thing notify Boss" << endl;

    oam_subsysa_cellconfig cellcfg;

    cellcfg.cell_id = 1;
    cellcfg.nr_pci = 0;
    cellcfg.prts_enable = true;
    cellcfg.tag_mcc1 = 100;
    cellcfg.tag_mcc2 = 200;

    Secretary.NotifySubScriber(OAM_SUBSYSA_GETXXX, (void *)&cellcfg);
    return true;
}

Employee::Employee()
{
}

Employee::~Employee()
{
}
