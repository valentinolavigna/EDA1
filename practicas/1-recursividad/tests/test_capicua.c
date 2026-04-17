#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests para Capicua");
    assert(bool_eq(esCapicua(12321), true));
    assert(bool_eq(esCapicua(1), true));
    assert(bool_eq(esCapicua(11), true));
    assert(bool_eq(esCapicua(123), false));
    assert(bool_eq(esCapicua(10), false));
    assert(bool_eq(esCapicua(-121), false));
    return 0;
}