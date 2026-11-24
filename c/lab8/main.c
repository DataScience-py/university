#include <stdio.h>
#include "myarrfunc.h"

#define SIZE 1000

int main(void) {
    int c;
    size_t n = 0, temp = 0;

    char command;
    int k, m;
    int arr[SIZE];
    fillArrValue(arr, SIZE, 0);

    while (1) {
        while (1) {
            printf("\na - set size of array\n"
                   "b - show array\n"
                   "c - fill array\n"
                   "d - max value from k to m index\n"
                   "e - average value from k to m index\n"
                   "f - count values bigger than k\n"
                   "g - exit\n"
                   "Input a command: ");
            c = scanf(" %c", &command);
            clear();
            if (c == 1) {
                if (command >= 'a' && command <= 'g') {
                    break;
                } else {
                    printf("Use only a, b, c, d, e, f, g for command.\n");
                }
            } else if (c == EOF) {
                return -1;
            } else {
                printf("Try again.\n");
            }
        }

        switch (command) {
            case 'a':
                temp = set_size();
                if (temp == -1){
                    return -1;
                }
                if (temp > SIZE){
                    printf("n больше чем %d, сохранено прошлое значение %zu", SIZE, n);
                    break;
                }
                n = temp;
                break;
            case 'b':
                if (n == 0){
                    printf("Укажите сначала размер");
                    break;
                }
                printArr(arr, n);
                break;
            case 'c':
                if (n == 0){
                    printf("Укажите сначала размер");
                    break;
                }
                fill(arr, n);
                break;
            case 'd':
                if (n == 0){
                    printf("Укажите сначала размер");
                    break;
                }
                while (1) {
                    printf("Input k and m indexes: ");
                    c = scanf("%d %d", &k, &m);
                    clear();
                    if (c == 2) {
                        break;
                    } else if (c == EOF) {
                        return -1;
                    } else {
                        printf("Try again.\n");
                    }
                }
                maxArr(arr, n, k, m);
                break;
            case 'e':
                if (n == 0){
                    printf("Укажите сначала размер");
                    break;
                }
                while (1) {
                   printf("Input k and m indexes: ");
                    c = scanf("%d %d", &k, &m);
                    clear();
                    if (c == 2) {
                        break;
                    } else if (c == EOF) {
                        return -1;
                    } else {
                        printf("Try again.\n");
                    }
                }
                avgArr(arr, n, k, m);
                break;
            case 'f':
                if (n == 0){
                    printf("Укажите сначала размер");
                    break;
                } 
                while (1) {
                    printf("Input k value: ");
                    c = scanf("%d", &k);
                    clear();
                    if (c == 1) {
                        break;
                    } else if (c == EOF) {
                        return -1;
                    } else {
                        printf("Try again.\n");
                    }
                }
                countBiggestArr(arr, n, k);
                break;
            case 'g':
                return 0;
        }
    }

    return 0;
}

