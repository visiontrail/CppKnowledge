#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/*
 * 使用alarm函数，对系统信号SIGALRM进行设置：
 * 函数原型：unsigned int alarm（unsigned int seconds）
 * 特性：alarm函数后一次设定将取消前一次的设定，如果为0的话，系统则不再发送SIGALARM信号
*/

int count;
void sigalrm_func(int sig)
{
    count++;
    printf("alarm![%d]\n", count);

    alarm(10);
    printf("over\n");
    return;
}

int main(void)
{
    signal(SIGALRM, sigalrm_func); // step1:SIGALRM信号是系统信号，将该信号注册给一个处理函数
    alarm(10);                     // step2:启动这个信号量，时间为10秒
    printf("start frist sigalarm\n");

    while (1)
    {
        sleep(1);
        printf(".");
        fflush(stdout);
    }
}