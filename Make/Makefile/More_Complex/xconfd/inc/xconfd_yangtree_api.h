/*
* @Copyright(C), CertusNet
* @file: xconfd_yangtree_api.h
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

#ifndef __XCONFD_YANGTREE_API_H__
#define __XCONFD_YANGTREE_API_H__

#ifdef __cplusplus
extern "C"
{
#endif

#if XCONFD_CODE("Macro definition")

typedef void XCONFD_YANGTREE_T;

typedef enum xconfd_node_type {
    XCONFD_NODE_UNKNOW = 0,
    XCONFD_NODE_CONTAINER,
    XCONFD_NODE_LIST,
    XCONFD_NODE_LEAF,
    XCONFD_NODE_LEAF_LIST,
    XCONFD_NODE_NOTIFICATION,
    XCONFD_NODE_CHOICE,
    XCONFD_NODE_CASE,
    XCONFD_NODE_RPC,
    XCONFD_NODE_INPUT,
    XCONFD_NODE_OUTPUT,
} XCONFD_NODE_TYPE_T;

typedef enum xconfd_operation {
    XCONFD_OP_UNKNOW = 0,
    XCONFD_OP_NOCHANGE,
    XCONFD_OP_MODIFIED,
    XCONFD_OP_CREATE,
    XCONFD_OP_DELETE,
    XCONFD_OP_DELETED,
    XCONFD_OP_SET,
} XCONFD_OPERATION_T;

#endif

#if XCONFD_CODE("build yang tree api")

/**
* @brief app build yang tree node leaf-list.
* @param name--leaf-list node name
* @param vals--leaf-list yang value array
* @param nvals--number of yang value array
* @retval leaf-list node.
* @date 2018-12-13
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_yang_tree_new_leaf_list(char *name, XCONFD_YANGVALUE_T **vals, int nvals);

/**
* @brief app build yang tree node leaf.
* @param name--leaf node name
* @param val--leaf yang value
* @param kidx--key leaf index, 0 means non-key leaf, >=1 means key index
* @retval leaf node.
* @date 2018-12-13
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_yang_tree_new_leaf(char *name, XCONFD_YANGVALUE_T *val, int kidx);

/**
* @brief app add children of parent yang tree node.
* @param parent--parent yang tree node
* @param Variable parameter--child nodes, must end with NULL
* @retval parent yang tree node itself.
* @date 2018-12-13
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_yang_tree_add_children(XCONFD_YANGTREE_T *parent, ...);

/**
* @brief app append list entries to the list(only used for the yang node 'list').
* @param cur--current list entry which already in the current list
* @param Variable parameter--list entries, must end with NULL
* @retval the current list entry node itself.
* @date 2018-12-13
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_yang_tree_list_append(XCONFD_YANGTREE_T *cur, ...);

/**
* @brief app add sibling nodes to the current node.
* @param cur--current yang tree node
* @param Variable parameter--sibling yang tree nodes, must end with NULL
* @retval the current node.
* @date 2018-12-13
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_yang_tree_add_siblings(XCONFD_YANGTREE_T *cur, ...);

/**
* @brief app build list node with entries
* @param listname
* @param entries
* @retval the list node.
* @date 2019-04-17
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_yang_tree_build_list(const char *listname, ...);

/**
* @brief app build list entry
* @param node--the first child node of the entry
* @param Variable parameter--the remain child nodes
* @retval the entry node(pointer to first node).
* @date 2019-04-17
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_yang_tree_build_entry(XCONFD_YANGTREE_T *node, ...);

/**
* @brief app build yang tree node.
* @param ntype--yang tree node type
* @param name--yang tree node name
* @param Variable parameter--child yang tree nodes, must end with NULL
* @retval the new yang tree node.
* @date 2018-12-13
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_yang_tree_new_node(XCONFD_NODE_TYPE_T ntype, const char *name, ...);

#define args(...) ,##__VA_ARGS__
#define CONTAINER(name, ...)    xconfd_yang_tree_new_node(XCONFD_NODE_CONTAINER, (name) args(__VA_ARGS__), NULL)
#define NOTIFICATION(name, ...) xconfd_yang_tree_new_node(XCONFD_NODE_NOTIFICATION, (name) args(__VA_ARGS__), NULL)
#define INPUT(...)              xconfd_yang_tree_new_node(XCONFD_NODE_INPUT, "input" args(__VA_ARGS__), NULL)
#define OUTPUT(...)             xconfd_yang_tree_new_node(XCONFD_NODE_OUTPUT, "output" args(__VA_ARGS__), NULL)
#define RPC(...)                xconfd_yang_tree_new_node(XCONFD_NODE_RPC, "rpc" args(__VA_ARGS__), NULL)
#define LIST(name, ...)         xconfd_yang_tree_build_list((name) args(__VA_ARGS__), NULL)
#define LEAF(name, value)            xconfd_yang_tree_new_leaf((name), value, 0)
#define LEAF_LIST(name, vals, nvals) xconfd_yang_tree_new_leaf_list((name), vals, nvals)
#define KEY_LEAF(name, value, idx)   xconfd_yang_tree_new_leaf((name), value, idx)

#define ADD_CHILDREN(parent, ...) xconfd_yang_tree_add_children((parent) args(__VA_ARGS__), NULL)
#define ADD_SIBLINGS(cur, ...)    xconfd_yang_tree_add_siblings((cur) args(__VA_ARGS__), NULL)
#define LIST_APPEND(head, ...)    xconfd_yang_tree_list_append((head) args(__VA_ARGS__), NULL)
#define XENTRY(node, ...)          xconfd_yang_tree_build_entry((node) args(__VA_ARGS__), NULL)

#define KEY_IDX_BASE 1


/* macro to build yangtree with operation */
#define CONTAINER_WITH_OPERATION(name, op, ...)    xconfd_yang_tree_new_node_with_operation(XCONFD_NODE_CONTAINER, (op), (name) args(__VA_ARGS__), NULL)
#define LEAF_WITH_OPERATION(name, op, value)       xconfd_yang_tree_new_leaf_with_operation((name), (op), (value), 0)
#define ENTRY_WITH_OPERATION(op, node, ...)        xconfd_yang_tree_build_entry_with_operation((op), (node) args(__VA_ARGS__), NULL)

#endif

#if XCONFD_CODE("yang tree access api")
/**
* @brief debug yangtree
* @param yt--yangtree
* @date 2018-12-03
* @history:
* @others 
*/
void xconfd_yang_tree_dump(XCONFD_YANGTREE_T *yt);

/**
* @brief app gets value of yang tree node.
* @param leaf--yangtree leaf node
* @retval yang value,you can get value by using xconfd_get_*.
* @date 2018-12-03
* @history:
* @others 
*/
XCONFD_YANGVALUE_T *xconfd_yang_tree_get_value(XCONFD_YANGTREE_T *leaf);

const char *xconfd_yang_tree_get_value_string(XCONFD_YANGTREE_T *leaf);
unsigned char *xconfd_yang_tree_get_value_bufptr(XCONFD_YANGTREE_T *leaf);
unsigned int xconfd_yang_tree_get_value_bufsize(XCONFD_YANGTREE_T *leaf);
int8_t xconfd_yang_tree_get_value_int8(XCONFD_YANGTREE_T *leaf);
int16_t xconfd_yang_tree_get_value_int16(XCONFD_YANGTREE_T *leaf);
int32_t xconfd_yang_tree_get_value_int32(XCONFD_YANGTREE_T *leaf);
int64_t xconfd_yang_tree_get_value_int64(XCONFD_YANGTREE_T *leaf);
u_int8_t xconfd_yang_tree_get_value_uint8(XCONFD_YANGTREE_T *leaf);
u_int16_t xconfd_yang_tree_get_value_uint16(XCONFD_YANGTREE_T *leaf);
u_int32_t xconfd_yang_tree_get_value_uint32(XCONFD_YANGTREE_T *leaf);
u_int64_t xconfd_yang_tree_get_value_uint64(XCONFD_YANGTREE_T *leaf);
double xconfd_yang_tree_get_value_double(XCONFD_YANGTREE_T *leaf);
struct in_addr xconfd_yang_tree_get_value_ipv4(XCONFD_YANGTREE_T *leaf);
struct in6_addr xconfd_yang_tree_get_value_ipv6(XCONFD_YANGTREE_T *leaf);
int xconfd_yang_tree_get_value_bool(XCONFD_YANGTREE_T *leaf);
XCONFD_DATETIME_T xconfd_yang_tree_get_value_datatime(XCONFD_YANGTREE_T *leaf);
XCONFD_DATE_T xconfd_yang_tree_get_value_date(XCONFD_YANGTREE_T *leaf);
XCONFD_TIME_T xconfd_yang_tree_get_value_time(XCONFD_YANGTREE_T *leaf);
XCONFD_DURATION_T xconfd_yang_tree_get_value_duration(XCONFD_YANGTREE_T *leaf);
int32_t xconfd_yang_tree_get_value_enum(XCONFD_YANGTREE_T *leaf);
u_int32_t xconfd_yang_tree_get_value_bit32(XCONFD_YANGTREE_T *leaf);
u_int64_t xconfd_yang_tree_get_value_bit64(XCONFD_YANGTREE_T *leaf);
XCONFD_YANGVALUE_T **xconfd_yang_tree_get_value_list(XCONFD_YANGTREE_T *leaf);
unsigned char *xconfd_yang_tree_get_value_binary_ptr(XCONFD_YANGTREE_T *leaf);
unsigned int xconfd_yang_tree_get_value_binary_size(XCONFD_YANGTREE_T *leaf);
XCONFD_IPV4_PREFIX_T xconfd_yang_tree_get_value_ipv4prefix(XCONFD_YANGTREE_T *leaf);
XCONFD_IPV6_PREFIX_T xconfd_yang_tree_get_value_ipv6prefix(XCONFD_YANGTREE_T *leaf);
unsigned char *xconfd_yang_tree_get_value_hexstr_ptr(XCONFD_YANGTREE_T *leaf);
unsigned int xconfd_yang_tree_get_value_hexstr_size(XCONFD_YANGTREE_T *leaf);
XCONFD_IPV4_PREFIX_T xconfd_yang_tree_get_value_ipv4_plen(XCONFD_YANGTREE_T *leaf);
XCONFD_IPV6_PREFIX_T xconfd_yang_tree_get_value_ipv6_plen(XCONFD_YANGTREE_T *leaf);
char **xconfd_yang_tree_get_value_list_string(XCONFD_YANGTREE_T *leaf_list, int *size);
int8_t *xconfd_yang_tree_get_value_list_int8(XCONFD_YANGTREE_T *leaf_list, int *size);
int16_t *xconfd_yang_tree_get_value_list_int16(XCONFD_YANGTREE_T *leaf_list, int *size);
int32_t *xconfd_yang_tree_get_value_list_int32(XCONFD_YANGTREE_T *leaf_list, int *size);
int64_t *xconfd_yang_tree_get_value_list_int64(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int8_t *xconfd_yang_tree_get_value_list_uint8(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int16_t *xconfd_yang_tree_get_value_list_uint16(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int32_t *xconfd_yang_tree_get_value_list_uint32(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int64_t *xconfd_yang_tree_get_value_list_uint64(XCONFD_YANGTREE_T *leaf_list, int *size);
double *xconfd_yang_tree_get_value_list_double(XCONFD_YANGTREE_T *leaf_list, int *size);
struct in_addr *xconfd_yang_tree_get_value_list_ipv4(XCONFD_YANGTREE_T *leaf_list, int *size);
struct in6_addr *xconfd_yang_tree_get_value_list_ipv6(XCONFD_YANGTREE_T *leaf_list, int *size);
int *xconfd_yang_tree_get_value_list_bool(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_DATETIME_T *xconfd_yang_tree_get_value_list_datatime(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_DATE_T *xconfd_yang_tree_get_value_list_date(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_TIME_T *xconfd_yang_tree_get_value_list_time(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_DURATION_T *xconfd_yang_tree_get_value_list_duration(XCONFD_YANGTREE_T *leaf_list, int *size);
int32_t *xconfd_yang_tree_get_value_list_enum(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int32_t *xconfd_yang_tree_get_value_list_bit32(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int64_t *xconfd_yang_tree_get_value_list_bit64(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_BINARY_T *xconfd_yang_tree_get_value_list_binary(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_IPV4_PREFIX_T *xconfd_yang_tree_get_value_list_ipv4prefix(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_IPV6_PREFIX_T *xconfd_yang_tree_get_value_list_ipv6prefix(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_HEXSTR_T *xconfd_yang_tree_get_value_list_hexstr(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_IPV4_PREFIX_T *xconfd_yang_tree_get_value_list_ipv4_plen(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_IPV6_PREFIX_T *xconfd_yang_tree_get_value_list_ipv6_plen(XCONFD_YANGTREE_T *leaf_list, int *size);

/**
* @brief app gets old value of yang tree node.
* @param leaf--yangtree leaf node
* @retval yang old value,you can get value by using xconfd_get_*.
* @date 2018-12-03
* @history:
* @others 
*/
XCONFD_YANGVALUE_T *xconfd_yang_tree_get_old_value(XCONFD_YANGTREE_T *leaf);

const char *xconfd_yang_tree_get_old_value_string(XCONFD_YANGTREE_T *leaf);
unsigned char *xconfd_yang_tree_get_old_value_bufptr(XCONFD_YANGTREE_T *leaf);
unsigned int xconfd_yang_tree_get_old_value_bufsize(XCONFD_YANGTREE_T *leaf);
int8_t xconfd_yang_tree_get_old_value_int8(XCONFD_YANGTREE_T *leaf);
int16_t xconfd_yang_tree_get_old_value_int16(XCONFD_YANGTREE_T *leaf);
int32_t xconfd_yang_tree_get_old_value_int32(XCONFD_YANGTREE_T *leaf);
int64_t xconfd_yang_tree_get_old_value_int64(XCONFD_YANGTREE_T *leaf);
u_int8_t xconfd_yang_tree_get_old_value_uint8(XCONFD_YANGTREE_T *leaf);
u_int16_t xconfd_yang_tree_get_old_value_uint16(XCONFD_YANGTREE_T *leaf);
u_int32_t xconfd_yang_tree_get_old_value_uint32(XCONFD_YANGTREE_T *leaf);
u_int64_t xconfd_yang_tree_get_old_value_uint64(XCONFD_YANGTREE_T *leaf);
double xconfd_yang_tree_get_old_value_double(XCONFD_YANGTREE_T *leaf);
struct in_addr xconfd_yang_tree_get_old_value_ipv4(XCONFD_YANGTREE_T *leaf);
struct in6_addr xconfd_yang_tree_get_old_value_ipv6(XCONFD_YANGTREE_T *leaf);
int xconfd_yang_tree_get_old_value_bool(XCONFD_YANGTREE_T *leaf);
XCONFD_DATETIME_T xconfd_yang_tree_get_old_value_datatime(XCONFD_YANGTREE_T *leaf);
XCONFD_DATE_T xconfd_yang_tree_get_old_value_date(XCONFD_YANGTREE_T *leaf);
XCONFD_TIME_T xconfd_yang_tree_get_old_value_time(XCONFD_YANGTREE_T *leaf);
XCONFD_DURATION_T xconfd_yang_tree_get_old_value_duration(XCONFD_YANGTREE_T *leaf);
int32_t xconfd_yang_tree_get_old_value_enum(XCONFD_YANGTREE_T *leaf);
u_int32_t xconfd_yang_tree_get_old_value_bit32(XCONFD_YANGTREE_T *leaf);
u_int64_t xconfd_yang_tree_get_old_value_bit64(XCONFD_YANGTREE_T *leaf);
XCONFD_YANGVALUE_T **xconfd_yang_tree_get_old_value_list(XCONFD_YANGTREE_T *leaf);
unsigned char *xconfd_yang_tree_get_old_value_binary_ptr(XCONFD_YANGTREE_T *leaf);
unsigned int xconfd_yang_tree_get_old_value_binary_size(XCONFD_YANGTREE_T *leaf);
XCONFD_IPV4_PREFIX_T xconfd_yang_tree_get_old_value_ipv4prefix(XCONFD_YANGTREE_T *leaf);
XCONFD_IPV6_PREFIX_T xconfd_yang_tree_get_old_value_ipv6prefix(XCONFD_YANGTREE_T *leaf);
unsigned char *xconfd_yang_tree_get_old_value_hexstr_ptr(XCONFD_YANGTREE_T *leaf);
unsigned int xconfd_yang_tree_get_old_value_hexstr_size(XCONFD_YANGTREE_T *leaf);
XCONFD_IPV4_PREFIX_T xconfd_yang_tree_get_old_value_ipv4_plen(XCONFD_YANGTREE_T *leaf);
XCONFD_IPV6_PREFIX_T xconfd_yang_tree_get_old_value_ipv6_plen(XCONFD_YANGTREE_T *leaf);
char **xconfd_yang_tree_get_old_value_list_string(XCONFD_YANGTREE_T *leaf_list, int *size);
int8_t *xconfd_yang_tree_get_old_value_list_int8(XCONFD_YANGTREE_T *leaf_list, int *size);
int16_t *xconfd_yang_tree_get_old_value_list_int16(XCONFD_YANGTREE_T *leaf_list, int *size);
int32_t *xconfd_yang_tree_get_old_value_list_int32(XCONFD_YANGTREE_T *leaf_list, int *size);
int64_t *xconfd_yang_tree_get_old_value_list_int64(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int8_t *xconfd_yang_tree_get_old_value_list_uint8(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int16_t *xconfd_yang_tree_get_old_value_list_uint16(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int32_t *xconfd_yang_tree_get_old_value_list_uint32(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int64_t *xconfd_yang_tree_get_old_value_list_uint64(XCONFD_YANGTREE_T *leaf_list, int *size);
double *xconfd_yang_tree_get_old_value_list_double(XCONFD_YANGTREE_T *leaf_list, int *size);
struct in_addr *xconfd_yang_tree_get_old_value_list_ipv4(XCONFD_YANGTREE_T *leaf_list, int *size);
struct in6_addr *xconfd_yang_tree_get_old_value_list_ipv6(XCONFD_YANGTREE_T *leaf_list, int *size);
int *xconfd_yang_tree_get_old_value_list_bool(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_DATETIME_T *xconfd_yang_tree_get_old_value_list_datatime(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_DATE_T *xconfd_yang_tree_get_old_value_list_date(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_TIME_T *xconfd_yang_tree_get_old_value_list_time(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_DURATION_T *xconfd_yang_tree_get_old_value_list_duration(XCONFD_YANGTREE_T *leaf_list, int *size);
int32_t *xconfd_yang_tree_get_old_value_list_enum(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int32_t *xconfd_yang_tree_get_old_value_list_bit32(XCONFD_YANGTREE_T *leaf_list, int *size);
u_int64_t *xconfd_yang_tree_get_old_value_list_bit64(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_BINARY_T *xconfd_yang_tree_get_old_value_list_binary(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_IPV4_PREFIX_T *xconfd_yang_tree_get_old_value_list_ipv4prefix(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_IPV6_PREFIX_T *xconfd_yang_tree_get_old_value_list_ipv6prefix(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_HEXSTR_T *xconfd_yang_tree_get_old_value_list_hexstr(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_IPV4_PREFIX_T *xconfd_yang_tree_get_old_value_list_ipv4_plen(XCONFD_YANGTREE_T *leaf_list, int *size);
XCONFD_IPV6_PREFIX_T *xconfd_yang_tree_get_old_value_list_ipv6_plen(XCONFD_YANGTREE_T *leaf_list, int *size);

/**
* @brief free list array which get by xconfd_yang_tree_get_value_list_xxx
*  or xconfd_yang_tree_get_old_value_list_xxx.
* @param cur--vlist
* @date 2019-04-10
* @history:
* @others 
*/
void xconfd_yang_tree_free_list(void *vlist);

/**
* @brief app gets value from yang tree by path.
* @param cur--yangtree
* @param xpath--path(both relative path and absolute path).
                when it is NULL or ".", app can get current value.
* @retval yang value,you can get value by using xconfd_get_*.
* @date 2018-12-03
* @history:
* @others 
*/
XCONFD_YANGVALUE_T *xconfd_yang_tree_get_value_ex(XCONFD_YANGTREE_T *cur, const char *xpath);

/**
* @brief app gets old value from yang tree by path.
* @param cur--yangtree
* @param xpath--path(both relative path and absolute path).
                when it is NULL or ".", app can get current value.
* @retval yang value,you can get value by using xconfd_get_*.
* @date 2018-12-03
* @history:
* @others 
*/
XCONFD_YANGVALUE_T *xconfd_yang_tree_get_old_value_ex(XCONFD_YANGTREE_T *cur, const char *xpath);

/**
* @brief app gets operation of yang tree node.
* @param yt--yangtree
* @retval operation. e.g. XCONFD_OP_NOCHANGE/XCONFD_OP_DELETED. 
* @date 2018-12-03
* @history:
* @others 
*/
XCONFD_OPERATION_T xconfd_yang_tree_get_operation(XCONFD_YANGTREE_T *yt);

/**
* @brief app gets child node of the node.
* @param yt--yangtree
* @param child_name--child name
* @retval child yang tree node. 
* @date 2018-12-13
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_yang_tree_get_child(XCONFD_YANGTREE_T *yt, const char *child_name);

/**
* @brief app gets yang tree node by xpath.
* @param yt--yangtree
* @param xpath--both relative xpath and absolute xpath supported
* @retval yang tree node. 
* @date 2018-12-13
* @history:
* @others 
*/
XCONFD_YANGTREE_T *xconfd_yang_tree_get_node(XCONFD_YANGTREE_T *yt, const char *xpath);

/**
* @brief app gets next yang tree list node of current list node.
* @param listnode--yangtree
* @retval yang tree node.
* @date 2019-06-10
* @history:
* @others
*/
XCONFD_YANGTREE_T *xconfd_yang_tree_list_get_next(XCONFD_YANGTREE_T *listnode);

/**
* @brief app convert the yang tree node to xpath.
* @param buf--provided buffer pointer
* @param bufsiz--provided buffer size
* @param yt--yangtree
* @retval XCONFD_OK/XCONFD_ERR. 
* @date 2018-12-03
* @history:
* @others 
*/
int xconfd_yangtree2xpath(char *buf, size_t bufsiz, XCONFD_YANGTREE_T *yt);
#endif

#define xconfd_yang_tree_exists(yt, xpath) (xconfd_yang_tree_get_node((yt), (xpath)) != NULL)
#define XCONFD_YANG_TREE_LIST_FOREACH(list, listnode) for(auto listnode=list; listnode!=NULL; listnode=xconfd_yang_tree_list_get_next(listnode))
#define xconfd_yang_tree_get_leaf_list(value_list, type, xpath, yt) {\
   auto leaf_list_yt = xconfd_yang_tree_get_node((yt), (xpath));\
   int leaf_list_size = 0;\
   auto leaf_list = xconfd_yang_tree_get_value_list_##type(leaf_list_yt, &leaf_list_size);\
   for (int i = 0; i < leaf_list_size; ++i)\
   {\
      value_list.push_back(leaf_list[i]);\
   }}

#ifdef __cplusplus
}
#endif

#endif

