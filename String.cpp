
#include "String.h"

//Crea un string vacio.
void strcrear(String &string_1)
{
    string_1 = new char[1];
    string_1[0] = '\0';
}

//Libera la memoria ocupada por el string y lo deja nulo.
void strdestruir(String &string_1)
{
    delete [] string_1;
    string_1 = NULL;
}

//Devuelve el largo de un string. Se entiende por largo, la cantidad de caracteres antes del car�cter nulo.
int strlar(String string_1)
{
    int i=0;

    while( string_1[i] != '\0' )
        i++;

    return i;
}

//Devuelve el largo de un string. Se entiende por largo, la cantidad de caracteres antes del espacio.
int contarnumero(String string_1)
{
    int i=0;
    printf("%c",string_1[0]);
    while( (string_1[i] != ' ') /*|| (string_1[i] != '\0')*/)
        i++;

    return i;
}


//Recibe dos strings y copia el segundo en el primero.
void strcop(String &string_1, String string_2)
{
    //Para no dejar memoria in�til, primeramente eliminar� toda la memoria del array dinamico del string_1
    delete [] string_1;

    //De acuerdo al tama�o del string_2, reservar� los espacios de memoria necesarios
    int largo = strlar(string_2);
    //Se le suma uno por el caracter '\0'
    string_1 = new char[largo+1];

    int i=0;
    while( string_2[i] != '\0' )
    {
        //Copio la celda del string_2 en el mismo lugar del string_1
        string_1[i] = string_2[i];
        i++;
    }

    //Agrego el caracter de fin de linea en el string_1
    string_1[i] = '\0';
}

//Lee un string desde el teclado. Se tomar�n en cuenta los primeros 79 caracteres
//significativos en caso de que el largo del string sea mayor o igual a 80. Un string
//finaliza cuando se lea un car�cter �nueva l�nea� el cual se sustituir� por uno nulo.
void scan(String &string_1)
{
    //En forma temporal, creo un string auxiliar de tamanio MAX. Se usar� para guardar temporalmente en memoria lo leido por
    //teclado, para luego pasarlo al otro string din�mico.
    String aux = new char[MAX];
    int i =0;

    do
    {
        scanf("%c", &aux[i]);
        i++;
    } while( (i < MAX) && (aux[i-1] != '\n') );

    aux[i-1] = '\0';
    fflush(stdin);

    //Procedimiento de copiado y eliminacion del string aux leido
    strcop(string_1, aux);
    strdestruir(aux);
}

//Recibe dos strings y concatena el segundo string al final del primero, la concatenaci�n
//deber� quedar sobre el primero de los dos. En caso de que el largo de los strings
//exceda los 79 caracteres, no se tomar�n los caracteres excedentes del segundo string.
void strcon(String &string_1, String string_2)
{
    int i=0, j=0, largo=0;

    //Necesito saber el largo de ambos string para calcular de cuanto sera el tama�o del nuevo string_1
    largo = strlar(string_1) + strlar(string_2);
    if ( largo < MAX)
        largo = largo + 1;
    else
        largo = MAX;

    //De acuerdo a mis necesidades, creare un string auxiliar con el tamanio correcto
    String aux = new char[largo];

    //Voy copiando el string_1 en �l
    while( string_1[i] != '\0' )
    {
        aux[i] = string_1[i];
        i++;
    }

    //Ahora copio el string_2
    while( (string_2[j] != '\0') && ( i < MAX-1 ) )
    {
        aux[i] = string_2[j];
        j++;
        i++;
    }

    //Ingreso el caracter de fin de linea
    aux[i] = '\0';
    //Destruyo el actual string_1, y apunto al puntero al nuevo string
    delete [] string_1;
    string_1 = aux;
}

//Recibe dos strings y devuelve el primero en el segundo, y viceversa.
void strswp(String &string_1, String &string_2)
{
    String aux;
    strcrear(aux);
    strcop(aux, string_1);
    strcop(string_1, string_2);
    strcop(string_2, aux);
    strdestruir(aux);
}

//Despliega un string por pantalla.
void print(String string_1)
{
    int i=0;

    while( string_1[i] != '\0' )
    {
        printf("%c", string_1[i]);
        i++;
    }
}

//Recibe dos strings y devuelve TRUE si el primero de ellos es menor (en orden
//alfab�tico) que el segundo, o FALSE en caso contrario.
boolean strmen(String string_1, String string_2)
{
    int i=0, aux=0;
    boolean resultado=FALSE, salir=FALSE;

    while( (string_1[i] != '\0') && (salir == FALSE) )
    {
        if ( string_1[i] == string_2[i] )
        {
            i++;
        }
        else
        {
            if ( string_1[i] < string_2[i] )
            {
                salir = TRUE;
                resultado = TRUE;
            }
            else
            {
                salir = TRUE;
                resultado = FALSE;
            }
        }
    }

    return resultado;
}

//Reciba dos strings y devuelve TRUE si ambos strings son iguales o FALSE en caso
//contrario.
boolean streq(String string_1, String string_2)
{
    int i=0;
    boolean resultado = TRUE;

    if(strlar(string_1) == strlar(string_2))
    {
        //Si el tamanio es igual, los comparo uno a uno. Si no ni me molesto, es malgastar procesador para nada.
        while( (string_1[i] != '\0') && (resultado == TRUE) )
        {
            if ( string_1[i] != string_2[i]  )
                resultado = FALSE;

            i++;
        }
    }
    else
        resultado = FALSE;

    return resultado;
}

//Guardara el String "string_1" dentro del archivo de nombre "nomach"
void Bajar_String(FILE * stream, String string_1)
{
    //Se recorrera todo el string hasta el '\0', el cual se cargara tambien en el archivo
    int i=0;
    while( string_1[i] != '\0' )
    {
        fwrite(&string_1[i],sizeof(char),1,stream);
        i++;
    }

    //Agrego el \0 tambien en el archivo, el cual fue excluido por la condicion del while antes
    fwrite(&string_1[i],sizeof(char),1,stream);
}

//Leera del puntero stream un string, y lo levantara en memoria en "sring_1"
void Subir_String(FILE * stream, String &string_1)
{
    //En forma temporal, creo un string auxiliar de tamanio MAX. Se usar� para guardar temporalmente en memoria lo leido en el archivo.
    String aux = new char[MAX];
    int i=0;

    //El archivo debio haber sido abierto previamente en modo "rb", escritura
    do
    {
        //Voy leyendo letra a letra
        fread(&aux[i],sizeof(char),1,stream);
        i++;
    } while( (aux[i-1] != '\0') ); //Hacer hasta que el ultimo dato leido, sea el '\0'

    //Procedimiento de copiado y eliminacion del string aux leido. De esa manera se genera el nuevo string dinamico.
    strcop(string_1, aux);
    strdestruir(aux);
}

//A raiz de un string, valida si el mismo es o no un alfanumerico
boolean ValidarAlfanumerico(String string_1)
{
    int i=0;
    boolean es_alfanumerico = TRUE;

    while( (string_1[i] != '\0') && (es_alfanumerico == TRUE) )
    {
        if(
          /* Letras de la A-Z */
          ( (int(string_1[i]) >= 65) && (int(string_1[i]) <= 90) )
        )
            i++;
        else
            /* Letras de la a-z */
            if(
              ( (int(string_1[i]) >= 97) && (int(string_1[i]) <= 122) )
            )
            i++;
            else
                /* Numeros de 0-9 */
                if(
                   ( (int(string_1[i]) >= 48) && (int(string_1[i]) <= 57) )
                )
                    i++;
                else
                    /* El espacio tambien lo dara como valido */
                    if ( (int(string_1[i]) == 32) )
                        i++;
                    else
                        es_alfanumerico = FALSE;
    }

    return es_alfanumerico;
}

//Se lee una cadena de caracteres de posibles terminos, y se devuelve TRUE/FALSE si
//se encontro caracteres extra�os. Esto validara que los posibles terminos solo
//tengan numeros, y que los mismos sean enteros, porque si se ingresa un �.� o una
//�,� los caraceres se reconoceran como invalidos.
//Tambien servira para verificar que en el comando evaluar se haya ingresado un entero
boolean ValidarSoloEnteros(String string_1)
{
    int i=0;
    boolean es_entero = TRUE;

    while( (string_1[i] != '\0') && (es_entero == TRUE) )
    {
        /* Numeros de 0-9, -, o espacio */
        if(
            ( (int(string_1[i]) >= 48) && (int(string_1[i]) <= 57) )
            ||
            (int(string_1[i]) == 32)
            ||
            (int(string_1[i]) == 45)
        )
            i++;
        else
            es_entero = FALSE;
    }

    return es_entero;
}

//Se valida que minimamente se haya ingresado algun numero. Porque la funcion
//ValidarSoloEnteros puede dar true si se ingreso solo espacios
//Tambien servira para verificar que en el comando evaluar se haya ingresado un entero
boolean ValidarExisteUnNumero(String string_1)
{
    int i=0;
    boolean es_entero = TRUE;

    while( (string_1[i] != '\0') && (es_entero == TRUE) )
    {
        /* Numeros de 0-9 solamente*/
        if(
            ( (int(string_1[i]) >= 48) && (int(string_1[i]) <= 57) )
        )
            i++;
        else
            es_entero = FALSE;
    }

    return es_entero;
}

//A raiz de un char que representa un caracter del 0-9, se deuelve el mismo en formato numero
//PRECONDICION: c_1 solo puede tener caraceres que represente un numero del 0-9
int ConvertirCaracter(char c_1)
{
    switch(c_1)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    default:
        return 45;
        break;
    }
}

//A raiz de un string que represente un numero positivo o negativo, se convierte al mismo en formato numero.
//PRECONDICION: El string no puede representar un numero mayor a lo maximo que permie almacenar el long int.
long int PasarStringANumero(String string_1)
{
    boolean flagnegativo = FALSE;
    int numerofinal = 0;
    int contador = 0;

    //Se crea el string 2 auxiliar
    String string_2;
    strcrear(string_2);

    //Se copian todos los caracteres numericos de s_1 en s_2, eliminando cualquier espacio o simbolo neativo que hubiera entre ellos
    int i=0,j=0;
    while( string_1[i] != '\0' )
    {
        //Si es un numero del 0-9
        if( (int(string_1[i]) >= 48) && (int(string_1[i]) <= 57) )
        //Copio la celda del string_2 en el mismo lugar del string_1
            string_2[i] = string_1[i];
        i++;
    }


}







