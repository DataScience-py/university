#include <stdio.h>

int ping(void){printf("PING");return 0;};

int pong(void){printf("PONG");return 0;};

int handshake(void){ping();printf("-");pong();printf("-");ping();return 0;};

int main(void){
    int node_id = 10;
    int packet_size = node_id * 4;
    int total_transfer = packet_size * 3;

    handshake();printf(":%d\n", packet_size);
    handshake();printf(":%d\n", total_transfer);
    printf("SESSION:CLOSED\n");
    return 0;
}
