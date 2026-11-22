#include <stdio.h>
#include <limits.h>

/*Вывод массива на экран через указатели*/
void printArr(int first[], int n){
    int *last = first + n; 
    printf("Arr: ");
    for (int *i = first; i < last; i++){
        printf("%d ", *i);
    };
    printf("\n");
};


/*Заполнение масисвы числом*/
void fillArrValue(int first[], int n, int value){
    int *last = first + n;
    for (int *i = first; i < last; i++){
        *i = value;
    };
};

/*Вывод размера массива*/
void size(int first[], int n){
    // можно и просто выводить n
    int *last = first + n;
    printf("%ld\n", last - first);
};


/*Очистка ввода*/
void clear(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
};

/*Заполнение массива данными*/
int fill(int first[], int n){
    int *last = first + n;
    printf("Filling the array. Only the first 9 digits are saved.\n");
    int *i = first;
    unsigned int count = 0;
    int c;
    while (i < last){
        printf("Value for %u is ", count);
        c = scanf("%9d", i);
        clear();
        if (c == 1){
            i++;
            count++;
        } else if (c == EOF) {
            printf("EOF");
            putchar('\n');
            return -1;
        } else{
            printf("Incorrect input. Try again\n");
            continue;
        };
    };
    putchar('\n');
    return 0;
};


/* 2 вариант поиск максимального с k по m индексы*/
void maxArr(int first[], int n, int k, int m){
    int *last = first + n;
    int *i = first + k;
    int *j = first + m + 1;
    if (k > m){
        printf("k=%d is biggest than m=%d", k, m);
        return;
    };
    if (j > last){
        printf("m=%d bigest than end index %ld", m, (last - first) - 1);
        return;
    };
    if (k == m){
        printf("MAX value from %d to %d is %d\n", k, m, *(first + k));
        return;
    }
    int mx = INT_MIN;
    for (;i < j; i++){
        if (mx < *i){
            mx = *i;
        };
    };
    printf("MAX value from %d to %d is %d\n", k, m, mx);
};


/* 11 вариант среднее с k по m в массиве*/
void avgArr(int first[], int n, int k, int m){
    int *last = first + n;
    int *i = first + k;
    int *j = first + m + 1;
    if (k > m){
        printf("k=%d is biggest than m=%d", k, m);
        return;
    };
    if (j > last){
        printf("m=%d bigest than end index %ld", m, (last - first) - 1);
        return;
    };
    if (k == m){
        printf("AVG value from %d to %d is %d\n", k, m, *(first + k));
        return;
    }
    long long int sum = 0;
    for (;i < j; i++){
        sum += *i;
    };
    printf("Avearge is %.6lf\n", (double)(sum) / (m-k));
};


/* 20 Количество превосходящих k в массиве*/
void countBiggestArr(int first[], int n, int k){
    unsigned int count = 0;
    int * last = first + n;
    for (int *i = first;i < last; i++){
        if (*i > k){
            count++;
        };
    };
    printf("Count vlaue biggest than %d is %u", k, count);
};
