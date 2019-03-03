#include "Comandos.h"

//A raiz de un String previamente cargado por teclado, se establecer� a cual comando se hace referencia.
//De esta manera, en el Menu se podra validar uno u otro comando, e invocar a aquel que sea correcto
Comandos EstablecerComando(String string_1)
{
    //Se declara un string auxiliar para guardar solo el nombre del comando
    String string_2;
    int largo_int = strlar(string_1);
    int i=0, j=0;
    Comandos com_1;

    //Se define string_2 con el tama�o de string_1 inicialmente, ya que no se sabe cuanto es el largo final de lo escrito
    string_2 = new char[largo_int+1];
    string_2[largo_int] = '\0';

    //Inicialmente, se sacan los espacios iniciales si los hubiera
    while ( string_1[i] == ' ' )
        i++;

    //Aca se comienza a cortar el primer termino, se lee hasta encontrarse un espacio y se copian los caracteres a string_2
    while ( (string_1[i] != ' ') && (string_1[i] != '\0') )
    {
        string_2[j] = string_1[i];
        i++;
        j++;
    }

    //"Acorto" el string_2 para topearlo hasta donde se leyo del string_1
    string_2[j] = '\0';

    //Una vez "cortado" la primera palabra, la comparare con los comandos a usar
    if( streq(string_2, "crear\0") )
        com_1 = CREAR;
    else
        if( streq(string_2, "sumar\0") )
            com_1 = SUMAR;
        else
            if( streq(string_2, "multiplicar\0") )
                com_1 = MULTIPLICAR;
            else
                if( streq(string_2, "evaluar\0") )
                    com_1 = EVALUAR;
                else
                    if( streq(string_2, "esraiz\0") )
                        com_1 = ESRAIZ;
                    else
                        if( streq(string_2, "mostrar\0") )
                            com_1 = MOSTRAR;
                        else
                            if( streq(string_2, "guardar\0") )
                                com_1 = GUARDAR;
                            else
                                if( streq(string_2, "recuperar\0") )
                                    com_1 = RECUPERAR;
                                else
                                    if( streq(string_2, "salir\0") )
                                        com_1 = SALIR;
                                    else
                                        if( streq(string_2, "ayuda\0") )
                                            com_1 = AYUDA;
                                        else
                                            com_1 = ERROR;

    //Para finalizar, se libera la memoria del array auxiliar y se retorna el comando encontrado
    strdestruir(string_2);
    return com_1;
}

//A raiz de un comando y de un string, se intenta comenzar la ejecucion del comando en cuestion.
//Dentro de esta funcion se llamara al validador auxiliar de cada comando para el string dado, si ocurre alguna falla,
//no se seguira con la ejecucion del comando y se dara el error correspondiente en pantalla.
void ComenzarComando(Comandos com_1, String string_1, Arbol &a)
{
    //Inicialmente se cortara el primer comando del string y se lo pasara a un string auxiliar. De esta manera,
    //tanto en las validaciones como en la ejecucion de cada comando no se tendra que volver a repetir este procedimiento
    //Se declara un string auxiliar para guardar solo el nombre del comando
    String string_2;
    String s_3,s_4;
    int largo_int = strlar(string_1);
    int i=0, j=0;

    //Se define string_2 con el tama�o de string_1 inicialmente, ya que no se sabe cuanto es el largo final de lo escrito
    string_2 = new char[largo_int+1];
    string_2[largo_int] = '\0';

    //Inicialmente, se sacan los espacios iniciales si los hubiera
    while ( string_1[i] == ' ' )
        i++;

    //Con lo siguiente, se leeran todos los caracteres del comando hasta el proximo espacio
    while ( (string_1[i] != ' ') && (string_1[i] != '\0') )
        i++;

    //Leo un espacio mas o los que hubiera antes de llegar a la siguiente palabra
    while ( (string_1[i] == ' ') && (string_1[i] != '\0') )
        i++;

    //Aca se separa todo lo siguiente y se lo guarda en el string_2
    while ( string_1[i] != '\0' )
    {
        string_2[j] = string_1[i];
        i++;
        j++;
    }

    //Termino el string_2 para topearlo hasta donde se leyo del string_1
    string_2[j] = '\0';

    switch(com_1)
    {
        case CREAR:
        {
            //En caso de que se de error en el comando,
            if ( ValidarCrear(string_2, a) )
                Crear(string_2, a);
            break;
        }
        case SUMAR:
        {

            break;
        }
        case MULTIPLICAR:
        {
                if ( ValidarMultiplicar(string_2,a))
                {
                    printf("\n HOLAAAAAAAAAAAA");
                    ExtraerNomnbresPoli(string_2, a, s_3, s_4);
                    EncontrarPolinomio(a, s_3);
                    EncontrarPolinomio(a, s_4);
                }


                //Crear(string_2, a);

            break;
        }
        case EVALUAR:
        {

            break;
        }
        case ESRAIZ:
        {

            break;
        }
        case MOSTRAR:
        {
            Mostrar(a);
            break;
        }
        case GUARDAR:
        {

            break;
        }
        case RECUPERAR:
        {

            break;
        }
    }

    //Para finalizar, elimino de la memoria el string auxiliar
    strdestruir(string_2);
}

//A raiz de un string pasado, devolvera true o false si el comando es valido y se puede proseguir con el mismo.
//Es el inicio del parsing, se realizara para cada comando ingresado.
//Se usaran todas las funciones auxiliares de parsing ya definidias en String.h
boolean ValidarCrear(String string_1, Arbol a)
{
    boolean resultado = TRUE;

    //1era validacion: Se debera ingresar minimamente 2 palabras: el nombre del nuevo polinomio y un termino
    if(ContarPalabras(string_1) < 2)
    {
        if ( ContarPalabras(string_1) == 1 )
        {
            Mostrar_Error(11);
            resultado = FALSE;
        }
        else
        {
            Mostrar_Error(10);
            resultado = FALSE;
        }
    }
    else
    {
        //2 Validacion: el nombre del polinomio ingresado tiene que ser Alfanumerico
        String string_2;
        int largo_int = strlar(string_1);
        int i=0, j=0;

        //Se define string_2 con el tama�o de string_1 inicialmente, ya que no se sabe cuanto es el largo final de lo escrito
        string_2 = new char[largo_int+1];
        string_2[largo_int] = '\0';

        while ( string_1[i] != ' ' )
        {
            string_2[j] = string_1[i];
            i++;
            j++;
        }

        //Termino el string_2 para topearlo hasta donde se leyo del string_1
        string_2[j] = '\0';

        //Al finalizar, en string_2 tendre cargado el posible nombre del polinomio
        if( !ValidarAlfanumerico(string_2) )
        {
            //Si el nombre no es alfanumerico, dara el error correspondiente
            Mostrar_Error(2);
            resultado = FALSE;
        }
        else
        {
            //3era validacion: El polinomio no existe en el arbol
            if ( ExistePolinomio(a, string_2) )
            {
                //Si ya existe algun polinomio con ese nombre, dara el error correspondiente
                Mostrar_Error(3);
                resultado = FALSE;
            }
            else
            {
                //Se continua cortando el string_1, ahora ya con miras a validar el conjunto de terminos cargados
                //Se sacan los espacios iniciales si los hubiera
                while ( string_1[i] == ' ' )
                    i++;

                String string_3;
                //Notar que la variable i se deja como esta, porque ya arranca desde donde se corto el nombre del polinomio
                j=0;

                //Se define string_3 con el tama�o de string_1 inicialmente, ya que no se sabe cuanto es el largo final de lo escrito
                string_3 = new char[largo_int+1];
                string_3[largo_int] = '\0';

                while ( string_1[i] != '\0' )
                {
                    string_3[j] = string_1[i];
                    i++;
                    j++;
                }

                //Termino el string_3 para topearlo hasta donde se leyo del string_1
                string_3[j] = '\0';

                //Una vez llegados a este punto, en string_3 tendre solamente la lista de terminos. Ahora resta continuar con las validaciones
                if ( !ValidarExisteUnNumero(string_3) )
                {
                    //4ta validacion: No se ingresos ningun numero entero
                    Mostrar_Error(5);
                    resultado = FALSE;
                }
                else
                {
                    //5ta validacion: Verificar que los numeros ingresados sean enteros
                    if( !ValidarSoloEnteros(string_3) )
                    {
                        Mostrar_Error(4);
                        resultado = FALSE;
                    }
                    else
                    {
                        //6ta validacion: Validar que el primer termino sea mayor a 0 en caso de que la cantidad de terminos sea mayor a 2
                        if ( !ValidarPrimerTermino(string_3) )
                        {
                            Mostrar_Error(6);
                            resultado = FALSE;
                        }
                    }
                }


                //Elimino string_3 de la memoria
                strdestruir(string_3);
            }
        }

        //Elimino string_2 de la memoria
        strdestruir(string_2);
    }

    return resultado;
}

//Se establece la funcion Crear, para a raiz de un string, crear un polinomio e insertarlo en el arbol.
//PRECONDICION: El string pasado debe haberse validado previamente antes de invocar esta funcion.
void Crear(String string_1, Arbol &a)
{
    //1er Paso: Separo el nombre del Polinomio de la Lista de Terminos.
    String nombre_pol;
    int largo_int = strlar(string_1);
    int i=0, j=0;

    //Como siempre, tengo cuidado con los espacios iniciales si los hubiera
    while ( string_1[i] == ' ' )
        i++;

    //Copio el nombre del string inicial al nuevo string
    nombre_pol = new char[largo_int+1];
    nombre_pol[largo_int] = '\0';

    while ( string_1[i] != ' ' )
    {
        nombre_pol[j] = string_1[i];
        i++;
        j++;
    }

    //Termino el string que incluye el nombre del polinomio
    nombre_pol[j] = '\0';

    //2do Paso: Leo hasta el final de lo que me resta en string_1 para crear el segundo string que contiene la lista de
    //coeficientes a agregar
    String lista_terminos;
    j=0;

    //Nuevamente, leo los espacios entre el nombre del comando y el primer termino que hubiera
    while ( string_1[i] == ' ' )
        i++;

    //Copio la lista del string inicial al nuevo string
    lista_terminos = new char[largo_int+1];
    lista_terminos[largo_int] = '\0';

    while ( string_1[i] != '\0' )
    {
        lista_terminos[j] = string_1[i];
        i++;
        j++;
    }

    //Termino el string que incluye la lista de terminos
    lista_terminos[j] = '\0';

    //Una vez separadas las cosas, invoco a las funciones correspondientes para agregarlas en el arbol
    Polinomio P_1;

    //Creo un nuevo Polinomio
    CrearPoli(P_1);
    Cargar_Polinomio_Desde_String(P_1, nombre_pol, lista_terminos);

    //Lo agrego en el arbol
    Insert(a, P_1);

    //Muestro el Polinomio creado como resultado
    printf(" Resultado:        ");
    Mostrar_Polinomio(P_1);
    printf("\n");

    //Elimino la memoria usada para los string auxiliares
    strdestruir(nombre_pol);
    strdestruir(lista_terminos);
}



boolean ValidarMultiplicar(String string_1, Arbol a)
{
    boolean resultado = TRUE;

    //1era validacion: Se debera ingresar minimamente 2 palabras: el nombre del nuevo polinomio y un termino
    if(ContarPalabras(string_1) < 3)
    {
        if ( ContarPalabras(string_1) == 1 )
        {
            Mostrar_Error(11);
            resultado = FALSE;
        }
        else
        {
            Mostrar_Error(10);
            resultado = FALSE;
        }
    }
    else
    {
        //2 Validacion: el nombre del polinomio ingresado tiene que ser Alfanumerico
        String string_2;
        int largo_int = strlar(string_1);
        int i=0, j=0;

        //Se define string_2 con el tama�o de string_1 inicialmente, ya que no se sabe cuanto es el largo final de lo escrito
        string_2 = new char[largo_int+1];
        string_2[largo_int] = '\0';

        while ( string_1[i] != ' ' )
        {
            string_2[j] = string_1[i];
            i++;
            j++;
        }

        //Termino el string_2 para topearlo hasta donde se leyo del string_1
        string_2[j] = '\0';

        //Al finalizar, en string_2 tendre cargado el posible nombre del polinomio
        if( !ValidarAlfanumerico(string_2) )
        {
            //Si el nombre no es alfanumerico, dara el error correspondiente
            Mostrar_Error(2);
            resultado = FALSE;
        }
        else
        {
            //3era validacion: El polinomio no existe en el arbol
            if ( ExistePolinomio(a, string_2) )
            {
                //Si ya existe algun polinomio con ese nombre, dara el error correspondiente
                Mostrar_Error(3);
                resultado = FALSE;
            }
            else
            {
                //Se continua cortando el string_1, ahora ya con miras a validar el conjunto de terminos cargados
                //Se sacan los espacios iniciales si los hubiera
                while ( string_1[i] == ' ' )
                    i++;

                String string_3;
                //Notar que la variable i se deja como esta, porque ya arranca desde donde se corto el nombre del polinomio
                j=0;

                //Se define string_3 con el tama�o de string_1 inicialmente, ya que no se sabe cuanto es el largo final de lo escrito
                string_3 = new char[largo_int+1];
                string_3[largo_int] = '\0';

                while ( string_1[i] != ' ' )
                {
                    string_3[j] = string_1[i];
                    i++;
                    j++;
                }

                //Termino el string_3 para topearlo hasta donde se leyo del string_1
                string_3[j] = '\0';


                //Se continua cortando el string_1, ahora ya con miras a validar el conjunto de terminos cargados
                //Se sacan los espacios iniciales si los hubiera
                while ( string_1[i] == ' ' )
                    i++;

                String string_4;
                //Notar que la variable i se deja como esta, porque ya arranca desde donde se corto el nombre del polinomio
                j=0;

                //Se define string_4 con el tama�o de string_1 inicialmente, ya que no se sabe cuanto es el largo final de lo escrito
                string_4 = new char[largo_int+1];
                string_4[largo_int] = '\0';

                while ( string_1[i] != '\0' )
                {
                    string_4[j] = string_1[i];
                    i++;
                    j++;
                }

                //Termino el string_3 para topearlo hasta donde se leyo del string_1
                string_4[j] = '\0';


                //Validacion: El polinomio no existe en el arbol
                if (!ExistePolinomio(a, string_4) )
                {
                    //Si ya existe algun polinomio con ese nombre, dara el error correspondiente
                    Mostrar_Error(3);
                    resultado = FALSE;
                }


                //Elimino string_3 de la memoria
                strdestruir(string_4);

                //Validacion: El polinomio no existe en el arbol
                if (!ExistePolinomio(a, string_3) )
                {
                    //Si ya existe algun polinomio con ese nombre, dara el error correspondiente
                    Mostrar_Error(3);
                    resultado = FALSE;
                }


                //Elimino string_3 de la memoria
                strdestruir(string_3);
            }
        }

        //Elimino string_2 de la memoria
        strdestruir(string_2);
    }

    return resultado;
}


void ExtraerNomnbresPoli(String string_1, Arbol a, String &string_3, String &string_4)
{
    boolean resultado = TRUE;

    //1era validacion: Se debera ingresar minimamente 2 palabras: el nombre del nuevo polinomio y un termino
    if(ContarPalabras(string_1) < 3)
    {
        if ( ContarPalabras(string_1) == 1 )
        {
            Mostrar_Error(11);
            resultado = FALSE;
        }
        else
        {
            Mostrar_Error(10);
            resultado = FALSE;
        }
    }
    else
    {
        //2 Validacion: el nombre del polinomio ingresado tiene que ser Alfanumerico
        String string_2;
        int largo_int = strlar(string_1);
        int i=0, j=0;

        //Se define string_2 con el tama�o de string_1 inicialmente, ya que no se sabe cuanto es el largo final de lo escrito
        string_2 = new char[largo_int+1];
        string_2[largo_int] = '\0';

        while ( string_1[i] != ' ' )
        {
            string_2[j] = string_1[i];
            i++;
            j++;
        }

        //Termino el string_2 para topearlo hasta donde se leyo del string_1
        string_2[j] = '\0';

        //Al finalizar, en string_2 tendre cargado el posible nombre del polinomio
        if( !ValidarAlfanumerico(string_2) )
        {
            //Si el nombre no es alfanumerico, dara el error correspondiente
            Mostrar_Error(2);
            resultado = FALSE;
        }
        else
        {
            //3era validacion: El polinomio no existe en el arbol
            if ( ExistePolinomio(a, string_2) )
            {
                //Si ya existe algun polinomio con ese nombre, dara el error correspondiente
                Mostrar_Error(3);
                resultado = FALSE;
            }
            else
            {
                //Se continua cortando el string_1, ahora ya con miras a validar el conjunto de terminos cargados
                //Se sacan los espacios iniciales si los hubiera
                while ( string_1[i] == ' ' )
                    i++;

                String string_3;
                //Notar que la variable i se deja como esta, porque ya arranca desde donde se corto el nombre del polinomio
                j=0;

                //Se define string_3 con el tama�o de string_1 inicialmente, ya que no se sabe cuanto es el largo final de lo escrito
                string_3 = new char[largo_int+1];
                string_3[largo_int] = '\0';

                while ( string_1[i] != ' ' )
                {
                    string_3[j] = string_1[i];
                    i++;
                    j++;
                }

                //Termino el string_3 para topearlo hasta donde se leyo del string_1
                string_3[j] = '\0';


                //Se continua cortando el string_1, ahora ya con miras a validar el conjunto de terminos cargados
                //Se sacan los espacios iniciales si los hubiera
                while ( string_1[i] == ' ' )
                    i++;

                String string_4;
                //Notar que la variable i se deja como esta, porque ya arranca desde donde se corto el nombre del polinomio
                j=0;

                //Se define string_4 con el tama�o de string_1 inicialmente, ya que no se sabe cuanto es el largo final de lo escrito
                string_4 = new char[largo_int+1];
                string_4[largo_int] = '\0';

                while ( string_1[i] != '\0' )
                {
                    string_4[j] = string_1[i];
                    i++;
                    j++;
                }

                //Termino el string_3 para topearlo hasta donde se leyo del string_1
                string_4[j] = '\0';


                //Validacion: El polinomio no existe en el arbol
                if (!ExistePolinomio(a, string_4) )
                {
                    //Si ya existe algun polinomio con ese nombre, dara el error correspondiente
                    Mostrar_Error(3);
                    resultado = FALSE;
                }


                //Elimino string_3 de la memoria
                strdestruir(string_4);

                //Validacion: El polinomio no existe en el arbol
                if (!ExistePolinomio(a, string_3) )
                {
                    //Si ya existe algun polinomio con ese nombre, dara el error correspondiente
                    Mostrar_Error(3);
                    resultado = FALSE;
                }


                //Elimino string_3 de la memoria
                strdestruir(string_3);
            }
        }

        //Elimino string_2 de la memoria
        strdestruir(string_2);
    }


}

//Se establece el comando Mostrar. Si no existe ningun polinomio a mostrar, se imprimira aca tambien el mensaje en pantalla.
//Si no, se invoca a las funciones de mostrar arbol, polinomio y termino en cada caso.
void Mostrar(Arbol a)
{
    if( EsVacio_Arbol(a) )
         printf(" Resultado:        No se ha ingresado ningun Polinomio al sistema\n");
    else
    {
        printf(" Resultado:        \n");
        MostrarArbol(a);
    }
}
