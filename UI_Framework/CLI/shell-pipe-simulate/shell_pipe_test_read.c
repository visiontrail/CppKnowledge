#include<stdio.h>
#include<unistd.h>
#include <sys/time.h>

void main(void)
{
    char temp;
    int read_chars = 1;
    
    struct timeval tp;
    
    printf(">Read>");
    while(-1!=(temp=fgetc(stdin))){
        gettimeofday(&tp,NULL);
        fprintf(stderr,"\n#read time %ld.%ld#\n",tp.tv_sec,tp.tv_usec);
        fputc(temp,stdout);
        fflush(stdout);
    }
}