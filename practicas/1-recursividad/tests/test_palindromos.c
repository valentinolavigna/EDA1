#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests para Palíndromos");
    assert(bool_eq(esPalindromo("neuquen"), true));
    assert(bool_eq(esPalindromo("a"), true));
    assert(bool_eq(esPalindromo(""), true));
    assert(bool_eq(esPalindromo("hola"), false));
    return 0;
}
