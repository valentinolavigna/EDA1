#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"


int main() {
    imprimir_titulo("Tests para término de Fibonacci");
    assert(int_eq(terminoSerieDeFibonacci(0), 0));
    assert(int_eq(terminoSerieDeFibonacci(1), 1));
    assert(int_eq(terminoSerieDeFibonacci(2), 1));
    assert(int_eq(terminoSerieDeFibonacci(6), 8));
    return 0;
}
