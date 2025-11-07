#include <stdio.h>
#include "macros.h"
#include "utilidades.h"
#include <string.h>
#include "m_string.h"

//Funciones para mostrar por pantalla
void Mostrar_Entero(void *info)
{
    int *p_info = (int*)info;
    printf("%d ", *p_info);
}

void Mostrar_Flotante(void *info)
{
    float *p_info = (float*)info;
    printf("%.2f ", *p_info);
}


void Mostrar_Caracter(void *info)
{
    char *p_info = (char*)info;
    printf("%c ", *p_info);
}

void Mostrar_cadena(void *info)
{
    char *p_info = (char*)info;
    printf("%s", p_info);
}

void Mostrar_Empleado(void *info)
{
    tEmpleado *p_emp = (tEmpleado*)info;
    printf("%4d %-25s %-4.1f\n", p_emp->legajo, p_emp->nombre, p_emp->sueldo);
}

void Mostrar_Alumno(void *info)
{
    tAlumno *p_alu = (tAlumno*)info;
    printf("%4d %-35s %2.2f\n", p_alu->legajo, p_alu->nombre, p_alu->promedio);
}

void mostrar_struct_int(void *info)
{
    r_promedio *prom = (r_promedio*)info;
    printf("%2d %2d\n", prom->acumulador, prom->cant);
}
//------------COMPARAR ENTEROS-----------------------------

int comparar_Enteros(const void *a, const void *b)
{
    int *p_a = (int*)a;
    int *p_b = (int*)b;
    return *p_a-*p_b;
}

int Comparar_Mayor_entero(const void *a,const void *b){
    int *p_a = (int*)a;
    int *p_b = (int*)b;
    return (*p_a>*p_b) ? 1 : 0;
}

int Comparar_Menor_entero(const void *a,const void *b){
    int *p_a = (int*)a;
    int *p_b = (int*)b;
    return (*p_a<*p_b) ? 1 : 0;
}
//------------COMPARAR FLOTANTES-----------------------------

int comparar_Flotantes(const void *a, const void *b)
{
    float *p_a = (float*)a;
    float *p_b = (float*)b;
    return *p_a-*p_b;
}

int Comparar_Mayor_flotante(const void *a,const void *b){
    float *p_a = (float*)a;
    float *p_b = (float*)b;
    return (*p_a>*p_b) ? 1 : 0;
}

int Comparar_Menor_flotante(const void *a,const void *b){
    float *p_a = (float*)a;
    float *p_b = (float*)b;
    return (*p_a<*p_b) ? 1 : 0;
}
//--------------COMPARAR CARACTERES---------------------------

int comparar_char(const void *a, const void *b)
{
    char *p_a = (char*)a;
    char *p_b = (char*)b;
    return *p_a-*p_b; //-> los caracteres son numeros
}

int Comparar_Mayor_char(const void *a,const void *b){
    char *p_a = (char*)a;
    char *p_b = (char*)b;
    return (*p_a>*p_b) ? 1 : 0;
}

int Comparar_Menor_char(const void *a,const void *b){
    char *p_a = (char*)a;
    char *p_b = (char*)b;
    return (*p_a<*p_b) ? 1: 0;
}
//--------------COMPARAR CADENAS CARACTERES---------------------------
int comparar_strings_i(const void *a, const void *b)
{
    char *p_a = (char*)a;
    char *p_b = (char*)b;
    return strcmpi(p_a,p_b); //-> los caracteres son numeros
}


int comparar_mayor_promedio(const void *a,const void *b)
{
    tAlumno *p_a = (tAlumno*)a;
    tAlumno *p_b = (tAlumno*)b;
    return (p_a->promedio>p_b->promedio) ? 1 : 0;
}

int Comparar_structs_int(const void *a, const void *b)
{
    r_promedio *p_a = (r_promedio*)a;
    r_promedio *p_b = (r_promedio*)b;
    return ( p_a->acumulador-p_b->acumulador );
}

int Mayor_structs_int(const void *a, const void *b)
{
    r_promedio *p_a = (r_promedio*)a;
    r_promedio *p_b = (r_promedio*)b;
    return (p_a->acumulador>p_b->acumulador) ? 1 : 0;
}

int Menor_structs_int(const void *a, const void *b)
{
    r_promedio *p_a = (r_promedio*)a;
    r_promedio *p_b = (r_promedio*)b;
    return (p_a->acumulador<p_b->acumulador) ? 1 : 0;
}

void Agrupar_struct(void *dest, const void *src)
{
    r_promedio *p_a = (r_promedio*)dest;
    r_promedio *p_b = (r_promedio*)src;
    p_a->cant+=p_b->cant;
}
//-----------------------------------------
int EsDistintoDeTres(const void *x)
{
    int *p_x = (int*)x;
    return (*p_x!=3) ? 1 : 0;
}

int EsDistintoDeCinco(const void *x)
{
    int *p_x = (int*)x;
    return (*p_x!=5) ? 1 : 0;
}
//-----------------------------------------
void Calcular_promedio_integer(void *r, const void *x)
{
    r_promedio *p_r = (r_promedio*)r;
    int valor = *(int*)x;
    p_r->acumulador+= valor;
    p_r->cant++;
}

void Suma_Elementos_int(void *r, const void *x)
{
    int *acum = (int*)r;
    int valor = *(int*)x;
    *acum+= valor;
}

//-----------------------------------------
int Trozar_alumno(char *linea, void *datos)
{
    tAlumno *p_alu = (tAlumno*)datos;
    char *p_letra;
    p_letra = m_strrchr(linea,'|');
    if(!p_letra)
        return 0;
    sscanf(p_letra+1,"%f",&p_alu->promedio);
    *p_letra='\0';
    p_letra = m_strrchr(linea,'|');
    if(!p_letra)
        return 0;
    strcpy(p_alu->nombre,p_letra+1);
    //sscanf(p_letra+1,"%[^|]",p_alu->nombre);
    *p_letra='\0';
    sscanf(linea,"%d",&p_alu->legajo);
    return 1;
}


//--------------COMPARAR EMPLEADOS---------------------------

int comparar_legajo(const void* a, const void *b)
{
    tEmpleado *p_a = (tEmpleado*)a;
    tEmpleado *p_b = (tEmpleado*)b;
    return p_a->legajo-p_b->legajo;
}
