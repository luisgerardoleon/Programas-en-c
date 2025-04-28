#include<stdio.h>
#include<math.h>
#include<string.h>

struct Eccradratica{
    int b;
    int a;
    int c;
    int determinante;
    float x1;
    float x2;
    char soluc[30];
};

int main(){
    struct Eccradratica arreglo[2] = {
        {3,2,-5,0,0.0,0.0},
        {7,3,-6,0,0.0,0.0}
};
for (int i = 0; i<2; i++){
    int d = (arreglo[i].b* arreglo[i].b)-(arreglo[i].a * arreglo[i].c);
    if(d<0){
        strcpy(arreglo[i].soluc, "no tiene solucion");
    }else{
        int valx1 = ((-1)* arreglo[i].b + sqrt(d))/ 2 * arreglo[i].a;
        int valx2 = ((-1)* arreglo[i].b - sqrt(d))/ 2 * arreglo[i].a;
    strcpy(arreglo[i].soluc, "Tiene solucion");
        arreglo[i].x1 = valx1;
        arreglo[i].x2 = valx2;
    }
    }
    printf("%s|%s|%s|%s|%s|%s\n", "a","b", "c", "x1", "x2", "soluc");
    for (int i = 0; i<2; i++){
        printf("%d | %d | %d | %.2f | %.2f | %s \n",
                arreglo[i].a,
                arreglo[i].b,
                arreglo[i].c,
                arreglo[i].x1,
                arreglo[i].x2,
                arreglo[i].soluc);
    } 
    return  0;
}