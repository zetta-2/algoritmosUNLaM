#ifndef DPILA_H_INCLUDED
#define DPILA_H_INCLUDED
#include "macros.h"

typedef tNodo* tPila; //->tipo de dato como puntero

///PRIMITIVAS
void d_crearPila(tPila *p);
int d_Apilar(tPila *p, const void *info, unsigned bytes);
int d_VerTope(const tPila *p, void *info, unsigned bytes);
int d_Despilar(tPila *p, void *info, unsigned bytes);
int d_PilaLlena(const tPila *p, unsigned bytes);
int d_pilaVacia(const tPila *p);
void d_VaciarPila(tPila *p);

#endif // DPILA_H_INCLUDED
