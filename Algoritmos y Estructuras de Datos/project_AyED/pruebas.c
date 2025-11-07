#include "pruebas.h"
#include "math.h"
#include "arbol/arbol.h"
#include <stdio.h>
#include "listaDoble/listadoble.h"
#include "recursividad.h"
#include <ctype.h>

#define NOMARCHBIN "lotePrueba.dat"
#define NOMARCHTXT "texto.txt"


#define MOVIMIENTOS "movimientos.dat"
#define MAYORISTAS "mayoristas.txt"
#define MINORISTAS "minoristas.txt"

#define MAX_TAM 10


#define ARCH_CLIENTES "clientes.bin"
#define ARCH_INDICE "clientes.idx"


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

///miscelaneos
int crearArchBinario(const void *info, size_t bytes, const char *nomarch)
{
    FILE *file = fopen(nomarch,"wb");
    if(!file)
        return ERROR;
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

void mostrarEntero(void *info)
{
    int *p_info = (int*)info;
    printf("%d\n",*p_info);
}

void mostrarFlotante(void *info)
{
    float *p_info = (float*)info;
    printf("%.2f\n",*p_info);
}

void mostrarRaizCuadrada(void *info)
{
    float *p_info = (float*)info;
    printf("sqrt(%.2f)=%.2f\n",*p_info,sqrt(*p_info));
}

void mostrarNumero(void *info)
{
    tNumeros *numero = (tNumeros*)info;
    printf("%5d %5d\n", numero->numero, numero->apariciones);
}

void mostrarCadena(void *info)
{
    char *p_info = (char*)info;
    puts(p_info);
}

int MayorEntero(const void *a, const void *b)
{
    if(*(int*)a>*(int*)b)
        return DISTINTOS;
    if(*(int*)a == *(int*)b)
        return IGUALES;
    return 0;
}

int MenorEntero(const void *a, const void *b)
{
    if(*(int*)a<*(int*)b)
        return DISTINTOS;
    if(*(int*)a == *(int*)b)
        return IGUALES;
    return 0;
}

///numeros
int MayorNumero(const void *a, const void *b)
{
    tNumeros *p_a = (tNumeros*)a;
    tNumeros *p_b = (tNumeros*)b;
    if( (p_a->numero) > (p_b->numero))
        return DISTINTOS;
    if( (p_a->numero) == (p_b->numero) )
        return IGUALES;
    return 0;
}

int MenorNumero(const void *a, const void *b)
{
    tNumeros *p_a = (tNumeros*)a;
    tNumeros *p_b = (tNumeros*)b;
    if( (p_a->numero) < (p_b->numero))
        return DISTINTOS;
    if( (p_a->numero) == (p_b->numero) )
        return IGUALES;
    return 0;
}

int igualValorEntero(const void *a, const void *clave)
{
    int *p_a=(int*)a;
    int *pClave=(int*)clave;
    return (*p_a-*pClave)==0 ? TODO_OK : -1;
}

///pruebas con las colas

int colaPruebaGenerica(const void *vec, int ce, unsigned tamanio, void accion(void*))
{
    tCola v;
    void *ini = (void*)vec;
    int i;
    void *buffer;
    d_crearCola(&v);
    buffer = malloc(tamanio);
    if(!buffer)
    {
        puts("No se pudo asignar tamanio para guardar datos de la cola.");
        return 0;
    }
    for(i=0;i<ce;i++)
    {
        d_encolar(&v,ini,tamanio);
        ini+=tamanio;
    }
    puts("Primer dato ingresado a la cola.");
    d_verPriCola(&v,buffer,tamanio);
    accion(buffer);
    puts("---ELEMENTOS DE LA COLA---");
    while(d_sacarPriCola(&v,buffer,tamanio))
        accion(buffer);
    d_vaciarCola(&v);
    free(buffer);
    puts("PRUEBA REALIZADA CON EXITO");
    return 0;
}

///funciones con listas sin admitir duplicados
int sinDuplicados(void *dest, const void *info)
{
    return 0;
}

void sacarPromedio(const void *info, void *r)
{
    tPromedio *prom = (tPromedio*)r;
    int *valor = (int*)info;
    prom->cantidad++;
    prom->suma+=*valor;
}

int aumentarApariciones(void *dest, const void *info)
{
    tNumeros *informacion = (tNumeros*)dest;
    informacion->apariciones++;
    return 0;
}

int pruebaInsertarOrdenadoNumeros()
{
    int vec[]={-5,-5,-5,8,71,32,15,-5,2,4,2,71,35,32};
    int ce = sizeof(vec)/sizeof(int);
    tLista lista;
    int i;
    tNumeros numero;
    crearLista(&lista);
    puts("ELEMENTOS DEL VECTOR ANTES DE INSERTAR EN LA LISTA");
    for(i=0;i<ce;i++)
        printf("%d ", vec[i]);
    puts("");
    for(i=0;i<ce;i++)
    {
        numero.numero = vec[i];
        numero.apariciones = 1;
        insertarOrdenado(&lista,&numero,sizeof(numero),MenorNumero,SIN_DUPLICADO,aumentarApariciones);
    }
    puts("ELEMENTOS DE LA LISTA:");
    printf("%5s %5s\n", "Numero", "Apariciones");
    recorrerLista(&lista,&mostrarNumero);
    vaciarLista(&lista);
    listaVacia(&lista) == VACIA ? puts("Lista vacia.") : puts("Lista no vacia.");
    return 0;
}

int probarMovimientos()
{
    tCola cola;
    FILE *movimientos, *mayoristas, *minoristas;
    FILE *p;
    tClientes clientes[]={{1,1,'d',1.2},
                        {2,1,'e',0.2},
                        {3,1,'d',9.21},
                        {1,2,'e',1.3},
                        {5,2,'d',2.22},
                        {1,3,'d',9.89},
                        {2,3,'e',15.3},
                        {8,3,'d',45.3},
                        {1,4,'d',5.3},
                        {2,4,'e',0.43},
                        {2,5,'e',1.12},
                        {2,6,'d',9.92}};
    tClientes cliente;
    tClientes cliente_nuevo;
    float suma;
    //CREANDO LOTE DE CLIENTES
    if(crearArchBinario(clientes,sizeof(clientes),MOVIMIENTOS)==ERROR)
        return ERROR;
    ///APERTURA DE LOS 3 ARCHIVOS
    movimientos = fopen(MOVIMIENTOS,"rb");
    if(!movimientos)
        return ERROR;
    mayoristas = fopen(MAYORISTAS,"wt");
    if(!movimientos)
    {
        fclose(movimientos);
        return ERROR;
    }
    minoristas = fopen(MINORISTAS,"wt");
    if(!minoristas)
    {
        fclose(mayoristas);
        fclose(movimientos);
        return ERROR;
    }
    ///INICIO DE LA LOGICA
    fread(&cliente,sizeof(cliente),1,movimientos);
    d_crearCola(&cola);
    while(!feof(movimientos))
    {
        suma = 0;
        cliente_nuevo.nro_cuenta = cliente.nro_cuenta;
        while(!feof(movimientos) && cliente_nuevo.nro_cuenta == cliente.nro_cuenta)
        {
            suma += cliente.importe;
            d_encolar(&cola,&cliente,sizeof(cliente));
            fread(&cliente,sizeof(cliente),1,movimientos);
        }
        if(suma>=10)
            p = mayoristas;
        else
            p = minoristas;
        fprintf(p,"Cliente %d\n",cliente_nuevo.nro_cuenta);
        while(d_sacarPriCola(&cola,&cliente_nuevo,sizeof(cliente_nuevo)))
            fprintf(p,"%d|%d|%c|%.2f\n",cliente_nuevo.fecha,cliente_nuevo.nro_cuenta,cliente_nuevo.movimiento, cliente_nuevo.importe);
    }
    d_vaciarCola(&cola);
    ///CIERRE DE LOS 3 ARCHIVOS
    fclose(minoristas);
    fclose(mayoristas);
    fclose(movimientos);
    remove(MOVIMIENTOS);
    return TODO_OK;
}

int pruebaListaDoble()
{
    int vec[]={3,3,3,3,5,26,21,26,23,90,3,3,3};
    int ce = sizeof(vec)/sizeof(int), i;
    tListaDoble lista;
    tPromedio promedio;
    crearListaDoble(&lista);
    for(i=0;i<ce;i++)
        insertarListaDoble(&lista,&vec[i],sizeof(int),&MayorEntero);
    if(listaDobleVacia(&lista)==VACIA)
        puts("VACIA");
    else
        puts("no vacia");
    puts("elementos de la lista");
    mapInicio(&lista,mostrarEntero);
    puts("PROMEDIO DE LOS NUMEROS DE LA LISTA");
    promedio.cantidad=0;
    promedio.suma=0;
    reduce(&lista,&promedio,sacarPromedio);
    if(promedio.cantidad!=0)
        printf("Promedio: %.2f\n", (float)promedio.suma/promedio.cantidad);
    puts("VACIAR LISTA...");
    vaciarListaDoble(&lista);
    return 0;
}

int pruebaBsearch()
{
    int vec[]={1,3,1,1,9,-1,5,2,10,0,36,78,91,912};
    tArbol arbol;
    crearArbolBin(&arbol);
    int i;
    int clave[] = {-6,-1,3,8,10,5,17,9,0,-8,43};
    for(i=0;i<sizeof(vec)/sizeof(int);i++)
        insertarEnArbolBin(&arbol,&vec[i],sizeof(int),cmpEnteros,sinDuplicados);
//    puts("Recorrido preorden");
//    recorrerArbolBinPreorden(&arbol,mostrarEntero);
//    puts("Recorrido postorden");
//    recorrerArbolBinPostorden(&arbol,mostrarEntero);
    puts("Recorrido inorden");
    recorrerArbolBinInorden(&arbol,mostrarEntero);
    puts("Busqueda binaria.");
    for(i=0;i<sizeof(clave)/sizeof(int);i++)
    {
        printf("%d\t",clave[i]);
        if(busquedaBin(&arbol,&clave[i],sizeof(int),cmpEnteros)!=NULL)
            puts("Clave encontrada.");
        else
            puts("Clave no encontrada.");
    }
    vaciarArbol(&arbol);
    if(arbolVacio(&arbol)==VACIA)
        puts("Arbol vacio.");
    else
        puts("Arbol no vacio.");
    return 0;
}

int mayoresA10(void *info)
{
    int *p_info=(int*)info;
    return *p_info>10 ? 1 : 0;
}

int contar(void *info)
{
    return 1;
}

int multiplos(void *info, const void *clave)
{
    int *p_info = (int*)info;
    int *p_clave = (int*)clave;
    return (*p_info)%(*p_clave)==0 ? 1 : 0;
}

void promedioPares(void* info,tPromedio* p_promedio)
{
    int *valor = (int*)info;
    tPromedio *p = (tPromedio*)p_promedio;
    if(*valor%2==0)
    {
        p->cantidad++;
        p->suma+=*valor;
    }
}

int pruebaIndices()
{
    tClientesSimple clientes[]={{123,'J','J'},
                                {951,'A','A'},
                                {324,'M','M'},
                                {574,'Z','Z'},
                                {698,'P','P'},
                                {147,'R','R'},
                                {852,'B','B'},
                                {691,'N','N'},
                                {574,'V','V'},
                                {456,'C','C'},
                                {642,'O','O'},
                                {258,'D','D'},
                                {741,'Q','Q'},
                                {252,'F','F'},
                                {300,'G','G'}};
    tArbol arbolIndice;
    int resultado = crearArchBinario(clientes,sizeof(clientes),ARCH_CLIENTES);
    if(!resultado)
    {
        puts("Error de creacion de archivo.");
        return 1;
    }
    crearArbolBin(&arbolIndice);
    indexarArchBin(ARCH_CLIENTES,sizeof(tClientesSimple),&arbolIndice,copiarClaveApellidoClientes,cmpApellidosIndex);
    if(crearIndice(ARCH_INDICE,&arbolIndice))
        puts("Indice creado.");
    else
        puts("Error de indice.");
    recorrerArbolBinInorden(&arbolIndice,mostrarIndice);
    vaciarArbol(&arbolIndice);
    return 0;
}

int pruebaLecturaIndice()
{
    tArbol arbol;
    FILE *pArch;
    tIndice indice;
    tClientesSimple cliente;
    crearArbolBin(&arbol);
    levantarIndice(&arbol,ARCH_INDICE);
    pArch = fopen(ARCH_CLIENTES,"rb");
    if(!pArch)
    {
        vaciarArbol(&arbol);
        puts("Error al abrir el archivo");
        return 1;
    }
    printf("Ingrese una clave del indice (caracter, '0' para fin):");
    scanf("%c",&indice.clave);
    while(indice.clave!='0')
    {
        fflush(stdin);
        indice.clave=toupper(indice.clave);
        if(busquedaBin(&arbol,&indice,sizeof(tIndice),cmpApellidosIndex))
        {
            fseek(pArch,indice.ubicacion*sizeof(tClientesSimple),SEEK_SET);
            fread(&cliente,sizeof(cliente),1,pArch);
            rewind(pArch);
            puts("Datos de registro:");
            printf("Apellido:%c Nombre:%c DNI:%d\n",cliente.apellido, cliente.nombre, cliente.DNI);
        }
        else
            puts("Valor no encontrado en el arbol.");
        system("pause");
        system("cls");
        printf("Ingrese una clave del indice (0 para fin):");
        scanf("%c",&indice.clave);
    }
    fclose(pArch);
    vaciarArbol(&arbol);
    return 0;
}

int pruebaOrdenarListaSimple()
{
    int vec[]={1};
    tLista lista;
    int i;
    crearLista(&lista);
    for(i=0;i<sizeof(vec)/sizeof(int);i++)
        insertarAlFinal(&lista,&vec[i],sizeof(int));
    if(listaVacia(&lista)==VACIA)
        puts("Lista vacia.");
    recorrerLista(&lista,mostrarEntero);
    puts("Lista ordenada de menor a mayor:");
    ordenarLista(&lista,MenorEntero);
    recorrerLista(&lista,mostrarEntero);
    vaciarLista(&lista);
    if(listaVacia(&lista)==VACIA)
        puts("Lista vacia.");
    return 0;
}
