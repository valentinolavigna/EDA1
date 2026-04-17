#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"


int main() {
    imprimir_titulo("Tests para divisiblePor7");
    assert(bool_eq(esDivisiblePor7(7), true));
    assert(bool_eq(esDivisiblePor7(49), true));
    assert(bool_eq(esDivisiblePor7(10), false));
    assert(bool_eq(esDivisiblePor7(100), false));
    assert(bool_eq(esDivisiblePor7(-49), true));
    assert(bool_eq(esDivisiblePor7(-10), false));
    return 0;
}
