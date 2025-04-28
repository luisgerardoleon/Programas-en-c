#include <stdio.h>

#define DIM 3  

void llenarMatriz(int matriz[DIM][DIM]) {
    printf("\nIngrese la matriz (3x3):\n");
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            printf("Posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[DIM][DIM], char* nombre) {
    printf("\nMatriz %s (3x3):\n", nombre);
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrices(int A[DIM][DIM], int B[DIM][DIM], int resultado[DIM][DIM]) {
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            resultado[i][j] = 0;
            for(int k = 0; k < DIM; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrizPotencia(int matriz[DIM][DIM], int resultado[DIM][DIM], int exponente) {
    int temp[DIM][DIM];
    
    if(exponente == 0) {
        for(int i = 0; i < DIM; i++) {
            for(int j = 0; j < DIM; j++) {
                resultado[i][j] = (i == j) ? 1 : 0;
            }
        }
        return;
    }
    

    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            resultado[i][j] = matriz[i][j];
        }
    }
    
   
    for(int e = 1; e < exponente; e++) {
 
        for(int i = 0; i < DIM; i++) {
            for(int j = 0; j < DIM; j++) {
                temp[i][j] = resultado[i][j];
            }
        }
        
        
        multiplicarMatrices(temp, matriz, resultado);
    }
}

int main() {
    int matriz[DIM][DIM], resultado[DIM][DIM];
    int exponente;
    
   
    llenarMatriz(matriz);
    mostrarMatriz(matriz, "original");
    
  
    printf("\nIngrese el exponente (entero >= 0): ");
    scanf("%d", &exponente);
    
    if(exponente < 0) {
        printf("Error: El exponente debe ser >= 0\n");
        return 1;
    }
    
    
    matrizPotencia(matriz, resultado, exponente);
    
   
    printf("\nResultado (Matriz elevada a %d):", exponente);
    mostrarMatriz(resultado, "resultado");
    
    return 0;
}