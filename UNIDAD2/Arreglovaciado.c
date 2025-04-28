#include <stdio.h>


int tieneRaizExacta(int num) {
    for (int i = 0; i <= num; i++) {
        if (i * i == num) {
            return 1; 
        }
    }
    return 0; 
}


int calcularRaiz(int num) {
    for (int i = 0; i <= num; i++) {
        if (i * i == num) {
            return i;
        }
    }
    return 0;
}


void llenarMatriz(int n, char matriz[n][n]) {
    printf("\nIngrese %d caracteres:\n", n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Posición [%d][%d]: ", i, j);
            scanf(" %c", &matriz[i][j]);
        }
    }
}


void imprimirMatriz(int n, char matriz[n][n]) {
    printf("\nMatriz (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}


void matrizArregloLineal(int n, char matriz[n][n], char arreglo[]) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arreglo[index++] = matriz[i][j];
        }
    }
}


void imprimirArregloLineal(int size, char arreglo[]) {
    printf("\nArreglo lineal:\n");
    for (int i = 0; i < size; i++) {
        printf("%c ", arreglo[i]);
    }
    printf("\n");
}

int main() {
    int num, n, valido = 0;
    

    for (; !valido; ) {
        printf("Ingrese un número con raíz exacta (ej: 4, 9, 16...): ");
        scanf("%d", &num);
        
        if (tieneRaizExacta(num)) {
            valido = 1;
        } else {
            printf("%d no tiene raíz exacta.\n", num);
        }
    }
    
 
    n = calcularRaiz(num);
    char matriz[n][n];
    

    llenarMatriz(n, matriz);
    imprimirMatriz(n, matriz);

    char arregloLineal[n * n];
    matrizArregloLineal(n, matriz, arregloLineal);
    imprimirArregloLineal(n * n, arregloLineal);
    
    return 0;
}