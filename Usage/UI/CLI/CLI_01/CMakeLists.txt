CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(Cli_01)

# 添加要编译lib的目标文件为calc
set(src_file 
    linklist.c
    menu.c
)

add_executable(Cli_01 ${src_file})