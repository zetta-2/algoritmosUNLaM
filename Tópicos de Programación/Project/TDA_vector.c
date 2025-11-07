#include "utilidades.h"
#include <stdlib.h>
#include "TDA_vector.h"
#include "genericos.h"
#include <string.h>

int TDA_Crear_vector(TDA_vector *v, unsigned tamanio)
{
    (v->vec) = malloc(TAM_MAX*tamanio);
    if(!v->vec)
        return 0;
    v->ce = 0;
    v->tamanio = tamanio;
    v->tam_max = TAM_MAX;
    return 1;
}

int TDA_InsertarOrdenado(TDA_vector *v, void *valor, int Comparar(const void*,const void*))
{
    void *ini;//primera direccion del vector
    void *fin;
    if(v->ce == v->tam_max){
        if(!TDA_Duplicar_tamanio(v))
        {
            fin = (v->vec) + (v->tamanio*v->ce) - (v->tamanio);
            if(!Comparar(valor,fin))
                return 0;
        }
    }
    ini = v->vec;
    fin = v->vec + (v->ce)*v->tamanio;
    while(ini<fin && Comparar(valor, (fin - (v->tamanio) ) ))
    {
        memcpy(fin, ( fin - v->tamanio ), v->tamanio);
        fin-=v->tamanio;
    }
    memcpy( fin , valor , (v->tamanio) );
    (v->ce)++;
    return 1;
}

//INSERTAR ELEMENTOS EN UN TDA VECTOR
int TDA_Insertar_al_final(TDA_vector *v, void *valor)
{
    void *pos;
    if(v->ce==v->tam_max)
    {
        if(!TDA_Duplicar_tamanio(v))
            return 0;
    }
    pos = v->vec + (v->ce)*(v->tamanio);
    memcpy(pos,valor,v->tamanio);
    (v->ce)++;
    return 1;
}

int TDA_bsearch(TDA_vector *v, void *clave, int cmp(const void*,const void*))
{
    void *p_p_medio;
    void *p_v = v->vec;
    int ce_interna = v->ce;
    int p_medio;
    int resu;
    while(ce_interna)
    {
        p_medio = ce_interna/2;
        p_p_medio = p_v + v->tamanio*p_medio;
        resu = cmp(clave,p_p_medio);
        if(resu==0)
        {
            memcpy(clave,p_p_medio,v->tamanio);
            return 1;
        }
        if(resu<0)
            ce_interna = p_medio;
        else
        {
            ce_interna = ce_interna-p_medio-1;
            p_v = p_p_medio + v->tamanio;
        }
    }
    return 0;
}

int TDA_bSeq(TDA_vector *v, void *clave, int cmp(const void*,const void*))
{
    void *p_vec = v->vec;
    int i;
    for(i=0;i<v->ce;i++)
    {
        if(cmp(clave,p_vec)==0)
        {
            memcpy(clave,p_vec,v->tamanio);
            return 1;
        }
        p_vec+=v->tamanio;
    }
    return 0;
}

int TDA_Vector_lleno(TDA_vector *v)
{
    return (v->ce==v->tam_max) ? 1 : 0;
}

int TDA_Vector_vacio(TDA_vector *v)
{
    return (v->ce==0) ? 1 : 0;
}

int TDA_ce(TDA_vector *v)
{
    return v->ce;
}

void* TDA_map(TDA_vector *v, void Accion(void*))
{
    void *ini = v->vec;
    int i;
    for(i=0;i<v->ce;i++)
    {
        Accion(v->vec);
        v->vec+=v->tamanio;
    }
    v->vec = ini;
    return ini;
}

int TDA_Destruir_vector(TDA_vector *v)
{
    v->ce=0;
    v->tamanio = 0;
    v->tam_max = 0;
    free(v->vec);
    return 1;
}

int TDA_Duplicar_tamanio(TDA_vector *v)///resize
{
    void *temporario = malloc(2*(v->tamanio*v->tam_max));
    if(!temporario)
        return 0;
    m_memcpy(temporario,v->vec,v->tamanio*v->ce);
    free(v->vec);
    v->vec = temporario;
    v->tam_max+=v->tam_max;
    return 1;
}

///FIJAR LA DIR INICIAL AL INICIAR EL ALGORITMO DE ORDENAMIENTO
void TDA_sort(TDA_vector *buffer, int comparar(const void*, const void*))
{
    int i;
    void *ini = buffer->vec;
    void *clave;
    for(i=0;i<(buffer->ce-1);i++)
    {
        clave = TDA_BuscarExtremo(buffer,buffer->ce-i-1,comparar);
        if(clave!=buffer->vec)
            Intercambio_generico(clave,buffer->vec,buffer->tamanio);
        buffer->vec+=buffer->tamanio;
    }
    buffer->vec=ini;
}

void* TDA_BuscarExtremo(TDA_vector *buffer, int ce_real ,int comparar(const void*,const void*))
{
    int i;
    void *p_vec = buffer->vec;
    void *clave = p_vec;
    for(i=0;i<ce_real;i++)
    {
        p_vec+=buffer->tamanio;
        if(!comparar(clave,p_vec))
            clave = p_vec;
    }
    return clave;
}
