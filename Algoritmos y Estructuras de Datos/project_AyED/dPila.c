#include "dPila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void d_crearPila(tPila *p)
{
    *p = NULL;//p es un puntero doble
}

int d_Apilar(tPila *p, const void *info, unsigned bytes)
{
    // (1) y (2)
    tNodo *nue= (tNodo*)malloc(sizeof(tNodo));//no poner tNodo*, castear a tNodo* segun la ver. del compiler
    if(!nue)//nue==NULL
        return 0;
    nue->info=malloc(bytes);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }
    // (3)
    memcpy(nue->info,info,bytes);
    nue->tamanio=bytes;
    //nue->sig=NULL; MAL
    // (4)
    nue->sig=*p;//asigno al siguiente lo que tenia en la pila, si no habia nada, era el primero
    // (5)
    *p=nue; //en la pila asigno al elemento insertado (el que esta en la cima)
    //free(nue);
    return 1;
}

int d_VerTope(const tPila *p, void *info, unsigned bytes)
{
    if(*p==NULL)
        return 0;
    memcpy(info,(*p)->info,MIN((*p)->tamanio,bytes));
    return 1;
}

int d_Despilar(tPila *p, void *info, unsigned bytes)
{
    tNodo *aux;
    if(*p==NULL)
        return 0;
    memcpy(info,(*p)->info,MIN((*p)->tamanio,bytes));
    aux=*p;
    *p=(*p)->sig;//puntero doble
    free(aux->info);
    free(aux);
    return 1;
}


int d_PilaLlena(const tPila *p, unsigned bytes)
{
    tNodo *aux;
    if( (aux=(tNodo*)malloc(sizeof(tNodo))) ==NULL)
        return 0;
    if( (aux->info=malloc(bytes)) ==NULL){
        free(aux);
        return 0;
    }
    free(aux->info);
    free(aux);
    return 1;
}

int d_pilaVacia(const tPila *p)
{
    return NULL==*p;
}

void d_VaciarPila(tPila *p)
{
    tNodo *aux;
    while(*p)
    {
        aux = *p;
        *p = (*p)->sig;
        free(aux->info);
        free(aux);
    }
}
