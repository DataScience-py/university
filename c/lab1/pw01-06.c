#include <stdio.h>
#define year 365
#define day 24
#define hour 3600

int main(void){
    int y = 18;
    printf("Тики: %d|Часы: %d|Дни: %d|Годы %d\n", y * year * day * hour, y*year*day, y*year, y);
    return 0;
}
