#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests del Ejercicio de Explosión saraza");

    int size;
    int *r;

    int esperado_10_3[] = {3, 2, 1, 1, 3};
    r = explosion(10, 3, &size);
    assert(ptr_not_null(r));
    assert(int_array_eq(r, esperado_10_3, size, 5));
    free(r);

    int esperado_20_5[] = {4, 3, 2, 2, 1, 1, 1, 1, 5};
    r = explosion(20, 5, &size);
    assert(ptr_not_null(r));
    assert(int_array_eq(r, esperado_20_5, size, 9));
    free(r);

    return 0;
}
