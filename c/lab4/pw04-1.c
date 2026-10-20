#include <stdio.h>


#define coef 1000

int main(void){
    long long base, start, to;
    
    while(scanf("%lld", &start) == 1 && start >= 0){
        to = start / coef;
        base = start % coef;
        printf("from %lld mg to result: %lld g, %lld mg\n", start, to, base);
    };
    printf("\n");
    return 0;
}
