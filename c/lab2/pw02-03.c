#include <stdio.h>


int main(void){
    int a = 10, b = 010, c = 0x10;
    char d = 'A', e = '\x41', f = '\101'; 
    printf("DEC_10: %d\n", a);
    printf("OCT_10: %d\n", b);
    printf("HEX_10: %d\n", c);
    printf("INT_SUFIX: %d %d %d %d\n", sizeof(a), sizeof(10u), sizeof(10LL), sizeof(10ULL));
    printf("FLOAT_SUFIX: %d %d %d\n", sizeof(1.0f), sizeof(1.0), sizeof(1.0L));
    printf("FLOAT_EQ: %d\n", 0.1==0.1f);
    printf("CHAR_FORMS: %d %d %d\n", d, e, f);
    printf("CHAR_LIT_VAR_STR: %d %d %d\n", sizeof(d), sizeof(e), sizeof(f));
    return 0;
}
