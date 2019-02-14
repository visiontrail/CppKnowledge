
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

message(${PROJECT_SOURCE_DIR}/libhello)
message(${INCLUDE_PATHS1})
message(${INCLUDE_PATHS2})

add_executable(CmakeLearn3 ${APP_SRC})
target_link_libraries(CmakeLearn3 libhello)
target_link_libraries(CmakeLearn3 calc)
