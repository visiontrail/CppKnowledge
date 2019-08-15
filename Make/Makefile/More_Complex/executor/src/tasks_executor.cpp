/***********************************************************************************************************************
 * Filename:      task_executor.cpp 
 *
 * Description:   This file contains implementation of tasks executor.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include "tasks_executor.h"
#include "netconf_client.h"


namespace exec
{

TasksExecutor* TasksExecutor::instance_ = nullptr;

void TasksExecutor::init()
{
   struct sigaction sa;

   sigemptyset(&sa.sa_mask);
   sa.sa_sigaction = signalHandler;
   sa.sa_flags = SA_SIGINFO;

   sigaction(SIGILL, &sa, nullptr);
   sigaction(SIGSEGV, &sa, nullptr);
   sigaction(SIGABRT, &sa, nullptr);
   sigaction(SIGTERM, &sa, nullptr);
   sigaction(SIGHUP, &sa, nullptr);
}

void TasksExecutor::start()
{
   init();
   
   /* start logger */

   /* Start device manager */

   /* Start alarm & event manager */

   /* Start NetConf client */
   comm::NetconfClient::get_instance()->netconf_client_session_init();

   while (true)
   {
      pause();
   }
}

void TasksExecutor::signalHandler(int sigNum, siginfo_t* info, void* ptr)
{
   if (sigNum == SIGHUP)
   {
      // return;
   }

   /* Stop device manager */

   /* Stop alarm & event manager */

   delete TasksExecutor::get_instance();

   exit(0);
}

} // namespace exec
