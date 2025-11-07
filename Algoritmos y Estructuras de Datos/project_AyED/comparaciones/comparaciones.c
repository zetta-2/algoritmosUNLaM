#include "comparaciones.h"

int cmpEnteros(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int cmpCaracteres(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

int cmpFlotantes(const void *a, const void *b)
{
    return *(float*)a - *(float*)b;
}

int cmpApellidosIndex(const void *a, const void *b)
{
    tIndice *p1 = (tIndice*)a;
    tIndice *p2 = (tIndice*)b;
    return p1->clave - p2->clave;
}

int cmpNombreIndex(const void *a, const void *b)
{
    tIndicePlayer *p1 = (tIndicePlayer*)a;
    tIndicePlayer *p2 = (tIndicePlayer*)b;
    return strcmpi(p1->clave,p2->clave);
}
