#include <stdio.h>

#define BUF_SIZE 100

void print(char arr[], int enter){
    for (char *i = arr; *i != '\0'; i++){
        putchar(*i);
    };
    if (enter == 0) {
        return;
    };
    putchar('\n');
}

int str2int(char arr[]){
    int val = 0;
    for (char *i = arr; *i != '\0'; i++){
        val = val * 10 + (*i - '0');
    };
    return val;
}

void int2str(char arr[BUF_SIZE], int val){
    int i = 0;
    int temp[BUF_SIZE];

    if (val == 0){
        arr[0] = '0';
        arr[1] = '\0';
        return;
    };

    while (val > 0){
        temp[i] = (val % 10) + '0';
        val /= 10;
        i++;
    };

    arr[i] = '\0';
    int j = 0;
    while (i > 0){
        i--;
        arr[j] = temp[i];
        j++;
    };
}

int buffer(char buf[BUF_SIZE]){
    int ch;
    for (int i = 0; i < BUF_SIZE; i++){
        ch = getchar();
        if (ch == '\n'){
            buf[i] = '\0';
            break;
        } else if (ch == -1) {
            return -1;
        } else {
            buf[i] = ch;
        }
    }
    return 0;
}


int main(void){
    print("test text: ", 0);
    char ch[BUF_SIZE];
    buffer(ch);
    int2str(ch, str2int(ch));
    print(ch, 1);

    return 0;
}
