#include <stdio.h>




void clear(void){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); 
}


void show_matrix(int *matrix, size_t n1, size_t n2, size_t max_size){
    for (int i = 0; i < n1; i++){
        printf("Row %d: ", i);
        for (int j = 0; j < n2; j++){
            printf("%d ", *(matrix + i * max_size + j));
        }
        printf("\n");
    }
}

int fill_matrix(int *matrix, size_t n1, size_t n2, size_t max_size){
    int m, value;
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            
            while(1){
                printf("matrix[%d][%d] = ", i, j);
                m = scanf("%d", &value);
                clear();
                if (m == 1){
                    *(matrix + i * max_size + j) = value;
                    break;
                } else if (m == EOF){
                    return -1;
                } else {
                    printf("Попробуйте снова\n");
                }
            }
        }
        printf("\n");
    }
    return 0;
}

// 10
void avg_columns(int *matrix, size_t n1, size_t n2, size_t max_size){
    long long s=0;
    for (int j = 0; j < n2; j++){
        s = 0;
        printf("Column %d: ", j);
        for (int i = 0; i < n1; i++){
            s += *(matrix + i * max_size + j);
        }
        printf("%lf\n", (double)s/n2);
    }
}

void plus_vlue(int *matrix, size_t n1, size_t n2, size_t max_size){
    int c = 0;
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            if (*(matrix + i * max_size + j) > 0){
                c++;
            }
        }
        printf("Положительных чисел: %d", c);
    }
}
void last_negative(int *matrix, size_t n1, size_t n2, size_t max_size){
    int c1 = -1, c2 = -1;
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            if (*(matrix + i * max_size + j) < 0){
                c1 = i;
                c2 = j;
            }
        }
        printf("Индексы последнего отрицательного числа: %d %d", c1, c2);
    }
}