#include <stdio.h>

void moverCursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void cambiarColor(const char* color) {
    printf("%s", color);
}

void reiniciarColor() {
    printf("\033[0m");
}

int main() {
    printf("\033[2J"); // Limpiar pantalla

    int franjas_totales = 13;
    int ancho_bandera = 45;
    int franjas_azules = 7;
    int ancho_azul = 18;
    int posX = 5;
    int posY = 3;

    for (int fila = 0; fila < franjas_totales; fila++) {
        moverCursor(posX, posY + fila);

        if (fila < franjas_azules) {
            cambiarColor("\033[44m"); // Fondo azul
            
            for (int columna = 0; columna < ancho_azul; columna++) {
                if (fila == franjas_azules/2 && columna == ancho_azul/2) {
                    cambiarColor("\033[37m"); // Estrella blanca
                    printf("*");
                    cambiarColor("\033[44m"); // Volver a azul
                } else {
                    printf(" ");
                }
            }

            if (fila % 2 == 0) {
                cambiarColor("\033[41m"); // Fondo rojo
            } else {
                cambiarColor("\033[47m"); // Fondo blanco
            }

            for (int columna = 0; columna < ancho_bandera - ancho_azul; columna++) {
                printf(" ");
            }
        } else {
            if (fila % 2 == 0) {
                cambiarColor("\033[41m"); // Fondo rojo
            } else {
                cambiarColor("\033[47m"); // Fondo blanco
            }

            for (int columna = 0; columna < ancho_bandera; columna++) {
                printf(" ");
            }
        }

        reiniciarColor();
    }

    moverCursor(0, posY + franjas_totales + 2);
    reiniciarColor();
    return 0;
}