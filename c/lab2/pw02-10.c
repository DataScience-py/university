#include <stdio.h>
#include <stdint.h>

int main(void){
    int a, d;
    float c;
    scanf("%x %o %f", &a, &d, &c);
    uint8_t b = (uint8_t)d;
    uint16_t checksum = (uint16_t)(a+b);
    printf("PACKET_ID: %d\n", a);
    printf("STATUS_CODE: %d\n", b);
    printf("STATUS_CHAR: %c\n", b);
    printf("VOLTAGE: %.2f\n", c);
    printf("CHECKSUM: %d\n", checksum);
    return 0;
}
