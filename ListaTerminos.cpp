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


void InsFront(Lista &L, int T)
{
    Lista aux=new nodo;
    aux->info=T;
    aux->sig=L;
    L=aux;
}

/*Termino Primero(Lista L)
{
    return L->info;
}
*/
void Resto(Lista &L)
{
    Lista aux=L;
    L=L->sig;
    aux;
}


