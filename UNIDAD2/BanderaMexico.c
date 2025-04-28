#include <stdio.h>


void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}


void setColor(const char* color) {
    printf("%s", color);
}


void resetColor() {
    printf("\033[0m");
}

int main() {
    printf("\033[2J"); 

    int altura = 10;
    int ancho = 30;  
    int startX = 20; 
    int startY = 5;  

    for (int fila = 0; fila < altura; fila++) {
        gotoxy(startX, startY + fila);

        
        setColor("\033[7;32m");
        for (int col = 0; col < ancho / 3; col++) {
            printf(" ");
        }

        
        setColor("\033[7;37m");
        for (int col = 0; col < ancho / 3; col++) {
            printf(" ");
        }

        
        setColor("\033[7;31m");
        for (int col = 0; col < ancho / 3; col++) {
            printf(" ");
        }

        resetColor();
    }

    gotoxy(0, startY + altura + 2);
    resetColor();
    return 0;
}
