#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max_line 1024

int main(){
    FILE *file;
    char line[Max_line];
    char *token;

    //Abrir un archivo en modo lectura
    file = fopen("../1Datos.csv", "r");
    if(file == NULL){
        perror("Error al abrir el archivo");
        return 1;
    }

    printf("%-15s %-10s %-15s\n", "nombre", "Edad", "Pais");
    printf("----------------------------------------\n");
    while(fgets(line, sizeof(line), file)){
        line[strcspn(line, "\n")] = 0;

        token = strtok(line, ",");
        if(token != NULL) printf("%-15s", token);

        token = strtok(NULL, ",");
        if(token != NULL) printf("%-10s", token);

        token = strtok(NULL, ",");
        if(token != NULL) printf("%-15s", token);

        printf("\n");
    }

    fclose(file);

    return 0;
}