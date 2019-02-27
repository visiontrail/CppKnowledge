set(src Pthread_Base.c)

# 添加可执行文件编译和输出路径
add_executable(PThreadBase ${src})
set(EXECUTABLE_OUTPUT_PATH ${CmakeBase_BINARY_DIR})

# 为这个项目添加它需要的静态依赖库
target_link_libraries(PThreadBase pthread)

set(src2 Pthread_Base2.c)

# 添加可执行文件编译和输出路径
add_executable(PThreadBase2 ${src2})
set(EXECUTABLE_OUTPUT_PATH ${CmakeBase_BINARY_DIR})

# 为这个项目添加它需要的静态依赖库
target_link_libraries(PThreadBase2 pthread)
