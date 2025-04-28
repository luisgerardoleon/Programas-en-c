#include <stdio.h>

void gotoxy (int x, int y){
    printf("\033[%d;%dH", x, y);
}

int main(){
    printf("\033[2J");
    gotoxy(10, 10);
    printf("Hola desde (10,5)");
    return 0;
}