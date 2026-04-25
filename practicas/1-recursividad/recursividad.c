#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recursividad.h"

int invertir(int numero, int acumulador) {
    if (numero == 0) return acumulador;
    return invertir(numero / 10, acumulador * 10 + numero % 10);
}

bool esCapicua(int numero) {
    if (numero < 0) return false;
    return numero == invertir(numero, 0);
}

static bool esPalindromoRecursivo(const char *inicio, const char *fin) {
    if (inicio >= fin) {
        return true;
    }

    if (*inicio != *fin) {
        return false;
    }

    return esPalindromoRecursivo(inicio + 1, fin - 1);
}

bool esPalindromo(char *palabra) {
    int largo = strlen(palabra);

    if (largo <= 1) {
        return true;
    }

    return esPalindromoRecursivo(palabra, palabra + largo - 1);
}


int productoRecursivo(int m, int n) {
    if (n == 0) {
        return 0;
    } 
    else if (n > 0) {
        return m + productoRecursivo(m, n - 1);
    }else {
        return - productoRecursivo(m, -n);
    } 
}


int terminoSerieDeFibonacci(int n) {
    if (n < 2) {
        return n;
    }else {
        return terminoSerieDeFibonacci(n - 1) + terminoSerieDeFibonacci(n - 2);
    }
}


static int divisiblePor7Recursivo(int n) {
    if (n < 70) {
        return n;
    }

    int ultimaCifra = n % 10;
    int resto = n / 10;
    return divisiblePor7Recursivo(resto - (ultimaCifra * 2));
}

bool esDivisiblePor7(int n) {
    if (n < 0) {
        n = -n;
    }

    int reducido = divisiblePor7Recursivo(n);
    return (reducido % 7) == 0;
}


int restoRecursivo(int dividendo, int divisor) {
    if (divisor == 0) {
        return 0;
    }

    if (divisor < 0) {
        divisor = -divisor;
    }

    if (dividendo < 0) {
        return -restoRecursivo(-dividendo, divisor);
    }

    if (dividendo < divisor) {
        return dividendo;
    }

    return restoRecursivo(dividendo - divisor, divisor);
}


static void agregarFragmento(int valor, int **resultado, int *size, int *capacidad) {
    if (*capacidad == 0) {
        *capacidad = 8;
        *resultado = malloc((size_t) *capacidad * sizeof(int));
    } else if (*size >= *capacidad) {
        *capacidad *= 2;
        *resultado = realloc(*resultado, (size_t) *capacidad * sizeof(int));
    }

    (*resultado)[*size] = valor;
    (*size)++;
}

static void explosionRecursiva(int n, int b, int **result, int *size, int *capacidad) {
    if (n <= b) {
        agregarFragmento(n, result, size, capacidad);
        return;
    }

    int n1 = n / b;
    int n2 = n - n1;

    explosionRecursiva(n1, b, result, size, capacidad);
    explosionRecursiva(n2, b, result, size, capacidad);
}

int *explosion(int n, int b, int *size) {
    *size = 0;
    int capacidad = 0;
    int *resultado = NULL;

    if (b <= 1 || n <= 0) {
        return resultado;
    }

    explosionRecursiva(n, b, &resultado, size, &capacidad);
    return resultado;
}

 char* chinos(unsigned int nivel){
    //Caso base
    if (nivel==1){
        char *base=malloc(6);//"(-.-)" + '\0'
        strcpy(base, "(-.-)");
        return base;
    }

    //Llamada recursiva:
    char *interno=chinos(nivel-1);

    int tam=strlen(interno)+6+1;

    char *resultado=malloc(tam);

    strcpy(resultado, "(-.");//parte izquierda fija
    strcat(resultado, interno);//parte recursiva 
    strcat(resultado, ".-)");//parte derecha

    free(interno);

    return resultado;
 }

char *agregarSeparadoresRecursivo(char *numero, int indice, int contador) {
}

char *agregarSeparadorMiles(char *numero){
    
    int tamaño=(strlen(numero));//Obtengo el tamaño del string

    //Caso base:
    if(tamaño<=3){
        char *n=malloc(tamaño +1);
        strcpy(n, numero);
        return n;//Retorno el string sin modificaciones
    }
        //Calcular primer bloque
        int cantidad=(tamaño%3==0)?3:(tamaño%3);//Hago la cuenta de cuantos puntos debo agregar

        //Cantidad de puntos necesarios
        int puntos=(tamaño-1)/3;

        char *n=malloc(tamaño+puntos+1);

        //Copiar primera parte
        strncpy(n, numero, cantidad);
        n[cantidad]='\0';

        //Recursión con el resto
        char *resto=agregarSeparadorMiles(numero+cantidad);

        //Armar resultado
        strcat(n, ".");
        strcat(n, resto);

        //Libero la memoria dinamica
        free(resto);
        
        return n;
}

static void ondaDigitalRecursiva(const char *entrada, int indice, int largo, char *salida, int *posicion) {
    if (indice >= largo) {
        return;
    }

    const char *simbolo = (entrada[indice] == 'H') ? "‾" : "_";
    size_t largoSimbolo = strlen(simbolo);
    memcpy(salida + *posicion, simbolo, largoSimbolo);
    *posicion += (int) largoSimbolo;

    if (indice == largo - 1) {
        return;
    }

    if (entrada[indice] == entrada[indice + 1]) {
        salida[*posicion] = ' ';
        (*posicion)++;
    } else {
        const char *separador = " | ";
        size_t largoSeparador = strlen(separador);
        memcpy(salida + *posicion, separador, largoSeparador);
        *posicion += (int) largoSeparador;
    }

    ondaDigitalRecursiva(entrada, indice + 1, largo, salida, posicion);
}

char *ondaDigital(char *onda) {
    if (onda == NULL) {
        return NULL;
    }

    int largo = (int) strlen(onda);
    if (largo == 0) {
        char *vacio = malloc(1);
        vacio[0] = '\0';
        return vacio;
    }

    size_t capacidad = ((size_t) largo * 5) + 1;
    char *resultado = malloc(capacidad);
    int posicion = 0;

    ondaDigitalRecursiva(onda, 0, largo, resultado, &posicion);
    resultado[posicion] = '\0';

    return resultado;
}