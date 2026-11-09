#include <stdio.h>


unsigned int rec_rev(unsigned int a, unsigned int rev);
unsigned int int_rev(unsigned int a);

int main(void){
    printf("Input a non negative integer\n");
    unsigned int n;
    scanf("%u", &n);
    unsigned int rec = rec_rev(n, 0), rev = int_rev(n);
    printf("Recursion output: %u\nInteractive output: %u\n", rec, rev);

    return 0;
}

unsigned int rec_rev(unsigned int a, unsigned int rev ){
    if (a <= 0){return rev;}
    return rec_rev(a /10, rev * 10 + (a % 10));
}


unsigned int int_rev(unsigned int a){
    unsigned int rev = 0;
    while (a > 0){
        rev = rev * 10 + (a % 10);
        a /= 10;
    }
    return rev;
}

