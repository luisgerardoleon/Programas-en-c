#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

void llenarMatriz(int matriz[FILAS][COLUMNAS]) {
    printf("\nIngrese la matriz 3x3:\n");
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[FILAS][COLUMNAS]) {
    printf("\nMatriz 3x3:\n");
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void transponerMatriz(int matriz[FILAS][COLUMNAS]) {
    for(int i = 0; i < FILAS; i++) {
        for(int j = i+1; j < COLUMNAS; j++) {
           
            int temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;
        }
    }
}

int main() {
    int matriz[FILAS][COLUMNAS];
    
    llenarMatriz(matriz);
    
    printf("\nMatriz original:");
    mostrarMatriz(matriz);
    
    transponerMatriz(matriz);
    
    printf("\nMatriz transpuesta:");
    mostrarMatriz(matriz);
    
    return 0;
}