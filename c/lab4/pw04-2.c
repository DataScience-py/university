#include <stdio.h>
#include <stdint.h>

int main(void){
    uint8_t r, g, b;
    printf("Input 3 number (1 byte with value from 0 to 255)\n");
    scanf("%hhu %hhu %hhu", &r, &g, &b);
    float val = (float)(r+g+b) / 3.0;
    printf("Size r, g, b: %zu %zu %zu\n", sizeof(r), sizeof(g), sizeof(b));
    unsigned long long v = (unsigned long long)val;
    printf("Result in float %f with size %zu\n", val, sizeof(val));
    printf("Result in unsigned long long %llu with size %zu\n", v, sizeof(v));
    
    return 0;
}
