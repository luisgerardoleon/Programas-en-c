#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdbool.h>
#define Filas 3
#define columnas 3 
#define FILAS 3
#define COLUMNAS 6  
#define Fila 2
#define Columna 2
#define Filas2 6
#define columnas2 6  
#define filas4 2
#define columnas4 2

struct Estudiante {
    char nombre [50];
    int edad;
    float promedio;
};

typedef struct {//firma de la estrcutura
    char nombre[50];
    int edad;
    float promedio;
} Estudiante2;

struct Usuario{
    char nombre[50];
    int edad;
    char correo [50];

};

struct Persona {
    char nombre[50];
    int edad;
    char correo[50];
    char telefono[50];
    int grupo;
    float promedio;
    char comidafav[50];
    char videojuegofav[50];
};

struct Direccion{
    char calle[50];
    int num;
};
struct Persona2 {
    char nombre [50];
    struct Direccion domilicio;
};

struct Coordenadas{
    int x;
    int y;
};
struct Direccion2{
    char calle[50];
    int numero;
    struct Coordenadas lugar;
};
struct Estudiante3{
    char nombre[50];
    struct Direccion2 domicilio2;
};

struct KeyValue{
    char clave[50];
    char valor[100];
};

struct Tabla{
    int valor1;
    int valor2;
    int resultado;
};

struct Eccradratica{
    int b;
    int a;
    int c;
    int determinante;
    float x1;
    float x2;
    char soluc[30];
};

struct Eccradratica2 { // Declaramos la estructura Eccradratica2 para representar una ecuación cuadrática
    int a2; // Variable de a2
    int b2; // Variable de b2
    int c2; // Variable de c2
    int determinante2; // Variable de la determinante2
    float x12; // Variable de la respuesta 1
    float x22; // Respuesta 2
    char soluc2[30]; // Dicta la impresión de si tiene solución o no
};

struct Coordenadas2{// Definimos una estructura llamada Coordenadas para almacenar las coordenadas de los vértices
    int x13;//varibale de x1
    int y13;//varibale de y1
    int x23;//varibale de x2
    int y23;//varibale de y2
    int x3;//varibale de x3
    int y3;//varibale de y3
    int x4;//varibale de x4
    int y4;//varibale de y4
};

struct Direccion3{
    char calle[50];
    int numero;
};

struct Persona3{
    char nombre[50];
    struct Direccion3 domicilio3;
};

union Dato{
    int entero;
    float decimal;
    char texto[20];
};

struct Vehiculo{
    int llantas;
    char color[50];
    int caballosfuerza;
    int kilometraje;
};

union Camion{
    int asientos;
    int puertas;
    struct Vehiculo vehiculo;
};

union Moto{
    struct Vehiculo vehiculo;
    int cc;
};

struct Videojuego{
    char nombre[50];
    int anio;
};

typedef struct{
    char nombre[50];
    int edad;
} Persona4;

typedef struct{
    char producto[50];
    float precio;
} Producto;

typedef union{
    Persona4 persona;
    Producto producto;
} Dato;

typedef struct{
    Dato valor;
    int tipo;
} Celda;


typedef struct{
    char nombre[50];
    int edad;
} Perro;

typedef struct{
    char nombre[50];
    float meses;
} Gato;

typedef union{
    Perro perro;
    Gato gato;
} Dato2;

typedef struct{
    Dato2 valor;
    int tipo;
} Celda2;

int suma(int a, int b){
    return a + b;
}

int resta(int a, int b){
    int result = a - b;
    return result;
}

int multi(int a){
    return a * a;
}


float dividir(int a, int b){
    return a / b;
}

void imprimir (int a, int b, int c, float d){
    printf("\nResultados: \nSuma: %d \nResta: %d \nMulti:%d \nDiv:%.2f",a,b,c,d);
}

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

int numero(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
    
}

int numero2(int a, int b, int c){
    if (a > b && a > c) {
        return a;
    } else if (b > c) {
        return b;
    } else {
        return c;
    }
}

int sumatoria(int a, int b){
    int suma = 0;
    for(int i = a + 1; i < b; i++){
            suma = suma + i;

    }
    return suma;
}

int numero3(int a){
    return a;
}

int exponencial(int base, int exponente){
    int resultado = 1;
    for(int i = 0; i < exponente; i++){
        resultado = base * resultado;
    }

    return resultado;
}

int tabla_mult(int a){
    for(int i = 0; i <= 10; i++){
        int tabla = a * i;
        printf("%d x %d = %d\n", a, i, tabla);
    }
}

int intervalo(int a, int b){
    int par = a;
    for(int i = a + 1; i < b; i++){
        par  = par + 1;
        if(i %2 == 0){
            printf("%d ", par);
        }else{
            printf("%s ", "*");
        }
    }

}

const char* palabras(int opc){
    switch(opc){
        case 1:
            return "hola";
            
        case 2:
            return "halo deidad";
            
        case 3:
            return "i am a master pize";
            
        case 4:
            return "adios";
            
        case 5:
            return "skibidi";
            
        case 6:
            return "peru";
            
        case 7:
            return "mexico";
            
        default:
            return "no ha seleccionado una opcion valida";
            
    }

}

float temperatura(float a){
    return (a * 9/5) + 32;
}

float temperatura2(float a){
    return (a - 32) * 5/9;
}

float temperatura3(float a){
    return ((9/5*a)-273) + 32;
}

float temperatura4(float a){
    return a+273;
}

float cambio(float d){
    return d * 20.34;
}

void resolver_ecuacion(float a, float b, float c) {
    float discriminante = b * b - 4 * a * c;

    if (discriminante > 0) {
        // Dos soluciones reales
        float x1 = (-b + sqrt(discriminante)) / (2 * a);
        float x2 = (-b - sqrt(discriminante)) / (2 * a);
        printf("Las soluciones son: x1 = %.2f y x2 = %.2f\n", x1, x2);
    } else{
        printf("No se puede, raiz negativa");
    } 
}

void llenarMatriz(char *nombre, int filas3, int columnas3, int matriz[filas3][columnas3]) {
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas3; i++) {
        for (int j = 0; j < columnas3; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void saveMatriz(int filas3, int columnas3, int matriz[filas3][columnas3]) {
    FILE *archivo = fopen("../matriz.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < filas3; i++) {
        for (int j = 0; j < columnas3; j++) {
            fprintf(archivo, "%d ", matriz[i][j]);
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);
    printf("Matriz guardada en 'matriz.txt' exitosamente.\n");
}

void imprimirMatriz(char *nombre, int filas3, int columnas3, int matriz[filas3][columnas3]) {
    printf("Nombre de la matriz: %s\n", nombre);
    printf("Matriz ingresada:\n");

    for (int i = 0; i < filas3; i++) {
        for (int j = 0; j < columnas3; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumarMatriz(int filas3, int columnas3,
                 int matriz1[filas3][columnas3], int matriz2[filas3][columnas3],
                 int matrizr[filas3][columnas3]) {
    for (int i = 0 ; i < filas3; i++) {
        for (int j = 0 ; j < columnas3; j++) {
            matrizr[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

//Realizar el método para escalar
void escalarMatriz(int filas3, int columnas3,
                   int matriz1[filas3][columnas3], int escalar,
                   int matrizr[filas3][columnas3]) {
    for (int i = 0 ; i < filas3; i++) {
        for (int j = 0 ; j < columnas3; j++) {
            matrizr[i][j] = matriz1[i][j] * escalar;
        }
    }
}

int determinanteSarrus(int matriz[3][3]) {
    int suma_diagonal = 0, suma_inversa = 0;

    for (int i = 0; i < 3; i++) {
        int producto = 1;
        for (int j = 0; j < 3; j++) {
            producto *= matriz[j][(i + j) % 3];  
        }
        suma_diagonal += producto;
    }

    for (int i = 0; i < 3; i++) {
        int producto = 1;
        for (int j = 0; j < 3; j++) {
            producto *= matriz[j][(3 + i - j) % 3];  
        }
        suma_inversa += producto;
    }

    return suma_diagonal - suma_inversa;
}

void llenarMatriz2(char *nombre, int raiz, char matriz[raiz][raiz]) {
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < raiz; i++) {
        for (int j = 0; j < raiz; j++) {
            printf("Ingrese un caracter para la posicion [%d][%d]: ", i, j);
            scanf(" %c", &matriz[i][j]); // nota el espacio antes de %c
        }
    }
}

// Función para imprimir la matriz
void imprimirMatriz2(char *nombre, int raiz, char matriz[raiz][raiz]) {
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < raiz; i++) {
        for (int j = 0; j < raiz; j++) {
            printf(" %c ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para volcar la matriz en un arreglo 1D
void vaciarEnArreglo2(int raiz, char matriz[raiz][raiz], char arreglo[]) {
    int k = 0;
    for (int i = 0; i < raiz; i++) {
        for (int j = 0; j < raiz; j++) {
            arreglo[k++] = matriz[i][j];
        }
    }
}

// Función para imprimir el arreglo 1D
void imprimirArreglo2(char *nombre, char arreglo[], int tamanio) {
    printf("%s: ", nombre);
    for (int i = 0; i < tamanio; i++) {
        printf("%c ", arreglo[i]);
    }
    printf("\n");
}

void llenarMatriz3(char *nombre, int matriz[filas4][columnas4]) {
    printf("Llenando %s:\n", nombre);
    for (int i = 0; i < filas4; i++) {
        for (int j = 0; j < columnas4; j++) {
            printf("Ingrese valor para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Función para imprimir la matriz
void imprimirMatriz3(char *nombre, int matriz[filas4][columnas4]) {
    printf("%s:\n", nombre);
    for (int i = 0; i < filas4; i++) {
        for (int j = 0; j < columnas4; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para llenar el vector (de tamaño 2)
void llenarVector(int vector[columnas4]) {
    printf("Llenando vector:\n");
    for (int i = 0; i < columnas4; i++) {
        printf("Ingrese valor para [%d]: ", i);
        scanf("%d", &vector[i]);
    }
}

// Función para multiplicar matriz por vector
void multiplicarMatrizPorVector(int matriz[filas4][columnas4], int vector[columnas4], int resultado[filas4]) {
    for (int i = 0; i < filas4; i++) {
        resultado[i] = 0;
        for (int j = 0; j < columnas4; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }
}

// Función para imprimir el vector resultado
void imprimirVectorResultado(int vector[filas4]) {
    printf("Resultado (matriz *  vector):\n");
    for (int i = 0; i < filas4; i++) {
        printf("%4d\n", vector[i]);
    }
}

void transpuestaMatriz(int filas3, int columnas3, int matriz[filas3][columnas3], int transpuesta[columnas3][filas3]) {
    for(int i = 0; i < filas3; i++) {
        for (int j = 0; j < columnas3; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
}

void multiplicacionMatriz(int filas3, int columnas3, int matriza[filas3][columnas3], int matrizb[columnas3][filas3], int multiplicacion[columnas3][filas3]) {
    for (int i = 0; i < filas3; i++) {
        for (int j = 0; j < columnas3; j++) {
            multiplicacion[i][j] = 0;
            for (int k = 0; k < columnas3; k++) {
                multiplicacion[i][j] = multiplicacion[i][j] + (matriza[i][k] * matrizb[k][j]);
            }
        }
    }
}

void llenarMatriz4(char *nombre, int n, int matriz[n][n]) {
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Ingrese el valor para la posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Imprimir la matriz
void imprimirMatriz4(char *nombre, int n, int matriz[n][n]) {
    printf("\nNombre de la matriz: %s\n", nombre);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Multiplicar dos matrices cuadradas
void multiplicar(int n, int A[n][n], int B[n][n], int resultado[n][n]) {
    // Inicializar la matriz resultado en cero
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            resultado[i][j] = 0;

    // Multiplicación estándar de matrices
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                resultado[i][j] += A[i][k] * B[k][j];
}

// Copiar matriz origen a destino
void copiarMatriz(int n, int origen[n][n], int destino[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            destino[i][j] = origen[i][j];
}

// Elevar la matriz a un exponente entero positivo
void elevarMatriz(int n, int matriz[n][n], int exponente, int resultado[n][n]) {
    // Inicializar como matriz identidad
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            resultado[i][j] = (i == j) ? 1 : 0;

    int temp[n][n];  // Matriz temporal

    for (int i = 0; i < exponente; i++) {
        multiplicar(n, resultado, matriz, temp);     // resultado × matriz → temp
        copiarMatriz(n, temp, resultado);            // temp → resultado
    }
}


void setColor(const char* color){
    printf("%s", color);
}

void gotoxy(int x, int y){
    printf("\033[%d;%dH", x, y);
}




int main(){
    int opc;
    printf("%s\n", "selecciona una opcion");
    printf("%s\n", "1) Estrucura estudiante");
    printf("%s\n", "2) Estrutura declarativa");
    printf("%s\n", "3) Declaracion arreglo"); //ya//
    printf("%s\n", "4) Declaracion leer"); //ya//
    printf("%s\n", "5) Estructura lectura");//ya//
    printf("%s\n", "6) Arreglo estructuras");//ya
    printf("%s\n", "7) Estrutura aninada");//ya
    printf("%s\n", "8) Estrutura doble aninada");//ya//
    printf("%s\n", "9) clave valor");//ya//
    printf("%s\n", "10) multiplicacion estrutura");//ya//
    printf("%s\n", "11) Ecuacion cuadratica");//ya//
    printf("%s\n", "12) Ecuacion cuadratica datos"); //ya//
    printf("%s\n", "13) coordenadas");//ya//
    printf("%s\n", "14) coordenadas remasterizada");//ya//
    printf("%s\n", "15) Estrutura impresion");//ya//
    printf("%s\n", "16) Sprinft");//ya//
    printf("%s\n", "17) Union");//ya//
    printf("%s\n", "18) Vehiculos");//ya//
    printf("%s\n", "19) Matriz");//ya//
    printf("%s\n", "20) Matriz cadenas");//ya//
    printf("%s\n", "21) Matriz operacion");//ya//
    printf("%s\n", "22) Matriz estructura");//ya//
    printf("%s\n", "23) Estrutura union");//ya//
    printf("%s\n", "24) Menu Estrutura union");//ya//
    printf("%s\n", "25) Matriz inversa");//ya//
    printf("%s\n", "26) Apuntador 1");//ya//
    printf("%s\n", "27) Indirecciones");//ya//
    printf("%s\n", "28) Apuntadores operacion");//ya//
    printf("%s\n", "29) Apuntadores constante");//ya//
    printf("%s\n", "30) Manipulacion Registro");//ya//
    printf("%s\n", "31) Funciones");//ya//
    printf("%s\n", "32) Funcion figura");//ya//
    printf("%s\n", "33) numero mayor");//ya//
    printf("%s\n", "34) numero mayor en 3 numeros");//ya//
    printf("%s\n", "35) Suma de numero en rango");//ya//
    printf("%s\n", "36) Positivo o negativo");//ya//
    printf("%s\n", "37) Exponenciales");//ya//
    printf("%s\n", "38) Matriz impar");//ya//
    printf("%s\n", "39) Intervalo par");//ya//
    printf("%s\n", "40) Tabla multiplicacion funcion");//ya//
    printf("%s\n", "41) palabras numeros");//ya//
    printf("%s\n", "42) Temperatura");//ya//
    printf("%s\n", "43) F a C");//ya//
    printf("%s\n", "44) K a F");//ya//
    printf("%s\n", "45) C a k");//ya//
    printf("%s\n", "46) Cambio de moneda");//ya//
    printf("%s\n", "47) Ecuacion funcion");//ya//
    printf("%s\n", "48) Matriz Funcion");//ya//
    printf("%s\n", "49) Matriz raiz cuadrada");//ya//
    printf("%s\n", "50) Matriz por vector");//ya//
    printf("%s\n", "51) Transpuesta");//ya//
    printf("%s\n", "52) Multiplicacion matriz por funcion");//ya//
    printf("%s\n", "53) Multiplicacion matriz por funcion y en fracciones");//ya//
    printf("%s\n", "54) Matriz exponente");//ya//
    printf("%s\n", "55) colores");//ya//
    printf("%s\n", "56) gotoxy");//ya//
    printf("%s\n", "57) gotoxy leer");//ya//
    printf("%s\n", "58) Menu colores");//ya//
    printf("%s\n", "59) Menu colores 2");//ya//
    printf("%s\n", "60) Tringulo colores");//ya//
    printf("%s\n", "61) Badnera Mexico");//ya//
    printf("%s\n", "62) Bandera EU");//ya//
    printf("%s\n", "63) Cuadradi");//ya//
    
    scanf("%d", &opc);
    switch(opc){
        case 1:
            printf("%s\n","Estrucura estudiante");
            
            struct Estudiante estudiante1= {"Asael Camilo", 19, 8.5};

            printf("nombre: %s\n", estudiante1.nombre);
            printf("Edad: %d\n", estudiante1.edad);
            printf("Promedio: %.1f\n", estudiante1.promedio);
        
            
            break;
        case 2:
            printf("%s\n","Estrutura declarativa");

            Estudiante2 estudiante12 = {"Maria Lopez", 22, 9.3};
            printf("nombre: %s\n", estudiante12.nombre);
            printf("Edad: %d\n", estudiante12.edad);
            printf("Promedio: %.1f\n", estudiante12.promedio);
            break;
        case 3:
            printf("%s\n","Declaracion arreglo");

            int num [] = {12, 20 ,30, 20};
            int size = sizeof(num)/sizeof(num[0]);
        
            printf("Tamanio: %d\n", size);
        
            for (int i = 0 ; i < size; i++){
                printf("numeros[%d] = %d\n", i, num[i]);
            }
            break;
        case 4:{
            printf("%s\n","numero 4");

            int size;
            printf("ingrese el tamaño del arreglo: \n");
            scanf("%d", &size);
        
            int arreglonum[size];
        
            for (int i = 0 ; i < size; i++){
                printf("Ingrese el valor en posicion [%d]: \n", i);
                int swap;
                scanf("%d", &swap);
                arreglonum[i] = swap;
            }
            //imprime los valores del arreglo
            for(int i = 0 ; i < size; i++){
                printf("arreglo[%d] = %d\n", i, arreglonum[i]);
            }
        } 
        break;

        case 5:
            printf("%s\n","numero 5");
            struct Usuario usuario1;

            printf("Ingrese su nombre\n");
            scanf("%s", usuario1.nombre);
            printf("Ingrese su edad\n");
            scanf("%s", usuario1.edad);
            printf("Ingrese su correo\n");
            scanf("%s", usuario1.correo);
        
            printf("\nDatos del usuario:\n");
            printf("Nombre: %s\n", usuario1.nombre);
            printf("Edad", usuario1.edad);
            printf("correo: %s\n", usuario1.correo);
        break;
        
        case 6:{
            printf("%s\n","numero 6");
            int size;

            printf("Ingrese la cantidad de estructuras: \n");
            scanf("%d", &size);
        
            struct Persona persona[size];
        
            for (int i = 0; i < size; i++) {
                printf("Ingrese su nombre: ");
                scanf(" %s", persona[i].nombre);  
        
                printf("Ingrese su edad: ");
                scanf("%d", &persona[i].edad);
        
                printf("Ingrese su correo: ");
                scanf(" %s", persona[i].correo);
        
                printf("Ingrese su promedio: ");
                scanf("%f", &persona[i].promedio);
        
                printf("Ingrese su telefono: ");
                scanf(" %s", persona[i].telefono);
        
                printf("Ingrese su comida favorita: ");
                scanf(" %s", persona[i].comidafav);
        
                printf("Ingrese su juego favorito: ");
                scanf(" %s", persona[i].videojuegofav);
        
                printf("Ingrese su grupo: ");
                scanf("%d", &persona[i].grupo);
            }
        
            printf("\n--- Datos ingresados ---\n");
        
            for (int i = 0; i < size; i++) {
                printf("\nPersona [%d]:\n\n", i);
                printf("Nombre: %s\n", persona[i].nombre);
                printf("Edad: %d\n", persona[i].edad);
                printf("Correo: %s\n", persona[i].correo);
                printf("Promedio: %.2f\n", persona[i].promedio);
                printf("Telefono: %s\n", persona[i].telefono);
                printf("Comida favorita: %s\n", persona[i].comidafav);
                printf("Juego favorito: %s\n", persona[i].videojuegofav);
                printf("Grupo: %d\n", persona[i].grupo);
            }
        }
        break;

        case 7:
            printf("%s\n","numero 7");
            struct Persona2 persona1 = {"Carlos Ramirez", {"Av.Reforma", 206}};
            printf("nombre: %s\n", persona1.nombre);
             printf("Domicilio: %s #%d\n", persona1.domilicio.calle, persona1.domilicio.num);
        break;

        case 8:{
            printf("%s\n","numero 8");
            int size;
            printf("Ingrese la cantidad de estructuras: \n");
            scanf("%d", &size);
        
            struct Estudiante3 alumno1[size];
            for (int i = 0; i < size; i++) {
                printf("Ingrese su nombre:");
                scanf("%s", alumno1[i].nombre);
        
                printf("Ingrese su calle:");
                scanf("%s", alumno1[i].domicilio2.calle);
        
                printf("Ingrese su numero: ");
                scanf("%d", &alumno1[i].domicilio2.numero);
        
                printf("Ingrese su coordenada x: ");
                scanf("%d", &alumno1[i].domicilio2.lugar.x);
        
                printf("Ingrese su coordenada y: ");
                scanf("%d", &alumno1[i].domicilio2.lugar.y);
        
            }
        
            printf("\n--- Datos ingresados ---\n");
        
            for (int i = 0; i < size; i++){
                printf("\nEstudiante [%d]:\n\n", i);
                printf("nombre: %s\n", alumno1[i].nombre);
                printf("Direccion: %s #%d\n", alumno1[i].domicilio2.calle, alumno1[i].domicilio2.numero);
                printf("Las coordenadas x son: %d", alumno1[i].domicilio2.lugar.x);
                printf("\nLas coordenadas y son: %d\n", alumno1[i].domicilio2.lugar.y);
            }
        }
        break;

        case 9:{
            printf("%s\n","numero 9");
            struct KeyValue tabla[3] ={
                {"usuario", "admin"},
                {"contrasena", "1234"},
                {"servidor", "localhost"}
            };
        
            printf("Tabla clave-valor:\n");
            for(int i =0; i<3; i++){
                printf("%s: %s\n", tabla[i].clave, tabla[i].valor);
            }
        }

        break;

        case 10:{
            printf("%s\n","numero 10");
            struct Tabla arreglo[3] = {
                {1,3,0},
                {2,3,0},
                {3,3,0},    
            };
        
        
        for(int i = 0; i<3; i++){
            int resultado = arreglo[i].valor1 * arreglo[i].valor2;
            arreglo[i].resultado = resultado;
            }
        
            for(int i = 0; i<3; i++){
                printf("%d x %d = %d\n",
                    arreglo[i].valor1,
                    arreglo[i].valor2,
                    arreglo[i].resultado);
            }
            return 0;
        }

        break;

        case 11:{
            printf("%s\n","numero 11");
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
        }

        break;

        case 12:{
            printf("%s\n","numero 12");
            int size2; // Variable para almacenar la cantidad de ecuaciones que se ingresarán
            printf("Ingrese la cantidad de ecuaciones: \n"); // Pedimos al usuario la cantidad de ecuaciones
            scanf("%d", &size2); // Leemos la cantidad ingresada por el usuario
            struct Eccradratica2 arreglo2[size2]; // Declaramos un arreglo de estructuras de tamaño 'size2'
            
            for(int i = 0; i < size2; i++) { // Bucle para ingresar los coeficientes de cada ecuación
                printf("%s"," ingrese el valor de a2:"); // Pedimos el coeficiente a2
                scanf("%d", &arreglo2[i].a2); // Leemos el valor de a2
                printf("%s"," ingrese el valor de b2:"); // Pedimos el coeficiente b2
                scanf("%d", &arreglo2[i].b2); // Leemos el valor de b2
                printf("%s"," ingrese el valor de c2:"); // Pedimos el coeficiente c2
                scanf("%d", &arreglo2[i].c2); // Leemos el valor de c2
            }  
        
            for (int i = 0; i < size2; i++) { // Bucle para calcular las soluciones de cada ecuación cuadrática
                int d2 = (arreglo2[i].b2 * arreglo2[i].b2) - (arreglo2[i].a2 * arreglo2[i].c2); // Calculamos la determinante (b2^2 - 4a2c2)
                if(d2 < 0) { // Si la determinante es menor que 0
                    strcpy(arreglo2[i].soluc2, "no tiene solucion"); // Guardamos "no tiene solucion" en el campo soluc2
                } else { // Si la determinante es mayor o igual a 0
                    float valx12 = ((-1) * arreglo2[i].b2 + sqrt(d2)) / (2 * arreglo2[i].a2); // Calculamos la primera raíz
                    float valx22 = ((-1) * arreglo2[i].b2 - sqrt(d2)) / (2 * arreglo2[i].a2); // Calculamos la segunda raíz
                    strcpy(arreglo2[i].soluc2, "Tiene solucion"); // Guardamos "Tiene solucion" en el campo soluc2
                    arreglo2[i].x12 = valx12; // Almacenamos la primera raíz en la estructura
                    arreglo2[i].x22 = valx22; // Almacenamos la segunda raíz en la estructura
                }
            }
        
            printf("\n--- Resultados ---\n"); // Imprimimos encabezado de los resultados
            printf("%s|%s|%s|%s|%s|%s\n", "a2", "b2", "c2", "x12", "x22", "soluc2"); // Imprimimos los nombres de las columnas
            for (int i = 0; i < size2; i++) { // Bucle para imprimir los resultados de cada ecuación
                printf("\nEcuacion [%d]:\n", i); // Imprimimos el número de ecuación
                printf("%d | %d | %d | %.2f | %.2f | %s \n",
                        arreglo2[i].a2,
                        arreglo2[i].b2,
                        arreglo2[i].c2,
                        arreglo2[i].x12,
                        arreglo2[i].x22,
                        arreglo2[i].soluc2); // Imprimimos los valores de la ecuación y sus soluciones
            } 
        }

        break;

        case 13:{
            printf("%s\n","numero 13");
            int opc; // Variable para almacenar la opción seleccionada por el usuario
            printf("%s\n", "Selecciona una opcion:"); // Mostramos el menú de selección
            printf("%s\n", "1.-cuadrado");
            printf("%s\n", "2.-triangulo");
            scanf("%d", &opc); // Leemos la opción ingresada por el usuario
            struct Coordenadas2 figura; // Declaramos una variable de tipo Coordenadas2
        
            switch(opc) { // Evaluamos la opción ingresada por el usuario
                case 1: 
                    printf("%s\n", "ha seleccionado cuadrado"); // Pedimos al usuario que ingrese las coordenadas de los cuatro vértices del cuadrado
                    printf("%s", "ingrese el valor para la coordenada x13\n"); // pide valor de x13
                    scanf("%d", &figura.x13); // lee x13
                    printf("%s", "ingrese el valor para la coordenada y13\n"); // pide valor de y13
                    scanf("%d", &figura.y13); // lee y13
                    printf("%s", "ingrese el valor para la coordenada x23\n"); // pide valor de x23
                    scanf("%d", &figura.x23); // lee x23
                    printf("%s", "ingrese el valor para la coordenada y23\n"); // pide valor de y23
                    scanf("%d", &figura.y23); // lee y23
                    printf("%s", "ingrese el valor para la coordenada x3\n"); // pide valor de x3
                    scanf("%d", &figura.x3); // lee x3
                    printf("%s", "ingrese el valor para la coordenada y3\n"); // pide valor de y3
                    scanf("%d", &figura.y3); // lee y3
                    printf("%s", "ingrese el valor para la coordenada x4\n"); // pide valor de x4
                    scanf("%d", &figura.x4); // lee x4
                    printf("%s", "ingrese el valor para la coordenada y4\n"); // pide valor de y4
                    scanf("%d", &figura.y4); // lee y4
        
                    // Calculamos las distancias entre los puntos para determinar los lados del cuadrado
                    float d1 = sqrt(pow(figura.x23 - figura.x13, 2) + pow(figura.y23 - figura.y13, 2)); // se resta las coordenadas luego se elevan al cuadrado y se saca raíz del resultado
                    float d2 = sqrt(pow(figura.x3 - figura.x23, 2) + pow(figura.y3 - figura.y23, 2)); // se resta las coordenadas luego se elevan al cuadrado y se saca raíz del resultado
                    float d3 = sqrt(pow(figura.x4 - figura.x3, 2) + pow(figura.y4 - figura.y3, 2)); // se resta las coordenadas luego se elevan al cuadrado y se saca raíz del resultado
                    float d4 = sqrt(pow(figura.x13 - figura.x4, 2) + pow(figura.y13 - figura.y4, 2)); // se resta las coordenadas luego se elevan al cuadrado y se saca raíz del resultado
                    float perimetro = d1 + d2 + d3 + d4; // Calculamos el perímetro y el área del cuadrado
                    float area = d1 * d2;
                    printf("Perimetro del cuadrado: %.2f\n", perimetro); // Mostramos los resultados del perímetro
                    printf("Area del cuadrado: %.2f\n", area); // Mostramos los resultados de área
                    break; // se acaba el caso
        
                case 2:
                    printf("%s\n", "ha seleccionado triangulo"); // Se selecciona el triángulo
                    // Pedimos al usuario que ingrese las coordenadas de los tres vértices del triángulo
                    printf("%s", "ingrese el valor para la coordenada x1\n"); // pide valor de x13
                    scanf("%d", &figura.x13); // lee x13
                    printf("%s", "ingrese el valor para la coordenada y1\n"); // pide valor de y13
                    scanf("%d", &figura.y13); // lee y13
                    printf("%s", "ingrese el valor para la coordenada x2\n"); // pide valor de x23
                    scanf("%d", &figura.x23); // lee x23
                    printf("%s", "ingrese el valor para la coordenada y2\n"); // pide valor de y23
                    scanf("%d", &figura.y23); // lee y23
                    printf("%s", "ingrese el valor para la coordenada x3\n"); // pide valor de x3
                    scanf("%d", &figura.x3); // lee x3
                    printf("%s", "ingrese el valor para la coordenada y3\n"); // pide valor de y3
                    scanf("%d", &figura.y3); // lee y3
                    // Calculamos las distancias entre los puntos para determinar los lados del triángulo
                    float d1t = sqrt(pow(figura.x23 - figura.x13, 2) + pow(figura.y23 - figura.y13, 2)); // se resta las coordenadas luego se elevan al cuadrado y se saca raíz del resultado
                    float d2t = sqrt(pow(figura.x3 - figura.x23, 2) + pow(figura.y3 - figura.y23, 2)); // se resta las coordenadas luego se elevan al cuadrado y se saca raíz del resultado
                    float d3t = sqrt(pow(figura.x13 - figura.x3, 2) + pow(figura.y13 - figura.y3, 2)); // se resta las coordenadas luego se elevan al cuadrado y se saca raíz del resultado
                    float perimetrot = d1t + d2t + d3t; // Calculamos el perímetro del triángulo
                    float s = perimetrot / 2; // Calcular el semiperímetro
                    float areat = sqrt(s * (s - d1t) * (s - d2t) * (s - d3t)); // Aplicar la fórmula de Herón
                    printf("Perimetro del triangulo: %.2f\n", perimetrot); // Mostramos los resultados de perímetro
                    printf("Area del triangulo: %.2f\n", areat); // Mostramos los resultados de área
                    break; // acaba el caso
        
                default:
                    printf("%s\n", "no ha seleccionado una opcion valida"); // Mensaje de error si la opción es inválida
                    break;
            }
        }

        break;

        case 14:{
            
        }

        break;

        case 15:{
            printf("%s\n","numero 15");
            int n;

            printf("ingresar el numero de personas: ");
            scanf("%d", &n);
            getchar();
        
            struct Persona3 personas[n];
            for(int i = 0; i < n; i++){
                printf("\nIngrese los datos de la persona %d:\n", i + 1);
        
                printf("nombre: ");
                scanf("%s", personas[i].nombre);
        
                printf("calle: ");
                scanf("%s", personas[i].domicilio3.calle);
        
                printf("numero: ");
                scanf("%d", &personas[i].domicilio3.numero);
                getchar();
            }
        
            printf("\n%--20s | %--20s | %--10s\n", "nombre", "direccion", "numero");
            printf("---------------------------------------------------------------\n");
        
            for(int i = 0; i < n; i++){
                printf("%--20s | %--20s | %--10d\n",
                        personas[i].nombre,
                        personas[i].domicilio3.calle,
                        personas[i].domicilio3.numero);
                        
            }
        }

        break;

        case 16:{
            printf("%s\n","numero 16");
            char buffer[100];
            float pi = 3.14159;
            sprintf(buffer, "The value of pi is %.2f.", pi);
            printf("%s\n", buffer);
            return 0;
        }

        break;

        case 17:{
            printf("%s\n","numero 17");
            union Dato variable;

            variable.entero = 42;
            printf("Entero: %d\n", variable.entero);
        
            variable.decimal = 3.14;
            printf("Decimal: %d\n", variable.decimal);
        
            sprintf(variable.texto, "hola.c");
            printf("Texto: %d\n", variable.entero);
        
            printf("\nDespues de asignar un texto:\n");
            printf("Entero: %d\n", variable.entero);
            printf("Decimal: %.2f\n", variable.decimal);
            printf("Texto: %s\n", variable.texto);
        }

        break;

        case 18:{
            printf("%s\n","numero 18");
            union Camion camion;
            camion.vehiculo = (struct Vehiculo){4,"azul",45,123000};
            camion.asientos = 4;
            camion.puertas = 6;
        
            union Moto moto;
            moto.vehiculo = (struct Vehiculo){2,"negra",123,123211};
            moto.cc=1231;
        
            printf("\nSe imprimen valores camion\n");
            printf("asientos: %d\n", camion.asientos);
            printf("puertas: %d\n", camion.puertas);
            printf("llantas: %d\n", camion.vehiculo.llantas);
            printf("color: %s\n",camion.vehiculo.color);
            printf("cabalos de fuerza: %d\n",camion.vehiculo.caballosfuerza);
            printf("kilometraje: %d\n",camion.vehiculo.kilometraje);
        
            printf("\nSe imprimen valores moto\n");
            printf("llantas: %d\n", moto.vehiculo.llantas);
            printf("color: %s\n",moto.vehiculo.color);
            printf("cabalos de fuerza: %d\n",moto.vehiculo.caballosfuerza);
            printf("kilometraje: %d\n",moto.vehiculo.kilometraje);
            printf("cc: %d\n", moto.cc);
        }
        break;

        case 19:{
            printf("%s\n","numero 19");
            int matriz [Filas][columnas] = {
                {1,2,3},
                {4,5,6},
                {7,8,9}
            };
        
            printf("recorriendo la matriz: \n");
            for(int i=0; i<Filas; i++){
                for(int j = 0; j< columnas; j++){
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }
            return 0;
        }
        break;

        case 20:{
            printf("%s\n","numero 20");
            char matriz [Filas][columnas][50];
            for (int i = 0; i < Filas; i++){
                for(int j = 0; j< columnas; j++){
                printf("dame la palabra: ");
                scanf("%s", matriz[i][j]);
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

        }

        break;
        
        case 21:{
            printf("%s\n","numero 21");
            int matriz[FILAS][COLUMNAS];

            printf("Ingrese los valores para la matriz :\n");
        
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    if (j < 2) {  
                        printf("Fila %d - Columna %d: ", i + 1, j + 1);
                        scanf("%d", &matriz[i][j]);
                    } else {
                        matriz[i][j] = 0;  
                    }
                }
            }
        
            
            for (int i = 0; i < FILAS; i++) {
                matriz[i][2] = matriz[i][0] + matriz[i][1];  
                matriz[i][3] = matriz[i][0] - matriz[i][1];  
                matriz[i][4] = matriz[i][0] * matriz[i][1];  
                if (matriz[i][1] != 0) {
                    matriz[i][5] = matriz[i][0] / matriz[i][1];  
                } 
                    
                
            }  
            printf("\nMatriz con resultados:\n");
            printf("%-10s | %-10s | %-10s | %-10s | %-10s | %-10s\n", "Val1", "Val2", "Suma", "Resta", "Multi", "Div");
            printf("------------------------------------------------------------------------\n");
        
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    if (j == 5 && matriz[i][5] == -1) {  
                        printf("%-10s | ", "ERROR");
                    } else {
                        printf("%-10d | ", matriz[i][j]);
                    }
                }
                printf("\n");
            }
        }

        break;

        case 22:{
            printf("%s\n","numero 22");
            struct Videojuego matriz[Filas][columnas];
            printf("Ingrese los valores para la matriz :\n");
        
            for (int i = 0; i < Filas; i++){
                for(int j = 0; j< columnas; j++){
                printf("dame el nombre del juego: ");
                scanf(" %49[^\n]", matriz[i][j].nombre);
                printf("dame el anio de salida del juego: ");
                scanf("%d", &matriz[i][j].anio);
                }
            }
        
            printf("recorriendo la matriz: \n");
            for(int i=0; i<Filas; i++){
                for(int j = 0; j< columnas; j++){
                    printf("%-22s%d ", matriz[i][j].nombre, matriz[i][j].anio);
                    printf(" | "); 
                }
                printf("\n");
            }

        }

        break;

        case 23:{
            printf("%s\n","numero 23");
            Celda matriz[Fila][Columna];

            strcpy(matriz[0][0].valor.persona.nombre, "Roberto");
            matriz[0][0].valor.persona.edad = 25;
            matriz[0][0].tipo = 1;
        
            strcpy(matriz[0][1].valor.persona.nombre,  "Alejandro");
            matriz[0][1].valor.persona.edad = 30;
            matriz[0][1].tipo = 1;
        
            strcpy(matriz[1][0].valor.producto.producto, "conejo");
            matriz[1][0].valor.producto.precio = 88.99;
            matriz[1][0].tipo = 2;
        
            strcpy(matriz[1][1].valor.producto.producto, "Golden");
            matriz[1][1].valor.producto.precio = 1377.99;
            matriz[1][1].tipo = 2;
        
            printf("Recorreindo la matriz de uniones de estructuras:\n");
        
            for(int i = 0; i < Fila; i++){
                for(int j= 0; j<Columna; j++){
                    printf("Celda [%d][%d]: ",i,j);
                    if (matriz[i][j].tipo == 1){
                        printf("Persona - Nombre: %s, Edad: %d\n",
                                matriz[i][j].valor.persona.nombre,
                                matriz[i][j].valor.persona.edad);
                    }else if(matriz[i][j].tipo == 2){
                        printf("Producto - Nombre: %s, Precio: %.2f\n",
                                matriz[i][j].valor.producto.producto,
                                matriz[i][j].valor.producto.precio);
                    }
                }
            }

        }

        break;

        case 24:{
            printf("%s\n","numero 24");
            Celda2 matriz[Fila][Columna];
            for(int i = 0; i < Fila; i++){
                for(int j = 0; j < Columna; j++){
                    int opc = 0;
                    printf("Selecciona una opcion: 1)Perro 2)Gato");
                    scanf("%d", &opc);
        
                    switch (opc){
                        case 1:
                            printf("ingrese nombre del perro:");
                            char nombre[20];
                            int edad;
                            scanf("%s", nombre);
                            strcpy(matriz[i][j].valor.perro.nombre, nombre);
                            printf("ingrese edad del perro:");
                            scanf("%d", &edad);
                            matriz[i][j].valor.perro.edad = edad;
                            matriz[i][j].tipo = 1;
                        break;
                            
                        case 2:
                            printf("ingrese nombre del gato:");
                            char nombre2[20];
                            float meses;
                            scanf("%s", nombre2);
                            strcpy(matriz[i][j].valor.gato.nombre, nombre2);
                            printf("ingrese los meses del gato:");   
                            scanf("%f", &meses);
                            matriz[i][j].valor.gato.meses = meses;
                            matriz[i][j].tipo = 2;
                        
                        break;
        
                        default:
                            printf("%s\n","no ha seleccionado una opcion valida");
                        break;
        
                    }
                }
            }
        
            for(int i = 0; i < Fila; i++){
                for(int j= 0; j<Columna; j++){
                    printf("Celda [%d][%d]: ",i,j);
                    if (matriz[i][j].tipo == 1){
                        printf("Perro - Nombre: %s, Edad: %d\n",
                                matriz[i][j].valor.perro.nombre,
                                matriz[i][j].valor.perro.edad);
                    }else if(matriz[i][j].tipo == 2){
                        printf("Gato - Nombre: %s, meses: %.1f\n",
                                matriz[i][j].valor.gato.nombre,
                                matriz[i][j].valor.gato.meses);
                    }
                }
            }
        }

        break;

        case 25:{
            printf("%s\n","numero 25");
        }

        break;

        case 26:{
            printf("%s\n","numero 26");
            int num1, num2;
            int *ptr1, *ptr2;
        
            ptr1 = &num1;
            ptr2 = &num2;
            printf("%p\n", *ptr1);
            printf("%p\n", *ptr2);
        
            num1 = 10;
            num2 = 20;
        
            ptr1 = ptr2;
            ptr2 = NULL;
            printf("%p\n", ptr1);
            printf("%p\n", ptr2);
        }

        break;

        case 27:{
            printf("%s\n","numero 27");
            int numero = 42;                // Variable entera
            int *ptr = &numero;             // Puntero apuntando a 'numero'
            int **ptr_doble = &ptr;         // Puntero doble apuntando a 'ptr'
         
            printf("Valor de 'numero': %d\n", numero);
            printf("Direccion de 'numero': %p\n", (void*)&numero);
         
            printf("\nUsando puntero simple:\n");
            printf("Valor de 'ptr': %p\n", (void*)ptr);
            printf("Valor al que apunta 'ptr': %d\n", *ptr);
            printf("Direccion de 'ptr': %p\n", (void*)&ptr);
         
            printf("\nUsando puntero doble:\n");
            printf("Valor de 'ptr_doble': %p\n", (void*)ptr_doble);
            printf("Valor al que apunta 'ptr_doble' (direccion de 'ptr'): %p\n", (void*)*ptr_doble);
            printf("Valor final al que apunta 'ptr_doble': %d\n", **ptr_doble);
            printf("Direccion de 'ptr_doble': %p\n", (void*)&ptr_doble);
        }

        break;

        case 28:{
            printf("%s\n","numero 28");
            int fno, sno, *ptr, *qtr, sum, res, multi, *sumapt, *restapt, *multiapt, *diviapt;// Declaración de variables y punteros
            float divi;
            
            printf("Numero 1:\n"); // Solicita al usuario ingresar el primer número
            scanf("%d", &fno);// Almacena el primer número ingresado en la variable fno
            printf("Numero 2:\n");// Solicita al usuario ingresar el segundo número
            scanf("%d", &sno);// Almacena el segundo número ingresado en la variable sno
            
            ptr=&fno;// ptr apunta a la dirección de memoria de fno
            qtr=&sno;// qtr apunta a la dirección de memoria de sno
            
            printf("\nApuntador1: %p", ptr);// Imprime la dirección de memoria de fno
            printf("\nApuntador2: %p\n\n", qtr);// Imprime la dirección de memoria de sno
            
            sum=*ptr + *qtr;// Suma los valores almacenados en fno y sno utilizando punteros
            res=*ptr - *qtr;// Resta los valores almacenados en fno y sno
            multi=*ptr * *qtr;// multiplica los valores almacenados en fno y sno
            divi=(float)*ptr / *qtr;// divide los valores almacenados en fno y sno
            
            printf("La suma es: %d\n", sum);// Imprime el resultado de la suma
            printf("La resta es: %d\n", res);// Imprime el resultado de la resta
            printf("La multiplicacion es: %d\n", multi);// Imprime el resultado de la multiplicacion 
            printf("La division es: %.2f\n\n", divi);// Imprime el resultado de la division
            
            
            sumapt=&sum;// sumapt apunta a la dirección de memoria de sum
            restapt=&res;// resapt apunta a la dirección de memoria de res
            multiapt=&multi;// mulapt apunta a la dirección de memoria de mul
            diviapt=&divi;// divapt apunta a la dirección de memoria de div
            
            printf("Apuntador de la suma: %p\n", sumapt);// Imprime la dirección de memoria de sum
            printf("Apuntador de la resta: %p\n", restapt);// Imprime la dirección de memoria de res
            printf("Apuntador de la multiplicacion: %p\n", multiapt);// Imprime la dirección de memoria de mul
            printf("Apuntador de la division: %p\n", diviapt);// Imprime la dirección de memoria de div
        }
        break;

        case 29:{
            printf("%s\n","numero 29");
            int a,b,c,d,e;

            printf("ingrese valor a\n");
            scanf("%d", &a);
            printf("ingrese valor b\n");
            scanf("%d", &b);
            printf("ingrese valor c\n");
            scanf("%d", &c);
            printf("ingrese valor d\n");
            scanf("%d", &d);
            printf("ingrese valor e\n\n");
            scanf("%d", &e);
        
            int *const pa = &a;
            int *const pb = &b;
            int *const pc = &c;
            int *const pd = &d;
            int *const pe = &e;
        
            printf("Valores ingresados a=%p\n", &pa);
            printf("Valores ingresados b=%p\n", &pb);
            printf("Valores ingresados c=%p\n", &pc);
            printf("Valores ingresados d=%p\n", &pd);
            printf("Valores ingresados e=%p\n\n", &pe);
        
            int suma = *pa + *pa;
            printf("Resuldato de la suma: %d\n", suma);
        
            *pa = suma;
            printf("Valor nuevo: a=%d\n\n", *pa);
        
            int resta = *pb - *pb;
            printf("Resuldato de la resta: %d\n", resta);
        
            *pb = resta;
            printf("Valor nuevo b:=%d\n\n", *pb);
        
            int multi = *pc * *pc;
            printf("Resuldato de la multiplicacion: %d\n", multi);
        
            *pb = multi;
            printf("Valor nuevo: c=%d\n\n", *pc);
        
            int divi = *pd + *pd;
            printf("Resuldato de la division: %d\n", resta);
        
            *pd = divi;
            printf("Valor nuevo: d=%d\n\n", *pd);
        }

        break;

        case 30:{
            printf("%s\n","numero 30");
            int a,b,c,d,e,f;

            printf("ingrese valor a\n");
            scanf("%d", &a);
            printf("ingrese valor b\n");
            scanf("%d", &b);
            printf("ingrese valor c\n");
            scanf("%d", &c);
            printf("ingrese valor d\n");
            scanf("%d", &d);
            printf("ingrese valor e\n");
            scanf("%d", &e);
            printf("ingrese valor f\n");
            scanf("%d", &f);
        
            int *const pa = &a;
            int *const pb = &b;
            int *const pc = &c;
            int *const pd = &d;
            int *const pe = &e;
            int *const pf = &f;
            int *const pr;
        
            printf("\nvalor de a=%d\n", *pa);
            printf("valor de b=%d\n", *pb);
            printf("Posicion de a=%p\n", &pa);
            printf("Posicion de b=%p\n", &pb);
            
            int suma1 = *pa + *pb;
            *pr = suma1;
            printf("Resuldato de la suma: %d\n", *pr);
        
            int resta1 = *pa - *pb;
            *pr = resta1;
            printf("Resuldato de la resta: %d\n", *pr);
        
            int multi1 = *pa * *pb;
            *pr = multi1;
            printf("Resuldato de la multiplicacion: %d\n", *pr);
        
            int divi = *pd / *pd;
            *pr = divi;
            printf("Resuldato de la division: %d\n\n",*pr);
        
            printf("valor de c=%d\n", *pc);
            printf("valor de d=%d\n", *pd);
            printf("Posicion de c=%p\n", &pc);
            printf("Posicion de d=%p\n", &pd);
            int suma2 = *pc + *pd;
            *pr = suma2;
            printf("Resuldato de la suma: %d\n", *pr);
            int resta2 = *pc - *pd;
            *pr = resta2;
            printf("Resuldato de la resta: %d\n", *pr);
            int multi2 = *pc * *pd;
            *pr = multi2;
            printf("Resuldato de la multi: %d\n", *pr);
            int divi2 = *pc / *pd;
            *pr = divi2;
            printf("Resuldato de la divi: %d\n\n", *pr);
        
            printf("valor de e=%d\n", *pe);
            printf("valor de f=%d\n", *pf);
            printf("Posicion de e=%p\n", &pe);
            printf("Posicion de f=%p\n", &pf);
        
            int suma3 = *pe + *pf;
            *pr = suma3;
            printf("Resuldato de la suma: %d\n", *pr);
            int resta3 = *pe - *pf;
            *pr = resta3;
            printf("Resuldato de la resta: %d\n", *pr);
            int multi3 = *pe * *pf;
            *pr = multi3;
            printf("Resuldato de la multi: %d\n", *pr);
            int divi3 = *pe / *pf;
            *pr = divi3;
            printf("Resuldato de la divi: %d\n\n", *pr);

        }
        break;

        case 31:{
            printf("%s\n","numero 31");
            int op1 = suma(2,3);
            int op2 = resta(5,3);
            int op3 = multi(3);
            float op4 = dividir(5,3);
            imprimir(op1,op2,op3,op4);
        }   
        break;

        case 32:{
            printf("%s\n","numero 32");
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
            
        }
        break;

        case 33:{
            printf("%s\n","numero 33");
            int a;
            int b;
            printf("Dame un numero\n");
            scanf("%d", &a);
            printf("Dame otro numero\n");
            scanf("%d", &b);
            int resultado = numero(a,b);
        
            printf("el numero mayor es: %d", resultado);
        }
        break;

        case 34:{
            printf("%s\n","numero 34");
            int a;
            int b;
            int c;
            printf("Dame un numero\n");
            scanf("%d", &a);
            printf("Dame otro numero\n");
            scanf("%d", &b);
            printf("Dame otro numero\n");
            scanf("%d", &c);
            int resultado = numero2(a,b,c);
        
            printf("el numero mayor es: %d", resultado);
        }
        break;

        case 35:{
            printf("%s\n","numero 35");
            int a;
            int b;
            printf("Dame el primer numero\n");
            scanf("%d", &a);
            printf("Dame el otro numero\n");
            scanf("%d", &b);
            int numeros = sumatoria(a,b);
            printf("La suma de los numeros en el rango es: %d\n", numeros);
        }
        break;

        case 36:{
            printf("%s\n","numero 36");
            int a;
            printf("Dame el numero y te dire si es positivo o negativo\n");
            scanf("%d", &a);
            int tipo = numero3(a);
            
            if(numero3(a) > 1){
                printf("el numero es postivo");
            }else{
                printf("el numero es negativo");
            }
        }
        break;

        case 37:{
            printf("%s\n","numero 35");
            int base, exponente; 
            printf("dame la base\n");
            scanf("%d", &base);
            printf("Dame el exponente\n");
            scanf("%d", &exponente);
        
            int resultado = exponencial(base, exponente);
            printf("%s%d", "El resulatdo es: ", resultado);
        }
        break;

        case 38:{
            printf("%s\n","numero 38");
            int matriz[Filas2][columnas2] ={
                {1,2,3,4,5,6},
                {7,8,9,10,11,12},
                {13,14,15,16,17,18},
                {19,20,21,22,23,24},
                {25,26,27,28,29,30},
                {31,32,33,34,35,36}
            };
        
            
            printf("\nRecorrido matriz:\n");
            for(int i=0; i<Filas2; i++){
                for(int j = 0; j< columnas2; j++){
                    if(j %2 == 1){
                    printf("%-10d ", matriz[i][j]);
                    printf(" | ");
                }else{
                    printf("%-10s ", "#");
                    printf(" | ");
                }
                }
                printf("\n");
            }
        }
        break;

        case 39:{
            printf("%s\n","numero 39");
            int a;
            int b;
            printf("Dame el primer numero\n");
            scanf("%d", &a);
            printf("Dame el otro numero\n");
            scanf("%d", &b);
            printf("los numeros pares dentro del intervalo son:\n");
            intervalo(a,b);
        }
        break;

        case 40:{
            printf("%s\n","numero 40");
            int a;
            printf("Dame un numero\n");
            scanf("%d", &a);
            printf("Tabla de multiplicar\n");
            tabla_mult(a);

        }
        break;

        case 41:{
            printf("%s\n","numero 41");
            int opc;
            printf("Dame un numero\n");
            scanf("%d", &opc);
            const char* resultado = palabras(opc);
            printf("Esta es la palabra del numero:%s\n", resultado);
        }
        break;

        case 42:{
            printf("%s\n","numero 42");
            float a;
            printf("Dame la temperatura en C y la convertire a F\n");
            scanf("%f", &a);
            float conversion = temperatura(a);
            printf("Esta es la conversion %.2f = %.2f",a,conversion);
            
        }
        break;

        case 43:{
            printf("%s\n","numero 43");
            
                float a;
                printf("Dame la temperatura en F y la convertire a C\n");
                scanf("%f", &a);
                float conversion = temperatura(a);
                printf("Esta es la conversion %.2f = %.2f",a,conversion);
            
        }
        break;

        case 44:{
            printf("%s\n","numero 44");
            float a;
            printf("Dame la temperatura en k y la convertire a F\n");
            scanf("%f", &a);
            float conversion = temperatura(a);
            printf("Esta es la conversion %.2f = %.2f",a,conversion);
        

        }
        break;

        case 45:{
            printf("%s\n","numero 45");
            float a;
            printf("Dame la temperatura en C y la convertire a k\n");
            scanf("%f", &a);
            float conversion = temperatura(a);
            printf("Esta es la conversion %.2f = %.2f",a,conversion);
        }
        break;
        
        case 46:{
            printf("%s\n","numero 46");
            float d;
            printf("Dame los dolares y te dire cuanto cuesta en pesos\n");
            scanf("%f", &d);
            float conversion = cambio(d);
            printf("Moneda Cantidad Precio\n");
            printf(" USD    %.2f     $%.2f\n", d, conversion);
        }
        break;

        case 47:{
            printf("%s\n","numero 47");
            float a, b, c;

            printf("Ingrese los coeficientes a, b y c de la ecuacion cuadratica:\n");
            scanf("%f %f %f", &a, &b, &c);
        
            if (a == 0) {
                printf("No es una ecuación cuadrática (a no puede ser 0).\n");
            } else {
                resolver_ecuacion(a, b, c);
            }
        
        }
        break;

        case 48:{
            printf("%s\n","numero 48");
            int filas3, columnas3;
            int escalar;
        
            printf("Ingrese el número de filas: ");
            scanf("%d", &filas3);
        
            printf("Ingrese el número de columnas: ");
            scanf("%d", &columnas3);
        
            printf("Dame el numero para sacar el escalar de A");
            scanf("%d", &escalar);
        
            int matriz_a[filas3][columnas3];
            int matriz_b[filas3][columnas3];
            int matriz_r[filas3][columnas3];
        
            int calcularDeterminante = (filas3 == 3 && columnas3 == 3);
        
            llenarMatriz("Matriz A", filas3, columnas3, matriz_a);
            llenarMatriz("Matriz B", filas3, columnas3, matriz_b);
        
            imprimirMatriz("Matriz A", filas3, columnas3, matriz_a);
            imprimirMatriz("MAtriz B", filas3, columnas3, matriz_b);
        
            sumarMatriz(filas3, columnas3, matriz_a, matriz_b, matriz_r);
            imprimirMatriz("SUMA A-B", filas3, columnas3, matriz_r);
        
            escalarMatriz(filas3, columnas3, matriz_a, escalar, matriz_r);
            imprimirMatriz("Escalar A", filas3, columnas3, matriz_r);
        
            if (calcularDeterminante) {
                int det = determinanteSarrus(matriz_a);
                printf("Determinante de Matriz A (Sarrus): %d\n", det);
            } else {
                printf("La determinante solo se puede calcular para matrices 3x3.\n");
            }
        
            saveMatriz(filas3, columnas3, matriz_r);
        
            
           
        }
        break;

        case 49:{
            printf("%s\n","numero 49");
            int numero;
            printf("Dame un numero: ");
            scanf("%d", &numero);
        
            bool flag = false;
            int raiz = 0;
        
            // Verificar si el número es cuadrado perfecto
            for (int i = 1; i <= 100; i++) {
                if (i * i == numero) {
                    flag = true;
                    raiz = i;
                    break;
                }
            }
        
            if (flag == true) {
                char matriz[raiz][raiz];
                char arreglo[raiz * raiz];
        
                llenarMatriz2("Matriz", raiz, matriz);
                imprimirMatriz2("Matriz", raiz, matriz);
                vaciarEnArreglo2(raiz, matriz, arreglo);
                imprimirArreglo2("Arreglo", arreglo, raiz * raiz);
            } else {
                printf("No tiene raiz\n");
            }
        
        }
        break;

        case 50:{
            printf("%s\n","numero 50");
            int matriz[filas4][columnas4];
            int vector[columnas4];
            int resultado[filas4];
        
            llenarMatriz3("Matriz A", matriz);
            imprimirMatriz3("Matriz A", matriz);
        
            llenarVector(vector);
        
            multiplicarMatrizPorVector(matriz, vector, resultado);
        
            imprimirVectorResultado(resultado);
        
        }
        break;

        case 51:{
            printf("%s\n","numero 51");
            int filas3, columnas3;
            printf("Ingrese el numero de filas: ");
            scanf("%d", &filas3);
            printf("Ingrese el numero de columnas: ");
            scanf("%d", &columnas3);
        
            int matriz_a[filas3][columnas3];
            int matriz_transpuesta[columnas3][filas3];
        
            llenarMatriz("Matriz A", filas3, columnas3, matriz_a);
            imprimirMatriz("Matriz A", filas3, columnas3, matriz_a);
        
            transpuestaMatriz(filas3, columnas3, matriz_a, matriz_transpuesta);
            imprimirMatriz("traspuesta", columnas3, filas3, matriz_transpuesta);
        }
        break;

        case 52:{
            printf("%s\n","numero 52");
            int filas3, columnas3;
            printf("Ingrese el numero de filas: ");
            scanf("%d", &filas3);
            printf("Ingrese el numero de columnas: ");
            scanf("%d", &columnas3);
        
            int matriz_a[filas3][columnas3];
            int matriz_b[filas3][columnas3];
            int multiplicacion[filas3][columnas3];
        
            llenarMatriz("Matriz A", filas3, columnas3, matriz_a);
            llenarMatriz("Matriz B", filas3, columnas3, matriz_b);
        
            imprimirMatriz("Matriz A", filas3, columnas3, matriz_a);
            imprimirMatriz("Matriz B", filas3, columnas3, matriz_b);
        
            multiplicacionMatriz(filas3, columnas3, matriz_a, matriz_b, multiplicacion);
            imprimirMatriz("multiplicacion", filas3, columnas3, multiplicacion);
        }
        break;

        case 53:{
            printf("%s\n","numero 53");
            
                
        }
        break;

        case 54:{
            printf("%s\n","numero 54");
            int n, exponente;

            printf("Ingrese el tamanio: ");
            scanf("%d", &n);
        
            printf("Ingrese el exponente: ");
            scanf("%d", &exponente);
        
            int matriz_a[n][n];
            int resultado[n][n];
        
            llenarMatriz4("Matriz A", n, matriz_a);
            imprimirMatriz4("Matriz A", n, matriz_a);
        
            elevarMatriz(n, matriz_a, exponente, resultado);
            imprimirMatriz4("Matriz A elevada", n, resultado);
        }
        break;

        case 55:{
            printf("%s\n","numero 55");     
                  //limpia pantalla 
    printf("\033[2J");

    setColor("\033[4;36m");
    printf("\n Bienvenido al progrma con marco y colores\n");

    //restaura color
    setColor("\033[0m");

    setColor("\033[7;34m");
    printf("\n Bienvenido al progrma con marco y colores\n");

    //restaura color
    setColor("\033[0m");

    setColor("\033[4;34m");
    printf("\n Bienvenido al progrma con marco y colores\n\n");

    setColor("\033[0m");  

        }
        break;

        case 56:{
            printf("%s\n","numero 56");       
            printf("\033[2J");//Limpia pantalla
            gotoxy(10,10);
            printf("Hola desde (10,5)");
            return 0;

        }
        break;

        case 57:{
            printf("%s\n","numero 57");       
            char nombre[50];
            int edad;
         
            printf("\033[2J"); // Limpia la pantalla
            setColor("\033[7;34m");
         
            gotoxy(10, 5);
            printf("Ingrese su nombre: ");
            gotoxy(30, 5); 
            setColor("\033[7;35m");
            scanf("%s", nombre);
         
            setColor("\033[7;34m");
            gotoxy(10, 7);
            printf("Ingrese su edad: ");
            gotoxy(30, 7);
            setColor("\033[7;35m");
            scanf("%d", &edad);
         
            gotoxy(10, 9);
            printf("Hola %s, tienes %d anios.\n", nombre, edad);

        }
        break;

        case 58:{
            printf("\033[2J"); // Limpia la pantalla
            printf("%s\n","numero 58");  
           

            setColor("\033[7;32m");
            gotoxy(5, 7);
            printf("Calculadora Basica de gotoxy y switch-case:");
            setColor("\033[0m");
            
            setColor("\033[4;30m");
            gotoxy(5, 8);
            printf("Menu de operaciones:");
            setColor("\033[0m");
        
            setColor("\033[7;31m");
            gotoxy(6, 13);
            printf("1. ");
            setColor("\033[0m");
            gotoxy(7, 13);
            printf("Suma\n");
        
            setColor("\033[7;32m");
            gotoxy(6, 14);
            printf("2. ");
            setColor("\033[0m");
            gotoxy(7, 15);
            printf("Resta\n");
        
        
            setColor("\033[7;33m");
            gotoxy(6, 15);
            printf("3. ");
            setColor("\033[0m");
            gotoxy(7, 16);
            printf("Multiplicacion\n ");
        
            setColor("\033[7;36m");
            gotoxy(6, 17);
            printf("4. ");
            setColor("\033[0m");
            gotoxy(7, 18);
            printf("Division\n ");
        
            gotoxy(5, 19);
            printf("Seleccione una opcion");
            setColor("\033[7;37m");
            gotoxy(28, 19);
            printf("(1-4)");
            setColor("\033[0m");     

        }
        break;

        case 59:{
            printf("%s\n","numero 59");   
            int opc;
            printf("\033[2J"); // Limpia la pantalla
        
            setColor("\033[7;32m");
            gotoxy(5, 7);
            printf("Calculadora Basica de gotoxy y switch-case:");
            setColor("\033[0m");
            
            setColor("\033[4;30m");
            gotoxy(5, 8);
            printf("Menu de operaciones:");
            setColor("\033[0m");
        
            setColor("\033[7;31m");
            gotoxy(6, 13);
            printf("1. ");
            setColor("\033[0m");
            gotoxy(7, 13);
            printf("Suma\n");
        
            setColor("\033[7;32m");
            gotoxy(6, 14);
            printf("2. ");
            setColor("\033[0m");
            gotoxy(7, 15);
            printf("Resta\n");
        
        
            setColor("\033[7;33m");
            gotoxy(6, 15);
            printf("3. ");
            setColor("\033[0m");
            gotoxy(7, 16);
            printf("Multiplicacion\n ");
        
            setColor("\033[7;37m");
            gotoxy(6, 18);
            printf("4. ");
            setColor("\033[0m");
            gotoxy(7, 18);
            printf("Division\n ");
        
            gotoxy(5, 18);
            printf("Seleccione una opcion");
            setColor("\033[7;37m");
            gotoxy(28, 18);
            printf("(1-4)");
            setColor("\033[0m");
        
            scanf("%d", &opc);
        
            printf("\033[2J"); // Limpia la pantalla
            int num1;
            int num2;
            gotoxy(5, 7);
            printf("Ingrese el primer numero\n");
            scanf("%d", &num1);
            gotoxy(5, 10);
            printf("ingrese el segundo numero\n");
            scanf("%d", &num2);
        
            printf("\033[2J"); // Limpia la pantalla
        
            switch(opc){
                case 1:
                    gotoxy(5, 7);
                    printf("Suma");
                    int suma = num1 + num2;
                    gotoxy(5, 8);
                    printf("Resultado");
                    gotoxy(15, 8);
                    setColor("\033[7;31m");
                    printf("%d", suma);
                    setColor("\033[0m");
                break;
        
                case 2:
                    gotoxy(5, 7);
                    printf("Resta");
                    int resta = num1 - num2;
                    gotoxy(5, 8);
                    printf("Resultado");
                    gotoxy(15, 8);
                    setColor("\033[7;32m");
                    printf("%d", resta);
                    setColor("\033[0m");
        
                break;
        
                case 3:
                gotoxy(5, 7);
                printf("multiplicacion");
                int mul = num1 / num2;
                gotoxy(5, 8);
                printf("Resultado");
                gotoxy(15, 8);
                setColor("\033[7;33m");
                printf("%d", mul);
                setColor("\033[0m");
        
                break;
        
                case 4:
                if(num2 >0){
                gotoxy(5, 7);
                printf("Division");
                float div = num1 / num2;
                gotoxy(5, 8);
                printf("Resultado");
                gotoxy(15, 8);
                setColor("\033[7;37m");
                printf("%.2f", div);
                setColor("\033[0m");
                }else{
                    printf("No se puede");
                }
                break;
        
                default:
                gotoxy(5, 7);
                    printf("%s\n","no ha seleccionado una opcion valida");
                break;
            }    

        }
        break;

        case 60:{
            printf("%s\n","numero 60");  
            int asteriscos = 1;
            int fila=11;
            for (int i=6; i>= 0; i --){
                gotoxy(5, fila);
                for(int j = 1; j <= asteriscos; j++ ){
                    setColor("\033[7;32m");
                    printf("%4s","*");
                }
                asteriscos++;
                fila ++;
                setColor("\033[0m");
                printf("\n");
                }
                     

        }
        break;

        case 61:{
            printf("%s\n","numero 61");  
            printf("\033[2J"); // Limpia la pantalla
            int alto = 10;
            int ancho_franja = 10;
            int inicio_y = 5;
            int inicio_x = 5;
        
            for (int fila = 0; fila < alto; fila++) {
                gotoxy(inicio_x, inicio_y + fila);
        
                // Franja verde
                setColor("\033[42m"); // fondo verde
                for (int i = 0; i < ancho_franja; i++) {
                    printf(" ");
                }
        
                // Franja blanca
                setColor("\033[47m"); // fondo blanco
                for (int i = 0; i < ancho_franja; i++) {
                    if (fila == alto / 2 && i == ancho_franja / 2 - 1) {
                        setColor("\033[30;47m"); // texto negro en blanco
                        printf("*");             // "escudo"
                        setColor("\033[47m");    // vuelve al blanco
                    } else {
                        printf(" ");
                    }
                }
        
                // Franja roja
                setColor("\033[41m"); // fondo rojo
                for (int i = 0; i < ancho_franja; i++) {
                    printf(" ");
                }
        
                setColor("\033[0m"); // reset color
                printf("\n");
            }
        
            gotoxy(0, inicio_y + alto + 1);     

        }
        break;

        case 62:{
            printf("%s\n","numero 62");   
            printf("\033[2J"); // Limpia la pantalla
            int inicio_x = 5;
            int inicio_y = 3;
            int ancho_total = 45;
            int ancho_union = 18; // Ancho del cuadro azul
            int alto_union = 7;   // Alto del cuadro azul
        
            for (int fila = 0; fila < 13; fila++) {
                gotoxy(inicio_x, inicio_y + fila);
        
                // Colores alternos de franjas: rojo (par), blanco (impar)
                if (fila % 2 == 0) {
                    setColor("\033[41m"); // fondo rojo
                } else {
                    setColor("\033[47m"); // fondo blanco
                }
        
                // Parte azul para las primeras 7 filas
                if (fila < alto_union) {
                    // Cuadro azul a la izquierda
                    setColor("\033[44m"); // azul
                    for (int i = 0; i < ancho_union; i++) {
                        printf(" ");
                    }
        
                    // El resto de la franja en rojo/blanco
                    if (fila % 2 == 0)
                        setColor("\033[41m");
                    else
                        setColor("\033[47m");
        
                    for (int i = ancho_union; i < ancho_total; i++) {
                        printf(" ");
                    }
        
                } else {
                    // Filas sin cuadro azul
                    for (int i = 0; i < ancho_total; i++) {
                        printf(" ");
                    }
                }
        
                setColor("\033[0m");
                printf("\n");
            }
        
            gotoxy(0, inicio_y + 14);    

        }
        break;

        case 63:{
            printf("%s\n","numero 63");  


        }
        break;
    }
}