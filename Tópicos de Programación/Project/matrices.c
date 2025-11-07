#include "matrices.h"
#include "vectores.h"
#include "macros.h"
#include <stdio.h>
#include <stdlib.h>
#include "genericos.h"

void Mostrar_Matriz(int mat[][TAM_COL] , int cf, int cc)
{
    int i;
    int j;
    for(i=0;i<cf;i++)
    {
        for(j=0;j<cc;j++)
            printf("%d ", mat[i][j]);
        puts("");
    }
}

void Inicializar_matriz(int **mat,int cf, int cc, int valor)
{
    int i;
    int j;
    for(i=0;i<cf;i++)
        for(j=0;j<cc;j++)
            mat[i][j]=valor;
}

int Recorrer_Diagonal_principal(int mat[][TAM_COL],int cfc)
{
    int i;
    int suma = 0;
    for(i=0;i<cfc;i++)
        suma+=mat[i][i];
    return suma;
}

int Recorrer_Diagonal_secundaria(int mat[][TAM_COL], int cfc)
{
    int i;
    int suma = 0;
    for(i=0;i<cfc;i++)
        suma+=mat[i][cfc-1-i];
    return suma;
}

int Recorrer_Debajo_Diagonal(int mat[][TAM_COL],int cfc)
{
    int i;
    int j;
    for(i=1;i<cfc;i++){
        for(j=0;j<i;j++)
            printf("%d ", mat[i][j]);
        puts("");
    }
    return 0;
}

int Recorrer_Encima_Diagonal(int mat[][TAM_COL],int cfc)
{
    int i, j;
    for(i=0;i<cfc-1;i++){
        for(j=1+i;j<cfc;j++)
            printf("%d ", mat[i][j]);
        puts("");
    }
    return 0;
}
//recorridos que incluyen las diagonales
int Recorrer_Debajo_Diagonal_i(int mat[][TAM_COL],int cfc)
{
    int i;
    int j;
    for(i=0;i<cfc;i++){
        for(j=0;j<=i;j++)
            printf("%d ", mat[i][j]);
        puts("");
    }
    return 0;
}

int Recorrer_Encima_Diagonal_i(int mat[][TAM_COL],int cfc)
{
    int i;
    int j;
    for(i=0;i<cfc;i++){
        for(j=i;j<cfc;j++)
            printf("%d ", mat[i][j]);
        puts("");
    }
    return 0;
}

int Es_Identidad(int mat[][TAM_COL],int cfc)
{
    int i;
    int j;
    for(i=0;i<cfc;i++){
        if(mat[i][i]!=1)
            return 0;
    }
    for(i=1;i<cfc;i++){
        for(j=0;j<i;j++)
            if(mat[i][j]!=0 || mat[j][i]!=0)
                return 0;
    }
    return 1;
}

int Es_Simetrica(int mat[][TAM_COL],int cfc)
{
    int i;
    int j;
    for(i=1;i<cfc;i++){
        for(j=0;j<i;j++)
            if(mat[i][j]!=mat[j][i])
                return 0;
    }
    return 1;
}

int Es_Diagonal(int mat[][TAM_COL], int cfc)
{
    int i, j;
    for(i=1;i<cfc;i++)
        for(j=0;j<i;j++)
            if(mat[i][j]!=0 || mat[j][i]!=0)
                return 0;
    return 1;
}


int Recorrer_triangulo_arriba(int mat[][TAM_COL],int cfc)
{
    int i, j;
    int fin_fila = cfc/2-(cfc+1)%2;
    int fin_col;
    for(i=0;i<fin_fila;i++)
    {
        fin_col = cfc-1-i;
        for(j=i+1;j<fin_col;j++)
            printf("%d ",mat[i][j]);
        puts("");
    }
    return 1;
}

int Recorrer_triangulo_abajo(int mat[][TAM_COL],int cfc)
{
    int i, j;
    int ini_fila = cfc/2+1;
    int ini_col;
    for (i=ini_fila;i<cfc;i++)
    {
        ini_col = cfc - i;
        for(j=ini_col;j<i;j++)
            printf("%d ",mat[i][j]);
        puts("");
    }
    return 1;
}

int Recorrer_triangulo_izq(int mat[][TAM_COL],int cfc)
{
    int i, j;
    int fin_col = cfc/2-(cfc+1)%2;
    int fin_fil;
    for(j=0;j<fin_col;j++)
    {
        fin_fil = cfc-1-j;
        for(i=j+1;i<fin_fil;i++)
            printf("%d ",mat[i][j]);
        puts("");
    }
    return 1;
}

int Recorrer_triangulo_der(int mat[][TAM_COL],int cfc)
{
    int i, j;
    int ini_col = cfc/2+1;
    int ini_fil;
    for (j=ini_col;j<cfc;j++)
    {
        ini_fil = cfc - j;
        for(i=ini_fil;i<j;i++)
            printf("%d ",mat[i][j]);
        puts("");
    }
    return 1;
}
//EJERCICIO PARTIDO FUTBOL
int Validar_matriz_resultados(int mat[][TAM_COL],int mat_puntaje[][TAM_COL] ,int cfc, int cc_puntaje)
{
    int i,j;
    int pos;
    //int ce_recorridos = 0;
    //int *p_mat = *mat_puntaje;
    for(i=1;i<cfc;i++){
        for(j=0;j<i;j++){
        //pos = BuscarValor(*p_mat,cc_puntaje,mat[i][j]);
        pos = BuscarValor(*mat_puntaje,cc_puntaje,mat[i][j]);
        if(pos==-1 || mat[j][i]!=mat_puntaje[1][pos])
            return 0;
        //ce_recorridos++;
        }
    }
    return 1;
}

void Puntaje_equipos(int *vec, int mat[][TAM_COL], int cfc)
{
    int i, j;
    for(i=1;i<cfc;i++)
        for(j=0;j<i;j++){
            *(vec+j)+=mat[i][j];
            *(vec+i)+=mat[j][i];
        }
}

int Recorrido_en_espiral(int mat[][TAM_COL], int cf, int cc)
{
    int ce = cf*cc;
    int recorrido = 0;
    int i;
    int j;
    int ini = 0;
    int tanda = 0;
    while(recorrido<ce)
    {
        //DERECHA Y ABAJO
        if(tanda%2==0)
        {
            for(i=ini;i<cc-ini;i++)
            {
                printf("%d ", mat[ini][i]);
                recorrido++;
            }
            puts("");
            ini++;
            for(j=ini;j<cf-ini+1;j++)
            {
                printf("%d ", mat[j][i-1]);
                recorrido++;
            }
        }
        //IZQUIERDA Y ARRIBA
        else
        {
            for(j=cc-ini-1;j>=ini-1;j--)
            {
                printf("%d ", mat[cf-ini][j]);
                recorrido++;
            }
            puts("");
            for(j=cf-ini-1;j>=ini;j--)
            {
                printf("%d ", mat[j][ini-1]);
                recorrido++;
            }
        }
        puts("");
        tanda++;
    }
    return 1;
}

void Multiplicar_matrices(int mat1[][TAM_COL], int cf1, int cc1,
                          int mat2[][TAM_COL], int cf2, int cc2,
                          int mat_resu[][TAM_COL]){
    int i;
    int j;
    int k;
    for(i=0;i<cf1;i++)
    {
        for(k=0;k<cc2;k++)
            for(j=0;j<cc1;j++)
                mat_resu[i][k]+=mat1[i][j]*mat2[j][k];
    }
}

void Transponer_matriz_cuadrada(int mat[][TAM_COL],int cfc)
{
    int i;
    int j;
    int aux;
    for(i=1;i<cfc;i++)
        for(j=0;j<i;j++)
        {
            aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
}

int Transponer_matriz(int mat[][TAM_COL], int cf, int cc)
{
    int i;
    int j;
    int aux;
    int tope = (cf>cc) ? cf : cc;
    for(i=1;i<tope;i++){
        for(j=0;j<i;j++)
        {
            aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
    }
    return 1;
}

int** Crear_Matriz(unsigned cf, unsigned cc)
{
    int **mat;
    int **ini;
    int i;
    mat = malloc(cf*sizeof(int*));
    if(!mat)
        return NULL;
    ini = mat;
    for(i=0;i<cf;i++)
    {
        *mat=malloc(cc*sizeof(int));
        if(!(*mat))
        {
            DestruirMatriz(ini,i);
            return NULL;
        }
        mat++;
    }
    return ini;
}

int DestruirMatriz(int **Mat, int cf)
{
    int i;
    int **ini = Mat;
    for(i=0;i<cf;i++)
        free(Mat[i]);
    free(ini);
    return 1;
}
