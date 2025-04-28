#include <stdio.h>

union Dato{
    int entero;
    float decimal;
    char texto[20];

};

int main (){
    union Dato variable;

    variable.entero = 42;
    printf("entero: %d\n", variable.entero);


    variable.decimal = 3.14;
    printf("decimal: %d\n", variable.decimal);

    sprintf(variable.texto ,"Hola.c");
    printf("texto: %d\n", variable.texto);

    printf("\n Despues de asignar un texto:\n");
    printf("entero : %d\n", variable.entero);
    printf("decimal: %.2f\n", variable.decimal);
    printf("texto: %s\n ",variable.texto);

    return 0;
}
