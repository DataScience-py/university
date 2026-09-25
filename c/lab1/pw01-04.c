#include <stdio.h>


int main(void){
    const int DAYS_PER_YEAR = 365;
    int years = 4, total_days = years * DAYS_PER_YEAR;
    printf("YEASR = %d\nDAYS_PER_YEAR = %d\nTOTAL_DAYS = %d\n", years, DAYS_PER_YEAR, total_days);
    return 0;
}
