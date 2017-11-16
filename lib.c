#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "lib.h"

//INGRESO DE DATOS

int getInt(int* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit)
{
    int aux;
    char auxChar[256];

    getString(mensaje,auxChar);
    if(esNumerico(auxChar) == -1)
    {
        printf("Este campo solo admite numeros enteros\n");
        return -1;
    }
    aux = atoi(auxChar);
    if(aux < lowLimit || aux > hiLimit)
    {
        printf("%s", eMensaje);
        return -1;
    }
    else
    {
        *input = aux;
        return 0;
    }
}

int getFloat(float* input,char mensaje[],char eMensaje[],float lowLimit,float hiLimit)
{
    float aux;
    char auxChar[256];

    getString(mensaje,auxChar);
    if(esNumerico(auxChar) == -1)
    {
        printf("Este campo solo admite numeros enteros\n");
        return -1;
    }
    aux = atof(auxChar);
    if(aux < lowLimit || aux > hiLimit)
    {
        printf("%s", eMensaje);
        return -1;
    }
    else
    {
        *input = aux;
        return 0;
    }
}

int getStringLetras(char* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit)
{
    char aux[50];
    char auxLetras[256];

    getString(mensaje,auxLetras);
    if(esSoloLetras(auxLetras) == -1)
    {
        printf("Este campo solo admite letras\n");
        return -1;
    }
    strcpy(aux,auxLetras);
    if(strlen(aux) < lowLimit || strlen(aux) > hiLimit)
    {
        printf("%s", eMensaje);
        return -1;
    }
    else
    {
        strcpy(input,aux);
        return 0;
    }
}

int getStringValidado(char* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit)
{
    char aux[50];

    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);
    if(strlen(aux) < lowLimit || strlen(aux) > hiLimit)
    {
        printf("%s", eMensaje);
        return -1;
    }
    else
    {
        strcpy(input,aux);
        return 0;
    }
}

int getSN(char* input, char mensaje[], char eMensaje[])
{
    char aux;
    printf("%s", mensaje);
    aux = tolower(getche());
    if(aux != 's' && aux != 'n')
    {
        printf("%s", eMensaje);
        return -1;
    }
    else
    {
        *input = aux;
        return 0;
    }
}

void getString(char mensaje[], char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int esNumerico(char string[])
{
    int i = 0;
    while(string[i] != '\0')
    {
        if((string[i] != '.') && (string[i] < '0' || string[i] > '9'))
        {
            return -1;
        }
        i++;
    }
    return 0;
}

int esSoloLetras(char string[])
{
    int i = 0;
    while(string[i] != '\0')
    {
        if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
        {
            return -1;
        }
        i++;
    }
    return 0;
}

int menu(char listado[])
{
    int opcion;
    char aux[50];

    printf("%s", listado);
    fflush(stdin);
    gets(aux);
    if(!esNumerico(aux))
    {
        opcion = atoi(aux);
        return opcion;
    }
    else
    {
        printf("Este campo solo admite numeros enteros\n");
        system("pause");
        return 0;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//ABM (FUNCIONES VARIAS)

void inicializarUsuarios(eUsuario usuarios[], int tamU, int valor)
{
    int i;

    for(i=0;i<tamU;i++)
    {
        usuarios[i].estadoUsuario = valor;
    }
}

void inicializarProductos(eProducto productos[], int tamP, int valor)
{
    int i;

    for(i=0;i<tamP;i++)
    {
        productos[i].estadoProducto = valor;
    }
}

int obtenerEspacioLibreUsuarios(eUsuario usuarios[],int tamU)
{
    int i;

    for(i=0;i<tamU;i++)
    {
        if(usuarios[i].estadoUsuario == 0)
        {
            return i;
        }
    }
    return -1;
}

int obtenerEspacioLibreProductos(eProducto productos[],int tamP)
{
    int i;

    for(i=0;i<tamP;i++)
    {
        if(productos[i].estadoProducto == 0)
        {
            return i;
        }
    }
    return -1;
}

int buscarPorIDU(eUsuario usuarios[],int tamU,int ID)
{
    int i;

    for(i=0;i<tamU;i++)
    {
        if(usuarios[i].idUsuario == ID && usuarios[i].estadoUsuario != 0)
        {
            return i;
        }
    }
    printf("ID no encontrado\n");
    return -1;
}

int buscarPorIDP(eProducto productos[],int tamP,int ID)
{
    int i;

    for(i=0;i<tamP;i++)
    {
        if(productos[i].idProducto == ID && productos[i].estadoProducto != 0)
        {
            return i;
        }
    }
    printf("ID no encontrado\n");
    return -1;
}

int agregarUsuario(eUsuario usuarios[], int tamU)
{
    int i;
    int respuesta;

    i = obtenerEspacioLibreUsuarios(usuarios,tamU);
    if(i == -1)
    {
        printf("Error. Lista llena\n");
        return -1;
    }

    respuesta = getStringLetras(usuarios[i].nombreUsuario,"Ingrese el nombre de usuario: ","\nERROR. El nombre debe contener entre 1 y 50 caracteres",1,50);
    if(respuesta == -1)
    {
        return -1;
    }

    respuesta = getStringValidado(usuarios[i].passUsuario,"Ingrese la contrasenia: ","\nERROR. La contraseña debe contener entre 6 y 18 caracteres",1,30);
    if(respuesta == -1)
    {
        return -1;
    }

    usuarios[i].idUsuario=i+1;
    usuarios[i].puntaje=0;
    usuarios[i].estadoUsuario = 1;
    usuarios[i].nota =0;
    usuarios[i].ventas =0;
    printf("Su ID es: %d\n",usuarios[i].idUsuario);
    return 0;
}

int agregarProducto(eUsuario usuarios[], int tamU, eProducto productos[], int tamP)
{
    int i;
    int respuesta;
    int IDAux;
    int ID;
    char Aux[50];

    i = obtenerEspacioLibreProductos(productos,tamP);
    if(i == -1)
    {
        printf("Error. Lista llena\n");
        return -1;
    }

    printf("Ingrese el ID del usuario con el que cargara el producto: ");
    fflush(stdin);
    gets(Aux);
    if(esNumerico(Aux) == -1)
    {
        printf("Este campo solo admite numeros enteros\n");
        return -1;
    }
    IDAux = atoi(Aux);
    ID = buscarPorIDU(usuarios,tamU,IDAux);
    if(ID == -1)
    {
        return -1;
    }

    respuesta = getStringValidado(productos[i].nombreProducto,"Ingrese el nombre del producto: ","\nError. El nombre debe contener entre 1 y 50 caracteres",1,50);
    if(respuesta == -1)
    {
        return -1;
    }

    respuesta = getInt(&productos[i].stock,"Ingrese el stock del producto: ","\nError. El stock debe estar comprendido entre 1 y 500 unidades",1,500);
    if(respuesta == -1)
    {
        return -1;
    }

    respuesta = getFloat(&productos[i].precio,"Ingrese el precio del producto: ","\nError. El precio debe estar comprendido entre 1 y 500 pesos",1.00,500.00);
    if(respuesta == -1)
    {
        return -1;
    }

    productos[i].vendidos=0;
    productos[i].idProducto = i+1;
    productos[i].idUsuario=IDAux;
    productos[i].estadoProducto = 1;
    return 0;
}

int borrarUsuario(eUsuario usuarios[], int tamU, eProducto productos[],int tamP)
{
    int i;
    int j;
    int IDAux;
    char respuesta;
    char Aux[50];

    printf("Ingrese el ID de la persona a borrar: ");
    fflush(stdin);
    gets(Aux);
    if(esNumerico(Aux) == -1)
    {
        printf("Este campo solo admite numeros enteros\n");
        return -1;
    }
    IDAux = atoi(Aux);
    i = buscarPorIDU(usuarios,tamU,IDAux);
    if(i == -1)
    {
        return -1;
    }
    else
    {
        system("cls");
        printf("Nombre: %s",usuarios[i].nombreUsuario);
        printf("\nContrasenia: %s",usuarios[i].passUsuario);
        printf("\nID: %d",usuarios[i].idUsuario);
        getSN(&respuesta,"\nEsta seguro que desea eliminar? s/n","\nError. Opcion no valida");
        if(respuesta == 's')
        {
            usuarios[i].estadoUsuario = 0;
            usuarios[i].idUsuario=0;
            for(j=0;j<tamP;j++)
            {
                if(productos[j].idUsuario == IDAux)
                {
                    productos[j].estadoProducto = 0;
                }
            }
            return 0;
        }
        return -1;
    }
}

int ModificarUsuario(eUsuario usuarios[], int tamU)
{
    int i;
    int IDAux;
    char Aux[50];
    char respuesta;

    printf("Ingrese el ID de la persona a modificar: ");
    fflush(stdin);
    gets(Aux);
    if(esNumerico(Aux) == -1)
    {
        printf("Este campo solo admite numeros enteros\n");
        return -1;
    }
    IDAux = atoi(Aux);
    i = buscarPorIDU(usuarios,tamU,IDAux);
    if(i == -1)
    {
        return -1;
    }
    else
    {
        system("cls");
        printf("Nombre: %s",usuarios[i].nombreUsuario);
        printf("\nContrasenia: %s",usuarios[i].passUsuario);
        printf("\nID: %d",usuarios[i].idUsuario);
        getSN(&respuesta,"\nEsta seguro que desea modificar los datos? s/n","\nError. Opcion no valida");
        if(respuesta == 's')
        {
            respuesta = getStringLetras(usuarios[i].nombreUsuario,"\n\nIngrese el nuevo nombre de usuario: ","\nERROR. El nombre debe contener entre 1 y 50 caracteres",1,50);
            if(respuesta == -1)
            {
                return -1;
            }

            respuesta = getStringValidado(usuarios[i].passUsuario,"Ingrese la nueva contrasenia: ","\nERROR. La contraseña debe contener entre 6 y 18 caracteres",1,30);
            if(respuesta == -1)
            {
                return -1;
            }
            return 0;
        }
        return -1;
    }
}

int ModificarPublicacion(eUsuario usuarios[], int tamU, eProducto productos[], int tamP)
{
    int i;
    int j;
    int IDU;
    char Aux[50];
    char respuesta;
    int flag=0;

    int q;
    int IDP;
    char Aux1[50];

    printf("Ingrese el ID de la persona para listar sus productos: ");
    fflush(stdin);
    gets(Aux);
    if(esNumerico(Aux) == -1)
    {
        printf("Este campo solo admite numeros enteros\n");
        return -1;
    }
    IDU = atoi(Aux);
    i = buscarPorIDU(usuarios,tamU,IDU);
    if(i == -1)
    {
        return -1;
    }
    else
    {
        printf("ID--NOMBRE PRODUCTO--PRECIO--CANTIDAD VENDIDA--STOCK--NOMBRE USUARIO\n");
        for(j=0;j<tamP;j++)
        {
            if(productos[j].idUsuario == IDU && productos[j].estadoProducto == 1)
            {
                printf("%d--%s--%.2f--%d--%d\n",productos[j].idProducto,productos[j].nombreProducto,productos[j].precio,productos[j].vendidos,productos[j].stock);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            system("cls");
            printf("No hay publicaciones activas\n");
            return -1;
        }
        printf("Ingrese el ID de la publicacion que desea modificar: ");
        fflush(stdin);
        gets(Aux1);
        if(esNumerico(Aux1) == -1)
        {
            printf("Este campo solo admite numeros enteros\n");
            return -1;
        }
        IDP = atoi(Aux1);
        q = buscarPorIDP(productos,tamP,IDP);
        if(q == -1)
        {
            return -1;
        }
        else
        {
                    printf("\nID: %d\n",productos[q].idProducto);
                    printf("NOMBRE: %s\n",productos[q].nombreProducto);
                    printf("PRECIO: %.2f\n",productos[q].precio);
                    printf("VENDIDOS: %d\n",productos[q].vendidos);
                    printf("STOCK: %d\n",productos[q].stock);
                    getSN(&respuesta,"\nEsta seguro que desea modificar los datos? s/n","\nError. Opcion no valida");
                    if(respuesta == 's')
                    {
                        respuesta = getInt(&productos[q].stock,"\nIngrese el nuevo stock del producto: ","\nError. El stock debe estar comprendido entre 1 y 500 unidades",1,500);
                        if(respuesta == -1)
                        {
                            return -1;
                        }

                        respuesta = getFloat(&productos[q].precio,"Ingrese el nuevo precio del producto: ","\nError. El precio debe estar comprendido entre 1 y 500 pesos",1.00,500.00);
                        if(respuesta == -1)
                        {
                            return -1;
                        }
                        return 0;
                    }
                    return -1;
            }
            return -1;
    }
    return -1;
}

int CancelarPublicacion(eUsuario usuarios[], int tamU, eProducto productos[],int tamP)
{
    int i;
    int j;
    int IDU;
    char Aux[50];
    char respuesta;
    int flag=0;

    int q;
    int IDP;
    char Aux1[50];

    printf("Ingrese el ID de la persona para listar sus productos: ");
    fflush(stdin);
    gets(Aux);
    if(esNumerico(Aux) == -1)
    {
        printf("Este campo solo admite numeros enteros\n");
        return -1;
    }
    IDU = atoi(Aux);
    i = buscarPorIDU(usuarios,tamU,IDU);
    if(i == -1)
    {
        return -1;
    }
    else
    {
        printf("ID--NOMBRE PRODUCTO--PRECIO--CANTIDAD VENDIDA--STOCK--NOMBRE USUARIO\n");
        for(j=0;j<tamP;j++)
        {
            if(productos[j].idUsuario == IDU && productos[j].estadoProducto == 1)
            {
                flag=1;
                printf("%d--%s--%.2f--%d--%d\n",productos[j].idProducto,productos[j].nombreProducto,productos[j].precio,productos[j].vendidos,productos[j].stock);
            }
        }
        if(flag==0)
        {
            system("cls");
            printf("No hay publicaciones activas\n");
            return -1;
        }
        printf("Ingrese el ID de la publicacion que desea modificar: ");
        fflush(stdin);
        gets(Aux1);
        if(esNumerico(Aux1) == -1)
        {
            printf("Este campo solo admite numeros enteros\n");
            return -1;
        }
        IDP = atoi(Aux1);
        q = buscarPorIDP(productos,tamP,IDP);
        if(q == -1)
        {
            return -1;
        }
        else
        {
            printf("\nID: %d\n",productos[q].idProducto);
            printf("NOMBRE: %s\n",productos[q].nombreProducto);
            printf("PRECIO: %.2f\n",productos[q].precio);
            printf("VENDIDOS: %d\n",productos[q].vendidos);
            printf("STOCK: %d\n",productos[q].stock);
            getSN(&respuesta,"\nEsta seguro que desea dar de baja esta publicacion? s/n","\nError. Opcion no valida");
            if(respuesta == 's')
            {
                productos[q].estadoProducto = 0;
                return 0;
            }
            return -1;
        }
        return -1;
    }
    return -1;
}

int ComprarProducto(eUsuario usuarios[], int tamU, eProducto productos[],int tamP)
{
        char Aux[50];
        char Aux1[50];
        char Aux2[50];
        char aux3[50];
        int flag = 0;
        int i;
        int j;
        int IDP;
        char respuesta;
        int cantidad;
        float nota;

        printf("\t\tPRODUCTOS\n");
        printf("ID--NOMBRE PRODUCTO--PRECIO--CANTIDAD VENDIDA--STOCK--NOMBRE USUARIO\n");
        for(i=0;i<tamP;i++)
        {
            if(productos[i].estadoProducto == 1)
            {
                for(j=0;j<tamU;j++ )
                {
                    if(productos[i].idUsuario == usuarios[j].idUsuario)
                    {
                        strcpy(aux3,usuarios[j].nombreUsuario);
                    }
                }
                printf("%d--%s--%.2f--%d--%d--%s\n",productos[i].idProducto,productos[i].nombreProducto,productos[i].precio,productos[i].vendidos,productos[i].stock,aux3);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            system("cls");
            printf("No hay publicaciones activas\n");
            return -1;
        }

        printf("Ingrese el ID del producto que desea comprar: ");
        fflush(stdin);
        gets(Aux);
        if(esNumerico(Aux) == -1)
        {
            printf("Este campo solo admite numeros enteros\n");
            return -1;
        }
        IDP = atoi(Aux);
        i = buscarPorIDP(productos,tamP,IDP);
        if(i == -1)
        {
            return -1;
        }
        else
        {
                    printf("\nID: %d\n",productos[i].idProducto);
                    printf("NOMBRE: %s\n",productos[i].nombreProducto);
                    printf("PRECIO: %.2f\n",productos[i].precio);
                    printf("VENDIDOS: %d\n",productos[i].vendidos);
                    printf("STOCK: %d\n",productos[i].stock);
                    printf("Cuantas unidades desea comprar?: ");
                    fflush(stdin);
                    gets(Aux1);
                    if(esNumerico(Aux1) == -1)
                    {
                        printf("\nEste campo solo admite numeros enteros\n");
                        return -1;
                    }
                    cantidad = atoi(Aux1);
                    if(cantidad < 1)
                    {
                        printf("ingreso una cantidad menor a una unidad\n");
                        return -1;
                    }
                    if(productos[i].stock < cantidad)
                    {
                        printf("No puede realizar la compra porque la cantidad que desea comprar supera el stock de este producto\n");
                        return -1;
                    }
                    getSN(&respuesta,"\nEsta seguro que desea comprar este producto? s/n","\nError. Opcion no valida");
                    if(respuesta == 's' && productos[i].stock > 0)
                    {
                            productos[i].stock = productos[i].stock - cantidad;
                            productos[i].vendidos = productos[i].vendidos + cantidad;
                            printf("\nIngrese una nota entre 1-10 para el comprador: ");
                            fflush(stdin);
                            gets(Aux2);
                            if(esNumerico(Aux2) == -1)
                            {
                                 printf("\nEste campo solo admite numeros\n");
                                 return -1;
                            }
                            nota = atof(Aux2);
                            for(j=0;j<tamU;j++)
                            {
                                if(usuarios[j].idUsuario == productos[i].idUsuario)
                                {
                                    usuarios[j].nota = usuarios[j].nota + nota;
                                    usuarios[j].ventas = usuarios[j].ventas + 1;
                                }
                            }
                            return 0;
                    }
                    return -1;
        }
}

void ListarPublicaciones(eUsuario usuarios[], int tamU, eProducto productos[], int tamP)
{
    int i;
    int j;
    char aux[50];
    int flag=0;

    printf("ID--NOMBRE PRODUCTO--PRECIO--CANTIDAD VENDIDA--STOCK--NOMBRE USUARIO\n");
    for(i=0;i<tamP;i++)
    {
        if(productos[i].estadoProducto == 1)
        {
            for(j=0;j<tamU;j++ )
            {
                if(productos[i].idUsuario == usuarios[j].idUsuario)
                {
                    strcpy(aux,usuarios[j].nombreUsuario);
                }
            }
            printf("%d--%s--%.2f--%d--%d--%s\n",productos[i].idProducto,productos[i].nombreProducto,productos[i].precio,productos[i].vendidos,productos[i].stock,aux);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        system("cls");
        printf("No hay publicaciones activas\n");
    }
}

void ListarPublicacionesUsuarios(eUsuario usuarios[], int tamU, eProducto productos[], int tamP)
{
    int i;
    int j;
    int IDU;
    char Aux[50];
    int flag=0;

    printf("Ingrese el ID de la persona para listar sus productos: ");
    fflush(stdin);
    gets(Aux);
    if(esNumerico(Aux) == -1)
    {
        printf("Este campo solo admite numeros\n");
    }
    IDU = atoi(Aux);
    i = buscarPorIDU(usuarios,tamU,IDU);
    if(i == -1)
    {
       printf("Usuario no encontrado\n");
    }
    else
    {
        system("cls");
        printf("\t\tPoductos de %s\n",usuarios[i].nombreUsuario);
        printf("ID--NOMBRE PRODUCTO--PRECIO--CANTIDAD VENDIDA--STOCK\n");
        for(j=0;j<tamP;j++)
        {
            if(productos[j].estadoProducto == 1 && productos[j].idUsuario == IDU)
            {
                printf("%d--%s--%.2f--%d--%d\n",productos[j].idProducto,productos[j].nombreProducto,productos[j].precio,productos[j].vendidos,productos[j].stock);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            system("cls");
            printf("No hay publicaciones activas\n");
        }
    }
}

void ListarUsuarios(eUsuario usuarios[], int tamU)
{
    int i;
    int flag=0;

    printf("NOMBRE DE USUARIO--PUNTAJE PROMEDIO\n");
    for(i=0;i<tamU;i++)
    {
        if(usuarios[i].estadoUsuario == 1 && usuarios[i].ventas > 0)
        {
            usuarios[i].puntaje = usuarios[i].nota / usuarios[i].ventas;
            printf("%s--%.2f\n",usuarios[i].nombreUsuario,usuarios[i].puntaje);
            flag = 1;
        }
    }
    if(flag==0)
    {
        system("cls");
        printf("No hay usuarios activos\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//HARDCODEO DE DATOS

void HardcodeoUsuarios(eUsuario usuarios[])
{
    int idU[]={1,2,3,4};
    char nombre[][50]={"Nicolas","Agustin","Juan","Jose"};
    char pass[][20]={"123456","123456","123456","123456"};
    int estado[]={1,1,1,1};
    float nota[]={5,6,7,10};
    int ventas[]={1,1,1,1};
    int i;

    for(i=0; i<4; i++)
    {
        usuarios[i].idUsuario=idU[i];
        usuarios[i].estadoUsuario=estado[i];
        usuarios[i].nota=nota[i];
        usuarios[i].ventas=ventas[i];
        strcpy(usuarios[i].nombreUsuario, nombre[i]);
        strcpy(usuarios[i].passUsuario, pass[i]);
    }
}

void HardcodeoProductos(eProducto productos[])
{
    int idP[]={1,2,3,4};
    char nombre[][50]={"CPU","RAM","HDD","MOTHER"};
    int idU[]={1,2,3,4};
    int estado[]={1,1,1,1};
    int stock[]={34,76,45,12};
    int vendidos[]={98,56,45,23};
    float precio[]={45.56,34.87,12.78,90.56};
    int i;

    for(i=0; i<4; i++)
    {
        productos[i].idProducto=idP[i];
        productos[i].idUsuario=idU[i];
        productos[i].estadoProducto=estado[i];
        productos[i].stock=stock[i];
        productos[i].vendidos=vendidos[i];
        productos[i].precio=precio[i];
        strcpy(productos[i].nombreProducto, nombre[i]);
    }
}






