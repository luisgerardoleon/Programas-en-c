#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3


void llenarMatriz(char *nombre, int matriz[FILAS][COLUMNAS]) {

printf("Nombre de la matriz: %s\n", nombre);
    
for (int i = 0; i < FILAS; i++) {
        
    
for (int j = 0; j < COLUMNAS; j++) {
            
printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            
scanf("%d", &matriz[i][j]);
        
}
    
}

}

void saveMatriz(int matriz[FILAS][COLUMNAS]) {
    
FILE *archivo = fopen("../matriz.txt", "w");
    
if (archivo == NULL) {
        
printf("Error al abrir el archivo.\n");
        
return;
    
}
    
    
for (int i = 0; i < FILAS; i++) {
        
for (int j = 0; j < COLUMNAS; j++) {
            
fprintf(archivo, "%d ", matriz[i][j]);
        
}
        
fprintf(archivo, "\n");
    
}
    
   
fclose(archivo);
    
printf("Matriz guardada en 'matriz.txt' exitosamente.\n");

}


void imprimirMatriz(char *nombre, int matriz[FILAS][COLUMNAS]) {

printf("Nombre de la matriz: %s\n", nombre);

printf("Matriz ingresada:\n");
    
for (int i = 0; i < FILAS; i++) {
        
for (int j = 0; j < COLUMNAS; j++) {
        
printf("%4d ", matriz[i][j]);
        
}
        
printf("\n");
    
}

}

void sumarMatriz(int matriz1[FILAS][COLUMNAS], 
                
int matriz2[FILAS][COLUMNAS], 
                
int matrizr[FILAS][COLUMNAS]) {
    
for (int i = 0; i < FILAS; i++) {
        
for (int j = 0; j < COLUMNAS; j++) {
            
matrizr[i][j] = matriz1[i][j] + matriz2[i][j];
        
}
    
}

}

void multiplicarescalar(int matriz1[FILAS][COLUMNAS],
                      
int escalar,
                    
int matrizR[FILAS][COLUMNAS]) {
    
for (int i = 0; i < FILAS; i++) {
        
for (int j = 0; j < COLUMNAS; j++) {
            
matrizR[i][j] = matriz1[i][j] * escalar;
        
}
    
}


}

int calcularDeterminante(int matriz[FILAS][COLUMNAS]) {
    int det = 0;
    for(int i = 0; i < 3; i++) {
        int pos = 1, neg = 1;
        for(int j = 0; j < 3; j++) {
            pos *= matriz[j][(i+j)%3];
            neg *= matriz[j][(i-j+3)%3];
        }
        det += pos - neg;
    }
    return det;
}

int main() {
    int escalar = 2;
    
    
int matriz_a[FILAS][COLUMNAS];

int matriz_b[FILAS][COLUMNAS];
    
int matriz_r[FILAS][COLUMNAS];
    
int matriz_escalar[FILAS][COLUMNAS];

   
llenarMatriz("Matriz A", matriz_a);
   
llenarMatriz("Matriz B", matriz_b);

 
imprimirMatriz("Matriz A", matriz_a);

imprimirMatriz("Matriz B", matriz_b);

printf("Determinante de A: %d\n", calcularDeterminante(matriz_a));
printf("Determinante de B: %d\n", calcularDeterminante(matriz_b));

sumarMatriz(matriz_a, matriz_b, matriz_r);

imprimirMatriz("SUMA A+B", matriz_r);
printf("Determinante de A+B: %d\n", calcularDeterminante(matriz_r));

multiplicarescalar(matriz_a, escalar, matriz_escalar);

imprimirMatriz("Matriz A multiplicada por escalar", matriz_escalar);
printf("Determinante de A*escalar: %d\n", calcularDeterminante(matriz_escalar));
    

saveMatriz(matriz_r); 
}
