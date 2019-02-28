/**********************************************************************
* 文件功能：通过互斥对象解决同时访问冲突域的问题
* 说明：但是这样会带来一个问题，就是死锁活锁问题，PThread_Base4给出解决方案
* 创建时间：2019-2-27
* 创建人：郭亮
**********************************************************************/
#include <pthread.h>
#include "errors.h"


void *thread_routine(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        printf("Do something! %d\n", i);
        sleep(2);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;
    int status;

    status = pthread_create(&thread1, NULL, thread_routine, "thread 1");
    if (status != 0)
    {
        err_abort(status, "Create thread 1");
    }

    status = pthread_create(&thread2, NULL, thread_routine, "thread 2");
    if (status != 0)
    {
        err_abort(status, "Create thread 2");
    }
    
    pthread_exit(NULL);
}
