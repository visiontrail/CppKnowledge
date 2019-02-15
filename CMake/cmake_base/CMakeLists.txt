##
# Copyright 2015 Datang Mobile, Inc.
#
# created by Guoliang
# For auto generate unit test project's make file (linux: Makefile, windows: .sln).
##

cmake_minimum_required (VERSION 2.6)

project (Tutorial)

message("Project SOURCE_DIR is " ${Tutorial_SOURCE_DIR})
message("Project BINARY_DIR is " ${Tutorial_BINARY_DIR})

if(CMAKE_SYSTEM_NAME STREQUAL Windows)
	message("This OS is " ${CMAKE_SYSTEM_NAME} " The Define can be used in cross complie!")
elseif(CMAKE_SYSTEM_NAME STREQUAL Linux)
	message("This OS is " ${CMAKE_SYSTEM_NAME} " The Define can be used in cross complie!")
endif ()

set(PROJECT_FILE CmakeTry_1.cpp)
set(LIB_FILE hello.cpp)

add_library(libhello ${LIB_FILE})

add_executable(Tutorial ${PROJECT_FILE})
target_link_libraries(Tutorial libhello)
set_target_properties(libhello PROPERTIES OUTPUT_NAME "hello")
