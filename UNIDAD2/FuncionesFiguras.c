#include <stdio.h>

union dato {
    int entero;
    float flotante;
};

int cuad(int l) {
    return l * l;
}

int rectangulo(int b, int h) {
    return b * h;
}

int triangulo(int b, int h) {
    return (b * h)/2;
}

int rombo(int D, int d) {
    return (D*d)/2;
}

float trapecio(int B, int b, int h) {
    return ((B + b) * h) / 2.0f;
}

int cubo(int l) {
    return l*l*l;
}

int prisma_rectangular(int b, int a, int h) {
    return b * a * h;
}

float cilindro(int r, int h) {
    return 3.1416 * r * r * h;
}

float esfera(int r) {
    return (4 * 3.1416 * r * r * r)/3;
}

float cono(int r, int h) {
    return (1* 3.1416 * r * r * h)/3;
}

int main() {
    union dato resultado;
    int opc, l, b, h, D, d, B, a, r;
    
    printf("Seleccione la figura:\n");
    printf("1. Cuadrado\n");
    printf("2. Rectangulo\n");
    printf("3. Triangulo\n");
    printf("4. Rombo\n");
    printf("5. Trapecio\n");
    printf("6. Cubo\n");
    printf("7. Prisma rectangular\n");
    printf("8. Cilindro\n");
    printf("9. Esfera\n");
    printf("10. Cono\n");
    scanf("%d", &opc);
    
    switch(opc) {
        case 1:
            printf("Dame el Lado: ");
            scanf("%d", &l);
            resultado.entero = cuad(l);
            printf("el Area es : %d\n", resultado.entero);
            break;
        case 2:
            printf("Base y altura: ");
            scanf("%d %d", &b, &h);
            resultado.entero = rectangulo(b, h);
            printf("Area: %d\n", resultado.entero);
            break;
        case 3:
            printf("Base y altura: ");
            scanf("%d %d", &b, &h);
            resultado.entero = triangulo(b, h);
            printf("Area: %d\n", resultado.entero);
            break;
        case 4:
            printf("Diagonal mayor y menor: ");
            scanf("%d %d", &D, &d);
            resultado.entero = rombo(D, d);
            printf("Area: %d\n", resultado.entero);
            break;
        case 5:
            printf("Base mayor, base menor y altura: ");
            scanf("%d %d %d", &B, &b, &h);
            resultado.flotante = trapecio(B, b, h);
            printf("Area: %.2f\n", resultado.flotante);
            break;
        case 6:
            printf("Lado: ");
            scanf("%d", &l);
            resultado.entero = cubo(l);
            printf("Volumen: %d\n", resultado.entero);
            break;
        case 7:
            printf("Base, altura y profundidad: ");
            scanf("%d %d %d", &b, &a, &h);
            resultado.entero = prisma_rectangular(b, a, h);
            printf("Volumen: %d\n", resultado.entero);
            break;
        case 8:
            printf("Radio y altura: ");
            scanf("%d %d", &r, &h);
            resultado.flotante = cilindro(r, h);
            printf("Volumen: %.2f\n", resultado.flotante);
            break;
        case 9:
            printf("Radio: ");
            scanf("%d", &r);
            resultado.flotante = esfera(r);
            printf("Volumen: %.2f\n", resultado.flotante);
            break;
        case 10:
            printf("Radio y altura: ");
            scanf("%d %d", &r, &h);
            resultado.flotante = cono(r, h);
            printf("Volumen: %.2f\n", resultado.flotante);
            break;
        default:
            printf("Opcion no valida\n");
    }
    
    return 0;
}

