#ifndef SCOLA_H_INCLUDED
#define SCOLA_H_INCLUDED

#define TAM_COLA 1024
typedef struct
{
    char cola[TAM_COLA];
    unsigned pri;
    unsigned ult;
    unsigned tamDisp;
}tCola;

void crearCola(tCola *p);
int ponerEnCola(tCola *p, const void *info, unsigned cantB);
int verPriDeCola(const tCola *p, void *info, unsigned cantB);
int SacarDeCola(tCola *p, void *info, unsigned cantB);
int colaLlena(const tCola *p, unsigned cantB);
int colaVacia(const tCola *p);
void vaciarCola(tCola *p);

#endif // SCOLA_H_INCLUDED
