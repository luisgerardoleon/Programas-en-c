#include <stdio.h>

struct Persona {
    char nombre[50];
    int edad;
    char mail[50];
    int matricula;
    char telefono[50];
    char curp[50];
    char ColorPiel[50];
    char ColorOjos[50];
};

int main() {
    int size;
    
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &size);

    struct Persona Estudiantes[size];

    for (int i = 0; i < size; i++) {
        printf("\nDame el nombre del estudiante %d: ", i + 1);
        scanf("%s", Estudiantes[i].nombre);

        printf("Dame la edad del estudiante %d: ", i + 1);
        scanf("%d", &Estudiantes[i].edad);

        printf("Dame el mail del estudiante %d: ", i + 1);
        scanf("%s", Estudiantes[i].mail);

        printf("Dame la matrícula del estudiante %d: ", i + 1);
        scanf("%d", &Estudiantes[i].matricula);

        printf("Dame el teléfono del estudiante %d: ", i + 1);
        scanf("%s", Estudiantes[i].telefono);

        printf("Dame el CURP del estudiante %d: ", i + 1);
        scanf("%s", Estudiantes[i].curp);

        printf("Dame el color de piel del estudiante %d: ", i + 1);
        scanf("%s", Estudiantes[i].ColorPiel);

        printf("Dame el color de ojos del estudiante %d: ", i + 1);
        scanf("%s", Estudiantes[i].ColorOjos);
    }

    printf("\nInformación de los estudiantes ingresada:\n");
    for (int i = 0; i < size; i++) {
        printf("\nEstudiante %d\n", i + 1);
        printf("Nombre: %s\n", Estudiantes[i].nombre);
        printf("Edad: %d\n", Estudiantes[i].edad);
        printf("Mail: %s\n", Estudiantes[i].mail);
        printf("Matrícula: %d\n", Estudiantes[i].matricula);
        printf("Teléfono: %s\n", Estudiantes[i].telefono);
        printf("CURP: %s\n", Estudiantes[i].curp);
        printf("Color de piel: %s\n", Estudiantes[i].ColorPiel);
        printf("Color de ojos: %s\n", Estudiantes[i].ColorOjos);
    }

    return 0;
}
