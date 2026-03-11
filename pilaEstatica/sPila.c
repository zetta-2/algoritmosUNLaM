#include "sPila.h"
#include <string.h>

void crearPila(tPila *pila)
{
    pila->tope = TAM_PILA;
}

int apilar(tPila *pila, const void *valor, unsigned tam_dato)
{
    if(pila->tope < (tam_dato + sizeof(unsigned int)) ) ///tam dato + tam de la cantidad de bytes a ocupar (segun la arquitectura)
        return 0;
    pila->tope-=tam_dato;
    memcpy(pila->pila+pila->tope,valor,tam_dato);
    pila->tope-=sizeof(unsigned int);
    memcpy(pila->pila+pila->tope,&tam_dato,sizeof(unsigned int));
    return 1;
}

int verTope(tPila *pila, void *valor, unsigned tam_dato)
{
    unsigned tam_enPila;
    if(pila->tope==TAM_PILA) //si es igual significa que no insertamos nada
        return 0;
    memcpy(&tam_enPila, pila->pila + pila->tope, sizeof(unsigned int)); //guardar el tamanio del dato en la pila
    //pila->tope+=sizeof(unsigned int); ir
    memcpy(valor,pila->pila+pila->tope+sizeof(unsigned int),MIN(tam_enPila,tam_dato)); //el ultimo sumando del 2do parametro es para no hacer la suma-resta del tope
    //en el ultimo parametro si el tamanio del dato en la pila es mas grande que el tam que se pretende guardar, se saca el tam mas chico
    //pila->tope-=sizeof(unsigned int); //volver
    return 1;
}

int desapilar(tPila *pila, void *valor, unsigned tam_dato)
{
    unsigned tam_enPila;//tamanio en la pila
    if(pila->tope==TAM_PILA)
        return 0;
    memcpy(&tam_enPila,pila->pila+pila->tope,sizeof(unsigned int));
    pila->tope+=sizeof(unsigned int);
    memcpy(valor,pila->pila+pila->tope+sizeof(unsigned int),MIN(tam_enPila,tam_dato));//el ultimo sumando del 2do parametro es para no hacer la suma-resta del tope
    ///en el ultimo parametro si el tamanio del dato en la pila es mas grande que el tam que se pretende guardar, se saca el tam mas chico
    pila->tope+=tam_enPila;
    return 1;
}

void vaciarPila(tPila *pila)
{
    pila->tope = TAM_PILA;
}

int pilaLlena(tPila *pila, unsigned tam_dato) ///dependera de lo que queramos insertar
{
    return pila->tope < tam_dato + sizeof(unsigned int);
}

int pilaVacia(tPila *pila)
{
    return pila->tope==TAM_PILA;
}
