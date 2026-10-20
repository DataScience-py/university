#include <stdio.h>
#include <limits.h>
#include <stdint.h>

#define COEF 1000;

int main(void){
    unsigned long long a = 1;
    uint8_t i = 0, n;
    printf("Input non negative integer (from %hhu to %hhu)\n", 0, 7);
    scanf("%hhu", &n);
    while ((i < n) && (i < 7)){
        i++;  
        printf("%hhu value: %lld\n", i, a);
        a = a * 1000;
    };
    return 0;
}
