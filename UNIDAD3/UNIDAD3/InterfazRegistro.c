#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


#define AMARILLO  "\033[43m\033[37m"  // Fondo amarillo, texto blanco
#define AZUL      "\033[44m\033[37m"  // Fondo azul, texto blanco
#define VERDE     "\033[42m\033[37m"  // Fondo verde, texto blanco
#define RESET     "\033[0m"           // Restablecer colores

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void clear_screen() {
    printf("\033[2J\033[H");
}


void leerConColor(const char *color, char *buffer, int max) {
    printf("%s", color); 
    fflush(stdout);       
    fgets(buffer, max, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    printf(RESET);        
}

int main() {
    FILE *file;
    char nombre[MAX][MAX];
    int edad[MAX];
    char pais[MAX][MAX];
    int cantidad, i;
    int opcion;
    char nombre_archivo[MAX];

    // Pedir nombre del archivo (normal)
    clear_screen();
    gotoxy(10, 5);
    printf("Ingrese el nombre del archivo: ");
    fgets(nombre_archivo, MAX, stdin);
    nombre_archivo[strcspn(nombre_archivo, "\n")] = 0;

    // Abrir el archivo
    file = fopen(nombre_archivo, "w");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Pedir cantidad (normal)
    clear_screen();
    gotoxy(10, 5);
    printf("Ingrese la cantidad de personas: ");
    scanf("%d", &cantidad);
    getchar();

    clear_screen();

   
    for (i = 0; i < cantidad; i++) {
        clear_screen();
        printf("\nPersona: %d\n", i + 1);

     
        printf(AMARILLO "Nombre: " RESET " ");
        leerConColor(AMARILLO, nombre[i], MAX);

        
        printf(AZUL "Edad: " RESET " ");
        printf(AZUL);  
        fflush(stdout);
        scanf("%d", &edad[i]);
        getchar();
        printf(RESET);

      
        printf(VERDE "Pais: " RESET " ");
        leerConColor(VERDE, pais[i], MAX);

        printf("\n");
    }

    clear_screen();

  
    fprintf(file, "Nombre,Edad,Pais\n");
    for (i = 0; i < cantidad; i++) {
        fprintf(file, "%s,%d,%s\n", nombre[i], edad[i], pais[i]);
    }

    fclose(file);

   
    printf("\nSe han guardado correctamente los registros en '%s'.\n", nombre_archivo);
    printf("Desea ver los registros (1 = Si / 0 = No): ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        clear_screen();

    
        int ancho = 50;
        for (i = 0; i < ancho; i++) printf("*");
        printf("\n");
        printf("* %-15s * %-5s * %-15s *\n", "Nombre", "Edad", "Pais");
        for (i = 0; i < ancho; i++) printf("*");
        printf("\n");

        for (i = 0; i < cantidad; i++) {
            printf("* %-15s * %-5d * %-15s *\n", nombre[i], edad[i], pais[i]);
        }

        for (i = 0; i < ancho; i++) printf("*");
        printf("\n");
    }

    return 0;
}