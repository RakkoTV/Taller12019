#include "Polinomio.h"


void Cargar_Polinomio_Desde_String(Polinomio &P, String nombre_pol, String lista_terminos)
{
    strcop(P.nombre, nombre_pol);
    Crear_Lista_Desde_String(P.Lterminos, lista_terminos);
}

void Cargar_Polinomio(Polinomio &P, String Nombre, Lista LisTer)
{
    CrearPoli(P);
    strcop(P.nombre, Nombre);
    P.Lterminos=LisTer;
}

void CrearPoli(Polinomio &P)
{
    strcrear(P.nombre);
    Crear_Lista(P.Lterminos);
}

void Mostrar_Polinomio(Polinomio P)
{
    print(P.nombre);
    printf(" = ");

    if( TodaListaConCeros(P.Lterminos) )
        printf("0");
    else
        MostrarLista(P.Lterminos);
}

void DarNombre(Polinomio P, String &s_1)
{
    strcop(s_1, P.nombre);
}

Lista DarTerminos(Polinomio P)
{
    return P.Lterminos;
}

//Se deja nulo el polinomio, eliminando la memoria dinamica almacenada por la lista de terminos y dejando nula la propia estructura.
void BorrarPolinomio(Polinomio &P)
{
    strdestruir(P.nombre);
    BorrarLista(P.Lterminos);
}
