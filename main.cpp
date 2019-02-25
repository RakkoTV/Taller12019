
#include "String.h"

int main()
{
    char c;
    String s_1;
    long int numero_ld;

    printf(" Bienvenido a la seccion de validacion!!\n Ingrese un String: ");
    scan(s_1);

    if( ValidarAlfanumerico(s_1) )
        printf("\n Val 1: El string es alfanumerico, o sea, pertenece al grupo: A-Z, a-z, 0-9 o es espacio... ");
    else
        printf("\n Val 1: El string NO es alfanumerico...");

    if( ValidarSoloEnteros(s_1) )
        printf("\n\n Val 2: El string esta en el grupo de los numeros, o sea: 0-9, espacio o '-'");
    else
        printf("\n\n Val 2: El string NO esta en el grupo de los: 0-9, espacio o '-'");

    if ( ValidarExisteUnNumero(s_1) )
        printf("\n\n Val 3: El string tiene SOLO numeros enteros adentro");
    else
        printf("\n\n Val 3: El string tiene otras cosas ademas de numeros solamente");

    if( ValidarSoloEnteros(s_1) )
    {
        printf("\n\n R1: Se contaran los posibles terminos ingresados...");
        printf("\n\n Resultado: %d", ContarTerminos(s_1));

        if( ContarTerminos(s_1) == 1 )
        {
            printf("\n\n Como el string solo tiene numeros, espacio y el simbolo de negativo, y ademas solo se corresponde con un termino, \n se lo tratara de pasar a numero de verdad... Procesando...");
            printf("\n\n Resultado: %ld", PasarStringANumero(s_1));
        }
    }

    printf("\n");

    return 0;
}
