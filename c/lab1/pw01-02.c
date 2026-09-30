#include <stdio.h>


int main(void){
    printf("[Голубчиков А.А.]\n");

    printf("%*s\n", 23, "Голубчиков"); // UTF-8 name 20 bytes 3 spaces

    printf("%*s\n", 19, "А.А."); // UTF-8 

    printf("]А.А. Голубчиков[\n");

    return 0;
}

