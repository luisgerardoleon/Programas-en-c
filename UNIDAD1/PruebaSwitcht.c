#include<stdio.h>
#define Filas 3
#define columnas 6

int  main(){
    int matriz [Filas][columnas];
    for (int i = 0; i < Filas; i++){
        for(int j = 0; j< columnas; j++){
            if(j == 0 || j == 1){
                printf("dame el numero: ");
                scanf("%d", matriz[i][j]);
            }
        }
    }
    for (int i = 0; i < Filas; i++){
        for(int j = 0; j< columnas; j++){
        matriz[i][2] = matriz[i][0]+matriz[i][1];
        matriz[i][3] = matriz[i][0]-matriz[i][1];
        matriz[i][4] = matriz[i][0]*matriz[i][1];
        matriz[i][5] = matriz[i][0]/matriz[i][1];
    } 
}      
    printf("recorriendo la matriz: \n");
    for(int i=0; i<Filas; i++){
        for(int j = 0; j< columnas; j++){
            printf("%-10s ", matriz[i][j]);
            printf(" | "); 
        }
        printf("\n");
    }
    return 0;
}