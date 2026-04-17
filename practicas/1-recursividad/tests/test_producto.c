#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests para producto");
    assert(int_eq(productoRecursivo(3, 4), 12));
    assert(int_eq(productoRecursivo(5, 0), 0));
    assert(int_eq(productoRecursivo(3, -4), -12));
    assert(int_eq(productoRecursivo(-3, 4), -12));
    return 0;
}
