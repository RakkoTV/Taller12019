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
//Muestra la Lista de Terminos
void Mostrarlista (Lista L);
//Dada una lista y un termino, agrega dicho termino al final de la lista
void InsBackRecu(Lista &L, Termino T_1);

//FUNCIONES ESPECIFICAS
//A raiz de un string de terminos, se crea una lista conteniendolos.
//PRECONDICION: El string pasado debe estar previamente validado y no puede contener ni el nombre del comando ni el nombre del polinomio
void Crear_Lista_Desde_String(Lista &L, String string_1);

//Despliega por pantalla (sin el \n) el conjunto de terminos guardados en esta lista. Se le agrega un espacio al final por cada
//termino que se hubiera almacenado.
void MostrarLista(Lista L);

//Se elimina termino a termino todo lo guardado en esa lista. Esto se da para eliminar toda la memoria dinamica almacenada
//en esta lista, dejando nulos todos los punteros y estructuras de terminos.
void BorrarLista(Lista &L);

//Guardara todos los terminos de la lista dentro del archivo apuntado por stream. Para cada termino, se invocara la funcion BajarTermino
//PRECONDICION: El mismo ya fue abierto previamente, y en modo "wb" o "ab"
void BajarLista(FILE * stream, Lista L);

//Leera del archivo apuntado por stream, y lo levantara en memoria como una lista de Terminos. Para cada termino, se utilizara a funcion SubirTermino
//PRECONDICION: stream ya fue abierto previamente, y en modo "rb"
void SubirLista(FILE * stream, Lista &L);

//INSERTA DE FORMA ORDENADA
void InsOrdenada(Lista &L, Termino Ter);

//OPERACIONES (SUMA, MULTIPLICACION)

Lista MultiplicarPoli(Lista Poli1, Lista Poli2);

#endif // LISTATERMINOS_H_INCLUDED
