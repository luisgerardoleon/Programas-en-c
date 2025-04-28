#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

void llenarMatriz(int matriz[FILAS][COLUMNAS]) {
    printf("\nIngrese la matriz 3x3:\n");
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            printf("numeros [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void llenarVector(int vector[FILAS]) {
    printf("\nIngrese los  vectores 3x1:\n");
    for(int i = 0; i < FILAS; i++) {
        printf("vector [%d]: ", i);
        scanf("%d", &vector[i]);
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

void mostrarVector(int vector[FILAS]) {
    printf("\nVector 3x1:\n");
    for(int i = 0; i < FILAS; i++) {
        printf("%d\n", vector[i]);
    }
}

void multiplicarMatrizVector(int matriz[FILAS][COLUMNAS], int vector[FILAS], int resultado[FILAS]) {
    for(int i = 0; i < FILAS; i++) {
        resultado[i] = 0;
        for(int j = 0; j < COLUMNAS; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }
}

int main() {
    int matriz[FILAS][COLUMNAS];
    int vector[FILAS];
    int resultado[FILAS];
    

    llenarMatriz(matriz);
    llenarVector(vector);

    printf("\nDatos ingresados:");
    mostrarMatriz(matriz);
    mostrarVector(vector);
    

    multiplicarMatrizVector(matriz, vector, resultado);
    
    printf("\nResultado de la multiplicacion:\n");
    mostrarVector(resultado);
    
    return 0;
}