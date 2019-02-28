set(EXECUTABLE_OUTPUT_PATH ${CmakeBase_BINARY_DIR})

# 添加可执行文件编译和输出路径
add_executable(PThreadBase Pthread_Base.c)
# 为这个项目添加它需要的静态依赖库
target_link_libraries(PThreadBase pthread)


# 添加可执行文件编译和输出路径
add_executable(PThreadBase2 Pthread_Base2.c)
# 为这个项目添加它需要的静态依赖库
target_link_libraries(PThreadBase2 pthread)


# 添加可执行文件编译和输出路径
add_executable(PThreadBase3 Pthread_Base3.c)
# 为这个项目添加它需要的静态依赖库
target_link_libraries(PThreadBase3 pthread)


