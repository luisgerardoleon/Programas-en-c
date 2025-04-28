#include <stdio.h>
struct personaje{
    char nombre [50];
    char videojuego [50];
    int estatura;
    int edad;
    char origen [50];
    char colorPiel [50];
    char HabilidadEspecial [50];
    char raza [50];
    char sexo [50];
    int kills;
    char rango [50];
    char alias [50];
};
int main(){
    int n;

    printf("ingresar un numero de personajes");
    scanf("%d", &n);
    getchar();

    struct personaje personajes [n];
    for ( int i=0 ;i< n ; i++){
        printf("\ningrese los datos\n");

        printf("nombre: ");
        scanf(" %[^\n]", personajes[i].nombre);

        printf("videojuego: ");
        scanf(" %[^\n]", personajes[i].videojuego);

        printf("estatura: ");
        scanf("%d", &personajes[i].estatura);

        printf("edad: ");
        scanf("%d", &personajes[i].edad);

        printf("origen: ");
        scanf(" %[^\n]", personajes[i].origen);

        printf("color de piel: ");
        scanf(" %[^\n]", personajes[i].colorPiel);

        printf("Habilidad Especial: ");
        scanf(" %[^\n]", personajes[i].HabilidadEspecial);

        printf("raza: ");
        scanf(" %[^\n]", personajes[i].raza);

        printf("sexo: ");
        scanf(" %[^\n]", personajes[i].sexo);

        printf("kills: ");
        scanf("%d", &personajes[i].kills);

        printf("rango: ");
        scanf(" %[^\n]", personajes[i].rango);

        printf("alias: ");
        scanf(" %[^\n]", personajes[i].alias);


    }
    printf("\n%-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s\n", 
        "nombre", "videojuego", "estatura","edad","origen","colorPiel","HabilidadEspecial","raza","sexo","kills","rango","alias");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");

    for(int i=0; i< n; i++){
        printf("%-5s | %-8s | %-8d | %-5d | %-5s | %-5s | %-5s | %-5s | %-5s | %-5d | %-5s | %-5s\n",
        personajes[i].nombre,
        personajes[i].videojuego,
        personajes[i].estatura,
        personajes[i].edad,
        personajes[i].origen,
        personajes[i].colorPiel,
        personajes[i].HabilidadEspecial,
        personajes[i].raza,
        personajes[i].sexo,
        personajes[i].kills,
        personajes[i].rango,
        personajes[i].alias);
    }

}