#include <stdio.h>


int main(void){
    char str[20];
    int d;
    scanf("%s %d", str, &d);
    printf("%*s\n", d, str);
    printf("%-*s\n", d+5, str);
    return 0;
}
