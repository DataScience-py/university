#include <stdio.h>

int phase1(void);
int phase2(void);
int phase3(void);

int phase1(void){
    printf("ALPHA ");
    phase2();
    return 0;
}

int phase2(void){
    printf("BETA ");
    phase3();
    return 0;
}

int phase3(void){
    printf("GAMMA ");
    return 0;
}

int main(void){
    printf("START ");
    phase1();
    printf("END\n");
    return 0;
}
