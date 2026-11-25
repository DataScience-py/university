#include <stdio.h>
#include "matrixfunc.h"

#define MAX_SIZE 1000


char read_command(void){
    char command;
    int n;
    while (1){
        printf( "a - Указать размерность матрицы\n"
                "b - Показать матрицу\n"
                "c - Заполнить матрицу\n"
                "d - Среднее значение по столбцам\n"
                "e - Количество положительных элементов\n"
                "f - Индексы последнего отрицательного числа\n"
                "g - выйти\n");
        n = scanf("%c", &command);
        clear();
        if (n == 1){
            if (command >= 'a' && command <= 'g'){
                return command; 
            } else{
                printf("Неправильный символ\n");
            }
        }else if (n == EOF){
            return 'g';
        } else {
            printf("Неправильный ввод попробуйте снова\n");
        }
    }
}

int set_size(size_t *n1, size_t *n2) {
    long long tmp1, tmp2;
    int n;
    while (1) {
        n = scanf("%lld %lld", &tmp1, &tmp2);
        clear();
        if (n == 2) {
            if (tmp1 > 0 && tmp1 <= MAX_SIZE && tmp2 > 0 && tmp2 <= MAX_SIZE) {
                *n1 = (size_t)tmp1;
                *n2 = (size_t)tmp2;
                return 0;
            } else {
                printf("Размеры должны быть от 1 до %d. Попробуйте снова:\n", MAX_SIZE);
            }
        } else if (n == EOF) {
            return -1;
        } else {
            printf("Неправильный ввод, попробуйте снова:\n");
        }
    }
}




int main(void){
    int matrix[MAX_SIZE][MAX_SIZE];

    size_t n1, n2, t1 = 0, t2 = 0;
    int n_set = 0, status;
    char command;
    while (1){
        command = read_command();
        switch(command){
            case 'a':
                status = set_size(&t1,&t2);
                if (status == -1){
                    return 0;
                }
                if ((t1 > 0) && (t2 > 0)){
                    n1 = t1;
                    n2 = t2;
                    n_set = 1;
                } else {
                    printf("Размер не установлен, так как размеры должны быть больше 0");
                }
                break;
            case 'b':
                if (n_set == 0){
                    printf("Сначала установите размерность\n");
                    break;
                }
                show_matrix(matrix[0], n1, n2, MAX_SIZE);
                break;
            case 'c':
                if (n_set == 0){
                    printf("Сначала установите размерность\n");
                    break;
                }
                status = fill_matrix(matrix[0], n1, n2, MAX_SIZE);
                if (status == -1){
                    return 0;
                }
                break;
            case 'd':
                if (n_set == 0){
                    printf("Сначала установите размерность\n");
                    break;
                }
                avg_columns(matrix[0], n1, n2, MAX_SIZE);
                break;
            case 'e':
                if (n_set == 0){
                    printf("Сначала установите размерность\n");
                    break;
                }         
                plus_vlue(matrix[0], n1, n2, MAX_SIZE);  
                break;
            case 'f':
                if (n_set == 0){
                    printf("Сначала установите размерность\n");
                    break;
                }
                last_negative(matrix[0], n1, n2, MAX_SIZE);
                break;
            case 'g':
                return 0;
        }
    }
}
