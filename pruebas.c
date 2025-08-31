#include "pruebas.h"
#define NOMARCHBIN "lotePrueba.dat"
#define NOMARCHTXT "texto.txt"

#define MAX_TAM 10

int crearLoteBinario()
{
    ///utilizar este lugar para crear lotes de archivos binarios
    char lote[][MAXLINE]={"Arriba la birra","Hola mama","Esto es Esparta", "Constantinopla", "Asimov"};
    if(!crearArchBinario(lote,sizeof(lote),NOMARCHBIN))
    {
        puts("No se pudo crear el archivo binario.");
        return 1;
    }
    puts("Exito.");
    return 0;
}

///---PRUEBAS---///
int pilaPruebaBin()
{
    tPilaVer2 pila;
    char buffer[MAXLINE];
    char dato[MAXLINE];
    FILE *arch = fopen(NOMARCHBIN,"rb");
    if(!arch)
    {
        puts("Error al crear el archivo.");
        puts("ERROR AL PROBAR LA FUNCION.");
        return 1;
    }
    if(!crearPilaVer2(&pila))
    {
        puts("No se puede crear la pila.");
        fclose(arch);
        return 2;
    }
    puts("Elementos insertados.");
    fread(buffer,MAXLINE,1,arch);
    while(!feof(arch))
    {
        if(!apilarVer2(&pila,buffer,strlen(buffer)+1))
            puts("No se pudo insertar el dato.");
        fread(buffer,MAXLINE,1,arch);
    }
    puts("---Tope de la pila---");
    if(verTopeVer2(&pila,dato,MAXLINE))
        printf("*%s\n",dato);
    puts("---Desapilar pila---");
    puts("--Elementos de la pila---");
    while(desapilarVer2(&pila,dato,MAXLINE))
            printf("*%s\n",dato);
    ///desapilando la pila, mostramos la insercion en orden inverso
    pilaVaciaVer2(&pila)?puts("Pila vacia."):puts("Pila no vacia.");
    puts("---FIN DE LA PILA---");
    vaciarPilaVer2(&pila);
    fclose(arch);
    return 0;
}

int pilaPruebaTexto()
{
    tPilaVer2 pila;
    char buffer[MAXLINE];
    char dato[MAXLINE];
    FILE *arch = fopen("texto.txt","rb");
    if(!arch)
    {
        puts("Error al crear el archivo.");
        puts("ERROR AL PROBAR LA FUNCION.");
        return 1;
    }
    if(!crearPilaVer2(&pila))
    {
        puts("No se puede crear la pila.");
        fclose(arch);
        return 2;
    }
    while(fgets(buffer,MAXLINE-1,arch))
    {
        eliminarSalto(buffer);
        if(!apilarVer2(&pila,buffer,strlen(buffer)+1))
            puts("No se pudo insertar el dato.");
    }
    puts("---Tope de la pila---");
    if(verTopeVer2(&pila,dato,MAXLINE))
        printf("*%s\n",dato);
    puts("---Desapilar pila---");
    puts("--Elementos de la pila--");
    while(desapilarVer2(&pila,dato,MAXLINE))
            printf("*%s\n",dato);
    ///desapilando la pila, mostramos la insercion en orden inverso
    pilaVaciaVer2(&pila)?puts("Pila vacia."):puts("Pila no vacia.");
    vaciarPilaVer2(&pila);
    fclose(arch);
    return 0;
}

int pilaPruebaCadenas()
{
    tPilaVer2 pila;
    char vec[][MAXLINE]={"Mama","Constantinopla","Arriba la birra","Hola mundo","Isaac Newton"};
    int ce = sizeof(vec)/MAXLINE;
    char dato[MAXLINE];
    int i;
    if(!crearPilaVer2(&pila))
    {
        puts("No se puede crear la pila.");
        puts("ERROR AL PROBAR LA FUNCION.");
        return 1;
    }
    puts("Elementos insertados.");
    for(i=0;i<ce;i++)
    {
        if(apilarVer2(&pila,vec[i],strlen(vec[i])+1))
            printf("*%s\n",vec[i]);
    }
    puts("---Tope de la pila---");
    if(verTopeVer2(&pila,dato,MAXLINE))
        printf("*%s\n",dato);
    puts("---Desapilar pila---");
    puts("--Elementos de la pila--");
    while(desapilarVer2(&pila,dato,MAXLINE))
            printf("*%s\n",dato);
    ///desapilando la pila, mostramos la insercion en orden inverso
    if(pilaLlenaVer2(&pila,sizeof(int)))
        puts("Pila llena para almacenar un entero de 4 bytes.");
    else
        puts("Espacio disponible para un entero de 4 bytes.");
    pilaVaciaVer2(&pila)?puts("Pila vacia."):puts("Pila no vacia.");
    vaciarPilaVer2(&pila);
    return 0;
}

///MISCELANEOS
int crearArchBinario(const void *info, size_t bytes, const char *nomarch)
{
    FILE *file = fopen(nomarch,"wb");
    if(!file)
        return 0;
    fwrite(info,bytes,1,file);
    fclose(file);
    return 1;
}

void eliminarSalto(char *buffer)
{
    while(*buffer && *buffer!='\n')
        buffer++;
    *buffer='\0';
}
