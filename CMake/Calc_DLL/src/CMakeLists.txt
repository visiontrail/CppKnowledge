CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 添加最后生成的文件为动态库文件
ADD_LIBRARY(calc2 SHARED calc.c)

# 实验一下同时生成其他两种文件
ADD_LIBRARY(calc_lib calc.c)
ADD_EXECUTABLE(calc_exe calc.c)