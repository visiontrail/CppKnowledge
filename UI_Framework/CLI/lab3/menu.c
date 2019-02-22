/*********************************************************/
/*Copyright (C) Je-vie.com, SSE@USTC, 2017-Now
/*
/*  FILE NAME               :   menu.c
/*  AUTHOR                  :   liujinfu
/*  MODULE NAME             :   menu
/*  LANGUAGE                :   C
/*  DATE OF FIRST RELEASE   :   2017/10/08
/*  DESCRIPTION             :   this is a menu program
/*******************************************************/


#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

int menu();
int quit();

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

static tDataNode head[]=
{
    //初始化赋值  链表
    {"menu", "this is menu cmd!", menu, &head[1]},
    {"version", "menu program v2.0", NULL, &head[2]},
    {"quit", "quit from menu", quit, NULL}
};

int main()
{
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Please input a cmd number ->");
        scanf("%s",cmd);
        tDataNode *p = FindCmd(head, cmd);

        if(p == NULL)
        {
            printf("This is a wrong cmd!\n");
            continue;
        }

        printf("%s - %s\n", p->cmd, p->desc);

        if(p->handler != NULL)
        {
            p->handler();
        }
    }
}

int menu()
{
    ShowAllCmd(head);
    return 0;
}

int quit()
{
    exit(0);
}