/*
 * 参考：https://blog.csdn.net/lell3538/article/details/53335231
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#define MYPORT 6666
#define BUFFER_SIZE 1024
char *SERVER_IP = "127.0.0.1";

typedef struct data_header
{
    char header1;
    int header2;
    char pad[3];
}header;


typedef struct tcp_content
{
    int data1;
    int data2;
}data;

typedef struct tcp_client_data
{
    header header;
    data data;
}tcp_data;


int main()
{
    int sock_cli = socket(AF_INET, SOCK_STREAM, 0);
    tcp_data send_data;
    char *sendbuf;
    struct sockaddr_in servaddr;

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(MYPORT);               // 服务器端口
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP); // 服务器ip

    send_data.header.header1 = 1;
    send_data.header.header2 = 2;
    send_data.data.data1 = 10;
    send_data.data.data2 = 20;

    printf("连接%s:%d,and linkid is %d\n", SERVER_IP, MYPORT, sock_cli);
    // 连接服务器，成功返回0，错误返回-1
    if (connect(sock_cli, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        exit(1);
    }
    printf("服务器连接成功\n");

    send(sock_cli, &send_data, sizeof(send_data), 0); // 发送

    return 0;
}