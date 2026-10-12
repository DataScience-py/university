#include <stdio.h>
#include <string.h>

int main(void){
    char str[] = "\x48\x65\x6c\x6c\x6F\t\x57\x6F\x72\x6C\x64\n";
    /*             H    E   L   L   O     W   O   R   L   D
    \t - табуляция
    */
    printf("%s", str);
    printf("STRLEN: %d\n", strlen(str));
    printf("SIZEOF: %zu\n", sizeof(str));
    return 0;
}
