#include "Comandos.h"

//A raiz de un String previamente cargado por teclado, se establecerá a cual comando se hace referencia.
//De esta manera, en el Menu se podra validar uno u otro comando, e invocar a aquel que sea correcto
Comandos EstablecerComando(String s_1)
{
    return AYUDA;
}

//A raiz de un comando y de un string, se intenta comenzar la ejecucion del comando en cuestion.
//Dentro de esta funcion se llamara al validador auxiliar de cada comando para el string dado, si ocurre alguna falla,
//no se seguira con la ejecucion del comando y se dara el error correspondiente en pantalla.
void ComenzarComando(Comandos com_1, String s_1, Arbol &a)
{

}


void Sumar(String s_1, Arbol &a)
{
    int i =0;
    while(s_1[i] !='\0')
     {
         if(s_1[i] != ' ')
         {
            strcrear(s_1);
         }
     }
}
