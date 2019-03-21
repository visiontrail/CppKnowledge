# 如果不希望automake工具检查README\Changelog等文件，添加这个
AUTOMAKE_OPTIONS=foreign
# 表示要编译出来的最终的动态库名字,必须是la,据说是GNU的规定
lib_LTLIBRARIES=libcalc.la

# 添加需要参与编译的文件
libcalc_la_SOURCES=calc.c
include_HEADERS=calc.h