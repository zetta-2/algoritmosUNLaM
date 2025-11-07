#include "recursividad.h"
#include <string.h>
#include <stdio.h>

unsigned long long factorial(int n)
{
    int i;
    unsigned long long resultado=1;
    for(i=1;i<=n;i++)
        resultado*=i;
    return resultado;
}

unsigned long long r_factorial(int n)
{
    if(n==0)
        return 1;
    return n*r_factorial(n-1);
}

unsigned long long sumaRecursiva(int ini, int fin)
{
    if(ini==fin)
        return fin;
    return ini + sumaRecursiva(ini+1,fin);
}

///ejercicios de cadenas recursivas

void mostrar(char *cad){
    if(*cad)
    {
        printf("%c",*cad);
        mostrar(cad+1);
    }
}

void mostrarAlReves(char *cad){
    if(*cad)
    {
        mostrarAlReves(cad+1);
        printf("%c",*cad);
    }
}

void mostrarInicioFinR(char *cad){
    if(*cad)
    {
        printf("%c\n",*cad);
        mostrarInicioFinR(cad+1);
        printf("%c\n",*cad);
    }
}

void mostrarInicioFin(char *cad){
    if(*cad)
    {
        if(*(cad+1))
        {
            printf("%c\n",*cad);
            mostrarInicioFin(cad+1);
        }
        printf("%c\n",*cad);
    }
}

void mostrarCadenaIzq(char *cad){
    if(*cad)
    {
        puts(cad);
        mostrarCadenaIzq(cad+1);
    }
}

void mostrarCadenaDer(char *cad){
    if(*cad)
    {
        mostrarCadenaDer(cad+1);
        puts(cad);
    }
}

void mostrarCadenaBi(char *cad){
    if(*cad)
    {
        puts(cad);
        mostrarCadenaBi(cad+1);
        puts(cad);
    }
}

//las que siguen requieren envoltorios

void mostrarCadenaV1(const char *cad)
{
    char *fin = (char*)cad;
    fin+=strlen(cad);
    if(*cad){
        _funcion1(cad,fin);
        puts("");
        _reinicio(cad,fin-1);
    }
}

void mostrarCadenaV2(const char *cad)
{
    char *ini = (char*)cad;
    if(*cad){
        _funcion2(cad,ini);
        puts("");
        _reinicioV2(cad,ini+1);
    }
}

///envoltorios
void _funcion1(const char *cad, char *fin)
{
    putchar(*cad);
    if((cad+1)<fin)
        _funcion1(cad+1,fin);
}

void _funcion2(const char *cad, char *fin)
{
    putchar(*cad);
    if(cad<fin)
        _funcion2(cad+1,fin);
}

void _reinicio(const char *cad, char *fin)
{
    if(cad<fin){
        _funcion1(cad,fin);
        puts("");
        _reinicio(cad,fin-1);
    }
}

void _reinicioV2(const char *cad, char *ini)
{
    if(*ini){
        _funcion2(cad,ini);
        puts("");
        _reinicioV2(cad,ini+1);
    }
}

void mostrarCadenaV3(const char *cad)
{
    mostrarCadenaV1(cad);
    mostrarCadenaV2(cad);
}
///funciones con numeros

void mostrarNumeroAlReves(int numero)
{
    int resto=numero%10;
    int cociente=numero/10;
    printf("%d\n",resto);
    if(cociente)
        mostrarNumeroAlReves(cociente);
}

void mostrarNumeroRecursiva(int numero)
{
    int resto=numero%10;
    int cociente=numero/10;
    if(cociente)
        mostrarNumeroRecursiva(cociente);
    printf("%d\n",resto);
}

void mostrarDerechoReves(int numero)
{
    int resto=numero%10;
    int cociente=numero/10;
    printf("%d\n",resto);
    if(cociente)
        mostrarDerechoReves(cociente);
    printf("%d\n",resto);
}

void mostrarCociente(int numero)
{
    int cociente=numero/10;
    printf("%d\n",numero);
    if(cociente)
        mostrarCociente(cociente);
}

void mostrarCocienteReves(int numero)
{
    int cociente=numero/10;
    if(cociente)
        mostrarCocienteReves(cociente);
    printf("%d\n",numero);
}

void mostrarCocienteRevesV2(int numero)
{
    int cociente=numero/10;
    printf("%d\n",numero);
    if(cociente)
        mostrarCocienteRevesV2(cociente);
    printf("%d\n",numero);
}

///ejercicios con lista simple

int mostrarListaReves(tLista *p, accion muestra)
{
    if(*p==NULL)
        return VACIA;
    if((*p)->sig)
        mostrarListaReves(&(*p)->sig,muestra);
    muestra((*p)->info);
    return TODO_OK;
}

int mostrarListaRevesNotR(tLista *p, accion muestra)
{
    if(*p==NULL)
        return VACIA;
    tLista *ini = p;
    tLista *fin;
    tLista *aux;
    while((*p)->sig)
        p=&(*p)->sig;
    fin = p;
    while(fin!=ini)
    {
        aux = ini;
        while(&(*aux)->sig!=fin)
            aux=&(*aux)->sig;
        muestra((*fin)->info);
        fin = aux;
    }
    muestra((*ini)->info);
    return TODO_OK;
}
