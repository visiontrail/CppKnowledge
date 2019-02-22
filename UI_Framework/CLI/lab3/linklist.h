
//这是一个头文件

//数据结构的定义
typedef struct DataNode
{
	char * cmd;
	char * desc;
	int (*handler)(); 	//函数指针
	struct DataNode * next;
}tDataNode;
//方法声明
tDataNode * FindCmd(tDataNode * head, char * cmd);
int ShowAllCmd(tDataNode * head);