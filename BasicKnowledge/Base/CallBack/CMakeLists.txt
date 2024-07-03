##
# created by Guoliang
# auto generate project's make file (linux: Makefile, windows: .sln).
##

cmake_minimum_required (VERSION 2.6)

# 添加项目文件
project(CallBack)

# 打印一些必要信息
message("++ Start to generate MakeFile")
message("++ Project SOURCE_DIR is " ${CallBack_SOURCE_DIR})
message("++ Project BINARY_DIR is " ${CallBack_BINARY_DIR})

if(CMAKE_SYSTEM_NAME STREQUAL Windows)
	message("++ This OS is " ${CMAKE_SYSTEM_NAME} " The Define can be used in cross complie!")
elseif(CMAKE_SYSTEM_NAME STREQUAL Linux)
	message("++ This OS is " ${CMAKE_SYSTEM_NAME} " The Define can be used in cross complie!")
endif ()

# 添加子文件夹
ADD_SUBDIRECTORY(Src)

