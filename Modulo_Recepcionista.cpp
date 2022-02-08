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

void iniciar();
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

    int opc;

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
	            iniciar();	
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
void iniciar(){
	
	system("cls");
	system("color f0");
	
	char name[10], pass[10];
	int longitud, longitud1, Pal, Pol;
	
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
	
	RL= fopen("Recepcionistas.dat", "rb");

    if(RL == NULL){
		printf("\n\t\t***********Error*********** \n");
		exit(EXIT_FAILURE);
	}
	
	rewind(RL);
	
	fread(&usi,sizeof(Usuarios),1,RL);
	//fread(&pass,sizeof(Usuarios),1,RL);
	
	Pal=strcmp(name,usi.usuario);
	Pol=strcmp(pass,usi.contrasena);
	
	longitud= strlen(name);
	longitud1= strlen(pass); 
	
 	while(!feof(RL)){
 		
		if( (Pal==0) && (Pol==0) ){
			
			printf("\nACCESO EXITOSO...!");
			
		}else{
			
			printf("\n\t\t*********ERROR*********");
			printf("\nEL USUARIO Y/O LA CONTRASENA ES INCORRECTA\n");
			system("pause");
			system("cls");
			printf("\nINICIE NUVAMENTE LA SESION...! ");
		}
			
 		fread(&usi,sizeof(Usuarios),1,RL);
 		//fread(&pass,sizeof(char),1,RL);	
 	}
 	
 	fclose(RL);

	getch();	
}
/*---------------------------------------------------------------------------*/
void regiCli(){
	
	system("cls");
    system("color f0");

    int continuar= 0, i=0, longitud, longitud2, j=1;
    int contDigitos=0, contMayus=0;
    int contMinusc=0, contMayusc=0, contNumeros=0;
    bool esta=false;
	bool esta2=false;

    CL= fopen("Clientes.dat", "ab");

    if(CL == NULL){
		printf("Error al crear el archivo \n");
		exit(EXIT_FAILURE);
	}
    
    printf("\t\t\tGENERE UNA CUENTA: ");
    printf("\n\t\t\t-----------------");
    printf("\n\n\t\tINGRESE LOS DATOS PERSONALES DEL CLIENTE: ");
    printf("\n\t\t--------------------------------------------");

    do{

        printf("\n\nINGRESE NOMBRE Y APELLIDO DEL CLIENTE: ");
        _flushall();
        gets(cli.AyN);
        
        printf("\n\nINGRESE DOMICILIO: ");
        gets(cli.Domicilio);
        printf("\n\nINGRESE NUMERO DE DNI: ");
        scanf("%d", &cli.dniCliente);
        printf("\n\nINGRESE LOCALIDAD: ");
        _flushall();
        gets(cli.localidad);
        
        printf("\nINGRESE FECHA DE NACIMIENTO: ");
		printf("\n\tDia: ");
		scanf("%d", &cli.fechadeNacimiento.dia);
		printf("\tMes: ");
		scanf("%d", &cli.fechadeNacimiento.mes);
		
		do{
			
			printf("\tAnio: ");
			scanf("%d", &cli.fechadeNacimiento.anio);
			
		}while(cli.fechadeNacimiento.anio<1000);
		
		printf("\nINGRESE LA MASA DE SU CUERPO (Kg): ");
		scanf("%f", &cli.peso);
		
		printf("\nINGRESE EL NUMERO DE TELEFONO: ");
		scanf("%d", &cli.tel);
        
        system("cls");
        
        printf("\n\t\tINGRESE USUARIO Y CONTRASENA PARA SU NUEVA CREDENCIAL:");
        printf("\n\t\t------------------------------------------------------");
        printf("\n\nINGRESE NOMBRE DE USUARIO (minimo 6 caracteres y maximo 10 caracteres, la primera letra minuscula, al menos tres letras mayusculas y tres numeros): ");
        
		do{
			_flushall();
			gets(usi.usuario);
			
			longitud = strlen(usi.usuario);
			
			if(longitud>=6 && longitud<=10){
			
				for(int i=0; i<longitud; i++){
					//printf("%c  - %d\n", cadFrase[i], cadFrase[i]);
					
					if(usi.usuario[0]>=97  && usi.usuario[0]<=122){		//Codigo ASCII de letras en minuscula
			
						if(usi.usuario[i]>=65 && usi.usuario[i]<=90){    //Codigo ASCII de letras en mayuscula
							contMayus++;	
									
				       	}
					}
					
				}
				
				for(int i=0; i<longitud; i++){
					//if(contMayus >= 2){
				    	if(usi.usuario[i]>=33 && usi.usuario[i]<=57){
							contDigitos = contDigitos + 1;	
				        }	
					//}
				}
				
				if(contDigitos < 4 && contMayus >= 2){
					esta = true;
				}else{
					printf("\n VUELVA A INGRESAR OTRO NOMBRE DE USUARIO: ");
				}
				
			}else{
				printf("\n NOMBRE DE USUARIO MUY CORTO - LARGO");
			}
       	
        }while(esta == false);
        
    	if(esta == true){
			printf("\nSU USUARIO SE CREO CON EXITO...!");
		}
		
		
        //=========================
        
        printf("\n\nINGRESE CONTRASENA (debe tener entre 6 y 32 caracteres, al menos una letra mayuscula, una letra minuscula, un numero, no podra contener nigun caracter de puntuacion, ni acentos, ni espacios, no debera tener mas de 3 caracteres numericos consecutivos, ni debe tener dos caracteres consecutivos que refieran a letras alfabeticamente consecutivas ascendentemente.): ");
        
        do{
        	
        	_flushall();
		    gets(usi.contrasena);
	        
	        longitud2 = strlen(usi.contrasena);
        
        	if(longitud2>=6 && longitud2<=32){
		
				for(int k=0; k<longitud2; k++){
					//printf("%c  - %d\n", cadFrase[i], cadFrase[i]);
					
					if(usi.contrasena[k]>=97  && usi.contrasena[k]<=122){		//Codigo ASCII de letras en minuscula
						contMinusc++;
					}
					if(usi.contrasena[k]>=65 && usi.contrasena[k]<=90){    //Codigo ASCII de letras en mayuscula
						contMayusc++;		
				    }
				    if(usi.contrasena[k]>=48 && usi.contrasena[k]<=57){
						contNumeros++;
					}
					if(usi.contrasena[k]!=32 && usi.contrasena[k]!=44 && usi.contrasena[k]!=46 && usi.contrasena[k]!=96 && usi.contrasena[k]!=59 && usi.contrasena[k]!=58){
						j = 0;
					}
					
				}
			
				if(contMinusc >=1 && contMayusc >= 1 && contNumeros >= 1 && j == 0){
					esta2 = true;
				}else{
					printf("\n ERROR EN LA CONFORMACION DE LA CONTRASENA, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
					printf("\n INGRESE OTRA CONTRASENA: ");
				}
					
			}else{
				printf("\n CONTRASENA MUY CORTO - LARGO\n");
				printf("\n INGRESE OTRA CONTRASENA: ");
			}
        	
        }while(esta2 == false);
        
        if(esta2==true){
			printf("\nSU CONTRASEÑA SE CREO CON EXITO...!");
		}
        
        fwrite(&cli,sizeof(Clientes),1,CL);
        fwrite(&usi,sizeof(Usuarios),1,CL);
        
        printf("\n");
        system("pause");
        system("cls");

        printf("\nDESEA CONTINUAR INGRESANDO PROFESIONALES...?\n\nPRESIONE 1 PARA SI Y 0 PARA NO: ");
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
	
	int conti;
	
	TR= fopen("Turnos.dat", "a+b");
	
	printf("************************************");
	printf("\n*\tREGISTRAR TURNO:              *");
	printf("\n\t---------------                 ");
	printf("\n**********************************");
	
	do{
		
		printf("\n\nINGRESE NUMERO DE IDENTIFICACION PROFESIONAL: ");
		scanf("%d", &tu.IdProfesional);
		
		printf("\n\nESTABLEZCA LA FECHA DEL TURNO: ");
		printf("\n\n\tDIA: ");
		scanf("%d", &tu.Fech.D);
		printf("\n\n\tMES: ");
		scanf("%d", &tu.Fech.M);
		
		do{
			
			printf("\n\n\tANIO: ");
			scanf("%d", &tu.Fech.A);
			
		}while(tu.Fech.A<1000);
		
		printf("\n\nINGRESE EL NUMERO DE DNI: ");
		scanf("%d", &tu.DniCliente);
		
		
		tu.borrado = false;
		
		fwrite(&tu,sizeof(tu),1,TR);
		
		printf("\n DESEA REGISTRAR OTRO TURNO?... 1 - SI /  0 - NO");
		scanf("%d", &conti); // conti = continuar
		
	}while(conti == 1);
	
	fclose(TR);
	getch();
	
}
/*-------------------------------------------------------------------*/
void listar(){
	
	system("cls");
	system("color f0");
	
	int i=0;
	
	TR= fopen("Turnos.dat", "rb");
	CL= fopen("Clientes.dat", "rb");
	
	printf("\n\t\t*********************************************************************************************************");
	printf("\n\t\t** INFORME DE CLIENTES QUE FUERON ATENDIDOS EN UNA DETERMINADA FECHA POR UN DETERMINADO PROFESIONAL     **");
	printf("\n\t\t**--------------------------------------------------------------------------------------------------**");
	printf("\n\t\t***********************************************************************************************************\n\n");
	
	rewind(TR);
	rewind(CL);
	
	fread(&tu, sizeof(Turnos), 1, TR);
	fread(&cli, sizeof(Clientes), 1, CL);

	while(!feof(CL) && !feof(TR)){
		
		printf("%d). %s --> ", i+1, cli.AyN);
		printf("\t-");
		printf("\t%d/%d/%d ", tu.Fech.D, tu.Fech.M, tu.Fech.A);
		printf("\t-");
		printf("\t%d ", tu.IdProfesional);

		fread(&tu, sizeof(Turnos), 1, TR);
		fread(&cli, sizeof(Clientes), 1, CL);
	}
	
	fclose(TR);
	fclose(CL);
	
	getch();
}
