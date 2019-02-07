#ifndef LISTATERMINOS_H_INCLUDED
#define LISTATERMINOS_H_INCLUDED

#include "Termino.h"

typedef struct nodoL {
    Termino info;
    nodoL * sig;
} nodo;

typedef nodo * Lista;

//Operaciones b�sicas sobre la lista de Terminos, oficialmente llamada "Polinomio"
//Crea una lista vac�a
void Crear_Lista(Lista &L);
//Saber si la lista est� vac�a
boolean EsVacio_Lista(Lista L);
//Inserta un termino al principio de la lista
void InsFront(Lista &L, Termino T);
//Devuelve el primer valor almacenado en la lista
Termino Primero(Lista L);
//Borra el primer valor almacenado en la lista
void Resto(Lista &L);

//FUNCIONES ESPECIFICAS

#endif // LISTATERMINOS_H_INCLUDED
