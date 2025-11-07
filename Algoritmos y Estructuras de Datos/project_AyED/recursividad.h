#ifndef RECURSIVIDAD_H_INCLUDED
#define RECURSIVIDAD_H_INCLUDED

#include "lista.h"

unsigned long long factorial(int n);
unsigned long long r_factorial(int n);
unsigned long long sumaRecursiva(int ini, int fin);


///ejercicios de cadenas
void mostrar(char *cad);
void mostrarAlReves(char *cad);
void mostrarInicioFinR(char *cad);
void mostrarInicioFin(char *cad);
void mostrarCadenaIzq(char *cad);
void mostrarCadenaDer(char *cad);
void mostrarCadenaBi(char *cad);
//las que siguen requieren envoltorios
void mostrarCadenaV1(const char *cad);
void mostrarCadenaV2(const char *cad);
void mostrarCadenaV3(const char *cad);

///envoltorios para cadenas
void _funcion1(const char *cad, char *fin);
void _funcion2(const char *cad, char *fin);
void _reinicio(const char *cad, char *fin);
void _reinicioV2(const char *cad, char *ini);
///ejercicios de numeros
void mostrarNumeroAlReves(int numero);
void mostrarNumeroRecursiva(int numero);
void mostrarDerechoReves(int numero);
void mostrarCociente(int numero);
void mostrarCocienteReves(int numero);
void mostrarCocienteRevesV2(int numero);

///ejercicio de lista enlazada

int mostrarListaReves(tLista *p, accion muestra);
int mostrarListaRevesNotR(tLista *p, accion muestra);
#endif // RECURSIVIDAD_H_INCLUDED
