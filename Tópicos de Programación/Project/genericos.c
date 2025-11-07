#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "genericos.h"

void Intercambio_generico(void *a, void *b, unsigned tamanio)
{
    char *p_a = (char*)a;
    char *p_b = (char*)b;
    char aux;
    int i;
    for(i=0;i<tamanio;i++)
    {
        aux = *p_a;
        *p_a = *p_b;
        *p_b = aux;
        p_a++;
        p_b++;
    }
}

void* m_memcpy(void *dest, const void *origin, size_t tamanio)
{
    void *ini = dest;
    int i;
    for(i=0;i<tamanio;i++)
    {
        *(char*)dest = *(char*)origin;
        dest++;
        origin++;
    }
    return ini;
}

void* m_memmove(void *dest, const void *origin, size_t tamanio)
{
    void *ini = dest;
    int i;
    char *aux = malloc(tamanio);
    char *p_aux;
    if(!aux)
        return NULL;
    p_aux = aux;
    for(i=0;i<tamanio;i++)
    {
        *aux = *(char*)origin;
        aux++;
        origin++;
    }
    aux = p_aux;
    for(i=0;i<tamanio;i++)
    {
        *(char*)dest = *p_aux;
        p_aux++;
        dest++;
    }
    free(aux);
    return ini;
}


void *copiaCosas(void *elemento, unsigned tam)
{
    char *dest = malloc(tam);
    char *p_dest = dest;
    int i;
    if(!dest)
        return NULL;
    for(i=0;i<tam;i++)
    {
        *dest = *(char*)elemento;
        dest++;
        elemento++;
    }
    //free(dest) ?? si hacemos esto, perdemos el contenido
    return p_dest;
}

void* B_sequence(void *pvec, int ce, void *valor, unsigned tamanio, int cmp(const void*,const void*))
{
    int recorrido = 0;
    while(recorrido<ce && cmp(valor,pvec)!=0)
    {
        recorrido++;
        pvec+=tamanio;
    }
    return recorrido!=ce ? pvec : NULL;
}

void* m_map(void *vec, int ce, unsigned tamanio, void accion(void*))
{
    int i;
    void *ini = vec;
    for(i=0;i<ce;i++)
    {
        accion(vec);
        vec+=tamanio;
    }
    return ini;
}

void* m_filter(void *vec, int *ce, unsigned tamanio ,int f_filtro(const void*))
{
    void *p_lectura = vec;
    void *p_escritura = vec;
    int i, cant_eliminar = 0;
    for(i=0;i<*ce;i++)
    {
        if(f_filtro(p_lectura))//preguntar si se queda el elemento
        {
            if(p_escritura != p_lectura)
                memcpy(p_escritura,p_lectura,tamanio);
            p_escritura+=tamanio;
        }
        else
            cant_eliminar++;//se va
        p_lectura+=tamanio;
    }
    (*ce)-=cant_eliminar;
    return vec;
}

void* m_reduce(void *vec, int ce, unsigned tamanio, void f_reduccion(void*, const void*), void *r)
{
    void *ini = vec;
    int i;
    for(i=0;i<ce;i++){
        f_reduccion(r,vec);
        vec+=tamanio;
    }
    return ini;
}

void S_sort(void *vec, size_t ce, size_t tamanio, int comparar(const void*, const void*))
{
    int i;
    void *p_vec = vec;
    void *clave;
    for(i=0;i<(ce-1);i++)
    {
        clave = BuscarExtremo(p_vec,ce-i-1,tamanio,comparar);
        if(clave!=p_vec)
            Intercambio_generico(clave,p_vec,tamanio);
        p_vec+=tamanio;
    }
}

void* BuscarExtremo(void *vec, size_t ce, size_t tamanio, int comparar(const void*,const void*))
{
    int i;
    void *p_vec = vec;
    void *clave = p_vec;
    for(i=0;i<ce;i++)
    {
        p_vec+=tamanio;
        if(!comparar(clave,p_vec))
            clave = p_vec;
    }
    return clave;
}

void* m_Bsearch(void *valor, const void *vec, size_t ce, size_t tamanio, int Comparar(const void*,const void*))
{
    int p_medio;
    void *p_vec = (void*)vec;
    void *p_p_medio;
    int ce_interna = ce;
    int resu;
    while(ce_interna>0)
    {
        p_medio=ce_interna/2;
        p_p_medio = p_vec+(p_medio*tamanio);
        resu = Comparar(p_p_medio,valor);
        if(resu==0)
            return p_p_medio;
        if(resu>0)
            ce_interna=p_medio;
        else
        {
            //ce_interna=p_medio-((ce+1)%2); ???
            ce_interna = ce_interna-p_medio-1;
            p_vec = p_p_medio+tamanio;
        }
    }
    return NULL;
}
//VERSION GENERICA DE LOS PRIMEROS 5 EJERCICIOS DE ARRAYS
int Insertar_Por_Pos_generico(void *vec, int *ce, void* valor, int pos, unsigned tam_max, unsigned tamanio)
{
    void *p_fin = vec + (*(ce))*tamanio;
    void *p_pos = vec + pos*tamanio;
    if(*ce == tam_max)
        p_fin-=tamanio;
    if( (pos>*ce && *ce != tam_max) )
    {
        (*ce)++;
        memcpy(p_fin,valor,tamanio);
        return 0;
    }
    while(p_fin>p_pos){
        memcpy(p_fin,p_fin-tamanio,tamanio);
        p_fin-=tamanio;
    }
    memcpy(p_fin,valor,tamanio);
    if(*ce != tam_max)
        (*ce)++;
    return ( pos<*ce || (pos<=*ce && *ce != tam_max)) ? 1 : 0;
}


int Insertar_Ordenadamente_generico(void *vec, int *ce, void *valor, unsigned capacidad_max, unsigned tamanio, int Comparar(const void*,const void*))
{
    void *ini = vec;//primera direccion del vector
    vec = vec + (*ce)*tamanio;
    if(capacidad_max==0)
        return 0;
    if(*ce == capacidad_max){
        vec-=tamanio;
        if(!Comparar(valor,vec))
            return 0;
    }
    while(ini<vec && Comparar(valor,vec-tamanio)){
        memcpy(vec,vec-tamanio,tamanio);
        vec-=tamanio;
    }
    memcpy(vec,valor,tamanio);
    if(*ce != capacidad_max)
    {
        (*ce)++;
        return 1;
    }
    return 0;
}

int Eliminar_primera_aparicion_generica(void *pvec, int *ce, void *valor, unsigned tamanio, int Comparar(const void*,const void*))
{
    void *p_lectura = pvec;
    void *p_escritura;
    void *p_fin = pvec + (*ce)*tamanio - tamanio;
    if(*ce==0)
        return 0;
    while(p_lectura < p_fin && !Comparar(p_lectura,valor))
        p_lectura+=tamanio;
    p_escritura = p_lectura;
    if(!Comparar(p_lectura,valor))
        return 0;
    while(p_escritura<p_fin)
    {
        memcpy(p_escritura,p_escritura+tamanio,tamanio);
        p_escritura+=tamanio;
    }
    (*ce)--;
    return 1;
}

int Eliminar_aparicion_por_pos_generico(void *pvec, int *ce, int pos, unsigned tamanio)
{
    void *pini = pvec + pos*tamanio;
    void *p_escritura;
    void *aux = malloc(tamanio);
    if(!aux)
        return 0;
    if(pos<0 || pos>=*ce){
        free(aux);
        return 0;
    }
    pvec = pvec + (*ce)*tamanio - tamanio;
    p_escritura = pvec;
    while(pvec>pini)
    {
        memcpy(aux,pvec-tamanio,tamanio);
        memcpy(pvec-tamanio,p_escritura,tamanio);
        memcpy(p_escritura,aux,tamanio);
        pvec-=tamanio;
    }
    (*ce)--;
    return 1;
}

int Eliminar_TODAS_apariciones_generica(void *pvec, int *ce, void *valor, unsigned tamanio, int Comparar(const void*, const void*))
{
    void *p_lectura = pvec;
    void *p_escritura = pvec;
    void *p_fin = pvec;
    int ce_ini = *ce;
    if(*ce!=0)
        p_fin+= (*ce)*tamanio - tamanio;
    while(p_lectura<=p_fin)
    {
        if(Comparar(p_lectura,valor)){
                p_lectura+=tamanio;
                (*ce)--;
        }
        else{
            if(!Comparar(p_lectura,p_escritura))
                memcpy(p_escritura,p_lectura,tamanio);
            p_lectura+=tamanio;
            p_escritura+=tamanio;
        }
    }
    return (ce_ini != *ce) ? 1: 0;
}

int Insertar_Aprupar_ordenado(void *buffer, void *clave, int *ce, unsigned tamanio, int cap_max,
                              int cmp(const void*,const void*),void Agrupar(void*,const void*),
                              int cmp_ord(const void*,const void*))
{
    void *pos = B_sequence(buffer,*ce,clave,tamanio,cmp);
    if(pos == NULL)
        Insertar_Ordenadamente_generico(buffer,ce,clave,cap_max,tamanio,cmp_ord);
    else
    {
        buffer = pos;
        Agrupar(buffer,clave);
    }
    return 1;

}
