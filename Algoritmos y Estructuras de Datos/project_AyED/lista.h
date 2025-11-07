#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "macros.h"

typedef tNodo* tLista;

///PRIMITIVAS
void crearLista(tLista *p);
int insertarAlPrincipio(tLista *p, const void *info, unsigned bytes);
int insertarAlFinal(tLista *p, const void *info, unsigned bytes);
int insertarAlMedio(tLista *p, const void *info, unsigned bytes, int pos);
int insertarOrdenado(tLista *p, const void *info, unsigned bytes, int orden(const void*,const void*),
                     int duplicado,int accionDuplicados(void*,const void*));
int ordenarLista(tLista *p, int cmp(const void*,const void*));
tLista* buscarExtremo(tLista *p, cmp comparacion);
void recorrerLista(tLista *p, void accion(void*));
int listaLlena(const tLista *p, unsigned bytes);
int listaVacia(const tLista *p);
void vaciarLista(tLista *p);

#endif // LISTA_H_INCLUDED
