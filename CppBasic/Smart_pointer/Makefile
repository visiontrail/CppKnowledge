######################################
#
######################################
#source file
#源文件，自动找所有.c和.cpp文件，并将目标定义为同名.o文件
SOURCE1  := $(wildcard *.cpp)
SOURCE2  := $(wildcard ./src/*.cpp)
OBJS1    := $(patsubst %.cpp,%.o,$(SOURCE1))
OBJS2    := $(patsubst %.cpp,%.o,$(SOURCE2))
  
#target you can change test to what you want
#目标文件名，输入任意你想要的执行文件名
TARGET  := main
  
#compile and lib parameter
#编译参数
CC      := gcc
LIBS    := -lstdc++
LDFLAGS := 
DEFINES := 
INCLUDE := -I./inc
CFLAGS  := $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS)
  
  
#i think you should do anything here
#下面的基本上不需要做任何改动了
.PHONY : everything objs clean veryclean rebuild
  
everything : $(TARGET)
  
all : $(TARGET)
  
objs : $(OBJS1) $(OBJS2)
  
rebuild: veryclean everything
                
clean :
	rm -fr *.so
	rm -fr *.o
    
veryclean : clean
	rm -fr $(TARGET)
  
$(TARGET) : $(OBJS1) $(OBJS2)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS1) $(OBJS2) $(LDFLAGS) $(LIBS)