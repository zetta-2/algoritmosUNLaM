#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include "genericos.h"
#include "lotes_prueba.h"

//IMPRESION POR PANTALLA
void Mostrar_Entero(void *entero);
void Mostrar_Flotante(void *info);
void Mostrar_Caracter(void *info);
void Mostrar_cadena(void *info);
void Mostrar_Empleado(void *info);
void Mostrar_Alumno(void *info);
void mostrar_struct_int(void *info);
//COMPARAR INTEGERS
int comparar_Enteros(const void *a,const void *b);
int Comparar_Mayor_entero(const void *a,const void *b);
int Comparar_Menor_entero(const void *a,const void *b);
//COMPARAR FLOTANTES
int comparar_Flotantes(const void *a,const void *b);
int Comparar_Mayor_flotante(const void *a,const void *b);
int Comparar_Menor_flotante(const void *a,const void *b);
//COMPARAR CARACTERES
int comparar_char(const void *a,const void *b);
int Comparar_Mayor_char(const void *a,const void *b);
int Comparar_Menor_char(const void *a,const void *b);
//COMPARAR EMPLEADOS->SUELDO
int comparar_Sueldo(const void *a,const void *b);
int Comparar_Mayor_Sueldo(const void *a,const void *b);
int Comparar_Menor_Sueldo(const void *a,const void *b);
//COMPARAR ALUMNO->PROMEDIO
int comparar_mayor_promedio(const void *a,const void *b);
//FILTROS
int EsDistintoDeTres(const void *x);
int EsDistintoDeCinco(const void *x);
///
int Comparar_structs_int(const void *a, const void *b);
int Mayor_structs_int(const void *a, const void *b);
int Menor_structs_int(const void *a, const void *b);
void Agrupar_struct(void *dest, const void *src);
//Reduccion
void Calcular_promedio_integer(void *r, const void *x);
void Suma_Elementos_int(void *r, const void *x);
//funciones para archivos
int Trozar_alumno(char *linea, void *datos);

///comparar legajo
int comparar_legajo(const void* a, const void *b);

#endif // UTILIDADES_H_INCLUDED
