#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "String.h"

//Creo archivo nuevo
void Arch_Crear(String nomach);

//Existe archivo?
boolean Arch_Existe(String nomach);

//Archivo esta vacio?
boolean Arch_Esvacio(String nomach);

//determino si el entero pertenece al archivo
void Agregar_Entero(String nomach, int n);


#endif // ARCHIVO_H_INCLUDED
