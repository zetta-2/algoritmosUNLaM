#ifndef LOTES_PRUEBA_H_INCLUDED
#define LOTES_PRUEBA_H_INCLUDED

#include "genericos.h"
#include "macros.h"

//LISTAS DE STRUCTS
typedef struct{
    int legajo;
    char nombre[TAM];
    float sueldo;
}tEmpleado;

typedef struct{
    int legajo;
    char nombre[TAM];
    float promedio;
}tAlumno;

typedef struct{
    int acumulador;
    int cant;
}r_promedio;

//structs para merge avanzado

typedef struct
{
    tEmpleado emp;
    char estado;
}t_novedades;

//CARGA DE DATOS DESDE LA MEMORIA
int Cargar_enteros(int *buffer);
int Cargar_enteros_ordenados(int *buffer);
int Cargar_Matriz_cuadrada(int Mat[][TAM_COL]);
int Cargar_Palindromos(char Mat[][TAM_CHAR]);
int CargarEmpleado(tEmpleado *buffer);
int CargarAlumno(tAlumno *buffer);
int CargarNovedades(t_novedades *buffer);
int Cargar_Struct_Int(r_promedio *buffer);

#endif // LOTES_PRUEBA_H_INCLUDED
