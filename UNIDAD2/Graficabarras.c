#include <stdio.h>


void establecerColorFondo(int color) {
    printf("\033[%dm", color + 10); 
}

void invertirColores() {
    printf("\033[3m"); 
}


void reiniciarFormato() {
    printf("\033[0m");
}

int main() {
    int num_barras, i, j;
    int alturas[7];
    int colores[] = {31, 32, 33, 34, 35, 36, 37}; 
    
    
    printf("¿Cuántas barras quieres? (1-7): ");
    scanf("%d", &num_barras);
    
    printf("¿Cuántas barras quieres? (1-7): ");
    scanf("%d", &num_barras);
    
    for(; num_barras < 1 || num_barras > 7; scanf("%d", &num_barras)) {
        printf("Por favor, introduce un número entre 1 y 7: ");
    }
    
    
    for(i = 0; i < num_barras; i++) {
        printf("Altura de la barra %d: ", i+1);
        scanf("%d", &alturas[i]);
    }
    
    
    int max_altura = 0;
    for(i = 0; i < num_barras; i++) {
        if(alturas[i] > max_altura) {
            max_altura = alturas[i];
        }
    }
    
    
    printf("\nGráfica de barras:\n\n");
    
    
    printf(" ");
    for(i = 0; i < num_barras * 4; i++) {
        printf("-");
    }
    printf("\n");
    
    
    for(i = max_altura; i > 0; i--) {
        printf("|");
        for(j = 0; j < num_barras; j++) {
            if(alturas[j] >= i) {
                establecerColorFondo(colores[j]); 
                invertirColores();               
                printf("***");                  
                reiniciarFormato();             
                printf(" ");
            } else {
                printf("    ");                  
            }
        }
        printf("\b|\n"); 
    }
    
    
    printf(" ");
    for(i = 0; i < num_barras * 4; i++) {
        printf("-");
    }
    printf("\n");
    
    
    printf(" ");
    for(i = 0; i < num_barras; i++) {
        establecerColorFondo(colores[i]);
        invertirColores();
        printf(" %d ", i+1);
        reiniciarFormato();
        if(i < num_barras - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}