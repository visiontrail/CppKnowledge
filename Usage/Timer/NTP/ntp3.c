#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

// gcc -o ntp_gettime ntp3.c

#define NTP_TIMESTAMP_DELTA 2208988800ull

int ntp_gettime() {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

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

    ntp_message msg;
    memset(&msg, 0, sizeof(msg));
    msg.li_vn_mode = 0x1b; // Client mode with version 3

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    server = gethostbyname("ntp2.aliyun.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        close(sockfd);
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(123);

    if (sendto(sockfd, &msg, sizeof(msg), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR sending to server");
        close(sockfd);
        return -1;
    }

    socklen_t len = sizeof(serv_addr);
    if (recvfrom(sockfd, &msg, sizeof(msg), 0, (struct sockaddr *)&serv_addr, &len) < 0) {
        perror("ERROR receiving from server");
        close(sockfd);
        return -1;
    }

    close(sockfd);

    msg.trans_timestamp_secs = ntohl(msg.trans_timestamp_secs);
    time_t txTm = (time_t)(msg.trans_timestamp_secs - NTP_TIMESTAMP_DELTA);

    struct tm *nowtm;
    nowtm = gmtime(&txTm);
    if (nowtm == NULL) {
        perror("ERROR converting time");
        return -1;
    }

    nowtm->tm_hour += 8;  // Adjust for UTC+8
    mktime(nowtm);  // Normalize the time structure

    char timebuf[64];
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", nowtm);
    printf("Time (UTC+8): %s\n", timebuf);

    return 1;
}

int main() {
    if (ntp_gettime() == -1) {
        printf("Failed to get NTP time.\n");
    }
    return 0;
}
