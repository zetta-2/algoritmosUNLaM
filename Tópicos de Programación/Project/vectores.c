#include <stdio.h>
///Todas las funciones se trabajan con numeros enteros

void MostrarVector(int *vec, int ce)
{
    int i;
    printf("[ ");
    for(i=0;i<ce;i++)
    {
        printf("%d ", *vec);
        vec++;
    }
    printf("]\n");
}

///la de abajo es un memset para numeros enteros
void Inicializar_Vector(int *vec, int ce, int valor)
{
    int i;
    for(i=0;i<ce;i++)
    {
        *vec = valor;
        vec++;
    }
}

int Insertar_Por_Pos(int *vec, int *ce, int valor, int pos, unsigned tam_max)
{
    int *p_fin = vec + *(ce);
    int *p_pos = vec + pos;
    if(*ce == tam_max)
        p_fin--;
    if( (pos>*ce && *ce != tam_max) )
    {
        (*ce)++;
        *p_fin = valor;
        return 0;
    }
    while(p_fin>p_pos){
        *p_fin=*(p_fin-1);
        p_fin--;
    }
    *p_fin = valor;
    if(*ce != tam_max)
        (*ce)++;
    return ( pos<*ce || (pos<=*ce && *ce != tam_max)) ? 1 : 0;
    /*
    if(pos<*ce || (pos<=*ce && *ce != tam_max))
        return 1;
    return 0;
    */
}

int Insertar_Ordenadamente(int *vec, int *ce, int valor, unsigned capacidad_max)
{
    int *ini = vec;//primera direccion del vector
    vec = vec + *ce;
    if(*ce == capacidad_max){
        vec--; // con esta asignacion, evito salirme de mi espacio de memoria
        if(valor > *vec)
            return 0;//retorno temprano
    }
    while(ini<vec && valor<*(vec-1)){
        *vec = *(vec-1);
        vec--;
    }
    *vec = valor;
    if(*ce != capacidad_max)
        (*ce)++;
    return 1;
}

int Eliminar_aparicion_por_pos(int *pvec, int *ce, int pos)
{
    int *pini = pvec + pos;
    int *p_escritura;
    int aux;
    if(pos<0 || pos>=*ce)
        return 0;
    pvec = pvec + *ce - 1;
    p_escritura = pvec;
    while(pvec>pini)
    {
        aux = *(pvec-1);
        *(pvec-1) = *p_escritura;
        *p_escritura = aux;
        pvec--;
    }
    (*ce)--;
    return 1;
}

int Eliminar_primera_aparicion(int *pvec, int *ce, int valor)
{
    int *p_lectura = pvec;
    int *p_escritura;
    int *p_fin = pvec + *ce - 1;
    if(*ce==0)
        return 0;
    while(p_lectura < p_fin && *p_lectura!=valor)
        p_lectura++;
    p_escritura = p_lectura;
    if(*p_lectura != valor)
        return 0;
    while(p_escritura<p_fin)
    {
        *p_escritura = *(p_escritura+1);
        p_escritura++;
    }
    (*ce)--;
    return 1;
}

int Eliminar_TODAS_apariciones(int *pvec, int *ce, int valor)
{
    int *p_lectura = pvec;
    int *p_escritura = pvec;
    int *p_fin = pvec;
    int ce_ini = *ce;
    if(*ce!=0)
        p_fin+= *ce - 1;
    while(p_lectura<=p_fin)
    {
        if(*p_lectura == valor){
                p_lectura++;
                (*ce)--;
        }
        else{
            if(*p_escritura != *p_lectura)
                *p_escritura = *p_lectura;
            p_lectura++;
            p_escritura++;
        }
    }
    if(ce_ini == *ce)
        return 0;
    return 1;
}

int BuscarValor(int *pvec, int ce, int valor)
{
    int pos = 0;
    while(pos<ce && *pvec!=valor)
    {
        pos++;
        pvec++;
    }
    return ce!=pos ? pos : -1;
}
