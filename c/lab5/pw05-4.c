#include <stdio.h>
#define LEN_ARR 8


int main(void){
    double arr[LEN_ARR];
    for (int i=0;i < LEN_ARR; i++){
        arr[i] = (1+i)*(1+i);
    };

    printf("Array:\n");
    for (int i=0;i < LEN_ARR; i++){
        printf("%.2lf ", arr[i]);
    };
    printf("\n");

    double s = 0.0;
    for (int i=0; i < LEN_ARR; i++){
        s += arr[i];
    };
    printf("SUM is: %.2lf\n", s);

    return 0;
}
