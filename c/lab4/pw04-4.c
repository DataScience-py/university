#include <stdio.h>
#include <limits.h>

int main(void){
    long long result;
    int i = 0, n;
    printf("Input N (from 0 to %d): ", INT_MAX);
    scanf("%d", &n);
    int sign = 1;
    while (i < n){
        i++;
        result = result + sign * i;
        sign = -sign;
    };
    printf("Result: %lld\n", result);
    return 0;
}
