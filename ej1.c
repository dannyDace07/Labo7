#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Persona
typedef struct {
    char nombre[50];
    int edad;
    double altura;
} Persona;

// Función para comparar por nombre
int comparar_por_nombre(const void *a, const void *b) {
    return strcmp(((Persona *)a)->nombre, ((Persona *)b)->nombre);
}

// Función para comparar por edad
int comparar_por_edad(const void *a, const void *b) {
    return ((Persona *)a)->edad - ((Persona *)b)->edad;
}

// Función para comparar por altura
int comparar_por_altura(const void *a, const void *b) {
    double diferencia = ((Persona *)a)->altura - ((Persona *)b)->altura;
    return (diferencia > 0) - (diferencia < 0);
}

// Función para imprimir el arreglo de personas
void imprimir_personas(const Persona *personas, int tamano) {
    for (int i = 0; i < tamano; i++) {
        printf("Nombre: %s, Edad: %d, Altura: %.2f\n", personas[i].nombre, personas[i].edad, personas[i].altura);
    }
    printf("\n");
}

int main() {
    Persona personas[] = {
        {"Carito", 30, 165.5},
        {"Kusanagi", 31, 168.0},
        {"Luffy", 35, 175.0},
        {"Enzo", 20, 170.3},
        {"Steven", 28, 160.0}
    };
    int tamano = sizeof(personas) / sizeof(personas[0]);

    printf("Lista de datos:\n");
    imprimir_personas(personas, tamano);

    qsort(personas, tamano, sizeof(Persona), comparar_por_nombre);
    printf("Orden por nombre:\n");
    imprimir_personas(personas, tamano);

    qsort(personas, tamano, sizeof(Persona), comparar_por_edad);
    printf("Orden por edad:\n");
    imprimir_personas(personas, tamano);

    qsort(personas, tamano, sizeof(Persona), comparar_por_altura);
    printf("Orden por altura:\n");
    imprimir_personas(personas, tamano);

    return 0;
}