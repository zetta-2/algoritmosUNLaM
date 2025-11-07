#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

#define Redondear(x) ((x - (int)x) >= 0.5 ? ((int)x + 1) : (int)x)
#define Valor_Absoluto(x) x>=0 ? x : x*(-1)
#define Truncar(x) (int)x //parte entera de un numero

//PROBAR
#define Parte_decimal(x) (x-(int)x)
#define ES_POTENCIA(x,y) ((y)*(y) == x)
#define POTENCIA(x) (x)*(x)

#define ESLETRA(x) ( (x>='a' && x<='z') || (x>='A' && x<='Z') )
#define ESDIGITO(x) ((x>='0') && (x<='9'))
#define A_MAYUS(x) (x>='a' && x<='z') ? (x - ('a'-'A')): x
#define A_MINUS(x) (x>='A' && x<='Z') ? (x + ('a'-'A')): x

#define ES_PAR(x) (x%2==0) ? 1 : 0

#define ES_MAYOR(x,y) (x>y) ? x : y
#define ES_MENOR(x,y) (x<y) ? x : y
#define ES_IGUAL(x,y) (x==y)

//TAMANIOS
#define TAM_MAX_VEC 100
#define TAM_CHAR 128
#define TAM_COL 100



#define DOBLE 2




#endif // MACROS_H_INCLUDED
