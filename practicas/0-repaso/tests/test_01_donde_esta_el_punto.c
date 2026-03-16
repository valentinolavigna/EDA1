#include <stdio.h>
#include <assert.h>

#include "aserciones.h"
#include "../repaso.h"
#include "cadenas.h"


int main() {
    imprimir_titulo("Tests de Ejercicio 1");
    assert(int_eq(dondeEstaElPunto(0, 0, 3, 0, 0), INTERNO));
    assert(int_eq(dondeEstaElPunto(0, 0, 5, 3, 4), EN_CIRCUNFERENCIA)); 
    assert(int_eq(dondeEstaElPunto(0, 0, 2, -3, 0), EXTERNO));
    return 0;
}
