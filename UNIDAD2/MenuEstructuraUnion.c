#include <stdio.h>

#define FILAS 2
#define COLUMNAS 2

typedef struct {
    char nombre[50];
    int edad;
} perro;

typedef struct {
    char nombre[50];
    float edad;
} gato;

typedef union {
    perro perro;
    gato gato;
} Dato;

typedef struct {
    Dato valor;
    int tipo;
} celda;

int main() {
    celda matriz[FILAS][COLUMNAS];
    int opcion;

    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            printf("Celda [%d][%d]:\n", i, j);
            printf("1. Ingresar perro\n");
            printf("2. Ingresar gato\n");
            printf("Seleccione opcion: ");
            scanf("%d", &opcion);

            switch(opcion) {
                case 1:
                    printf("Nombre del perro: ");
                    scanf("%s", matriz[i][j].valor.perro.nombre);
                    printf("Edad del perro: ");
                    scanf("%d", &matriz[i][j].valor.perro.edad);
                    matriz[i][j].tipo = 1;
                    break;

                case 2:
                    printf("Nombre del gato: ");
                    scanf("%s", matriz[i][j].valor.gato.nombre);
                    printf("edad del gato: ");
                    scanf("%f", &matriz[i][j].valor.gato.edad);
                    matriz[i][j].tipo = 2;
                    break;
            }
        }
    }

    printf("\nContenido de la matriz:\n");
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            printf("\nCelda [%d][%d]: ", i, j);
            
            if(matriz[i][j].tipo == 1) {
                printf("%s,%d anios", 
                       matriz[i][j].valor.perro.nombre,
                       matriz[i][j].valor.perro.edad);
            } else {
                printf("%s %d",
                       matriz[i][j].valor.gato.nombre,
                       matriz[i][j].valor.gato.edad);
            }
        }
    }

    return 0;
}