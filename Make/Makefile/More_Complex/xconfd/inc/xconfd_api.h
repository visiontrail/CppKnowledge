/*
* @Copyright(C), CertusNet
* @file: xconfd.h
* @Version: 1.0
* @Date: 2018.11.29
* @brief : Declaration of external function
* @Others:  
* @History:  
*   1.Date:
*     Author:
*     Modification:
*   2.
*/
#ifndef __XCONFD_API_H__
#define __XCONFD_API_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <ctype.h>
#include <inttypes.h>
#include <assert.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define XCONFD_CODE(x)          1
#define XCONFD_OK       0
#define XCONFD_ERR      -1
#define XCONFD_VALIDATION_OK       0
#define XCONFD_VALIDATION_ERR      -1
#define XCONFD_VALIDATION_WARN     -3
#define XCONFD_ASSERT(E) assert(E)


#include "xconfd_yangvalue_api.h"
#include "xconfd_yangtree_api.h"

typedef void (*XCONFD_POLL_CB)(int fd, u_int32_t epoll_event, void *usr_cookie);
typedef int  (*XCONFD_POLL_ADD)(int fd, XCONFD_POLL_CB cb, u_int32_t poll_event, void *usr_cookie);
typedef void (*XCONFD_POLL_DEL)(int fd);
typedef void (*XCONFD_LOAD_FINISH)(void);
typedef void (*XCONFD_STARTED_CB)(void);
typedef void (*XCONFD_STOPPED_CB)(void);

typedef enum xconfd_option {
    XCONFD_OPT_DGB_LEVEL,
    XCONFD_OPT_MODULE_NAME,
    XCONFD_OPT_ADDR,
    XCONFD_OPT_IP,
    XCONFD_OPT_PORT,
    XCONFD_OPT_POLL_ADD_FUNC,
    XCONFD_OPT_POLL_DEL_FUNC,
    XCONFD_OPT_POLL_EVENT,
    XCONFD_OPT_LOAD_FINISH_FUNC,
    XCONFD_OPT_STARTED_FUNC,
    XCONFD_OPT_STOPPED_FUNC,
} XCONFD_OPT_T;

typedef void XCONFD_CTX_T;


#if XCONFD_CODE("App callback function definition")
/**
* @brief app config callback
* @param ctx--callback context; 
* @param yt--yangtree; 
* @param user--user data(app register)
* @retval XCONFD_OK; XCONFD_ERR
* @date: 2018-11-28
* @history:
* @others:
*/
typedef int (*XCONFD_CONFIG_CB) (XCONFD_CTX_T *ctx, XCONFD_YANGTREE_T *yt, void *user);
/**
* @brief app validate callback.
         reply validate result by xconfd_validate_reply(see below)
* @param ctx--callback context; 
* @param yt--yangtree; 
* @param user--user data(app register)
* @retval XCONFD_OK; XCONFD_ERR
* @date: 2018-11-28
* @history:
* @others:
*/
typedef int (*XCONFD_VALIDATE_CB) (XCONFD_CTX_T *ctx, XCONFD_YANGTREE_T *yt, void *user);
/**
* @brief app show callback.
         reply show result by xconfd_show_reply(see below)
* @param ctx--callback context;
* @param breakpoint--last breakpoint(app set); 
* @param user--user data(app register)
* @retval XCONFD_OK; XCONFD_ERR
* @date: 2018-11-28
* @history:
* @others:
*/
typedef int (*XCONFD_SHOW_CB) (XCONFD_CTX_T *ctx, XCONFD_YANGTREE_T *yt, void *breakpoint, void *user);
/**
* @brief app hook callback.
* @param ctx--callback context; 
* @param yt--yangtree; 
* @param user--user data(app register)
* @retval XCONFD_OK; XCONFD_ERR
* @date: 2019-03-25
* @history:
* @others:
*/
typedef int (*XCONFD_HOOK_CB) (XCONFD_CTX_T *ctx, XCONFD_YANGTREE_T *yt, void *user);
/**
* @brief app action callback.
         reply action result by xconfd_action_reply(see below)
* @param ctx--callback context; 
* @param yt--yangtree(action input data)
* @param user--user data(app register)
* @retval XCONFD_OK; XCONFD_ERR
* @date: 2018-11-28
* @history:
* @others:
*/

typedef int (*XCONFD_ACTION_CB) (XCONFD_CTX_T *ctx, XCONFD_YANGTREE_T *yt, void *user);
/**
* @brief app commond callback,apply to *.cli in confd
*        reply commond result by xconfd_action_reply(see below)
* @param ctx--callback context; 
* @param argc--the number of argv; 
* @param argv--param array;
* @param user--user data(app register)
* @retval XCONFD_OK; XCONFD_ERR
* @date: 2018-11-28
* @history:
* @others:
*/
typedef int (*XCONFD_COMMOND_CB) (XCONFD_CTX_T *ctx, const char* path, int argc, char **argv, void *user);
/**
* @brief app abort action callback.
* @param ctx--callback context; 
* @param user--user data(app register)
* @retval XCONFD_OK; XCONFD_ERR
* @date: 2018-11-28
* @history:
* @others:
*/
typedef int (*XCONFD_ABORT_CB) (XCONFD_CTX_T *ctx, void *user);
#endif

#if XCONFD_CODE("Base function")
/**
* @brief App inits all related resources of xconfd before registering callback.
* @param nil; 
* @retval nil
* @date: 2018-11-28
* @history:
* @others:
*/
void xconfd_init();
/**
* @brief App uninits all related resources of xconfd.
* @param nil; 
* @retval nil
* @date: 2018-11-28
* @history:
* @others:
*/
void xconfd_uninit();
/**
* @brief Start to run xconfd after registering callback.
* @param nil; 
* @retval nil
* @date: 2018-11-28
* @history:
* @others:
*/
void xconfd_start();
/**
* @brief Stop to run xconfd.
* @param nil; 
* @retval nil
* @date: 2018-11-28
* @history:
* @others:
*/
void xconfd_stop();
/**
* @brief Set options to xconfd.
* @param opt--option type.
* @param value--option value.
* @retval nil
* @date: 2018-12-07
* @history:
* @others:
*/
void xconfd_set_option(XCONFD_OPT_T opt, void *value);
#endif

#if XCONFD_CODE("App register callback ")
/**
* @brief App register container callback.
* @param callback--app callback.
* @param user--user data(delivery to app callback)
* @param leaf_path--register path(It must be absolutely path in yang file.)
* @param Variable parameter--leaf_paths,the last one must be null.
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others:
*/
int xconfd_reg_conf_container_cb(XCONFD_CONFIG_CB callback, void *user, const char *leaf_path,  .../*leafs*/);
/**
* @brief App register full container callback.
* @param callback--app callback.
* @param user--user data(delivery to app callback)
* @param path--register path(It must be absolutely path in yang file.)
* @param Variable parameter--leaf_paths,the last one must be null.
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others:
*/
int xconfd_reg_conf_full_cb(XCONFD_CONFIG_CB callback, void *user, const char *path,  .../*leafs*/);

/**
* @brief App register list callback.
* @param callback--app callback.
* @param user--user data(delivery to app callback)
* @param list_path--register list path(It must be absolutely path in yang file.)
* @param Variable parameter--leaf_paths,the last one must be null.
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 1)The trigger path must be under the same List, that is,
*           cannot subscribe different leafs belong to two different lists at the same time.
*         2)leafs(variable parameter) must be relative paths and under the current List.
*         3)KeyLeaf do not need regisiter��?
*/
int xconfd_reg_conf_list_cb(XCONFD_CONFIG_CB callback,XCONFD_CONFIG_CB callback_ex, void *user, const char *list_path, .../*leafs*/);
/**
* @brief App register validate callback.
* @param callback--app callback.
* @param user--user data(delivery to app callback)
* @param point--validate callpoint in yang file.
* @param Variable parameter--dependency list, dependencies defined in YANG module
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_reg_validate_cb(XCONFD_VALIDATE_CB callback, void *user, const char *point, .../*dependencies*/);

/**
* @brief App register action callback.
* @param act_cb--app callback is executed when the action is occurred.
* @param abrt_cb--app callback is executed when user interrupts action,e.g. Ctrl+c
* @param user--user data(delivery to app callback)
* @param point--action callpoint in yang file.
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_reg_action_cb(XCONFD_ACTION_CB act_cb, XCONFD_ABORT_CB abrt_cb, void *user, const char *point);
/**
* @brief App register commond callback.
* @param cmd_cb--app callback is executed when the commond is occurred.
* @param abrt_cb--app callback is executed when user interrupts action,e.g. Ctrl+c
* @param user--user data(delivery to app callback)
* @param point--action callpoint in cli file.
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_reg_command_cb(XCONFD_COMMOND_CB cmd_cb, XCONFD_ABORT_CB abrt_cb, void *user, const char *point);
/**
* @brief App register show callback.
* @param callback--app show callback 
* @param user--user data(delivery to app callback)
* @param point--show callpoint in yang file.
* @param pointpath--show callpoint path.
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_reg_show_cb(XCONFD_SHOW_CB callback, void *user, const char *point, const char *pointpath);

/**
* @brief App register hook callback.
* @param callback--app hook callback 
* @param user--user data(delivery to app callback)
* @param point--hook callpoint in yang file.
* @retval XCONFD_OK; XCONFD_ERR
* @date 2019-03-25
* @history:
* @others 
*/
int xconfd_reg_hook_cb(XCONFD_HOOK_CB callback, void *user, const char *point);

/**
* @brief App register notification stream name.
* @param stream--the name of stream 
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others report notification to the controller by netconf
*/
int xconfd_reg_notification(const char *stream);
/**
* @brief App register snmp trap.
* @param notiname--the name of stream 
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_reg_notification_snmp(const char *notiname);

#endif

#if XCONFD_CODE("Apps reply or send data to confd")
/**
* @brief Apps reply show-data to confd.It is called in app's show-callback.
* @param ctx--callback context
* @param yt--reply data(yangtree)
* @param breakpoint--user's breakpoint(multi screen display data)
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_show_reply(XCONFD_CTX_T *ctx, XCONFD_YANGTREE_T *yt, void *breakpoint);
/**
* @brief Apps reply hook status ok.
* @param ctx--callback context
* @retval XCONFD_OK
* @date 2019-04-25
* @history:
* @others
*/
int xconfd_hook_reply_ok(XCONFD_CTX_T *ctx);
/**
* @brief Apps reply hook status failure.
* @param ctx--callback context
* @param errfmt--user's error info
* @retval XCONFD_ERR
* @date 2019-04-25
* @history:
* @others
*/
int xconfd_hook_reply_error(XCONFD_CTX_T *ctx, const char *errfmt, ...);
/**
* @brief Apps reply validate-data to confd.It is called in app's validate-callback.
* @param ctx--callback context
* @param result-- XCONFD_VALIDATION_OK; XCONFD_VALIDATION_ERR;XCONFD_VALIDATION_WARN
* @param fmt--user's replied data
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_validate_reply(XCONFD_CTX_T *ctx, int result, const char *fmt, ...);
#define xconfd_validate_reply_ok(ctx)                    xconfd_validate_reply(ctx, XCONFD_VALIDATION_OK, NULL);
#define xconfd_validate_reply_warning(ctx, warnmsg, ...) xconfd_validate_reply(ctx, XCONFD_VALIDATION_WARN, warnmsg, ##__VA_ARGS__);
#define xconfd_validate_reply_error(ctx, errmsg, ...)    xconfd_validate_reply(ctx, XCONFD_VALIDATION_ERR, errmsg, ##__VA_ARGS__);
/**
* @brief Apps reply action-data to confd.It is called in app's action-callback.
* @param ctx--callback context
* @param yt--reply data(action output data)
* @param err--action result
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_action_reply(XCONFD_CTX_T *ctx, XCONFD_YANGTREE_T *yt, const char *errfmt, ...);
#define xconfd_action_reply_ok(ctx, yt) xconfd_action_reply(ctx, yt, NULL)
#define xconfd_action_reply_error(ctx, errmsg, ...) xconfd_action_reply(ctx, NULL, errmsg, ##__VA_ARGS__)

/**
* @brief Apps reply action-commond-data to confd.It is called in app's action-commond-data.
* @param argc--the count of args
* @param ppargs--reply data(action output data)
* @param err--action result
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_action_reply_command(XCONFD_CTX_T *ctx, int argc , char** ppargs, const char* err);

/**
* @brief Apps synchronously reply action-data to confd in action callback.
* @param ctx--callback context
* @param fmt--printf data
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others :this function is called in action callback before xconfd_action_reply is called.
*/
int xconfd_action_printf(XCONFD_CTX_T *ctx, const char *fmt, ...);

/**
* @brief Apps asynchronously reply action-data to confd.e.g. ping commond
* @param uid--user id(call xconfd_get_userId(ctx))
* @param fmt--printf data
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others :this function is called in app's pthread
*/
int xconfd_action_printf_ex(u_int32_t userID, const char *fmt, ...);

/**
* @brief Apps get user id in action callback.
* @param  ctx--callback context
* @retval user id
* @date 2018-11-28
* @history:
* @others :this function is called in action callback.
*/
u_int32_t xconfd_get_userID(XCONFD_CTX_T *ctx);


/**
* @brief App sends notification to confd.
* @param stream--the name of stream.
* @param yt--send data(yangtree)
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_send_notification(const char *stream, XCONFD_YANGTREE_T *yt);
/**
* @brief App sends trap to confd.
* @param notiname--the name of stream.
* @param binds--oid and data
* @param num--the count of binds
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_send_notification_snmp(const char *notiname, XCONFD_SNMP_OID_BIND_T *binds, int num);
#endif

#if XCONFD_CODE("App gets non-subscription-data from cdb, and all data is already in the database.")
/**
* @brief App gets yang tree from cdb. 
* @param ctx--callback context
* @param fmt--leaf absolutely path
* @retval XCONFD_YANGTREE_T*
* @date 2019-04-03
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_cdb_get_node(XCONFD_CTX_T * ctx, const char *fmt, ...);
#endif

#if XCONFD_CODE("Get data from vdb(committing data merge with cdb).")
/**
* @brief App gets yang leaf node(commit data merge with cdb) for validating. 
* @param ctx--callback context
* @param fmt--leaf absolutely path
* @retval XCONFD_YANGTREE_T*
* @date 2019-04-03
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_vdb_get_node(XCONFD_CTX_T * ctx, const char *fmt, ...);
#endif

#if XCONFD_CODE("Get and set data by mdb api interface.")
/**
* @brief App gets data from confd's database in transaction.
* @param ctx--callback context
* @param fmt--leaf absolutely path
* @retval XCONFD_YANGTREE_T *.
* @date 2018-11-28
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_mdb_get_tree(XCONFD_CTX_T *ctx, const char *fmt, ...);
/**
* @brief App sets data to confd's database in transaction
* @param ctx--callback context.
* @param yt--yangtree
* @retval XCONFD_OK; XCONFD_ERR
* @date 2018-11-28
* @history:
* @others 
*/
int xconfd_mdb_set_tree(XCONFD_CTX_T *ctx , XCONFD_YANGTREE_T* yt);
/**
* @brief App set elem data to confd's database in transaction
* @param ctx--callback context.
* @param yv--the element new value.
* @param fmt--the format of the element path
* @param Variable parameter
* @retval XCONFD_OK; XCONFD_ERR
* @date 2019-04-19
* @history:
* @others 
*/
int xconfd_mdb_set_elem(XCONFD_CTX_T *ctx, XCONFD_YANGVALUE_T *yv, const char *fmt, ...);
/**
* @brief App create data to confd's database in transaction
* @param ctx--callback context.
* @param fmt--the format of the created node path
* @param Variable parameter
* @retval XCONFD_OK; XCONFD_ERR
* @date 2019-04-19
* @history:
* @others 
*/
int xconfd_mdb_create(XCONFD_CTX_T *ctx, const char *fmt, ...);
/**
* @brief App delete data to confd's database by in transaction
* @param ctx--callback context.
* @param fmt--the format of the deleted node path
* @param Variable parameter
* @retval XCONFD_OK; XCONFD_ERR
* @date 2019-04-19
* @history:
* @others 
*/
int xconfd_mdb_delete(XCONFD_CTX_T *ctx, const char *fmt, ...);
#endif

#if XCONFD_CODE("commit configuration by northbound api interface.")
/**
* @brief App commit tree data to confd's database
* @param yt--yangtree
* @retval XCONFD_OK; XCONFD_ERR
* @date 2019-04-25
* @history:
* @others
*/
int xconfd_commit_tree(XCONFD_YANGTREE_T* yt);
/**
* @brief App commit value to confd's database
* @param yv--the element new value.
* @param fmt--the format of the element path
* @param Variable parameter
* @retval XCONFD_OK; XCONFD_ERR
* @date 2019-04-25
* @history:
* @others
*/
int xconfd_commit_value(XCONFD_YANGVALUE_T *yv, const char *fmt, ...);
/**
* @brief App commit create to confd's database
* @param fmt--the format of the created node path
* @param Variable parameter
* @retval XCONFD_OK; XCONFD_ERR
* @date 2019-04-25
* @history:
* @others
*/
int xconfd_commit_create(const char *fmt, ...);
/**
* @brief App commit delete to confd's database
* @param fmt--the format of the deleted node path
* @param Variable parameter
* @retval XCONFD_OK; XCONFD_ERR
* @date 2019-04-25
* @history:
* @others
*/
int xconfd_commit_delete(const char *fmt, ...);
#endif

#define xconfd_reg_conf_container_m(cb, xpath, ...) xconfd_reg_conf_container_cb(cb, NULL, xpath, ##__VA_ARGS__, NULL)
#define xconfd_reg_conf_full_m(cb, xpath, ...) xconfd_reg_conf_full_cb(cb, NULL, xpath, ##__VA_ARGS__, NULL)
#define xconfd_reg_conf_list_m(cb, xpath, ...) xconfd_reg_conf_list_cb(cb, NULL, NULL, xpath, ##__VA_ARGS__, NULL)
#define xconfd_reg_validate_m(cb, point, ...) xconfd_reg_validate_cb(cb, NULL, point, ##__VA_ARGS__, NULL)
#define xconfd_reg_action_m(act_cb, abrt_cb, point) xconfd_reg_action_cb(act_cb, abrt_cb, NULL, point)
#define xconfd_reg_command_m(cmd_cb, abrt_cb, point) xconfd_reg_command_cb(cmd_cb,  abrt_cb, NULL, point)
#define xconfd_reg_show_m(cb, point, xpath) xconfd_reg_show_cb(cb, NULL, point, xpath)
#define xconfd_reg_hook_m(cb, point) xconfd_reg_hook_cb(cb, NULL, point)


#ifdef __cplusplus
}
#endif

#endif //__XCONFD_H__


