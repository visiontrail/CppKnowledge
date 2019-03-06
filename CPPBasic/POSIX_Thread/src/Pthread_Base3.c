/**********************************************************************
* 文件功能：通过互斥对象解决同时访问冲突域的问题
* 说明：但是这样会带来一个问题，就是死锁活锁问题，PThread_Base4给出解决方案
* 创建时间：2019-2-27
* 创建人：郭亮
**********************************************************************/

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int myglobal;

// mutex是一个互斥对象，即两个对象不能同时对同一个互斥对象加锁
pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;

// 当代码使用 malloc() 分配一个新的互斥对象时,以上的方法行不通
// 需要调用pthread_mutex_init()：
// 并同时使用pthread_mutex_destroy()消除

void *thread_function(void *arg)
{
    int i, j;


        for (i = 0; i < 20; i++)
    {
        // 当这个线程访问以下对象的时候，其他线程都会进入睡眠状态，等待此线程释放锁
        pthread_mutex_lock(&mymutex);
        j = myglobal;
        j = j + 1;
        printf(".");
        fflush(stdout);
        sleep(1);
        myglobal = j;
        pthread_mutex_unlock(&mymutex);
    }
    return NULL;
}
int main(void)
{
    pthread_t mythread;
    int i;
    if (pthread_create(&mythread, NULL, thread_function, NULL))
    {
        printf("error creating thread.");
        abort(); // 异常终止一个进程;
    }
    for (i = 0; i < 20; i++)
    {
        pthread_mutex_lock(&mymutex);
        // 还有一点需要注意，给这个变量进行+1处理，其实在有些编译器是会把它编译为一条机器指令的
        // 这就是所谓的原子操作，但是不要想当然，一切都要以最终编译的结果为准
        myglobal = myglobal + 1;
        pthread_mutex_unlock(&mymutex);
        printf("o");
        fflush(stdout);
        sleep(1);
    }
    if (pthread_join(mythread, NULL))
    {
        printf("error joining thread.");
        abort(); // 异常终止一个进程;
    }
    printf("\nmyglobal equals %d\n", myglobal);
    exit(0);
}