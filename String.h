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

#endif // STRING_H_INCLUDED
