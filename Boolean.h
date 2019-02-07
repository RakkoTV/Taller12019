#ifndef BOOLEAN.H
#define BOOLEAN.H

#include <stdio.h>

typedef enum{FALSE,TRUE} boolean;

void Boolean_Cargar(boolean &boolean_1);
void Boolean_Mostrar(boolean boolean_1);

int TransformarNumero (boolean boolean1);

#endif // BOOLEAN
