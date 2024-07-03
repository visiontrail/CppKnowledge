######################################
#
######################################
#source file
#源文件，自动找所有.c和.cpp文件，并将目标定义为同名.o文件
  
#target you can change test to what you want
#目标文件名，输入任意你想要的执行文件名
TARGET  := func
TARGET2 := bind

BINDSOURCE = bind.cpp
FUNCTIONSOURCE = function.cpp
  
#compile and lib parameter
#编译参数
CC      := g++
LIBS    := 
LDFLAGS := 
DEFINES :=
INCLUDE := 
CFLAGS  := $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS)
  
  
#i think you should do anything here
#下面的基本上不需要做任何改动了
.PHONY : everything objs clean veryclean rebuild
  
everything : $(TARGET) $(TARGET2)
  
all : $(TARGET)
  
objs : $(OBJS)
  
rebuild: veryclean everything
                
clean :
	rm -fr *.so
	rm -fr *.o
	rm -fr $(TARGET) $(TARGET2)
    
veryclean : clean
	rm -fr $(TARGET) $(TARGET2)
  
$(TARGET2) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(BINDSOURCE)

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(FUNCTIONSOURCE)