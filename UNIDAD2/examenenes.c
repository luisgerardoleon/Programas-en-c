#include <stdio.h>

// Códigos ANSI para colores y posición
#define AZUL "\033[44m"
#define ROJO "\033[41m"
#define AMARILLO_SUB "\033[4;43m"
#define RESET "\033[0m"

// Posiciona el cursor en (x,y)
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

// Limpia pantalla
void limpiarPantalla() {
    printf("\033[2J");
    gotoxy(1, 1);
}

// Dibuja un marco de asteriscos
void dibujar_marco(int x, int y, int ancho, int alto) {
    for (int i = 0; i < alto; i++) {
        gotoxy(x, y + i);
        for (int j = 0; j < ancho; j++) {
            printf(i == 0 || i == alto - 1 || j == 0 || j == ancho - 1 ? "*" : " ");
        }
    }
}

// Muestra el menú y captura la opción
int mostrar_menu() {
    limpiarPantalla();

    // Marco del menú
    dibujar_marco(10, 5, 25, 8);

    // Opciones del menú
    gotoxy(12, 6); printf("1. Suma de matrices");
    gotoxy(12, 7); printf("2. Resta de matrices");
    gotoxy(12, 8); printf("3. Multiplicacion");
    gotoxy(12, 9); printf("4. Determinante");
    gotoxy(12, 10); printf("5. Salir");

    // Campo para ingresar opción
    dibujar_marco(30, 10, 10, 3);
    gotoxy(32, 11); printf("opc: _");
    gotoxy(36, 11);

    int opcion;
    scanf("%d", &opcion);
    return opcion;
}

// Captura una matriz mostrando casillas para ingresar datos
void capturar_matriz(int matriz[3][3], int x, int y, const char* color, const char* nombre) {
    // Título de la matriz
    gotoxy(x, y - 2); printf("%s", nombre);

    // Dibujar casillas para ingresar datos
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gotoxy(x + j * 6, y + i * 2); // Ajusté la posición para alineación
            printf("%s    %s", color, RESET);
        }
    }

    // Captura los valores de la matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gotoxy(x + j * 6 + 1, y + i * 2 + 1); // Posiciona el cursor para capturar el valor
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Muestra una matriz con color
void mostrar_matriz(int matriz[3][3], int x, int y, const char* color) {
    for (int i = 0; i < 3; i++) {
        gotoxy(x, y + i);
        for (int j = 0; j < 3; j++) {
            printf("%s%4d%s ", color, matriz[i][j], RESET);
        }
    }
}

// Calcula el determinante de una matriz 3x3
int calcular_determinante(int m[3][3]) {
    int det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
            - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
            + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    return det;
}

int main() {
    int opcion, matrizA[3][3], matrizB[3][3], resultado[3][3];

    do {
        opcion = mostrar_menu();
        limpiarPantalla();

        if (opcion >= 1 && opcion <= 4) {
            // Capturar matriz A (azul)
            capturar_matriz(matrizA, 10, 5, AZUL, "MATRIZ A (AZUL)");

            // Capturar matriz B (rojo) si es necesario
            if (opcion != 4) {
                capturar_matriz(matrizB, 30, 5, ROJO, "MATRIZ B (ROJO)");
            }

            // Realizar operación seleccionada
            switch (opcion) {
                case 1: // Suma
                    for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++)
                            resultado[i][j] = matrizA[i][j] + matrizB[i][j];

                    gotoxy(10, 12); printf("RESULTADO (SUMA):");
                    mostrar_matriz(resultado, 10, 13, AMARILLO_SUB);
                    break;

                case 2: // Resta
                    for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++)
                            resultado[i][j] = matrizA[i][j] - matrizB[i][j];

                    gotoxy(10, 12); printf("RESULTADO (RESTA):");
                    mostrar_matriz(resultado, 10, 13, AMARILLO_SUB);
                    break;

                case 3: // Multiplicación
                    for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++) {
                            resultado[i][j] = 0;
                            for (int k = 0; k < 3; k++)
                                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
                        }

                    gotoxy(10, 12); printf("RESULTADO (MULTIPLICACION):");
                    mostrar_matriz(resultado, 10, 13, AMARILLO_SUB);
                    break;

                case 4: // Determinante
                    int det = calcular_determinante(matrizA);
                    gotoxy(10, 12); printf("DETERMINANTE: %s%d%s", AMARILLO_SUB, det, RESET);
                    break;
            }

            gotoxy(1, 20); printf("Presione Enter para continuar...");
            getchar(); getchar();
        }

    } while (opcion != 5);

    limpiarPantalla();
    gotoxy(15, 10); printf("%sPROGRAMA TERMINADO%s", AMARILLO_SUB, RESET);
    gotoxy(1, 12);
    return 0;
}
