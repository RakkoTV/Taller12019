#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include "ListaTerminos.h"

typedef struct {
    String nombre;
    Lista terminos;
} Polinomio;

//CARGAR/MOSTRAR
//El cargado se realizara tambien a través de un string, cortando el nombre del polinomio y sus terminos
//PRECONDICION: El string pasado no puede tener el nombre del comando, y debe haber sido validado previamente
void Cargar_Polinomio_Desde_String(Polinomio &P, String s_1);
void Cargar_Polinomio(Polinomio &P);
void Mostrar_Polinomio(Polinomio P);

//SELECTORAS
void DarNombre(Polinomio P, String &s_1);
Lista DarTerminos(Polinomio P);

//OPERACIONES ESPECIFICAS

#endif // POLINOMIO_H_INCLUDED
