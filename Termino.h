#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED

#include "String.h"
#include "ArreglodinamicoNumero.h"
#include "String.h"


typedef struct {
    long int coeficiente;
    int exponente;
    char signo;
} Termino;

//CARGAR/MOSTRAR
//La funcion carar tambien se configurara para que el dato del input sea un string previo.
//PRECONDICION: El string pasado no puede tener ni el nombre del comando ni el del polinomio, debe haberse validado previamente
//              y solo debe hacer referencia a un termino valido.
void Cargar_Termino_Desde_String(Termino &T, String s_1, int exponente);

//Muestra el termino ingresado
void Mostrar_Termino(Termino T);

//SELECTORAS
// Dar Coeficiante
int DarCoeficiente(Termino T);
//Dar exponento
int DarExponente(Termino T);
// Selectora dar signo
char DarSigno(Termino T);

//OPERACIONES ESPECIFICAS
//Se deja nulo el termino(No deberia realizarse aqui ya que termino no utiliza memoria dinamica)
void BorrarTermino(Termino &T);

//Guardara el Termino dentro del archivo apuntado por stream
//PRECONDICION: El mismo ya fue abierto previamente, y en modo "wb" o "ab"
void BajarTermino(FILE * stream, Termino T);

//Leera del archivo apuntado por stream, y lo levantara en memoria en Termino
//PRECONDICION: stream ya fue abierto previamente, y en modo "rb"
void SubirTermino(FILE * stream, Termino &T);
//devuelte entero
int DevuelveINT (array_dinamico a, int cant);

//Potencia
int potencia(int x, int y);

//SUMA Percondicion que los exponentes sean iguales
Termino SumarTermino(Termino T, Termino T2);
//MULTIPLICA
Termino MultiplicaTerm (Termino T1, Termino T2);

#endif // TERMINO_H_INCLUDED
