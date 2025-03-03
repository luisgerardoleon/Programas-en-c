#include <stdio.h>
int main (){
    float   b , c , r;
    int N;

    printf("%s\n", "seleccione una opcion");
    printf("%s\n", " 1.- suma");
    printf("%s\n", "2.- resta");
    printf("%s\n", "3.-multiplicacion");
    printf("%s\n", "4.-division");
    scanf("%d",&N);
    switch ( N )
    {
        case 1:
        printf("%s\n","seleccionaste suma");
        printf("%s\n", "dame el primer numero");
        scanf("%f",&b);
        printf("%s\n","dame el segundo numero");
        scanf("%f",&c);
        r = b + c;
        printf("%s%f\n","el resultado de tu suma es ",r);
        break;

        case 2:
        printf("%s\n","seleccionaste resta");
        printf("%s\n", "dame el primer numero");
        scanf("%f",&b);
        printf("%s\n","dame el segundo numero");
        scanf("%f",&c);
        r = b - c;
        printf("%s%f\n","el resultado de tu resta  es ", r );
        break;

        case 3:
        printf("%s\n","seleccionaste multiplicacion");
        printf("%s\n", "dame el primer numero");
        scanf("%f",&b);
        printf("%s\n","dame el segundo numero");
        scanf("%f",&c);
        r = b * c;
        printf("%s%f\n","el resultado de tu multiplicacion es ", r );
        break;

        case 4:
        printf("%s\n","seleccionaste division");
        printf("%s\n", "dame el primer numero");
        scanf("%f",&b);
        printf("%s\n","dame el segundo numero");
        scanf("%f",&c);
        r = b / c;
        printf("%s%f\n","el resultado de tu suma es ", r );
        break;

    }
    return 0;
}