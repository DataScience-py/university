#include <stdio.h>
#include <ctype.h>

int main(void){
    int c;
    while((c = getchar()) != EOF) {
        if (isprint((unsigned char)c)){
            putchar(c);
        }
    }
    putchar('\n');

    return 0;
}
