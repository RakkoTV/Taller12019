#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "Polinomio.h"

typedef struct nodoAA {
    Polinomio info;
    nodoAA * HIzq;
    nodoAA * HDer;
} nodoA;

typedef nodoA * Arbol;

//OPERACIONES B�SICAS
//Crear un �rbol vac�o
void Crear_Arbol(Arbol &a);

//Saber si el �rbol est� vac�o
boolean EsVacio_Arbol(Arbol a);

//Devolver la ra�z del �rbol
//PRECONDICION: Arbol NO vac�o
Polinomio DarRaiz(Arbol a);

//Obtener el sub�rbol izquierdo
//Precondici�n: Arbol NO vac�o
Arbol HijoIzq(Arbol a);

//Obtener el sub�rbol derecho
//Precondici�n: Arbol NO vac�o
Arbol HijoDer(Arbol a);

//Dados dos �rboles y un valor, devolver un nuevo �rbol
//colocando dicho valor como una nueva ra�z y a los dos
//�rboles como sub�rboles de la misma
Arbol Cons(Polinomio P, Arbol i, Arbol d);

//OPERACIONES ESPEC�FICAS
//Insertar, de acuerdo al criterio de nombres mayores o menores alfabeticamente, utilizando el nombre del Polinomio pasado
//PRECONDICION: En el arbol no se encuentra ningun expediente con el codigo del que ahora se va a insertar.
void Insert(Arbol &a, Polinomio P);


#endif // ARBOL_H_INCLUDED
