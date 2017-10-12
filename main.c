#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define USUARIOS 7 // si pongo mas de 7 muestra È en el item 9
#define PRODUCTOS 7


int main()
{
    char salir = 'n';
    int respuesta;
    int opcion;
    int flagU = 0;
    int flagP = 0;

    eUsuario usuarios[USUARIOS];
    inicializarUsuarios(usuarios,USUARIOS,0);

    eProducto productos[PRODUCTOS];
    inicializarProductos(productos,PRODUCTOS,0);

    while(salir == 'n')
    {
        system("cls");
        opcion = menu("1-ALTA DE USUARIO \n2-MODIFICAR DATOS DEL USUARIO \n3-BAJA DEL USUARIO \n4-PUBLICAR PRODUCTO \n5-MODIFICAR PUBLICACION \n6-CANCELAR PUBLICACION \n7-COMPRAR PRODUCTO \n8-LISTAR PUBLICACIONES DE USUARIO \n9-LISTAR PUBLICACIONES \n10-LISTAR USUARIOS \n11-SALIR \nIngrese una opcion: ");
        switch(opcion)
        {
            case 1:
                system("cls");
                if(flagU == 0)
                {
                    HardcodeoUsuarios(usuarios);
                    flagU = 1;
                }
                else
                {
                    respuesta = agregarUsuario(usuarios,USUARIOS);
                    if(respuesta == 0)
                    {
                        printf("Usuario agregado con exito\n");
                    }
                    else
                    {
                        printf("Usuario no agregado\n");
                    }
                }
                system("pause");
                break;
            case 2:
                system("cls");
                respuesta = ModificarUsuario(usuarios,USUARIOS);
                if(respuesta == 0)
                {
                    printf("Usuario modificado con exito\n");
                }
                else
                {
                    printf("\nUsuario no modificado\n");
                }
                system("pause");
                break;
            case 3:
                system("cls");
                respuesta = borrarUsuario(usuarios,USUARIOS,productos,PRODUCTOS);
                if(respuesta == 0)
                {
                    printf("Usuario Borrado con exito\n");
                }
                else
                {
                    printf("Usuario no Borrado\n");
                }
                system("pause");
                break;
            case 4:
                system("cls");
                if(flagP == 0)
                {
                    HardcodeoProductos(productos);
                    flagP = 1;
                }
                else
                {
                    respuesta = agregarProducto(usuarios,USUARIOS,productos,PRODUCTOS);
                    if(respuesta == 0)
                    {
                        printf("Producto agregado con exito\n");
                    }
                    else
                    {
                        printf("Producto no agregado\n");
                    }
                }
                system("pause");
                break;
            case 5:
                system("cls");
                respuesta = ModificarPublicacion(usuarios,USUARIOS,productos,PRODUCTOS);
                if(respuesta == 0)
                {
                    printf("Publicacion modificada con exito\n");
                }
                else
                {
                    printf("\nPublicacion no modificada\n");
                }
                system("pause");
                break;
            case 6:
                system("cls");
                respuesta = CancelarPublicacion(usuarios,USUARIOS,productos,PRODUCTOS);
                if(respuesta == 0)
                {
                    printf("\nPublicacion cancelada con exito\n");
                }
                else
                {
                    printf("\nPublicacion no cancelada\n");
                }
                system("pause");
                break;
            case 7:
                system("cls");
                respuesta = ComprarProducto(usuarios,USUARIOS,productos,PRODUCTOS);
                if(respuesta == 0)
                {
                    printf("\nCompra realizada con exito\n");
                }
                else
                {
                    printf("\nCompra no realizada\n");
                }
                system("pause");
                break;
            case 8:
                system("cls");
                ListarPublicacionesUsuarios(usuarios,USUARIOS,productos,PRODUCTOS);
                system("pause");
                break;
            case 9:
                system("cls");
                ListarPublicaciones(usuarios,USUARIOS,productos,PRODUCTOS);
                system("pause");
                break;
            case 10:
                system("cls");
                ListarUsuarios(usuarios,USUARIOS);
                system("pause");
                break;
            case 11:
                system("cls");
                respuesta = getSN(&salir,"Realmente desea salir? s/n: ","ERROR. Opcion no valida");
                break;
        }
    }
    return 0;
}
