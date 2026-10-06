#include <stdio.h>
#include <stdint.h>

int main(void){
    int a;
    scanf("%d", &a);
    uint8_t b = (uint8_t)a;
    printf("ADD %d\n", (uint8_t)(b+10));
    printf("MUL2: %d\n", (uint8_t)(b*2));
    printf("SQR: %d\n", (uint8_t)(b*b));

    return 0;
}
