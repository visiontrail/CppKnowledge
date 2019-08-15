/***********************************************************************************************************************
 * Filename:      netconf_client.cpp
 *
 * Description:   This file contains implementation of xconfd agent alarm.
 *
 * History:       2019-08-12 20:00:10
***********************************************************************************************************************/

#include "netconf_client.h"


namespace comm
{
NetconfClient *NetconfClient::instance_ = new NetconfClient;

NetconfClient::NetconfClient()
{
}

NetconfClient::~NetconfClient()
{
    nc_client_destroy();
}

void NetconfClient::netconf_client_session_init()
{
    struct nc_session *session;
    int ret = -1;
    // const char* public_key = "";
    // const char* private_key = "";

    nc_client_init();
    
    ret = nc_client_ssh_set_username("admin");
    if (-1 == ret)
    {
        exit(0);
    }
    std::cout << "nc_client_ssh_get_username is " << nc_client_ssh_get_username() << std::endl;

    // nc_client_ssh_set_auth_password_clb()

    session = nc_connect_ssh("172.21.6.91", 2022, NULL);
    if (session == NULL)
    {
        // ERROR(func_name, "Connecting to the %s:%d as user \"%s\" failed.", host, port, user);
    }
}

} // namespace comm
