#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

void llenarMatriz(int matriz[FILAS][COLUMNAS], char nombre) {
    printf("\nIngrese la matriz %c (3x3):\n", nombre);
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            printf("Matriz %c [%d][%d]: ", nombre, i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[FILAS][COLUMNAS], char nombre) {
    printf("\nMatriz %c (3x3):\n", nombre);
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrices(int A[FILAS][COLUMNAS], int B[FILAS][COLUMNAS],int resultado[FILAS][COLUMNAS]) {
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            resultado[i][j] = 0;
            for(int k = 0; k < COLUMNAS; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[FILAS][COLUMNAS], B[FILAS][COLUMNAS], resultado[FILAS][COLUMNAS];
    
    
    llenarMatriz(A, 'A');
    llenarMatriz(B, 'B');
    
   
    printf("\nMatrices ingresadas:");
    mostrarMatriz(A, 'A');
    mostrarMatriz(B, 'B');
    
   
    multiplicarMatrices(A, B, resultado);
    
    
    printf("\nResultado de la multiplicación (A * B):");
    mostrarMatriz(resultado, 'R');
    
    return 0;
}