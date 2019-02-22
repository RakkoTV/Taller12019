#include "Termino.h"

/*
void Cargar_Termino_Desde_String(Termino &T, String s_1)/*
{
    array_dinamico arre,arre1;
    int i=0, cant=0, j;

     while(s_1[i] !='\0')
     {
         if(s_1[i] != ' ')
         {
             //capaz que poner una procedimiento que contemple que el usuario ponga varios espacios
             if (ConvertirCaracter(s_1[i]==45))
                 T.signo = '-';


                    else
                       {
                        cant=contarnumero(s_1);
                        CrearAD(arre,cant);
                        for(j=i;j<cant;j++)
                            arre[j]=ConvertirCaracter(s_1[j]);
                        DevuelveINT(arre[j],cant);


                       }

               i=j;
          }

          i++;

                        j=i;
                        cant=contarnumero(s_1);
                        CrearAD(arre1,cant);
                        for(j;j<cant;j++)
                        arre1[j]=ConvertirCaracter(s_1[j]);
                        DevuelveINT(arre1[j],cant);

     }

}


 int DevuelveINT (arre a, int cant)
{
    int n=0, i=0;

    if(cant==1)
    return arre[n];

    else
        n= arre[i] * potencia(10,cant-1)+ DevuelveINT(arre[i+1], cant -1);





    }

int potencia(x,y)
{
    int resultado=1;
    int i=1;
    for(i;i<y;i++)
     resultado=resultado*10;

    return resultado;
}

*/

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

void Cargar_Termino_Desde_String(Termino &T, long int coeficiente, int exponente, char signo)
{    ///aca va un for y strlargo para determinan el largo del string y recorrlo
     if (ConvertirCaracter(signo)==45)
           T.signo='-';

          T.coeficiente=coeficiente;
          T.exponente=exponente;

}


void Mostrar_Termino(Termino T)
{
    printf("%c",T.signo);
    printf("%d \t",T.coeficiente);
    printf("%d",T.exponente);


}




