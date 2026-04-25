#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "recursividad.h"

typedef struct {
    unsigned int fila;
    unsigned int columna;
} Posicion;

typedef struct {
    char **celdas;
    int filas;
    int columnas;
    Posicion inicio;
    Posicion salida;
} Mapa;

typedef struct {
    bool encontrada;
    int puntaje;
    int pasos;
    char *movimientos;
    Posicion *camino;
    int largo_camino;
} Solucion;

static const int DELTA_FILA[]    = { -1,  1,  0,  0 };
static const int DELTA_COLUMNA[] = {  0,  0,  1, -1 };
static const char LETRAS[]       = { 'A', 'B', 'D', 'I' };

static Mapa *leer_mapa(const char *archivo) {
    FILE *f = fopen(archivo, "r");
    if (!f) return NULL;

    Mapa *mapa = malloc(sizeof(Mapa));
    if (!mapa) { fclose(f); return NULL; }

    if (fscanf(f, "%d %d\n", &mapa->filas, &mapa->columnas) != 2) {
        free(mapa);
        fclose(f);
        return NULL;
    }

    mapa->celdas = malloc((size_t)mapa->filas * sizeof(char *));
    if (!mapa->celdas) { free(mapa); fclose(f); return NULL; }

    for (int i = 0; i < mapa->filas; i++) {
        mapa->celdas[i] = malloc((size_t)(mapa->columnas + 1));
        if (!mapa->celdas[i] || fscanf(f, "%s", mapa->celdas[i]) != 1) {
            for (int j = 0; j <= i; j++) free(mapa->celdas[j]);
            free(mapa->celdas);
            free(mapa);
            fclose(f);
            return NULL;
        }
        for (int j = 0; j < mapa->columnas; j++) {
            if (mapa->celdas[i][j] == 'I') {
                mapa->inicio.fila = (unsigned int)(i + 1);
                mapa->inicio.columna = (unsigned int)(j + 1);
            } else if (mapa->celdas[i][j] == 'S') {
                mapa->salida.fila = (unsigned int)(i + 1);
                mapa->salida.columna = (unsigned int)(j + 1);
            }
        }
    }

    fclose(f);
    return mapa;
}

static void liberar_mapa(Mapa *mapa) {
    for (int i = 0; i < mapa->filas; i++) free(mapa->celdas[i]);
    free(mapa->celdas);
    free(mapa);
}

static bool es_mejor(Solucion *actual, int nuevo_puntaje, int nuevos_pasos) {
    if (!actual->encontrada) return true;
    if (nuevo_puntaje > actual->puntaje) return true;
    if (nuevo_puntaje == actual->puntaje && nuevos_pasos < actual->pasos) return true;
    return false;
}

static void actualizar_solucion(Solucion *mejor, int puntaje, int pasos,
                                char *movimientos, Posicion *camino) {
    free(mejor->movimientos);
    free(mejor->camino);
    mejor->encontrada = true;
    mejor->puntaje = puntaje;
    mejor->pasos = pasos;
    mejor->movimientos = malloc((size_t)(pasos + 1));
    memcpy(mejor->movimientos, movimientos, (size_t)(pasos + 1));
    mejor->largo_camino = pasos + 1;
    mejor->camino = malloc((size_t)(pasos + 1) * sizeof(Posicion));
    memcpy(mejor->camino, camino, (size_t)(pasos + 1) * sizeof(Posicion));
}

static void buscar(Mapa *mapa, bool **visitado, Posicion *camino, char *movimientos,
                   int fila, int columna, int puntaje, int pasos, Solucion *mejor) {
    if (fila == (int)mapa->salida.fila && columna == (int)mapa->salida.columna) {
        if (es_mejor(mejor, puntaje, pasos))
            actualizar_solucion(mejor, puntaje, pasos, movimientos, camino);
        return;
    }

    for (int d = 0; d < 4; d++) {
        int nf = fila + DELTA_FILA[d];
        int nc = columna + DELTA_COLUMNA[d];

        if (nf < 1 || nf > mapa->filas || nc < 1 || nc > mapa->columnas) continue;

        char celda = mapa->celdas[nf - 1][nc - 1];
        if (celda == '#' || visitado[nf - 1][nc - 1]) continue;

        int puntos_extra = (celda >= '0' && celda <= '9') ? (celda - '0') : 0;

        visitado[nf - 1][nc - 1] = true;
        camino[pasos + 1].fila = (unsigned int)nf;
        camino[pasos + 1].columna = (unsigned int)nc;
        movimientos[pasos] = LETRAS[d];
        movimientos[pasos + 1] = '\0';

        buscar(mapa, visitado, camino, movimientos, nf, nc,
               puntaje + puntos_extra, pasos + 1, mejor);

        visitado[nf - 1][nc - 1] = false;
    }
}

void resolver_ruta_mina(const char *archivo_entrada, const char *archivo_salida) {
    Mapa *mapa = leer_mapa(archivo_entrada);

    FILE *salida = fopen(archivo_salida, "w");
    if (!salida) {
        if (mapa) liberar_mapa(mapa);
        return;
    }

    if (!mapa) {
        fprintf(salida, "RESULTADO: SIN_CAMINO\n");
        fclose(salida);
        return;
    }

    int max_len = mapa->filas * mapa->columnas;

    bool **visitado = malloc((size_t)mapa->filas * sizeof(bool *));
    for (int i = 0; i < mapa->filas; i++)
        visitado[i] = calloc((size_t)mapa->columnas, sizeof(bool));

    Posicion *camino = malloc((size_t)max_len * sizeof(Posicion));
    char *movimientos = malloc((size_t)max_len);

    Solucion mejor = { false, 0, 0, NULL, NULL, 0 };

    int fi = (int)mapa->inicio.fila;
    int ci = (int)mapa->inicio.columna;
    camino[0].fila = mapa->inicio.fila;
    camino[0].columna = mapa->inicio.columna;
    movimientos[0] = '\0';
    visitado[fi - 1][ci - 1] = true;

    buscar(mapa, visitado, camino, movimientos, fi, ci, 0, 0, &mejor);

    if (!mejor.encontrada) {
        fprintf(salida, "RESULTADO: SIN_CAMINO\n");
    } else {
        fprintf(salida, "RESULTADO: ENCONTRADO\n");
        fprintf(salida, "PUNTAJE: %d\n", mejor.puntaje);
        fprintf(salida, "PASOS: %d\n", mejor.pasos);
        fprintf(salida, "MOVIMIENTOS: %s\n", mejor.movimientos);
        fprintf(salida, "CAMINO:");
        for (int i = 0; i < mejor.largo_camino; i++) {
            if (i == 0)
                fprintf(salida, " (%u,%u)", mejor.camino[i].fila, mejor.camino[i].columna);
            else
                fprintf(salida, " -> (%u,%u)", mejor.camino[i].fila, mejor.camino[i].columna);
        }
        fprintf(salida, "\n");
    }

    fclose(salida);
    free(mejor.movimientos);
    free(mejor.camino);
    free(movimientos);
    free(camino);
    for (int i = 0; i < mapa->filas; i++) free(visitado[i]);
    free(visitado);
    liberar_mapa(mapa);
}
