
#include "Errores.h"

//No tiene ningun typedef, ya que este modulo s�lo servir� para tener centralizados los distintos tipos de errores
//escritos que pudieran producirse en la aplicaci�n, y mostrarlos en pantalla cuando sea necesario.
//A raiz de un codigo interno del 1-50, se mostrar� el error definido en la documentaci�n.
void Mostrar_Error(int codigo)
{
    switch(codigo)
    {
        case 1:
            printf(" Resultado:        Comando no reconocido , vuelva a ingresarlo\n");
            break;
        case 2:
            printf(" Resultado:        Debe ingresar un nombre de Polinomio valido. El mismo debe ser Alfanumerico\n");
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
        case 12:
            printf(" Resultado:        Debe ingresar al menos algun numero entero despues del nombre del polinomio\n");
            break;
        case 13:
            printf(" Resultado:        Debe ingresar el nombre del polinomio a evaluar, seguido de un numero entero\n");
            break;
        case 14:
            printf(" Resultado:        No existe este polinomio en el arbol\n");
            break;
        case 15:
            printf(" Resultado:        El numero ingresado no es un numero entero\n");
            break;
        case 16:
            printf(" Resultado:        Debe ingresar un numero entero\n");
            break;
        case 17:
            printf(" Resultado:        Falta ingresar los polinomios a operar\n");
            break;
        case 18:
            printf(" Resultado:        Se deben ingresar exactamente 3 nombres de polinomios\n");
            break;
        case 19:
            printf(" Resultado:        El nombre del nuevo Polinomio a crear debe ser alfanumerico\n");
            break;
        case 20:
            printf(" Resultado:        El polinomio a crear con el resultado no puede estar ingresado en el sistema previamente\n");
            break;
        case 21:
            printf(" Resultado:        Error con el 2do polinomio ingresado. El nombre no es alfanumerico\n");
            break;
        case 22:
            printf(" Resultado:        Error con el 3er polinomio ingresado. El nombre no es alfanumerico\n");
            break;
        case 23:
            printf(" Resultado:        Error con el 2do polinomio ingresado. El mismo no existe en el sistema\n");
            break;
        case 24:
            printf(" Resultado:        Error con el 3er polinomio ingresado. El mismo no existe en el sistema\n");
            break;
        case 25:
            printf(" Resultado:        Falta ingresar el nombre del archivo\n");
            break;
        case 26:
            printf(" Resultado:        Debe ingresar solo el nombre del polinomio seguido del nombre de un archivo valido\n");
            break;
        case 27:
            printf(" Resultado:        El nombre del polinomio ingresado debe ser alfanumerico\n");
            break;
        case 28:
            printf(" Resultado:        El polinomio no existe en el sistema\n");
            break;
        case 29:
            printf(" Resultado:        El nombre del archivo debe ser Alfanumerico\n");
            break;
        case 30:
            printf(" Resultado:        El nombre del archivo debe tener minimo 1 letra y finalizar en '.txt'\n");
            break;
        case 31:
            printf(" Resultado:        Debe ingresar el nombre del nuevo polinomio seguido del archivo a leer para recuperarlo\n");
            break;
        case 32:
            printf(" Resultado:        Demasiadas palabras ingresadas, vuelva a intentarlo\n");
            break;
        case 33:
            printf(" Resultado:        El nombre del polinomio a crear ya existe en el arbol actualmente, reintente\n");
            break;
        case 34:
            printf(" Resultado:        El archivo no existe en disco actualmente\n");
            break;
        case 35:
            printf(" Resultado:        El polinomio NO fue guardado en el archivo\n");
            break;
    }
}

//Tambien, en este modulo se adjunta la funcion "MostrarAyuda()" con el fin de especificar en cualquier momento
//la lista de comandos al usuario final
void Mostrar_Ayuda()
{
    printf("--SINTAXIS DE COMANDOS--\n");
    printf("\n");
    printf("Sintaxis del comando CREAR: crear <nombre polinomio> <coef 1> <coef N> \n");
    printf("Sintaxis del comando SUMAR: sumar <nombre polinomio nuevo> <nombre polinomio 1> <nombre polinomio 2> \n");
    printf("Sintaxis del comando MULTIPLICAR: multiplicar <nombre polinomio nuevo> <nombre polinomio 1> <nombre polinomio 2> \n");
    printf("Sintaxis del comando EVALUAR: evaluar <nombre polinomio> <numero entero> \n");
    printf("Sintaxis del comando ESRAIZ: esraiz <nombre polinomio> <numero entero> \n");
    printf("Sintaxis del comando MOSTRAR: mostrar \n");
    printf("Sintaxis del comando GUARDAR: guardar <nombre polinomio> <nombre archivo.txt> \n");
    printf("Sintaxis del comando SALIR: salir \n");

    printf("\n");
    printf("--DESCRIPCION DE COMANDOS--\n");
    print("\n");
    printf("Comando CREAR: Crea un nuevo polinomio con el nombre en primer lugar y N coeficientes luego del nombre \n");
    printf("Comando SUMAR: Crea un nuevo polinomio cuyo nombre sera el primer ingresado y contendra la suma de los otros dos \n");
    printf("Comando MULTIPLICAR: Crea un nuevo polinomio cuyo nombre sera el primer ingresado y contendra la multiplicacion de los otros dos \n");
    printf("Comando EVALUAR: Despliega por pantalla el valor que se obtiene al susituir las x del polinomio ingresado, por el entero ingresado en segundo lugar \n");
    printf("Comando ESRAIZ:  Determina si el numero ingresado en segundo lugar es raiz del polinomio cuyo nombre se ingresa en primer lugar \n");
    printf("Comando MOSTRAR: Lista por pantalla los polinomios existentes en memoria \n");
    printf("Comando GUARDAR: Almacena el polinomio cuyo nombre se ingresa en primer lugar en un archivo con extension .txt cuyo nombre se ingresa en segundo lugar \n");
    printf("comando SALIR: sale del programa \n");



}

//Muestra la opcion de sobreescribir un archivo, para el comando Guardar
boolean MostrarSobreEscribir()
{
    char letra = 'A';
    boolean salir=FALSE, resultado;

    while ( salir == FALSE )
    {
        printf(" Resultado:        El archivo ya existe en el disco. Desea sobreescribirlo?[s/n] ");
        scanf("%c",&letra);
        fflush(stdin);

        switch(letra)
        {
            case 'n':
            case 'N':
            {
                salir = TRUE;
                resultado = FALSE;
                break;
            }
            case 's':
            case 'S':
            {
                salir = TRUE;
                resultado = TRUE;
                break;
            }
            default:
            {
                printf("                   ERROR: Ingrese s/n\n\n");
                break;
            }
        }
    }

    return resultado;
}

