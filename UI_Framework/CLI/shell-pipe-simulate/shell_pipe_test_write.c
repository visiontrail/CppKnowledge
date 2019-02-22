#include<stdio.h>
#include<unistd.h>
#include <sys/time.h>

void main(void)
{
    struct timeval tp;

    printf("A");
    gettimeofday(&tp,NULL);
    fprintf(stderr,"\n#write time %ld.%ld#\n",tp.tv_sec,tp.tv_usec);
    fflush(stdout);
    sleep(2);
    printf("B");
    gettimeofday(&tp,NULL);
    fprintf(stderr,"\n#write time %ld.%ld#\n",tp.tv_sec,tp.tv_usec);
    fflush(stdout);
    sleep(2);
    printf("C");
    gettimeofday(&tp,NULL);
    fprintf(stderr,"\n#write time %ld.%ld#\n",tp.tv_sec,tp.tv_usec);
    fflush(stdout);
    sleep(5);
    gettimeofday(&tp,NULL);
    fprintf(stderr,"\n#write time %ld.%ld#\n",tp.tv_sec,tp.tv_usec);
}