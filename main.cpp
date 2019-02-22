
#include "String.h"

int main()
{
    char c;
    String s_1;

    printf("Hello world!\n Ingrese un String: ");
    scan(s_1);

    if( ValidarAlfanumerico(s_1) == TRUE )
        printf("\n\nES ALFANUMERICO!! ");
    else
        printf("\n\nNO ES, MARCHASTES!");

    return 0;
}
