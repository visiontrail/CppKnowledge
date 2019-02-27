set(src Pthread_Base.c)

# 添加可执行文件编译和输出路径
add_executable(PThreadBase ${src})
set(EXECUTABLE_OUTPUT_PATH ${CmakeBase_BINARY_DIR})
