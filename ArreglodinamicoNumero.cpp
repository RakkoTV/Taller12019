#include "ArreglodinamicoNumero.h"

void CrearAD(array_dinamico &ad, int celdas)
{
    //Se reserva el espacio de memoria y se apunta a arre a la primera posicisión de dicho espacio
    ad.arre = new int[celdas];
    //Dentro del elemento ad, se actualiza el tamanio según lo creado
    ad.tamanio = celdas;
}

void Cargar(array_dinamico &ad)
{
    int i;

    for(i=0;i<ad.tamanio;i++)
    {
        printf("\nIngrese el numero: ");
        scanf("%d", &ad.arre[i]);
        fflush(stdin);
    }
}

void Mostrar(array_dinamico ad)
{
    int i;

    for(i=0;i<ad.tamanio;i++)
    {
        printf("\n[%d]: %d", i, ad.arre[i]);
    }
}

boolean Pertenece(array_dinamico ad, int valor)
{
    boolean existe = FALSE;
    int i=0;

    while((i < ad.tamanio) && (existe == FALSE))
    {
        if (ad.arre[i] == valor)
            existe = TRUE;
        i++;
    }

    return existe;
}

float Promedio(array_dinamico ad)
{
    int i;
    float suma=0;

    for(i=0;i<ad.tamanio;i++)
    {
        suma = suma + ad.arre[i];
    }

    return suma/ad.tamanio;
}

//PRECONDICION: El array dinamico tiene que tener algun valor cargado previamente.
void MaxPos(array_dinamico ad, int &mayor, int &posicion)
{
    int i;
    mayor = ad.arre[0];
    posicion = 0;

    for(i=1;i<ad.tamanio;i++)
    {
        if( ad.arre[i] > mayor)
        {
            mayor = ad.arre[i];
            posicion = i;
        }
    }
}

void Destruir(array_dinamico &ad)
{
    //Devuelvo todas las celdas del array para ser ocupadas por el SO
    delete [] ad.arre;
    //Apunto el puntero al array inexisten a NULL
    ad.arre = NULL;
    //Dejo a la estructuro con tamanio 0
    ad.tamanio = 0;
}
