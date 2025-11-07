#ifndef GENERICOS_H_INCLUDED
#define GENERICOS_H_INCLUDED
#include <stdio.h>

#define TAM 1024

void Intercambio_generico(void *a, void *b, unsigned tamanio);// sin malloc
void* m_memcpy(void *dest, const void *origin, size_t tamanio);
void* m_memmove(void *dest, const void *origin, size_t tamanio);
void* copiaCosas(void *elemento, unsigned tam);
void* B_sequence(void *pvec, int ce, void *valor, unsigned tamanio, int cmp(const void*,const void*));//PROBAR LUEGO
//funciones genericas, algunas de la biblioteca Ansi C
void* m_map(void *vec, int ce, unsigned tamanio, void accion(void*));
void* m_filter(void *vec, int *ce, unsigned tamanio, int f_filtro(const void*));
void* m_reduce(void *vec, int ce, unsigned tamanio, void f_reduccion(void*, const void*), void* r);
void S_sort(void *vec, size_t ce, size_t tamanio, int comparar(const void*, const void*));
void* BuscarExtremo(void *vec, size_t ce, size_t tamanio, int comparar(const void*,const void*));
void* m_Bsearch(void *valor, const void *vec, size_t ce, size_t tamanio, int Comparar(const void*,const void*));
//REINGENIERIA
int Insertar_Por_Pos_generico(void *vec, int *ce, void *valor, int pos, unsigned tam_max, unsigned tamanio);
int Insertar_Ordenadamente_generico(void *vec, int *ce, void *valor, unsigned capacidad_max, unsigned tamanio, int Comparar(const void*,const void*));
int Eliminar_aparicion_por_pos_generico(void *pvec, int *ce, int pos, unsigned tamanio);
int Eliminar_primera_aparicion_generica(void *pvec, int *ce, void *valor, unsigned tamanio, int Comparar(const void*,const void*));
int Eliminar_TODAS_apariciones_generica(void *pvec, int *ce, void *valor, unsigned tamanio, int Comparar(const void*, const void*));

int Insertar_Aprupar_ordenado(void *buffer, void *clave, int *ce, unsigned tamanio, int cap_max,
                              int cmp(const void*,const void*),void Agrupar(void*,const void*),
                              int cmp_ord(const void*,const void*));
#endif // GENERICOS_H_INCLUDED
