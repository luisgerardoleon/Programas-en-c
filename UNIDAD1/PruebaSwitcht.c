#include <stdio.h>
int main (){
    int opc;
    printf("%s\n", "seleccione una opcion:");
    printf("%s\n", "1.- sumar");
    printf("%s\n", "2.- restar");
    scanf("%d",&opc);
    switch (opc)
    {
    case 1:
        printf("%s\n", "ah seleccionado suma");
        break;
    case 2:
    printf("%s\n"," ah seleccionado resta ");
        break;
    default:
    printf("%s\n","no ah seleccionado una opcion valida");    
        break;
    }
    return 0;
}