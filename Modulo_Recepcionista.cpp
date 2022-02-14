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

void gotoxy(int x, int y);
void iniciar(int &b);
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
	system("mode con: cols=140 lines=40");

    int opc, l=0;

	do{
		system("color b0");
		
		gotoxy(38,5);printf("*****************************************************************");
		gotoxy(38,6);printf("*        M O D U L O - D E L - R E C E P C I O N I S T A        *");
		gotoxy(38,7);printf("*        -----------   -----   -------------------------        *");
		gotoxy(38,8);printf("*****************************************************************");
		gotoxy(38,10);printf("*       1. INICIAR SESION                                       *");
		gotoxy(38,11);printf("*       2. REGISTRAR CLIENTE                                    *");
		gotoxy(38,12);printf("*       3. REGISTRAR TURNO                                      *");
		gotoxy(38,13);printf("*       4. LISTADO DE ATENCIONES POR PROFESIONAL Y FECHA        *");
		gotoxy(38,14);printf("*       5. CERRAR LA APLICACION                                 *");
		gotoxy(38,16);printf("*****************************************************************");
		gotoxy(38,18);printf("  OPCION: ");
		scanf("%d", &opc);
		
		printf("\n");
		
		switch(opc){

			case 1:
	            iniciar(l);	
	            printf("\n\n");
				system("PAUSE");
				break;

			case 2:
				if(l==1){
					regiCli();
				}else{
					printf("\n\t [ INICIE SECCION PARA ACCEDER A ESTA OPCION ]");
				}
				printf("\n\n");
				system("PAUSE");
				break;
			
			case 3:
				if(l==1){
					regiTur();
				}else{
					printf("\n\t [ INICIE SECCION PARA ACCEDER A ESTA OPCION ]");
				}
				printf("\n\n");
				system("PAUSE");
				break;
			
			case 4:
				if(l==1){
					listar();
				}else{
					printf("\n\t [ INICIE SECCION PARA ACCEDER A ESTA OPCION ]");
				}
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
void iniciar(int &b){
	
	system("cls");
	system("color f0");
	
	char name[10], pass[10];
	int longitud, longitud1, Pal, Pol;
	b=0;
	
	gotoxy(38,2);printf("+++++++++++++++++++++++++++++++++++++++++++++++++++");
	gotoxy(38,3);printf("+\t\t       INICIE SESION:                   +");
	gotoxy(38,4);printf("+\t\t       -------------                    +");
	gotoxy(38,5);printf("+++++++++++++++++++++++++++++++++++++++++++++++++++");
	
	gotoxy(37,7);printf(" INGRESE");
	gotoxy(38,8);printf(" NOMBRE DE USUARIO: ");
	_flushall();
    gets(name);
	
	gotoxy(38,10);printf(" CONTRASENA: ");
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
			
			gotoxy(50,14);printf("ACCESO EXITOSO...!");
			b=1;
		}else{
			b=0;
		}
			
 		fread(&usi,sizeof(Usuarios),1,RL);
 	}
 	
 	fclose(RL);
 	
	if(b==0){
		gotoxy(45,15); printf("      *********ERROR*********");
		gotoxy(40,16);printf("EL USUARIO Y/O LA CONTRASENA ES INCORRECTA\n");
		gotoxy(40,18);system("pause");
		system("cls");
		gotoxy(42,8);printf("INICIE NUEVAMENTE LA SESION...! \n");
	}else{
		b=1;
	}

	
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
	
	gotoxy(38,2);printf("************************************");
	gotoxy(38,3);printf("*         REGISTRAR TURNO:         *");
	gotoxy(38,4);printf("          ---------------           ");
	gotoxy(38,5);printf("************************************");
	
		
	gotoxy(38,7);printf(" INGRESE EL NUMERO DE DNI: ");
	scanf("%d", &dniCliente);
	
	fread(&cli,sizeof(Clientes),1,CL);
	while(!feof(CL) && elCli==0){
	
		if(dniCliente==cli.dniCliente){
			elCli=1;
			gotoxy(38,9);printf("- - - DATOS DEL CLIENTE - - -");
			gotoxy(38,10);printf(" NOMBRE: ");
			puts(cli.AyN);
			gotoxy(38,11);printf(" DIRECCION: ");
			puts(cli.Domicilio);
		
			
			gotoxy(38,14);printf(" ESTABLEZCA LA FECHA PARA EL TURNO: ");
			gotoxy(38,15);printf("DIA: ");
			scanf("%d", &tu.Fech.D);
			gotoxy(38,16);printf("MES: ");
			scanf("%d", &tu.Fech.M);
			
			do{
				
				gotoxy(38,17);printf("ANIO: ");
				scanf("%d", &tu.Fech.A);
				
			}while(tu.Fech.A<1000);
			
			gotoxy(36,19);printf("ID DEL PROFESIONAL CON QUIEN SE ATENDERA: ");
			scanf("%d", &tu.IdProfesional);
			
			tu.DniCliente=cli.dniCliente;
			tu.borrado = false;
			
			gotoxy(35,23);printf(" DESEA REGISTRAR EL TURNO? // 1 - SI | 0 - NO: ");
			scanf("%d", &opc);
			if(opc==1){
				fwrite(&tu,sizeof(tu),1,TR);
				gotoxy(44,28);printf(" TURNO REGISTRADO ");
			}else{
				gotoxy(44,28);printf(" TURNO NO REGISTRADO ");
			}
			
		}
		fread(&cli,sizeof(Clientes),1,CL);
	}
	
	if(elCli==0)
	{
		gotoxy(35,14);printf(" NO SE REGISTRO UN CLIENTE CON ESE DNI");
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

	fclose(TR);
	fclose(CL);
	fclose(RP);
	
	getch();
}

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}
