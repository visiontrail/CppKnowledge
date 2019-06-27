#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define DEFAULT_PORT 6666

in_addr_t IPtoInt(char *str_ip)
{
    in_addr_t addr;
    if (inet_aton(str_ip, &addr))
    {
    }
    return addr;
}

int main(int argc, char **argv)
{
    int serverfd, acceptfd;        /* 监听socket: serverfd,数据传输socket: acceptfd */
    struct sockaddr_in my_addr;    /* 本机地址信息 */
    struct sockaddr_in their_addr; /* 客户地址信息 */
    unsigned int sin_size, myport = 6666, lisnum = 10;

    // socket相当于一个普通文件打开操作,返回一个socket文件描述符
    // 参数一，protofamily：协议族，AF_INET(ipv4),AF_INET6(ipv6),AF_LOCAL等等
    // 参数二，type：socket类型，SOCK_STREAM(TCP)、SOCK_DGRAM(UDP)、SOCK_RAW、SOCK_PACKET、SOCK_SEQPACKET等等
    // 参数三，protocol：协议，IPPROTO_TCP、IPPTOTO_UDP、IPPROTO_SCTP、IPPROTO_TIPC
    if ((serverfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
    {
        perror("socket");
        return -1;
    }

    printf("socket ok %d \n", serverfd);
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(DEFAULT_PORT);
    my_addr.sin_addr.s_addr = IPtoInt("127.0.0.2");
    bzero(&(my_addr.sin_zero), 0);

    if (bind(serverfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("bind");
        return -2;
    }
    printf("bind ok \n");

    if (listen(serverfd, lisnum) == -1)
    {
        perror("listen");
        return -3;
    }
    printf("listen ok \n");

    fd_set client_fdset;  /*监控文件描述符集合*/
    int maxsock;          /*监控文件描述符中最大的文件号*/
    struct timeval tv;    /*超时返回时间*/
    int client_sockfd[5]; /*存放活动的sockfd*/
    int conn_amount = 0;  /*用来记录描述符数量*/
    char buffer[1024];
    int ret = 0;

    bzero((void *)client_sockfd, sizeof(client_sockfd));

    maxsock = serverfd;
    /*不断的查看是否有新的client连接；已连接的client是否有发送消息过来*/
    while (1)
    {

        FD_ZERO(&client_fdset);          /*初始化文件描述符号到集合*/
        FD_SET(serverfd, &client_fdset); /*加入服务器描述符*/

        tv.tv_sec = 30; /*30秒*/
        tv.tv_usec = 0;

        /* 把活动的句柄加入到文件描述符中 */
        for (int i = 0; i < 5; ++i)
        {
            /*程序中Listen中参数设为5,故i必须小于5*/
            if (client_sockfd[i] != 0)
            {
                FD_SET(client_sockfd[i], &client_fdset);
            }
        }

        /*select函数，根据返回值判断程序是否有异常*/
        ret = select(maxsock + 1, &client_fdset, NULL, NULL, &tv);

        if (ret < 0)
        {
            perror("select error!\n");
            break;
        }
        else if (ret == 0)
        {
            printf("timeout!\n");
            continue;
        }
        /*轮询各个(已连接上的client的)文件描述符有无可读(接收)数据，有就输出，没有或者异常时，关闭相应的client连接，并在集合里清理掉*/
        for (int i = 0; i < conn_amount; ++i)
        {
            /*FD_ISSET检查client_sockfd是否可读写，>0可读写*/
            if (FD_ISSET(client_sockfd[i], &client_fdset))
            {
                printf("start recv from client[%d]:\n", i);
                ret = recv(client_sockfd[i], buffer, 1024, 0);
                if (ret <= 0)
                {
                    printf("client[%d] close\n", i);
                    close(client_sockfd[i]);
                    FD_CLR(client_sockfd[i], &client_fdset);
                    client_sockfd[i] = 0;
                }
                else
                {
                    printf("recv from client[%d] :%s\n", i, buffer);
                }
            }
        }
        /*检查是否有新的连接，如果有，接收连接加入到client_sockfd中*/
        if (FD_ISSET(serverfd, &client_fdset))
        {
            /*接受连接*/
            struct sockaddr_in client_addr;
            size_t size = sizeof(struct sockaddr_in);
            int sock_client = accept(serverfd, (struct sockaddr *)(&client_addr), (unsigned int *)(&size));
            if (sock_client < 0)
            {
                perror("accept error!\n");
                continue;
            }
            /*把连接加入到文件描述符集合中*/
            if (conn_amount < 5)
            {
                client_sockfd[conn_amount++] = sock_client;
                bzero(buffer, 1024);
                strcpy(buffer, "this is server! welcome!\n");
                send(sock_client, buffer, 1024, 0);
                printf("new connection client[%d] %s:%d\n", conn_amount, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                bzero(buffer, sizeof(buffer));
                ret = recv(sock_client, buffer, 1024, 0);
                if (ret < 0)
                {
                    perror("recv error!\n");
                    close(serverfd);
                    return -1;
                }
                printf("recv : %s\n", buffer);
                //更新maxsock,因为下一次进入while循环调用时，需要传当前最大的fd值+1给select函数
                if (sock_client > maxsock)
                {
                    maxsock = sock_client;
                }
                else
                {
                    printf("max connections!!!quit!!\n");
                    break;
                }
            }
        }
    }

    //最后，把已连接上的clent的fd和server自身的fd都关闭
    for (int i = 0; i < 5; ++i)
    {
        if (client_sockfd[i] != 0)
        {
            close(client_sockfd[i]);
        }
    }

    close(serverfd);
    return 0;
}