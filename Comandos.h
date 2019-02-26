#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "Errores.h"
#include "Archivo.h"
#include "Arbol.h"

//Este modulo servirá para centralizar el parsing, y para guardar los posibles comandos que se podrán invocar
typedef enum{CREAR,SUMAR,MULTIPLICAR,EVALUAR,ESRAIZ,MOSTRAR,GUARDAR,RECUPERAR,SALIR,AYUDA,ERROR}Comandos;

//--> FUNCIONES ESPECIFICAS DE LOS COMANDOS

//A raiz de un String previamente cargado por teclado, se establecerá a cual comando se hace referencia.
//De esta manera, en el Menu se podra validar uno u otro comando, e invocar a aquel que sea correcto
Comandos EstablecerComando(String s_1);

//A raiz de un comando y de un string, se intenta comenzar la ejecucion del comando en cuestion.
//Dentro de esta funcion se llamara al validador auxiliar de cada comando para el string dado, si ocurre alguna falla,
//no se seguira con la ejecucion del comando y se dara el error correspondiente en pantalla.
void ComenzarComando(Comandos com_1, String s_1, Arbol &a);

//A raiz de un string pasado, devolvera true o false si el comando es valido y se puede proseguir con el mismo.
//Es el inicio del parsing, se realizara para cada comando ingresado.
//Se usaran todas las funciones auxiliares de parsing ya definidias en String.h
boolean ValidarCrear(String s_1, Arbol a);

//Se establece la funcion Crear, para a raiz de un string, crear un polinomio e insertarlo en el arbol.
//PRECONDICION: El string pasado debe haberse validado previamente antes de invocar esta funcion.
void Crear(String s_1, Arbol &a);

//A raiz de un string pasado, se verifica que el mismo sea valido para con el comando SUMAR
//(que tenga 3 polinomios, el primero que no exista en el sistema y los otros 2 que si existan)
//Si no, dara error en cada caso.
boolean ValidarSumar(String s_1, Arbol a);

//Se establece la funcion Sumar, para que a raiz de los parametros del string, se sumen los 2 polinomios y se cree
//un tercero en el arbol
void Sumar(String s_1, Arbol &a);

//A raiz de un string pasado, se verifica que el mismo sea valido para con los requerimientos del comando MULTIPLICAR
//(que tenga 3 polinomios, el primero que no exista en el sistema y los otros 2 que si existan)
//Si no, dara error en cada caso.
boolean ValidarMultiplicar(String s_1, Arbol a);

//Se establece la funcion Multiplicar, para que a raiz de los parametros del string, se multipliquen los 2 polinomios y se cree
//un tercero en el arbol
void Multiplicar(String s_1, Arbol &a);

//Se valida el comando evaluar, verificando que el string tenga el nombre de un polinomio valido, que el mismo ya este en el
//arbol actual, y que el numero a evaluar sea efectivamente un numero y ademas sea entero
boolean ValidarEvaluar(String s_1, Arbol a);

//Se ejecuta el comando evaluar, encontrando al polinomio en el arbol, sustituyendo las "x" por el numero entero, y luego
//mostrando por pantalla el resultado final
void Evaluar(String s_1, Arbol a);

//Se valida el comando EsRaiz. Se verifica que el nombre del string pertenezca a un polinomio valido y ya dado de alta en
//el arbol, y que el numero siguiente sea valido y sea entero.
boolean ValidarEsRaiz(String s_1, Arbol a);

//Se establece el comando EsRaiz. Se recorre el arbol hasta encontrar el polinomio, y se determina si ese numero entero
//es raiz del polinomio o no.
boolean EsRaiz(String s_1, Arbol a);

//Se establece el comando Mostrar. Si no existe ningun polinomio a mostrar, se imprimira aca tambien el mensaje en pantalla.
//Si no, se invoca a las funciones de mostrar arbol, polinomio y termino en cada caso.
void Mostrar(Arbol a);

//Se valida el comando Guardar. Se revisa que se este invocandolo con un polinomio valido y previamente existente, que
//el nombre del archivo sea valido, y que la extension sea correcta.
boolean ValidarGuardar(String s_1, Arbol a);

//Se establece el comando Guardar. A raiz del nombre de archivo en s_1, se encuentra al polinomio en el arbol y se lo guarda
//en el archivo especificado.
void Guardar(String s_1, Arbol a);

//Se valida el comando Recuperar. Se revisa que el archivo al cual se hace referencia exista en disco, que el nombre y la extension
//sean validos, y que el nombre del nuevo polinomio que se tiene que crear sea alfanumerico y que no exista en este momento
//en el sistema.
boolean ValidarRecuperar(String s_1, Arbol a);

//Se establece el comando Recuperar. Se crea en memoria el nuevo polinomio con el nombre especificado, y se lo inserta en el arbol.
void Recuperar(String s_1, Arbol &a);

//Se establece el comando Salir. Se termina la ejecucion del sistema y se libera toda la memoria dinamica creada por el arbol.
//Para eso, se llama a las funciones de eliminacion de termino, lista_terminos, polinomio y arbol en cada caso.
void SalirSistema(Arbol &a);

#endif // COMANDOS_H_INCLUDED
