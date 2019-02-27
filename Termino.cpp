#include "Termino.h"





int DarCoeficiente(Termino T)
{
     return T.coeficiente;
}

int DarExponente(Termino T)
{
    return T.exponente;
}

char DarSigno(Termino T)
{
    return T.signo;
}

void Cargar_Termino_Desde_String(Termino &T, String s_1, int exponente)
 {
     T.coeficiente= PasarStringANumero(s_1);
     if(T.coeficiente<0)
        T.signo=45;
        else
           T.signo=' '; //En caso de que no tenga el signo de menos se carga la componente para no dejarle basura
        T.exponente=exponente;

}

void Mostrar_Termino(Termino T)
{
   // printf("%c",T.signo);
    if(T.coeficiente != 0)
    {

    printf("%d",T.coeficiente);
    printf(" ");
    if(T.exponente > 0)
    printf("%d \t",T.exponente);

    }




}

void BajarTermino(FILE * stream, Termino T)
{
 fwrite(&T.signo,sizeof(char),1,stream);
 fwrite(&T.coeficiente,sizeof(int),1,stream);
 fwrite(&T.exponente,sizeof(int),1,stream);
}

void SubirTermino(FILE * stream, Termino &T)
{
 fread(&T.signo,sizeof(char),1,stream);
 fread(&T.coeficiente,sizeof(int),1,stream);
 fread(&T.exponente,sizeof(int),1,stream);

}





