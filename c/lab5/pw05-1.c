#include <stdio.h>
#include <math.h>

double f(double x);


int main(void){
    double y = 0.0;
    for (int x = 1; x <= 4; x++){
        y = f((double)x);

        printf("For X: %d is Y=F(x): %lf\n", x, y);
    }
    return 0;
}

double f(double x){
    return pow(x, 1.0 / 3.0);
}

