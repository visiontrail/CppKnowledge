set(src Boss.cpp
        Employee.cpp
        CallbackInterface.cpp
        NotifyInterface.cpp
)

include_directories(../Inc)

# 添加可执行文件编译和输出路径
add_executable(CallBackTest ${src})
set(EXECUTABLE_OUTPUT_PATH ${CallBack_BINARY_DIR})

# 添加必要的依赖库文件
target_link_libraries(CallBackTest pthread)

