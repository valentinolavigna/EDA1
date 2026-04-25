#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

static bool file_eq(const char *archivo_esperado, const char *archivo_generado) {
    FILE *esperado = fopen(archivo_esperado, "r");
    FILE *generado = fopen(archivo_generado, "r");

    if (!esperado || !generado) {
        if (esperado) fclose(esperado);
        if (generado) fclose(generado);
        return false;
    }

    char linea_esperada[256];
    char linea_generada[256];
    bool son_iguales = true;

    while (fgets(linea_esperada, sizeof(linea_esperada), esperado) != NULL) {
        if (fgets(linea_generada, sizeof(linea_generada), generado) == NULL) {
            son_iguales = false;
            break;
        }
        if (strcmp(linea_esperada, linea_generada) != 0) {
            son_iguales = false;
            break;
        }
    }

    if (fgets(linea_generada, sizeof(linea_generada), generado) != NULL)
        son_iguales = false;

    fclose(esperado);
    fclose(generado);
    return son_iguales;
}

int main() {
    imprimir_titulo("TP Integrador - Ruta de Rescate en Mina");

    // Prueba 1: ruta con mayor puntaje gana sobre ruta directa mas corta
    resolver_ruta_mina("archivos/prueba1_entrada.txt", "archivos/prueba1_salida.txt");
    assert(file_eq("archivos/prueba1_salida_esperada.txt", "archivos/prueba1_salida.txt"));

    // Prueba 2: mapa sin camino posible
    resolver_ruta_mina("archivos/prueba2_entrada.txt", "archivos/prueba2_salida.txt");
    assert(file_eq("archivos/prueba2_salida_esperada.txt", "archivos/prueba2_salida.txt"));

    // Prueba 3: empate en puntaje, gana la de menor cantidad de pasos
    resolver_ruta_mina("archivos/prueba3_entrada.txt", "archivos/prueba3_salida.txt");
    assert(file_eq("archivos/prueba3_salida_esperada.txt", "archivos/prueba3_salida.txt"));

    // Prueba 4: empate en puntaje y pasos, gana la de menor secuencia lexicografica
    resolver_ruta_mina("archivos/prueba4_entrada.txt", "archivos/prueba4_salida.txt");
    assert(file_eq("archivos/prueba4_salida_esperada.txt", "archivos/prueba4_salida.txt"));

    return 0;
}
