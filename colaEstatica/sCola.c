#include "sCola.h"
#include "macros.h"
#include <string.h>

void crearCola(tCola *p)
{
    p->pri=0;
    p->ult=0;
    p->tamDisp=TAM_COLA;
}

int ponerEnCola(tCola *p, const void *info, unsigned cantB)
{
    unsigned ini, fin;///2 variables auxiliares
    unsigned tamInsertar=cantB+sizeof(unsigned int);
    if(p->tamDisp<tamInsertar)
        return 0;
    p->tamDisp-=tamInsertar;
    ///mecanismo de trozado para insertar el tam del tam del dato
    ini=MIN(sizeof(unsigned int),TAM_COLA-p->ult);///primera parte del dato
    fin=sizeof(unsigned int)-ini;///2da parte del dato
    if(ini>0)
        memcpy(p->cola+p->ult,&cantB,ini);///desplazarse hasta el final
    if(fin>0)
        memcpy(p->cola,((char*)&cantB)+ini,fin);///castear la dir memoria a char* para sumar solo #bytes primitivos
    p->ult=(p->ult+sizeof(unsigned int))%TAM_COLA;///posicionar el ult
    //p->ult = fin>0?p->ult = fin : p-> ult + ini;//otra forma con ternario

    ///mecanismo de trozado para insertar el dato
    ini=MIN(cantB,TAM_COLA-p->ult);///primera parte del dato
    fin=cantB-ini;///2da parte del dato
    if(ini>0)
        memcpy(p->cola+p->ult,info,ini);///desplazarse hasta el final
    if(fin>0)
        memcpy(p->cola,(char*)info+ini,fin);///castear info a char* para sumar solo #bytes primitivos
    p->ult=(p->ult+cantB)%TAM_COLA;///posicionar el ult
    //p->ult = fin>0? fin : p-> ult + ini;//otra forma con ternario
    return 1;
}

int verPriDeCola(const tCola *p, void *info, unsigned cantB)
{
    unsigned tamEnCola;
    unsigned ini, fin;
    unsigned tamMin;
    int despP;///desplazamiento pendiente
    if(TAM_COLA==p->tamDisp)
        return 0;
    //p->tamDisp+=cantB+sizeof(unsigned int); //no se actualiza primero


    ///union del tamanio en la cola
    ini=MIN(sizeof(unsigned int),TAM_COLA-p->pri);///primera parte (va p->pri porque sacaremos el primer dato ingresado)
    fin=sizeof(unsigned int)-ini;///2da parte del dato
    if(ini>0)
        memcpy(&tamEnCola,p->cola+p->pri,ini);
    if(fin>0)
        memcpy(((char*)&tamEnCola)+ini,p->cola,fin);
    despP = (p->pri+sizeof(unsigned int))%TAM_COLA; ///mover segun el tam de un entero sin signo

    tamMin = MIN(tamEnCola,cantB);

    ///union del dato
    ini=MIN(tamMin,TAM_COLA-despP);///primera parte (va p->pri porque sacaremos el primer dato ingresado)
    fin=tamMin-ini;///2da parte del dato

    if(ini>0)
        memcpy(info,p->cola+despP,ini);
    if(fin>0)
        memcpy((char*)info+ini,p->cola,fin);
    return 1;
}

int SacarDeCola(tCola *p, void *info, unsigned cantB)
{
    unsigned tamEnCola;
    unsigned ini, fin;
    unsigned tamMin;
    if(TAM_COLA==p->tamDisp)
        return 0;
    //p->tamDisp+=cantB+sizeof(unsigned int); //no se actualiza primero

    ///union del tamanio en la cola
    ini=MIN(sizeof(unsigned int),TAM_COLA-p->pri);///primera parte (va p->pri porque sacaremos el primer dato ingresado)
    fin=sizeof(unsigned int)-ini;///2da parte del dato
    if(ini>0)
        memcpy(&tamEnCola,p->cola+p->pri,ini);
    if(fin>0)
        memcpy(((char*)&tamEnCola)+ini,p->cola,fin);
    p->pri = (p->pri+sizeof(unsigned int))%TAM_COLA; ///mover segun el tam de un entero sin signo
    //p->pri = fin>0?fin : p-> pri + ini
    p->tamDisp+=(tamEnCola+sizeof(unsigned int));

    tamMin = MIN(tamEnCola,cantB);

    ///union del dato
    ini=MIN(tamMin,TAM_COLA-p->pri);///primera parte (va p->pri porque sacaremos el primer dato ingresado)
    fin=tamMin-ini;///2da parte del dato

    if(ini>0)
        memcpy(info,p->cola+p->pri,ini);
    if(fin>0)
        memcpy((char*)info+ini,p->cola,fin);
    ///moverse segun el tam en cola
    p->pri = (p->pri+tamEnCola)%TAM_COLA;
    return 1;
}

int colaLlena(const tCola *p, unsigned cantB)
{
    return p->tamDisp<cantB+sizeof(unsigned int);
}

int colaVacia(const tCola *p)
{
    return TAM_COLA==p->tamDisp;
}

void vaciarCola(tCola *p)
{
    p->pri=p->ult;
    p->tamDisp=0;
}
