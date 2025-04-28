#include <stdio.h>
struct Direccion{
    char calle [50];
    int numero; 
    
};
struct persona{
    char nombre [50];
    struct Direccion Domicilio;

};
int main(){
    int n;

    printf("ingresar un numero de personas");
    scanf("%d", &n);
    getchar();

    struct persona personas [n];
    for( int i=0 ;i<=n ; i++){
        printf("\nIngrese los datos");

        printf("nombre: ");
        scanf("%s", personas[i].nombre);

        printf("calle: ");
        scanf("%s",personas[i].}Domicilio.nombre);

        printf("numero: ");
        scanf("%d" &personas[i].Domicilio.nombre);
        getchar();
    }
    
    printf("%--20s | %--20s | %--10s\n", "nombre", "Direccion", "numero");
    printf("-----------------------------------------------------------\n");

    for ( int i= 0; i < n; i++;){
        printf("%--20s | %--20s | %--10s\n",
        personas[i].nombre,
        personas[i].Domicilio.calle,
        personas[i].Domicilio.numero);
    }
    return 0;
}
