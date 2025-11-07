#ifndef M_STRING_H_INCLUDED
#define M_STRING_H_INCLUDED

#include "macros.h"
//#include <stdio.h>

size_t m_strlen(const char *cad);
char* m_strcpy(char *cad_destino, const char *cad_origen);
char* m_strcat(char *cad_destino, const char *cad_origen);
char* m_strchr(const char *cadena, int letra);//devuelve la dir de la 1ra aparicion de la letra
char* m_strrchr(const char *cadena, int letra);/*devuelve la dir de la "ultima" aparicion de la letra (la que se
                                                    encuentra mas a la izquierda*/
int m_strcmp(char *cad1, char *cad2);
int m_strcmpi(char *cad1, char *cad2);
char* m_strstr(const char* cad1, const char* cad2);
char* m_strncpy(char *cad_destino, const char *cad_origen, size_t cant_bytes);

//ejercicios de la guia

int Es_Palindromo(const char* cad); //probado
int Proxima_palabra(const char *cad, char **ini);//se pasa la dir de memoria del inicio de la palabra
char* Normalizar_Cadena(char *cadena);
char* Desofuscar(char *cadena, const char *grupo);
void Reverse(char *cadena); //revierte la cadena completa
void Revertir_palabra(char *cadena, int cant_letras);//revierte solo palabras
char* copiaCadena(const char *origen);
//Otras funciones complementarias



#endif // M_STRING_H_INCLUDED
