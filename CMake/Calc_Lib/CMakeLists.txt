# 添加要编译lib的目标文件为calc
set(src_file 
    calc.c
    print_hello.c
)

# 添加最后生成的文件为静态库文件
add_library(calc STATIC ${src_file})