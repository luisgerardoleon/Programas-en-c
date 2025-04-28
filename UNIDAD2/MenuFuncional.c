#include <stdio.h>
 
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}
 
int main() {
    int opc;
    printf("\033[2J"); // Limpia la pantalla

    setColor("\033[7;32m");
    gotoxy(5, 7);
    printf("Calculadora Basica de gotoxy y switch-case:");
    setColor("\033[0m");
    
    setColor("\033[4;30m");
    gotoxy(5, 8);
    printf("Menu de operaciones:");
    setColor("\033[0m");

    setColor("\033[7;31m");
    gotoxy(6, 13);
    printf("1. ");
    setColor("\033[0m");
    gotoxy(7, 13);
    printf("Suma\n");

    setColor("\033[7;32m");
    gotoxy(6, 14);
    printf("2. ");
    setColor("\033[0m");
    gotoxy(7, 15);
    printf("Resta\n");


    setColor("\033[7;33m");
    gotoxy(6, 15);
    printf("3. ");
    setColor("\033[0m");
    gotoxy(7, 16);
    printf("Multiplicacion\n ");

    setColor("\033[7;37m");
    gotoxy(6, 18);
    printf("4. ");
    setColor("\033[0m");
    gotoxy(7, 18);
    printf("Division\n ");

    gotoxy(5, 18);
    printf("Seleccione una opcion");
    setColor("\033[7;37m");
    gotoxy(28, 18);
    printf("(1-4)");
    setColor("\033[0m");

    scanf("%d", &opc);

    printf("\033[2J"); // Limpia la pantalla
    int num1;
    int num2;
    gotoxy(5, 7);
    printf("Ingrese el primer numero\n");
    scanf("%d", &num1);
    gotoxy(5, 10);
    printf("ingrese el segundo numero\n");
    scanf("%d", &num2);

    printf("\033[2J"); // Limpia la pantalla

    switch(opc){
        case 1:
            gotoxy(5, 7);
            printf("Suma");
            int suma = num1 + num2;
            gotoxy(5, 8);
            printf("Resultado");
            gotoxy(15, 8);
            setColor("\033[7;31m");
            printf("%d", suma);
            setColor("\033[0m");
        break;

        case 2:
            gotoxy(5, 7);
            printf("Resta");
            int resta = num1 - num2;
            gotoxy(5, 8);
            printf("Resultado");
            gotoxy(15, 8);
            setColor("\033[7;32m");
            printf("%d", resta);
            setColor("\033[0m");

        break;

        case 3:
        gotoxy(5, 7);
        printf("multiplicacion");
        int mul = num1 / num2;
        gotoxy(5, 8);
        printf("Resultado");
        gotoxy(15, 8);
        setColor("\033[7;33m");
        printf("%d", mul);
        setColor("\033[0m");

        break;

        case 4:
        if(num2 >0){
        gotoxy(5, 7);
        printf("Division");
        float div = num1 / num2;
        gotoxy(5, 8);
        printf("Resultado");
        gotoxy(15, 8);
        setColor("\033[7;37m");
        printf("%.2f", div);
        setColor("\033[0m");
        }else{
            printf("No se puede");
        }
        break;

        default:
        gotoxy(5, 7);
            printf("%s\n","no ha seleccionado una opcion valida");
        break;
    }
 
    return 0;
}