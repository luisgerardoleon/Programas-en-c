#include <stdio.h>

#define DIM 3


typedef struct {
    int numerador;
    int denominador;
} Fraccion;

void llenarMatrizFracciones(Fraccion matriz[DIM][DIM], char nombre) {
    printf("\nIngrese la matriz %c (3x3) como fracciones (a/b):\n", nombre);
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            printf("Matriz %c [%d][%d]: ", nombre, i, j);
            scanf("%d/%d", &matriz[i][j].numerador, &matriz[i][j].denominador);
 
        }
    }
}

void mostrarMatrizFracciones(Fraccion matriz[DIM][DIM], char* nombre) {
    printf("\nMatriz %s (3x3):\n", nombre);
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            printf("%d/%d\t", matriz[i][j].numerador, matriz[i][j].denominador);
        }
        printf("\n");
    }
}

void multiplicarElementos(Fraccion A[DIM][DIM], Fraccion B[DIM][DIM], Fraccion resultado[DIM][DIM]) {
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {

            resultado[i][j].numerador = A[i][j].numerador * B[i][j].numerador;
            resultado[i][j].denominador = A[i][j].denominador * B[i][j].denominador;
        }
    }
}

int main() {
    Fraccion A[DIM][DIM], B[DIM][DIM], resultado[DIM][DIM];
    
    
    llenarMatrizFracciones(A, 'A');
    llenarMatrizFracciones(B, 'B');
    
   
    printf("\nMatrices ingresadas:");
    mostrarMatrizFracciones(A, "A");
    mostrarMatrizFracciones(B, "B");
    

    multiplicarElementos(A, B, resultado);
    

    printf("\nresultado:");
    mostrarMatrizFracciones(resultado, "Resultado");
    
    return 0;
}