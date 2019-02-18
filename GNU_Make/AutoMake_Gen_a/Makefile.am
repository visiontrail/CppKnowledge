# 如果不希望automake工具检查README\Changelog等文件，添加这个
AUTOMAKE_OPTIONS=foreign
# 表示要编译出来的最终的动态库名字,必须是la,据说是GNU的规定
lib_LTLIBRARIES=libsma.la

# 添加需要参与编译的文件
libsma_la_SOURCES = \
                src/calc.c  \
                src/stringHelper.c

include_HEADERS = \
                inc/calc.h \
                inc/stringHelper.h