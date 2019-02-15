#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "Boolean.h"

const int MAX = 500;
typedef char * String;

//Crea un string vacio.
void strcrear(String &string_1);

//Libera la memoria ocupada por el string y lo deja nulo.
void strdestruir(String &string_1);

//Devuelve el largo de un string. Se entiende por largo, la cantidad de caracteres antes del carácter nulo.
int strlar(String string_1);

//Recibe dos strings y copia el segundo en el primero.
void strcop(String &string_1, String string_2);

//Lee un string desde el teclado. Se tomarán en cuenta los primeros 79 caracteres
//significativos en caso de que el largo del string sea mayor o igual a 80. Un string
//finaliza cuando se lea un carácter ‘nueva línea’ el cual se sustituirá por uno nulo.
void scan(String &string_1);

//Recibe dos strings y concatena el segundo string al final del primero, la concatenación
//deberá quedar sobre el primero de los dos. En caso de que el largo de los strings
//exceda los 79 caracteres, no se tomarán los caracteres excedentes del segundo string.
void strcon(String &string_1, String string_2);

//Recibe dos strings y devuelve el primero en el segundo, y viceversa.
void strswp(String &string_1, String &string_2);

//Despliega un string por pantalla.
void print(String string_1);

//Recibe dos strings y devuelve TRUE si el primero de ellos es menor (en orden
//alfabético) que el segundo, o FALSE en caso contrario.
boolean strmen(String string_1, String string_2);

//Reciba dos strings y devuelve TRUE si ambos strings son iguales o FALSE en caso
//contrario.
boolean streq(String string_1, String string_2);

//Guardara el String "string_1" dentro del archivo apuntado por stream
//PRECONDICION: El mismo ya fue abierto previamente, y en modo "wb" o "ab"
void Bajar_String(FILE * stream, String string_1);

//Leera del archivo apuntado por stream, y lo levantara en memoria en "sring_1"
//PRECONDICION: stream ya fue abiert previamente, y en modo "rb"
void Subir_String(FILE * stream, String &string_1);

//--> FUNCIONES AUXILIARES DEL PARSING
//A raiz de un string, valida si el mismo es o no un alfanumerico
boolean ValidarAlfanumerico(String s_1);

//Se lee una cadena de caracteres de posibles terminos, y se devuelve TRUE/FALSE si
//se encontro caracteres extraños. Esto validara que los posibles terminos solo
//tengan numeros, y que los mismos sean enteros, porque si se ingresa un “.” o una
//“,” los caraceres se reconoceran como invalidos.
boolean ValidarSoloEnteros(String s_1);

//Se valida que minimamente se haya ingresado algun numero. Porque la funcion
//ValidarSoloEnteros puede dar true si se ingreso solo espacios
boolean ValidarExisteUnNumero(String s_1);

//A raiz de un char que representa un caracter del 0-9, se deuelve el mismo en formato numero
//PRECONDICION: c_1 solo puede tener caraceres que represente un numero del 0-9
int ConvertirCaracter(char c_1);

//A raiz de un string que represente un numero positivo o negativo, se convierte al mismo en formato numero.
//PRECONDICION: El string no puede representar un numero mayor a lo maximo que permie almacenar el long int.
long int PasarStringANumero(String s_1);

//En caso de que la cantidad de terminos separados por espacio, sea 2 o mas, se
//debe validar que el primer termino sea distinto de 0. Esto devolvera TRUE/FALSE si se cumple eso dado
//un string previamente semi-validado y cortado para que solo incluya los posibles terminos
boolean ValidarPrimerTermino(String s_1);

//A raiz de un string que contiene el conjunto de terminos, esta funcion realiza un conteo de los
//mismos
//PRECONDICION: Se debe validar previamente que el string dado contenga terminos
//validos, habiendo eliminado previamente del string el nombre del comando y el
//nombre del polinomio a crear.
int ContarTerminos(String s_1);


#endif // STRING_H_INCLUDED
