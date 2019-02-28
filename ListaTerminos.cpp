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

//Dada una lista y un termino, agrega dicho termino al final de la lista
void InsBackRecu(Lista &L, Termino T_1)
{
    if (L == NULL)
        InsFront(L, T_1);
    else
        if (L->sig != NULL)
            InsBackRecu(L->sig, T_1);
        else
        {
            //Esto de abajo va a quedar como pendiente hasta llegar al final de la lista.
            //De esa manera, no se pierde la posicion original de L, ya que al terminar todas las subrutinas
            //L ira volviendo al nodo 1.
            Lista aux_nodo = new nodo;
            aux_nodo->info = T_1;
            aux_nodo->sig = NULL;
            L->sig = aux_nodo;
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

void Crear_Lista_Desde_String(Lista &L, String string_1)
{
    int i=0;
    int cant_terminos = ContarTerminos(string_1);
    int largo_int = strlar(string_1);

    //En este caso no tendre cuidado con los espacios iniciales
    while ( cant_terminos != 0 )
    {
        //Para cada termino leido, voy leyendo el string y cortando en cada caso
        Termino T_1;
        int j=0;
        String aux;

        aux = new char[largo_int+1];
        aux[largo_int] = '\0';

        while ( (string_1[i] != ' ') && (string_1[i] != '\0') )
        {
            aux[j] = string_1[i];
            i++;
            j++;
        }

        aux[j] = '\0';

        //Re posiciono a string_1 sacando los espacios entre los terminos. Si llegue al final, no se entrara en este while
        while ( string_1[i] == ' ' )
            i++;

        //Llegados a este punto, en aux tendre el termino leido.
        //Ahora puedo cargar el termino usando su propia funcion
        Cargar_Termino_Desde_String(T_1, aux, cant_terminos-1);

        //Lo inserto en la lista de atras para adelante. Para que la misma quede ordenada siempre de mayor a menos
        InsBackRecu(L, T_1);

        //Antes de continuar, elimino de memoria a aux
        strdestruir(aux);
        cant_terminos--;
    }

//    //-->> DESARROLLADO POR SEBA 28/02/2019 <<--//
//    int i=0,j=0,cant;
//    Termino T;
//    String s1,s2;
//    cant=1;//ContarTerminos(s_1);
//    int largo=strlar(s_1);
//
//
//    while((s_1[i] != '\0')&&(i<largo))
//    {
//        strcrear(s1);
//
//        strcrear(s2);
//          printf("Inicio de iteracion posicion j es %d",j);
//
//
//       while((s_1[j] != ' ')&&(s_1[j] != '\0'))
//        {
//
//        s2[j]=s_1[j];
//        //printf("%c",s2[j]);
//        j++;
//
//        }
//        s2[j]='\0';
//        printf(" poscion j es %d \n",j);
//
//        strcop(s1,s2);
//        strdestruir(s2);
//        //print(s1);
//
//      // printf("termino copiado 1 \n");
//        Cargar_Termino_Desde_String(T,s1,cant);
//        //Mostrar_Termino(T);
//        InsFront(L,T);
//        strdestruir(s1);
////
////       // cant--;
////       // printf("se ingreso primer termino en");
//
//        printf("Fin iteracion poscion j es %d \n",j);
//        j=j+1;
//        i=j;
//
//        //fflush(stdin);
//
//    }

}


