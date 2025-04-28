#include <stdio.h>

#define FILAS 2
#define COLUMNAS 2

typedef struct {
    char nombre[50];
    int edad;
} persona;

typedef struct {
    char producto[50];
    float precio;
} producto;

typedef union {
    persona persona;
    producto producto;
} Dato;

typedef struct {
    Dato valor;
    int tipo;
} celda;

int main() {
    celda matriz[FILAS][COLUMNAS];

    strcpy (matriz[0][0].valor.persona.nombre, "roberto");
    matriz[0][0].valor.persona.edad = 25;
    matriz[0][0].tipo = 1;

    strcpy(matriz[0][1].valor.persona.nombre, "alejandro");
    matriz[0][1].valor.persona.edad = 30;
    matriz[0][1].tipo = 1;

    strcpy(matriz[1][0].valor.producto.producto, "conejo");
    matriz[1][0].valor.producto.precio = 88.99;
    matriz[1][0].tipo = 2;

    strcpy(matriz[1][1].valor.producto.producto, "Golden");
    matriz[1][1].valor.producto.precio = 99.99;
    matriz[1][1].tipo = 2;

    printf("Recorriendo la matriz de uniones con estructuras:\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Celda [%d][%d]: ", i, j);
            
            if (matriz[i][j].tipo == 1) {
                printf("Persona - Nombre: %s, Edad: %d\n", 
                    matriz[i][j].valor.persona.nombre,
                    matriz[i][j].valor.persona.edad);
            } else if (matriz[i][j].tipo == 2) {
                printf("Producto - Nombre: %s, Precio: %.2f\n",
                    matriz[i][j].valor.producto.producto,
                    matriz[i][j].valor.producto.precio);
            }
        }    
    }

    return 0;
}