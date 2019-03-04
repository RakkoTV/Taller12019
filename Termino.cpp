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
    //Se carga el coeficiente transformando el mismo a numero
    T.coeficiente= PasarStringANumero(s_1);

    //El signo solo para mostrarlo
    if(T.coeficiente<0)
        T.signo='-';
    else
        T.signo='+';

    //El exponente ya calculado en la lista previamente
    T.exponente=exponente;
}

void Mostrar_Termino(Termino T)
{
    //Solo se mostraran los terminos que no sean 0
    if(T.coeficiente != 0)
    {
        //Para que no se repita un doble signo --, se hace la siguiente condicion
        if( (T.coeficiente > 0) || (T.coeficiente == -1) )
            printf("%c", T.signo);

        if( ((T.coeficiente != 1) && (T.coeficiente != -1)) || ( T.exponente == 0 ) )
            printf("%ld",T.coeficiente);

        if( T.exponente >=1 )
            printf("x");

        if( T.exponente > 1)
            printf("%d", T.exponente);

        //OJO: Se agrega un espacio al final, para el uso explicito al recorrer todos los terminos de la lista
        printf(" ");
    }
}

void BajarTermino(FILE * stream, Termino T)
{
 fwrite(&T.signo,sizeof(char),1,stream);
 fwrite(&T.coeficiente,sizeof(long int),1,stream);
 fwrite(&T.exponente,sizeof(int),1,stream);
}

void SubirTermino(FILE * stream, Termino &T)
{
 fread(&T.signo,sizeof(char),1,stream);
 fread(&T.coeficiente,sizeof(long int),1,stream);
 fread(&T.exponente,sizeof(int),1,stream);

}


Termino MultiplicaTerm (Termino T1, Termino T2)
{
  Termino T3;
  T3.coeficiente= T1.coeficiente * T2.coeficiente;
  T3.exponente= T1.exponente + T2.exponente;
  return T3;
}

//Percondicion que los exponentes sean iguales
Termino SumarTermino(Termino T, Termino T2)
{

    T.coeficiente=T.coeficiente + T2.coeficiente;


   return T;

}
long int potenciaLong(long int x, int y)
{

        if (y<=0)
                return 1;
        else
                return x*(potenciaLong(x,y-1));

}





