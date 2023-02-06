#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;

// ARCHIVOS DONDE SE VAN A GUARDAR
// Usuarios.dat
// Entrenadores.dat
// Socios.dat
// Turnos.dat

// Estructuras necesarias
//       ENTRENADORES
//-----/ Es decir que cada SOCIOS se le asocia al legajo del entrenador
//-----/ y si tiene más SOCIOS asociados, cobrará más.

struct Entrenador
{
    char Apellido_Nombre_ENTRE[60], Contrasena[10];
    int LEGAJO;
    int horas = 0;
    int horastotales = 0;
    int CantSocios = 0;
};

//      SOCIOS

struct fecha
{
    int dia, mes, anio;
};
struct Socio
{
    char Apellido_Nombre[60];
    int DNI, NroSocio;
    int Edad, Peso, Altura;
    char IndicacionesMedicas[100];
    char Domicilio[30];
    int Telefono;
    fecha ingreso;
    char RUTINA[380];
    char Nombre_Rutina[60];
    char Actividad[100];
};

//      FECHA

//      USUARIO

struct Usuario
{
    char UsuarioUSU[10], Contrasena[10], Apellido_NombreUSU[60];
};

//      ACTIVIDADES

struct actividades
{
    char actividad[40];
    int hora;
};

//      TURNOS

struct Turnos
{
    int LEGAJO;
    fecha fecha;
    int NroSocio;
};

int Crear_Usuario()
{
    system("cls");
    struct Usuario usu;
    FILE *arch;
    arch = fopen("Usuarios.dat", "a+b");
    if (arch == NULL)
    {
        printf("error");
        getch();
        exit(1);
    }
    int Usuario_Creado = 0;
    int usuRept = 0;
    printf("        **Requerimientos para NOMBRE DE USUARIO**\n");
    printf("        >>SER UNICO\n");
    printf("        >>COMENZAR CON MINUSCULA\n");
    printf("        >>TENER MINIMO 2 MAYUSCULAS\n");
    printf("        >>TENER COMO MAXIMO 3 DIGITOS\n");

    do
    {
        char Usuario_Ingreso[10];
        int Longitud = 0;
        int mayusculas = 0, digitos = 0;
        printf("\tUsuario: ");
        _flushall();
        gets(Usuario_Ingreso);
        fread(&usu, sizeof(Usuario), 1, arch);
        while (!feof(arch))
        {
            if (strcmp(Usuario_Ingreso, usu.UsuarioUSU) == 0)
            {
                usuRept = 1;
                strcpy(Usuario_Ingreso,"nnnnnnnnn");
            }
            fread(&usu, sizeof(Usuario), 1, arch);
        }
        if (usuRept == 1)
        {
            printf("El usuario se encuentra repetido, por favor ingrese de nuev.\n");
            getch();
            usuRept=0;
            
        }

 
        Longitud = strlen(Usuario_Ingreso);
    if(strcmp(Usuario_Ingreso,"nnnnnnnnn")!=0){

        if (Longitud < 6)
        {
            printf("Nombre de usuario demasiado corto, ingresar de nuevo...\n");
        }
        if (Longitud > 10)
        {
            printf("Nombre de usuario demasiado extenso, ingresar de nuevo...\n");
        }
        

        if (Longitud > 5 && Longitud < 11)
        {
            // printf("longitud adecuada\n");
            if (Usuario_Ingreso[0] >= 'a' && Usuario_Ingreso[0] <= 'z')
            {
                // printf("comienza bien\n");
                for (int i = 0; i < Longitud; i++)
                {
                    if (Usuario_Ingreso[i] >= 'A' && Usuario_Ingreso[i] <= 'Z')
                    {
                        mayusculas++;
                    }
                }
                if (mayusculas >= 2)
                {
                    // printf("posee al menos 2 mayusculas\n");

                    for (int i = 0; i < Longitud; i++)
                    {
                        if (Usuario_Ingreso[i] == '1' || Usuario_Ingreso[i] == '2' || Usuario_Ingreso[i] == '3' || Usuario_Ingreso[i] == '4' || Usuario_Ingreso[i] == '5' || Usuario_Ingreso[i] == '6' || Usuario_Ingreso[i] == '7' || Usuario_Ingreso[i] == '8' || Usuario_Ingreso[i] == '9' || Usuario_Ingreso[i] == '0')
                        {
                            digitos++;
                        }
                    }
                    if (digitos <= 3 && usuRept==0)
                    {
                        printf("\t-SU NOMBRE DE USUARIO ES: %s\n", Usuario_Ingreso);
                        Usuario_Creado = 1;
                        strcpy(usu.UsuarioUSU, Usuario_Ingreso);
                        _flushall();
                        getch();
                    }
                    else
                    {
                        printf("Debe poseer menos o igual a 3 digitos\n");
                    }
                }
                else
                {
                    printf("No posee 2 mayusculas\n");
                }
            }
            else
            {
                printf("El Nombre de Usuario debe comenzar con una Minuscula\n");
            }
        }
    }
    } while (Usuario_Creado != 1);

    // CONTRASEÑA

    int ContraCorrecta = 0;
    printf("----------------------------------------------------------------------------\n");
    printf("        **Requerimientos para crear una CONTRASEÑA\n");
    printf("        >>CONTENER COMO MINIMO: 1(MAYUSCULA,MINUSCULA,NUMERO)\n");
    printf("        >>LONGITUD: 6 A 32\n");
    printf("        >>NO CONTENER 3 NUMEROS SEGUIDOS\n");
    printf("        >>NO POSEER LETRAS ORDENADAS ALFABETICAMENTE: EJEMPLO[opq,abc]\n");

    do
    {
        char contra_REP[32];
        char contra[32], invalida = 0;
        int i, upper = 0, lower = 0, num = 0, consec_num = 0, consec_alpha = 0, flag = 0;

        printf("Ingrese la contrasena: ");
        _flushall();
        gets(contra);

        if (strlen(contra) < 6 || strlen(contra) > 32)
        {
            printf("La cadena debe tener entre 6 y 32 caracteres.\n");
            invalida = 1;
        }

        for (i = 0; i < strlen(contra); i++)
        {
            if (!((contra[i] >= 'a' && contra[i] <= 'z') || (contra[i] >= 'A' && contra[i] <= 'Z') || (contra[i] >= '0' && contra[i] <= '9')))
            {
                printf("La cadena solo debe contener caracteres alfanuméricos.\n");
                invalida = 1;
            }
            if (contra[i] >= 'A' && contra[i] <= 'Z')
            {
                upper = 1;
            }
            if (contra[i] >= 'a' && contra[i] <= 'z')
            {
                lower = 1;
            }
            if (contra[i] >= '0' && contra[i] <= '9')
            {
                num = 1;
                consec_num++;
                if (consec_num >= 3)
                {
                    printf("La cadena no debe tener más de 3 caracteres numéricos consecutivos.\n");
                    invalida = 1;
                    flag=1;
                }
            }
            else
            {
                consec_num = 0;
            }

            if (((contra[i] >= 'a' && contra[i] <= 'z') || (contra[i] >= 'A' && contra[i] <= 'Z')) && contra[i] == contra[i + 1] - 1)
            {
                consec_alpha++;
                if (consec_alpha >= 2)
                {
                    printf("La cadena no debe tener más de 2 caracteres consecutivos alfabéticamente consecutivos\n");
                    invalida = 1;
                    flag=1;
                }
            }
            else
            {
                consec_alpha = 0;
            }
        }

        if (!upper)
        {
            printf("La cadena debe contener al menos una letra mayuscula\n");
            flag = 1;
            invalida=1;
        }
        if (!lower)
        {
            printf("La cadena debe contener al menos una letra minuscula\n");
            flag = 1;
            invalida=1;
        }
        if (!num)
        {
            printf("La cadena debe contener al menos un carácter numérico.\n");
            flag = 1;
            invalida=1;
        }
        if (!flag)
        {
            printf("La cadena cumple con los criterios.\n");
            printf("La contraseña es correcta\n");
            strcpy(usu.Contrasena, contra);
            _flushall();
            ContraCorrecta=1;
            getch();
        }

    } while (ContraCorrecta == 0);

    printf("El Usuario ha sido creado correctamente\n");
    printf("__________________________________________________________\n");
    printf("Porfavor ingrese su Nombre y Apellido\n");
    _flushall();
    gets(usu.Apellido_NombreUSU);
    fwrite(&usu, sizeof(Usuario), 1, arch);
    getch();
    fclose(arch);
    return 0;
    
}
void Registrar_Actividades()
{
    system("cls");
    char ingreso[40];
    int repetida = 0;
    struct actividades ac;
    srand(time(NULL));
    FILE *arch;
    arch = fopen("Usuarios.dat", "a+b");
    if (arch == NULL)
    {
        printf("error");
        getch();
        exit(1);
    }
    printf("Ingrese el nombre de la actividad a registrar: \n");
    _flushall();
    gets(ingreso);
    fread(&ac, sizeof(actividades), 1, arch);
    while (!feof(arch))
    {
        if (strcmp(ac.actividad, ingreso) == 0)
        {
            repetida = 1;
        }
        fread(&ac, sizeof(actividades), 1, arch);
    }
    if (repetida == 1)
    {
        printf("La actividad ya se encuentra registrada.\n");
        getch();
        rewind(arch);
        fclose(arch);
        Registrar_Actividades();
    }
    printf("Ingrese el horario de la actividad: [Ejemplo: 2030,1920,1500]\n");
    scanf("%d", &ac.hora);
    fwrite(&ac, sizeof(actividades), 1, arch);
    rewind(arch);
    fclose(arch);
    system("pause");
}
void Registrar_Entrenador()
{
    system("cls");
    struct Entrenador ent;
    FILE *arch;
    arch = fopen("Entrenadores.dat", "a+b");
    int x = 1;
    if (arch == NULL)
    {
        printf("error");
        getch();
        exit(1);
    }
    printf("///////Recuerde que la contraseña debe cumplir los siguientes parametros\n/////");
    printf("Deberá contener al menos una letra mayúscula, una letra minúscula y un número.\n");
    printf("No podrá contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanuméricos.\n");
    printf("Deberá tener entre 6 y 32 caracteres.\n");
    printf("No debe tener más de 3 caracteres numéricos consecutivos.\n");
    printf("No debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas\n");
    printf("(ascendentemente). Este criterio es válido tanto para letras mayúsculas, minúsculas o\n");
    printf("combinación de ambas.\n");
    do
    {
        printf("Ingrese el nombre del entrenador: \n");
        _flushall();
        gets(ent.Apellido_Nombre_ENTRE);

        int ContraCorrecta = 0;
        do
        {
            system("cls");
            char contra_REP[32];
            char contra[32], invalida = 0;
            int i, upper = 0, lower = 0, num = 0, consec_num = 0, consec_alpha = 0, flag = 0;

            printf("Ingrese la contrasena: ");
            gets(contra);

            if (strlen(contra) < 6 || strlen(contra) > 32)
            {
                printf("La cadena debe tener entre 6 y 32 caracteres.\n");
                invalida = 1;
            }

            for (i = 0; i < strlen(contra); i++)
            {
                if (!((contra[i] >= 'a' && contra[i] <= 'z') || (contra[i] >= 'A' && contra[i] <= 'Z') || (contra[i] >= '0' && contra[i] <= '9')))
                {
                    printf("La cadena solo debe contener caracteres alfanuméricos.\n");
                    invalida = 1;
                }
                if (contra[i] >= 'A' && contra[i] <= 'Z')
                {
                    upper = 1;
                }
                if (contra[i] >= 'a' && contra[i] <= 'z')
                {
                    lower = 1;
                }
                if (contra[i] >= '0' && contra[i] <= '9')
                {
                    num = 1;
                    consec_num++;
                    if (consec_num >= 3)
                    {
                        printf("La cadena no debe tener más de 3 caracteres numéricos consecutivos.\n");
                        invalida = 1;
                    }
                }
                else
                {
                    consec_num = 0;
                }

                if (((contra[i] >= 'a' && contra[i] <= 'z') || (contra[i] >= 'A' && contra[i] <= 'Z')) && contra[i] == contra[i + 1] - 1)
                {
                    consec_alpha++;
                    if (consec_alpha >= 2)
                    {
                        printf("La cadena no debe tener más de 2 caracteres consecutivos alfabéticamente consecutivos\n");
                        invalida = 1;
                    }
                }
                else
                {
                    consec_alpha = 0;
                }
            }

            if (!upper)
            {
                printf("\n");
                flag = 1;
            }
            if (!lower)
            {
                printf("La cadena debe contener al menos una letra mayúscula\n");
                flag = 1;
                invalida=1;
            }
            if (!num)
            {
                printf("La cadena debe contener al menos un carácter numérico.\n");
                flag = 1;
                invalida=1;
            }
            if (!flag)
            {
                printf("La cadena cumple con los criterios.\n");
                printf("La contraseña es correcta\n");
                strcpy(ent.Contrasena, contra_REP);
                ContraCorrecta=1;
                getch();
            }

        } while (ContraCorrecta == 0);

        ent.LEGAJO = 1 + rand() % (10000 - 1000);

        printf("el numero de legajo con el que se encontrara su entrenador es: %d", ent.LEGAJO);

        fwrite(&ent, sizeof(Entrenador), 1, arch);
        rewind(arch);
        fclose(arch);
        int cont = 0;
        printf("Si desea seguir ingresando ingrese 1, en caso contrario, 0");
        scanf("%d", &cont);
        if (cont == 1)
        {
            x = 0;
        }
    } while (x == 0);
}
void Ini_Sesion(int &Ingreso_Exitoso)
{
    int local_info = 0;
    system("cls");
    char contra[10];
    char nombre[10];
    struct Usuario usu;
    FILE *arch;
    arch = fopen("Usuarios.dat", "r+b");
    if (arch == NULL)
    {
        printf("error");
        getch();
        exit(1);
    }
    printf("Ingrese el nombre de usuario:: ");
    _flushall();
    gets(nombre);
    fread(&usu, sizeof(Usuario), 1, arch);
    while (!feof(arch))
    {
        if (strcmp(nombre, usu.UsuarioUSU) == 0)
        {
            printf("Ingrese la contrasena: ");
            _flushall();
            gets(contra);
            if (strcmp(contra, usu.Contrasena) == 0)
            {

                Ingreso_Exitoso = 1;
            }
            else
            {
                printf("\nContrasena Incorrecta\n");
                Ingreso_Exitoso = 0;
                local_info = 1;
            }
        }
        fread(&usu, sizeof(Usuario), 1, arch);
    }
    if (Ingreso_Exitoso == 0 && local_info == 1)
    {
        int z = 0;
        printf("No se ha podido ingresar a la cuenta, intente de nuevo\n");
        printf("        Intentar de nuevo [1] || Salir [0]\n");
        scanf("%d", &z);
        getch();
        if (z == 1)
        {
            Ini_Sesion(Ingreso_Exitoso);
        }
    }
    rewind(arch);
    fclose(arch);
}
void Registrar_Socios()
{
    system("cls");
    int nro_random = 0;
    int control_horario[20], contador = 0, okay = 0;
    char ingreso[100];
    struct Socio soc;
    struct actividades ac;

    FILE *archSocio;
    archSocio = fopen("Socios.dat", "ab");
    if (archSocio == NULL)
    {
        printf("error 2");
        getch();
        exit(1);
    }
    printf("____________________________________________________\n");
    _flushall();
    printf("Apellido y Nombre de socio: ");
    gets(soc.Apellido_Nombre);
    printf("Edad: ");
    scanf("%d", &soc.Edad);
    printf("Peso: ");
    scanf("%d", &soc.Peso);
    printf("Altura: ");
    scanf("%d", &soc.Altura);
    _flushall();
    printf("Domicilio: ");
    gets(soc.Domicilio);
    printf("DNI: ");
    scanf("%d", &soc.DNI);
    printf("Ingrese la fecha de ingreso\n");
    printf("Dia: ");
    scanf("%d", &soc.ingreso.dia);
    printf("Mes: ");
    scanf("%d", &soc.ingreso.mes);
    printf("Anio: ");
    scanf("%d", &soc.ingreso.anio);
    printf("\nIngrese el telefono: ");
    scanf("%d", &soc.Telefono);
    _flushall();
    printf("Ingrese la rutina: ");
    gets(soc.RUTINA);

    printf("las actividades disponibles hasta el momento son: ");

    FILE *archUsuario;
    archUsuario = fopen("Usuarios.dat", "a+b");
    if (archUsuario == NULL)
    {
        printf("error 1");
        getch();
        exit(1);
    }
    fread(&ac, sizeof(actividades), 1, archUsuario);
    while (!feof(archUsuario))
    {
        if (ac.hora != 0)
        {
            printf("Actividad: %s\n", ac.actividad);
            printf("Horario: %d\n", ac.hora);
            printf("_____________________________________________\n");
        }
        fread(&ac, sizeof(actividades), 1, archUsuario);
    }

    rewind(archUsuario);
    fclose(archUsuario);
    // int coincidencias=0;
    // do{
    printf("\nEscriba el nombre de la cual desee, separado por una coma: ");
    _flushall();
    gets(ac.actividad);

    // fread(&ac,sizeof(actividades),1,arch2);
    /*while(!feof(arch2)){

        if(strstr(ingreso,ac.actividad)){

            control_horario[contador]=ac.hora;
            contador++;
        }
        fread(&ac,sizeof(actividades),1,arch2);
    }
    int comparador=0,coincidencias=0;
    for(int i=1;i<contador;i++){

        comparador=control_horario[i];
        if(comparador==control_horario[i+1]){
            coincidencias++;
            printf("sss");
        }
    }
    if(coincidencias>=2){
        printf("[ERROR] Hay dos actividades que transcurren en el mismo horario\n");

    }
    if(coincidencias<2){
        strcpy(soc.Actividad,ingreso);
        okay=1;
    }
    }while (okay==1);*/

    int registrado = 0;
    srand(time(NULL));
    nro_random = 1 + rand() % (10000 - 1000);
    /*fread(&soc,sizeof(Socio),1,archSocio);
    while(!feof(archSocio)){

    fread(&soc,sizeof(Socio),1,archSocio);

    }
    rewind(archSocio);*/
    soc.NroSocio = nro_random;
    printf("\n\tSu nro de socio es: %d\n", nro_random);

    fwrite(&soc, sizeof(Socio), 1, archSocio);
    getch();
    fclose(archSocio);
}

void Registrar_Rutinas()
{
    int nro;
    int i = 0;
    struct Socio soc;
    FILE *arch;
    arch = fopen("Socios.dat", "a+b");
    if (arch == NULL)
    {
        printf("error");
        getch();
        exit(1);
    }
    printf("INGRESE EL NRO DE SOCIO AL QUE QUIERE INGRESAR UNA RUTINA: ");
    scanf("%d", &nro);
    fread(&soc, sizeof(Socio), 1, arch);
    while (!feof(arch))
    {
        if (nro == soc.NroSocio)
        {
            printf("Ingrese el nombre de la Rutina: \n");
            _flushall();
            gets(soc.Nombre_Rutina);
            printf("Ingrese la Rutina: \n");
            _flushall();
            gets(soc.RUTINA);
            fwrite(&soc, sizeof(Socio), 1, arch);
            i = 1;
        }
        fread(&soc, sizeof(Socio), 1, arch);
    }
    rewind(arch);
    fclose(arch);

    if (i = 0)
    {
        int x = 0;
        printf("No se ha encontrado el socio...");
        printf("BUSCAR DE NUEVO [0], SALIR [1]");
        scanf("%d", &x);
        if (x == 0)
        {
            Registrar_Rutinas();
        }
    }
    getch();
}

void Hras_entrenador()
{
    int leg, i = 0;
    struct Entrenador ent;
    FILE *arch;
    arch = fopen("Entrenadores.dat", "a+b");
    if (arch == NULL)
    {
        printf("error");
        getch();
        exit(1);
    }
    printf("INGRESE EL LEGAJO DEL ENTRENADOR\n");
    scanf("%d", &leg);
    fread(&ent, sizeof(Entrenador), 1, arch);
    while (!feof(arch))
    {
        if (leg == ent.LEGAJO)
        {
            printf("Ingrese la cantidad de horas que trabaha x dia: \n");
            scanf("%d", &ent.horas);
            ent.horastotales = ent.horas * 30;
            fwrite(&ent, sizeof(Entrenador), 1, arch);
            i = 1;
        }
        fread(&ent, sizeof(Entrenador), 1, arch);
    }
    rewind(arch);
    fclose(arch);
    getch();
}

void Listar_Socios()
{
    struct Socio sc;
    FILE *arch;
    arch = fopen("Socios.dat", "r+b");
    if (arch == NULL)
    {
        printf("error");
        getch();
        exit(1);
    }
    fread(&sc, sizeof(Socio), 1, arch);
    while (!feof(arch))
    {

        printf("Apellido y Nombre: %s\n", sc.Apellido_Nombre);
        printf("DNI: %d\n", sc.DNI);
        printf("nro de socio: %d\n", sc.NroSocio);
        printf("_____________________________________________________________\n");
        fread(&sc, sizeof(Socio), 1, arch);
    }
    getch();
    rewind(arch);
    fclose(arch);
}

// Calc_pago_entrenador();

// Listado_Pago();

// Retornar();
