#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Fecha{

    int anio;
	int mes;
	int dia;
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

struct Turnos{
	
	int IdProfesional;
	Fecha Fech;
	int DniCliente;
	char DetalledeAtencion[380];
	bool borrado;
};

int menu();
void gotoxy(int x, int y);
int iniciarSecion(char nomProfesional[60], int b);
void listarTurnos( int diaBuscar, int mesBuscar, int anioBuscar);
void evolucionTratamiento(int diaBuscar, int mesBuscar, int anioBuscar, char nombreProfe[60]);

Usuarios usi;
Turnos tu;
Clientes cli;
Profesionales profe;

main(){
	int opc;
	system("mode con: cols=140 lines=40");
	
	int diaBuscar=0, mesBuscar=0, anioBuscar=0, l;
	char nomProfesional[60];
	
	do{
		system("cls");
		opc = menu();
		system("cls");
		system("color b0");
		
		switch( opc ){
			case 1:{
						gotoxy(32,3); printf("       *  *  * INICIE SESION CON SU CUENTA PROFESIONAL *  *  *");
						gotoxy(32,4); printf("       -------------------------------------------------------");
						iniciarSecion(nomProfesional, l);
						break;
					}
			
			case 2:{
						if(l==1){
						
							gotoxy(30,3); printf("                   *  *  * LISTA DE ESPERA *  *  *");
							gotoxy(32,4); printf("       -------------------------------------------------------");
							printf("\n\n\t INGRESE LA FECHA DE HOY ");
							printf("\n\t                    DIA: ");
							scanf("%d", &diaBuscar);
							
							printf("\n\t                    MES: ");
							scanf("%d", &mesBuscar);
							
							printf("\n\t                    ANIO: ");
							do{
								scanf("%d", &anioBuscar);
								printf("\n\t INGRESE UN ANIO VALIDO: ");
								
							}while(anioBuscar<1000);
							
							listarTurnos(diaBuscar, mesBuscar, anioBuscar);
						}else{
							printf("\n\t [ INICIE SECCION PARA ACCEDER A ESTA OPCION ]");
						}
						break;
					}

			case 3:{
						if(l==1){
							gotoxy(30,3); printf("        *  *  * EVOLUCION DEL TRATAMIENTO DEL CLIENTE *  *  *");
							gotoxy(32,4); printf("       -------------------------------------------------------");
							evolucionTratamiento(diaBuscar, mesBuscar, anioBuscar, nomProfesional);
						}else{
							printf("\n\t [ INICIE SECCION PARA ACCEDER A ESTA OPCION ]");
						}
						break;
					}	
					
			case 4:{
						printf("\n\n\t SALIENDO DEL PROGRAMA..");
						break;
					}
			
			default:{
						printf("\n\n\t OPCION INCORRECTA. VUELVA A INTENTARLO");
						break;
					}
		}// fin switch
		printf("\n\n");
		system("pause");
	}while(opc != 4);
	
}


void evolucionTratamiento(int diaBuscar, int mesBuscar, int anioBuscar, char nombreProfe[60]){
	char nomyapeBus[60];
	int edad=0, compNom, c=0, idProfes=0;
	bool band;
	
	if(diaBuscar!=0 && mesBuscar!=0 && anioBuscar!=0){
		
		printf("\n\n\t\t FECHA DE HOY: %d/%d/%d \n", diaBuscar, mesBuscar, anioBuscar);
	}else{
		printf("\n\n\t\t INGRESE FECHA DE HOY ");
		printf("\n\t\t                    DIA: ");
		scanf("%d", &diaBuscar);
		
		printf("\t\t                    MES: ");
		scanf("%d", &mesBuscar);
		
		do{
			printf("\t\t                    ANIO: ");
			scanf("%d", &anioBuscar);
			
		}while(anioBuscar<1000);
	}
	
	printf("\n\t\t ID DEL PROFESIONAL: ");
	scanf("%d", &idProfes);
	
	printf("\n\t\t NOMBRE Y APELLIDO DEL CLIENTE A ATENDER: ");
	_flushall();
	gets(nomyapeBus);
	
	FILE *archivo = fopen("Clientes.dat","r+b");
	FILE *archivo2 = fopen("Turnos.dat","r+b");
	
	fseek(archivo, 0, SEEK_SET);
	fseek(archivo2, 0, SEEK_SET);
	
	
	fread(&tu, sizeof(Turnos), 1, archivo2);
	
	band=false;
	
	
	while(!feof(archivo2) && band == false){
		if(tu.borrado == false && tu.Fech.dia == diaBuscar && tu.Fech.mes == mesBuscar && tu.Fech.anio == anioBuscar){ 
			
			fread(&cli, sizeof(Clientes), 1, archivo);
			while(!feof(archivo)){ 
				compNom = strcmp(nomyapeBus, cli.AyN);
				if(compNom == 0 && cli.dniCliente == tu.DniCliente){ //verifica si el cliente tiene un turno
						
					printf("\n\t\t\t +  +  +  +  +  +  + DATOS DEL CLIENTE +  +  +  +  +  +  +\n");
					printf("\n\t\t\t\t NOMBRE Y APELLIDO: ");
					puts(cli.AyN);
					printf("\n\t\t\t\t DNI: %d", cli.dniCliente);
					printf("\n\t\t\t\t DOMICILIO: ");
					puts(cli.Domicilio);
					
					edad = 2022 - cli.fechadeNacimiento.anio;
					printf("\n\t\t\t\t EDAD: %d", edad);
					printf("\n\t\t\t\t PESO: %.2f", cli.peso);
					
					tu.borrado=true;
					fseek(archivo2, (long) -sizeof(Turnos), SEEK_CUR);
					fwrite(&tu, sizeof(Turnos), 1, archivo2);
					
					
					printf("\n\n\t\t\t 'enter' para redactar la evolucion del tratamiento\n\n");
					system("pause");
					system("cls");
					gotoxy(30,3);printf(" -----------------------------------------------------------------");
					gotoxy(30,5);printf(" |                FECHA DE ATENCION: %d/%d/%d                    |", diaBuscar, mesBuscar, anioBuscar);
					gotoxy(30,6);printf("                  ID DEL PROFESIONAL: %d                     ",idProfes);
					gotoxy(30,7);printf(" |                                                               |");
					gotoxy(30,8);printf(" -----------------------------------------------------------------");
					gotoxy(30,10);printf("   EVOLUCION DEL TRATAMIENTO: ");
					_flushall();
					gets(tu.DetalledeAtencion);
					
					c++;
					
					tu.borrado=true;
					fseek(archivo2, (long) -sizeof(Turnos), SEEK_CUR);
					fwrite(&tu, sizeof(Turnos), 1, archivo2);
					band=true;
					
				}
			
				fread(&cli, sizeof(Clientes), 1, archivo);
			}
		}else{
			
			fread(&tu, sizeof(Turnos), 1, archivo2);
		}
		
	}
	
	if(c == 0){
		gotoxy(37,18);printf(" . . . . . . . . . . . . . . . . . . . . . . . . .  ");
		gotoxy(37,19);printf("  EL CLIENTE INGRESADO NO SE ENCUENTRA REGISTRADO");
		gotoxy(37,20);printf("  Y/O NO SE ENCONTRO NINGUN TURNO EL DIA DE HOY");
	}else{
		printf("\n\n\n\t\t\t\t    ''''''''''''''''''''''''''''''''''''''''''''''''");
		printf("\n\t\t\t\t         EVOLUCION DEL TRATAMIENTO REGISTRADO");
	}
	fclose(archivo);
	fclose(archivo2);
	
}


void listarTurnos( int diaBuscar, int mesBuscar, int anioBuscar){
	int contador=0; // variable para contar los turnos del dia
	
	system("cls");
	printf("\n FECHA DE HOY: %d/%d/%d \n\n", diaBuscar, mesBuscar, anioBuscar);

	FILE *archivo = fopen("Turnos.dat","r+b");
	FILE *archivo1 = fopen("Clientes.dat","r+b");
	
	rewind(archivo);
	
	fread(&tu, sizeof(Turnos), 1, archivo);
	
	while(!feof(archivo)){
		if(tu.borrado == false){
			if(tu.Fech.mes == mesBuscar && tu.Fech.anio == anioBuscar && tu.Fech.dia == diaBuscar){
				rewind(archivo1);
			    fread(&cli,sizeof(Clientes),1,archivo1);
			    
			    while(!feof(archivo1)){
		    		if(tu.DniCliente == cli.dniCliente){
		    			printf("\n\n\t\t CLIENTE: ");
						puts(cli.AyN);
						printf("\t\t DNI %d", tu.DniCliente);
						printf("\n\t\t PESO: %.2f", cli.peso);
						printf("\n\t\t EDAD: %d", 2022 - cli.fechadeNacimiento.anio);
						printf("\n\t\t FECHA DE TURNO: %d/%d/%d", tu.Fech.dia, tu.Fech.mes, tu.Fech.anio);
						contador++;
						printf("\n\t------------------------------------------------\n\n");
						
					}
				fread(&cli,sizeof(Clientes),1,archivo1);
				}
				
			}
		}	
		fread(&tu, sizeof(Turnos), 1, archivo);
	}
	
	if(contador == 0){
		printf("\n\n\t\t NO SE REGISTRARON TURNOS EN LA FECHA");
	}else{
		printf("\n\n\t\t |  LISTA DE ESPERA CARGADA  |");
	}
	fclose(archivo);
	fclose(archivo1);
}


int iniciarSecion(char nomProfesional[60], int b){
	system("color b0");
	int valor1, valor2;
	char nomUsuario[10], contraUsuario[10];
	b=0;
	
	gotoxy(38,6); printf(" INGRESE EL NOMBRE DE USUARIO: ");
	_flushall();
	gets(nomUsuario);
	
	gotoxy(38,8); printf(" CONTRASENA: ");
	_flushall();
	gets(contraUsuario);
	

	FILE *archi = fopen("Profesionales.dat", "r+b");
	
	if(archi == NULL){
		printf("\n\t\t***********Error*********** \n");
		exit(EXIT_FAILURE);
	}
	
	rewind(archi);
	
	fread(&profe, sizeof(Profesionales), 1, archi);
	fread(&usi, sizeof(Usuarios), 1, archi);

	while(!feof(archi)){
		valor1=strcmp(usi.usuario, nomUsuario);
		valor2=strcmp(usi.contrasena, contraUsuario);
		
		if( (valor1==0) ){
			if(valor2==0){
				gotoxy(50,14); printf("ACCESO EXITOSO...!\n\n ");
				strcpy(nomProfesional,profe.ApellidoyNombre);
				b=1;
			}
		}	
		fread(&profe, sizeof(Profesionales),1, archi);
		fread(&usi, sizeof(Usuarios),1, archi);
			
 	}
 	
 	fclose(archi);
 	
 	if(b == 0){
		gotoxy(45,14); printf("      *********ERROR*********");
		gotoxy(40,15);printf("EL USUARIO Y/O LA CONTRASENA ES INCORRECTA\n");
		gotoxy(40,17);system("pause");
		system("cls");
		gotoxy(42,8);printf("INICIE NUEVAMENTE LA SESION...! \n");
	}else{
		b=1;
	}

 	
 	return b;
		
}


int menu(){
	int opcion=0;
	system("color b0");

	gotoxy(38,5);printf(" ========================================================");
	gotoxy(38,6);printf(" |          M O D U L O - E S P A C I O S               |");
	gotoxy(38,7);printf(" ========================================================");
	
	//printf("\033[0;33m");
	gotoxy(38,9);printf(" ________________________________________________________");
	gotoxy(38,10);printf("  1- INICIAR SESION     ");
	gotoxy(38,11);printf(" ________________________________________________________");
	gotoxy(38,12);printf("  2- VISUALIZAR LISTA DE ESPERA DE TURNOS (informe)     ");
	gotoxy(38,13);printf(" ________________________________________________________");
	gotoxy(38,14);printf("  3- REGISTRAR EVOLUCION DEL TRATAMIENTO      ");
	gotoxy(38,15);printf(" ________________________________________________________");
	gotoxy(38,16);printf("  4- CERRAR LA APLICACION                  ");

	
	gotoxy(52,18);printf("-----------------------");
	gotoxy(52,19); printf("      OPCION: ");
	scanf("%d", &opcion);
	
	return opcion;
}

//FUNCION GOTOXY
void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}
