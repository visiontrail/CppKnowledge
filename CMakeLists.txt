cmake_minimum_required(VERSION 3.8)
project(CPP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Class_Learn1/Bank_Acount.cpp
        Class_Learn1/Bank_Acount.h
        Class_Learn1/Sales_data.cpp
        Class_Learn1/Sales_data.h
        Class_Learn1/Screen.cpp
        Class_Learn1/Screen.h
        Class_Learn1/stdafx.cpp
        Class_Learn1/stdafx.h
        Class_Learn1/StrVec.cpp
        Class_Learn1/StrVec.h
        Class_Learn1/targetver.h
        Class_Learn1/Window_Mgr.cpp
        Class_Learn1/Window_Mgr.h
        CPPBasic/array.cpp
        CPPBasic/auto.cpp
        CPPBasic/const.cpp
        CPPBasic/CPPBasic.cpp
        CPPBasic/CPPBasic.h
        CPPBasic/function.cpp
        CPPBasic/stdafx.cpp
        CPPBasic/stdafx.h
        CPPBasic/targetver.h
        Smart_pointer/Smart_pointer.cpp
        Smart_pointer/smart_pointer.h
        Smart_pointer/stdafx.cpp
        Smart_pointer/stdafx.h
        Smart_pointer/targetver.h
        STL_Lerarn/GenericAlg.cpp
        STL_Lerarn/GenericAlg.h
        STL_Lerarn/lambda.cpp
        STL_Lerarn/Lambda.h
        STL_Lerarn/stdafx.cpp
        STL_Lerarn/stdafx.h
        STL_Lerarn/STL_Learn.h
        STL_Lerarn/STL_Lerarn.cpp
        STL_Lerarn/string.cpp
        STL_Lerarn/String_l.h
        STL_Lerarn/targetver.h
        STL_Lerarn/Vector_etc.cpp
        STL_Lerarn/Vector_etc.h)

add_executable(CPP ${SOURCE_FILES})