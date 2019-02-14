#cmake min version
cmake_minimum_required (VERSION 3.5)

#project name
project (make1)

#set output apth
set (EXECUTABLE_OUTPUT_PATH ./)

#header files
include_directories(./include)

#source file
add_executable (make1 ./src/main.c)
#link share lib
target_link_libraries (make1 /home/guoliang/Desktop/WorkSpace/Learn/GNU_Make/AutoMake03/lib/libcalc.so)