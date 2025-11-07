#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

#include "macros.h"

typedef tNodo* tPilaCircular;
typedef tNodo* tColaCircular;

///primitivas de pila circular
void crearPilaCircular(tPilaCircular *pila);
int apilarCircular(tPilaCircular *pila, const void *info, unsigned bytes);
int verTopeCircular(tPilaCircular *pila, void *tope, unsigned bytes);
int extraerTopeCircular(tPilaCircular *pila, void *tope, unsigned bytes);
int pilaCircularVacia(tPilaCircular *pila);
int pilaCircularLlena(tPilaCircular *pila, unsigned bytes);
void vaciarPilaCircular(tPilaCircular *pila);

///primitivas de cola circular
void crearColaCircular(tColaCircular *cola);
int encolarCircular(tColaCircular *cola, const void *info, unsigned bytes);
int verPrimeroColaCircular(tColaCircular *cola, void *info, unsigned bytes);
int extraerPrimeroColaCircular(tColaCircular *cola, void *info, unsigned bytes);
int colaCircularVacia(tColaCircular *cola);
int colaCircularLlena(tColaCircular *cola, unsigned bytes);
void vaciarColaCircular(tColaCircular *cola);

#endif // LISTACIRCULAR_H_INCLUDED
