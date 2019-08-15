/*
* @Copyright(C), CertusNet
* @file: xconfd_yangvalue_api.h
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


#ifndef __XCONFD_YANGVALUE_API_H__
#define __XCONFD_YANGVALUE_API_H__

#ifdef __cplusplus
extern "C"
{
#endif

#if XCONFD_CODE("Macro definition")

typedef void XCONFD_YANGVALUE_T;

#endif

#if XCONFD_CODE("Data structure definition")

typedef struct snmp_oid_bind {
#define MAX_OID_NUMBER 64
    u_int32_t    oid[MAX_OID_NUMBER];
    u_int8_t     oid_len;
    XCONFD_YANGVALUE_T *val;
} XCONFD_SNMP_OID_BIND_T;

typedef struct xconfd_buf {
    unsigned int size;
    unsigned char *ptr;
} XCONFD_BUF_T;

typedef XCONFD_BUF_T XCONFD_BINARY_T;
typedef XCONFD_BUF_T XCONFD_HEXSTR_T;

struct xml_tag {
    uint32_t tag;
    uint32_t ns;
};
typedef struct xconfd_datetime {
    int16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    uint32_t micro;
    int8_t timezone;
    int8_t timezone_minutes;
}XCONFD_DATETIME_T;
typedef struct xconfd_date {
    int16_t year;
    uint8_t month;
    uint8_t day;
    int8_t timezone;
    int8_t timezone_minutes;
}XCONFD_DATE_T;
typedef struct xconfd_time {
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    uint32_t micro;
    int8_t timezone;
    int8_t timezone_minutes;
}XCONFD_TIME_T;
typedef struct xconfd_duration {
    uint32_t years;
    uint32_t months;
    uint32_t days;
    uint32_t hours;
    uint32_t mins;
    uint32_t secs;
    uint32_t micros;
}XCONFD_DURATION_T;
typedef struct xconfd_list {
    unsigned int size;
    XCONFD_YANGVALUE_T **ptr;
}XCONFD_LIST_T;
typedef struct xconfd_ipv4_prefix {
    struct in_addr ip;
    uint8_t len;
}XCONFD_IPV4_PREFIX_T;
typedef struct xconfd_ipv6_prefix{
    struct in6_addr ip6;
    uint8_t len;
}XCONFD_IPV6_PREFIX_T;
#endif

#if XCONFD_CODE("yangvalue creat api")
/**
* @brief free yangvalue and internal value
* @param v--point to yangvalue; 
* @retval void
* @date: 2018-12-03
* @history:
* @others:
*/
void xconfd_free_yang_value(XCONFD_YANGVALUE_T* v);
/**
* @brief yangtree is made from yangvlaue by app.
* @param p--app's data; app's data will be copied to yangvalue, yangvalue will be free in yangtree.
* @retval XCONFD_YANGVALUE_T *
* @date: 2018-12-03
* @history:
* @others:
*/
XCONFD_YANGVALUE_T * xconfd_newvalue_string(const char *p);
XCONFD_YANGVALUE_T *xconfd_newvalue_buf(unsigned char *buf, unsigned int len);
XCONFD_YANGVALUE_T *xconfd_newvalue_int8(int8_t i);
XCONFD_YANGVALUE_T *xconfd_newvalue_int16(int16_t i);
XCONFD_YANGVALUE_T *xconfd_newvalue_int32(int32_t i);
XCONFD_YANGVALUE_T *xconfd_newvalue_int64(int64_t i);
XCONFD_YANGVALUE_T *xconfd_newvalue_uint8(uint8_t i);
XCONFD_YANGVALUE_T *xconfd_newvalue_uint16(uint16_t i);
XCONFD_YANGVALUE_T *xconfd_newvalue_uint32(uint32_t i);
XCONFD_YANGVALUE_T *xconfd_newvalue_uint64(uint64_t i);
XCONFD_YANGVALUE_T *xconfd_newvalue_double(double i);
XCONFD_YANGVALUE_T *xconfd_newvalue_ipv4(struct in_addr ip);
XCONFD_YANGVALUE_T *xconfd_newvalue_ipv6(struct in6_addr ip);
XCONFD_YANGVALUE_T *xconfd_newvalue_bool(int b);
XCONFD_YANGVALUE_T *xconfd_newvalue_datetime(XCONFD_DATETIME_T datetime);
XCONFD_YANGVALUE_T *xconfd_newvalue_date(XCONFD_DATE_T date);
XCONFD_YANGVALUE_T *xconfd_newvalue_time(XCONFD_TIME_T time);
XCONFD_YANGVALUE_T *xconfd_newvalue_duration(XCONFD_DURATION_T duration);
XCONFD_YANGVALUE_T *xconfd_newvalue_enum(int32_t enumm);
XCONFD_YANGVALUE_T *xconfd_newvalue_bit32(uint32_t bit);
XCONFD_YANGVALUE_T *xconfd_newvalue_bit64(uint64_t bit);
XCONFD_YANGVALUE_T *xconfd_newvalue_list(XCONFD_YANGVALUE_T **list, int num);

/**
* @brief App creats ipv4prefix. e.g. 192.168.2.1/24
* @param ipprefix--XCONFD_IPV4_PREFIX_T
* @retval XCONFD_YANGVALUE_T *
* @date 2018-12-03
* @history:
* @others yang leaf type: inet:ipv4-prefix;
*/
XCONFD_YANGVALUE_T *xconfd_newvalue_ipv4prefix(XCONFD_IPV4_PREFIX_T ipprefix);
/**
* @brief App creats ipv6prefix. e.g. 908:200:900/120
* @param ipprefix--XCONFD_IPV6_PREFIX_T
* @retval XCONFD_YANGVALUE_T *
* @date 2018-12-03
* @history:
* @others yang leaf type: inet:ipv6-prefix;
*/
XCONFD_YANGVALUE_T *xconfd_newvalue_ipv6prefix(XCONFD_IPV6_PREFIX_T ipprefix);
/**
* @brief App creats ipv4plen, the part of host must 0. e.g. 192.168.2.0/24
* @param ipprefix--XCONFD_IPV4_PREFIX_T
* @retval XCONFD_YANGVALUE_T *
* @date 2018-12-03
* @history:
* @others yang leaf type: tailf:ipv4-address-and-prefix-length;
*/
XCONFD_YANGVALUE_T *xconfd_newvalue_ipv4plen(XCONFD_IPV4_PREFIX_T ipprefix);
/**
* @brief App creats ipv6plen, the part of host must 0. e.g. 908::900/120
* @param ipprefix--XCONFD_IPV4_PREFIX_T
* @retval XCONFD_YANGVALUE_T *
* @date 2018-12-03
* @history:
* @others yang leaf type: tailf:ipv6-address-and-prefix-length;
*/
XCONFD_YANGVALUE_T *xconfd_newvalue_ipv6plen(XCONFD_IPV6_PREFIX_T ipprefix);
XCONFD_YANGVALUE_T *xconfd_newvalue_hexstr(unsigned char *buf, unsigned int len);
XCONFD_YANGVALUE_T *xconfd_newvalue_binary(unsigned char *buf, unsigned int len);

#endif
#if XCONFD_CODE("yangvalue get api")
/**
* @brief app gets string point from yangvalue
* @param yv--yangvalue
* @retval point to string
* @date 2018-12-03
* @history:
* @others 
*/
const char *xconfd_get_string(XCONFD_YANGVALUE_T *yv);  
/**
* @brief app gets buff point from yangvalue
* @param yv--yangvalue
* @retval point to buff
* @date 2018-12-03
* @history:
* @others 
*/
unsigned char *xconfd_get_bufptr(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets buff size from yangvalue
* @param yv--yangvalue
* @retval the size of buf
* @date 2018-12-03
* @history:
* @others 
*/
unsigned int xconfd_get_bufsize(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets int8 from yangvalue
* @param yv--yangvalue
* @retval int8
* @date 2018-12-03
* @history:
* @others 
*/
int8_t xconfd_get_int8(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets int16 from yangvalue
* @param yv--yangvalue
* @retval int16
* @date 2018-12-03
* @history:
* @others 
*/
int16_t xconfd_get_int16(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets int32 from yangvalue
* @param yv--yangvalue
* @retval int32
* @date 2018-12-03
* @history:
* @others 
*/
int32_t xconfd_get_int32(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets int64 from yangvalue
* @param yv--yangvalue
* @retval int64
* @date 2018-12-03
* @history:
* @others 
*/
int64_t xconfd_get_int64(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets uint8 from yangvalue
* @param yv--yangvalue
* @retval uint8
* @date 2018-12-03
* @history:
* @others 
*/
u_int8_t xconfd_get_uint8(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets uint16 from yangvalue
* @param yv--yangvalue
* @retval uint16
* @date 2018-12-03
* @history:
* @others 
*/
u_int16_t xconfd_get_uint16(XCONFD_YANGVALUE_T *yv); 
/**
* @brief app gets uint32 from yangvalue
* @param yv--yangvalue
* @retval uint32
* @date 2018-12-03
* @history:
* @others 
*/
u_int32_t xconfd_get_uint32(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets uint64 from yangvalue
* @param yv--yangvalue
* @retval uint64
* @date 2018-12-03
* @history:
* @others 
*/
u_int64_t xconfd_get_uint64(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets double from yangvalue
* @param yv--yangvalue
* @retval double
* @date 2018-12-03
* @history:
* @others 
*/
double xconfd_get_double(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets ipv4 from yangvalue
* @param yv--yangvalue
* @retval ipv4
* @date 2018-12-03
* @history:
* @others 
*/
struct in_addr xconfd_get_ipv4(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets ipv6 from yangvalue
* @param yv--yangvalue
* @retval ipv6
* @date 2018-12-03
* @history:
* @others 
*/
struct in6_addr xconfd_get_ipv6(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets bool from yangvalue
* @param yv--yangvalue
* @retval bool
* @date 2018-12-03
* @history:
* @others 
*/
int xconfd_get_bool(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets datatime from yangvalue
* @param yv--yangvalue
* @retval datatime
* @date 2018-12-03
* @history:
* @others 
*/
XCONFD_DATETIME_T xconfd_get_datatime(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets data from yangvalue
* @param yv--yangvalue
* @retval data
* @date 2018-12-03
* @history:
* @others 
*/
XCONFD_DATE_T xconfd_get_data(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets time from yangvalue
* @param yv--yangvalue
* @retval time
* @date 2018-12-03
* @history:
* @others 
*/
XCONFD_TIME_T xconfd_get_time(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets duration from yangvalue
* @param yv--yangvalue
* @retval duration
* @date 2018-12-03
* @history:
* @others 
*/
XCONFD_DURATION_T xconfd_get_duration(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets enum from yangvalue
* @param yv--yangvalue
* @retval enum
* @date 2018-12-03
* @history:
* @others 
*/
int32_t xconfd_get_enum(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets bit32 from yangvalue
* @param yv--yangvalue
* @retval bit32
* @date 2018-12-03
* @history:
* @others 
*/
u_int32_t xconfd_get_bit32(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets bit64 from yangvalue
* @param yv--yangvalue
* @retval bit64
* @date 2018-12-03
* @history:
* @others 
*/
u_int64_t xconfd_get_bit64(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets value list from yangvalue
* @param yv--yangvalue
* @retval yang value list array
* @date 2018-12-03
* @history:
* @others 
*/
XCONFD_YANGVALUE_T ** xconfd_get_list(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets leaf list size from yangvalue
* @param yv--yangvalue
* @retval list size
* @date 2018-12-03
* @history:
* @others 
*/
unsigned int xconfd_get_list_size(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets point to binary from yangvalue
* @param yv--yangvalue
* @retval point to binary
* @date 2018-12-03
* @history:
* @others 
*/
unsigned char *xconfd_get_binary_ptr(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets size of binary from yangvalue
* @param yv--yangvalue
* @retval point to binary
* @date 2018-12-03
* @history:
* @others 
*/
unsigned int xconfd_get_binary_size(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets ipv4prefix from yangvalue
* @param yv--yangvalue
* @retval ipv4prefix
* @date 2018-12-03
* @history:
* @others 
*/
XCONFD_IPV4_PREFIX_T xconfd_get_ipv4prefix(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets ipv6prefix from yangvalue
* @param yv--yangvalue
* @retval ipv6prefix
* @date 2018-12-03
* @history:
* @others yang leaf type: inet:ipv4-prefix;
*/
XCONFD_IPV6_PREFIX_T xconfd_get_ipv6prefix(XCONFD_YANGVALUE_T *yv); 
/**
* @brief app gets point to hexstr from yangvalue
* @param yv--yangvalue
* @retval point to hexstr
* @date 2018-12-03
* @history:
* @others yang leaf type: inet:ipv6-prefix;
*/
unsigned char *xconfd_get_hexstr_ptr(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets point to hexstr from yangvalue
* @param yv--yangvalue
* @retval point to hexstr
* @date 2018-12-03
* @history:
* @others 
*/
unsigned int xconfd_get_hexstr_size(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets ipv4 and plen from yangvalue
* @param yv--yangvalue
* @retval ipv4 and plen
* @date 2018-12-03
* @history:
* @others yang leaf type: tailf:ipv4-address-and-prefix-length;
*/
XCONFD_IPV4_PREFIX_T xconfd_get_ipv4_plen(XCONFD_YANGVALUE_T *yv);
/**
* @brief app gets ipv6 and plen from yangvalue
* @param yv--yangvalue
* @retval ipv6 and plen
* @date 2018-12-03
* @history:
* @others yang leaf type: tailf:ipv6-address-and-prefix-length;
*/
XCONFD_IPV6_PREFIX_T xconfd_get_ipv6_plen(XCONFD_YANGVALUE_T *yv);

#define xconfd_get(var, type, name, tree) {\
   auto yv = xconfd_yang_tree_get_value_ex((tree), (name));\
   if (yv != nullptr)\
   {\
      var = (decltype(var))xconfd_get_##type(yv);\
   }\
   else\
   {\
      std::string var_type = #type;\
      if ((var_type.find("int") != std::string::npos) || (var_type == "enum") || (var_type == "double") || (var_type == "bool"))\
      {\
         var = (decltype(var))0;\
      }\
   }}

#define xconfd_get_optional(var, type, suffix, name, tree) {\
   auto yv = xconfd_yang_tree_get_value_ex((tree), (name));\
   if (yv != nullptr)\
   {\
      var = std::make_shared<type>(xconfd_get_##suffix(yv));\
   }}

#define xconfd_get_optional_enum(var, type, name, tree) {\
   auto yv = xconfd_yang_tree_get_value_ex((tree), (name));\
   if (yv != nullptr)\
   {\
      var = std::make_shared<type>((type)xconfd_get_enum(yv));\
   }}


#define xconfd_get_empty_value(var, name, tree) { var = xconfd_yang_tree_get_value_ex((tree), (name)) ? true : false; }


#endif

#ifdef __cplusplus
}
#endif

#endif
