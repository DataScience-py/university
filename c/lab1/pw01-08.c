#include <stdio.h>

int pulse(void){
    printf("@");
}

int main(void){
    for (int i =0; i < 3; i++){
        for (int j =0; j <= i; j++){
            pulse();
        };
        printf("\n");
    };
    return 0;
}
