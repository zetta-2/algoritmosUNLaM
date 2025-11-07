#include "listaDoble.h"
#include "../macros.h"
#include <stdlib.h>
#include <string.h>

void crearListaDoble(tListaDoble *p)
{
    *p=NULL;
}

int insertarListaDoble(tListaDoble *p, const void *info, unsigned bytes, cmp comparar)
{
    tNodoD *nue, *actual, *auxAnt, *auxSig;
    actual = *p;
    ///si la lista esta vacia, pongo los 2 punteros a null
    if(actual==NULL)
    {
        auxAnt=NULL;
        auxSig=NULL;
    }
    else
    {
        ///los 2 bucles
        while(actual->sig && comparar(info,actual->info)==DISTINTOS)
            actual=actual->sig;
        while(actual->ant && comparar(actual->info,info)==DISTINTOS)
            actual=actual->ant;
        if(comparar(info,actual->info)==DISTINTOS)
        {
            auxAnt = actual;
            auxSig = actual->sig;
        }
        else
        {
            auxAnt=actual->ant;
            auxSig=actual;
        }
    }
    ///creacion de nodo
    nue = (tNodoD*)malloc(sizeof(tNodoD));
    if(!nue)
        return SIN_MEMORIA;
    nue->info=malloc(bytes);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEMORIA;
    }
    ///dar valores a los campos del nuevo nodo
    memcpy(nue->info,info,bytes);
    nue->tam=bytes;
    nue->ant=auxAnt;
    nue->sig=auxSig;
    ///hacer el enganche
    if(auxSig)
        auxSig->ant=nue;
    if(auxAnt)
        auxAnt->sig =nue;
    *p=nue;
    return TODO_OK;
}

int listaDobleVacia(const tListaDoble *p)
{
    return *p==NULL ? VACIA : NO_VACIA;
}

int listaDobleLlena(const tListaDoble *p, unsigned bytes)
{
    tNodoD *aux = (tNodoD*)malloc(sizeof(tNodoD));
    if(!aux)
        return LLENA;
    aux->info = malloc(bytes);
    if(!aux->info)
    {
        free(aux);
        return LLENA;
    }
    free(aux->info);
    free(aux);
    return NO_LLENA;
}

void mapIzq(tListaDoble *p, void accion(void*))
{
    while(*p)
    {
        accion((*p)->info);
        p=&(*p)->ant;
    }
}
void mapDer(tListaDoble *p, void accion(void*))
{
    while(*p)
    {
        accion((*p)->info);
        p=&(*p)->sig;
    }
}
///DEPURAR MAP FINAL Y MAP PRINCIPIO, VISUALIZAR FUNCIONAMIENTO
void mapFinal(tListaDoble *p, void accion(void*))
{
    while((*p)->sig)
        p=&(*p)->sig;
    while(*p)
    {
        accion((*p)->info);
        p=&(*p)->ant;
    }
}

void mapInicio(tListaDoble *p, void accion(void*))
{
    while((*p)->ant)
        p=&(*p)->ant;
    while(*p)
    {
        accion((*p)->info);
        p=&(*p)->sig;
    }
}

void filter(tListaDoble *p, const void *clave ,int filtro(const void*,const void*))
{
    tNodoD *pe;
    tNodoD *aux;
    while((*p)->ant)
        *p=(*p)->ant;
    pe=*p;
    while(pe)
    {
        while(pe && filtro(pe->info,clave)==TODO_OK){
            aux=pe;
            pe=aux->sig;
            pe->ant=aux->ant;
            free(aux->info);
            free(aux);
        }
        *p=pe;
        if(pe)
            pe=pe->sig;
    }
}

void reduce(const tListaDoble *p, void *r, reduccion red)
{
    while((*p)->ant)
        p=&(*p)->ant;
    while(*p)
    {
        red((*p)->info,r);
        p=&(*p)->sig;
    }
}

///DEPURAR ESTO
int buscarValor(const tListaDoble *p, const void *clave ,void *info, unsigned bytes, cmp comparar)
{
    tNodoD *actual=*p;
    if(!actual)
        return VACIA;
    while(actual->sig && comparar(clave,actual->info)==DISTINTOS)
        actual=actual->sig;
    while(actual->ant && comparar(actual->info,clave)==DISTINTOS)
        actual=actual->ant;
    if(comparar(clave,actual->info)==IGUALES)
    {
        memcpy(info,actual->info,MIN(actual->tam,bytes));
        return EXISTE;
    }
    return NO_EXISTE;
}

void vaciarListaDoble(tListaDoble *p)
{
    tNodoD *aux;
    while((*p)->ant)
        *p=(*p)->ant;
    while(*p)
    {
        aux=*p;
        *p=(*p)->sig;
        free(aux->info);
        free(aux);
    }
}
