#ifndef DCOLA_H_INCLUDED
#define DCOLA_H_INCLUDED
#include "macros.h"

typedef struct
{
    tNodo *pri;
    tNodo *ult;
}tCola;

///PRIMITIVAS
void d_crearCola(tCola *cola);
int d_encolar(tCola *cola, const void *info, unsigned bytes);
int d_verPriCola(const tCola *cola, void *info, unsigned bytes);
int d_sacarPriCola(tCola *cola, void *info, unsigned bytes);
int d_colaLlena(const tCola *cola, unsigned bytes);
int d_colaVacia(const tCola *cola);
void d_vaciarCola(tCola *cola);

#endif // DCOLA_H_INCLUDED
