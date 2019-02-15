include_directories(inc)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(ProjUseSharedLib main.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
    message("Linux build with dll " ${PROJECT_SOURCE_DIR}/lib)

    #target_link_libraries(ProjUseSharedLib 
    #${PROJECT_SOURCE_DIR}/lib/ProjUseLibDLL.so)
    target_link_libraries(ProjUseSharedLib 
    ${PROJECT_SOURCE_DIR}/lib/libcalc2.so)


endif ()