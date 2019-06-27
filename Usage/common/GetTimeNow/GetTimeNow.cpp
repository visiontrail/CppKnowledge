#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int int16_t;
typedef unsigned short int uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

typedef struct
{
    uint16_t u16Year;
    uint8_t u8Month;
    uint8_t u8Day;
    uint8_t u8Hour;
    uint8_t u8Minute;
    uint8_t u8Second;
    uint8_t u8Pad;
} om_stru_Time;

int main()
{
    time_t timep;
    struct tm *p;

    time(&timep);       /*获得time_t结构的时间，UTC时间*/
    p = gmtime(&timep); /*转换为struct tm结构的UTC时间*/
    printf("gmtime: %d/%d/%d ", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf(" %d:%d:%d\n",  p->tm_hour, p->tm_min, p->tm_sec);

    p = localtime(&timep); /*转换为struct tm结构的UTC时间*/
    printf("localtime: %d/%d/%d ", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf(" %d:%d:%d\n",  p->tm_hour, p->tm_min, p->tm_sec);
    
    return 0;
}
