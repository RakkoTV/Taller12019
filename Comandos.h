#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "String.h"

//Este modulo servir� para centralizar el parsing, y para guardar los posibles comandos que se podr�n invocar
typedef enum{CREAR,SUMAR,MULTIPLICAR,EVALUAR,ESRAIZ,MOSTRAR,GUARDAR,RECUPERAR,SALIR,ERROR}Comandos;

//A raiz de un String previamente cargado por teclado, se establecer� a cual comando se hace referencia.
Comandos EstablecerComando(String s_1);

//A raiz de un string pasado, devolvera true o false si el comando es valido y se puede proseguir con el mismo.
//Es el inicio del parsing.
boolean VerificarComando(String s_1);

#endif // COMANDOS_H_INCLUDED
