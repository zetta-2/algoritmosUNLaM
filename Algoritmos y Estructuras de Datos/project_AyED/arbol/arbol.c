#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void crearArbolBin(tArbol *raiz)
{
    *raiz = NULL;
}

int insertarEnArbolBinRecursivo(tArbol *raiz, const void *info, unsigned bytes, cmp comparacion, accionDuplicado funcion)
{
    tNodoArbol *nue;
    int compare;
    if(*raiz==NULL)
    {
        nue = (tNodoArbol*)malloc(sizeof(tNodoArbol));
        if(!nue)
            return LLENA;
        nue->info=malloc(bytes);
        if(!nue->info)
        {
            free(nue);
            return LLENA;
        }
        memcpy(nue->info,info,bytes);
        nue->tam=bytes;
        nue->izq=NULL;
        nue->der=NULL;
        *raiz=nue;
        return TODO_OK;
    }
    compare=comparacion(info,(*raiz)->info);
    if(compare<0)
        return insertarEnArbolBin(&(*raiz)->izq,info,bytes,comparacion,funcion);
    if(compare>0)
        return insertarEnArbolBin(&(*raiz)->der,info,bytes,comparacion,funcion);
    return funcion((*raiz)->info,info);
}

int insertarEnArbolBin(tArbol *raiz, const void *info, unsigned bytes, cmp comparacion, accionDuplicado funcion)
{
    tNodoArbol *nue;
    int compare;
    while(*raiz){
        compare=comparacion(info,(*raiz)->info);
        if(compare==0)
            return funcion((*raiz)->info,info);
        if(compare<0)
            raiz = &(*raiz)->izq;
        else
            raiz = &(*raiz)->der;
    }
    nue = (tNodoArbol*)malloc(sizeof(tNodoArbol));
    if(!nue)
        return LLENA;
    nue->info=malloc(bytes);
    if(!nue->info)
    {
        free(nue);
        return LLENA;
    }
    memcpy(nue->info,info,bytes);
    nue->tam=bytes;
    nue->izq=NULL;
    nue->der=NULL;
    *raiz=nue;
    return TODO_OK;
}

int recorrerArbolBinPreorden(tArbol *raiz, accion funcion)
{
    if(*raiz){
        funcion((*raiz)->info);
        recorrerArbolBinPreorden(&(*raiz)->izq,funcion);
        recorrerArbolBinPreorden(&(*raiz)->der,funcion);
    }
    return TODO_OK;
}

int recorrerArbolBinPostorden(tArbol *raiz, accion funcion)
{
    if(*raiz){
        recorrerArbolBinPostorden(&(*raiz)->izq,funcion);
        recorrerArbolBinPostorden(&(*raiz)->der,funcion);
        funcion((*raiz)->info);
    }
    return TODO_OK;
}

int recorrerArbolBinInorden(tArbol *raiz, accion funcion)
{
    if(*raiz){
        recorrerArbolBinInorden(&(*raiz)->izq,funcion);
        funcion((*raiz)->info);
        recorrerArbolBinInorden(&(*raiz)->der,funcion);
    }
    return TODO_OK;
}

void* busquedaBin(tArbol *raiz, void *clave, unsigned bytes, cmp comparacion)
{
    int compare;
    if(*raiz==NULL)
        return NULL;
    compare=comparacion(clave,(*raiz)->info);
    if(compare==0)
    {
        memcpy(clave,(*raiz)->info, MIN(bytes,(*raiz)->tam));
        return clave;
    }
    if(compare>0)
        return busquedaBin(&(*raiz)->der,clave,bytes,comparacion);
    return busquedaBin(&(*raiz)->izq,clave,bytes,comparacion);
}

int arbolVacio(const tArbol *raiz)
{
    return *raiz==NULL ? VACIA : NO_VACIA;
}

int arbolLleno(const tArbol *raiz, unsigned bytes)
{
    tNodoArbol *aux;
    aux = (tNodoArbol*)malloc(sizeof(tNodoArbol));
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

void vaciarArbol(tArbol *raiz)
{
    tNodoArbol *aux;
    if(*raiz)
    {
        vaciarArbol(&(*raiz)->izq);
        vaciarArbol(&(*raiz)->der);
        aux = *raiz;
        *raiz = aux->der;
        free(aux->info);
        free(aux);
    }
}
///ejercicios extras para entregas
int contarHojas(tArbol *raiz)
{
    int hojas=0;
    if(*raiz==NULL)
        return 0;
    if((*raiz)->izq==NULL && (*raiz)->der==NULL)
        return 1;
    hojas+=contarHojas(&(*raiz)->izq);
    return hojas+contarHojas(&(*raiz)->der);
}

int contarNoHojas(tArbol *raiz)
{
    int noHojas=0;
    if(*raiz==NULL)
        return 0;
    if((*raiz)->izq!=NULL || ((*raiz)->der!=NULL))
        noHojas++;
    noHojas+=contarNoHojas(&(*raiz)->izq);
    return noHojas+contarNoHojas(&(*raiz)->der);
}

int contarNodos(tArbol *raiz)
{
    int cantNodos=0;
    if(*raiz==NULL)
        return 0;
    cantNodos++;
    cantNodos+=contarNodos(&(*raiz)->izq);
    return cantNodos+contarNodos(&(*raiz)->der);
}

tNodoArbol* buscarClaveMayor(tArbol *raiz)
{
    if(*raiz==NULL)
        return NULL;
    if((*raiz)->der==NULL)
        return *raiz;
    return buscarClaveMayor(&(*raiz)->der);
}

tNodoArbol* buscarClaveMenor(tArbol *raiz)
{
    if(*raiz==NULL)
        return NULL;
    if((*raiz)->izq==NULL)
        return *raiz;
    return buscarClaveMenor(&(*raiz)->izq);
}

int recorrerSubarbolDer(tArbol *raiz, condicion funcion)
{
    if(*raiz==NULL)
        return VACIA;
    return _accionSubarbolDer(&(*raiz)->der,funcion);
}

int _accionSubarbolDer(tArbol *raiz,condicion funcion)
{
    int condicionCumplida=0;
    if(*raiz==NULL)
        return 0;
    condicionCumplida+=funcion((*raiz)->info);
    condicionCumplida+=_accionSubarbolDer(&(*raiz)->izq,funcion);
    return condicionCumplida+_accionSubarbolDer(&(*raiz)->der,funcion);
}

int contarNodosPorClave(tArbol *raiz, const void *clave, int fnc(void*,const void*))
{
    int cantidad=0;
    if(*raiz==NULL)
        return 0;
    cantidad+=fnc((*raiz)->info,clave);
    cantidad+=contarNodosPorClave(&(*raiz)->izq,clave,fnc);
    return cantidad+contarNodosPorClave(&(*raiz)->der,clave,fnc);
}

float promedioConClavePar(tArbol *raiz, tPromedio *p ,void promedio(void*,tPromedio*))
{
    if(*raiz==NULL)
        return 0;
    promedio((*raiz)->info,p);
    promedioConClavePar(&(*raiz)->izq,p,promedio);
    promedioConClavePar(&(*raiz)->der,p,promedio);
    if(p->cantidad)
        return (float)p->suma/p->cantidad;
    return 0;
}


///pendiete de revision, idem el de contar por no clave
int buscarPorNoClave(tArbol *raiz, void *noClave, unsigned bytes, int algo(void *,const void*))
{
    if(*raiz==NULL)
        return 0;
    if(algo((*raiz)->info,noClave))
    {
        memcpy(noClave,(*raiz)->info,MIN(bytes,(*raiz)->tam));
        return TODO_OK;
    }
    if((*raiz)->izq && (*raiz)->der==NULL)
        return buscarPorNoClave(&(*raiz)->izq,noClave,bytes,algo);
    if((*raiz)->izq==NULL && (*raiz)->der)
        return buscarPorNoClave(&(*raiz)->izq,noClave,bytes,algo);
    return 0;
}

///////////////////////////////////////////////////////////////
///no hace falta los +=, las asignaciones son para evitar llamadas en el retorno
int alturaArbol(tArbol *raiz)
{
    int hi = 0, hd = 0;
    if(*raiz==NULL)
        return 0;
    hi = alturaArbol(&(*raiz)->izq);
    hd = alturaArbol(&(*raiz)->der);
    return MAX(hi+1,hd+1);
}

int nivelArbol(tArbol *raiz)
{
    int hi = 0, hd = 0;
    if(*raiz==NULL)
        return -1;
    hi = nivelArbol(&(*raiz)->izq);
    hd = nivelArbol(&(*raiz)->der);
    return (hi>hd) ? hi+1 : hd+1;
}

int recorrerHastaNivel(tArbol *raiz, int nivel,void accion(void*))
{
    if(*raiz==NULL || nivel==-1)
        return TODO_OK;
    accion((*raiz)->info);
    recorrerHastaNivel(&(*raiz)->izq,nivel-1,accion);
    return recorrerHastaNivel(&(*raiz)->der,nivel-1,accion);
}

int recorrerNivel(tArbol *raiz, int nivel, void accion(void*))
{
    if(*raiz==NULL)
        return TODO_OK;
    if(nivel==0)
    {
        accion((*raiz)->info);
        return TODO_OK;
    }
    recorrerNivel(&(*raiz)->izq,nivel-1,accion);
    return recorrerNivel(&(*raiz)->der,nivel-1,accion);
}


///revisar si se puede sin la variable actual
int recorrerDesdeNivel(tArbol *raiz, int nivel, void accion(void*))
{
    if(*raiz==NULL)
        return TODO_OK;
    if(nivel<=0)
        accion((*raiz)->info);
    recorrerDesdeNivel(&(*raiz)->izq,nivel-1,accion);
    return recorrerDesdeNivel(&(*raiz)->der,nivel-1,accion);
}

///////////////////////////////////////////////////////////////
int esArbolBinCompleto(tArbol *raiz)
{
    int nodosArbol = contarNodos(raiz);
    int potencia = pow(2,alturaArbol(raiz))-1;
    return nodosArbol == potencia ? COMPLETO : NO_COMPLETO;
}

int esArbolBinBalanceado(tArbol *raiz, int nivel)
{
    if(*raiz==NULL)
        return BALANCEADO;
    if(nivel)
    {
        esArbolBinBalanceado(&(*raiz)->izq,nivel-1);
        esArbolBinBalanceado(&(*raiz)->der,nivel-1);
    }
    else if((*raiz)->izq || (*raiz)->der)
        return NO_BALANCEADO;
    return BALANCEADO;
}

int esAVL(tArbol *raiz)
{
    int altIzq;
    int altDer;
    if(*raiz==NULL)
        return AVL;
    altIzq = alturaArbol(&(*raiz)->izq);
    altDer = alturaArbol(&(*raiz)->der);
    if(abs(altIzq-altDer)>1)
        return NO_AVL;
    return AVL;
}

int eliminarNodo(tArbol *raiz, void *clave, unsigned bytes, int cmp(const void*,const void*))
{
    int comparacion;
    tNodoArbol *aux;
    if(*raiz==NULL)
        return ERROR;
    comparacion = cmp(clave,(*raiz)->info);
    if(comparacion==0)
    {
        if((*raiz)->izq==NULL && (*raiz)->der==NULL)
        {
            memcpy(clave,(*raiz)->info,MIN(bytes,(*raiz)->tam));
            aux=*raiz;
            *raiz=aux->der;
            free(aux->info);
            free(aux);
            return TODO_OK;
        }
        else
            return eliminarRaiz(raiz,clave,bytes);
    }
    if(comparacion>0)
        return eliminarNodo(&(*raiz)->der,clave,bytes,cmp);
    return eliminarNodo(&(*raiz)->izq,clave,bytes,cmp);
}

int eliminarRaiz(tArbol* raiz, void *clave, unsigned bytes)
{
    tArbol *p;
    tNodoArbol *nodo;
    int hi = nivelArbol(&(*raiz)->izq);
    int hd = nivelArbol(&(*raiz)->der);
    if(hi>hd)
    {
        p = &(*raiz)->izq;
        while((*p)->der)
            p=&(*p)->der;
    }
    else
    {
        p = &(*raiz)->der;
        while((*p)->izq)
            p=&(*p)->izq;
    }
    nodo=*p;
    memcpy(clave,nodo->info,MIN(nodo->tam,bytes));
    if(nodo->izq)
        *p=nodo->izq;
    else
        *p=nodo->der;
    memcpy((*raiz)->info,nodo->info,MIN(nodo->tam,bytes));
    free(nodo->info);
    free(nodo);
    return TODO_OK;
}
///----------------------------indices----------------------------------------------------------
int indexarArchBin(const char *arch, unsigned bytes,tArbol *arbol,void copia(void*,void*),int cmp(const void*,const void*))
{
    FILE *p_arch;
    tIndice index;
    void *buffer;
    ///INICIALIZACION DE LO NECESARIO
    p_arch=fopen(arch,"rb");
    if(!p_arch)
        return 0;
    buffer=malloc(bytes);
    if(!buffer)
    {
        fclose(p_arch);
        return 0;
    }
    ///INICIO DE LA LOGICA
    fread(buffer,bytes,1,p_arch);
    index.ubicacion=0;
    while(!feof(p_arch))
    {
        copia(&index.clave,buffer);
        insertarEnArbolBin(arbol,&index,sizeof(index),cmp,sinDuplicados);
        index.ubicacion++;
        fread(buffer,bytes,1,p_arch);
    }
    fclose(p_arch);
    free(buffer);
    return TODO_OK;
}

int crearIndice(const char *arch, tArbol *raiz)
{
    FILE *indice;
    indice = fopen(arch,"wb");
    if(!indice)
        return 0;
    _escribirIndice(indice, raiz);
    fclose(indice);
    return 1;
}

void _escribirIndice(FILE *indice, tArbol *raiz)
{
    if(*raiz)
    {
        _escribirIndice(indice, &(*raiz)->izq);
        fwrite((*raiz)->info,(*raiz)->tam,1,indice);
        _escribirIndice(indice, &(*raiz)->der);
    }
}

void mostrarIndice(void *info)
{
    tIndice *p= (tIndice*)info;
    printf("%-5c %-5d\n",p->clave, p->ubicacion);
}

void copiarClaveApellidoClientes(void *key, void *buffer)
{
    tClientesSimple *p=(tClientesSimple*)buffer;
    tIndice *p_index = (tIndice*)key;
    p_index->clave=p->apellido;
}

int levantarIndice(tArbol *arbol, const char *nom_arch)
{
    void *buffer;
    FILE *p_arch=fopen(nom_arch,"rb");
    int ce;
    int inicio=0;
    if(!p_arch)
        return 0;
    buffer=malloc(sizeof(tIndice));
    if(!buffer)
    {
        fclose(p_arch);
        return 0;
    }
    fseek(p_arch,0,SEEK_END);
    ce = ftell(p_arch)/sizeof(tIndice);
    procesarIndice(p_arch,arbol,buffer,inicio,ce);
    fclose(p_arch);
    free(buffer);
    return TODO_OK;
}

void procesarIndice(FILE *index, tArbol *raiz, void *buffer, int ini, int fin)
{
    int pmedio;
    if(ini>fin)
        return;
    rewind(index);
    pmedio = (ini + fin)/2;
    fseek(index,pmedio*sizeof(tIndice),SEEK_CUR);
    fread(buffer,sizeof(tIndice),1,index);
    insertarEnArbolBinRecursivo(raiz,buffer,sizeof(tIndice),cmpApellidosIndex,sinDuplicados);
    procesarIndice(index,raiz,buffer,ini,pmedio-1);
    procesarIndice(index,raiz,buffer,pmedio+1,fin);
}

///*plantear busqueda binaria
///*pensar en la utilidad de los 3 recorridos
