/***********************************************************************************************************************
 * Filename:      netconf_client.h
 *
 * Description:   This file contains definition of xconfd agent alarm.
 *
 * History:       2019-08-12 20:00:00
***********************************************************************************************************************/

#ifndef OAM_NETCONF_CLIENT_H_
#define OAM_NETCONF_CLIENT_H_

#include <iostream>
#include <libssh/libssh.h>
#include "xconfd_agent.h"
#include "libnetconf/session_client.h"

namespace comm
{

class NetconfClient
{
private:
    NetconfClient();
    ~NetconfClient();
    static NetconfClient *instance_;

public:
    static NetconfClient *get_instance()
    {
        return instance_;
    }

    void netconf_client_session_init();

};

} // namespace comm

#endif // OAM_NETCONF_CLIENT_H_
