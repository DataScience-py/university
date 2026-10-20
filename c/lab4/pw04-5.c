#include <stdio.h>

double l_to_gal(double l);

int main(void){
    double l, gal = 0;
    while(scanf("%lf", &l) == 1){
        gal = l_to_gal(l);
        printf("%.2lf liter in %.2lf gal\n", l, gal);
    };
    return 0;
};


const double coef = 3.785;
double l_to_gal(double l){
  return l / coef;  
};
