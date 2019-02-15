
set(INCLUDE_PATHS1 inc)
set(INCLUDE_PATHS2 ../inc)

# 为可执行文件添加需要编译的cpp文件
set(APP_SRC CmakeTry_1.cpp)

# 添加依赖的头文件目录
include_directories(../libhello)
include_directories(${INCLUDE_PATHS1})
include_directories(${INCLUDE_PATHS2})

# 添加依赖的库文件目录
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 设置一个第三方动态库
#add_library(calc2 SHARED IMPORTED)
# 设置第三方动态库属性（存储位置）
#set_target_properties(calc2  PROPERTIES IMPORTED_LOCATION lib/calc2.dll)

# 打印一些信息
message("Add library dir lib: " ${PROJECT_SOURCE_DIR}/lib)
message("Add include dir: " ${INCLUDE_PATHS1} " and" ${INCLUDE_PATHS2})
message("Will build file: " ${APP_SRC})

# 添加需要参与编译的文件，编译结果为可执行文件
add_executable(ProjUseLibDLL ${APP_SRC})

# 为这个项目添加它需要的静态依赖库
target_link_libraries(ProjUseLibDLL calc
                                    libhello
)

# 为项目指定动态库
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    message("Windows build")
elseif(CMAKE_SYSTEM_NAME STREQUAL Linux)
    message("Linux build")
    target_link_libraries(ProjUseLibDLL 
    ${PROJECT_SOURCE_DIR}/lib/libcalc2.so)
endif ()
