#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 100

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}

int main() {
    FILE *file;
    char nombre[Max];
    int edad;
    char pais[Max];
    int cantidad, i;
    char name[Max];
    char desicion[Max];
    char linea[Max];

    printf("\033[2J"); // Limpia la pantalla
    gotoxy(5, 7);
    printf("nombre del archivo?");
    scanf("%s", name);
    getchar();

    // Abrir el archivo en modo escritura
    file = fopen(name, "w");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Escribir encabezados
    fprintf(file, "%-30s,%-10s,%-15s\n", "nombre", "Edad", "Pais");

    printf("\033[2J"); // Limpia la pantalla
    gotoxy(5, 7);
    printf("Cuantas personas quieres registrar?");
    scanf("%d", &cantidad);
    getchar();

    printf("\033[2J"); // Limpia la pantalla
    for (i = 0; i < cantidad; i++) {
        gotoxy(3, 8);
        printf("\nPersona %d\n", i + 1);

        gotoxy(4, 10);
        setColor("\033[7;31m");
        printf("nombre completo: ");
        setColor("\033[0m");
        fgets(nombre, Max, stdin);
        nombre[strcspn(nombre, "\n")] = 0; // Eliminar el salto de línea al final del nombre

        gotoxy(4, 12);
        setColor("\033[7;32m");
        printf("Edad: ");
        setColor("\033[0m");
        scanf("%d", &edad);
        getchar();

        gotoxy(4, 14);
        setColor("\033[7;33m");
        printf("Pais: ");
        setColor("\033[0m");
        fgets(pais, Max, stdin);
        pais[strcspn(pais, "\n")] = 0; // Eliminar salto de línea

        // Guardar los datos en el archivo con el formato adecuado
        fprintf(file, "%-30s,%-10d,%-15s\n", nombre, edad, pais);
        printf("\033[2J"); // Limpia la pantalla
    }

    fclose(file);
    printf("\nArchivo %s creado exitosamente.\n", name);

    printf("¿Quieres ver los datos? (si/no)\n");
    scanf("%s", desicion);

    if (strcmp(desicion, "si") == 0) {
        file = fopen(name, "r"); // Abrimos en modo lectura
        if (file == NULL) {
            perror("Error al abrir el archivo para leer");
            return 1;
        }

        printf("\n");

        // Encabezado de la tabla
        setColor("\033[1;36m"); // Color cian para los encabezados
        printf("| %-3s | %-30s | %-5s | %-15s |\n", "#", "Nombre", "Edad", "Pais");
        printf("|-----|--------------------------------|-----------|---------------|\n");
        setColor("\033[0m"); // Reset color

        int contador = 0;
        fgets(linea, Max, file); // Saltar encabezado

        while (fgets(linea, Max, file) != NULL) {
            char *token;

            token = strtok(linea, ",");
            if (token != NULL) {
                contador++;
                strcpy(nombre, token); // Nombre completo

                token = strtok(NULL, ",");
                if (token != NULL)
                    edad = atoi(token);

                token = strtok(NULL, "\n");
                if (token != NULL)
                    strcpy(pais, token);

                // Imprimir los datos en la tabla
                printf("| %-3d | %-30s | %-5d | %-15s |\n", contador, nombre, edad, pais);
            }
        }

        fclose(file);
    }

    return 0;
}