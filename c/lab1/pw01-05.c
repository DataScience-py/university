#include <stdio.h>


int main(void){
    int reactor_core = 11;
    printf("[");
    printf("%d", reactor_core);
    printf(", ");
    printf("%d", reactor_core * 2);
    printf(", ");
    printf("%d", reactor_core * reactor_core);
    printf("]\n");
    return 0;
}
