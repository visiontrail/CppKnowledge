set(src linktable.c
        menu.c
        test.c    
)

add_executable(CmdLine02 ${src})
include_directories(../Inc)
set(EXECUTABLE_OUTPUT_PATH ${CmakeBase_BINARY_DIR})





