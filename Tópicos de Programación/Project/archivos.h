#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <stdio.h>
#include "genericos.h"

int CrearArchivoBinario(const char *nomArch, const void *datos, unsigned tamanio);
int RecorrerArchivoBinario(const char *nomArch,unsigned tamanio, void Accion(void*));
int Merge_Empleados_Alumnos(const char *Arch_emp, const char *arch_alumnos);
int CrearArchivo_solo_texto(const char *nomArch, const char datos[][TAM], unsigned cant_datos);
int RecorrerArchivo_solo_texto(const char *nomArch, void accion(void*));
//CREACION Y LECTURA FIJO
int Crear_lote_alumno_texto_fijo(const char *nomArch);
int Leer_lote_alumno_texto_fijo(const char *nomArch);
//CREACION Y LECTURA  VARIABLE
int Crear_lote_alumno_texto_variable(const char *nomArch);
int Leer_lote_alumno_texto_variable(const char *nomArch);
//ULTIMOS TEMAS DE ARCHIVOS
int f_Bin_sec_(void *buffer, const char *nom_arch, unsigned tamanio, int cmp(const void*,const void*));
int Merge_avanzado_novedades(const char *arch_dest, const char *arch_src, const char *arch_temp);
//BSEARCH EN ARCHIVOS PENDIENTE (tomado en parcial)
int f_Bin_bsearch(void *buffer, const char* nomarch, unsigned tam, int cmp(const void *, const void *));
int f_Bin_Ssort(const char *nom_arch, unsigned tamanio, int cmp(const void*,const void*));


#endif // ARCHIVOS_H_INCLUDED
