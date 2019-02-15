#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "Errores.h"
#include "Arbol.h"

//Este modulo servirá para centralizar el parsing, y para guardar los posibles comandos que se podrán invocar
typedef enum{CREAR,SUMAR,MULTIPLICAR,EVALUAR,ESRAIZ,MOSTRAR,GUARDAR,RECUPERAR,SALIR,AYUDA,ERROR}Comandos;

//--> FUNCIONES ESPECIFICAS DE LOS COMANDOS

//A raiz de un String previamente cargado por teclado, se establecerá a cual comando se hace referencia.
//De esta manera, en el Menu se podra validar uno u otro comando, e invocar a aquel que sea correcto
Comandos EstablecerComando(String s_1);

//A raiz de un string pasado, devolvera true o false si el comando es valido y se puede proseguir con el mismo.
//Es el inicio del parsing, se realizara para cada comando ingresado.
//Se usaran todas las funciones auxiliares de parsing ya definidias en String.h
boolean ValidarCrear(String s_1);

//Se establece la funcion Crear, para a raiz de un string, crear un polinomio e insertarlo en el arbol.
//PRECONDICION: El string pasado debe haberse validado previamente antes de invocar esta funcion.
void Crear(String s_1, Arbol &a);

//A raiz de un comando y de un string, se intenta comenzar la ejecucion del comando en cuestion.
//Dentro de esta funcion se llamara al validador auxiliar de cada comando para el string dado, si ocurre alguna falla,
//no se seguira con la ejecucion del comando y se dara el error correspondiente en pantalla.
void ComenzarComando(Comandos com, String s_1);

#endif // COMANDOS_H_INCLUDED
