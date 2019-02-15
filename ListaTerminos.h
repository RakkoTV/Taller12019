#ifndef LISTATERMINOS_H_INCLUDED
#define LISTATERMINOS_H_INCLUDED

#include "Termino.h"

typedef struct nodoL {
    Termino info;
    nodoL * sig;
} nodo;

typedef nodo * Lista;

//Operaciones básicas sobre la lista de Terminos, oficialmente llamada "Polinomio"
//Crea una lista vacía
void Crear_Lista(Lista &L);
//Saber si la lista está vacía
boolean EsVacio_Lista(Lista L);
//Inserta un termino al principio de la lista
void InsFront(Lista &L, Termino T);
//Devuelve el primer valor almacenado en la lista
Termino Primero(Lista L);
//Borra el primer valor almacenado en la lista
void Resto(Lista &L);

//FUNCIONES ESPECIFICAS
//A raiz de un string de terminos, se crea una lista conteniendolos.
//PRECONDICION: El string pasado debe estar previamente validado y no puede contener ni el nombre del comando ni el nombre del polinomio
void Crear_Lista_Desde_String(Lista &L, String s_1);


#endif // LISTATERMINOS_H_INCLUDED
