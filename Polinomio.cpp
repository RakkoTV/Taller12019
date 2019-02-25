#include "Polinomio.h"


void Cargar_Polinomio_Desde_String(Polinomio &P, String s_1);


void Cargar_Polinomio(Polinomio &P, String Nombre, Lista LisTer)
{
    CrearPoli(P);
    strcop(Nombre, P.nombre);
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
    DesplegarInteractiva(P.Lterminos);
}

void DarNombre(Polinomio P, String &s_1);
Lista DarTerminos(Polinomio P);

void BajarPolinomio(FILE * stream, Polinomio P);

Polinomio SubirPolinomio(FILE * stream, String s_1);

