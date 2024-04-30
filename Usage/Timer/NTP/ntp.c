#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

// gcc -o ntp_gettime ntp.c

#define NTP_TIMESTAMP_DELTA 2208988800ull

int ntp_gettime() {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    struct timeval timeout;
    int rv;

    typedef struct {
        uint8_t li_vn_mode;      // Mode
        uint8_t stratum;         // Stratum
        uint8_t poll;            // Polling Interval
        uint8_t precision;       // Precision
        uint32_t root_delay;     // Root Delay
        uint32_t root_dispersion; // Root Dispersion
        uint32_t ref_id;         // Reference ID
        uint32_t ref_timestamp_secs; // Reference Timestamp
        uint32_t ref_timestamp_frac;
        uint32_t orig_timestamp_secs; // Originate Timestamp
        uint32_t orig_timestamp_frac;
        uint32_t recv_timestamp_secs; // Received Timestamp
        uint32_t recv_timestamp_frac;
        uint32_t trans_timestamp_secs; // Transmit Timestamp
        uint32_t trans_timestamp_frac;
    } ntp_message;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo("ntp2.aliyun.com", "123", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return -1;
    }

    // loop through all the results and make a socket
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to create socket\n");
        return -1;
    }

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        perror("ERROR setting socket timeout");
        close(sockfd);
        return -1;
    }

    ntp_message msg;
    memset(&msg, 0, sizeof(msg));
    msg.li_vn_mode = 0x1b; // Client mode with version 3

    if (sendto(sockfd, &msg, sizeof(msg), 0, p->ai_addr, p->ai_addrlen) < 0) {
        perror("sendto");
        close(sockfd);
        return -1;
    }

    unsigned int addr_len = p->ai_addrlen;
    if (recvfrom(sockfd, &msg, sizeof(msg), 0, p->ai_addr, &addr_len) < 0) {
        perror("recvfrom");
        close(sockfd);
        return -1;
    }

    msg.trans_timestamp_secs = ntohl(msg.trans_timestamp_secs);
    time_t txTm = (time_t)(msg.trans_timestamp_secs - NTP_TIMESTAMP_DELTA);

    struct tm *nowtm;
    nowtm = gmtime(&txTm);
    if (nowtm == NULL) {
        perror("gmtime");
        close(sockfd);
        return -1;
    }

    nowtm->tm_hour += 8;
    mktime(nowtm);

    char timebuf[64];
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", nowtm);
    printf("Time (UTC+8): %s\n", timebuf);

    freeaddrinfo(servinfo);
    close(sockfd);
    return 1;
}

int main() {
    if (ntp_gettime() == -1) {
        printf("Failed to get NTP time.\n");
    }
    return 0;
}
