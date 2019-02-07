#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include "ListaTerminos.h"

typedef struct {
    String nombre;
    Lista terminos;
} Polinomio;

//CARGAR/MOSTRAR
void Cargar_Polinomio(Polinomio &P);
void Mostrar_Polinomio(Polinomio P);

//SELECTORAS
void DarNombre(Polinomio P, String &s_1);
Lista DarTerminos(Polinomio P);

//OPERACIONES ESPECIFICAS

#endif // POLINOMIO_H_INCLUDED
