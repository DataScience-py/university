#include <math.h>
#include <stdio.h>

double calc(double a, double b);

int main(void){
    double a, b;
    while(scanf("%lf %lf", &a, &b) == 2)
        printf("Result is: %.4lf\n", calc(a,b));
    return 0;  
};


double calc(double a, double b){
    return pow(pow(a, 3) + pow(b, 3), 1.0/3.0);  
};

