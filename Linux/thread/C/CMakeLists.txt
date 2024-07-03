set(executable_output_path ${cmakebase_binary_dir})

# 添加可执行文件编译和输出路径
add_executable(pthreadbase pthread_create.c)
# 为这个项目添加它需要的静态依赖库
target_link_libraries(pthread_create pthread)


# 添加可执行文件编译和输出路径
add_executable(pthreadbase2 pthread_mutex.c)
# 为这个项目添加它需要的静态依赖库
target_link_libraries(pthread_mutex pthread)


# 添加可执行文件编译和输出路径
add_executable(pthreadbase3 pthread_no_mutex.c)
# 为这个项目添加它需要的静态依赖库
target_link_libraries(pthread_no_mutex pthread)


# 添加可执行文件编译和输出路径
add_executable(pthreadbase4 pthread_twothread.c)
# 为这个项目添加它需要的静态依赖库
target_link_libraries(pthread_twothread pthread)

