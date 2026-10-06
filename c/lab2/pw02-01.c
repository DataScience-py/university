#include <stdio.h>


int main(void){
    int a, b, c;
    scanf("%d %x %o", &a, &b, &c);
    printf("UNIT_T: %d\n", a);
    printf("UNIT_VERSION: %d\n", b);
    printf("UNIT_STATUS: %d\n", c);
    printf("SUM: %d\n", a+b+c);
    return 0;
}
