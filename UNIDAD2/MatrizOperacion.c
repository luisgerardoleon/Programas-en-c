#include <stdio.h>

#define FILAS 3
#define COLUMNAS 6  

int main() {
    int matriz[FILAS][COLUMNAS];

    printf("Ingrese los valores para la matriz :\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (j < 2) {  
                printf("Fila %d - Columna %d: ", i + 1, j + 1);
                scanf("%d", &matriz[i][j]);
            } else {
                matriz[i][j] = 0;  
            }
        }
    }

    
    for (int i = 0; i < FILAS; i++) {
        matriz[i][2] = matriz[i][0] + matriz[i][1];  
        matriz[i][3] = matriz[i][0] - matriz[i][1];  
        matriz[i][4] = matriz[i][0] * matriz[i][1];  
        if (matriz[i][1] != 0) {
            matriz[i][5] = matriz[i][0] / matriz[i][1];  
        } 
            
        
    }

    
    printf("\nMatriz con resultados:\n");
    printf("%-10s | %-10s | %-10s | %-10s | %-10s | %-10s\n", "Val1", "Val2", "Suma", "Resta", "Multi", "Div");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (j == 5 && matriz[i][5] == -1) {  
                printf("%-10s | ", "ERROR");
            } else {
                printf("%-10d | ", matriz[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}