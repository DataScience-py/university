#include <stdio.h>
#include "myarrfunc.h"

int main(void) {
    int n, c;
    while (1) {
        printf("Input a size of array: ");
        c = scanf("%d", &n);
        clear();
        if (c == 1 && n > 0) {
            break;
        } else if (c == EOF) {
            return -1;
        } else {
            printf("Try again. Size must be > 0.\n");
        }
    }

    int arr[n];
    fillArrValue(arr, n, 0);

    char command;
    int k, m;

    while (1) {
        while (1) {
            printf("\na - size of array\n"
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
                size(arr, n);
                break;
            case 'b':
                printArr(arr, n);
                break;
            case 'c':
                fill(arr, n);
                break;
            case 'd':
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

