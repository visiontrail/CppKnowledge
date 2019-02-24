set(src hello.cpp)

# 添加输出路径
SET(LIBRARY_OUTPUT_PATH ${CmakeBase_BINARY_DIR})

# 添加要寻找的头文件目录
include_directories(../Inc)

# 添加静态库文件输出
add_library(hellolib ${src})