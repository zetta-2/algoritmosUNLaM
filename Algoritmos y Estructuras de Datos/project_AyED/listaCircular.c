#include "listaCircular.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


///implementaciones de pila circular
void crearPilaCircular(tPilaCircular *pila)
{
    *pila=NULL;
}

int apilarCircular(tPilaCircular *pila, const void *info, unsigned bytes)
{
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEMORIA;
    nue->info=malloc(bytes);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEMORIA;
    }
    memcpy(nue->info,info,bytes);
    nue->tamanio=bytes;
    if(*pila==NULL)
    {
        *pila=nue;
        nue->sig=nue;
    }
    else
    {
        nue->sig=(*pila)->sig;
        (*pila)->sig=nue;
    }
    return TODO_OK;
}

int verTopeCircular(tPilaCircular *pila, void *tope, unsigned bytes)
{
    if(*pila==NULL)
        return VACIA;
    memcpy(tope,(*pila)->sig->info,MIN(bytes,(*pila)->sig->tamanio));
    return TODO_OK;
}

int extraerTopeCircular(tPilaCircular *pila, void *tope, unsigned bytes)
{
    tNodo *aux;
    if(*pila==NULL)
        return VACIA;
    aux=(*pila)->sig;
    memcpy(tope,aux->info,MIN(bytes,aux->tamanio));
    if(*pila==aux)
        *pila=NULL;
    else
        (*pila)->sig=aux->sig;
    free(aux->info);
    free(aux);
    return TODO_OK;
}

int pilaCircularVacia(tPilaCircular *pila)
{
    return *pila==NULL ? VACIA : NO_VACIA;
}
int pilaCircularLlena(tPilaCircular *pila, unsigned bytes)
{
    tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
    if(!aux)
        return LLENA;
    aux->info=malloc(bytes);
    if(!aux->info)
    {
        free(aux);
        return LLENA;
    }
    free(aux->info);
    free(aux);
    return NO_LLENA;
}

void vaciarPilaCircular(tPilaCircular *pila)
{
    tNodo *aux;
    while(*pila)
    {
        aux = (*pila)->sig;
        if(*pila==aux)
            *pila=NULL;
        else
            *pila=(*pila)->sig;
        free(aux->info);
        free(aux);
    }
}

///implementaciones de cola circular
void crearColaCircular(tColaCircular *cola)
{
    *cola=NULL;
}

int encolarCircular(tColaCircular *cola, const void *info, unsigned bytes)
{
    tNodo *nue;
    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEMORIA;
    nue->info=malloc(bytes);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEMORIA;
    }
    memcpy(nue->info,info,bytes);
    nue->tamanio=bytes;
    if(*cola==NULL)
        nue->sig=nue;
    else
    {
        nue->sig=(*cola)->sig;
        (*cola)->sig=nue;
    }
    *cola=nue;
    return TODO_OK;
}

int verPrimeroColaCircular(tColaCircular *cola, void *info, unsigned bytes)
{
    if(*cola==NULL)
        return VACIA;
    memcpy(info,(*cola)->sig->info,MIN(bytes,(*cola)->sig->tamanio));
    return TODO_OK;
}

int extraerPrimeroColaCircular(tColaCircular *cola, void *info, unsigned bytes)
{
    tNodo *aux;
    if(*cola==NULL)
        return VACIA;
    aux=(*cola)->sig;
    memcpy(info,aux->info,MIN(bytes,aux->tamanio));
    if(*cola==aux)
        *cola=NULL;
    else
        (*cola)->sig=aux->sig;
    free(aux->info);
    free(aux);
    return TODO_OK;
}

int colaCircularVacia(tColaCircular *cola)
{
    return NULL==*cola ? VACIA : NO_VACIA;
}

int colaCircularLlena(tColaCircular *cola, unsigned bytes)
{
    tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
    if(!aux)
        return LLENA;
    aux->info=malloc(bytes);
    if(!aux->info)
    {
        free(aux);
        return LLENA;
    }
    free(aux->info);
    free(aux);
    return NO_LLENA;
}

void vaciarColaCircular(tColaCircular *cola)
{
    tNodo *aux;
    while(*cola)
    {
        aux=(*cola)->sig;
        if(*cola==aux)
            *cola=NULL;
        else
            (*cola)->sig=aux->sig;
        free(aux->info);
        free(aux);
    }
}
