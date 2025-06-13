#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// Incluir el encabezado de MySQL C API
#include <mysql.h>

// Definición de estructuras según tu modelo relacional
typedef struct {
    int hospital_id;
    char nombre[50];
    int num_camas;
    char tipo[20];         // "Propio" o "Concertado"
    float presupuesto;     // Solo si es propio
    char servicio[50];     // Solo si es propio
    int area_id;           // Solo si es concertado
} Hospital;

typedef struct {
    int area_id;
    char nombre[50];
    float superficie;
    int num_habitantes;
} Area;

typedef struct {
    int medico_id;
    char nombre[50];
    char telefono[20];
    int jefe_id;
    int area_id;
} Medico;

typedef struct {
    int asegurado_id;
    int poliza_id;
    int num_correlativo;
    char nombre[50];
    char fecha_nac[12];
    char categoria[20];
} Asegurado;

typedef struct {
    int hospitalizacion_id;
    int asegurado_id;
    int hospital_id;
    int medico_id;
    char fecha_inicio[12];
    char fecha_fin[12];
} Hospitalizacion;

// Arrays para almacenar datos (se usarían para el modo sin DB o como caché)
Hospital hospitales[100];
Area areas[100];
Medico medicos[100];
Asegurado asegurados[100];
Hospitalizacion hospitalizaciones[100];

// Contadores (se usarían para el modo sin DB)
int total_hospitales = 0;
int total_areas = 0;
int total_medicos = 0;
int total_asegurados = 0;
int total_hospitalizaciones = 0;

// Global para la conexión a MySQL
MYSQL *conn;

// --- Funciones de utilidad para la consola ---
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void limpiar_pantalla() {
    system("cls");
}

void mostrar_titulo(const char* titulo) {
    gotoxy(25, 2);
    printf("=== %s ===", titulo);
}

// ==================== FUNCIONES DE CONEXIÓN A LA BASE DE DATOS ====================

// Función para conectar a la base de datos MySQL
int conectar_db() {
    conn = mysql_init(NULL); // Inicializa la conexión

    // Conectar a la base de datos
    // Servidor: localhost, Usuario: root, Contraseña: 12345, BD: hospitales_bd, Puerto: 3306
    if (!mysql_real_connect(conn, "localhost", "root", "12345", "hospitales_bd", 3306, NULL, 0)) {
        limpiar_pantalla();
        mostrar_titulo("ERROR DE CONEXION DB");
        gotoxy(5, 4);
        fprintf(stderr, "Error al conectar a la base de datos: %s\n", mysql_error(conn));
        gotoxy(5, 6);
        printf("Asegúrese de que el servidor MySQL está corriendo y la DB 'hospitales_bd' existe.\n");
        gotoxy(5, 8);
        printf("Presione cualquier tecla para continuar...");
        getch();
        return 0; // Falló la conexión
    }
    limpiar_pantalla();
    mostrar_titulo("CONEXION DB");
    gotoxy(5, 4);
    printf("Conexión a la base de datos MySQL exitosa!\n");
    gotoxy(5, 6);
    printf("Presione cualquier tecla para continuar...");
    getch();
    return 1; // Conexión exitosa
}

// Función para desconectar de la base de datos MySQL
void desconectar_db() {
    if (conn) {
        mysql_close(conn);
        limpiar_pantalla();
        mostrar_titulo("DESCONEXION DB");
        gotoxy(5, 4);
        printf("Desconexión de la base de datos MySQL exitosa.\n");
        gotoxy(5, 6);
        printf("Presione cualquier tecla para continuar...");
        getch();
    }
}

// ==================== EJEMPLOS DE CRUD CON MYSQL ====================

// Ejemplo de función para insertar un hospital en la base de datos MySQL
void insertar_hospital_db_ejemplo() {
    limpiar_pantalla();
    mostrar_titulo("CREAR HOSPITAL (EN DB)");

    Hospital nuevo;
    // En un sistema real, el ID podría ser AUTO_INCREMENT en la DB
    gotoxy(5, 4);
    printf("ID del hospital (ej. 101): ");
    scanf("%d", &nuevo.hospital_id);
    getchar();

    gotoxy(5, 6);
    printf("Nombre del hospital: ");
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0;

    gotoxy(5, 8);
    printf("Número de camas: ");
    scanf("%d", &nuevo.num_camas);
    getchar();

    gotoxy(5, 10);
    printf("Tipo de hospital (Propio/Concertado): ");
    fgets(nuevo.tipo, sizeof(nuevo.tipo), stdin);
    nuevo.tipo[strcspn(nuevo.tipo, "\n")] = 0;

    char query[512]; // Suficiente espacio para la consulta

    if (strcmp(nuevo.tipo, "Propio") == 0) {
        gotoxy(5, 12);
        printf("Presupuesto: ");
        scanf("%f", &nuevo.presupuesto);
        getchar();
        gotoxy(5, 14);
        printf("Servicio: ");
        fgets(nuevo.servicio, sizeof(nuevo.servicio), stdin);
        nuevo.servicio[strcspn(nuevo.servicio, "\n")] = 0;
        nuevo.area_id = -1; // No aplica para DB, será NULL o valor por defecto
        
        sprintf(query, "INSERT INTO hospitales (hospital_id, nombre, num_camas, tipo, presupuesto, servicio) VALUES (%d, '%s', %d, '%s', %.2f, '%s')",
                nuevo.hospital_id, nuevo.nombre, nuevo.num_camas, nuevo.tipo, nuevo.presupuesto, nuevo.servicio);
    } else if (strcmp(nuevo.tipo, "Concertado") == 0) {
        gotoxy(5, 12);
        printf("ID del Área asignada: ");
        scanf("%d", &nuevo.area_id);
        getchar();
        nuevo.presupuesto = 0.0; // No aplica
        strcpy(nuevo.servicio, ""); // No aplica

        // Validación: Buscar si el area_id existe en la tabla 'areas'
        // Es importante que la tabla 'areas' ya exista en tu DB.
        char check_area_query[128];
        sprintf(check_area_query, "SELECT area_id FROM areas WHERE area_id = %d", nuevo.area_id);
        if (mysql_query(conn, check_area_query)) {
            gotoxy(5, 16);
            fprintf(stderr, "Error al verificar área: %s\n", mysql_error(conn));
            getch();
            return;
        }
        MYSQL_RES *res_area = mysql_store_result(conn);
        if (mysql_num_rows(res_area) == 0) {
            gotoxy(5, 16);
            printf("Error: El ID de área %d no existe en la base de datos 'areas'.", nuevo.area_id);
            mysql_free_result(res_area);
            getch();
            return;
        }
        mysql_free_result(res_area);

        sprintf(query, "INSERT INTO hospitales (hospital_id, nombre, num_camas, tipo, area_id) VALUES (%d, '%s', %d, '%s', %d)",
                nuevo.hospital_id, nuevo.nombre, nuevo.num_camas, nuevo.tipo, nuevo.area_id);
    } else {
        gotoxy(5, 16);
        printf("Tipo inválido. Operación cancelada.");
        getch();
        return;
    }
    

    if (mysql_query(conn, query)) {
        gotoxy(5, 18);
        fprintf(stderr, "Error al insertar hospital en DB: %s\n", mysql_error(conn));
    } else {
        gotoxy(5, 18);
        printf("Hospital '%s' insertado exitosamente en la base de datos.", nuevo.nombre);
    }
    gotoxy(5, 20);
    printf("Presione cualquier tecla para continuar...");
    getch();
}

// Ejemplo de función para mostrar hospitales desde la base de datos MySQL
void mostrar_hospitales_db_ejemplo() {
    limpiar_pantalla();
    mostrar_titulo("LISTA DE HOSPITALES (Desde MySQL)");

    // Asegúrate de que la conexión esté activa
    if (conn == NULL) {
        gotoxy(5, 4);
        printf("No hay conexión a la base de datos. Por favor, conéctese primero.\n");
        gotoxy(5, 6);
        printf("Presione una tecla para continuar...");
        getch();
        return;
    }

    if (mysql_query(conn, "SELECT hospital_id, nombre, num_camas, tipo, presupuesto, servicio, area_id FROM hospitales")) {
        gotoxy(5, 4);
        fprintf(stderr, "Error al obtener hospitales de DB: %s\n", mysql_error(conn));
        getch();
        return;
    }

    MYSQL_RES *result = mysql_store_result(conn); // Almacena el resultado de la consulta
    if (result == NULL) {
        gotoxy(5, 4);
        fprintf(stderr, "Error al obtener resultado de DB: %s\n", mysql_error(conn));
        getch();
        return;
    }

    int num_fields = mysql_num_fields(result); // No usado, pero útil para iterar campos
    MYSQL_ROW row;

    gotoxy(2, 5);
    printf("ID  NOMBRE                CAMAS  TIPO         PRESUPUESTO  SERVICIO             AREA_ID");
    gotoxy(2, 6);
    printf("-----------------------------------------------------------------------------------------");

    int current_line = 7;
    while ((row = mysql_fetch_row(result))) {
        gotoxy(2, current_line);
        // row[4] (presupuesto) y row[6] (area_id) pueden ser NULL en la BD si no aplican
        // Se manejan con el operador ternario para evitar imprimir "(null)"
        printf("%-3s %-20s %-6s %-12s %-12s %-20s %-8s",
               row[0] ? row[0] : "",  // hospital_id
               row[1] ? row[1] : "",  // nombre
               row[2] ? row[2] : "",  // num_camas
               row[3] ? row[3] : "",  // tipo
               row[4] ? row[4] : "0.00",  // presupuesto (manejar NULL como "0.00")
               row[5] ? row[5] : "",  // servicio (manejar NULL como cadena vacía)
               row[6] ? row[6] : "NULL"   // area_id (manejar NULL como "NULL")
        );
        current_line++;
    }

    mysql_free_result(result); // Libera la memoria del resultado
    gotoxy(2, current_line + 2);
    printf("Presione una tecla para continuar...");
    getch();
}


// ==================== CRUD HOSPITALES (VERSION CON ARRAYS - SIN DB) ====================
// Estas funciones todavía operan con los arrays globales y NO con la BD.
// Deberías modificarlas para usar mysql_query, mysql_store_result, etc. para integrar con la DB.

void crear_hospital() {
    limpiar_pantalla();
    mostrar_titulo("CREAR HOSPITAL (VERSION SIN DB)");

    Hospital nuevo;
    nuevo.hospital_id = total_hospitales + 1;

    gotoxy(5, 4);
    printf("Nombre del hospital: ");
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0;

    gotoxy(5, 6);
    printf("Número de camas: ");
    scanf("%d", &nuevo.num_camas);
    getchar();

    gotoxy(5, 8);
    printf("Tipo de hospital:");
    gotoxy(5, 9);
    printf("1. Propio");
    gotoxy(5, 10);
    printf("2. Concertado");

    gotoxy(5, 11);
    printf("Seleccione una opción: ");
    int tipo_opcion;
    scanf("%d", &tipo_opcion);
    getchar();

    if (tipo_opcion == 1) {
        strcpy(nuevo.tipo, "Propio");

        gotoxy(5, 13);
        printf("Presupuesto: ");
        scanf("%f", &nuevo.presupuesto);
        getchar();

        gotoxy(5, 15);
        printf("Tipo de servicio: ");
        fgets(nuevo.servicio, sizeof(nuevo.servicio), stdin);
        nuevo.servicio[strcspn(nuevo.servicio, "\n")] = 0;

        nuevo.area_id = -1; // No aplica para hospitales propios
    } else if (tipo_opcion == 2) {
        strcpy(nuevo.tipo, "Concertado");

        nuevo.presupuesto = 0;
        strcpy(nuevo.servicio, "");

        gotoxy(5, 13);
        printf("Área asignada (ID): ");
        scanf("%d", &nuevo.area_id);
        getchar();
        
        // Validar si el area_id existe en el array (versión sin DB)
        int area_encontrada = 0;
        for (int i = 0; i < total_areas; i++) {
            if (areas[i].area_id == nuevo.area_id) {
                area_encontrada = 1;
                break;
            }
        }
        if (!area_encontrada) {
            gotoxy(5, 17);
            printf("Error: El ID de área ingresado no existe. Operación cancelada.");
            getch();
            return;
        }

    } else {
        gotoxy(5, 13);
        printf("Tipo inválido. Operación cancelada.");
        getch();
        return;
    }

    if (total_hospitales < 100) {
        hospitales[total_hospitales++] = nuevo;
        gotoxy(5, 17);
        printf("Hospital creado exitosamente!");
    } else {
        gotoxy(5, 17);
        printf("Error: Límite de hospitales alcanzado.");
    }
    getch();
}

void mostrar_hospitales() {
    limpiar_pantalla();
    mostrar_titulo("LISTA DE HOSPITALES (VERSION SIN DB)");

    gotoxy(2, 5);
    printf("ID  NOMBRE                CAMAS  TIPO         PRESUPUESTO  SERVICIO             AREA_ID");
    gotoxy(2, 6);
    printf("-----------------------------------------------------------------------------------------");

    for (int i = 0; i < total_hospitales; i++) {
        gotoxy(2, 7 + i);
        printf("%-3d %-20s %-6d %-12s %-12.2f %-20s %-8d",
            hospitales[i].hospital_id,
            hospitales[i].nombre,
            hospitales[i].num_camas,
            hospitales[i].tipo,
            hospitales[i].presupuesto,
            hospitales[i].servicio,
            hospitales[i].area_id
        );
    }

    gotoxy(2, 9 + total_hospitales);
    printf("Presione una tecla para continuar...");
    getch();
}

void actualizar_hospital() {
    limpiar_pantalla();
    mostrar_titulo("ACTUALIZAR HOSPITAL (VERSION SIN DB)");
    
    int id;
    gotoxy(5, 6);
    printf("Ingrese ID del hospital a actualizar: ");
    scanf("%d", &id);
    
    getchar();
    int encontrado = -1;
    for(int i = 0; i < total_hospitales; i++) {
        if(hospitales[i].hospital_id == id) {
            encontrado = i;
            break;
        }
    }
    
    if(encontrado == -1) {
        gotoxy(5, 8);
        printf("Hospital no encontrado!");
        gotoxy(5, 10);
        printf("Presione cualquier tecla para continuar...");
        getch();
        return;
    }
    
    gotoxy(5, 8);
    printf("Hospital encontrado: %s", hospitales[encontrado].nombre);
    
    gotoxy(5, 10);
    printf("Nuevo nombre (actual: %s): ", hospitales[encontrado].nombre);
    fgets(hospitales[encontrado].nombre, sizeof(hospitales[encontrado].nombre), stdin);
    hospitales[encontrado].nombre[strcspn(hospitales[encontrado].nombre, "\n")] = 0;
    
    gotoxy(5, 12);
    printf("Nuevo número de camas (actual: %d): ", hospitales[encontrado].num_camas);
    scanf("%d", &hospitales[encontrado].num_camas);
    getchar();

    if (strcmp(hospitales[encontrado].tipo, "Propio") == 0) {
        gotoxy(5, 14);
        printf("Nuevo presupuesto (actual: %.2f): ", hospitales[encontrado].presupuesto);
        scanf("%f", &hospitales[encontrado].presupuesto);
        getchar();

        gotoxy(5, 16);
        printf("Nuevo tipo de servicio (actual: %s): ", hospitales[encontrado].servicio);
        fgets(hospitales[encontrado].servicio, sizeof(hospitales[encontrado].servicio), stdin);
        hospitales[encontrado].servicio[strcspn(hospitales[encontrado].servicio, "\n")] = 0;
    } else if (strcmp(hospitales[encontrado].tipo, "Concertado") == 0) {
        gotoxy(5, 14);
        printf("Nueva Área asignada (ID) (actual: %d): ", hospitales[encontrado].area_id);
        scanf("%d", &hospitales[encontrado].area_id);
        getchar();
        
        int area_encontrada = 0;
        for (int i = 0; i < total_areas; i++) {
            if (areas[i].area_id == hospitales[encontrado].area_id) {
                area_encontrada = 1;
                break;
            }
        }
        if (!area_encontrada) {
            gotoxy(5, 18);
            printf("Error: El ID de área ingresado no existe. Operación cancelada.");
            getch();
            return;
        }
    }
    
    gotoxy(5, 18);
    printf("Hospital actualizado exitosamente!");
    gotoxy(5, 20);
    printf("Presione cualquier tecla para continuar...");
    getch();
}

void eliminar_hospital() {
    limpiar_pantalla();
    mostrar_titulo("ELIMINAR HOSPITAL (VERSION SIN DB)");
    
    int id;
    gotoxy(5, 6);
    printf("Ingrese ID del hospital a eliminar: ");
    scanf("%d", &id);
    
    getchar();
    int encontrado = -1;
    for(int i = 0; i < total_hospitales; i++) {
        if(hospitales[i].hospital_id == id) {
            encontrado = i;
            break;
        }
    }
    
    if(encontrado == -1) {
        gotoxy(5, 8);
        printf("Hospital no encontrado!");
        gotoxy(5, 10);
        printf("Presione cualquier tecla para continuar...");
        getch();
        return;
    }
    
    gotoxy(5, 8);
    printf("Hospital a eliminar: %s", hospitales[encontrado].nombre);
    gotoxy(5, 10);
    printf("¿Está seguro? (s/n): ");
    
    char confirmacion;
    scanf(" %c", &confirmacion);
    
    getchar();
    if(confirmacion == 's' || confirmacion == 'S') {
        // CASCADA (sin DB): Eliminar hospitalizaciones asociadas a este hospital
        int i = 0;
        while (i < total_hospitalizaciones) {
            if (hospitalizaciones[i].hospital_id == id) {
                for (int j = i; j < total_hospitalizaciones - 1; j++) {
                    hospitalizaciones[j] = hospitalizaciones[j + 1];
                }
                total_hospitalizaciones--;
            } else {
                i++;
            }
        }

        // Eliminar el hospital
        for(int k = encontrado; k < total_hospitales - 1; k++) {
            hospitales[k] = hospitales[k + 1];
        }
        total_hospitales--;
        
        gotoxy(5, 12);
        printf("Hospital y sus hospitalizaciones asociadas eliminadas exitosamente!");
    } else {
        gotoxy(5, 12);
        printf("Operación cancelada.");
    }
    
    gotoxy(5, 14);
    printf("Presione cualquier tecla para continuar...");
    getch();
}

// ==================== CRUD AREAS (VERSION CON ARRAYS - SIN DB) ====================
void crear_area() {
    limpiar_pantalla();
    mostrar_titulo("CREAR ÁREA (VERSION SIN DB)");

    Area nueva;
    nueva.area_id = total_areas + 1;

    gotoxy(5, 6);
    printf("Nombre del Área: ");
    fgets(nueva.nombre, sizeof(nueva.nombre), stdin);
    nueva.nombre[strcspn(nueva.nombre, "\n")] = 0;

    gotoxy(5, 8);
    printf("Superficie (m²): ");
    scanf("%f", &nueva.superficie);
    getchar();

    gotoxy(5, 10);
    printf("Número de Habitantes: ");
    scanf("%d", &nueva.num_habitantes);
    getchar();

    if (total_areas < 100) {
        areas[total_areas++] = nueva;
        gotoxy(5, 13);
        printf("Área creada exitosamente!");
    } else {
        gotoxy(5, 13);
        printf("Error: Límite de áreas alcanzado.");
    }
    getch();
}

void mostrar_areas() {
    limpiar_pantalla();
    mostrar_titulo("LISTA DE ÁREAS (VERSION SIN DB)");

    gotoxy(2, 5);
    printf("ID  NOMBRE                SUPERFICIE (m²)  HABITANTES");
    gotoxy(2, 6);
    printf("-------------------------------------------------------");

    for (int i = 0; i < total_areas; i++) {
        gotoxy(2, 7 + i);
        printf("%-3d %-20s %-16.2f %-10d",
            areas[i].area_id,
            areas[i].nombre,
            areas[i].superficie,
            areas[i].num_habitantes
        );
    }

    gotoxy(2, 9 + total_areas);
    printf("Presione una tecla para continuar...");
    getch();
}

void actualizar_area() {
    limpiar_pantalla();
    mostrar_titulo("ACTUALIZAR ÁREA (VERSION SIN DB)");

    int id;
    gotoxy(5, 6);
    printf("Ingrese ID del área a actualizar: ");
    scanf("%d", &id);
    getchar();

    int encontrado = -1;
    for (int i = 0; i < total_areas; i++) {
        if (areas[i].area_id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        gotoxy(5, 8);
        printf("Área no encontrada!");
        getch();
        return;
    }

    gotoxy(5, 8);
    printf("Área encontrada: %s", areas[encontrado].nombre);

    gotoxy(5, 10);
    printf("Nuevo nombre (actual: %s): ", areas[encontrado].nombre);
    fgets(areas[encontrado].nombre, sizeof(areas[encontrado].nombre), stdin);
    areas[encontrado].nombre[strcspn(areas[encontrado].nombre, "\n")] = 0;

    gotoxy(5, 12);
    printf("Nueva superficie (actual: %.2f): ", areas[encontrado].superficie);
    scanf("%f", &areas[encontrado].superficie);
    getchar();

    gotoxy(5, 14);
    printf("Nuevo número de habitantes (actual: %d): ", areas[encontrado].num_habitantes);
    scanf("%d", &areas[encontrado].num_habitantes);
    getchar();

    gotoxy(5, 16);
    printf("Área actualizada exitosamente!");
    getch();
}

void eliminar_area() {
    limpiar_pantalla();
    mostrar_titulo("ELIMINAR ÁREA (VERSION SIN DB)");

    int id;
    gotoxy(5, 6);
    printf("Ingrese ID del área a eliminar: ");
    scanf("%d", &id);
    getchar();

    int encontrado = -1;
    for (int i = 0; i < total_areas; i++) {
        if (areas[i].area_id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        gotoxy(5, 8);
        printf("Área no encontrada!");
        getch();
        return;
    }

    gotoxy(5, 8);
    printf("¿Está seguro de eliminar el área %s? (s/n): ", areas[encontrado].nombre);
    char confirm;
    scanf(" %c", &confirm);
    getchar();

    if (confirm == 's' || confirm == 'S') {
        // CASCADA (sin DB): Desvincular hospitales concertados de esta área
        for (int i = 0; i < total_hospitales; i++) {
            if (strcmp(hospitales[i].tipo, "Concertado") == 0 && hospitales[i].area_id == id) {
                hospitales[i].area_id = -1;
            }
        }
        // CASCADA (sin DB): Desvincular médicos de esta área
        for (int i = 0; i < total_medicos; i++) {
            if (medicos[i].area_id == id) {
                medicos[i].area_id = -1;
            }
        }
        // Eliminar el área
        for (int i = encontrado; i < total_areas - 1; i++) {
            areas[i] = areas[i + 1];
        }
        total_areas--;
        gotoxy(5, 10);
        printf("Área eliminada exitosamente! Hospitales y Médicos desvinculados.");
    } else {
        gotoxy(5, 10);
        printf("Operación cancelada.");
    }
    getch();
}


// ==================== CRUD MEDICOS (VERSION CON ARRAYS - SIN DB) ====================
void crear_medico() {
    limpiar_pantalla();
    mostrar_titulo("CREAR MEDICO (VERSION SIN DB)");
    
    Medico nuevo;
    nuevo.medico_id = total_medicos + 1;
    
    gotoxy(5, 6);
    printf("Nombre del Médico: ");
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0;
    
    gotoxy(5, 8);
    printf("Teléfono: ");
    fgets(nuevo.telefono, sizeof(nuevo.telefono), stdin);
    nuevo.telefono[strcspn(nuevo.telefono, "\n")] = 0;
    
    gotoxy(5, 10);
    printf("ID del Jefe (0 si no tiene): ");
    scanf("%d", &nuevo.jefe_id);
    
    getchar();
    gotoxy(5, 12);
    printf("ID del Área de adscripción: ");
    scanf("%d", &nuevo.area_id);
    getchar();

    int area_encontrada = 0;
    for (int i = 0; i < total_areas; i++) {
        if (areas[i].area_id == nuevo.area_id) {
            area_encontrada = 1;
            break;
        }
    }
    if (!area_encontrada) {
        gotoxy(5, 15);
        printf("Error: El ID de área ingresado no existe. Operación cancelada.");
        getch();
        return;
    }
    
    if (total_medicos < 100) {
        medicos[total_medicos++] = nuevo;
        gotoxy(5, 15);
        printf("Médico creado exitosamente!");
    } else {
        gotoxy(5, 15);
        printf("Error: Límite de médicos alcanzado.");
    }
    gotoxy(5, 17);
    printf("Presione cualquier tecla para continuar...");
    getch();
}

void mostrar_medicos() {
    limpiar_pantalla();
    mostrar_titulo("LISTA DE MEDICOS (VERSION SIN DB)");
    
    gotoxy(2, 6);
    printf("ID  NOMBRE                TELEFONO          JEFE_ID  AREA_ID");
    gotoxy(2, 7);
    printf("--------------------------------------------------------------");
    
    for(int i = 0; i < total_medicos; i++) {
        gotoxy(2, 8 + i);
        printf("%-3d %-20s %-18s %-8d %-8d", 
            medicos[i].medico_id,
            medicos[i].nombre,
            medicos[i].telefono,
            medicos[i].jefe_id,
            medicos[i].area_id
        );
    }
    
    gotoxy(5, 10 + total_medicos);
    printf("Presione cualquier tecla para continuar...");
    getch();
}

void actualizar_medico() {
    limpiar_pantalla();
    mostrar_titulo("ACTUALIZAR MEDICO (VERSION SIN DB)");

    int id;
    gotoxy(5, 6);
    printf("Ingrese ID del médico a actualizar: ");
    scanf("%d", &id);
    getchar();

    int encontrado = -1;
    for (int i = 0; i < total_medicos; i++) {
        if (medicos[i].medico_id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        gotoxy(5, 8);
        printf("Médico no encontrado!");
        getch();
        return;
    }

    gotoxy(5, 8);
    printf("Nuevo nombre (actual: %s): ", medicos[encontrado].nombre);
    fgets(medicos[encontrado].nombre, sizeof(medicos[encontrado].nombre), stdin);
    medicos[encontrado].nombre[strcspn(medicos[encontrado].nombre, "\n")] = 0;

    gotoxy(5, 10);
    printf("Nuevo teléfono (actual: %s): ", medicos[encontrado].telefono);
    fgets(medicos[encontrado].telefono, sizeof(medicos[encontrado].telefono), stdin);
    medicos[encontrado].telefono[strcspn(medicos[encontrado].telefono, "\n")] = 0;

    gotoxy(5, 12);
    printf("Nuevo ID del jefe (actual: %d): ", medicos[encontrado].jefe_id);
    scanf("%d", &medicos[encontrado].jefe_id);
    getchar();

    gotoxy(5, 14);
    printf("Nuevo ID de área (actual: %d): ", medicos[encontrado].area_id);
    scanf("%d", &medicos[encontrado].area_id);
    getchar();
    
    int area_encontrada = 0;
    for (int i = 0; i < total_areas; i++) {
        if (areas[i].area_id == medicos[encontrado].area_id) {
            area_encontrada = 1;
            break;
        }
    }
    if (!area_encontrada) {
        gotoxy(5, 16);
        printf("Error: El ID de área ingresado no existe. Operación cancelada.");
        getch();
        return;
    }

    gotoxy(5, 16);
    printf("Médico actualizado exitosamente!");
    getch();
}

void eliminar_medico() {
    limpiar_pantalla();
    mostrar_titulo("ELIMINAR MEDICO (VERSION SIN DB)");

    int id;
    gotoxy(5, 6);
    printf("Ingrese ID del médico a eliminar: ");
    scanf("%d", &id);
    getchar();

    int encontrado = -1;
    for (int i = 0; i < total_medicos; i++) {
        if (medicos[i].medico_id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        gotoxy(5, 8);
        printf("Médico no encontrado!");
        getch();
        return;
    }

    gotoxy(5, 8);
    printf("¿Está seguro? (s/n): ");
    char confirm;
    scanf(" %c", &confirm);
    getchar();

    if (confirm == 's' || confirm == 'S') {
        // Validación (sin DB): No permitir eliminar si es jefe de otro médico
        for (int i = 0; i < total_medicos; i++) {
            if (medicos[i].jefe_id == id) {
                gotoxy(5, 10);
                printf("Error: No se puede eliminar el médico. Es jefe de otro médico.");
                getch();
                return;
            }
        }
        
        // CASCADA (sin DB): Desvincular hospitalizaciones asociadas a este médico
        int i = 0;
        while (i < total_hospitalizaciones) {
            if (hospitalizaciones[i].medico_id == id) {
                hospitalizaciones[i].medico_id = -1; // Desvincular la hospitalización del médico
            }
            i++;
        }

        // Eliminar el médico
        for (int k = encontrado; k < total_medicos - 1; k++) {
            medicos[k] = medicos[k + 1];
        }
        total_medicos--;
        gotoxy(5, 10);
        printf("Médico eliminado exitosamente! Hospitalizaciones desvinculadas.");
    } else {
        gotoxy(5, 10);
        printf("Operación cancelada.");
    }
    getch();
}


// ==================== CRUD ASEGURADOS (VERSION CON ARRAYS - SIN DB) ====================
void crear_asegurado() {
    limpiar_pantalla();
    mostrar_titulo("CREAR ASEGURADO (VERSION SIN DB)");
    
    Asegurado nuevo;
    nuevo.asegurado_id = total_asegurados + 1;
    
    gotoxy(5, 6);
    printf("Número de Póliza: ");
    scanf("%d", &nuevo.poliza_id);
    
    getchar();
    gotoxy(5, 8);
    printf("Número Correlativo: ");
    scanf("%d", &nuevo.num_correlativo);
    
    getchar();
    gotoxy(5, 10);
    printf("Nombre del Asegurado: ");
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0;
    
    gotoxy(5, 12);
    printf("Fecha de Nacimiento (dd/mm/yyyy): ");
    fgets(nuevo.fecha_nac, sizeof(nuevo.fecha_nac), stdin);
    nuevo.fecha_nac[strcspn(nuevo.fecha_nac, "\n")] = 0;
    
    gotoxy(5, 14);
    printf("Categoría (A1C, A2C, A3C, etc.): ");
    fgets(nuevo.categoria, sizeof(nuevo.categoria), stdin);
    nuevo.categoria[strcspn(nuevo.categoria, "\n")] = 0;
    
    if (total_asegurados < 100) {
        asegurados[total_asegurados++] = nuevo;
        gotoxy(5, 17);
        printf("Asegurado creado exitosamente!");
    } else {
        gotoxy(5, 17);
        printf("Error: Límite de asegurados alcanzado.");
    }
    gotoxy(5, 19);
    printf("Presione cualquier tecla para continuar...");
    getch();
}

void mostrar_asegurados() {
    limpiar_pantalla();
    mostrar_titulo("LISTA DE ASEGURADOS (VERSION SIN DB)");
    
    gotoxy(2, 6);
    printf("ID  POLIZA  CORRELATIVO  NOMBRE                FECHA_NAC    CATEGORIA");
    gotoxy(2, 7);
    printf("--------------------------------------------------------------------------");
    
    for(int i = 0; i < total_asegurados; i++) {
        gotoxy(2, 8 + i);
        printf("%-3d %-7d %-11d %-20s %-12s %-9s", 
            asegurados[i].asegurado_id,
            asegurados[i].poliza_id,
            asegurados[i].num_correlativo,
            asegurados[i].nombre,
            asegurados[i].fecha_nac,
            asegurados[i].categoria
        );
    }
    
    gotoxy(5, 10 + total_asegurados);
    printf("Presione cualquier tecla para continuar...");
    getch();
}

void actualizar_asegurado() {
    limpiar_pantalla();
    mostrar_titulo("ACTUALIZAR ASEGURADO (VERSION SIN DB)");

    int id;
    gotoxy(5, 6);
    printf("Ingrese ID del asegurado a actualizar: ");
    scanf("%d", &id);
    getchar();

    int encontrado = -1;
    for (int i = 0; i < total_asegurados; i++) {
        if (asegurados[i].asegurado_id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        gotoxy(5, 8);
        printf("Asegurado no encontrado!");
        getch();
        return;
    }

    gotoxy(5, 8);
    printf("Nuevo número de póliza (actual: %d): ", asegurados[encontrado].poliza_id);
    scanf("%d", &asegurados[encontrado].poliza_id);
    getchar();

    gotoxy(5, 10);
    printf("Nuevo número correlativo (actual: %d): ", asegurados[encontrado].num_correlativo);
    scanf("%d", &asegurados[encontrado].num_correlativo);
    getchar();

    gotoxy(5, 12);
    printf("Nuevo nombre (actual: %s): ", asegurados[encontrado].nombre);
    fgets(asegurados[encontrado].nombre, sizeof(asegurados[encontrado].nombre), stdin);
    asegurados[encontrado].nombre[strcspn(asegurados[encontrado].nombre, "\n")] = 0;

    gotoxy(5, 14);
    printf("Nueva fecha de nacimiento (actual: %s): ", asegurados[encontrado].fecha_nac);
    fgets(asegurados[encontrado].fecha_nac, sizeof(asegurados[encontrado].fecha_nac), stdin);
    asegurados[encontrado].fecha_nac[strcspn(asegurados[encontrado].fecha_nac, "\n")] = 0;

    gotoxy(5, 16);
    printf("Nueva categoría (actual: %s): ", asegurados[encontrado].categoria);
    fgets(asegurados[encontrado].categoria, sizeof(asegurados[encontrado].categoria), stdin);
    asegurados[encontrado].categoria[strcspn(asegurados[encontrado].categoria, "\n")] = 0;

    gotoxy(5, 18);
    printf("Asegurado actualizado exitosamente!");
    getch();
}

void eliminar_asegurado() {
    limpiar_pantalla();
    mostrar_titulo("ELIMINAR ASEGURADO (VERSION SIN DB)");

    int id;
    gotoxy(5, 6);
    printf("Ingrese ID del asegurado a eliminar: ");
    scanf("%d", &id);
    getchar();

    int encontrado = -1;
    for (int i = 0; i < total_asegurados; i++) {
        if (asegurados[i].asegurado_id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        gotoxy(5, 8);
        printf("Asegurado no encontrado!");
        getch();
        return;
    }

    gotoxy(5, 8);
    printf("¿Está seguro? (s/n): ");
    char confirm;
    scanf(" %c", &confirm);
    getchar();

    if (confirm == 's' || confirm == 'S') {
        // CASCADA (sin DB): Eliminar hospitalizaciones asociadas a este asegurado
        int i = 0;
        while (i < total_hospitalizaciones) {
            if (hospitalizaciones[i].asegurado_id == id) {
                for (int j = i; j < total_hospitalizaciones - 1; j++) {
                    hospitalizaciones[j] = hospitalizaciones[j + 1];
                }
                total_hospitalizaciones--;
            } else {
                i++;
            }
        }
        // Eliminar el asegurado
        for (int k = encontrado; k < total_asegurados - 1; k++) {
            asegurados[k] = asegurados[k + 1];
        }
        total_asegurados--;
        gotoxy(5, 10);
        printf("Asegurado y sus hospitalizaciones asociadas eliminadas exitosamente!");
    } else {
        gotoxy(5, 10);
        printf("Operación cancelada.");
    }
    getch();
}
// ==================== CRUD HOSPITALIZACIONES (VERSION CON ARRAYS - SIN DB) ====================
void crear_hospitalizacion() {
    limpiar_pantalla();
    mostrar_titulo("CREAR HOSPITALIZACION (VERSION SIN DB)");
    
    Hospitalizacion nueva;
    nueva.hospitalizacion_id = total_hospitalizaciones + 1;
    
    gotoxy(5, 6);
    printf("ID del Asegurado: ");
    scanf("%d", &nueva.asegurado_id);
    getchar();

    int asegurado_existe = 0;
    char categoria_asegurado[20];
    for(int i = 0; i < total_asegurados; i++) {
        if(asegurados[i].asegurado_id == nueva.asegurado_id) {
            asegurado_existe = 1;
            strcpy(categoria_asegurado, asegurados[i].categoria);
            break;
        }
    }
    if (!asegurado_existe) {
        gotoxy(5, 17);
        printf("Error: El ID de asegurado no existe. Operación cancelada.");
        getch();
        return;
    }
    if (strcmp(categoria_asegurado, "A1C") != 0 && strcmp(categoria_asegurado, "A2C") != 0) {
        gotoxy(5, 17);
        printf("Error: Asegurado de categoría '%s' no tiene derecho a hospitalización. Operación cancelada.", categoria_asegurado);
        getch();
        return;
    }
    
    gotoxy(5, 8);
    printf("ID del Hospital: ");
    scanf("%d", &nueva.hospital_id);
    getchar();

    int hospital_existe = 0;
    char tipo_hospital[20];
    for(int i = 0; i < total_hospitales; i++) {
        if(hospitales[i].hospital_id == nueva.hospital_id) {
            hospital_existe = 1;
            strcpy(tipo_hospital, hospitales[i].tipo);
            break;
        }
    }
    if (!hospital_existe) {
        gotoxy(5, 17);
        printf("Error: El ID de hospital no existe. Operación cancelada.");
        getch();
        return;
    }
    if (strcmp(categoria_asegurado, "A2C") == 0 && strcmp(tipo_hospital, "Propio") != 0) {
        gotoxy(5, 17);
        printf("Error: Asegurados de categoría A2C solo pueden ser hospitalizados en hospitales Propios. Operación cancelada.");
        getch();
        return;
    }

    gotoxy(5, 10);
    printf("ID del Médico: ");
    scanf("%d", &nueva.medico_id);
    getchar();

    int medico_existe = 0;
    for(int i = 0; i < total_medicos; i++) {
        if(medicos[i].medico_id == nueva.medico_id) {
            medico_existe = 1;
            break;
        }
    }
    if (!medico_existe) {
        gotoxy(5, 17);
        printf("Error: El ID de médico no existe. Operación cancelada.");
        getch();
        return;
    }
    
    gotoxy(5, 12);
    printf("Fecha de Inicio (dd/mm/yyyy): ");
    fgets(nueva.fecha_inicio, sizeof(nueva.fecha_inicio), stdin);
    nueva.fecha_inicio[strcspn(nueva.fecha_inicio, "\n")] = 0;
    
    gotoxy(5, 14);
    printf("Fecha de Fin (dd/mm/yyyy): ");
    fgets(nueva.fecha_fin, sizeof(nueva.fecha_fin), stdin);
    nueva.fecha_fin[strcspn(nueva.fecha_fin, "\n")] = 0;
    
    if (total_hospitalizaciones < 100) {
        hospitalizaciones[total_hospitalizaciones++] = nueva;
        gotoxy(5, 17);
        printf("Hospitalización creada exitosamente!");
    } else {
        gotoxy(5, 17);
        printf("Error: Límite de hospitalizaciones alcanzado.");
    }
    gotoxy(5, 19);
    printf("Presione cualquier tecla para continuar...");
    getch();
}

void mostrar_hospitalizaciones() {
    limpiar_pantalla();
    mostrar_titulo("LISTA DE HOSPITALIZACIONES (VERSION SIN DB)");
    
    gotoxy(2, 6);
    printf("ID  ASEGURADO_ID  HOSPITAL_ID  MEDICO_ID  FECHA_INICIO  FECHA_FIN");
    gotoxy(2, 7);
    printf("------------------------------------------------------------------");
    
    for(int i = 0; i < total_hospitalizaciones; i++) {
        gotoxy(2, 8 + i);
        printf("%-3d %-13d %-12d %-10d %-13s %-11s", 
            hospitalizaciones[i].hospitalizacion_id,
            hospitalizaciones[i].asegurado_id,
            hospitalizaciones[i].hospital_id,
            hospitalizaciones[i].medico_id,
            hospitalizaciones[i].fecha_inicio,
            hospitalizaciones[i].fecha_fin
        );
    }
    
    gotoxy(5, 10 + total_hospitalizaciones);
    printf("Presione cualquier tecla para continuar...");
    getch();
}

void actualizar_hospitalizacion() {
    limpiar_pantalla();
    mostrar_titulo("ACTUALIZAR HOSPITALIZACION (VERSION SIN DB)");

    int id;
    gotoxy(5, 6);
    printf("Ingrese ID de la hospitalización a actualizar: ");
    scanf("%d", &id);
    getchar();

    int encontrado = -1;
    for (int i = 0; i < total_hospitalizaciones; i++) {
        if (hospitalizaciones[i].hospitalizacion_id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        gotoxy(5, 8);
        printf("Hospitalización no encontrada!");
        getch();
        return;
    }

    int old_asegurado_id = hospitalizaciones[encontrado].asegurado_id;
    int old_hospital_id = hospitalizaciones[encontrado].hospital_id;
    int old_medico_id = hospitalizaciones[encontrado].medico_id;


    gotoxy(5, 8);
    printf("Nuevo ID del asegurado (actual: %d): ", hospitalizaciones[encontrado].asegurado_id);
    scanf("%d", &hospitalizaciones[encontrado].asegurado_id);
    getchar();

    int asegurado_existe = 0;
    char categoria_asegurado[20];
    for(int i = 0; i < total_asegurados; i++) {
        if(asegurados[i].asegurado_id == hospitalizaciones[encontrado].asegurado_id) {
            asegurado_existe = 1;
            strcpy(categoria_asegurado, asegurados[i].categoria);
            break;
        }
    }
    if (!asegurado_existe) {
        gotoxy(5, 20);
        printf("Error: El nuevo ID de asegurado no existe. Operación cancelada.");
        hospitalizaciones[encontrado].asegurado_id = old_asegurado_id;
        getch();
        return;
    }
    if (strcmp(categoria_asegurado, "A1C") != 0 && strcmp(categoria_asegurado, "A2C") != 0) {
        gotoxy(5, 20);
        printf("Error: Nueva categoría de asegurado '%s' no tiene derecho a hospitalización. Operación cancelada.", categoria_asegurado);
        hospitalizaciones[encontrado].asegurado_id = old_asegurado_id;
        getch();
        return;
    }


    gotoxy(5, 10);
    printf("Nuevo ID del hospital (actual: %d): ", hospitalizaciones[encontrado].hospital_id);
    scanf("%d", &hospitalizaciones[encontrado].hospital_id);
    getchar();

    int hospital_existe = 0;
    char tipo_hospital[20];
    for(int i = 0; i < total_hospitales; i++) {
        if(hospitales[i].hospital_id == hospitalizaciones[encontrado].hospital_id) {
            hospital_existe = 1;
            strcpy(tipo_hospital, hospitales[i].tipo);
            break;
        }
    }
    if (!hospital_existe) {
        gotoxy(5, 20);
        printf("Error: El nuevo ID de hospital no existe. Operación cancelada.");
        hospitalizaciones[encontrado].hospital_id = old_hospital_id;
        getch();
        return;
    }
    if (strcmp(categoria_asegurado, "A2C") == 0 && strcmp(tipo_hospital, "Propio") != 0) {
        gotoxy(5, 20);
        printf("Error: Asegurados de categoría A2C solo pueden ser hospitalizados en hospitales Propios. Operación cancelada.");
        hospitalizaciones[encontrado].hospital_id = old_hospital_id;
        getch();
        return;
    }

    gotoxy(5, 12);
    printf("Nuevo ID del médico (actual: %d): ", hospitalizaciones[encontrado].medico_id);
    scanf("%d", &hospitalizaciones[encontrado].medico_id);
    getchar();

    int medico_existe = 0;
    for(int i = 0; i < total_medicos; i++) {
        if(medicos[i].medico_id == hospitalizaciones[encontrado].medico_id) {
            medico_existe = 1;
            break;
        }
    }
    if (!medico_existe) {
        gotoxy(5, 20);
        printf("Error: El nuevo ID de médico no existe. Operación cancelada.");
        hospitalizaciones[encontrado].medico_id = old_medico_id;
        getch();
        return;
    }

    gotoxy(5, 14);
    printf("Nueva fecha de inicio (actual: %s): ", hospitalizaciones[encontrado].fecha_inicio);
    fgets(hospitalizaciones[encontrado].fecha_inicio, sizeof(hospitalizaciones[encontrado].fecha_inicio), stdin);
    hospitalizaciones[encontrado].fecha_inicio[strcspn(hospitalizaciones[encontrado].fecha_inicio, "\n")] = 0;

    gotoxy(5, 16);
    printf("Nueva fecha de fin (actual: %s): ", hospitalizaciones[encontrado].fecha_fin);
    fgets(hospitalizaciones[encontrado].fecha_fin, sizeof(hospitalizaciones[encontrado].fecha_fin), stdin);
    hospitalizaciones[encontrado].fecha_fin[strcspn(hospitalizaciones[encontrado].fecha_fin, "\n")] = 0;

    gotoxy(5, 18);
    printf("Hospitalización actualizada exitosamente!");
    getch();
}

void eliminar_hospitalizacion() {
    limpiar_pantalla();
    mostrar_titulo("ELIMINAR HOSPITALIZACION (VERSION SIN DB)");

    int id;
    gotoxy(5, 6);
    printf("Ingrese ID de la hospitalización a eliminar: ");
    scanf("%d", &id);
    getchar();

    int encontrado = -1;
    for (int i = 0; i < total_hospitalizaciones; i++) {
        if (hospitalizaciones[i].hospitalizacion_id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        gotoxy(5, 8);
        printf("Hospitalización no encontrada!");
        getch();
        return;
    }

    gotoxy(5, 8);
    printf("¿Está seguro? (s/n): ");
    char confirm;
    scanf(" %c", &confirm);
    getchar();

    if (confirm == 's' || confirm == 'S') {
        for (int i = encontrado; i < total_hospitalizaciones - 1; i++) {
            hospitalizaciones[i] = hospitalizaciones[i + 1];
        }
        total_hospitalizaciones--;
        gotoxy(5, 10);
        printf("Hospitalización eliminada exitosamente!");
    } else {
        gotoxy(5, 10);
        printf("Operación cancelada.");
    }
    getch();
}


// ==================== REPORTES RELACIONALES (VERSION CON ARRAYS - SIN DB) ====================
void mostrar_reporte_relacional() {
    limpiar_pantalla();
    mostrar_titulo("REPORTE RELACIONAL - HOSPITALIZACIONES COMPLETAS (VERSION SIN DB)");
    
    gotoxy(2, 6);
    printf("PACIENTE                HOSPITAL              MEDICO                FECHA_INICIO  FECHA_FIN");
    gotoxy(2, 7);
    printf("----------------------------------------------------------------------------------------------");
    
    int linea = 8;
    for(int i = 0; i < total_hospitalizaciones; i++) {
        char nombre_asegurado[50] = "No encontrado";
        for(int j = 0; j < total_asegurados; j++) {
            if(asegurados[j].asegurado_id == hospitalizaciones[i].asegurado_id) {
                strcpy(nombre_asegurado, asegurados[j].nombre);
                break;
            }
        }
        
        char nombre_hospital[50] = "No encontrado";
        for(int j = 0; j < total_hospitales; j++) {
            if(hospitales[j].hospital_id == hospitalizaciones[i].hospital_id) {
                strcpy(nombre_hospital, hospitales[j].nombre);
                break;
            }
        }
        
        char nombre_medico[50] = "No encontrado";
        for(int j = 0; j < total_medicos; j++) {
            if(medicos[j].medico_id == hospitalizaciones[i].medico_id) {
                strcpy(nombre_medico, medicos[j].nombre);
                break;
            }
        }
        
        gotoxy(2, linea);
        printf("%-20s", nombre_asegurado);
        gotoxy(24, linea);
        printf("%-20s", nombre_hospital);
        gotoxy(46, linea);
        printf("%-20s", nombre_medico);
        gotoxy(68, linea);
        printf("%-13s", hospitalizaciones[i].fecha_inicio);
        gotoxy(82, linea);
        printf("%s", hospitalizaciones[i].fecha_fin);
        
        linea++;
    }
    
    gotoxy(5, linea + 2);
    printf("Presione cualquier tecla para continuar...");
    getch();
}

// Función para cargar datos de ejemplo en los ARRAYS (NO EN LA DB)
void cargar_datos_ejemplo() {
    total_hospitales = 0;
    total_areas = 0;
    total_medicos = 0;
    total_asegurados = 0;
    total_hospitalizaciones = 0;

    hospitales[0].hospital_id = 1;
    strcpy(hospitales[0].nombre, "Hospital General");
    hospitales[0].num_camas = 200;
    strcpy(hospitales[0].tipo, "Propio");
    hospitales[0].presupuesto = 5000000.0;
    strcpy(hospitales[0].servicio, "Urgencias, Cirugia");
    hospitales[0].area_id = -1;

    hospitales[1].hospital_id = 2;
    strcpy(hospitales[1].nombre, "Hospital San Juan");
    hospitales[1].num_camas = 150;
    strcpy(hospitales[1].tipo, "Concertado");
    hospitales[1].presupuesto = 0.0;
    strcpy(hospitales[1].servicio, "");
    hospitales[1].area_id = 1;

    hospitales[2].hospital_id = 3;
    strcpy(hospitales[2].nombre, "Clínica de la Paz");
    hospitales[2].num_camas = 80;
    strcpy(hospitales[2].tipo, "Propio");
    hospitales[2].presupuesto = 2500000.0;
    strcpy(hospitales[2].servicio, "Pediatria, Ginecologia");
    hospitales[2].area_id = -1;

    total_hospitales = 3;

    areas[0].area_id = 1;
    strcpy(areas[0].nombre, "Centro");
    areas[0].superficie = 1500.5;
    areas[0].num_habitantes = 50000;

    areas[1].area_id = 2;
    strcpy(areas[1].nombre, "Norte");
    areas[1].superficie = 2000.0;
    areas[1].num_habitantes = 75000;

    total_areas = 2;

    medicos[0].medico_id = 1;
    strcpy(medicos[0].nombre, "Dr. Juan Pérez");
    strcpy(medicos[0].telefono, "123-456-7890");
    medicos[0].jefe_id = 0;
    medicos[0].area_id = 1;

    medicos[1].medico_id = 2;
    strcpy(medicos[1].nombre, "Dra. María García");
    strcpy(medicos[1].telefono, "098-765-4321");
    medicos[1].jefe_id = 1;
    medicos[1].area_id = 2;
    total_medicos = 2;

    asegurados[0].asegurado_id = 1;
    asegurados[0].poliza_id = 1001;
    asegurados[0].num_correlativo = 1;
    strcpy(asegurados[0].nombre, "Carlos López");
    strcpy(asegurados[0].fecha_nac, "15/03/1985");
    strcpy(asegurados[0].categoria, "A1C");

    asegurados[1].asegurado_id = 2;
    asegurados[1].poliza_id = 1002;
    asegurados[1].num_correlativo = 2;
    strcpy(asegurados[1].nombre, "Ana Martínez");
    strcpy(asegurados[1].fecha_nac, "22/07/1990");
    strcpy(asegurados[1].categoria, "A2C");
    
    asegurados[2].asegurado_id = 3;
    asegurados[2].poliza_id = 1003;
    asegurados[2].num_correlativo = 3;
    strcpy(asegurados[2].nombre, "Pedro Ramirez");
    strcpy(asegurados[2].fecha_nac, "10/11/1995");
    strcpy(asegurados[2].categoria, "A3C");

    total_asegurados = 3;

    hospitalizaciones[0].hospitalizacion_id = 1;
    hospitalizaciones[0].asegurado_id = 1;
    hospitalizaciones[0].hospital_id = 1;
    hospitalizaciones[0].medico_id = 1;
    strcpy(hospitalizaciones[0].fecha_inicio, "01/01/2025");
    strcpy(hospitalizaciones[0].fecha_fin, "05/01/2025");
    
    hospitalizaciones[1].hospitalizacion_id = 2;
    hospitalizaciones[1].asegurado_id = 2;
    hospitalizaciones[1].hospital_id = 1;
    hospitalizaciones[1].medico_id = 2;
    strcpy(hospitalizaciones[1].fecha_inicio, "10/02/2025");
    strcpy(hospitalizaciones[1].fecha_fin, "12/02/2025");
    total_hospitalizaciones = 2;
}

// ==================== MENUS ====================
void menu_hospitales() {
    int opcion;
    do {
        limpiar_pantalla();
        mostrar_titulo("GESTION DE HOSPITALES (VERSION SIN DB)"); // Nota importante para el usuario
        
        gotoxy(10, 8);
        printf("1. Crear Hospital (VERSION SIN DB)");
        gotoxy(10, 10);
        printf("2. Mostrar Hospitales (VERSION SIN DB)");
        gotoxy(10, 12);
        printf("3. Actualizar Hospital (VERSION SIN DB)");
        gotoxy(10, 14);
        printf("4. Eliminar Hospital (VERSION SIN DB)");
        gotoxy(10, 16);
        printf("5. Volver al Menú Principal");
        
        gotoxy(10, 18);
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        getchar();
        switch(opcion) {
            case 1: crear_hospital(); break;
            case 2: mostrar_hospitales(); break;
            case 3: actualizar_hospital(); break;
            case 4: eliminar_hospital(); break;
            case 5: break;
            default:
                gotoxy(10, 20);
                printf("Opción inválida!");
                getch();
        }
    } while(opcion != 5);
}

void menu_areas() {
    int opcion;
    do {
        limpiar_pantalla();
        mostrar_titulo("GESTIÓN DE ÁREAS (VERSION SIN DB)"); // Nota importante para el usuario

        gotoxy(10, 8);  printf("1. Crear Área (VERSION SIN DB)");
        gotoxy(10, 10); printf("2. Mostrar Áreas (VERSION SIN DB)");
        gotoxy(10, 12); printf("3. Actualizar Área (VERSION SIN DB)");
        gotoxy(10, 14); printf("4. Eliminar Área (VERSION SIN DB)");
        gotoxy(10, 16); printf("5. Volver al Menú Principal");

        gotoxy(10, 18); printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1: crear_area(); break;
            case 2: mostrar_areas(); break;
            case 3: actualizar_area(); break;
            case 4: eliminar_area(); break;
            case 5: break;
            default:
                gotoxy(10, 20);
                printf("Opción inválida!");
                getch();
        }
    } while(opcion != 5);
}


void menu_medicos() {
    int opcion;
    do {
        limpiar_pantalla();
        mostrar_titulo("GESTION DE MEDICOS (VERSION SIN DB)"); // Nota importante para el usuario

        gotoxy(10, 8);  printf("1. Crear Médico (VERSION SIN DB)");
        gotoxy(10, 10); printf("2. Mostrar Médicos (VERSION SIN DB)");
        gotoxy(10, 12); printf("3. Actualizar Médico (VERSION SIN DB)");
        gotoxy(10, 14); printf("4. Eliminar Médico (VERSION SIN DB)");
        gotoxy(10, 16); printf("5. Volver al Menú Principal");

        gotoxy(10, 18); printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1: crear_medico(); break;
            case 2: mostrar_medicos(); break;
            case 3: actualizar_medico(); break;
            case 4: eliminar_medico(); break;
            case 5: break;
            default:
                gotoxy(10, 20);
                printf("Opción inválida!");
                getch();
        }
    } while(opcion != 5);
}


void menu_asegurados() {
    int opcion;
    do {
        limpiar_pantalla();
        mostrar_titulo("GESTION DE ASEGURADOS (VERSION SIN DB)"); // Nota importante para el usuario

        gotoxy(10, 8);  printf("1. Crear Asegurado (VERSION SIN DB)");
        gotoxy(10, 10); printf("2. Mostrar Asegurados (VERSION SIN DB)");
        gotoxy(10, 12); printf("3. Actualizar Asegurado (VERSION SIN DB)");
        gotoxy(10, 14); printf("4. Eliminar Asegurado (VERSION SIN DB)");
        gotoxy(10, 16); printf("5. Volver al Menú Principal");

        gotoxy(10, 18); printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1: crear_asegurado(); break;
            case 2: mostrar_asegurados(); break;
            case 3: actualizar_asegurado(); break;
            case 4: eliminar_asegurado(); break;
            case 5: break;
            default:
                gotoxy(10, 20);
                printf("Opción inválida!");
                getch();
        }
    } while(opcion != 5);
}

void menu_hospitalizaciones() {
    int opcion;
    do {
        limpiar_pantalla();
        mostrar_titulo("GESTION DE HOSPITALIZACIONES (VERSION SIN DB)"); // Nota importante para el usuario

        gotoxy(10, 8);  printf("1. Crear Hospitalización (VERSION SIN DB)");
        gotoxy(10, 10); printf("2. Mostrar Hospitalizaciones (VERSION SIN DB)");
        gotoxy(10, 12); printf("3. Actualizar Hospitalización (VERSION SIN DB)");
        gotoxy(10, 14); printf("4. Eliminar Hospitalización (VERSION SIN DB)");
        gotoxy(10, 16); printf("5. Volver al Menú Principal");

        gotoxy(10, 18); printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1: crear_hospitalizacion(); break;
            case 2: mostrar_hospitalizaciones(); break;
            case 3: actualizar_hospitalizacion(); break;
            case 4: eliminar_hospitalizacion(); break;
            case 5: break;
            default:
                gotoxy(10, 20);
                printf("Opción inválida!");
                getch();
        }
    } while(opcion != 5);
}


void menu_principal() {
    int opcion;
    do {
        limpiar_pantalla();
        
        // Título principal con diseño
        gotoxy(25, 2);
        printf("╔══════════════════════════════════════╗");
        gotoxy(25, 3);
        printf("║     SISTEMA DE GESTION HOSPITALARIA  ║");
        gotoxy(25, 4);
        printf("╚══════════════════════════════════════╝");
        
        gotoxy(15, 7);
        printf("1. Conectar a la Base de Datos");
        gotoxy(15, 9);
        printf("2. Desconectar de la Base de Datos");
        gotoxy(15, 11);
        printf("3. Crear Hospital (Ejemplo en DB)"); // Nueva opción para probar DB
        gotoxy(15, 13);
        printf("4. Mostrar Hospitales (Desde DB)");   // Nueva opción para probar DB
        gotoxy(15, 15);
        printf("5. Gestión de Hospitales (VERSION SIN DB)"); // Opciones de CRUD con arrays
        gotoxy(15, 17);
        printf("6. Gestión de Áreas (VERSION SIN DB)");
        gotoxy(15, 19);
        printf("7. Gestión de Médicos (VERSION SIN DB)");
        gotoxy(15, 21);
        printf("8. Gestión de Asegurados (VERSION SIN DB)");
        gotoxy(15, 23);
        printf("9. Gestión de Hospitalizaciones (VERSION SIN DB)");
        gotoxy(15, 25);
        printf("10. Reporte Relacional (VERSION SIN DB)");
        gotoxy(15, 27);
        printf("11. Cargar Datos de Ejemplo (VERSION SIN DB)");
        gotoxy(15, 29);
        printf("12. Salir");
        
        gotoxy(15, 31);
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        getchar();
        switch(opcion) {
            case 1: conectar_db(); break;
            case 2: desconectar_db(); break;
            case 3: insertar_hospital_db_ejemplo(); break; // Llama a la función de DB
            case 4: mostrar_hospitales_db_ejemplo(); break; // Llama a la función de DB
            case 5: menu_hospitales(); break;
            case 6: menu_areas(); break;
            case 7: menu_medicos(); break;
            case 8: menu_asegurados(); break;
            case 9: menu_hospitalizaciones(); break;
            case 10: mostrar_reporte_relacional(); break;
            case 11: 
                cargar_datos_ejemplo();
                gotoxy(15, 33);
                printf("Datos de ejemplo cargados exitosamente en memoria (NO EN DB)!");
                getch();
                break;
            case 12: 
                desconectar_db(); // Asegurarse de desconectar al salir
                gotoxy(15, 33);
                printf("¡Gracias por usar el sistema!");
                break;
            default:
                gotoxy(15, 33);
                printf("Opción inválida!");
                getch();
        }
    } while(opcion != 12);
}

int main() {
    // Configurar consola para caracteres especiales
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    // Iniciar la conexión a la base de datos al inicio si deseas
    // o dejar que el usuario la conecte desde el menú.
    // conectar_db(); // Podrías llamar a esto aquí si quieres que se conecte automáticamente

    menu_principal();
    
    // Asegurarse de cerrar la conexión al finalizar el programa
    // (aunque ya se llama en el menú principal al salir)
    if (conn) {
        mysql_close(conn);
    }
    
    return 0;
}