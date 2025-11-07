#ifndef COMPARACIONES_H_INCLUDED
#define COMPARACIONES_H_INCLUDED

#include "../macros.h"
#include "../arbol/arbol.h"

int cmpEnteros(const void *a, const void *b);
int cmpCaracteres(const void *a, const void *b);
int cmpFlotantes(const void *a, const void *b);
int cmpApellidosIndex(const void *a, const void *b);
int cmpNombreIndex(const void *a, const void *b);
#endif // COMPARACIONES_H_INCLUDED
