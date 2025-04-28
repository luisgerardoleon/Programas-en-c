#include <stdio.h>

void setColor(const char* color) {
    printf("%s", color);
}

void resetColor() {
    printf("\033[0m");
}

int main() {
    int altura = 10;  
    int ancho = 30;   

    for (int fila = 0; fila < altura; fila++) {
        
        setColor("\033[42m");
        for (int col = 0; col < ancho / 3; col++) {
            printf(" ");
        }

        
        setColor("\033[47m");
        for (int col = 0; col < ancho / 3; col++) {
            printf(" ");
        }

    
        setColor("\033[41m");
        for (int col = 0; col < ancho / 3; col++) {
            printf(" ");
        }

        resetColor();
        printf("\n");
    }

    return 0;
}