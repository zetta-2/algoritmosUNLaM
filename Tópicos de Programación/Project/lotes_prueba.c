#include "lotes_prueba.h"
#include <string.h>

int Cargar_enteros(int *buffer)
{
    int vec[]={3,200,153,231,-1,87,24,64,21,85,23,12,90,56,100};
    int ce = sizeof(vec)/sizeof(int);
    int i;
    int *p_vec = vec;
    for(i=0;i<ce;i++)
    {
        *buffer = *p_vec;
        buffer++;
        p_vec++;
    }
    return ce;
}

int Cargar_enteros_ordenados(int *buffer)
{
    int vec[]={3,6,9,12,15,18,24,33,37,76,80,91,103,125,150,200};
    int ce = sizeof(vec)/sizeof(int);
    int i;
    int *p_vec = vec;
    for(i=0;i<ce;i++)
    {
        *buffer = *p_vec;
        buffer++;
        p_vec++;
    }
    return ce;
}

int CargarEmpleado(tEmpleado *buffer)
{
    tEmpleado empleado[]={{10,"Maria Pia",200.0},
                {20,"Juan Perez",300.0},
                {30,"Diego Beltran",200.0},
                {40,"Diego Martinez",200.0},
                {50,"Nicolas Sattel",200.0},
                {60,"Marcela De Negri",150.0},
                {80,"Damian Cale",800.0},
                {100,"Lucas Grance",1000.0},
                {105,"Pablo Soligo",1000.0}};
    unsigned tamanio = sizeof(tEmpleado);
    int ce = sizeof(empleado)/tamanio;
    int i;
    tEmpleado *p_emp = empleado;
    for(i=0;i<ce;i++)
    {
        memcpy(buffer,p_emp,tamanio);
        buffer++;
        p_emp++;
    }
    return ce;
}

int CargarAlumno(tAlumno *buffer)
{
    tAlumno alumno[]={{10,"Juan Perez",4.0},
                      {20,"Florencia Re",4.0},
                      {30,"Maria Benitez",7.5},
                      {40,"Victor Gomez",7.5},
                      {50,"Flavio Gomez",9.2},
                      {70,"Julieta Beltran",3.0},
                      {90,"Fernanda Gauna",9.0},
                      {100,"Lucas Grance",10.0},
                      {105,"Pablo Soligo",10.0}};
    unsigned tamanio = sizeof(tAlumno);
    int ce = sizeof(alumno)/tamanio;
    tAlumno *p_alu = alumno;
    int i;
    for(i=0;i<ce;i++)
    {
        memcpy(buffer,p_alu,tamanio);
        p_alu++;
        buffer++;
    }
    return ce;
}

int CargarNovedades(t_novedades *buffer)
{
    t_novedades nov[]={{{17,"Ana Benitez",300.0},'a'},
                    {{20,"Juan Perez Beltran",250.0},'m'},
                    {{33,"Jorge Asraliam",300.0},'a'},
                    {{55,"Badom Daniel",250.0},'b'},
                    {{80,"Damian Calle",800.0},'b'},
                    {{85,"Santiago Franco",800.0},'m'},
                    {{87,"Amabel Docaso",150.0},'b'},
                    {{88,"Martina Capusso",200.0},'a'}};
    unsigned tamanio = sizeof(t_novedades);
    int ce = sizeof(nov)/tamanio;
    memcpy(buffer,nov,tamanio*ce);
    return ce;
}

int Cargar_Struct_Int(r_promedio *buffer)
{
    r_promedio prom[]={{3,10},{5,15},{9,81},{70,50},{3,15},{3,17}};
    unsigned tamanio = sizeof(r_promedio);
    int ce = sizeof(prom)/tamanio;
    memcpy(buffer,prom,tamanio*ce);
    return ce;
}


