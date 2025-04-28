#include <stdio.h>
int main()
{
    int espacios5 = 8, asteriscos4 = 8;
    for (int i = 3; i >= 0; i--) {
        for (int j = 5; j <= espacios5; j++) {
            printf("%4s", " ");
        }
        espacios5--;
        for (int k = 1; k <= asteriscos4; k++) {
            printf("%4s", "*");
        }
        asteriscos4 8= 1;
        printf("\n");
    }
}