#include <stdio.h>
#include <ctype.h>


int main(void){
    char c;
    printf("Input a some ebglish text with '#' means end of text\n");
    unsigned int count_space = 0;
    while((c = getchar()) != '#'){
        if (isspace(c)){
            count_space++;
        }
    }
    printf("You input %u spaces\n", count_space);

    return 0;
}
