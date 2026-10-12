#include <stdio.h>
#include <string.h>

int main(void){
    char str1[20] = "SibSUTIS";
    char str2[20] = "СибГУТИ";

    printf("%s\n", str1);
    printf("SIZEOF: %zu\n", sizeof(str1));
    printf("STRLEN: %zu\n", strlen(str1));
    printf("FREE_BYTES: %d\n", sizeof(str1) - strlen(str1) - 1);
    
    printf("\n\n%s\n", str2);
    printf("SIZEOF: %zu\n", sizeof(str2));
    printf("STRLEN: %zu\n", strlen(str2));
    printf("FREE_BYTES: %d\n", sizeof(str2) - strlen(str2) - 1);
    
    return 0;
}
