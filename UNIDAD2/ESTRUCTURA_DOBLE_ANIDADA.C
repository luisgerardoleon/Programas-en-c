#include <stdio.h>

struct coordenadas {
    char numero[50];
    char calle[50];
    int cp;
};

struct direccion {
    char referencias[50];
    char colonia[50];
    struct coordenadas domicilio;
};

struct estudiantes {
    char nombre[50];
    int id;
    struct direccion casa;
};

int main() {
    int size;
    printf("Inserta el tamaño del arreglo: ");
    scanf("%d", &size);

    struct estudiantes arreglo[size];

    for (int i = 0; i < size; i++) {
        printf("\nIngrese los datos del estudiante %d:\n", i + 1);
        printf("Ingrese el ID: ");
        scanf("%d", &arreglo[i].id);
        printf("Ingresa el nombre: ");
        scanf("%s", arreglo[i].nombre);
        printf("Ingresa la colonia: ");
        scanf("%s", arreglo[i].casa.colonia);
        printf("Ingresa la calle: ");
        scanf("%s", arreglo[i].casa.domicilio.calle);
        printf("Ingresa el número de casa: ");
        scanf("%s", arreglo[i].casa.domicilio.numero);
        printf("Ingresa tu código postal: ");
        scanf("%d", &arreglo[i].casa.domicilio.cp);
    }

    printf("\nLista de estudiantes:\n");
    for (int i = 0; i < size; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        printf("ID: %d\n", arreglo[i].id);
        printf("Nombre: %s\n", arreglo[i].nombre);
        printf("Dirección: Colonia: %s, Calle: %s, Número: %s, CP: %d\n", 
               arreglo[i].casa.colonia, arreglo[i].casa.domicilio.calle, 
               arreglo[i].casa.domicilio.numero, arreglo[i].casa.domicilio.cp);
    }

    return 0;
}
