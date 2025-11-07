#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

void MostrarVector(int *vec, int ce);
//EJERCICIOS 1.1 A 1.5
int Insertar_Por_Pos(int *vec, int *ce, int valor, int pos, unsigned tam_max);
int Insertar_Ordenadamente(int *vec, int *ce, int valor, unsigned capacidad_max);
int Eliminar_aparicion_por_pos(int *pvec, int *ce, int pos);
int Eliminar_primera_aparicion(int *pvec, int *ce, int valor);
int Eliminar_TODAS_apariciones(int *pvec, int *ce, int valor);

void Inicializar_Vector(int *vec, int ce, int valor);
int BuscarValor(int *pvec, int ce, int valor);

//
#endif // VECTORES_H_INCLUDED
