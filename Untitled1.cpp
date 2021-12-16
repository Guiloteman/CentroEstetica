/*La gerencia del centro est�tico es la encargada de realizar la generaci�n (rergistraci�n) de los
nuevos profesionales que trabajan en el establecimiento, as� como tambi�n de los empleados
recepcionistas que realizan la registraci�n de los turnos y clientes.
 Es el �rea encargada de visualizar las atenciones realizadas por los profesionales seg�n el mes
en curso, en este punto se debe obtener un listado u informe que indique por profesional
cuantas atenciones realizo en el mes actual.
 Para incentivar a los Profesionales, la gerencia otorga un bono mensual al que haya
registrado la mayor cantidad de turnos en ese periodo, por lo tanto, una necesidad del
sistema, es indicar cu�l es el profesional que debe recibir el bono*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct Fecha{

    int anio, mes, dia;

};

struct Usuarios{

    char usuario[10];

    char contrasena[10];

    char ApeyNom[60];

};

struct Clientes{

    char AyN[60];

    char Domicilio[60];

    int dniCliente;

    char localidad[60];

    Fecha fechadeNacimiento;

    float peso;

    int tel;

};

struct Profesionales{

    char ApellidoyNombre[60];

    int IdProfesional;

    int Dni;

    int Telefono;

};

//Variables Globales.

FILE *RP;

char edad, dni[10];

int clave, auxClave;

bool encontrado= false;

//Prototipos de funciones.

void regiPro();

main(){

    system("color 9f");

    int opc;

    printf("**********************************************************************");
    printf("\n*\tBienvenido al Sistema del Centro de Estetica Misa               *");
    printf("\n********************************************************************");
    printf("\n");
	
	do{
		printf("\n-----------------------------------------------------------------");
		printf("\n-                  Menu de Opciones                             -");
		printf("\n-----------------------------------------------------------------");
		printf("\n-1. Registrar Profesional.                                      -");
		printf("\n-2. Registrar Usuario Recepcionista.                            -");
		printf("\n-3. Atenciones por Profesional.                                 -");
		printf("\n-4. Ranking de Profesionales por Atenciones.                    -");
		printf("\n-5. Cerrar la aplicaci�n.                                       -");
		printf("\n-----------------------------------------------------------------");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opc);
		
		switch(opc){

			case 1:

			printf("\n");

            regiPro();	
			
			system("PAUSE");

			break;

			case 2:

			printf("\n");
			
			system("PAUSE");
			break;
			case 3:
			
			system("PAUSE");
			break;
			case 4:
			
			system("PAUSE");
			break;
			case 5:
			
			system("PAUSE");
			break;
			default:
			printf("Opcion invalida\n");
			system("PAUSE");
			break;
		}
			system("CLS");
			
	}while(opc != 5);



    getch();

}
/*----------------------------------------------------------------------*/
void regiPro(){

    system("color 1d");

    bool continuar= 'n' || 'N';

    RP= fopen("Profesionales.dat", "w+b");

    if(RP == NULL){
		
		printf("Error al crear el archivo \n");
		
		exit(EXIT_FAILURE);
		
	}else{

        printf("El Archivo se creo exitosamente...");

    }

    system("pause");

    system("cls");

    printf("INGRESE LOS DATOS DEL PROFESIONAL: ");

    do{

        printf("\nINGRESE NOMBRE Y APELLIDO DEL PROFESIONAL: ");

        gets(Profesionales.ApellidoyNombre);

        printf("\nINGRESE NUMERO DE MATRICULA: ");

        scanf("%d", &Profesionales.IdProfesional);

        printf("\nINGRESE NUMERO DE D.N.I.: ");

        scanf("%d", &Profesionales.Dni);
        
        printf("\nINGRESE EL NUMERO DE TELEFENO: ");
        
        SCANF("%d", &Profesionales.Telefono);
        
        system("pause");
        
        system("cls");



        printf("\DESEA CONTINUAR INGRESANDO PROFESIONALES...?\n\nPRESIONE 'S' PARA SI Y 'N' PARA NO: ");

        scanf("%b", &continuar);

        system("pause");

        system("cls");

    }(continuar== 's' || 'S');









    fclose(RP);

}
