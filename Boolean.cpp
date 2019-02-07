
#include "Boolean.h"

void Boolean_Cargar(boolean &boolean_1)
{
    int aux;

    scanf("%d", &aux);
    if (aux == 1)
        boolean_1 = TRUE;
    else
        boolean_1 = FALSE;
}

void Boolean_Mostrar(boolean boolean_1)
{
    if (boolean_1 == TRUE)
        printf("TRUE");
    else
        printf("FALSE");
}

int TransformarNumero(boolean boolean1)
{
    if (boolean1 == FALSE)
        return 0;
    else
        return 1;
}

