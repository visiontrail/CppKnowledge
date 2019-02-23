set(src MainApp.cpp)

add_executable(MainApp ${src})

include_directories(../Inc)
include_directories(../../HelloLib/Inc)

# 添加依赖的库文件目录
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    message("Windows add Link Dir is" ${CmakeBase_BINARY_DIR})
    link_directories(${CmakeBase_BINARY_DIR})
elseif(CMAKE_SYSTEM_NAME STREQUAL Linux)
    link_directories(${CmakeBase_BINARY_DIR})
endif ()

# 为这个项目添加它需要的静态依赖库
target_link_libraries(MainApp hellolib)