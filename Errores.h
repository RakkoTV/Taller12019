#ifndef ERRORES_H_INCLUDED
#define ERRORES_H_INCLUDED

#include "String.h"

//No tiene ningun typedef, ya que este modulo s�lo servir� para tener centralizados los distintos tipos de errores
//escritos que pudieran producirse en la aplicaci�n, y mostrarlos en pantalla cuando sea necesario.
//A raiz de un codigo interno del 1-50, se mostrar� el error requerido.
void Mostrar_Error(int codigo);

#endif // ERRORES_H_INCLUDED
