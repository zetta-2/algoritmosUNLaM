#include "private.h"
#include <stdlib.h>
#include <string.h>
#define INCREMENTO 2

///redimension de la pila
int _resize_2(tPilaVer2 *pila, unsigned tam_adicional)
{
    unsigned int new_tamanio = pila->capacidad*INCREMENTO+tam_adicional;
    void *aux = realloc(pila->pila,new_tamanio);
    if(!aux)
        return 0;
    pila->pila=aux;
    pila->capacidad=new_tamanio;
    return 1;
}
