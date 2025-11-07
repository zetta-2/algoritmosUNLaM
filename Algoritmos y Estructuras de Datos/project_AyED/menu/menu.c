#include "menu.h"

void imprimirMenu()
{
    puts("Elija una 2 las 2 opciones:\n"
         "1-Cargar lista desde un archivo de texto con datos simples.\n"
         "2-Cargar lista desde un archivo binario con datos en una estructura"
         "3-Salir");
}

void subMenu()
{
    puts("A continuacion decida si quere o no duplicados:\n"
         "1-Con duplicados.\n"
         "2-Sin duplicados");
}

void Error()
{
    puts("Opcion incorrecta, elija una de las que se muestra por pantalla.");
    system("cls");
}
