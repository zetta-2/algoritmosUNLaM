#include <math.h>
#include <stdio.h>

unsigned long long int Factorial(int num)
{
    int i;
    int acumulador=1;
    //for(i=1;i<=num;i++)
    for(i=num;i>0;i--)
        acumulador*=i;
    return acumulador;
}

int Combinatorio(int m, int n)
{
    int resultado;
    int numerador = Factorial(m);
    int denominador = Factorial(m-n)*Factorial(n);
    resultado = numerador/denominador;
    return resultado;
}

int Potencia(int base, int exp)
{
    int i;
    int resultado=1;
    if(exp==0)
        return 1;
    for(i=1;i<=exp;i++)
        resultado*=base;
    return resultado;
}

float Exponencial(int exp, float TOL)
{
    int i=1;
    float resultado = 1;
    float termino = resultado;
    if(exp==0)
        return 1;
    while(termino>TOL)
    {
        termino = (float)(Potencia(exp,i))/(Factorial(i));//operacion de cada termino
        resultado+=termino;
        i++;
    }
    return resultado;
}

float RaizCuadrada(int radicando, float TOL)
{
    float Ter_ant = 1;
    float Ter = 0.5*(Ter_ant+(radicando/Ter_ant));
    while(fabs(Ter_ant-Ter)>TOL)
    {
        Ter_ant = Ter;
        Ter = 0.5*(Ter_ant+(radicando/Ter_ant));
    }
    return Ter;
}

int Fibonacci(unsigned num)
{
    int ter = 1;
    int TerAnt = 1;
    int suma;
    while(ter<num)
    {
        suma = TerAnt + ter;
        TerAnt = ter;
        ter = suma;
    }
    if(ter==num)
        return 1;
    return 0;
}

double Seno(int x, float tol)
{
    int i = 0;
    double resultado = 0;
    double termino;
    unsigned long long int numerador;
    unsigned long long int denominador;
    int exponente;
    do
    {
        exponente = i+1;
        numerador = pow(x,exponente);
        denominador = Factorial(exponente);
        termino = (double)numerador/denominador;
        resultado += pow(-1,i%2)*termino;
        i+=2;
    }while(termino>tol);
    return resultado;
}

int multiplicacion(int factor_1, int factor_2)
{
    int i;
    int resultado = 0;
    if(factor_1==0 || factor_2==0)
        return 0;
    for(i=1;i<=factor_1;i++)
        resultado+=factor_2;
    return resultado;
}

//Intercambio de numeros enteros
void Intercambio(int *px, int *py)
{
    int aux;
    aux = *px;
    *px = *py;
    *py = aux;
}

