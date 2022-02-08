/*                        Módulo Recepción:
	
* Este módulo satisface las necesidades del personal que recibe al cliente y 
asiste a los Profesionales en la atención al público. Desde aquí se hace
ingreso de los clientes (alta de un nuevo cliente),

* y la registración de los turnos (Esto solo lo realizan los recepcionistas).

* Esta aplicación debe permitir obtener un informe de los clientes atendidos en
determinada fecha por un determinado profesional.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct Fecha{

    int anio, mes, dia;
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

struct Usuarios{

    char usuario[10];
    char contrasena[10];
    char ApeyNom[60];
};

struct Profesionales{

    char ApellidoyNombre[60];
    int IdProfesional;
    int Dni;
    int Telefono;
};

struct fecha{
	
	int A, M, D;
};

struct Turnos{
	
	int IdProfesional;
	fecha Fech;
	int DniCliente;
	char DetalledeAtencion[380];
	bool borrado;
};


//PROTOTIPOS.

int iniciar(int b);
void regiCli();
void regiTur();
void listar();

//VARIABLES GLOBALES.

FILE *RP;
FILE *CL;
FILE *RL;
FILE *TR;

char edad, dni;
int tur=0;

Usuarios usi;
Profesionales profe;
Clientes cli;
Turnos tu;

main(){
	
	system("color f0");

    int opc, l;

    printf("**********************************************************************");
    printf("\n*\tBienvenido al Sistema del Centro de Estetica Misa            *");
    printf("\n*\t-------------------------------------------------            *");
    printf("\n**********************************************************************");
    printf("\n");
	
	do{
		printf("\n*****************************************************************");
		printf("\n*                  Menu de Opciones                             *");
		printf("\n*                  ----------------                             *");
		printf("\n*****************************************************************");
		printf("\n* 1. Iniciar Sesion.                                            *");
		printf("\n* 2. Registrar Cliente.                                         *");
		printf("\n* 3. Registrar Turno.                                           *");
		printf("\n* 4. Listado de Atenciones por Profesional y Fecha.             *");
		printf("\n* 5. Cerrar la aplicacion.                                      *");
		printf("\n*****************************************************************");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opc);
		
		printf("\n");
		
		switch(opc){

			case 1:
	            iniciar(l);	
				system("PAUSE");
				break;

			case 2:
				regiCli();
				system("PAUSE");
				break;
			
			case 3:
				regiTur();
				system("PAUSE");
				break;
			
			case 4:
				listar();
				printf("\n");
				system("PAUSE");
				break;
			
			case 5:
				printf("CERRAR APLICACION...!");
				printf("\n");
				system("PAUSE");
				break;
			
			default:
				printf("Opcion invalida\n");
				system("PAUSE");
				break;
			
		}// fin switch
		
		system("CLS");
			
	}while(opc != 5);

	getch();	
}
/*-------------------------------------------------------------------------------*/
int iniciar(int b){
	
	system("cls");
	system("color f0");
	
	char name[10], pass[10];
	int longitud, longitud1, Pal, Pol;
	b=0;
	
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n+\t\tINICIE SESION:                    +");
	printf("\n+\t\t-------------                     +");
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++");
	
	printf("\n\nINGRESE EL NOMBRE DE USUARIO: ");
	_flushall();
    gets(name);
	
	printf("\n\nINGRESE LA CONTRASENA: ");
	_flushall();
	gets(pass);
	
	RL= fopen("Recepcionistas.dat", "a+b");

    if(RL == NULL){
		printf("\n\t\t***********Error*********** \n");
		exit(EXIT_FAILURE);
	}
	
	rewind(RL);
	
	fread(&usi,sizeof(Usuarios),1,RL);
	
	
 	while(!feof(RL)){
 		Pal=strcmp(name,usi.usuario);
		Pol=strcmp(pass,usi.contrasena);
 		
		if( (Pal==0) && (Pol==0) ){
			
			printf("\nACCESO EXITOSO...!");
			b=1;
		}
			
 		fread(&usi,sizeof(Usuarios),1,RL);
 		//fread(&pass,sizeof(char),1,RL);	
 	}
 	
 	fclose(RL);
 	
	if(b==0){
		printf("\n\t\t*********ERROR*********");
		printf("\nEL USUARIO Y/O LA CONTRASENA ES INCORRECTA\n");
		system("pause");
		system("cls");
		printf("\nINICIE NUVAMENTE LA SESION...! ");
	}
	getch();
	return b;	
}
/*---------------------------------------------------------------------------*/
void regiCli(){
	
	system("cls");
    system("color f0");

	int continuar;
	
    CL= fopen("Clientes.dat", "a+b");

    if(CL == NULL){
		printf("Error al crear el archivo \n");
		exit(EXIT_FAILURE);
	}
    
    printf("\n\n\t\tINGRESE LOS DATOS PERSONALES DEL CLIENTE: ");
    printf("\n\t\t--------------------------------------------");

    do{

        printf("\n\n INGRESE NOMBRE Y APELLIDO DEL CLIENTE: ");
        _flushall();
        gets(cli.AyN);
        
        printf("\n\n INGRESE DOMICILIO: ");
        gets(cli.Domicilio);
        printf("\n\n INGRESE NUMERO DE DNI: ");
        scanf("%d", &cli.dniCliente);
        printf("\n\n INGRESE LOCALIDAD: ");
        _flushall();
        gets(cli.localidad);
        
        printf("\n INGRESE FECHA DE NACIMIENTO: ");
		printf("\n\t Dia: ");
		scanf("%d", &cli.fechadeNacimiento.dia);
		printf("\t Mes: ");
		scanf("%d", &cli.fechadeNacimiento.mes);
		
		do{
			
			printf("\t Anio: ");
			scanf("%d", &cli.fechadeNacimiento.anio);
			
		}while(cli.fechadeNacimiento.anio<1000);
		
		printf("\n INGRESE LA MASA DE SU CUERPO (Kg): ");
		scanf("%f", &cli.peso);
		
		printf("\n INGRESE EL NUMERO DE TELEFONO: ");
		scanf("%d", &cli.tel);
        
        system("cls");
        
        
        fwrite(&cli,sizeof(Clientes),1,CL);
        
        printf("\n");
        system("pause");
        system("cls");

        printf("\nDESEA CONTINUAR INGRESANDO CLIENTES...?\n\n PRESIONE 1 PARA SI Y 0 PARA NO: ");
        scanf("%d", &continuar);
        system("pause");
        system("cls");

    }while(continuar== 1);


    fclose(CL);
	
	getch();
}
/*-----------------------------------------------------------------------*/
void regiTur(){
	
	system("cls");
	system("color f0");
	
	int conti, dniCliente=0, elCli=0, opc;
	
	TR= fopen("Turnos.dat", "a+b");
	CL=fopen("Clientes.dat","a+b");
	
	printf("************************************");
	printf("\n*\tREGISTRAR TURNO:              *");
	printf("\n\t---------------                 ");
	printf("\n**********************************");
	
		
	printf("\n\nINGRESE EL NUMERO DE DNI: ");
	scanf("%d", &dniCliente);
	
	fread(&cli,sizeof(Clientes),1,CL);
	while(!feof(CL) && elCli==0){
	
		if(dniCliente==cli.dniCliente){
			elCli=1;
			printf("\n\t\t\t - - DATOS DEL CLIENTE - -\n ");
			printf("\n\t\t\t NOMBRE: ");
			puts(cli.AyN);
			printf("\n\t\t\t DIRECCION: ");
			puts(cli.Domicilio);
		
			
			printf("\n\nESTABLEZCA LA FECHA PARA EL TURNO: ");
			printf("\n\n\tDIA: ");
			scanf("%d", &tu.Fech.D);
			printf("\n\n\tMES: ");
			scanf("%d", &tu.Fech.M);
			
			do{
				
				printf("\n\n\tANIO: ");
				scanf("%d", &tu.Fech.A);
				
			}while(tu.Fech.A<1000);
			
			printf("\n\nID DEL PROFESIONAL CON QUIEN SE ATENDERA: ");
			scanf("%d", &tu.IdProfesional);
			
			tu.DniCliente=cli.dniCliente;
			tu.borrado = false;
			
			printf("\n DESEA REGISTRAR EL TURNO? // 1 - SI | 0 - NO: ");
			scanf("%d", &opc);
			if(opc==1){
				fwrite(&tu,sizeof(tu),1,TR);
				printf("\n\t\t\t TURNO REGISTRADO \n");
			}else{
				printf("\n\t\t\t TURNO NO REGISTRADO \n");
			}
			
		}
		fread(&cli,sizeof(Clientes),1,CL);
	}
	
	if(elCli==0)
	{
		printf("\n\t\t NO SE REGISTRO UN CLIENTE CON ESE DNI\n\n");
	}
	
	
	fclose(TR);
	fclose(CL);
	getch();
	
}
/*-------------------------------------------------------------------*/
void listar(){
	
	system("cls");
	system("color f0");
	
	int conta=0, dia=0, mes=0, anio=0, idDelProfesional=0;
	
	RP=fopen("Profesionales.dat","a+b");
	TR=fopen("Turnos.dat","a+b");
	CL=fopen("Clientes.dat","a+b");
	
	printf("\n\t\t*********************************************************************************************************");
	printf("\n\t\t** INFORME DE CLIENTES QUE FUERON ATENDIDOS EN UNA DETERMINADA FECHA POR UN DETERMINADO PROFESIONAL     **");
	printf("\n\t\t**--------------------------------------------------------------------------------------------------**");
	printf("\n\t\t***********************************************************************************************************\n\n");
	
	printf("\n INGRESE ID DEL PROFESIONAL: ");
	scanf("%d", &idDelProfesional);
	
	printf("\n INGRESE FECHA DE ATENCION: ");
	printf("\n\tDIA: ");
	scanf("%d", &dia);
	printf("\tMES: ");
	scanf("%d", &mes);
	
	do{
		
		printf("\tANIO: ");
		scanf("%d", &anio);
		
	}while(anio<1000);
	
	
	/*rewind(TR);
	rewind(CL);
	rewind(RP);
	*/
	fread(&tu, sizeof(Turnos), 1, TR);
	while(!feof(TR)){
		//printf("\n ENTRA");
		if(tu.borrado==true && idDelProfesional==tu.IdProfesional && tu.Fech.D==dia && tu.Fech.M==mes && tu.Fech.A==anio){
			fread(&profe, sizeof(Profesionales), 1, RP);
			fread(&usi,sizeof(Usuarios),1,RP);
		
			while(!feof(RP)){

				if(profe.IdProfesional==idDelProfesional){
					fread(&cli, sizeof(Clientes), 1, CL);
		
					while(!feof(CL)){
			
						if(cli.dniCliente==tu.DniCliente){
							
							printf("\n\t\t\t    PROFESIONAL: ");
							puts(profe.ApellidoyNombre);
							printf("\n\t\t\t    CLIENTE ATENDIDO: ");
							puts(cli.AyN);
							printf("\n\t\t\t    DNI: %d", cli.dniCliente);
							printf("\n\t\t\t    DETALLE DE ATENCION: ");
							puts(tu.DetalledeAtencion);
							
							conta++;
							
							printf("\n\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
						}
						fread(&cli,sizeof(Clientes),1,CL);
					}
					rewind(CL);
				}
				fread(&profe, sizeof(Profesionales), 1, RP);
				fread(&usi,sizeof(Usuarios),1,RP);
			}
			rewind(RP);
		}
		fread(&tu, sizeof(Turnos), 1, TR);
	}

	
	
	
	if(conta==0){
		printf("\n\t La ID no esta en el sistema / No hay atenciones en la fecha\n");
	}else{
		printf("\n\t\t Operacion realizada sin errores\n");
	}
	
	/*fread(&tu, sizeof(Turnos), 1, TR);
	fread(&cli, sizeof(Clientes), 1, CL);

	while(!feof(CL) && !feof(TR)){
		
		printf("%d). %s --> ", i+1, cli.AyN);
		printf("\t-");
		printf("\t%d/%d/%d ", tu.Fech.D, tu.Fech.M, tu.Fech.A);
		printf("\t-");
		printf("\t%d ", tu.IdProfesional);

		fread(&tu, sizeof(Turnos), 1, TR);
		fread(&cli, sizeof(Clientes), 1, CL);
	}*/
	
	fclose(TR);
	fclose(CL);
	fclose(RP);
	
	getch();
}
