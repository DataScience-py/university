#include <stdio.h>
#include <stdbool.h>


void module(void){
    int v;
    printf("Input a value > ");
    scanf("%d", &v);
    printf( "Module is %u\n", (v >=0) ? v:-v);
}
void sign(void){
    int v;
    printf("Input a value > ");
    scanf("%d", &v);
    printf( "Sign is %u\n", (v = 0) ? 0:(v > 0) ? 1:-1);
}
void round_up(void){
    double v;
    printf("Input a value > ");
    scanf("%lf", &v);
    printf( "Round up is %d\n", (int)(v)+ (v > 0 && v != (int)v));
}

void round_down(void){
    double v;
    printf("Input a value > ");
    scanf("%lf", &v);
    printf( "Round down is %d\n", (int)(v) - (v < 0 && v != (int)v));
}

void error(void){
    printf("Incorrect input, try again");
}

int main(void){
    int v;
    printf("0 - Exit\n1 - module\n2 - sign\n3 - round up\n4 - round down\n>");
    bool is_exit = false;
    while (!is_exit && scanf("%d", &v) == 1){
        switch (v) {
            case 1: module(); break;
            case 0: is_exit = true;  break;
            case 2: sign(); break;
            case 3: round_up(); break;
            case 4: round_down(); break;
            default: error(); break; 
        }
        if (!is_exit){
            printf("0 - Exit\n1 - module\n2 - sign\n3 - round up\n4 - round down\n>");
        }
    }
    printf("\n");

    return 0;    
}
