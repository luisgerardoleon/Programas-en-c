#include <stdio.h>

// Códigos ANSI para colores y posición
#define VERDE "\x1B[42m"
#define ROJO "\x1B[41m"
#define SUBRAYADO "\x1B[4m"
#define BLANCO "\x1B[37m"
#define RESET "\x1B[0m"
#define GOTOXY(x,y) printf("\x1B[%d;%dH", (y), (x))

void dibujar_marco(int x, int y, int ancho, int alto) {
    // Marco superior
    GOTOXY(x, y);
    for(int i = 0; i < ancho; i++) printf("*");
    
    // Laterales
    for(int i = 1; i < alto-1; i++) {
        GOTOXY(x, y+i);
        printf("*");
        GOTOXY(x+ancho-1, y+i);
        printf("*");
    }
    
    // Marco inferior
    GOTOXY(x, y+alto-1);
    for(int i = 0; i < ancho; i++) printf("*");
}

void mostrar_menu(int *opc) {
    dibujar_marco(10, 5, 25, 8);
    
    GOTOXY(12, 6); printf("1. Suma de matrices");
    GOTOXY(12, 7); printf("2. Resta de matrices");
    GOTOXY(12, 8); printf("3. Multiplicacion");
    GOTOXY(12, 9); printf("4. Determinante");
    GOTOXY(12, 10); printf("5. Salir");
    
    dibujar_marco(30, 10, 10, 3);
    GOTOXY(32, 11); printf("opc: ");
    GOTOXY(36, 11); scanf("%d", opc);
}

void dibujar_matriz(int x, int y, int matriz[3][3], const char *color) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            GOTOXY(x + j*4, y + i*2);
            printf("%s_%d_%s", color, matriz[i][j], RESET);
        }
    }
}

void ingresar_matriz(int x, int y, int matriz[3][3], const char *nombre) {
    dibujar_marco(x-2, y-1, 14, 8);
    GOTOXY(x, y-1); printf("%s", nombre);
    
    // Dibujar cuadrícula
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            GOTOXY(x + j*4, y + i*2);
            printf("_");
        }
    }
    
    // Ingresar valores
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            GOTOXY(x + j*4, y + i*2);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void operar_matrices(int opcion) {
    int matrizA[3][3] = {{0}};
    int matrizB[3][3] = {{0}};
    int resultado[3][3] = {{0}};
    
    // Limpiar pantalla
    printf("\x1B[2J");
    
    // Ingresar matriz A (verde)
    ingresar_matriz(10, 5, matrizA, "MATRIZ A");
    dibujar_matriz(10, 5, matrizA, VERDE);
    
    // Ingresar matriz B (rojo) si es necesario
    if(opcion != 4) {
        ingresar_matriz(30, 5, matrizB, "MATRIZ B");
        dibujar_matriz(30, 5, matrizB, ROJO);
    }
    
    // Realizar operación
    switch(opcion) {
        case 1: // Suma
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    resultado[i][j] = matrizA[i][j] + matrizB[i][j];
            break;
            
        case 2: // Resta
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    resultado[i][j] = matrizA[i][j] - matrizB[i][j];
            break;
            
        case 3: // Multiplicación
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    for(int k = 0; k < 3; k++)
                        resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            break;
            
        case 4: // Determinante
            int det = matrizA[0][0]*(matrizA[1][1]*matrizA[2][2] - matrizA[1][2]*matrizA[2][1])
                    - matrizA[0][1]*(matrizA[1][0]*matrizA[2][2] - matrizA[1][2]*matrizA[2][0])
                    + matrizA[0][2]*(matrizA[1][0]*matrizA[2][1] - matrizA[1][1]*matrizA[2][0]);
            
            dibujar_marco(20, 12, 20, 5);
            GOTOXY(22, 14); printf("%sDETERMINANTE: %d%s", SUBRAYADO BLANCO, det, RESET);
            GOTOXY(1, 20); return;
    }
    
    // Mostrar resultado
    ingresar_matriz(20, 12, resultado, "RESULTADO");
    dibujar_matriz(20, 12, resultado, SUBRAYADO BLANCO);
    GOTOXY(1, 20);
}

int main() {
    int opcion = 0;
    
    do {
        printf("\x1B[2J"); // Limpiar pantalla
        mostrar_menu(&opcion);
        
        if(opcion >= 1 && opcion <= 4) {
            operar_matrices(opcion);
            printf("Presione Enter para continuar...");
            getchar(); getchar();
        }
        
    } while(opcion != 5);
    
    printf("\x1B[2J");
    GOTOXY(15, 10); printf("%sPROGRAMA TERMINADO%s", SUBRAYADO BLANCO, RESET);
    GOTOXY(1, 12);
    return 0;
}