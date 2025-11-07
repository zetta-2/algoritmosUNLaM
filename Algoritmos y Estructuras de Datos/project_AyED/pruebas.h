#ifndef PRUEBAS_H_INCLUDED
#define PRUEBAS_H_INCLUDED

///lista de bibliotecas
#include "dPila.h"
#include "dCola.h"
#include "stdlib.h"
#include "lista.h"
#include <string.h>
#include "macros.h"
#include "listaDoble/listadoble.h"
#include "comparaciones/comparaciones.h"


///Aqui se almacenaran todas las pruebas realizadas

///CREACION DE LOTES EN ARCHIVOS
int crearLoteBinario();
int crearLoteSoloTexto();

///PRUEBAS CON LAS COLAS
int colaPruebaGenerica(const void *vec, int ce, unsigned tamanio, void accion(void*));


///PRUEBAS CON LAS LISTAS
int pruebaInsertarOrdenadoNumeros();

int probarMovimientos();

///MISCELANEOS
int crearArchBinario(const void *info, size_t bytes, const char *nomarch);
void eliminarSalto(char *buffer);

///MUESTRAS POR PANTALLA
void mostrarEntero(void *info);
void mostrarFlotante(void *info);
void mostrarNumero(void *info);


void mostrarRaizCuadrada(void *info);
void mostrarCadena(void *info);

///funciones de ordenamiento
int MayorEntero(const void *a, const void *b);
int MenorEntero(const void *a, const void *b);

int MayorNumero(const void *a, const void *b);
int MenorNumero(const void *a, const void *b);


int igualValorEntero(const void *a, const void *clave);
//funciones para reducir
void sacarPromedio(const void *info, void *r);

///funciones con listas sin admitir duplicados
int sinDuplicados(void *dest, const void *info);
int aumentarApariciones(void *dest, const void *info);


///pruebas con listas doble
int pruebaListaDoble();

///impresiones de menu



int pruebaBsearch();



int mayoresA10(void *info);
int contar(void *info);
int multiplos(void *info, const void *clave);
void promedioPares(void* info,tPromedio* p_promedio);

///indices
int pruebaIndices();
int pruebaLecturaIndice();


///pruebas con lista simple
int pruebaOrdenarListaSimple();


#endif // PRUEBAS_H_INCLUDED
