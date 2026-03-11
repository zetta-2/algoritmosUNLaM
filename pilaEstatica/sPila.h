#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "../macros.h"
#define TAM_PILA 128

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
}tPila;

///PRIMITIVAS LISTA ESTATICA
void crearPila(tPila *pila);///no puede fallar
int apilar(tPila *pila, const void *valor, unsigned tam_dato);///el ultimo argumento es una copia, por eso no va const
int verTope(tPila *pila, void *valor, unsigned tam_dato);///en valor levantamos el tope de la pila, por eso no lleva const
int desapilar(tPila *pila, void *valor, unsigned tam_dato);
void vaciarPila(tPila *pila);///tampoco puede fallar
int pilaLlena(tPila *pila, unsigned tam_dato); ///dependera de lo que queramos insertar
int pilaVacia(tPila *pila); ///de tarea terminar



#endif // PILA_H_INCLUDED
