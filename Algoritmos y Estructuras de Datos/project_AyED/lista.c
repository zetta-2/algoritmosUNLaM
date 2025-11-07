#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void crearLista(tLista *p)
{
    *p=NULL;
}

int insertarAlPrincipio(tLista *p, const void *info, unsigned bytes)
{
    ///se comporta igual que una pila (de la pila)
    tNodo *nue;
    nue=(tNodo*)malloc(sizeof(tNodo));
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
    nue->sig = *p;
    *p = nue;
    return 1;
}

int insertarAlFinal(tLista *p, const void *info, unsigned bytes)
{
    ///se comporta igual que una cola?
    tNodo *nue;
    while(*p)
        p=&(*p)->sig;
    nue=(tNodo*)malloc(sizeof(tNodo));
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
    nue->sig=NULL;
    *p=nue;//al contenido de p le ponemos el nodo creado
    return TODO_OK;
}

int insertarAlMedio(tLista *p, const void *info, unsigned bytes, int pos)
{
    tNodo *nue;
    int i = 0;
    while(*p && i<pos)
    {
        p = &(*p)->sig;
        i++;
    }
    nue=(tNodo*)malloc(sizeof(tNodo));
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
    nue->sig=*p;
    *p=nue;
    return i != pos ? TODO_OK : INSERCION_SUCIA;
}

int insertarOrdenado(tLista *p, const void *info, unsigned bytes, int orden(const void*,const void*),
                     int duplicado, int accionDuplicado(void*,const void*)){
    tNodo *nue;
    int comparacion = DISTINTOS;
    while(*p && (comparacion = orden((*p)->info,info))==DISTINTOS)
        p = &(*p)->sig;
    ///preguntas si hay duplicados, realizar alguna accion
    if(duplicado == SIN_DUPLICADO && comparacion == IGUALES)
        return accionDuplicado((*p)->info,info);

    nue=(tNodo*)malloc(sizeof(tNodo));
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
    nue->sig=*p;
    *p=nue;
    return TODO_OK;
}

int ordenarLista(tLista *p, int cmp(const void*,const void*))
{
    tNodo *nodoDesenganchado;
    tLista *extremo;
    if(*p==NULL)
        return VACIA;
    while((*p)->sig)
    {
        extremo=buscarExtremo(p,cmp);
        if(extremo!=p)
        {
            nodoDesenganchado=*extremo;
            *extremo = nodoDesenganchado->sig;
            nodoDesenganchado->sig = *p;
            *p = nodoDesenganchado;
        }
        p = &(*p)->sig;
    }
    return TODO_OK;
}

tLista* buscarExtremo(tLista *p, cmp comparacion)
{
    tLista *aux = p;
    while((*p)->sig)
    {
        if(comparacion((*p)->sig->info,(*aux)->info)==DISTINTOS)
            aux=&(*p)->sig;
        p=&(*p)->sig;
    }
    return aux;
}

void recorrerLista(tLista *p, void accion(void*))
{
    while(*p)
    {
        accion((*p)->info);
        p=&(*p)->sig;
    }
}

int listaLlena(const tLista *p, unsigned bytes)
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

int listaVacia(const tLista *p)
{
    return NULL==*p ? VACIA : NO_VACIA;
}

void vaciarLista(tLista *p)
{
    tNodo *aux;
    while(*p)
    {
        aux = *p;
        *p=(*p)->sig;
        free(aux->info);
        free(aux);
    }
}
