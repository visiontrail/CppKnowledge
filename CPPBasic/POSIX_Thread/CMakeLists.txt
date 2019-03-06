##
# Copyright 2019 Guoliang.
#
# created by Guoliang
# auto generate project's make file (linux: Makefile, windows: .sln).
##

cmake_minimum_required (VERSION 2.6)

# 添加项目文件
project(Pthread_base)

if(CMAKE_SYSTEM_NAME STREQUAL Windows)
	message(FATAL_ERROR "++ This OS is " ${CMAKE_SYSTEM_NAME} " The Program CAN NOT cross complie! ++")
elseif(CMAKE_SYSTEM_NAME STREQUAL Linux)
	message("++ This OS is " ${CMAKE_SYSTEM_NAME} " The Define can be used in cross complie!")
endif ()

# 添加子文件夹
ADD_SUBDIRECTORY(src)

