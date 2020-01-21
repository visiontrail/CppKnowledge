#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"

#define FONTSIZE 10

// 打印最开始执行时候的Logo
int PrintMenuOS()
{
    int i, j;
    char data_M[FONTSIZE][FONTSIZE] =
        {
            "          ",
            "  CertUs  ",
            "   NET    ",
            "  ******  ",
            "  ******  ",
            "   OAM    ",
            " CLI_Demo ",
            " *Ver1.0* ",
            " *      * ",
            "          "};
    char data_e[FONTSIZE][FONTSIZE] =
        {
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          "};
    char data_n[FONTSIZE][FONTSIZE] =
        {
            "          ",
            "   ****   ",
            "  *    *  ",
            " *      * ",
            " *      * ",
            " *      * ",
            " *      * ",
            "  *    *  ",
            "   ****   ",
            "          "};
    char data_u[FONTSIZE][FONTSIZE] =
        {
            "          ",
            "     *    ",
            "   *   *  ",
            "  *     * ",
            "  ******* ",
            "  *     * ",
            "  *     * ",
            "  *     * ",
            "  *     * ",
            "          "};
    char data_O[FONTSIZE][FONTSIZE] =
        {
            "          ",
            "  *    *  ",
            " ***  *** ",
            " * *  * * ",
            " * *  * * ",
            " *  **  * ",
            " *      * ",
            " *      * ",
            " *      * ",
            "          "};
    char data_S[FONTSIZE][FONTSIZE] =
        {
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          "};

    for (i = 0; i < FONTSIZE; i++)
    {
        for (j = 0; j < FONTSIZE; j++)
        {
            printf("%c", data_M[i][j]);
        }
        for (j = 0; j < FONTSIZE; j++)
        {
            printf("%c", data_e[i][j]);
        }
        for (j = 0; j < FONTSIZE; j++)
        {
            printf("%c", data_n[i][j]);
        }
        for (j = 0; j < FONTSIZE; j++)
        {
            printf("%c", data_u[i][j]);
        }
        for (j = 0; j < FONTSIZE; j++)
        {
            printf("%c", data_O[i][j]);
        }
        for (j = 0; j < FONTSIZE; j++)
        {
            printf("%c", data_S[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int Quit(int argc, char *argv[])
{
    exit(0);
}

int Time(int argc, char *argv[])
{
    time_t tt;
    struct tm *t;
    tt = time(NULL);
    t = localtime(&tt);
   
    /*
    for (int i = 0; i < argc; i++)
    {
        printf("Time the argv is %s\n", argv[i]);
    }
    */

    printf("time:%d:%d:%d:%d:%d:%d\n", t->tm_year + 1900, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}

int main()
{
    PrintMenuOS();
    // 将命令行头改为OAM_CMD
    SetPrompt("OAM_CMD>>");
    // 将命令与函数对应关系添加到一个全局链表当中
    MenuConfig("version", "MenuOS V1.0(Based on Linux 3.18.6)", NULL);
    MenuConfig("quit", "Quit from MenuOS", Quit);
    MenuConfig("time", "Show System Time", Time);

    // 开始执行命令行程序
    ExecuteMenu();
}
