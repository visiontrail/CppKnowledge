set(src GenericAlg.cpp
           lambda.cpp
           STL_Lerarn.cpp
           string.cpp
           Vector_etc.cpp
)

# 添加可执行文件编译和输出路径
add_executable(stl_learn ${src})
set(EXECUTABLE_OUTPUT_PATH ${CmakeBase_BINARY_DIR})

include_directories(../inc)

# 添加依赖的库文件目录
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    link_directories(${CmakeBase_BINARY_DIR})
elseif(CMAKE_SYSTEM_NAME STREQUAL Linux)
    link_directories(${CmakeBase_BINARY_DIR})
endif ()
