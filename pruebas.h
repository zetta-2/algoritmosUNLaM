#ifndef PRUEBAS_H_INCLUDED
#define PRUEBAS_H_INCLUDED

///lista de bibliotecas
#include "pila_mix_2.h"
#include "stdlib.h"
#include <string.h>

#define MAXLINE 1024

///Aqui se almacenaran todas las pruebas realizadas

///CREACION DE LOTES EN ARCHIVOS
int crearLoteBinario();
int crearLoteSoloTexto();

///PRUEBAS CON LAS PILAS NUEVAS
int pilaPruebaCadenas();
int pilaPruebaBin();
int pilaPruebaTexto();

///miscelaneo
int crearArchBinario(const void *info, size_t bytes, const char *nomarch);
void eliminarSalto(char *buffer);
#endif // PRUEBAS_H_INCLUDED
