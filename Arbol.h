#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "Polinomio.h"

typedef struct nodoAA {
    Polinomio info;
    nodoAA * HIzq;
    nodoAA * HDer;
} nodoA;

typedef nodoA * Arbol;

//OPERACIONES BÁSICAS
//Crear un árbol vacío
void Crear_Arbol(Arbol &a);

//Saber si el árbol está vacío
boolean EsVacio_Arbol(Arbol a);

//Devolver la raíz del árbol
//PRECONDICION: Arbol NO vacío
Polinomio DarRaiz(Arbol a);

//Obtener el subárbol izquierdo
//Precondición: Arbol NO vacío
Arbol HijoIzq(Arbol a);

//Obtener el subárbol derecho
//Precondición: Arbol NO vacío
Arbol HijoDer(Arbol a);

//Dados dos árboles y un valor, devolver un nuevo árbol
//colocando dicho valor como una nueva raíz y a los dos
//árboles como subárboles de la misma
Arbol Cons(Polinomio P, Arbol i, Arbol d);

//OPERACIONES ESPECÍFICAS
//Insertar, de acuerdo al criterio de nombres mayores o menores alfabeticamente, utilizando el nombre del Polinomio pasado
//PRECONDICION: En el arbol no se encuentra ningun expediente con el codigo del que ahora se va a insertar.
void Insert(Arbol &a, Polinomio P);


#endif // ARBOL_H_INCLUDED
