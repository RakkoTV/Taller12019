#ifndef ARREGLODINAMICONUMERO_H_INCLUDED
#define ARREGLODINAMICONUMERO_H_INCLUDED

#include "Boolean.h"

typedef struct {
                int * arre;
                int tamanio;
               } array_dinamico;

//Dados un arreglo dinámico y un entero n  > 0, reservar dinámicamente n celdas
//en memoria para el arreglo.
void CrearAD(array_dinamico &ad, int celdas);

//Dado un arreglo dinámico, cargarlo desde teclado.
void Cargar(array_dinamico &ad);

//Dado un arreglo dinámico, mostrar todo su contenido
void Mostrar(array_dinamico ad);

//Dados un arreglo dinámico y un valor entero, determinar si dicho valor
//pertenece al arreglo o no.
//boolean Pertenece(array_dinamico ad, int valor);

//Dado un arreglo dinámico, devolver el promedio de los valores
//almacenados en él.
float Promedio(array_dinamico ad);

//Dado un arreglo dinámico, devolver el mayor entero almacenado en él junto
//con la posición que le corresponde.
//PRECONDICION: El array dinamico tiene que tener algun valor cargado previamente.
void MaxPos(array_dinamico ad, int &mayor, int &posicion);

//Dado un arreglo dinámico, liberar la memoria ocupada por el mismo.
void Destruir(array_dinamico &ad);

#endif // ARREGLODINAMICONUMERO_H_INCLUDED

