#include <stdio.h>
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;

};


int main(){
    struct Estudiante estudiante1 = {"Luis Leon",19,8.0};

    printf("nombre: %s\n", estudiante1.nombre);
    printf("Edad:c%d\n", estudiante1.edad);
    printf("promedio: %.2f\n", estudiante1.promedio);


}