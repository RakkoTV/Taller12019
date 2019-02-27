
#include "Errores.h"

//No tiene ningun typedef, ya que este modulo sólo servirá para tener centralizados los distintos tipos de errores
//escritos que pudieran producirse en la aplicación, y mostrarlos en pantalla cuando sea necesario.
//A raiz de un codigo interno del 1-50, se mostrará el error definido en la documentación.
void Mostrar_Error(int codigo)
{
    switch(codigo)
    {
        case 1:
            printf(" Resultado:        Comando no reconocido, vuelva a ingresarlo\n");
            break;
        case 2:
            printf(" Resultado:        Debe ingresar un nombre de Poinomio valido. El mismo debe ser Alfanumerico\n");
            break;
        case 3:
            printf(" Resultado:        No se puede crear este Polinomio porque el mismo ya existe en el sistema\n");
            break;
        case 4:
            printf(" Resultado:        Los coeficientes deben ser numeros enteros\n");
            break;
        case 5:
            printf(" Resultado:        No se ha ingresado ningun coeficiente valido\n");
            break;
        case 6:
            printf(" Resultado:        El primer coeficiente debe ser distinto de 0 en este caso\n");
            break;
        case 7:
            printf(" Resultado:        El archivo ya existe\n");
            break;
        case 8:
            printf(" Resultado:        El arbol se encuentra vacio\n");
            break;
        case 9:
            printf(" Resultado:        La extension no es la correcta\n");
            break;
        case 10:
            printf(" Resultado:        Debe ingresar el nombre del polinomio a crear, seguido de uno o varios coeficientes\n");
            break;
        case 11:
            printf(" Resultado:        Debe ingresar al menos algun coeficiente despues del nombre del polinomio\n");
            break;
    }
}

//Tambien, en este modulo se adjunta la funcion "MostrarAyuda()" con el fin de especificar en cualquier momento
//la lista de comandos al usuario final
void Mostrar_Ayuda()
{
    printf(" Resultado:        Las instrucciones se listaran a continuacion...\n");
}

