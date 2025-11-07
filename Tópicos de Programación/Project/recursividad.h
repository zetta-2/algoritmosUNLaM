#ifndef RECURSIVIDAD_H_INCLUDED
#define RECURSIVIDAD_H_INCLUDED
#include <stdio.h>

unsigned long long r_factorial(unsigned x);
int r_map(void *vec, int ce, unsigned tamanio, void accion(void*));
int r_map_inverso(void *vec, int ce, unsigned tamanio, void accion(void*));
size_t r_strlen(const char *cad);
char* r_strchr(const char *cadena, int letra);
char* r_strrchr(const char *cadena, int letra);
int r_Es_Palindromo(const char *cad);
int _r_Es_Palindromo(const char *ini, const char *fin);//envoltorio
void* r_Bsearch(void *valor, const void *vec, size_t ce, size_t tamanio, int Comparar(const void*,const void*));

#endif // RECURSIVIDAD_H_INCLUDED

