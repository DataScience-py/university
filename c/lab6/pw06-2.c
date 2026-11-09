#include <wchar.h>
#include <locale.h>


int main(void){
    setlocale(LC_ALL, "");
    wchar_t c;
    unsigned int count = 0;
    wprintf(L"Введи немного текста, символ '#' заканчмвает ввод текста.\n");
    while((c = getwchar()) != L'#'){
        if (c == L'а' || c == L'е'){
            count++;
        }
    }
    wprintf(L"Ты ввёл всего 'а' и 'е' символов: %u\n", count);
    return 0;
}
