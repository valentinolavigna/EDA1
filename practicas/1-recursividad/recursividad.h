#ifndef RECURSIVIDAD_H
#define RECURSIVIDAD_H

#include <stdbool.h>


bool esCapicua(int numero);

bool esPalindromo(char *palabra);

int productoRecursivo(int m, int n);

int terminoSerieDeFibonacci(int n);

int restoRecursivo(int dividendo, int divisor);

char *agregarSeparadorMiles(char *numero);

char *chinos(unsigned int nivel);

char *ondaDigital(char *);

bool esDivisiblePor7(int n);

int *explosion(int n, int b, int *size);

void resolver_ruta_mina(const char *archivo_entrada, const char *archivo_salida);

#endif // RECURSIVIDAD_H
