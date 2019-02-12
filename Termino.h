#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED

#include "String.h"

typedef struct {
    int coeficiente;
    int exponente;
    char signo;
} Termino;

//CARGAR/MOSTRAR
void Cargar_Termino(Termino &T);
void Mostrar_Termino(Termino T);

//SELECTORAS
int DarCoeficiente(Termino T);
int DarExponente(Termino T);

//OPERACIONES ESPECIFICAS


#endif // TERMINO_H_INCLUDED
