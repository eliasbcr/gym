#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funccopianuevo.h"

/*void MenuInicio(){
    int opcion=0;
    do{
    printf("-------------------------------------------Inicio-------------------------------------------\n");
    printf("1)Iniciar sesion \n");
    printf("2)Crear usuario \n");
    printf("3)Salir de aplicacion \n");
    printf("\n");
    printf("Ingrese una opcion:_");
    scanf("%d",&opcion);
    }while(opcion!=3);

}*/
/*void Crear_Usuario(){
       int opcion=0;
       int bandera_usu=0,bandera_ctra=0,bandera_NOYAP=0;
   do{
    printf("-------------------------------------------Crear Usuario-------------------------------------------\n");
    printf("1)CREAR USUARIO\n");
    printf("2)CREAR CONTRASENA \n");
    printf("3)Ingresar Nombre y apellido");
    printf("4)RETORNAR\n");
    printf("\n");
    printf("Ingrese una opcion:_");
    scanf("%d",&opcion);
    //Selector_Crear_Usuario(opcion,bandera_usu,bandera_usu,bandera_NOYAP);
    if(bandera_NOYAP==5){
        opcion=5;
    }
   }while(opcion!=5);

}*/
/*void Selector_Crear_Usuario(int x,int z,int y,int&bandera_NOYAP){

    switch (x)
    {
    case 1:
        Crear_NombreUsuario();
        z=1;
        break;
    case 2:
        Crear_Contrasena();
        y=1;
        break;
    case 3:
        if(z==1 && y==1){
        Ingreso_NOYAP();
        bandera_NOYAP=1;
        }else{
            printf("Debe haber ingresado el usuario y la contraseña");
        }
        break;
    case 4:
        if(z==1 && y==1 && bandera_NOYAP==1){
            //Retornar();
            bandera_NOYAP=5;// utilizo esto para verificar que todas los campos hayan sido completados
        }else{
            printf("Falta completar datos...");
            bandera_NOYAP=1;
        }
        break;
    
    default:
        break;
    }

}*/
/*void Ini_Sesion(){
   int opcion=0;
   do{
    printf("-------------------------------------------Iniciar Sesion-------------------------------------------\n");
    printf("1)USUARIO\n");
    printf("2)CONTRASENA \n");
    printf("3)INGRESAR\n");
    printf("4)RETORNAR\n");
    printf("\n");
    printf("Ingrese una opcion:_");
    scanf("%d",&opcion);
    Selector_Ini_Sesion(opcion);
   }while(opcion!=4);
}
void Selector_Ini_Sesion(int x){

    switch (x)
    {
    case 1:
        //Ingresar_Usuario();
        break;
    case 2:
        //Ingresar_Contrasena();
        break;
    case 3:
        //INGRESAR();
        //todo listo, o no todo listo, necesita una bandera para saber si se ingreso correctamente la contra o el usuario
        break;
    case 4:
        //Retornar();
        break;
    default:
        break;
    }

}*/
void Selector_Menu_Principal(int x);
void Menu_Principal();
void Modulo_Gym();
void Modulo_Recepcion();
void Modulo_Administracion();
void Selector_RECEPCION(int x,int&Ingreso_Exitoso,int&USUARIO_INGRESO);
void Selector_ADMIN(int x,int&Ingreso_Exitoso,int&USUARIO_INGRESO);
void Selector_GYM(int x,int&Ingreso_Exitoso,int&USUARIO_INGRESO);


void Menu_Principal(){
    int opcion;
    do
    {
    system("cls");
    printf("-------------------------------------------Menu Principal-------------------------------------------\n");
    printf("1)Modulo Gym\n");
    printf("2)Modulo Recepcion \n");
    printf("3)Modulo Administracion\n");
    printf("4)Salir\n");
    printf("\n");
    printf("Ingrese una opcion:_");
    scanf("%d",&opcion);
    Selector_Menu_Principal(opcion);
    } while (opcion!=4);
    
}
void Selector_Menu_Principal(int x){

    switch (x)
    {
    case 1:
        Modulo_Gym();
        break;
    case 2:
        Modulo_Recepcion();
        break;
    case 3:
        Modulo_Administracion();
        break;
    default:
        break;
    }

}
void Modulo_Gym(){
    //DIRIGIDO A ENTRENADORES
   int opcion;
    int Ingreso_Exitoso=0;
    int USUARIO_INGRESO=0;

    do
    {
    system("cls");
        printf("-----------Modulo GYM-----------\n");
        printf("1-Iniciar Sesion\n");
        printf("2-Visualizar listado de Socios de gimnasia\n");
        printf("3-Registrar rutinas de gimnasia\n");
        printf("4-Cerrar la aplicacion\n");
        printf("\n");
        printf("\n");
        printf("Ingrese una opcion:_ ");
        scanf("%d", &opcion);
        Selector_GYM(opcion,Ingreso_Exitoso,USUARIO_INGRESO);
    } while (opcion != 4);
    
}

void Selector_GYM(int x,int&Ingreso_Exitoso,int&USUARIO_INGRESO){

switch (x)
{
case 1:
        Ini_Sesion(Ingreso_Exitoso);
        if(Ingreso_Exitoso==1){
            USUARIO_INGRESO=1;
        }
    break;
case 2:
    if(USUARIO_INGRESO==1){
        Listar_Socios();
        getch();
        }else{
            system("cls");
            printf("[ERROR]--->No se ha iniciado sesion...");
            getch();
        }
    //Se lista los socios tal como en le siguiente ejemplo:
    //NOMBRE DE SOCIO:  anónimo
    //EDAD: DD MM NN
    //DNI:  123456789
    //ACTIVIDAD:  GYM, ZUMBA,SPINNING.
    break;
case 3:
    if(USUARIO_INGRESO==1){
        Registrar_Rutinas();
        }else{
            system("cls");
            printf("[ERROR]--->No se ha iniciado sesion...");
            getch();
        }
    //TEXTO DE NO MAS DE 380 PALABRAS(se me hace que es lo mismo que en le caso 3- de ModuloRecepcion)
    break;
case 4:
        if(USUARIO_INGRESO==1){
        system("cls");
        printf("\tSe ha cerrado sesion.....");
        getch();
        Ingreso_Exitoso=0;
        USUARIO_INGRESO=0;
        }
        break;

default:
    break;
}

}
void Modulo_Recepcion(){

    //DIRIGIDA A PERSONAL DE ATENCION AL PUBLICO
    // REGISTRA A SOCIOS EN BASE DE DATOS
    // CADA SOCIO TIENE UN NRO DE IDENTIFICACION
    int opcion,Ingreso_Exitoso=0;
    int USUARIO_INGRESO=0;

    do
    {
    system("cls");
        printf("-----------Modulo Recepcion-----------\n");
        printf("1-Iniciar Sesion\n");
        printf("2-Registrar socios\n");
        printf("3-Registrar Actividades de Socios\n");
        printf("4-Listado de Socios\n");
        printf("5-Listado de fechas de pagos[INHABILITADO]\n");
        printf("6-Cerrar la aplicacion\n");
        printf("\n");
        printf("\n");
        printf("Ingrese una opcion:_ ");
        scanf("%d", &opcion);
        Selector_RECEPCION(opcion,Ingreso_Exitoso,USUARIO_INGRESO);
    } while (opcion != 6);

}

void Selector_RECEPCION(int x,int&Ingreso_Exitoso,int&USUARIO_INGRESO){

    switch (x)
    {
    case 1:
        Ini_Sesion(Ingreso_Exitoso);
        if(Ingreso_Exitoso==1){
            USUARIO_INGRESO=1;
        }
        break;
    case 2:
        if(USUARIO_INGRESO==1){
        Registrar_Socios();
        }else{
            system("cls");
            printf("[ERROR]--->No se ha iniciado sesion...");
            getch();
        }
        //Se le pedira todo tipo de datos al socio. altura, peso, domicilio. Y a el mismo se le dara un nro de identificiacion(NRO_IDE).
        //el socio no inicia sesion, solo los entrenadores y los empleados
        break;
    case 3:
        if(USUARIO_INGRESO==1){
        Registrar_Actividades();
        }else{
            system("cls");
            printf("[ERROR]--->No se ha iniciado sesion...");
            getch();
        }
        //Registro de actividad. Una vez registrado el socio, este podrá inscribirse en distintas actividades
        //pudiendo elegir el horario y entrenador.
        break;
    case 4:
        if(USUARIO_INGRESO==1){
        Listar_Socios();
        }else{
            system("cls");
            printf("[ERROR]--->No se ha iniciado sesion...");
            getch();
        }
        //Se lista los socios tal como en le siguiente ejemplo:
        //listado de participantes, de una actividad determinada, por horario y entrenador.
        //NOMBRE DE SOCIO:  anónimo
        //EDAD: DD MM NN
        //DNI:  123456789
        //ACTIVIDAD:  GYM, ZUMBA,SPINNING.
        //ENTRENADOR: ********* ****** ********
        break;
    case 5:
        /*if(USUARIO_INGRESO==1){
        Listado_Pago();
        }else{
            system("cls");
            printf("[ERROR]--->No se ha iniciado sesion...");
            getch();
        }*/
        // el listado de pagos, a mi parecer es el vencimiento del pago y si está en regla o no el pago. FECHA DE INGRESO
        break; 
    case 6:
        if(USUARIO_INGRESO==1){
        system("cls");
        printf("\tSe ha cerrado sesion.....");
        getch();
        Ingreso_Exitoso=0;
        USUARIO_INGRESO=0;
        }
        break;    
    default:
        break;
    }

}

void Modulo_Administracion(){

    //AQUI SE REGISTRA EL USUARIO A UTILIZAR LA PLATAFORMA(ADMIN O PERSONAL DE ATENCION)
    //REGISTRAR ACTIVIDADES(NO PUEDE HABER 2 ACTV EN EL MISMO HORARIO)
    // CADA ENTRENADOR SE REGISTRA CON UN LEGAJO
    //--> HAY QUE RECORDAR QUE EL ENTRENADOR TIENE QUE TENER UNA MANERA DE SER REGISTRADO 
    //    Y SER BUSCADO PARA SABER SUS HORAS TRABAJADAS Y SU PAGO
    int opcion;
    int Ingreso_Exitoso=0;
    int USUARIO_INGRESO=0;
    do
    {
    system("cls");
        printf("-----------Modulo Administracion-----------\n");
        printf("1-Iniciar Sesion\n");
        printf("2-Registrar usuario de recepcion\n");
        printf("3-Registrar Actividades del GYM\n");
        printf("4-Registrar Entrenador\n");
        printf("5-Calcular pago de entrenador[INHABILITADO]\n");
        printf("6-Entrenador con mayor carga horaria[INHABILITADO]\n");
        printf("7-Cerrar la aplicacion\n");
        printf("\n");
        printf("\n");
        printf("Ingrese una opcion:_ ");
        scanf("%d", &opcion);
        Selector_ADMIN(opcion,Ingreso_Exitoso,USUARIO_INGRESO);
    } while (opcion != 7);

}
void Selector_ADMIN(int x,int&Ingreso_Exitoso,int&USUARIO_INGRESO){

    switch (x)
    {
    case 1:
        Ini_Sesion(Ingreso_Exitoso);
        if(Ingreso_Exitoso==1){
            USUARIO_INGRESO=1;
        }
        break;
    case 2:
        Crear_Usuario();
        break;
    case 3:
        if(USUARIO_INGRESO==1){
        Registrar_Actividades();
        }else{
            system("cls");
            printf("[ERROR]--->No se ha iniciado sesion...");
            getch();
        }
        // lo que vamos a hacer es registrar un vector con actividades, y este mismo va a ser modificado
        break;
    case 4:        
    if(USUARIO_INGRESO==1){
        Registrar_Entrenador();
        }else{
            system("cls");
            printf("[ERROR]--->No se ha iniciado sesion...");
            getch();

        }
        //se registra al entrenador, pidiendole el nombre de usuario,contraseña, y se le da un nro de lejado de forma aleatoria con rand().
        break;
    case 5:
        //Calc_pago_entrenador();
        //se realiza la apertura del archivo entrenadores.dat, se ingresa muestran todos los entrenadores con su usuario y lejado a la par
        //   se pregunta el nro de legajo al que quiere acceder, se busca el legajo y se le da al usuario que solicitó un conteo de horas que tiene multiplicada
        //         por el costo
        break;
    case 6:
        //Hras_entrenador();
        // se realiza la busqueda en el archivo de la cantidad de horas y se comparan hasta encontrar el entrenador con mayor carga horaria.
        break;
    case 7:
        if(USUARIO_INGRESO==1){
        system("cls");
        printf("\tSe ha cerrado sesion.....");
        getch();
        Ingreso_Exitoso=0;
        USUARIO_INGRESO=0;
        }
        break;
    default:
        break;
    }
}


int main(){
    Menu_Principal();
}
