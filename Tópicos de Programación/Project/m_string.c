#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include <string.h>

size_t m_strlen(const char *cad)
{
    size_t resultado = 0;
    while(*cad)
    {
        resultado++;
        cad++;
    }
    return resultado;
}

char* m_strcpy(char *cad_destino, const char *cad_origen)
{
    char *ini = cad_destino;
    while(*cad_origen)
    {
        *cad_destino = *cad_origen;
        cad_destino++;
        cad_origen++;
    }
    *cad_destino='\0';//NO OLVIDARSE DE ESTO
    //DEBE SER UNA CADENA BIEN FORMADA
    return ini;
}

char* m_strcat(char *cad_destino, const char *cad_origen)
{
    char *ini = cad_destino;
    while(*cad_destino)
        cad_destino++;
    while(*cad_origen)
    {
        *cad_destino = *cad_origen;
        cad_destino++;
        cad_origen++;
    }
    *cad_destino='\0';
    return ini;
}

//probar las funciones de abajo luego
char* m_strchr(const char *cadena, int letra)
{
    char *p_cad = (char*)cadena;
    while(*p_cad){
        if(*p_cad==letra)
            return p_cad;
        p_cad++;
    }
    return NULL;
}

char* m_strrchr(const char *cadena, int letra)
{
    char *ini = (char*)cadena;
    while(*cadena)
        cadena++;
    while(cadena>=ini){
        if(*cadena==letra)
            return (char*)cadena;
        cadena--;
    }
    return NULL;
}

int m_strcmp(char *cad1, char *cad2)
{
    while(*cad1 && *cad2 && *cad1==*cad2){
        cad1++;
        cad2++;
    }
    return *cad1-*cad2;
}

int m_strcmpi(char *cad1, char *cad2)
{
    while(*cad1 && *cad2 && A_MAYUS(*cad1)==A_MAYUS(*cad2)){
        cad1++;
        cad2++;
    }
    return *cad1-*cad2;
}

char* m_strstr(const char* cad1, const char* cad2)
{
    char *p_cad1 = (char*)cad1;
    char *p_cad2 = (char*)cad2;
    while(*p_cad1)
    {
        while(*p_cad1 && *p_cad2 && *p_cad1==*p_cad2)
        {
            p_cad1++;
            p_cad2++;
        }
        if(*p_cad2 == '\0')
            return (char*)cad1;
        p_cad2 = (char*)cad2;
        p_cad1++;
    }
    return (*cad1=='\0' && *cad1 == *cad2) ? (char*)cad1 : NULL;
}

char* m_strncpy(char *cad_destino, const char *cad_origen, size_t cant_bytes)
{
    char *ini = cad_destino;
    int i=0;//cantidad de bytes copiados
    while(*cad_origen && i<cant_bytes)
    {
        *cad_destino = *cad_origen;
        cad_destino++;
        cad_origen++;
        i++;
    }
    *cad_destino='\0';//NO OLVIDARSE DE ESTO
    //DEBE SER UNA CADENA BIEN FORMADA
    return ini;
}
/*----------------------------------------------------------------*/
int Es_Palindromo(const char *cad)
{
    char *ini=(char*)cad;
    char *fin = (char*)cad;
    while(*fin)
        fin++;
    if(*cad!='\0')
        fin--;
    while(ini<fin){
        while(!ESLETRA(*fin))
            fin--;
        while(!ESLETRA(*ini))
            ini++;
        if((A_MAYUS(*ini)) != (A_MAYUS(*fin)))
            return 0;
        ini++;
        fin--;
    }
    return 1;
}

int Proxima_palabra(const char *cad, char **ini)
{
    int cant_letras = 0;
    while(!ESLETRA(*cad) && *cad)
        cad++;
    *ini = (char*)cad;
    while(ESLETRA(*cad))
    {
        cant_letras++;
        cad++;
    }
    return cant_letras;
}

char* Normalizar_Cadena(char *cadena)
{
    int cant_letras;
    int cant_total = 0;
    char *lectura = cadena;
    char *escritura = cadena;
    int band;
    if(!(*lectura))
        return cadena;
    while(*lectura)
    {
        band = 1;
        cant_letras = Proxima_palabra(lectura,&lectura);
        cant_total+=cant_letras;
        while(cant_letras)
        {
            *escritura = (band == 1) ? A_MAYUS(*lectura) : A_MINUS(*lectura);
            lectura++;
            escritura++;
            band = 0;
            cant_letras--;
        }
        if(band!=1)
        {
            *escritura = ' ';
            escritura++;
        }
    }
    *escritura = '\0';
    return cadena;
}

char* Desofuscar(char *cadena, const char *grupo)
{
    int largo_grupo = strlen(grupo);
    char *ini = cadena;
    char *dir_cadena;
    int pos;
    int desplazamiento;
    int cant_letras;
    while(*cadena)//*cadena!='\0'
    {
        pos = 1;
        cant_letras = Proxima_palabra(cadena,&cadena);
        while(cant_letras)//cant_letras!=0
        {
            dir_cadena = m_strchr(grupo,*cadena);
            if(dir_cadena)//dir:cadena!=NULL
            {
                desplazamiento = (dir_cadena-grupo+pos)%(largo_grupo);
                *cadena = *(grupo+desplazamiento);
            }
            pos++;
            cadena++;
            cant_letras--;
        }
    }
    return ini;
}

void Reverse(char *cadena)
{
    char *ini = cadena;
    char *fin = cadena;
    char aux;
    while(*fin)
        fin++;
    fin--;
    while(ini<fin)
    {
        aux = *ini;
        *ini = *fin;
        *fin = aux;
        ini++;
        fin--;
    }
}

void Revertir_palabra(char *cadena, int cant_letras)
{
    char *ini = cadena;
    char *fin = cadena + cant_letras - 1;
    char aux;
    while(ini<fin){
        aux = *ini;
        *ini = *fin;
        *fin = aux;
        ini++;
        fin--;
    }
}

char* copiaCadena(const char *origen)
{
    int long_cadena = strlen(origen)+1;
    char *dest = malloc(long_cadena);
    char *p_dest = dest;
    int i;
    if(!dest)
        return NULL;
    for(i=0;i<long_cadena;i++)
    {
        *dest = *origen;
        dest++;
        origen++;
    }
    //free(p_dest) ?? si hacemos esto, perdemos el contenido
    return p_dest;
}

