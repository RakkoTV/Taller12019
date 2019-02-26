#include"ListaTerminos.h"

void Crear_Lista(Lista &L)
{
    L=NULL;
}


boolean EsVacio_Lista(Lista L)
{
    boolean es = FALSE;

    if(L==NULL)
        es =TRUE;

    return es;
}


void InsFront(Lista &L, Termino T)
{
    Lista aux=new nodo;
    aux->info=T;
    aux->sig=L;
    L=aux;
}

Termino Primero(Lista L)
{
    return L->info;
}

void Resto(Lista &L)
{
    Lista aux=L;
    L=L->sig;
    aux;
}

void Mostrarlista (Lista L)
{
    while(L!=NULL)
    {
        Mostrar_Termino(L->info);
        L=L->sig;

    }
}

void InsOrdenada(Lista &L, Termino Ter) //Num;
{
    Lista NuevoNodo= new nodo;
    NuevoNodo->info=Ter;
    Lista Aux1=L;
    Lista Aux2; //Lo puse a null no se si va

while((Aux1 !=NULL)&&(DarExponente(Ter)<DarExponente(Aux1->info)))

    //Programar esa funcion boolean
    {
        Aux2=Aux1;
        Aux1=Aux1->sig;
    }
    if(L==Aux1) //No entro al while, va al principio
    {
        L=NuevoNodo;
    }
    else
        {
        Aux2->sig=NuevoNodo;//Entro al while
        }
    NuevoNodo->sig=Aux1; //Lo muevo
}

Lista MultiplicarPoli(Lista Pol1, Lista Pol2)
{

    Lista Nueva, Aux;
    Aux=Pol2;
    Crear_Lista(Nueva);
    while(Pol1 !=NULL)
    {

        while(Aux!=NULL)
        {


           InsOrdenada(Nueva, MultiplicaTerm(Primero(Pol1),Primero(Aux)));

        Aux=Aux->sig;
        }
        Aux=Pol2;
        Pol1=Pol1->sig;

    }

    return Nueva;


}



