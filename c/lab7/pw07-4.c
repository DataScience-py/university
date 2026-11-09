#include <stdio.h>

void calc(double* a, double* b){
    if (*a > *b){
        *a = *a / *b;
        *b = *a;
    }else{
        *a = *b / *a;
        *b = *a;
    }
}


int main(void){
    double a, b;
    printf("Input a 2 non negative integer\n");
    scanf("%lf %lf", &a, &b);
    calc(&a, &b);
    printf("Output is %lf %lf\n", a, b);
    return 0;
}
