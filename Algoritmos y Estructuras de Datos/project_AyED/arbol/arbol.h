#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "../macros.h"
#include "../pruebas.h"
#include <stdio.h>

typedef struct aNodo{
    void *info;
    unsigned tam;
    struct aNodo *izq;
    struct aNodo *der;
}tNodoArbol;

///ejemplos con indice
typedef struct{
    char clave;
    int ubicacion;
}tIndice;

typedef struct{
    char clave[512];
    int ubicacion;
}tIndicePlayer;

typedef struct
{
    int DNI;
    char nombre;
    char apellido;
}tClientesSimple;

typedef void(*copiarIndex) (void*,void*);
typedef tNodoArbol *tArbol;


///funciones clase 1 arbol
void crearArbolBin(tArbol *raiz);
int insertarEnArbolBinRecursivo(tArbol *raiz, const void *info, unsigned bytes, cmp comparacion, accionDuplicado funcion);
int insertarEnArbolBin(tArbol *raiz, const void *info, unsigned bytes, cmp comparacion, accionDuplicado funcion);
int recorrerArbolBinPreorden(tArbol *raiz, accion funcion);
int recorrerArbolBinPostorden(tArbol *raiz, accion funcion);
int recorrerArbolBinInorden(tArbol *raiz, accion funcion);
void* busquedaBin(tArbol *raiz, void *clave, unsigned bytes,cmp comparacion);
int arbolVacio(const tArbol *raiz);
int arbolLleno(const tArbol *raiz, unsigned bytes);
void vaciarArbol(tArbol *raiz);

///ejercicios para la proxima clase

int contarHojas(tArbol *raiz);
int contarNoHojas(tArbol *raiz);
int contarNodos(tArbol *raiz);
tNodoArbol* buscarClaveMayor(tArbol *raiz);
tNodoArbol* buscarClaveMenor(tArbol *raiz);
int recorrerSubarbolDer(tArbol *raiz, condicion funcion);
int _accionSubarbolDer(tArbol *raiz,condicion funcion);
int contarNodosPorClave(tArbol *raiz, const void *clave, int fnc(void*,const void*));
float promedioConClavePar(tArbol *raiz, tPromedio *p ,void promedio(void*,tPromedio*));
///pendiente de revision
int buscarPorNoClave(tArbol *raiz, void *noClave, unsigned bytes, int algo(void *,const void*));

///actividades de la 2da clase arbol
int alturaArbol(tArbol *raiz);
int nivelArbol(tArbol *raiz);
int recorrerHastaNivel(tArbol *raiz, int nivel, void accion(void*));
int recorrerNivel(tArbol *raiz, int nivel, void accion(void*));
int recorrerDesdeNivel(tArbol *raiz, int nivel, void accion(void*));
int esArbolBinCompleto(tArbol *raiz);
int esArbolBinCompletoHastaNivel(tArbol *raiz, int nivel);
///FUNCIONES PENDIENTES
int esArbolBinBalanceado(tArbol *raiz, int nivel);
int esAVL(tArbol *raiz);
///
int eliminarNodo(tArbol *raiz, void *clave, unsigned bytes,int cmp(const void*,const void*));
int eliminarRaiz(tArbol* raiz, void *clave,unsigned bytes);


///Indices
void MostrarCliente(void *info);
void mostrarIndice(void *info);

int indexarArchBin(const char *arch, unsigned bytes,tArbol *arbol,void copia(void*,void*),int cmp(const void*,const void*));
int crearIndice(const char *arch, tArbol *raiz);
void _escribirIndice(FILE *indice, tArbol *raiz);
void copiarClaveApellidoClientes(void *key, void *buffer);
int levantarIndice(tArbol *arbol, const char *nom_arch);
void procesarIndice(FILE *index, tArbol *raiz, void *buffer, int ini, int fin);


///queda pendiente crear un arbol balanceado a partir de un indice
#endif // ARBOL_H_INCLUDED
