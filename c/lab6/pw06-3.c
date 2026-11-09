#include <stdio.h>


unsigned int rev(unsigned int v){
    unsigned int reversed = 0;
    while (v > 0){
        reversed = reversed * 10 + (v % 10);
        v /= 10;
    }
    return reversed;
}

int main(void){
    unsigned int val, c1, c2, s1, s2;
    printf("Input non negative number (0 is end)\n");
    while (scanf("%u", &val) == 1 && val > 0){
        if (rev(val) == val && val / 100 == 0){
            s1 += val;
            c1++;
        }else{
            s2 += val;
            c2++;
        }
    }
    printf("Count number of palendrom with 2 simbvols: %u, avg: %lf\nCount other number: %u, %lf\n", c1, (double)s1 / c1, c2, (double)s2 / c2);
    return 0;
}
