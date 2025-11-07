#include "archivos.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CrearArchivoBinario(const char *nomArch, const void *datos, unsigned tamanio)
{
    FILE *pf = fopen(nomArch,"wb");
    if(!pf)
        return 0;
    fwrite(datos,tamanio,1,pf);
    fclose(pf);
    return 1;
}

int RecorrerArchivoBinario(const char *nomArch,unsigned tamanio, void Accion(void*))
{
    void *buffer;
    FILE *pf;
    buffer=malloc(tamanio);
    if(!buffer)
        return 0;
    pf = fopen(nomArch,"rb");
    if(!pf)
    {
        free(buffer);
        return 0;
    }
    fread(buffer,tamanio,1,pf);
    while(!feof(pf))
    {
        Accion(buffer);
        fread(buffer,tamanio,1,pf);
    }
    fclose(pf);
    free(buffer);
    return 1;
}

int Merge_Empleados_Alumnos(const char *Arch_emp, const char *arch_alumnos)
{
    tEmpleado empleado;
    int tamanio_emp = sizeof(tEmpleado);
    tAlumno alumno;
    FILE* f_emp;
    FILE* f_alu;
    f_emp = fopen(Arch_emp,"r+b");
    int comparacion;
    if(!f_emp)
        return 0;
    f_alu = fopen(arch_alumnos,"rb");
    if(!f_alu)
    {
        fclose(f_emp);
        return 0;
    }
    fread(&empleado,sizeof(empleado),1,f_emp);
    fread(&alumno,sizeof(alumno),1,f_alu);
    while(!feof(f_emp) && !feof(f_alu))
    {
        comparacion = comparar_Enteros(&empleado.legajo,&alumno.legajo);
        if(comparacion==0)
        {
            if(alumno.promedio>=7.0)
            {
                fseek(f_emp,(-1*tamanio_emp),SEEK_CUR);
                empleado.sueldo*=1.07;
                fwrite(&empleado,sizeof(empleado),1,f_emp);
                fseek(f_emp,0,SEEK_CUR);//fseek fantasma
                //fflush(f_emp);
            }
            fread(&empleado,sizeof(empleado),1,f_emp);
            fread(&alumno,sizeof(alumno),1,f_alu);
        }
        else if(comparacion>0)
            fread(&alumno,sizeof(alumno),1,f_alu);
        else
            fread(&empleado,sizeof(empleado),1,f_emp);
    }
    fclose(f_emp);
    fclose(f_alu);
    return 1;
}

int CrearArchivo_solo_texto(const char *nomArch, const char datos[][TAM], unsigned cant_datos)
{
    FILE *pf=fopen(nomArch,"wt");
    int i;
    if(!pf)
        return 0;
    for(i=0;i<cant_datos;i++)
        fprintf(pf,"%s\n",datos[i]);
    fclose(pf);
    return 1;
}

int RecorrerArchivo_solo_texto(const char *nomArch, void accion(void*))
{
    char linea[TAM];
    FILE *pf=fopen(nomArch,"rt");
    if(!pf)
        return 0;
    while(fgets(linea,TAM-1,pf))
    {
        //puts(linea); deja un espacio de mas
        accion(linea);
    }
    fclose(pf);
    return 1;
}

int Crear_lote_alumno_texto_fijo(const char *nomArch)
{
    tAlumno alumno[]={{10,"Juan Perez",4.0},
                      {20,"Florencia Re",4.0},
                      {30,"Maria Benitez",7.5},
                      {40,"Victor Gomez",7.5},
                      {50,"Flavio Gomez",9.2},
                      {70,"Julieta Beltran",3.0},
                      {90,"Fernanda Gauna",9.0},
                      {100,"Grance Lucas",10.0}};
    int ce_alumno = sizeof(alumno)/sizeof(tAlumno);
    int i;
    tAlumno *p_alu = alumno;
    FILE *f_alu = fopen(nomArch,"wt");
    if(!f_alu)
        return 0;
    for(i=0;i<ce_alumno;i++)
    {
        fprintf(f_alu,"%3d%-20s%3.1f\n",p_alu->legajo,p_alu->nombre,p_alu->promedio);
        p_alu++;
    }
    fclose(f_alu);
    return 1;
}

int Leer_lote_alumno_texto_fijo(const char *nomArch)
{
    char LINEA[TAM];
    char *p_linea;
    char DATO[TAM];
    char *p_dato = DATO;
    tAlumno alu;
    FILE *f_alu = fopen(nomArch,"rt");
    if(!f_alu)
        return 0;
    while(fgets(LINEA,TAM,f_alu))
    {
        p_linea = LINEA;
        strncpy(p_dato,p_linea,3);
        sscanf(p_dato,"%d",&alu.legajo);
        p_linea+=3;
        strncpy(p_dato,p_linea,20);
        sscanf(p_dato,"%[^|]",alu.nombre);
        p_linea+=20;
        strcpy(p_dato,p_linea);
        sscanf(p_dato,"%f",&alu.promedio);
        //APLICAR LOGICA DE TROZADO
        fprintf(stdout,"%3d%-20s%3.1f\n",alu.legajo,alu.nombre,alu.promedio);
    }
    fclose(f_alu);
    return 1;
}

int Crear_lote_alumno_texto_variable(const char *nomArch)
{
    tAlumno alumno[]={{10,"Juan Perez",4.0},
                      {20,"Florencia Re",4.0},
                      {30,"Maria Benitez",7.5},
                      {40,"Victor Gomez",7.5},
                      {50,"Flavio Gomez",9.2},
                      {60,"Claudio Dadomo",9.9},
                      {70,"Julieta Beltran",3.0},
                      {90,"Fernanda Gauna",9.0},
                      {100,"Grance Lucas",10.0},
                      {120,"Roberto Carlos",2.0},
                      {130,"Marcos Alonso",5.0}};
    int ce_alumno = sizeof(alumno)/sizeof(tAlumno);
    int i;
    tAlumno *p_alu = alumno;
    FILE *f_alu = fopen(nomArch,"wt");
    if(!f_alu)
        return 0;
    for(i=0;i<ce_alumno;i++)
    {
        fprintf(f_alu,"%d|%s|%3.1f\n",p_alu->legajo,p_alu->nombre,p_alu->promedio);
        p_alu++;
    }
    fclose(f_alu);
    return 1;
}

int Leer_lote_alumno_texto_variable(const char *nomArch)
{
    char LINEA[TAM];
    tAlumno alu;
    FILE *f_alu = fopen(nomArch,"rt");
    if(!f_alu)
        return 0;
    while(fgets(LINEA,TAM,f_alu))
    {
        if(Trozar_alumno(LINEA,&alu))
            fprintf(stdout,"%-4d%-20s%3.1f\n",alu.legajo,alu.nombre,alu.promedio);
    }
    fclose(f_alu);
    return 1;
}

int f_Bin_sec_(void *buffer, const char *nom_arch, unsigned tamanio, int cmp(const void*,const void*))
{
    void *local_buffer;
    FILE *file = fopen(nom_arch,"rb");
    if(!file)
        return 0;
    local_buffer = malloc(tamanio);
    if(!local_buffer)
    {
        fclose(file);
        return 0;
    }
    fread(local_buffer,tamanio,1,file);
    while(!feof(file))
    {
        if(cmp(buffer,local_buffer)==0)
        {
            memcpy(buffer,local_buffer,tamanio);
            free(local_buffer);
            fclose(file);
            return 1;
        }
        fread(local_buffer,tamanio,1,file);
    }
    free(local_buffer);
    fclose(file);
    return 0;
}

int f_Bin_bsearch(void *buffer, const char* nomarch, unsigned tam, int cmp(const void *, const void *))
{
    void *local_buffer; /// buffer local -> pedir memoria para malloc
    int ce_registros; ///cantidad de registros en el archivo
    int p_medio; ///punto medio
    int comparacion;///variable para guardar la comparacion
    int desplazamiento;///para moverme en el archivo
    FILE *file = fopen(nomarch,"rb");
    if(!file)
        return 0;
    local_buffer = malloc(tam);
    if(!local_buffer)
    {
        fclose(file);
        return 0;
    }
    fseek(file,0,SEEK_END);
    ce_registros = ftell(file)/tam;
    rewind(file);///fseek "fantasma" para ir al inicio
    while(ce_registros)///cuando no haya registros, finaliza bsearch
    {
        fseek(file,desplazamiento,SEEK_CUR);
        fread(local_buffer,tam,1,file);
        comparacion = cmp(local_buffer,buffer);
        if(comparacion==0)///hubo match???
        {
            memcpy(buffer,local_buffer,tam);
            fclose(file);
            free(local_buffer);
            return 1;
        }
        p_medio = ce_registros/2;
        if(comparacion<0){
            ce_registros = p_medio;
            desplazamiento = -ce_registros + ce_registros/2 - 1;
        }
        else
        {
            ce_registros = ce_registros - p_medio - 1;
            desplazamiento = ce_registros/2 - (ce_registros+1)%2;
        }
    }
    ///llegados a este punto no se encontro el valor en el archivo
    free(local_buffer);
    fclose(file);
    return 0;
}

int Merge_avanzado_novedades(const char *arch_dest, const char *arch_src, const char *arch_temp)
{
    tEmpleado emp;
    t_novedades nov;
    int comparar_legajo;
    FILE *f_emp, *f_nov, *f_temp, *f_error;
    ///APERTURA DE LOS ARCHIVOS
    ///empleados
    f_emp = fopen(arch_dest,"rb");
    if(!f_emp)
        return 0;
    ///novedades
    f_nov = fopen(arch_src,"rb");
    if(!f_nov)
    {
        fclose(f_emp);
        return 0;
    }
    ///temporario
    f_temp = fopen(arch_temp,"wb");
    if(!f_temp)
    {
        fclose(f_emp);
        fclose(f_nov);
        return 0;
    }
    ///errores
    f_error = fopen("errores.txt","wt");
    if(!f_error)
    {
        fclose(f_emp);
        fclose(f_nov);
        fclose(f_temp);
        return 0;
    }
    ///INICIO DEL MERGE
    fread(&emp,sizeof(emp),1,f_emp);
    fread(&nov,sizeof(nov),1,f_nov);
    while(!feof(f_emp) && !feof(f_nov))
    {
        comparar_legajo = emp.legajo-nov.emp.legajo;
        if(comparar_legajo<0)
        {
            fwrite(&emp,sizeof(emp),1,f_temp);
            fread(&emp,sizeof(emp),1,f_emp);
        }
        if(comparar_legajo>0)
        {
            if(nov.estado=='a')
                fwrite(&nov.emp,sizeof(nov.emp),1,f_temp);
            if(nov.estado=='b' || nov.estado=='m')
                fprintf(f_error,"%d|%s|%f\n", nov.emp.legajo, nov.emp.nombre, nov.emp.sueldo);
            fread(&nov,sizeof(nov),1,f_nov);
        }
        if(comparar_legajo==0)
        {
            if(nov.estado=='m')
                fwrite(&nov.emp,sizeof(nov.emp),1,f_temp);
            fread(&emp,sizeof(emp),1,f_emp);
            fread(&nov,sizeof(nov),1,f_nov);
        }
    }
    while(!feof(f_emp))
    {
        fwrite(&emp,sizeof(emp),1,f_temp);
        fread(&emp,sizeof(emp),1,f_emp);
    }
    while(!feof(f_nov))
    {
        if(nov.estado=='a')
            fwrite(&nov.emp,sizeof(nov.emp),1,f_temp);
        if(nov.estado=='b' || nov.estado=='m')
            fprintf(f_error,"%d|%s|%f\n", nov.emp.legajo, nov.emp.nombre, nov.emp.sueldo);
        fread(&nov,sizeof(nov),1,f_nov);
    }
    ///CIERRE DE LOS 4 ARCHIVOS
    fclose(f_emp);
    fclose(f_nov);
    fclose(f_error);
    fclose(f_temp);
    ///ELIMINAR ARCH DE EMP ANTES Y RENOMBRARLO
    remove(arch_dest);
    rename(arch_temp,arch_dest);
    return 1;
}

int f_Bin_Ssort(const char *nom_arch, unsigned tamanio, int cmp(const void*,const void*))
{
    void *local_buffer;
    FILE *file = fopen(nom_arch,"r+b");
    if(!file)
        return 0;
    local_buffer = malloc(tamanio);
    if(!local_buffer)
    {
        fclose(file);
        return 0;
    }
    ///aplicar logica aqui
    fclose(file);
    free(local_buffer);
    return 1;
}

