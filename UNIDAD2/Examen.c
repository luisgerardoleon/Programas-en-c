#include <stdio.h>

#define AZUL "\033[44m"
#define ROJO "\033[41m"
#define AMARILLO_SUB "\033[4;43m"
#define RESET "\033[0m"


void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}


void limpiarPantalla() {
    printf("\033[2J");
    fflush(stdout);
}


int mostrar_menu() {
    limpiarPantalla();
    printf("*****************************\n");
    printf("*          menu             *\n");
    printf("*1 suma de matriz           *\n");
    printf("*2 resta de matriz          *\n");
    printf("*3 multiplicacion de matriz *\n");
    printf("*4 determinante             *\n");
    printf("*                      opc_ *\n");
    printf("*****************************\n");

    gotoxy(27, 10); 
    int opcion;
    scanf("%d", &opcion);
    return opcion;
}


void capturar_matriz(int matriz[3][3], int x, int y, const char* color) {
    gotoxy(1, y - 2);
    printf("Ingrese la matriz:\n");

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gotoxy(x + j * 5 + 1, y + i);  
            printf("%s    %s", color, RESET);  
        }
    }

   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gotoxy(x + j * 5 + 1, y + i);  
            scanf("%d", &matriz[i][j]);  
        }
    }
}


void mostrar_matriz_coloreada(int matriz[3][3], int x, int y, const char* color) {
    for (int i = 0; i < 3; i++) {
        gotoxy(x, y + i);  
        for (int j = 0; j < 3; j++) {
            printf("%s%4d%s ", color, matriz[i][j], RESET); 
            scanf("%d",matriz[i][j]);
        }
    }
}


int determinante_sarrus(int m[3][3]) {
    int det = 0;
    det = m[0][0] * m[1][1] * m[2][2]
        + m[0][1] * m[1][2] * m[2][0]
        + m[0][2] * m[1][0] * m[2][1]
        - m[0][2] * m[1][1] * m[2][0]
        - m[0][0] * m[1][2] * m[2][1]
        - m[0][1] * m[1][0] * m[2][2];
    return det;
}

int main() {
    int matrizA[3][3], matrizB[3][3], resultado[3][3];
    int opcion = mostrar_menu();

    if (opcion >= 1 && opcion <= 4) {
        capturar_matriz(matrizA, 5, 20, AZUL);

        if (opcion != 4) {
            capturar_matriz(matrizB, 30, 30, ROJO);
        }

        if (opcion == 1) { 
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    resultado[i][j] = matrizA[i][j] + matrizB[i][j];

            gotoxy(20, 13);
            printf("Resultado (Suma):");
            mostrar_matriz_coloreada(resultado, 5, 40, AMARILLO_SUB);

        } else if (opcion == 2) { 
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    resultado[i][j] = matrizA[i][j] - matrizB[i][j];

            gotoxy(30, 13);
            printf("Resultado (Resta):");
            mostrar_matriz_coloreada(resultado, 5, 40, AMARILLO_SUB);

        } else if (opcion == 3) {
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                    resultado[i][j] = 0;
                    for (int k = 0; k < 3; k++)
                        resultado[i][j] += matrizA[i][k] * matrizB[k][j];
                }

            gotoxy(40, 13);
            printf("Resultado (Multiplicación):");
            mostrar_matriz_coloreada(resultado, 5, 40, AMARILLO_SUB);

        } else if (opcion == 4) { 
            int det = determinante_sarrus(matrizA);
            gotoxy(5, 40);
            printf("Determinante: %s%d%s\n", AMARILLO_SUB, det, RESET);
        }
    } else {
        gotoxy(50, 40);
        printf("Opción inválida.");
    }

    gotoxy(1, 40);
    printf("\n\n");
    return 0;
}
