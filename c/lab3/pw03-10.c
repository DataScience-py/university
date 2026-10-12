#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "");
    wchar_t s1[20], s2[20], s3[20];
    wscanf(L"%ls", s1);
    wscanf(L"%ls", s2);
    wscanf(L"%ls", s3);

    wprintf(L"%-15ls|%20ls|%.5ls\n", s1, s2, s3);
    return 0;
}
