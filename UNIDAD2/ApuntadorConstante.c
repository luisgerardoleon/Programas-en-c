#include <stdio.h>
int main (){
    int  a, b, c, d, e;

    printf("ingrese valor :\n");
    scanf("%d",&a);
    printf("ingrese valor :\n");
    scanf("%d",&b);
    printf("ingrese valor :\n");
    scanf("%d",&c);
    printf("ingrese valor :\n");
    scanf("%d",&d);
    printf("ingrese valor :\n");
    scanf("%d",&e);

    int *const pa = &a;
    int *const pb = &b;
    int *const pc = &c;
    int *const pd = &d;
    int *const pe = &e;

    printf ("Valores Ingresados: A=%p\n", &pa);
    printf ("Valores Ingresados: B=%p\n", &pb);
    printf ("Valores Ingresados: C=%p\n", &pc);
    printf ("Valores Ingresados: D=%p\n", &pd);
    printf ("Valores Ingresados: E=%p\n", &pe);

    int suma = *pa +*pa;
    printf("resultado de la suma : %d\n", suma);

    *pa = suma;
    printf ("valor neuvo : A=%d\n\n", *pa);

    int resta = *pb - *pb;
    printf("resultado de la resta : %d\n", resta);

    *pb = resta;
    printf ("valor neuvo : B=%d\n", *pb);

    int multiplicacion = *pc * *pc;
    printf("resultado de la multiplicacion : %d\n", multiplicacion);

    *pc = multiplicacion;
    printf ("valor nuevo : C=%d\n", *pc);

    int division = *pd / *pd;
    printf("resultado de la division : %d\n\n", division );

    *pd = division;
    printf ("valor nuevo : D=%d\n", *pd);

}