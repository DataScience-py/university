#include <stdio.h>
#include <string.h>

int main(void){
    char str1[15] = "", str2[15] = "";
    scanf("%s %s", str1, str2);
    printf("%s-%s\n", str1, str2);
    printf("TOTAL_LEN: %d\n", strlen(str1) + strlen(str2));
    return 0;
}
