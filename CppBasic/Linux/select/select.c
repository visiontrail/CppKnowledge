#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

/*
 * 编译：gcc -o select select.c
 * 
 * 备注1：什么是fd
 * 经常在linux程序中看到×××fd，这个fd的全称是：file descriptor。要加深对linux中一切皆文件的理解：
 * - 例子1：比如一个Socket句柄，可以看做是一个文件，在socket上收发数据，相当于对一个文件进行读写
*/

int main()
{
    int keyboard;
    int ret, i;
    char c;
    fd_set readfd;
    struct timeval timeout;

    // 打开文件，获得这个文件的文件描述符（或称访问句柄也可以）
    keyboard = open("/dev/tty", O_RDONLY | O_NONBLOCK);

    assert(keyboard > 0);

    while (1)
    {
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        printf(".");
        fflush(stdout);

        FD_ZERO(&readfd);          // 将文件句柄清空
        FD_SET(keyboard, &readfd); // 在文件句柄中增加一个新的内容

        // select用于非阻塞读取文件描述符：当多个信号输入时，系统提供的select函数来实现多路复用输入输出模型
        // 但是注意，以下这个例子，只有一路输入,可以查看socket\socket_select中接收多路socket客户端的实例
        /*
         * select原型:
         * int select(int maxfdp,fd_set *readfds,fd_set *writefds,fd_set *errorfds,struct timeval *timeout); 
         * 参数1 - maxfdp：集合中所有文件描述符的范围
         * 参数2 - *readfds：指向fd_set结构的指针，如果这个集合中有文件可读，select就会返回一个大于0的值
         * 参数3 - *writefds：指向fd_set结构的指针，关心文件是否可写
         * 参数4 - *errorfds：指向fd_set结构的指针，用来监视文件错误异常
         * 参数5 - *timeout：超时时间
         * 返回值 - int：正值表示准备就绪的描述符个数，负值表示select出错
        */
        ret = select(keyboard + 1, &readfd, NULL, NULL, &timeout);

        printf(".");
        fflush(stdout);

        // select出错
        if (ret == -1)
        {
            perror("select error\n");
        }
        // 当select获取到了文件描述符
        else if (ret)
        {
            // 指定的文件描述符是否在该集合中
            if (FD_ISSET(keyboard, &readfd))
            {
                i = read(keyboard, &c, 1);
                if ('\n' == c)
                    continue;
                printf("The input is %c\n", c);
                if ('q' == c)
                    break;
            }
        }
        else if (ret == 0)
        {
            printf("time out\n");
        }
            
    }
    return 0;
}