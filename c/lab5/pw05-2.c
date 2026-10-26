#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 5
#define R (HEIGHT / 2)

int main(void) {
    const char ch[] = "* ";

    for (int y = -R; y <= R; y++) {
        for (int x = -R; x <= R; x++) {
            printf("%c", ch[(abs(x) + abs(y)) != R]);
        }
        printf("\n");
    }

    return 0;
}
