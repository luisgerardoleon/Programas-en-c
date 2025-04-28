#include <stdio.h>
#include <string.h>

struct Keyvalue {
    char Clave[50];
    char valor[100];

};
 int main(){
    struct Keyvalue tabla[3]={
        {"usuario", "admin"},
        {"contraseña","1234"},
        {"servidor", "localhost"}

    };
    printf ("tabla Clave-Valor:\n");
    for (int i=0;i<3;i++){
        printf ("%s\n",tabla[i].Clave, tabla[i].valor);
    }
}