
/**************************************************************************************************/
/*  FILE NAME             :  menu.c                                                               */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2019/2/24                                                            */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"
#include "menu.h"

tLinkTable *head = NULL;
int Help(); // Help的函数声明
int Quit();

#define CMD_MAX_LEN 1024
#define CMD_MAX_ARGV_NUM 32
#define DESC_LEN 1024
#define CMD_NUM 10

char prompt[CMD_MAX_LEN] = "Input Cmd >";

/* data struct and its operations 
* 保存系统支持的命令的链表节点
* 包含命令名称、命令描述、要执行命令的函数指针
*/
typedef struct DataNode
{
    tLinkTableNode *pNext;
    char *cmd;
    char *desc;
    int (*handler)(int argc, char *argv[]);
} tDataNode;

int SearchConditon(tLinkTableNode *pLinkTableNode, void *arg)
{
    char *cmd = (char *)arg;
    tDataNode *pNode = (tDataNode *)pLinkTableNode;
    if (strcmp(pNode->cmd, cmd) == 0)
    {
        return SUCCESS;
    }
    return FAILURE;
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode *FindCmd(tLinkTable *head, char *cmd)
{
    tDataNode *pNode = (tDataNode *)GetLinkTableHead(head);
    while (pNode != NULL)
    {
        if (!strcmp(pNode->cmd, cmd))
        {
            return pNode;
        }
        pNode = (tDataNode *)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
    }
    return NULL;
}

/* show all cmd in listlist */
// Help函数调用，打印全局链表中所有的命令内容
int ShowAllCmd(tLinkTable *head)
{
    tDataNode *pNode = (tDataNode *)GetLinkTableHead(head);
    while (pNode != NULL)
    {
        printf("    * %s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode *)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
    }
    return 0;
}

// 打印Help函数中的所有内容
int Help(int argc, char *argv[])
{
    ShowAllCmd(head);
    return 0;
}

int SetPrompt(char *p)
{
    if (p == NULL)
    {
        return 0;
    }
    strcpy(prompt, p);
    return 0;
}

/* add cmd to menu 
*  添加命令与函数之间的关系
* 参数一：命令名称
* 参数二：命令描述
* 参数三：函数指针
*/
int MenuConfig(char *cmd, char *desc, int (*handler)())
{
    // 新建一个DataNode，用于保存系统支持的命令
    tDataNode *pNode = NULL;

    // 如果用于保存所有命令的链表为空，则新建一个链表头
    if (head == NULL)
    {
        head = CreateLinkTable();
        pNode = (tDataNode *)malloc(sizeof(tDataNode));
        pNode->cmd = "help";
        pNode->desc = "Menu List";
        pNode->handler = Help; // 将Help的函数指针赋给全局链表
        AddLinkTableNode(head, (tLinkTableNode *)pNode);
    }

    // 为pNode分配空间
    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = cmd;
    pNode->desc = desc;
    pNode->handler = handler;
    AddLinkTableNode(head, (tLinkTableNode *)pNode);
    return 0;
}

/* Menu Engine Execute */
// 主函数调用，等待以及处理用户输入的命令
int ExecuteMenu()
{
    /* cmd line begins */
    // 命令行程序开始
    while (1)
    {
        int argc = 0;
        char *argv[CMD_MAX_ARGV_NUM];
        char cmd[CMD_MAX_LEN];
        char *pcmd = NULL; // 接收用户输入的命令

        printf("%s", prompt);
        /* scanf("%s", cmd); */
        // 获取用户输入的值
        pcmd = fgets(cmd, CMD_MAX_LEN, stdin);
        if (pcmd == NULL)
        {
            printf("Please inter a cmd，“help” for check the cmd list\n");
            continue;
        }

        /* 将用户输入的内容转化为argc和argv */
        // argc表示用户输入的命令和参数数量
        // argv表示用户输入的内容
        pcmd = strtok(pcmd, " "); //切割字符串，将pcmd通过空格切分成子串
        while (pcmd != NULL && argc < CMD_MAX_ARGV_NUM)
        {
            argv[argc] = pcmd;
            argc++;
            pcmd = strtok(NULL, " ");
        }

        /*
        for (int i = 0; i < argc; i++)
        {
            printf("The argc%d and argv is %s\n", i, argv[i]);
        }
        */

        // argc为1的话，证明用户输入的仅有一条不带参数的命令
        if (argc == 1)
        {
            int len = strlen(argv[0]);   // 获取用户输入的命令长度
            *(argv[0] + len - 1) = '\0'; // 将用户输入的内容长度……？
            //printf("after progress is %s %d \n",argv[0],len);
        }

        // 检索用户输入的值是否在全局链表之中
        tDataNode *p = (tDataNode *)SearchLinkTableNode(head, SearchConditon, (void *)argv[0]);
        // 如果不在，则继续执行等待用户输入
        if (p == NULL)
        {
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc);
        // 如果对应的函数指针存储不为NULL，则执行该函数指针
        if (p->handler != NULL)
        {
            p->handler(argc, argv);
        }
    }
}
