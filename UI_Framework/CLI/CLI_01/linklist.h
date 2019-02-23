
//这是一个头文件

//数据结构的定义
typedef struct DataNode
{
	char * cmd;
	char * desc;
	int (*handler)(); 	//函数指针
	struct DataNode * next;
}tDataNode;

// 查找命令
tDataNode * FindCmd(tDataNode * head, char * cmd);
// 显示全部命令
int ShowAllCmd(tDataNode * head);