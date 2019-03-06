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

void MostrarLista (Lista L)
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

}

Lista SumarPoli(Lista lista_1, Lista lista_2)
{
    Lista resultado_inicial, resultado_final, aux_1, aux_2;
    long int coeficiente_aux;
    int maximo_exponente = 0;
    aux_1 = lista_1;
    aux_2 = lista_2;
    Crear_Lista(resultado_inicial);
    Crear_Lista(resultado_final);

    //Se concatena la lista_1 junto con la lista_2 para ser sumarizada mas adelante
    while( aux_1 != NULL )
    {
        InsFront(resultado_inicial, aux_1->info);
        aux_1 = aux_1->sig;
    }

    while ( aux_2 != NULL )
    {
        InsFront(resultado_inicial, aux_2->info);
        aux_2 = aux_2->sig;
    }

    //En el resultado_inicial tendre la lista final pero con los terminos de igual exponenete, sin sumar
    //Precisare sumarlos ahora

    //Se inicia teniendo en cuenta el maximo exponente encontrado
    aux_1 = resultado_inicial;
    while( aux_1 != NULL )
    {
        if( DarExponente(aux_1->info) > maximo_exponente )
            maximo_exponente = DarExponente(aux_1->info);

        aux_1 = aux_1->sig;
    }

    //En maximo_exponente tendre cargado el maximo exponente de la lista con los resultados primarios de la multiplicacion
    //Para cada exponenete desde el maximo, hasta el 0, se necesita sumar todos los termino
    while( maximo_exponente >= 0 )
    {
        coeficiente_aux = 0;

        //Recorro toda la lista para ver los terminos que tengan el exponente en cuestion
        aux_1 = resultado_inicial;
        while( aux_1 != NULL )
        {
            if( DarExponente(aux_1->info) == maximo_exponente )
                coeficiente_aux = coeficiente_aux + DarCoeficiente(aux_1->info);

            aux_1 = aux_1->sig;
        }

        //Creo el termino auxiliar que contiene la suma de todos los coeficientes encontrados para este exponente
        Termino termino_aux;
        Cargar_Termino(termino_aux, coeficiente_aux, maximo_exponente);

        //Inserto dicho termino en la nueva lista ordenada de resultado
        InsBackRecu(resultado_final, termino_aux);

        //Minimizo un exponente a buscar, hasta haber recorrido todo por completo
        maximo_exponente--;
    }

    //Borro los punteros innecesarios
    BorrarLista(resultado_inicial);
    aux_1 = NULL;
    aux_2 = NULL;

    //--> MOSTRAR A LA PROFE PORQUE NO SE ELIMINA LA LISTA <--
    //printf(" - ");
    //MostrarLista(resultado_inicial);
    //printf(" - \n");

    //Devuelvo la lista ordenada
    return resultado_final;
}

Lista MultiplicarPoli(Lista lista_1, Lista lista_2)
{
    Lista resultado_inicial, resultado_final, aux_1, aux_2;
    long int coeficiente_aux;
    int maximo_exponente = 0;
    aux_1 = lista_1;
    aux_2 = lista_2;
    Crear_Lista(resultado_inicial);
    Crear_Lista(resultado_final);

    while( aux_1 != NULL )
    {
        while ( aux_2 != NULL )
        {
            InsFront(resultado_inicial, MultiplicaTerm(aux_1->info, aux_2->info));
            aux_2 = aux_2->sig;
        }
        aux_2 = lista_2;
        aux_1 = aux_1->sig;
    }

    //En el resultado_inicial tendre la lista final pero con los terminos de igual exponenete, sin sumar
    //Precisare sumarlos ahora

    //Se inicia teniendo en cuenta el maximo exponente encontrado
    aux_1 = resultado_inicial;
    while( aux_1 != NULL )
    {
        if( DarExponente(aux_1->info) > maximo_exponente )
            maximo_exponente = DarExponente(aux_1->info);

        aux_1 = aux_1->sig;
    }

    //En maximo_exponente tendre cargado el maximo exponente de la lista con los resultados primarios de la multiplicacion
    //Para cada exponenete desde el maximo, hasta el 0, se necesita sumar todos los termino
    while( maximo_exponente >= 0 )
    {
        coeficiente_aux = 0;

        //Recorro toda la lista para ver los terminos que tengan el exponente en cuestion
        aux_1 = resultado_inicial;
        while( aux_1 != NULL )
        {
            if( DarExponente(aux_1->info) == maximo_exponente )
                coeficiente_aux = coeficiente_aux + DarCoeficiente(aux_1->info);

            aux_1 = aux_1->sig;
        }

        //Creo el termino auxiliar que contiene la suma de todos los coeficientes encontrados para este exponente
        Termino termino_aux;
        Cargar_Termino(termino_aux, coeficiente_aux, maximo_exponente);

        //Inserto dicho termino en la nueva lista ordenada de resultado
        InsBackRecu(resultado_final, termino_aux);

        //Minimizo un exponente a buscar, hasta haber recorrido todo por completo
        maximo_exponente--;
    }

    //Borro los punteros innecesarios
    BorrarLista(resultado_inicial);
    aux_1 = NULL;
    aux_2 = NULL;

    //--> MOSTRAR A LA PROFE PORQUE NO SE ELIMINA LA LISTA <--
    //printf(" - ");
    //MostrarLista(resultado_inicial);
    //printf(" - \n");

    //Devuelvo la lista ordenada
    return resultado_final;
}

long int EvaluarRecursivo(Lista L, long int n)
{
    long int resultado;

    if (L==NULL)
        return 0;
    else
        resultado=((potenciaLong(n,DarExponente(L->info)))*DarCoeficiente(L->info));

    return resultado+EvaluarRecursivo(L->sig,n);
}

//Se elimina termino a termino todo lo guardado en esa lista. Esto se da para eliminar toda la memoria dinamica almacenada
//en esta lista, dejando nulos todos los punteros y estructuras de terminos.
void BorrarLista(Lista &L)
{
    if( L != NULL )
    {
        BorrarLista(L->sig);
        delete L;
    }
}


