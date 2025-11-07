#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include "macros.h"




//FUNCIONES PARA CUALQUIER MATRIZ
void Mostrar_Matriz(int mat[][TAM_COL],int cf, int cc);
void Inicializar_matriz(int **mat,int cf, int cc, int valor);
int Recorrido_en_espiral(int mat[][TAM_COL], int cf, int cc);
void Multiplicar_matrices(int mat1[][TAM_COL], int cf1, int cc1,
                          int mat2[][TAM_COL], int cf2, int cc2,
                          int mat_resu[][TAM_COL]);

//FUNCIONES PARA MATRICES CUADRADAS

int Recorrer_Diagonal_principal(int mat[][TAM_COL],int cfc);
int Recorrer_Diagonal_secundaria(int mat[][TAM_COL],int cfc);
//lo mas importante de las funciones es el recorrido
int Recorrer_Debajo_Diagonal(int mat[][TAM_COL],int cfc);
int Recorrer_Encima_Diagonal(int mat[][TAM_COL],int cfc);
//idem funciones anteriores, incluyendo la diagonal
int Recorrer_Debajo_Diagonal_i(int mat[][TAM_COL],int cfc);
int Recorrer_Encima_Diagonal_i(int mat[][TAM_COL],int cfc);
int Es_Identidad(int mat[][TAM_COL],int cfc);
int Es_Simetrica(int mat[][TAM_COL],int cfc);
int Es_Diagonal(int mat[][TAM_COL], int cfc);
int Recorrer_triangulo_arriba(int mat[][TAM_COL],int cfc);
int Recorrer_triangulo_abajo(int mat[][TAM_COL],int cfc);
int Recorrer_triangulo_izq(int mat[][TAM_COL],int cfc);
int Recorrer_triangulo_der(int mat[][TAM_COL],int cfc);
int Validar_matriz_resultados(int mat[][TAM_COL],int mat_puntaje[][TAM_COL] ,int cfc, int cc_puntaje);
void Puntaje_equipos(int *vec, int mat[][TAM_COL], int cfc);
int Transponer_matriz(int mat[][TAM_COL], int cf, int cc);
void Transponer_matriz_cuadrada(int mat[][TAM_COL],int cfc);
//Matriz dinamica
int** Crear_Matriz(unsigned cf, unsigned cc);
int DestruirMatriz(int **Mat, int cf);
#endif // MATRICES_H_INCLUDED
