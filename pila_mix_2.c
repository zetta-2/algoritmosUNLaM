#include "pila_mix_2.h"
#include "private.h"
#include "macros.h"
#include <stdlib.h>
#include <string.h>

int crearPilaVer2(tPilaVer2 *pila)
{
    pila->pila=malloc(TAM_PILA);
    if(!pila->pila)
        return 0;
    pila->capacidad=TAM_PILA;
    pila->tope=0;
    return 1;
}

int apilarVer2(tPilaVer2 *pila, const void *clave, size_t tam_dato)
{
    unsigned int tam_min=tam_dato+sizeof(unsigned int);
    if(pila->capacidad-pila->tope<tam_min)
    {
        if(!_resize_2(pila,tam_min))
            return 0;
    }
    memcpy(pila->pila+pila->tope,clave,tam_dato);
    pila->tope+=tam_dato;
    memcpy(pila->pila+pila->tope,&tam_dato,sizeof(unsigned int));
    pila->tope+=sizeof(unsigned int);
    return 1;
}

int verTopeVer2(tPilaVer2 *pila, void *valor, size_t tam_dato)
{
    unsigned int tamEnPila;
    if(pila->tope==0)
        return 0;
    memcpy(&tamEnPila,pila->pila+pila->tope-sizeof(unsigned int),sizeof(unsigned int));
    memcpy(valor,pila->pila+pila->tope-sizeof(unsigned int)-tamEnPila,MIN(tamEnPila,tam_dato));
    return 1;
}

int desapilarVer2(tPilaVer2 *pila, void *valor, size_t tam_dato)
{
    unsigned tam_enPila;//tamanio en la pila
    if(pila->tope==0)
        return 0;
    memcpy(&tam_enPila,pila->pila+pila->tope-sizeof(unsigned int),sizeof(unsigned int));
    pila->tope-=sizeof(unsigned int);
    memcpy(valor,pila->pila+pila->tope-tam_enPila,MIN(tam_enPila,tam_dato));//el ultimo sumando del 2do parametro es para no hacer la suma-resta del tope
    ///en el ultimo parametro si el tamanio del dato en la pila es mas grande que el tam que se pretende guardar, se saca el tam mas chico
    pila->tope-=tam_enPila;
    return 1;
}

int pilaLlenaVer2(tPilaVer2 *pila, size_t tam_dato)
{
    return pila->capacidad-pila->tope<tam_dato+sizeof(unsigned int);
}
int pilaVaciaVer2(tPilaVer2 *pila)
{
    return pila->tope==0;
}

int vaciarPilaVer2(tPilaVer2 *pila)//vaciar pila
{
    pila->capacidad=0;
    pila->tope=0;
    free(pila->pila);
    return 1;
}
