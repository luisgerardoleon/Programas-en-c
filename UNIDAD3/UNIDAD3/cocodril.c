#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>

typedef struct {
    int id_cocodrilo;
    char especie[50];
    char nombre[50];
    char color[30];
    char habitat[50];
} Cocodrilo;

typedef struct {
    int id;
    int id_cocodrilo;
    char descripcion[100];
    char fecha[11];  // YYYY-MM-DD
} Mantenimiento;

typedef struct {
    int id;
    int id_cocodrilo;
    char tipo_comida[50];
    float cantidad;
    char fecha[11];  // YYYY-MM-DD
} Alimentacion;

typedef struct {
    int id_ubicacion;
    char nombre_ubicacion[50];
    char descripcion[100];
} Ubicacion;

typedef struct {
    int id;
    int id_cocodrilo;
    int id_ubicacion;
    char fecha_ingreso[11];
    char fecha_salida[11];
} CocodriloUbicacion;

MYSQL *con;

void finish_with_error() {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void conectar() {
    con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "12345", "cocodrilo", 3306, NULL, 0) == NULL) {
        finish_with_error();
    }
}

int insertar_cocodrilo(const Cocodrilo *c) {
    char query[512];
    snprintf(query, sizeof(query),
        "INSERT INTO cocodrilos (especie, nombre, color, habitat) VALUES('%s','%s','%s','%s')",
        c->especie, c->nombre, c->color, c->habitat);
    if (mysql_query(con, query)) {
        finish_with_error();
    }
    return (int)mysql_insert_id(con);
}

void insertar_mantenimiento(const Mantenimiento *m) {
    char query[512];
    snprintf(query, sizeof(query),
        "INSERT INTO mantenimientos (id_cocodrilo, descripcion, fecha) VALUES (%d, '%s', '%s')",
        m->id_cocodrilo, m->descripcion, m->fecha);
    if (mysql_query(con, query)) {
        finish_with_error();
    }
}

void insertar_alimentacion(const Alimentacion *a) {
    char query[512];
    snprintf(query, sizeof(query),
        "INSERT INTO alimentacion (id_cocodrilo, tipo_comida, cantidad, fecha) VALUES (%d, '%s', %.2f, '%s')",
        a->id_cocodrilo, a->tipo_comida, a->cantidad, a->fecha);
    if (mysql_query(con, query)) {
        finish_with_error();
    }
}

int insertar_ubicacion(const Ubicacion *u) {
    char query[512];
    snprintf(query, sizeof(query),
        "INSERT INTO ubicaciones (nombre_ubicacion, descripcion) VALUES ('%s', '%s')",
        u->nombre_ubicacion, u->descripcion);
    if (mysql_query(con, query)) {
        finish_with_error();
    }
    return (int)mysql_insert_id(con);
}

void insertar_cocodrilo_ubicacion(const CocodriloUbicacion *cu) {
    char query[512];
    snprintf(query, sizeof(query),
        "INSERT INTO cocodrilo_ubicacion (id_cocodrilo, id_ubicacion, fecha_ingreso, fecha_salida) VALUES (%d, %d, '%s', '%s')",
        cu->id_cocodrilo, cu->id_ubicacion, cu->fecha_ingreso, cu->fecha_salida);
    if (mysql_query(con, query)) {
        finish_with_error();
    }
}

void mostrar_cocodrilos_completo() {
    const char *query =
        "SELECT c.id_cocodrilo, c.especie, c.nombre, c.color, c.habitat, "
        "m.descripcion, m.fecha, "
        "a.tipo_comida, a.cantidad, a.fecha, "
        "u.nombre_ubicacion, u.descripcion, "
        "cu.fecha_ingreso, cu.fecha_salida "
        "FROM cocodrilos c "
        "LEFT JOIN mantenimientos m ON c.id_cocodrilo = m.id_cocodrilo "
        "LEFT JOIN alimentacion a ON c.id_cocodrilo = a.id_cocodrilo "
        "LEFT JOIN cocodrilo_ubicacion cu ON c.id_cocodrilo = cu.id_cocodrilo "
        "LEFT JOIN ubicaciones u ON cu.id_ubicacion = u.id_ubicacion "
        "ORDER BY c.id_cocodrilo";

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (!result) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int last_id = -1;

    while ((row = mysql_fetch_row(result))) {
        int id = atoi(row[0]);
        if (id != last_id) {
            printf("\nCocodrilo ID: %d\n", id);
            printf("Especie: %s | Nombre: %s | Color: %s | Hábitat: %s\n",
                row[1] ? row[1] : "N/A",
                row[2] ? row[2] : "N/A",
                row[3] ? row[3] : "N/A",
                row[4] ? row[4] : "N/A");
            printf("Mantenimientos:\n");
            printf("Alimentación:\n");
            printf("Ubicaciones:\n");
            last_id = id;
        }
        if (row[5] && row[6])
            printf(" - %s (%s)\n", row[5], row[6]);
        if (row[7] && row[8] && row[9])
            printf(" - %s, %.2f kg (%s)\n", row[7], atof(row[8]), row[9]);
        if (row[10] && row[11] && row[12] && row[13])
            printf(" - %s: %s (Ingreso: %s, Salida: %s)\n", row[10], row[11], row[12], row[13]);
    }

    mysql_free_result(result);
}

void eliminar_cocodrilo(int id_cocodrilo) {
    char query[256];

    // Eliminar en orden para evitar problemas de FK
    snprintf(query, sizeof(query), "DELETE FROM mantenimientos WHERE id_cocodrilo=%d", id_cocodrilo);
    if (mysql_query(con, query)) finish_with_error();

    snprintf(query, sizeof(query), "DELETE FROM alimentacion WHERE id_cocodrilo=%d", id_cocodrilo);
    if (mysql_query(con, query)) finish_with_error();

    snprintf(query, sizeof(query), "DELETE FROM cocodrilo_ubicacion WHERE id_cocodrilo=%d", id_cocodrilo);
    if (mysql_query(con, query)) finish_with_error();

    snprintf(query, sizeof(query), "DELETE FROM cocodrilos WHERE id_cocodrilo=%d", id_cocodrilo);
    if (mysql_query(con, query)) finish_with_error();

    printf("Cocodrilo y sus datos relacionados eliminados.\n");
}

int main() {
    conectar();

    // Insertar cocodrilo
    Cocodrilo c = {0, "Cocodrilo Americano", "Alfredo", "Verde oscuro", "Pantano"};
    int id_c = insertar_cocodrilo(&c);

    // Insertar mantenimientos
    Mantenimiento m1 = {0, id_c, "Revisión veterinaria", "2025-05-20"};
    Mantenimiento m2 = {0, id_c, "Cambio de agua del hábitat", "2025-05-21"};
    insertar_mantenimiento(&m1);
    insertar_mantenimiento(&m2);

    // Insertar alimentación
    Alimentacion a1 = {0, id_c, "Pescado fresco", 5.0f, "2025-05-20"};
    Alimentacion a2 = {0, id_c, "Carne de res", 3.5f, "2025-05-21"};
    insertar_alimentacion(&a1);
    insertar_alimentacion(&a2);

    // Insertar ubicación
    Ubicacion u = {0, "Zona A", "Área pantanosa para cocodrilos grandes"};
    int id_u = insertar_ubicacion(&u);

    // Insertar relación cocodrilo-ubicación
    CocodriloUbicacion cu = {0, id_c, id_u, "2025-05-01", "2025-06-01"};
    insertar_cocodrilo_ubicacion(&cu);

    // Mostrar todo
    mostrar_cocodrilos_completo();

    // Eliminar cocodrilo y sus datos
    eliminar_cocodrilo(id_c);

    mysql_close(con);
    return 0;
}
