#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

const char s1[] = "Сбой матрицы";
const wchar_t s2[] = L"Сбой матрицы";

int main(void){
    setlocale(LC_ALL, "");
    printf("cahr -> sizeof: %zu bytes, strlen: %d chars\n", sizeof(s1), strlen(s1));
    printf("wchar -> sizeof: %zu bytes, strlen: %d chars", sizeof(s2), wcslen(s2));    
    return 0;
}
