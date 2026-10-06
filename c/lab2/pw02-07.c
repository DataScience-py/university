#include <stdio.h>


int main(void){
    long double a;
    scanf("%Lf", &a);
    double b = (double)a;
    float c = (float)a;
    printf("FLOAT: %.6f\nDOUBLE: %.6f\nLDOUBLE: %.6Lf\n", c, b, a);
    a = a + 1;
    b = b + 1; 
    c = c + 1;
    printf("FLOAT+1: %.6f\nDOUBLE+1: %.6f\nLDOUBLE+1: %.6Lf\n", c, b, a);
    return 0;
}
