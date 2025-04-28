#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3  
#define LONGITUD 40

int main(){
    char matriz [FILAS][COLUMNAS][LONGITUD];

      printf("ingrese 9 palabras:\n ");

      for (int i = 0; i<FILAS; i++){
        for (int j =0; j<COLUMNAS;j++ ){
            printf("matriz [%d][%d]: ", i, j);
            scanf("%s",matriz[i][j]);

        }
    }

    printf ("Recorriendo la matriz:\n"); 
        for (int i = 0; i<FILAS; i++){
        for (int j =0; j<COLUMNAS;j++ ){
            printf("%-10s",matriz[i][j]);
            printf("%s", "|");
        }
        printf("\n");
     }
     return 0;
}
