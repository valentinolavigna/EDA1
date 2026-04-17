#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests para ondaDigital");

    char *r;

    r = ondaDigital("HL");
    assert(str_eq(r, "‾ | _"));
    free(r);

    r = ondaDigital("LH");
    assert(str_eq(r, "_ | ‾"));
    free(r);

    r = ondaDigital("HLHL");
    assert(str_eq(r, "‾ | _ | ‾ | _"));
    free(r);

    r = ondaDigital("HLLHHL");
    assert(str_eq(r, "‾ | _ _ | ‾ ‾ | _"));
    free(r);

    r = ondaDigital("");
    assert(str_eq(r, ""));
    free(r);

    return 0;
}
