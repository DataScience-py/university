#include <stdbool.h>
#include <stdio.h>


int main(void){
    int a1, b1;
    scanf("%d %d", &a1, &b1);
    bool a = a1, b = b1;
    printf("MODULE_READY: %d\n", a);
    printf("FAULT_STATE: %d\n", b);
    printf("BOOL_SIZE: %d\n", sizeof(a));
    printf("FLAGS_SUM: %d\n", a + b);
    return 0;
}
