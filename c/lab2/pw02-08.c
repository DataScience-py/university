#include <stdio.h>
#include <float.h>

int main(void){
    /*The size can have opther values (in some system long double = double)*/
    printf("FLOAT: size=%d, digits=%d, max=%Le\n", sizeof(float), FLT_DIG, FLT_MAX);
    printf("DOUBLE: size=%d, digits=%d, max=%Le\n", sizeof(double), DBL_DIG, DBL_MAX);
    printf("LDOUBLE: size=%d, digits=%d, max=%Le\n", sizeof(long double), LDBL_DIG, LDBL_MAX);
    return 0;
}
