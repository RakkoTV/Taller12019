#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED

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
void Cargar_Termino_Desde_String(Termino &T, String s_1);
void Cargar_Termino(Termino &T);
void Mostrar_Termino(Termino T);

//SELECTORAS
int DarCoeficiente(Termino T);
int DarExponente(Termino T);

//OPERACIONES ESPECIFICAS


#endif // TERMINO_H_INCLUDED
