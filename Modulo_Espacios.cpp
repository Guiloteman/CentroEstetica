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
	system("mode con: cols=100 lines=35");
	
	int diaBuscar=0, mesBuscar=0, anioBuscar=0, l=0;
	char nomProfesional[60];
	
	do{
		system("cls");
		opc = menu();
		system("cls");
		
		switch( opc ){
			case 1:{
						gotoxy(30,1); printf("     *  *  * INICIE SESION CON SU CUENTA PROFESIONAL *  *  *");
						iniciarSecion(nomProfesional, l);
						break;
					}
			
			case 2:{
						if(l==1){
						
							gotoxy(30,1); printf("     *  *  * LISTA DE ESPERA *  *  *");
							printf("\n Ingrese la fecha de hoy ");
							printf("\n                    DIA: ");
							scanf("%d", &diaBuscar);
							
							printf("\n                    MES: ");
							scanf("%d", &mesBuscar);
							
							printf("\n                    ANIO: ");
							do{
								scanf("%d", &anioBuscar);
								printf("\n INGRESE UN ANIO VALIDO: ");
								
							}while(anioBuscar>1000);
							
							listarTurnos(diaBuscar, mesBuscar, anioBuscar);
						}else{
							printf("\n\t [ INICIE SECCION PARA ACCEDER A ESTA OPCION ]");
						}
						break;
					}

			case 3:{
						if(l==1){
							gotoxy(30,1); printf("     *  *  * EVOLUCION DEL TRATAMIENTO DEL CLIENTE *  *  *");
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
	int edad=0;
	bool band;
	
	printf("/n/t/t FECHA DE HOY: %d/%d/%d \n", diaBuscar, mesBuscar, anioBuscar);
	
	printf("\n\t INGRESE ");
	printf("NOMBRE Y APELLIDO DEL CLIENTE A ATENDER: ");
	_flushall();
	gets(nomyapeBus);
	
	FILE *archivo = fopen("Clientes.dat","r+b");
	FILE *archivo2 = fopen("Turnos.dat","r+b");
	
	fseek(archivo, 0, SEEK_SET);
	fseek(archivo2, 0, SEEK_SET);
	
	fread(&cli, sizeof(Clientes), 1, archivo);
	fread(&tu, sizeof(Turnos), 1, archivo2);
	
	band=false;
	
	while(!feof(archivo) && !feof(archivo2) && band == false){
		if(nomyapeBus == cli.AyN && tu.borrado == false){ // verifica si el cliente existe
			//if(tu.borrado == false){ // buscar turnos activos
				if(cli.dniCliente == tu.DniCliente){ //verifica si el cliente tiene un turno
					if((tu.Fech.dia == diaBuscar) && (tu.Fech.mes == mesBuscar) && (tu.Fech.anio == anioBuscar)){ // verifica si el cliente tiene un turno el dia de hoy
						
						printf("\n\t ================ DATOS DEL CLIENTE =================");
						printf("\n NOMBRE Y APELLIDO: ");
						puts(cli.AyN);
						printf("\n\t DNI: %d", cli.dniCliente);
						printf("\n\t DOMICILIO: ");
						puts(cli.Domicilio);
						
						edad = 2021 - cli.fechadeNacimiento.anio;
						printf("\n\t EDAD: %d", edad);
						printf("\n\t PESO: %.2f", cli.peso);
						
						tu.borrado=true;
						fseek(archivo2, (long) -sizeof(Turnos), SEEK_CUR);
						fwrite(&tu, sizeof(Turnos), 1, archivo2);
						band=true;
						
						printf("\n\n 'enter' para redactar la evolucion del tratamiento");
						system("cls");
						printf("\n\t -----------------------------------------------------------------");
						printf("\n\t |                     FECHA DE ATENCION: %d/%d/%d               |", diaBuscar, mesBuscar, anioBuscar);
						printf("\n\t                  NOMBRE DEL PROFESIONAL: ");
						puts(nombreProfe);
						printf("         |");
						printf("\n\t -----------------------------------------------------------------");
						printf("\n \tEVOLUCION DEL TRATAMIENTO: ");
						_flushall();
						gets(tu.DetalledeAtencion);
						
						band=true;
						
					}
				}else{
					printf("\n\t El cliente no posee un turno para el dia de hoy.");
				}
			//}
		}else{
			//printf("\n [ EL CLIENTE INGRESADO NO SE ENCUENTRA REGISTRADO ]");
			fread(&cli, sizeof(Clientes), 1, archivo);
			fread(&tu, sizeof(Turnos), 1, archivo2);
		}
		
	}
	fclose(archivo);
	fclose(archivo2);
	
}

void listarTurnos( int diaBuscar, int mesBuscar, int anioBuscar){
	int contador=0; // variable para contar los turnos del dia
	system("cls");
	printf("\n FECHA DE HOY: %d/%d/%d \n\n", diaBuscar, mesBuscar, anioBuscar);
	
	//void listarTurnos(Registro regi, int fechaBus)
	FILE *archivo = fopen("Turnos.dat","rb");
	fseek(archivo, 0, SEEK_SET);
	fread(&tu, sizeof(Turnos), 1, archivo);
	
	while(!feof(archivo)){
		if(tu.borrado == false){
			if(tu.Fech.dia == diaBuscar){
				if(tu.Fech.mes == mesBuscar && tu.Fech.anio == anioBuscar){
				
					printf("\n \t\t DNI DEL CLIENTE %d\n", tu.DniCliente);
					///================================
					// AGREGAR INFORMACION DEL CLIENTE (ej, nombre, edad etc)(para hacer esto se debe abrir el archivo de clientes.dat)
					// ===================================
					
					/*printf("\tID: ");
					puts(regi.apeynom);
					
					printf("\tNRO DE FACTURA   : %d", regi.nroFactura);
					
					printf("\n\tIMPORTE          : $%.2f", regi.montoFactura);
			    	
			    	printf("\n\tTIPO DE VENTA  	 : ");
			        	
						if(regi.formaVenta == 1)
							printf("CONTADO");
			    		if(regi.formaVenta == 2)
			   				printf("CREDITO");
			   	
					printf("\n\tFECHA DE VENTA 	 : %d/%d/%d", regi.fecha.dia, regi.fecha.mes, regi.fecha.anio);
					if (regi.borrado == false){
						printf("\n\tESTADO           : ACTIVO");
					}else{
						printf("\n\tESTADO           : BORRADO");
					}*/
					printf("\t------------------------------------------------\n\n");
					contador++;
				}
			}
		}
			
		fread(&tu, sizeof(Turnos), 1, archivo);
	}
	
	if(contador == 0){
		printf("\n\n\t\t NO SE REGISTRARON TURNOS EL DIA DE HOY");
	}
	fclose(archivo);
}

int iniciarSecion(char nomProfesional[60], int b){
	
	int valor1, valor2;
	char nomUsuario[10], contraUsuario[10];
	
	printf("\n INGRESE EL NOMBRE DE USUARIO: ");
	_flushall();
	gets(nomUsuario);
	
	printf("\n CONTRASENA: ");
	_flushall();
	gets(contraUsuario);
	

	FILE *archi = fopen("Profesionales.dat", "r+b");
	
	if(archi == NULL){
		printf("\n\t\t***********Error*********** \n");
		exit(EXIT_FAILURE);
	}
	
	rewind(archi);
	fread(&usi, sizeof(Usuarios), 1, archi);
	
	valor1=strcmp(nomUsuario, usi.usuario);
	valor2=strcmp(contraUsuario, usi.contrasena);
	
	while(!feof(archi)){
		//valor1=strcmp(usi.usuario, nomUsuario);
		//valor2=strcmp(usi.contrasena, contraUsuario);
		
		if( (valor2==0) ){
			//(valor1==0) && (valor2==0)
			printf("\nACCESO EXITOSO...!");
			nomProfesional = profe.ApellidoyNombre;
			b=1;	
		}	
		fread(&usi,sizeof(Usuarios),1, archi);
		//fread(&pass,sizeof(char),1,RL);	
 	}
 	
 	if(b == 0){
		printf("\n\t\t*********ERROR*********");
		printf("\nEL USUARIO Y/O LA CONTRASENA ES INCORRECTA\n");
		system("pause");
		system("cls");
		printf("\nINICIE NUVAMENTE LA SESION...! ");
	 }

 	fclose(archi);
 	
 	return b;
		
}

int menu(){
	int opcion=0;
	printf("\033[1;35m");
	gotoxy(30,2);printf(" ========================================================");
	gotoxy(30,3);printf(" |          M O D U L O - E S P A C I O S               |");
	gotoxy(30,4);printf(" ========================================================");
	
	printf("\033[0;33m");
	gotoxy(30,6);printf(" _________________________________________________________");
	gotoxy(30,7);printf("  1- INICIAR SESION     ");
	gotoxy(30,8);printf(" _________________________________________________________");
	gotoxy(30,9);printf("  2- VISUALIZAR LISTA DE ESPERA DE TURNOS (informe)     ");
	gotoxy(30,10);printf(" ________________________________________________________");
	gotoxy(30,11);printf("  3- REGISTRAR EVOLUCION DEL TRATAMIENTO      ");
	gotoxy(30,12);printf(" ________________________________________________________");
	gotoxy(30,13);printf("  4- CERRAR LA APLICACION                  ");

	
	gotoxy(44,15);printf("-----------------------");
	gotoxy(44,16); printf("    OPCION: ");
	scanf("%d", &opcion);
	
	printf("\033[0m");
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
