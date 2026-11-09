#include <stdio.h>

int main(void){
    int c;
    unsigned int count;
    while((c = getchar()) != EOF) {
        if (c == '.' || c == '?' || c == '!'){
            count++;
        }
    }

    printf("count of sentences is %u\n", count);

    return 0;
}
