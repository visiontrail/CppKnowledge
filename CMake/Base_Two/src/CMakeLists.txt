
set(INCLUDE_PATHS1 inc)
set(INCLUDE_PATHS2 ../inc)

set(APP_SRC CmakeTry_1.cpp)

include_directories(../libhello)
include_directories(${INCLUDE_PATHS1})
include_directories(${INCLUDE_PATHS2})

message(${PROJECT_SOURCE_DIR}/libhello)
message(${INCLUDE_PATHS1})
message(${INCLUDE_PATHS2})

add_executable(CmakeLearn3 ${APP_SRC})
target_link_libraries(CmakeLearn3 libhello)
