/***********************************************************************************************************************
 * Filename:      netconf_client.cpp
 *
 * Description:   This file contains implementation of xconfd agent alarm.
 *
 * History:       2019-08-12 20:00:10
***********************************************************************************************************************/

#include "ssh_client.h"


namespace comm
{
SshClient *SshClient::instance_ = new SshClient;

SshClient::SshClient()
{
}

SshClient::~SshClient()
{
}

void SshClient::ssh_client_init()
{

}

} // namespace comm
