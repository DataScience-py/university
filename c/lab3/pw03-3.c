#include <stdio.h>


int main(void){
    char name[20];

    scanf("%s", name);

    printf("\"%s\"\n", name);
    printf("\"%20s\"\n", name);
    printf("\"%-20s\"\n", name);
    printf("\"%5c %s %5c\"\n", ' ', name, ' ');

    return 0;
}
