#include <stdio.h>
#include <stdlib.h>

//lista de bibliotecas
#include "macros.h"
#include "pila_mix_2.h"
#include "pruebas.h"

/*Actividad
TDA Pila
crear una implementación semi-estática o semi-dinámica de Pila.
Subir por grupo el proyecto compactado,eliminando la carpeta .bin y .obj
*/

int main()
{
    puts("Prueba con cadena de textos.");
    pilaPruebaCadenas();
    system("pause");
    system("cls");
    puts("Prueba con archivos binarios.");
    pilaPruebaBin();
    system("pause");
    system("cls");
    puts("Prueba con archivos de textos.");
    pilaPruebaTexto();
    system("pause");
    system("cls");
    puts("FIN");
    return 0;
}
