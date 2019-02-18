
# 添加依赖的头文件目录
include_directories(../libhello)
include_directories(inc)
include_directories(../inc)

# 添加依赖的库文件目录
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 添加需要参与编译的文件，编译结果为可执行文件
add_executable(ProjUseLibDLL CmakeTry_1.cpp)

# 为这个项目添加它需要的静态依赖库
target_link_libraries(ProjUseLibDLL calc
                                    libhello
                                    Strdemo
)

# 为项目指定动态库
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    message("Windows build")
elseif(CMAKE_SYSTEM_NAME STREQUAL Linux)
    message("Linux build")
    target_link_libraries(ProjUseLibDLL 
    ${PROJECT_SOURCE_DIR}/lib/libcalc2.so)
endif ()



set(INCLUDE_PATHS1 inc)
set(INCLUDE_PATHS2 ../inc)
set(APP_SRC CmakeTry_1.cpp)

# 打印一些信息
message("Add library dir lib: " ${PROJECT_SOURCE_DIR}/lib)
message("Add include dir: " ${INCLUDE_PATHS1} " and" ${INCLUDE_PATHS2})
message("Will build file: " ${APP_SRC})