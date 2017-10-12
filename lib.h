#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    char nombreUsuario[51];
    char passUsuario[30];
    int estadoUsuario;
    int idUsuario;
    float puntaje;
    int ventas;
    int nota;

}eUsuario;

typedef struct
{
    char nombreProducto[51];
    int idUsuario;
    int idProducto;
    int estadoProducto;
    int stock;
    int vendidos;
    float precio;

}eProducto;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//INGRESO DE DATOS

/**
* \brief Solicita un numero al usuario y lo valida
* \param input se carga el numero ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit limite inferior a validar
* \param hiLimit limite superior a validar
* \return si obtuvo el numero devuelve "0", en caso contrario devuelve "-1"
*/
int getInt(int* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit);

/**
* \brief Solicita un numero al usuario y lo valida
* \param input se carga el numero ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit limite inferior a validar
* \param hiLimit limite superior a validar
* \return si obtuvo el numero devuelve "0", en caso contrario devuelve "-1"
*/
int getFloat(float* input,char mensaje[],char eMensaje[],float lowLimit,float hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y lo valida
* \param input se carga el string ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit longitud minima de la cadena
* \param hiLimit longitud maxima de la cadena
* \return si obtuvo la cadena devuelve "0", en caso contrario devuelve "-1"
*/
int getStringLetras(char* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y lo valida
* \param input se carga el string ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit longitud minima de la cadena
* \param hiLimit longitud maxima de la cadena
* \return si obtuvo la cadena devuelve "0", en caso contrario devuelve "-1"
*/
int getStringValidado(char* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit);

/**
* \brief Solicita s o n al usuario y la valida
* \param input Se carga el caracter validado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \return Si obtuvo un caracter valido 0 si no -1
*/
int getSN(char* input, char message[], char eMessage[]);

/**
 * \brief Solicita una cadena de caracteres al usuario
 * \param mensaje Es el mensaje a  ser mostrado
 * \param input Array donde se cargara la cadena
 * \return Void No devuelve nada
 */
void getString(char mensaje[], char input[]);

/**
 * \brief Verifica si el valor recibido es numerico
 * \param string Es el array con la cadena a ser analizada
 * \return Si es numerico devuelve "0" si no lo es devuelve "-1"
 */
int esNumerico(char string[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param string Es el array con la cadena a ser analizada
 * \return Si contiene solo letras devuelbe "0" en caso contrario devuelve "-1"
 */
int esSoloLetras(char string[]);

/**
 * \brief Muestra el menu por pantalla
 * \param listado Es el listado de opciones que mostrara
 * \return Devuelve la opcion seleccionada por el usuario
 */
int menu(char listado[]);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//ABM (FUNCIONES VARIAS)

/**
 * \brief Inicializa el estado del array de usuarios con el valor pasado como parametro
 * \param usuarios Es el array que se pasa como parametro
 * \param tamU Es el tamaño del array
 * \param valor Es el valor que queremos cargar en el array
 * \return Void No devuelve nada
 */
void inicializarUsuarios(eUsuario usuarios[], int tamU, int valor);

/**
 * \brief Inicializa el estado del array de productos con el valor pasado como parametro
 * \param productos Es el array que se pasa como parametro
 * \param tamP Es el tamaño del array
 * \param valor Es el valor que queremos cargar en el array
 * \return Void No devuelve nada
 */
void inicializarProductos(eProducto productos[], int tamP, int valor);

/**
* \brief Obtiene el primer indice libre del array usuarios
* \param usuarios el array se pasa como parametro
* \param tamU el tamaño del array que se paso como parametro
* \return el primer indice disponible
*/
int obtenerEspacioLibreUsuarios(eUsuario usuarios[],int tamU);

/**
* \brief Obtiene el primer indice libre del array usuarios
* \param productos el array se pasa como parametro
* \param tamP el tamaño del array que se paso como parametro
* \return el primer indice disponible
*/
int obtenerEspacioLibreProductos(eProducto productos[],int tamP);

/**
 * \brief  Busca si el ID se encuentra activo
 * \param usuarios el array se pasa como parametro
 * \param tamU el tamaño del array que se paso como parametro
 * \param ID Es el ID a ser verificado
 * \return Devuelve 0 si esta activo o -1 si no esta activo
 */
int buscarPorIDU(eUsuario usuarios[],int tamU,int ID);

/**
 * \brief  Busca si el ID se encuentra activo
 * \param productos el array se pasa como parametro
 * \param tamP el tamaño del array que se paso como parametro
 * \param ID es el ID a ser verificado
 * \return Devuelve 0 si esta activo o -1 si no esta activo
 */
int buscarPorIDP(eProducto productos[],int tamP,int ID);

/**
 * \brief Agrega una persona al array
 * \param usuarios Es el array que se pasa como parametro
 * \param tamU Es el tamaño del array
 * \return Devuelve "1" si dio de alta a una persona, "-1" si no dio de alta a una persona
 */
int agregarUsuario(eUsuario usuarios[], int tamU);

/**
 * \brief Agrega un producto al array
 * \param usuarios array de usuarios
 * \param productos array de productos
 * \param tamU tamaño de array de usuarios
 * \param tamP tamaño e array de productos
 * \return Devuelve "0" si dio de alta a una persona, "-1" si no dio de alta a una persona
 */
int agregarProducto(eUsuario usuarios[], int tamU, eProducto productos[], int tamP);

/**
 * \brief Borra un usuario del array
 * \param usuarios array de usuarios
 * \param productos array de productos
 * \param tamU tamaño de array de usuarios
 * \param tamP tamaño e array de productos
 * \return Devuelve "0" en caso de borrar exitosamente al usuario, "-1" si no logra borrar al usuario
 */
int borrarUsuario(eUsuario usuarios[], int tamU, eProducto productos[],int tamP);

/**
 * \brief Modifica una persona del array
 * \param usuarios Es el array que se pasa como parametro
 * \param tamU Es el tamaño del array
 * \return Devuelve "0" si modifico a una persona, "-1" si no modifico a una persona
 */
int ModificarUsuario(eUsuario usuarios[], int tamU);

/**
 * \brief Modifica una publicacion del array
 * \param usuarios array de usuarios
 * \param productos array de productos
 * \param tamU tamaño de array de usuarios
 * \param tamP tamaño e array de productos
 * \return Devuelve "0" en caso de modificar exitosamente a la publicacion, "-1" si no logra modificar la publicacion
 */
int ModificarPublicacion(eUsuario usuarios[], int tamU, eProducto productos[], int tamP);

/**
 * \brief Modifica una persona del array
 * \param usuarios array de usuarios
 * \param productos array de productos
 * \param tamU tamaño de array de usuarios
 * \param tamP tamaño e array de productos
 * \return Devuelve "0" si cancelo la publicacion, "-1" si no la cancelo
 */
int CancelarPublicacion(eUsuario usuarios[], int tamU, eProducto productos[],int tamP);

/**
 * \brief Compra de un producto
 * \param usuarios array de usuarios
 * \param productos array de productos
 * \param tamU tamaño de array de usuarios
 * \param tamP tamaño e array de productos
 * \return Devuelve "0" si cancelo la publicacion, "-1" si no la cancelo
 */
int ComprarProducto(eUsuario usuarios[], int tamU, eProducto productos[],int tamP);

/**
 * \brief Lista las publicaciones activas
 * \param usuarios array de usuarios
 * \param productos array de productos
 * \param tamU tamaño de array de usuarios
 * \param tamP tamaño e array de productos
 * \return Void No devuelve nada
 */
void ListarPublicaciones(eUsuario usuarios[], int tamU, eProducto productos[], int tamP);

/**
 * \brief Lista las publicaciones activas por usuario
 * \param usuarios array de usuarios
 * \param productos array de productos
 * \param tamU tamaño de array de usuarios
 * \param tamP tamaño e array de productos
 * \return Void No devuelve nada
 */
void ListarPublicacionesUsuarios(eUsuario usuarios[], int tamU, eProducto productos[], int tamP);

/**
 * \brief Lista los usuarios activos
 * \param usuarios array de usuarios
 * \param tamU tamaño de array de usuarios
 * \return Void No devuelve nada
 */
void ListarUsuarios(eUsuario usuarios[], int tamU);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//HARDCODEO DE DATOS

/**
 * \brief Hardcodea el array de usuarios
 * \param usuarios Array que recibe para inicializar
 * \return Void No devuelve nada
 */
void HardcodeoUsuarios(eUsuario usuarios[]);

/**
 * \brief Hardcodea el array de usuarios
 * \param productos Array que recibe para inicializar
 * \return Void No devuelve nada
 */
void HardcodeoProductos(eProducto productos[]);

#endif // LIB_H_INCLUDED
