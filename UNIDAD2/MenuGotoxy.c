#include <stdio.h>
 
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}
 
int main() {
  
    printf("\033[2J"); // Limpia la pantalla
    setColor("\033[7;36m");
    gotoxy(15, 1);
    printf("calculadora basica de gotoxy y switch case");

    setColor("\033[4;30m");
    gotoxy(10, 3);
    printf("menu de operaciones ");
    


    setColor("\033[7;33m");
    gotoxy(10, 5);
    printf("1.: ");
    setColor("\033[0m");
    gotoxy(15, 5);
    printf("suma");

    setColor("\033[7;31m");
    gotoxy(10, 6);
    printf("2.: ");
    setColor("\033[0m");
    gotoxy(15, 6);
    printf("resta");

    setColor("\033[7;32m");
    gotoxy(10, 7);
    printf("3.: ");
    setColor("\033[0m");
    gotoxy(15, 7);
    printf("multiplicacion");

    setColor("\033[7;34m");
    gotoxy(10, 8);
    printf("4.: ");
    setColor("\033[0m");
    gotoxy(15, 8);
    printf("division");

    setColor("\033[0m");
    gotoxy(10, 10);
    printf("seleccione opcion del  ");

    setColor("\033[7;34m");
    gotoxy(35, 10);
    printf("1 al 4");

    setColor("\033[0m");


 


 
    
 
    return 0;
}