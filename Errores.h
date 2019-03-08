#ifndef ERRORES_H_INCLUDED
#define ERRORES_H_INCLUDED

#include "String.h"

//No tiene ningun typedef, ya que este modulo s�lo servir� para tener centralizados los distintos tipos de errores
//escritos que pudieran producirse en la aplicaci�n, y mostrarlos en pantalla cuando sea necesario.
//A raiz de un codigo interno del 1-50, se mostrar� el error definido en la documentaci�n.
void Mostrar_Error(int codigo);

//Tambien, en este modulo se adjunta la funcion "MostrarAyuda()" con el fin de especificar en cualquier momento
//la lista de comandos al usuario final
void Mostrar_Ayuda();

//Muestra la opcion de sobreescribir un archivo, para el comando Guardar
boolean MostrarSobreEscribir();

#endif // ERRORES_H_INCLUDED
