/*                       Modulo Administracion:

 La gerencia del centro estético es la encargada de realizar la generación 
(rergistración) de los nuevos profesionales que trabajan en el establecimiento,
así como también de los empleados recepcionistas que realizan la registración 
de los turnos y clientes.

 Es el área encargada de visualizar las atenciones realizadas por los
profesionales según el mes en curso, en este punto se debe obtener un listado
u informe que indique por profesional cuantas atenciones realizo en el mes 
actual.

 Para incentivar a los Profesionales, la gerencia otorga un bono mensual al 
que haya registrado la mayor cantidad de turnos en ese periodo, por lo tanto,
una necesidad del sistema, es indicar cuál es el profesional que debe recibir 
el bono*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include <windows.h>

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

struct RegistroDeAtenciones{
	int IdProfesional;
	char ApellidoyNombre[60];
	int atenciones;
	fecha fechadeatencion;
};

//Variables Globales.

FILE *RP;
FILE *RL;
FILE *TR;

char edad, dni[10];

Usuarios usi;
Profesionales profe;
Turnos tu;

//Prototipos de funciones.

void gotoxy(int x, int y);
void registProfesional();
void regUsuarioRecepcionista();
void atencionProfesional();
void rankingProfesionales();
int meses();

main(){

	system("mode con: cols=140 lines=40");
    int opc;
	
	do{
		system("color b0");
		
		gotoxy(38,5);printf("*****************************************************************");
		gotoxy(38,6);printf("*          M O D U L O - A D M I N I S T R A C I O N            *");
		gotoxy(38,7);printf("*          -----------   ---------------------------            *");
		gotoxy(38,8);printf("*****************************************************************");
		gotoxy(38,10);printf("*       1. REGISTRAR PROFESIONAL                                *");
		gotoxy(38,11);printf("*       2. REGISTRAR USUARIO RECEPCIONISTA                      *");
		gotoxy(38,12);printf("*       3. ATENCIONES POR PROFESIONAL                           *");
		gotoxy(38,13);printf("*       4. RANKING DE PROFESIONALES POR ATENCIONES              *");
		gotoxy(38,14);printf("*       5. CERRAR LA APLICACION                                 *");
		gotoxy(38,16);printf("*****************************************************************");
		gotoxy(38,18);printf("  OPCION: ");
		scanf("%d", &opc);
		
		switch(opc){

			case 1:
				printf("\n");
	            registProfesional();	
				system("PAUSE");
				break;

			case 2:
				printf("\n");
				regUsuarioRecepcionista();
				system("PAUSE");
				break;
			
			case 3:
				printf("\n");
				atencionProfesional();

				break;
			
			case 4:
				printf("\n");
				rankingProfesionales();
				printf("\n");
				system("PAUSE");
				break;
			
			case 5:
				printf("\n");
				printf("CERRAR APLICACION...!");
				printf("\n");
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
void registProfesional(){
	
	system("cls");
	system("color f0");
    
    bool esta=false;
	bool esta2=false;
	int contDigitos=0, contMayus=0, cont=0;
	int contMinusc=0, contMayusc=0, contNumeros=0, contNumCons=0, contAlfabCons=0;
    int continuar= 0, longitud, longitud2, j=1;
    char aux[10];
    

    FILE *RP = fopen("Profesionales.dat", "a+b");

    if(RP == NULL){
		printf("Error al crear el archivo \n");
		
		exit(1);
	}
    
    printf("\t\t\t\t\t\t  GENERE UNA CUENTA ");
    printf("\n\t\t\t\t\t\t  -----------------");
    printf("\n\n\t\t\t\t\tINGRESE LOS DATOS PERSONALES DEL PROFESIONAL: ");
    printf("\n\t\t\t\t\t--------------------------------------------");


        printf("\n\n\t\t           NOMBRE Y APELLIDO DEL PROFESIONAL: ");
        _flushall();
		gets(profe.ApellidoyNombre);

        printf("\n\t\t             NUMERO DE MATRICULA: ");
		scanf("%d", &profe.IdProfesional);

        printf("\n\t\t             NUMERO DE DNI: ");
        scanf("%d", &profe.Dni);
        
        printf("\n\t\t             NUMERO DE TELEFENO: ");
        scanf("%d", &profe.Telefono);
        
        
        system("cls");
        
        printf("\n\t\tINGRESE USUARIO Y CONTRASENA PARA SU NUEVA CREDENCIAL:");
        printf("\n\t\t------------------------------------------------------");
        
        printf("\n\nINGRESE NOMBRE DE USUARIO (minimo 6 caracteres y maximo 10 caracteres, la primera letra minuscula,");
		printf("\n                              al menos dos letras mayusculas y tres numeros como maximo)");
        
        printf("\n -> ");
       
       	do{
			contDigitos=0, contMayus=0, cont=0;
				
			_flushall();
			gets(usi.usuario);
			
			longitud = strlen(usi.usuario);
			
			if(longitud>=6 && longitud<=10){
			
				for(int i=0; i<longitud; i++){
					
					if(i==0){
						
						if(usi.usuario[i]>=97  && usi.usuario[i]<=122){		//Codigo ASCII de letras en minuscula
							cont++;
						}
					}else{
						
						if(usi.usuario[i]>=65 && usi.usuario[i]<=90){    //Codigo ASCII de letras en mayuscula
							contMayus++;					
					    }
					    
					    if(usi.usuario[i]>=33 && usi.usuario[i]<=57){
							contDigitos = contDigitos + 1;	
				        }
					}
				}
				
	
				if(contDigitos < 4 && contMayus >= 2 && cont==1){
					esta = true;
				}else{
					printf("\n VUELVA A INGRESAR OTRO NOMBRE DE USUARIO: ");
				}
				
			}else{
				printf("\n NOMBRE DE USUARIO MUY CORTO - LARGO");
				printf("\n  INGRESE OTRO NOMBRE DE USUARIO: ");
			}
			
		}while(esta == false);
	
		if(esta==true){
			printf("\n\t\t\t\t ========================================");
			printf("\n\t\t\t\t |   SU USUARIO SE CREO CON EXITO...!   |");
			printf("\n\t\t\t\t ========================================");
		}
	
	 // =========================
	
	
        printf("\n\nINGRESE CONTRASENA (debe tener entre 6 y 32 cacteres, al menos una letra mayuscula, una letra minuscula, un numero,");
		printf("\n                     no podra contener nigun caracter de puntuacion, ni acentos, ni espacios, no debera tener mas de 3 ");
		printf("\n                     caracteres numericos consecutivos, ni debe tener 2 caracteres consecutivos que refieran a letras ");
		printf("\n                                         alfabeticamente consecutivas ascendentemente.)");
	    
	    printf("\n -> ");
	    do{
	    	contMinusc=0, contMayusc=0, contNumeros=0, contNumCons=0, contAlfabCons=0, j=1; 
	    	
	    	_flushall();
		    gets(usi.contrasena);
		    
		    strcpy(aux, usi.contrasena);
		    strlwr(aux);
	        
	        longitud2 = strlen(usi.contrasena);
        
        	if(longitud2>=6 && longitud2<=32){
		
				for(int k=0; k<longitud2; k++){
					//printf("%c  - %d\n", cadFrase[i], cadFrase[i]);
					
					if(usi.contrasena[k]>=97  && usi.contrasena[k]<=122){		//Codigo ASCII de letras en minuscula
						contMinusc++;
						
							if(aux[k] == aux[k+1] - 1){
								contAlfabCons++; // contador de caracteres consecutivos de letras alfabéticamente 
							}
					}
					
					if(usi.contrasena[k]>=65 && usi.contrasena[k]<=90){    //Codigo ASCII de letras en mayuscula
						contMayusc++;		
				    }
				    
				    if(usi.contrasena[k]>=48 && usi.contrasena[k]<=57){
						contNumeros++;
						
							if(usi.contrasena[k] == usi.contrasena[k+1] - 1){
								contNumCons++; // contador de Numeros consecutivos
							}
					}
					
					if(usi.contrasena[k]!=32 && usi.contrasena[k]!=44 && usi.contrasena[k]!=46 && usi.contrasena[k]!=96 && usi.contrasena[k]!=59 && usi.contrasena[k]!=58){
						j = 0;
					}
					
				}
			
				if(contMinusc >=1 && contMayusc >= 1 && contNumeros >= 1 && j == 0 && contNumCons <= 2 && contAlfabCons == 0){
					esta2 = true;
				}else{
					printf("\n ERROR EN LA CONFORMACION DE LA CONTRASENA, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
					printf("\n  INGRESE OTRA CONTRASENA: ");
				}
					
			}else{
				printf("\n CONTRASENA MUY CORTO - LARGO");
				printf("\n  INGRESE OTRA CONTRASENA: ");
			}
        
   		}while(esta2 == false);
   		
   		if(esta2==true){
   			printf("\n\t\t\t\t ========================================");
			printf("\n\t\t\t\t | SU CONTRASENA SE CREO CON EXITO...!  |");
			printf("\n\t\t\t\t ========================================");

		}
		
    	
    	fwrite(&profe,sizeof(Profesionales),1,RP);
        fwrite(&usi,sizeof(Usuarios),1,RP);
        
        fseek(RP, 2, SEEK_END);
        
        printf("\n");


        system("pause");
        system("cls");

    
    fclose(RP);
    
    getch();
}
/*---------------------------------------------------------------------------------------------------*/
void regUsuarioRecepcionista(){
	
	system("cls");

	int longitud, longitud2;
    char aux[10];
	int contMinusc1=0, contMayusc1=0, contNumeros1=0, contNumCons1=0, contAlfabCons1=0, j1=1; 
	int contDigitos1=0, contMayus1=0, cont1=0;
	bool esta=false;
	bool esta2=false;
	
	
	RL= fopen("Recepcionistas.dat", "ab");

    if(RL == NULL){
		
		printf("Error al crear el archivo \n");
		exit(EXIT_FAILURE);
	}
	
	gotoxy(32,3);printf("*****************************************************");
	gotoxy(32,4);printf("*          REGISTRAR USUARIO RECEPCIONISTA          *");
	gotoxy(32,5);printf("*          --------- ------- -------------          *");
	gotoxy(32,6);printf("*****************************************************");
	
	
		gotoxy(34,8);printf(" INGRESE ");
		gotoxy(34,9);printf(" NOMBRE Y APELLIDO: ");
		_flushall();
		gets(usi.ApeyNom);
		
		printf("\n\n INGRESE NOMBRE DE USUARIO (minimo 6 caracteres y maximo 10 caracteres, la primera letra minuscula,");
		printf("\n                              al menos dos letras mayusculas y tres numeros como maximo)");
        
        printf("\n -> ");
       
       	do{
			contDigitos1=0, contMayus1=0, cont1=0;
				
			_flushall();
			gets(usi.usuario);
			
			longitud = strlen(usi.usuario);
			
			if(longitud>=6 && longitud<=10){
			
				for(int i=0; i<longitud; i++){
					
					if(i==0){
						
						if(usi.usuario[i]>=97  && usi.usuario[i]<=122){		//Codigo ASCII de letras en minuscula
							cont1++;
						}
					}else{
						
						if(usi.usuario[i]>=65 && usi.usuario[i]<=90){    //Codigo ASCII de letras en mayuscula
							contMayus1++;					
					    }
					    
					    if(usi.usuario[i]>=33 && usi.usuario[i]<=57){
							contDigitos1 = contDigitos1 + 1;	
				        }
					}
				}
				
				if(contDigitos1 < 4 && contMayus1 >= 2 && cont1==1){
					esta = true;
				}else{
					printf("\n VUELVA A INGRESAR OTRO NOMBRE DE USUARIO: ");
				}
				
			}else{
				printf("\n NOMBRE DE USUARIO MUY CORTO - LARGO");
				printf("\n  INGRESE OTRO NOMBRE DE USUARIO: ");
			}
			
		}while(esta == false);
	
		if(esta==true){
			printf("\n\t\t\t\t ========================================");
			printf("\n\t\t\t\t |   SU USUARIO SE CREO CON EXITO...!   |");
			printf("\n\t\t\t\t ========================================");
		}
	
	 // =========================
	
	
        printf("\n\n INGRESE CONTRASENA (debe tener entre 6 y 32 cacteres, al menos una letra mayuscula, una letra minuscula,");
		printf("\n                     un numero, nigun caracter de puntuacion, ni acentos, ni espacios, no mas de 3 caracteres,");
		printf("\n                     numericos consecutivos, ni debe tener 2 caracteres consecutivos que refieran a letras ");
		printf("\n                                      alfabeticamente consecutivas ascendentemente.)");
	    
	    printf("\n -> ");
	    do{
	    	contMinusc1=0, contMayusc1=0, contNumeros1=0, contNumCons1=0, contAlfabCons1=0, j1=1; 
	    	
	    	_flushall();
		    gets(usi.contrasena);
		    
		    strcpy(aux, usi.contrasena);
		    strlwr(aux);
	        
	        longitud2 = strlen(usi.contrasena);
        
        	if(longitud2>=6 && longitud2<=32){
		
				for(int k=0; k<longitud2; k++){
					
					if(usi.contrasena[k]>=97  && usi.contrasena[k]<=122){		//Codigo ASCII de letras en minuscula
						contMinusc1++;
						
							if(aux[k] == aux[k+1] - 1){
								contAlfabCons1++; // contador de caracteres consecutivos de letras alfabéticamente 
							}
					}
					
					if(usi.contrasena[k]>=65 && usi.contrasena[k]<=90){    //Codigo ASCII de letras en mayuscula
						contMayusc1++;		
				    }
				    
				    if(usi.contrasena[k]>=48 && usi.contrasena[k]<=57){
						contNumeros1++;
						
							if(usi.contrasena[k] == usi.contrasena[k+1] - 1){
								contNumCons1++; // contador de Numeros consecutivos
							}
					}
					
					if(usi.contrasena[k]!=32 && usi.contrasena[k]!=44 && usi.contrasena[k]!=46 && usi.contrasena[k]!=96 && usi.contrasena[k]!=59 && usi.contrasena[k]!=58){
						j1 = 0;
					}
					
				}
			
				if(contMinusc1 >=1 && contMayusc1 >= 1 && contNumeros1 >= 1 && j1 == 0 && contNumCons1 <= 2 && contAlfabCons1 == 0){
					esta2 = true;
				}else{
					printf("\n ERROR EN LA CONFORMACION DE LA CONTRASENA, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
					printf("\n  INGRESE OTRA CONTRASENA: ");
				}
					
			}else{
				printf("\n CONTRASENA MUY CORTO - LARGO");
				printf("\n  INGRESE OTRA CONTRASENA: ");
			}
        
   		}while(esta2 == false);
   		
   		if(esta2==true){
   			printf("\n\t\t\t\t ========================================");
			printf("\n\t\t\t\t | SU CONTRASENA SE CREO CON EXITO...!  |");
			printf("\n\t\t\t\t ========================================");
		}
		
        

		fwrite(&usi,sizeof(Usuarios),1,RL);
		
		printf("\n");

        system("pause");
		system("cls");

	
	fclose(RL);
	
	getch();	
}
/*---------------------------------------------------------------------------------------*/
void atencionProfesional(){
	
	system("cls");

	
	int contarAtenciones=0, mesActual, idProfesional=0;
	char apeynom[60];
	
	TR= fopen("Turnos.dat", "rb");
	RP= fopen("Profesionales.dat", "r+b");
	
	printf("\n   = INGRESE MES ACTUAL PARA MOSTRAR NRO. ATENCIONES = \n ");
	mesActual = meses();
	system("cls");
	gotoxy(45,8);printf(" INGRESE EL ID DEL PROFESIONAL: ");
	scanf("%d", &idProfesional);
	
	printf("\n\n");
	
	
	rewind(TR);
	rewind(RP);
	
	fread(&tu, sizeof(tu), 1, TR);
	
	while(!feof(TR)){
		
		if(tu.Fech.M == mesActual && tu.borrado == true && tu.IdProfesional == idProfesional){
		
			contarAtenciones++;
		}
			
		fread(&tu, sizeof(tu), 1, TR);
	}
	

	gotoxy(32,13);printf(" ------------------------------------------------------------------");
	gotoxy(32,14);printf(" |       EL PROFESIONAL TUVO %d ATENCIONES EN EL MES ACTUAL        |",contarAtenciones);
	gotoxy(32,15);printf(" ------------------------------------------------------------------");
	
	fclose(TR);
	fclose(RP);
	
	getch();
}
/*-------------------------------------------------------------------------------*/
void rankingProfesionales(){
	
	system("cls");
	
	int mayor=0, i=0;
	int mes=0, nroderegi, nrodeatenciones, bandera;
	RegistroDeAtenciones vectordeatenciones[50], aux; 
	
	TR= fopen("Turnos.dat", "a+b");
	RP= fopen("Profesionales.dat", "a+b");
	
	if(TR==NULL|| RP==NULL){
		printf("*Error en el sistema-Archivos no cargados*"); 
		exit(1);
	}
	
	rewind(TR);
	
	printf("INGRESE MES: "); 
	scanf("%d",&mes);
	
	/*Se almacenan los Profesionales en un vector de registro*/
	
	nroderegi=0;
	rewind(RP);
	fread(&profe, sizeof(Profesionales), 1, RP);
	fread(&usi, sizeof(Usuarios), 1, RP);
	while(!feof(RP)){		
				strcpy(vectordeatenciones[nroderegi].ApellidoyNombre, profe.ApellidoyNombre);
				vectordeatenciones[nroderegi].IdProfesional=profe.IdProfesional;
				vectordeatenciones[nroderegi].atenciones=0;
				vectordeatenciones[nroderegi].fechadeatencion.M=mes;
				nroderegi++;
		fread(&profe, sizeof(Profesionales), 1, RP);
		fread(&usi, sizeof(Usuarios), 1, RP);		
	}

	/*Conteo y guardado de las atenciones de cada profesional en el mes*/
	
	rewind(TR);
   for(int i=0; i<nroderegi; i++){ 
	    nrodeatenciones=0;
	   	
	   	fread(&tu, sizeof(Turnos), 1, TR);
		while(!feof(TR)){
	   	 	if(tu.borrado==true && tu.IdProfesional==vectordeatenciones[i].IdProfesional && mes==tu.Fech.M){
	   	 	  	nrodeatenciones++;	 
			}
		fread(&tu, sizeof(Turnos), 1, TR);
		 }
		 rewind(TR);
		 vectordeatenciones[i].atenciones=nrodeatenciones;
   }
   fclose(TR);
   fclose(RP);
	
	
	do{
	   bandera=0;	
	   for(int i=0; i<nroderegi-1;i++){
		   	if(vectordeatenciones[i].atenciones<vectordeatenciones[i+1].atenciones){
		   		aux=vectordeatenciones[i+1];
		   		vectordeatenciones[i+1]=vectordeatenciones[i];
		   		vectordeatenciones[i]=aux;
		   		bandera=1;
			}
	   }
   }while(bandera==1);
   

	gotoxy(31,3);printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	gotoxy(31,4);printf("+\tRANKING DE PROFESIONALES QUE MAS ATENCIONES REALIZARON      +");
	gotoxy(31,5);printf("+\t------------------------------------------------------      +");
	gotoxy(31,6);printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	
	for(int i=0; i<nroderegi; i++){
		printf("\n\n\t\t\t\t - - - - - - - - - -");
   		printf("\n\t\t\t\t    PUESTO NRO. %d",i+1);
   		printf("\n\t\t\t\t - - - - - - - - - -");
   		printf("\n\t\t\t\tPROFESIONAL: %s", vectordeatenciones[i].ApellidoyNombre);
   		printf("\n\t\t\t\tID: %d", vectordeatenciones[i].IdProfesional);
   		printf("\n\t\t\t\tNRO. DE ATENCIONES EN EL MES [%d]: %d\n",mes,vectordeatenciones[i].atenciones);
   }
	
	
	getch();
}

int meses(){
	int opci=0;
	
	printf("\n   1) Enero");
	printf("\n   2) Febrero");
	printf("\n   3) Marzo");
	printf("\n   4) Abril");
	printf("\n   5) Mayo");
	printf("\n   6) Junio");
	printf("\n   7) Julio");
	printf("\n   8) Agosto");
	printf("\n   9) Septiembre");
	printf("\n   10) Octubre");
	printf("\n   11) Noviembre");
	printf("\n   12) Diciembre");
	printf("\n RESPUESTA: ");
	scanf("%d", &opci);
	
	return opci;
}

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}
