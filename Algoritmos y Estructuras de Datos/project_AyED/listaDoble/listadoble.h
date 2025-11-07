#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include "../macros.h"

typedef struct dNodo
{
    void *info;
    unsigned tam;
    struct dNodo *sig;
    struct dNodo *ant;
}tNodoD;

typedef tNodoD* tListaDoble;

void crearListaDoble(tListaDoble *p);
int insertarListaDoble(tListaDoble *p, const void *info, unsigned bytes, cmp comparar);
int listaDobleVacia(const tListaDoble *p);
int listaDobleLlena(const tListaDoble *p, unsigned bytes);
void mapIzq(tListaDoble *p, void accion(void*));
void mapDer(tListaDoble *p, void accion(void*));
void mapFinal(tListaDoble *p, void accion(void*));
void mapInicio(tListaDoble *p, void accion(void*));
void filter(tListaDoble *p, const void *clave ,int filtro(const void*,const void*));
void reduce(const tListaDoble *p, void *r, reduccion red);
int buscarValor(const tListaDoble *p, const void *clave ,void *info, unsigned bytes, cmp comparar);
void vaciarListaDoble(tListaDoble *p);

#endif // LISTADOBLE_H_INCLUDED
