#include <stdio.h>
#include <string.h>

#define LINUX "ArchLinux"
const char YEAR[] = "2026";

int main(void){
    printf("DISTRO: %s\n", LINUX);
    printf("RDATE: %s\n", YEAR);
    printf("STRLEN: %d\n", strlen(LINUX));
    printf("SIZEOF: %d\n", sizeof(LINUX));
    return 0;
}
