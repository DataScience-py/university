#include <stdio.h>

#define COEF 1000;

int main(void){
    int n;
    double s;
    while(scanf("%d", &n) == 1 && n > 0){
        s = 0;
        for (int i=1;i<n;i++){  
            s += 1.0 / (2*i * (2*i -1));
        };
        printf("Sum is first N value is: %lf\n", s);
    }; 
    return 0;
}
