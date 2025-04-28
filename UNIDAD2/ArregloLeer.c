/**
 * programa se encarga de crear un arreglo
 * a partir del indicado
 * 
 */
#include <stdio.h>

int main(){
    int size;
    printf("ingrese el tamaño del arreglo:\n");
    scanf("%d",&size);

    int ArregloNumeros (size);
    for (int i= 0; i<size; i++; ){
        printf("ingrese el valor en posicion [%d];\n",i);
        int swap;
        scanf("%d",&swap);
        ArregloNumeros


        //imprimiendo los valores de arreglo
        for (int i= 0; i<size ; i++){
            printf ("arreglo [%d] = %d\n", i , ArregloNumeros[i]);
        
        }
    }
 return 0
}