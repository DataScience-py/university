#include <stdio.h>
#include <math.h>

double calculate(double a, double b) {
    return fabs(a - b) / (a + b);
}

int main(void) {
    double a, b;

    printf("Enter two numbers separated by a space (any character or Ctrl+D to exit):\n");

    while (scanf("%lf %lf", &a, &b) == 2) {
        if (a + b == 0.0) {
            printf("Error: sum of numbers is zero (division by zero is not allowed).\n\n");
        } else {
            double res = calculate(a, b);
            printf("Result: %.4f\n\n", res);
        }

        printf("Enter the next pair of numbers:\n");
    }

    printf("Input finished.\n");
    return 0;
}

