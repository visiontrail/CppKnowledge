/***************************************************************************************
 * 环境：Ubuntu + GCC
 * 执行的参数为想要创建管道的程序序列，参数任意长度，且只能是程序
 * 执行后会为参数中指定的程序分别创建线程并执行
 * 参数中的程序在执行之前会为其创建好合适的管道
 ***************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/*
 * description: 创建管道并执行进程
 * parameter:   想要创建管道并执行的进程
 * return:      void
 */
void main(int argc,char* argv[])
{
    // 参数中至少有两个进程才可以创建管道并执行
    if(argc < 3){
        fprintf(stderr,"At least two processes being needed.");
        exit(1);
    }

    // 管道需要的文件描述符
    int fd[argc-2][2];
    
    // // 输出传递的参数
    // for(int i=0;i<argc;i++){
        // printf("argc:%d\targv:%s\n",i,argv[i]);
    // }
    
    // 循环创建管道并执行，但是最后一个进程的情况特殊，另外执行
    // 每次循环在当前对应的两个进程之间创建stdout-stdin管道，并执行前一个程序
    for(int i=0;i<argc-2;i++){
        // 创建一个管道
        if(pipe(fd[i]) == -1){
            /* perror:参数为字符串，作用为在输出参数中的字符串之后输出错误信息 */
            perror("Failed to create a pipe:");
            exit(i*10+2);
        }
        // fork出一个子进程
        switch(fork()){
            case -1:{
                perror("Failed to fork:");
                exit(i*10+3);
            }
            // 父进程的标准输出已建立管道连接，可以执行相应程序
            // 其中标准输出的管道另一端尚未和程序相连，但是这个进程的工作已经完成
            // 如果此进程是第一个程序，那么不用创建标准输入的管道
            // 如果此进程是中间的程序，那么标准输入在上一次循环中已创建
            default:{/* parent process */
                close(fd[i][0]);/* close read end */
                dup2(fd[i][1],fileno(stdout));/* set stdout as write end */
                close(fd[i][1]);/* close useless copy of write end */
                if(execlp(argv[i+1],argv[i+1],NULL) == -1)
                    perror("Failed to execute parameter1:\n");
                exit(i*10+4);
            }
            // 子进程只创建一半管道，即其标准输入和前面的程序的标准输出管道连接
            // 如果不是最后一个程序，那么下一次循环此进程将会作为父进程
            case 0:{/* child process */
                close(fd[i][1]);/* close write end */
                dup2(fd[i][0],fileno(stdin));/* set stdin as read end */
                close(fd[i][0]);/* close useless copy of read end */
            }
        }
    }
    // 最后一个程序不需要创建stdout的相关管道，所以直接执行
    if(execlp(argv[argc-1],argv[argc-1],NULL) == -1)
        perror("Failed to execute parameter1:\n");
}