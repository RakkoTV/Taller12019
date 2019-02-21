#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED

#include "String.h"
#include "ArreglodinamicoNumero.h"


typedef struct {
    long int coeficiente;
    int exponente;
    char signo;
} Termino;

//CARGAR/MOSTRAR
//La funcion carar tambien se configurara para que el dato del input sea un string previo.
//PRECONDICION: El string pasado no puede tener ni el nombre del comando ni el del polinomio, debe haberse validado previamente
//              y solo debe hacer referencia a un termino valido.
void Cargar_Termino_Desde_String(Termino &T, String s_1);


void Mostrar_Termino(Termino T);

//SELECTORAS
int DarCoeficiente(Termino T);
int DarExponente(Termino T);
//Grabara en el char pasado un signo
void DarSigno(char &s_1);

//OPERACIONES ESPECIFICAS
//Se deja nulo el termino
void BorrarTermino(Termino &T);

//Guardara el Termino dentro del archivo apuntado por stream
//PRECONDICION: El mismo ya fue abierto previamente, y en modo "wb" o "ab"
void BajarTermino(FILE * stream, Termino T_1);

//Leera del archivo apuntado por stream, y lo levantara en memoria en Termino
//PRECONDICION: stream ya fue abierto previamente, y en modo "rb"
void SubirTermino(FILE * stream, Termino &T_1);
//devuelte entero
int DevuelveINT (array_dinamico a, int cant);

//Potencia
int potencia(int x, int y);

#endif // TERMINO_H_INCLUDED
