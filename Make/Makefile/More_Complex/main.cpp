/***********************************************************************************************************************
 * Filename:      main.cpp 
 *
 * Description:   This file contains implementation of main.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#include "tasks_executor.h"

int main(int argc, char **argv)
{
   exec::TasksExecutor::get_instance()->start();
   return 0;
}
