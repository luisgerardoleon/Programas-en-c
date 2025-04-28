#include <stdio.h>
int main (){
    int  DH, DL, CH, CL, BL, BH, AL, AH;

    printf("ingrese valor :\n");
    scanf("%d",&CH);
    printf("ingrese valor :\n");
    scanf("%d",&CL);
    printf("ingrese valor :\n");
    scanf("%d",&BL);
    printf("ingrese valor :\n");
    scanf("%d",&BH);
    printf("ingrese valor :\n");
    scanf("%d",&AL);
    printf("ingrese valor :\n");
    scanf("%d",&AH);

    int *const PDH = &DH;
    int *const PDL = &DL;
    int *const PCH = &CH;
    int *const PCL = &CL;
    int *const PBL = &BL;
    int *const PBH = &BH;
    int *const PAL = &AL;
    int *const PAH = &AH;

    printf ("Valores Ingresados: A=%p\n", &DH);
    printf ("Valores Ingresados: B=%p\n", &DL);
    printf ("Valores Ingresados: C=%p\n", &CH);
    printf ("Valores Ingresados: D=%p\n", &CL);
    printf ("Valores Ingresados: E=%p\n", &BL);
    printf ("Valores Ingresados: F=%p\n", &BH);
    printf ("Valores Ingresados: G=%p\n", &AL);
    printf ("Valores Ingresados: H=%p\n", &AH);

    // Operaciones con CH y CL
    printf(" Operaciones con CH y CL \n");
    *PDL = *PCH + *PCL;
    printf("Resultado de la suma: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);

    *PDL = *PCH - *PCL;
    printf("Resultado de la resta: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);

    *PDL = *PCH * *PCL;
    printf("Resultado de la multiplicacion: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);

    *PDL = *PCH / *PCL;
    printf("Resultado de la division: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);

    // Operaciones con BL y BH
    printf("\n Operaciones con BL y BH \n");
    *PDL = *PBL + *PBH;
    printf("Resultado de la suma: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);

    *PDL = *PBL - *PBH;
    printf("Resultado de la resta: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);

    *PDL = *PBL * *PBH;
    printf("Resultado de la multiplicacion: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);

    *PDL = *PBL / *PBH;
    printf("Resultado de la division: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);

    // Operaciones con AL y AH
    printf("\n Operaciones con AL y AH \n");
    *PDL = *PAL + *PAH;
    printf("Resultado de la suma: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);

    *PDL = *PAL - *PAH;
    printf("Resultado de la resta: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);

    *PDL = *PAL * *PAH;
    printf("Resultado de la multiplicacion: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);

    *PDL = *PAL / *PAH;
    printf("Resultado de la division: %d\n", *PDL);
    printf("Valor nuevo DL: %d\n\n", *PDL);
}
