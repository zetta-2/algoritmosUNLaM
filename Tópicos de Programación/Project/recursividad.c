#include "recursividad.h"
#include "m_string.h"

unsigned long long r_factorial(unsigned x)
{
    return (x) ? (x*r_factorial(x-1)) : 1;
}

int r_map(void *vec, int ce, unsigned tamanio, void accion(void*))
{
    if(ce==0)
        return 0;
    accion(vec);
    return r_map(vec+tamanio,ce-1,tamanio,accion);
}

int r_map_inverso(void *vec, int ce, unsigned tamanio, void accion(void*))
{
    if(ce==0)//caso base
        return 0;
    r_map_inverso(vec+tamanio,ce-1,tamanio,accion);
    accion(vec);
    return 1;
}

size_t r_strlen(const char *cad)
{
    if(*cad=='\0')
        return 0;
    return r_strlen(cad+1)+1;
}

char* r_strchr(const char *cadena, int letra)
{
    if(*cadena=='\0' && (char)letra!='\0')
        return NULL;
    if(*cadena==(char)letra)
        return (char*)cadena;
    return r_strchr(cadena+1,letra);
}

char* r_strrchr(const char *cadena, int letra)
{
    char *resultado;//alamacenar fin en un puntero para no saltar de la recursion
    if(*cadena!='\0')
        resultado = r_strrchr(cadena+1,letra);
    else
        return NULL;
    if(resultado!=NULL)
        return resultado;
    if(*cadena==(char)letra)
        return (char*)cadena;
    return NULL;
}

int r_Es_Palindromo(const char *cad)
{
    char *fin;
    if(*cad=='\0')
        return 1;
    fin = (char*)cad + r_strlen(cad)-1;
    return _r_Es_Palindromo(cad,fin);
}

int _r_Es_Palindromo(const char *ini, const char *fin)
{
    if(!(ESLETRA(*fin)))
        return _r_Es_Palindromo(ini,fin-1);
    if(!(ESLETRA(*ini)))
        return _r_Es_Palindromo(ini+1,fin);
    if( (A_MAYUS(*ini)) != (A_MAYUS(*fin)) )
        return 0;
    return (ini<fin) ? (_r_Es_Palindromo(ini+1,fin-1)) : 1;
}

void* r_Bsearch(void *valor, const void *vec, size_t ce, size_t tamanio, int Comparar(const void*,const void*))
{
    int p_medio = ce/2;
    void *p_vec = (void*)vec;
    void *p_p_medio = p_vec + p_medio*tamanio;
    int resu;
    if(ce==0)//CASO BASE 1
        return NULL;
    resu = Comparar(p_p_medio,valor);
    if(resu==0)//CASO BASE 2
        return p_p_medio;
    if(resu>0)//izquierda
        ce = p_medio;
    else//derecha
    {
        ce = ce - p_medio - 1;
        p_vec = p_p_medio + tamanio;
    }
    return r_Bsearch(valor,p_vec,ce,tamanio,Comparar);
}



