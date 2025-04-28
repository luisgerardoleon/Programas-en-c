#include <stdio.h>
int main(){
    printf("hola mundo");



    printf("1. Ingresar persona\n");
    printf("2. Ingresar producto\n");
    printf("Seleccione opcion: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("Ingrese nombre: ");
            scanf("%s", matriz[i][j].valor.persona.nombre);
            printf("Ingrese edad: ");
            scanf("%d", &matriz[i][j].valor.persona.edad);
            matriz[i][j].tipo = 1;
            break;

        case 2:
            printf("Ingrese producto: ");
            scanf("%s", matriz[i][j].valor.producto.producto);
            printf("Ingrese precio: ");
            scanf("%f", &matriz[i][j].valor.producto.precio);
            matriz[i][j].tipo = 2;
            break;

        default:
            printf("Opción inválida. Se asignarán valores por defecto\n");
            strcpy(matriz[i][j].valor.persona.nombre, "N/A");
            matriz[i][j].valor.persona.edad = 0;
            matriz[i][j].tipo = 1;
    }
}
}

// Mostrar matriz
printf("\nContenido de la matriz:\n");
for(int i = 0; i < FILAS; i++) {
for(int j = 0; j < COLUMNAS; j++) {
    if(matriz[i][j].tipo == 1) {
        printf("Celda [%d][%d] - Persona: %s, %d años\n",
               i, j,
               matriz[i][j].valor.persona.nombre,
               matriz[i][j].valor.persona.edad);
    } else {
        printf("Celda [%d][%d] - Producto: %s, $%.2f\n",
               i, j,
               matriz[i][j].valor.producto.producto,
               matriz[i][j].valor.producto.precio);
    }
}
}

return 0;
}
}

