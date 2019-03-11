/**********************************************************************
* 文件功能：一个启动一个后台运行线程
* 说明：
* 创建时间：2019-2-27
* 创建人：郭亮
**********************************************************************/
#include <pthread.h>


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
        printf("Create thread 1 failed");
    }

    status = pthread_create(&thread2, NULL, thread_routine, "thread 2");
    if (status != 0)
    {
        printf("Create thread 2 failed");
    }

    printf("Main Thread is waiting\n");
    
    pthread_exit(NULL);
}
