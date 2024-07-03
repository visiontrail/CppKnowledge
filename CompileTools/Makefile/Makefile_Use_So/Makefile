######################################
#
######################################
#source file
#源文件，自动找所有.c和.cpp文件，并将目标定义为同名.o文件
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

# 编译时间
COMPILE_TIME = $(shell date +"%Y-%M-%d %H:%M:%S")
CFLAGS += "\"$(COMPILE_TIME)\""

#target you can change test to what you want
#目标文件名，输入任意你想要的执行文件名
TARGET  := main

#compile and lib parameter
#编译参数
CC      := gcc
LIBS    := -lcalc2 -lstdc++
LDFLAGS := -Llib/
DEFINES :=
INCLUDE := -I./inc
CFLAGS  := $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS)

#i think you should do anything here
#下面的基本上不需要做任何改动了
.PHONY : everything objs clean veryclean rebuild
  
everything : $(TARGET)
  
all : $(TARGET)
  
objs : $(OBJS)
  
rebuild: veryclean everything
                
clean :
	rm -fr *.so
	rm -fr *.o
    
veryclean : clean
	rm -fr $(TARGET)
  
$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)