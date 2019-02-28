#include "Arbol.h"

//typedef struct nodoAA {
//    Polinomio info;
//    nodoAA * HIzq;
//    nodoAA * HDer;
//} nodoA;
//
//typedef nodoA * Arbol;


void Crear_Arbol(Arbol &a)
{
    a=NULL;
}


//Saber si el árbol está vacío
boolean EsVacio_Arbol(Arbol a)
{
    boolean Es=FALSE;
    if(a==NULL)
    {
        Es=TRUE;
    }
    return Es;
}

//Devolver la raíz del árbol
//PRECONDICION: Arbol NO vacío
Polinomio DarRaiz(Arbol a)
{
    return a->info;
}

//Obtener el subárbol izquierdo
//Precondición: Arbol NO vacío
Arbol HijoIzq(Arbol a)
{
    return a->HIzq;
}

//Obtener el subárbol derecho
//Precondición: Arbol NO vacío
Arbol HijoDer(Arbol a)
{
    return a->HDer;
}


//Dados dos árboles y un valor, devolver un nuevo árbol
//colocando dicho valor como una nueva raíz y a los dos
//árboles como subárboles de la misma
Arbol Cons(Polinomio P, Arbol i, Arbol d)
{

    Arbol NuevoArbol;
    NuevoArbol= new nodoA;//Llamar a polinomio
    NuevoArbol->info=P;
    NuevoArbol->HIzq=i;
    NuevoArbol->HDer;

    return NuevoArbol;

}

//OPERACIONES ESPECÍFICAS
//Insertar, de acuerdo al criterio de nombres mayores o menores alfabeticamente, utilizando el nombre del Polinomio pasado
//PRECONDICION: En el arbol no se encuentra ningun expediente con el codigo del que ahora se va a insertar.
void Insert(Arbol &a, Polinomio P_1)
{
    if (a == NULL)
    {
        a = new nodoA;
        a -> info = P_1;
        a -> HIzq = NULL;
        a -> HDer = NULL;
    }
    else
    {
        String Aux_NodoActual, Aux_NuevoNodo;
        strcrear(Aux_NodoActual);
        strcrear(Aux_NuevoNodo);

        DarNombre(a->info, Aux_NodoActual);
        DarNombre(P_1, Aux_NuevoNodo);

        //Si el nombre del polinomio del nodo presente es menor al nombre del polinomio del nuevo nodo, se ira para la izquierda.
        //Si no, se ira para la derecha
        if ( strmen(Aux_NodoActual, Aux_NuevoNodo) )
            Insert(a->HIzq,P_1);
        else
            Insert(a->HDer,P_1);

        strdestruir(Aux_NodoActual);
        strdestruir(Aux_NuevoNodo);
    }
}

//A raiz de un string que represena el nombre de un polinomio, se devuelve si se lo encontro en el arbol o no
//PREONDICION: s_1 es un nombre de polinomio valido
boolean ExistePolinomio(Arbol a, String s_1)
{
    if (a==NULL)
    {
        return FALSE;
    }
    else
    {
        String Aux;
        strcrear(Aux);
        DarNombre(a->info, Aux);

        if( streq(Aux, s_1) )
            return TRUE;
        else
            if( strmen(Aux, s_1) )// como separa antes de comparar
                return ExistePolinomio(a->HIzq, s_1);
            else
                return ExistePolinomio(a->HDer, s_1);

        strdestruir(Aux);
    }
}

//A raiz del nombre de un polinomio ya existente, se lo devuelve en base a una busqueda en el arbol
//PRECONDICION: s_1 es un nombre valido, y el polinomio s_1 ya se encuentra cargado en el arbol previamente
Polinomio EncontrarPolinomio(Arbol a, String s_1);

//Despliega en pantalla el conjunto de polinomios guardado, uno en cada linea.
void MostrarArbol(Arbol a)
{
    //La recorrida completa usara el metodo "Orden"
    if( a != NULL)
    {
        MostrarArbol(a->HIzq);

        //Se deja todos los espacios iniciales para que por cada polinomio se muestre linea a linea todo
        printf("                   ");
        Mostrar_Polinomio(a->info);
        printf("\n");

        MostrarArbol(a->HDer);
    }
}

//Se recorrera todos los nodos del arbol, eliminando la memoria almacenada por cada uno. Se invocara a las funciones de eliminacion
//de BorrarPolinomio, BorrarLista y BorrarTerminos.
void BorrarArbol(Arbol &a);

