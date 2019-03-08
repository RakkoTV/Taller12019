
#include "Menu.h"

//Muestra la pantalla inicial, da el puntapie inicial para iniciar toda la aplicacion
void MostrarMenu()
{
    Arbol a;
    String s_1;
    Comandos com_1;
    boolean salir = FALSE;

    //Se crea el arbol inicial
    Crear_Arbol(a);
    //Se crea el string inicial de comandos
    strcrear(s_1);

    printf(" Bienvenido al programa de Polinomios mas avanzado de la UDE!\n");

    while ( salir != TRUE )
    {
        printf("\n Ingrese Comando:  ");
        scan(s_1);

        com_1 = EstablecerComando(s_1);

        switch(com_1)
        {
            case ERROR:
                Mostrar_Error(1);
                break;
            case AYUDA:
                Mostrar_Ayuda();
                break;
            case SALIR:
            {
                printf(" Resultado:        Hasta la proxima\n");
                salir = TRUE;
                break;
            }
            default:
                ComenzarComando(com_1, s_1, a);
                break;
        }
    }

    //Libero toda la memoria, desde lo mas pequeño a lo mas grande
    strdestruir(s_1);
    SalirSistema(a);
}



