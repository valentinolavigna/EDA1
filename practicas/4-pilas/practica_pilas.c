#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "practica_pilas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "pilas/pilas.h"

bool buscarElemento(Pila p, TipoElemento e) {

    Pila aux = p_crear();
    bool encontrado = false;

    while (!p_es_vacia(p)) {

        TipoElemento te = p_desapilar(p);

        if (te->clave == e->clave)
            encontrado = true;

        p_apilar(aux, te);
    }

    while (!p_es_vacia(aux))
        p_apilar(p, p_desapilar(aux));

    return encontrado;
}

void insertarElemento(Pila p, TipoElemento e, int pos) {

    Pila aux = p_crear();

    int actual = 1;

    while (!p_es_vacia(p) && actual < pos) {
        p_apilar(aux, p_desapilar(p));
        actual++;
    }

    p_apilar(p, e);

    while (!p_es_vacia(aux))
        p_apilar(p, p_desapilar(aux));
}

void eliminarElemento(Pila p, int clave) {

    Pila aux = p_crear();
    bool eliminado = false;

    while (!p_es_vacia(p)) {

        TipoElemento te = p_desapilar(p);

        if (!eliminado && te->clave == clave) {
            eliminado = true;
        } else {
            p_apilar(aux, te);
        }
    }

    while (!p_es_vacia(aux))
        p_apilar(p, p_desapilar(aux));
}

void intercambiarElementos(Pila p, int pos1, int pos2) {

    int n = contarElementos(p);

    TipoElemento elementos[1000];

    int i = 0;

    while (!p_es_vacia(p))
        elementos[i++] = p_desapilar(p);

    TipoElemento aux = elementos[pos1 - 1];
    elementos[pos1 - 1] = elementos[pos2 - 1];
    elementos[pos2 - 1] = aux;

    for (i = n - 1; i >= 0; i--)
        p_apilar(p, elementos[i]);
}

Pila copiar(Pila p) {

    Pila aux = p_crear();
    Pila copia = p_crear();

    while (!p_es_vacia(p))
        p_apilar(aux, p_desapilar(p));

    while (!p_es_vacia(aux)) {

        TipoElemento te = p_desapilar(aux);

        p_apilar(p, te);
        p_apilar(copia, te);
    }

    return copia;
}

int contarElementos(Pila p) {

    Pila aux = p_crear();
    int contador = 0;

    while (!p_es_vacia(p)) {

        p_apilar(aux, p_desapilar(p));
        contador++;
    }

    while (!p_es_vacia(aux))
        p_apilar(p, p_desapilar(aux));

    return contador;
}

bool compararPilas(Pila p1, Pila p2) {

    Pila aux = p_crear();

    bool iguales = true;

    while (!p_es_vacia(p1) && !p_es_vacia(p2)) {

        TipoElemento e1 = p_desapilar(p1);
        TipoElemento e2 = p_desapilar(p2);

        if (e1->clave != e2->clave)
            iguales = false;

        p_apilar(aux, e1);
        p_apilar(aux, e2);
    }

    if (!p_es_vacia(p1) || !p_es_vacia(p2))
        iguales = false;

    while (!p_es_vacia(aux)) {

        TipoElemento e2 = p_desapilar(aux);
        TipoElemento e1 = p_desapilar(aux);

        p_apilar(p1, e1);
        p_apilar(p2, e2);
    }

    return iguales;
}

char *cambioDeBase(int numero, int base) {

    static char resultado[100];

    char digitos[] = "0123456789ABCDEF";

    Pila p = p_crear();

    if (numero == 0) {
        strcpy(resultado, "0");
        return resultado;
    }

    while (numero > 0) {

        int resto = numero % base;

        p_apilar(p, te_crear(resto));

        numero /= base;
    }

    int i = 0;

    while (!p_es_vacia(p)) {

        TipoElemento te = p_desapilar(p);

        resultado[i++] = digitos[te->clave];
    }

    resultado[i] = '\0';

    return resultado;
}

Pila invertirPila(Pila p) {

    Pila invertida = p_crear();
    Pila aux = p_crear();

    while (!p_es_vacia(p)) {

        TipoElemento te = p_desapilar(p);

        p_apilar(aux, te);
        p_apilar(invertida, te);
    }

    while (!p_es_vacia(aux))
        p_apilar(p, p_desapilar(aux));

    return invertida;
}

Pila eliminarTodasOcurrencias(Pila p, int clave) {

    Pila resultado = p_crear();
    Pila aux = p_crear();

    while (!p_es_vacia(p)) {

        TipoElemento te = p_desapilar(p);

        p_apilar(aux, te);

        if (te->clave != clave)
            p_apilar(resultado, te);
    }

    while (!p_es_vacia(aux))
        p_apilar(p, p_desapilar(aux));

    return invertirPila(resultado);
}

Pila elementosEnComun(Pila p1, Pila p2) {

    Pila resultado = p_crear();

    Pila copia1 = copiar(p1);

    while (!p_es_vacia(copia1)) {

        TipoElemento te = p_desapilar(copia1);

        if (buscarElemento(p2, te))
            p_apilar(resultado, te);
    }

    return invertirPila(resultado);
}

Pila eliminarRepetidos(Pila p) {

    Pila resultado = p_crear();
    Pila copia = copiar(p);

    while (!p_es_vacia(copia)) {

        TipoElemento te = p_desapilar(copia);

        if (!buscarElemento(resultado, te))
            p_apilar(resultado, te);
    }

    return invertirPila(resultado);
}
