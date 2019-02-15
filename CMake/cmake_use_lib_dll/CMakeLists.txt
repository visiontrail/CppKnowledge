cmake_minimum_required(VERSION 2.8)

# 1、该项目利用cmake编译静态库并利用这个静态库编译进可执行文件中
# 2、该项目利用cmake使用已存在的静态库编译进可执行文件中
project(ProjUseLibDLL)

# 分别为不同的项目新建项目文件夹，让工程项目更加清晰

# 以下为在build目录和源码文件夹之间做了一个相当于映射关系的工作：
# 在build目录下新建了一个bin文件夹
# bin文件夹用于存放src文件夹下的CMakeLists生成的sln或者Makefile工程
add_subdirectory(src bin)
# 在build目录下新建了一个lib文件夹
# lib文件夹用于存放libhello文件夹下的CMakeLists生成的sln或者Makefile工程
add_subdirectory(libhello lib)

