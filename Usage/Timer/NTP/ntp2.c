#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

// gcc -o ntp_gettime ntp2.c

#define NTP_TIMESTAMP_DELTA 2208988800ull

int ntp_gettime() {
    int sockfd;
    struct sockaddr_in servaddr;
    struct timeval timeout;

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
    msg.li_vn_mode = 0x1b;

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        perror("ERROR setting socket timeout");
        close(sockfd);
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(123);
    if (inet_pton(AF_INET, "203.107.6.88", &servaddr.sin_addr) <= 0) {
        perror("ERROR server address not valid");
        close(sockfd);
        return -1;
    }

    if (sendto(sockfd, &msg, sizeof(msg), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR sending to server");
        close(sockfd);
        return -1;
    }

    unsigned int addr_len = sizeof(servaddr);
    if (recvfrom(sockfd, &msg, sizeof(msg), 0, (struct sockaddr *)&servaddr, &addr_len) < 0) {
        perror("ERROR receiving from server");
        close(sockfd);
        return -1;
    }

    msg.trans_timestamp_secs = ntohl(msg.trans_timestamp_secs);
    time_t txTm = (time_t)(msg.trans_timestamp_secs - NTP_TIMESTAMP_DELTA);

    struct tm *nowtm;
    nowtm = gmtime(&txTm);
    if (nowtm == NULL) {
        perror("ERROR converting time");
        close(sockfd);
        return -1;
    }

    nowtm->tm_hour += 8;
    mktime(nowtm); // Normalize the time structure

    char timebuf[64];
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", nowtm);
    printf("Time (UTC+8): %s\n", timebuf);

    close(sockfd);
    return 1;
}

int main() {
    if (ntp_gettime() == -1) {
        printf("Failed to get NTP time.\n");
    }
    return 0;
}
