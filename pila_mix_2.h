#ifndef PILA_MIX_2_H_INCLUDED
#define PILA_MIX_2_H_INCLUDED

#include <stdio.h>
#define TAM_PILA 16

typedef struct
{
    char *pila;
    unsigned int tope;
    unsigned int capacidad;//tamanio de la pila
}tPilaVer2;

///PRIMITIVAS
int crearPilaVer2(tPilaVer2 *pila);
int apilarVer2(tPilaVer2 *pila, const void *clave, size_t tam_dato);
int verTopeVer2(tPilaVer2 *Pila, void *valor, size_t tam_dato);
int desapilarVer2(tPilaVer2 *pila, void *valor, size_t tam_dato);
int pilaLlenaVer2(tPilaVer2 *pila, size_t tam_dato);
int pilaVaciaVer2(tPilaVer2 *pila);
int vaciarPilaVer2(tPilaVer2 *pila);

#endif // PILA_MIX_2_H_INCLUDED
