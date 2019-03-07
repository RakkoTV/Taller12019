#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include "ListaTerminos.h"

typedef struct {
    String nombre;
    Lista Lterminos;
} Polinomio;

//CARGAR/MOSTRAR
//El cargado se realizara tambien a través de un string, cortando el nombre del polinomio y sus terminos
//PRECONDICION: El string pasado no puede tener el nombre del comando, y debe haber sido validado previamente
void Cargar_Polinomio_Desde_String(Polinomio &P, String nombre_pol, String lista_terminos);
void Cargar_Polinomio(Polinomio &P, String Nombre, Lista LisTer);
//Crea el pilinomio
void CrearPoli(Polinomio &P);
//Muestra el Polinomio
void Mostrar_Polinomio(Polinomio P);

//SELECTORAS

//Mostrar Nombre de Polinomio
void DarNombre(Polinomio P, String &s_1);
//Devolver Lista de Terminos
Lista DarTerminos(Polinomio P);

//OPERACIONES ESPECIFICAS
//Se verifica si a raiz de un entero r, el mismo es raiz del polinomio. Se usara para el comando EsRaiz.
boolean OperacionMatematicaEsRaiz(Polinomio P, int r);

//Se deja nulo el polinomio, eliminando la memoria dinamica almacenada por la lista de terminos y dejando nula la propia estructura.
void BorrarPolinomio(Polinomio &P);

//Se bajara en el archivo stream la totalidad del polinomio. En realidad, el nombre se lo descarta y se guarda solo la lista de terminos
//separados por espacio en el mismo.
//PRECONDICION: El archivo ya fue abierto previamente, y en modo "wb" o "ab"
//void BajarPolinomio(FILE * stream, Polinomio P);

//Leera del archivo apuntado por stream, y lo levantara en memoria como un nuevo Polinomio creando la lista
//de terminos asociados (leyendo uno a uno) y usando el nombre de s_1 como nombre del polinomio.
//Se devolvera el polinomio creado.
//PRECONDICION: stream ya fue abierto previamente, y en modo "rb"
//Polinomio SubirPolinomio(FILE * stream, String s_1);

#endif // POLINOMIO_H_INCLUDED
