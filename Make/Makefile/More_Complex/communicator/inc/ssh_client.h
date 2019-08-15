/***********************************************************************************************************************
 * Filename:      ssh_client.h
 *
 * Description:   This file contains definition of xconfd agent alarm.
 *
 * History:       2019-08-12 20:00:00
***********************************************************************************************************************/

#ifndef OAM_SSH_CLIENT_H_
#define OAM_SSH_CLIENT_H_

#include <iostream>
#include <libssh/libssh.h>
namespace comm
{

class SshClient
{
private:
    SshClient();
    ~SshClient();
    static SshClient *instance_;

public:
    static SshClient *get_instance()
    {
        return instance_;
    }

    void ssh_client_init();

};

} // namespace comm

#endif // OAM_SSH_CLIENT_H_
