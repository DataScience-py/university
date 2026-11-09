#include <stdio.h>

double discount_calc(unsigned int amount){
    double res;
    if (amount > 1000){
        res = (double)amount *0.85;
    } else if(amount > 500){
        res = (double)amount * 0.90;
    } else if(amount > 100){
        res = (double)amount * 0.95;
    }else {
        res = (double)amount;
    }
    return res;
}

int main(void){
    unsigned int v;
    double res;
    printf("Input purchase amount\n");
    scanf("%u", &v);
    res = discount_calc(v); 
    printf("Prise is with your discount %lf\n", res);
    return 0;
}
