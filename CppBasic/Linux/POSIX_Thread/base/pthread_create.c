/*************************************************
* 文件功能：一个最为简单的创建POSIX线程的功能
* 创建时间：2019-2-27
* 创建人：郭亮
**************************************************/


#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    int i;
    for (i = 0; i < 20; i++)
    {
        printf("Thread says hi!\n");
        sleep(1);
    }
    return NULL;
}

int main(void)
{
    pthread_t mythread; // 线程ID，可以认为它是一个线程句柄

    /*
     * pthread_create 用法:
     * 参数1：
     * 参数2：
     * 参数3：
     * 参数4：
    */ 
    
    // 调用pthread_create则是真正建立了一个活动线程
    // 当第三个参数，这个函数被创建的线程回调，当return返回时，该线程自动退出
    if (pthread_create(&mythread, NULL, thread_function, NULL))
    {
        printf("error creating thread.");
        abort();
    }

    printf("Main Thread continue \n");

    // 以阻塞的方式等待mythread线程结束，当这个mythread结束后，将两个线程合并成为一个
    // 如果调用这个函数，主线程会中断（转向睡眠等待mythread线程执行结束）
    if (pthread_join(mythread, NULL))
    {
        printf("error joining thread.");
        abort();
    }
    
    printf("Main Thread now finish \n");
    //exit(0);
}