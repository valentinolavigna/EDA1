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


bool esPalindromo(char *palabra) {
    int largo = strlen(palabra);

    if (largo <= 1)
        return true;

    if (palabra[0] != palabra[largo - 1])
        return false;

    palabra[largo - 1] = '\0';
    return esPalindromo(palabra + 1);
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


bool esDivisiblePor7(int n) {
    if (n < 0)
        return esDivisiblePor7(-n);

    if (n == 0 || n == 7)
        return true;

    if (n < 10)
        return false;

    int ultimo = n % 10;
    int resto = n / 10;

    // Aplicar regla
    return esDivisiblePor7(resto - 2 * ultimo);
}


int restoRecursivo(int dividendo, int divisor) {
    
}



void explosionRecursiva(int n, int b, int *result, int *size) {
}

int *explosion(int n, int b, int *size) {
}

char *chinos(unsigned int nivel) {
}

char *agregarSeparadoresRecursivo(char *numero, int indice, int contador) {
}

char *agregarSeparadorMiles(char *numero){
    int cantidad=(strlen(numero)-1)/3;//Hago la cuenta de cuantos puntos debo agregar.El strlen(numero) devuelve un int que es la cantidad de elemntos
    char *n=malloc(strlen(numero)+cantidad+1);//Reservo espacio en la memoria dinamica. Obtengo el tamaño del string con strlen(numero) sumo la cantidad de puntos que tengo que agregar más 1 que es el \0 el fin de linea
    int tamaño=(strlen(numero));//Obtengo el tamaño del string
    if(tamaño<=3){//Si el número es menor o igual
        return n;//Retorno el string, retorno n que es un char* que es como esta definida la función(char *agregarSeparadorMiles(char *numero)), n es el comienzo del string
    }//Retorn el string modificado con los puntos agregados
    else{
        strncpy(n, numero, 3);//Destino, cadena de origen y la cantidad de caracteres a copiar. n->es un string | *n->es un caracter. numero->es un string | *numero->es un caracter                                                                                             
        *n=".";
        return agregarSeparadorMiles(numero+cantidad);
    }
}