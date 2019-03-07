
#include "Archivo.h"


void Arch_Crear(String nomach)
{
    FILE * stream;
    stream = fopen(nomach,"ab");
    fclose(stream);
}

boolean Arch_Existe(String nomach)
{
    boolean Ex=FALSE;

    FILE * stream;
    stream = fopen(nomach,"rb");

    if(stream!=NULL)
        Ex=TRUE;

    fclose(stream);
    return Ex;
}

boolean Arch_Esvacio(String nomach)
{
    boolean ES=FALSE;
    int buffer;
    FILE * stream;

    stream = fopen(nomach,"rb");
    //Como lo primero a leer es el codigo del expediente, se usa el sizeof de un int
    if((fread(&buffer,sizeof(int),1,stream)==0))
        ES = TRUE;

    fclose(stream);
    return ES;
}

void Agregar_Entero(String nomach, int n)
{
    FILE * stream;
    stream = fopen(nomach,"ab");
    fwrite(&n,sizeof(int),1,stream);
    fclose(stream);
}
