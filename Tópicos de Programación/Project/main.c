#include <stdio.h>
#include <stdlib.h>
#include "genericos.h"
#include "archivos.h"
#include "utilidades.h"
#include "m_string.h"
#include "TDA_vector.h"
#include "matrices.h"
#include "recursividad.h"

#define NOM_ARCH_1 "empleados.dat"
#define NOM_ARCH_2 "alumnos.dat"

//macros para el merge_avanzado
#define NOM_ARCH_DEST "emp.dat"
#define NOM_ARCH_SRC "nov.dat"
#define NOM_ARCH_TEMP "temp.dat"

//VARIACION CON ARCHIVOS DE TEXTOS
#define NOM_ARCH_TEXTO_ALU "alumno.txt"
#define NOM_ARCH_TEXTO_ALU_VAR "alumno_var.txt"

int main()
{
    r_promedio vec[TAM_MAX_VEC];
    r_promedio *p = vec;
    r_promedio vec_agr_ord[TAM_MAX_VEC];
    int ce = Cargar_Struct_Int(vec);
    int ce_agrp = 0;
    int i;
    puts("Campos cargados:");
    m_map(vec,ce,sizeof(r_promedio),mostrar_struct_int);
    puts("Agrupamiento ordenado:");
    for(i=0;i<ce;i++)
    {
        Insertar_Aprupar_ordenado(vec_agr_ord,p,&ce_agrp,sizeof(r_promedio),TAM_MAX_VEC,Comparar_structs_int,Agrupar_struct,Menor_structs_int);
        p++;
    }
    m_map(vec_agr_ord,ce_agrp,sizeof(r_promedio),mostrar_struct_int);
    return 0;
}






    /*int dato1 = CrearArchivoBinario(NOM_ARCH_DEST,empleado,sizeof(empleado));
    int dato2 = CrearArchivoBinario(NOM_ARCH_SRC,nov,sizeof(nov));
    if(!dato1 || !dato2)
        puts("Error al crear alguno de los archivos.");
    puts("Proceso de merge...");

    puts("Empleados antes");
    if(!RecorrerArchivoBinario(NOM_ARCH_DEST,sizeof(tEmpleado),Mostrar_Empleado))
        puts("Error");

    if(!Merge_avanzado_novedades(NOM_ARCH_DEST,NOM_ARCH_SRC,NOM_ARCH_TEMP))
        puts("Error");

    puts("Empleados ahora");
    if(!RecorrerArchivoBinario(NOM_ARCH_DEST,sizeof(tEmpleado),Mostrar_Empleado))
        puts("Error");*/
