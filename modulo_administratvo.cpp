/*                       Modulo Administracion:

 La gerencia del centro est�tico es la encargada de realizar la generaci�n 
(rergistraci�n) de los nuevos profesionales que trabajan en el establecimiento,
as� como tambi�n de los empleados recepcionistas que realizan la registraci�n 
de los turnos y clientes.

 Es el �rea encargada de visualizar las atenciones realizadas por los
profesionales seg�n el mes en curso, en este punto se debe obtener un listado
u informe que indique por profesional cuantas atenciones realizo en el mes 
actual.

 Para incentivar a los Profesionales, la gerencia otorga un bono mensual al 
que haya registrado la mayor cantidad de turnos en ese periodo, por lo tanto,
una necesidad del sistema, es indicar cu�l es el profesional que debe recibir 
el bono*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

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

void registProfesional();
void regUsuarioRecepcionista();
void atencionProfesional();
void rankingProfesionales();

main(){

    system("color 9f");

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
		printf("\n* 1. Registrar Profesional.                                     *");
		printf("\n* 2. Registrar Usuario Recepcionista.                           *");
		printf("\n* 3. Atenciones por Profesional.                                *");
		printf("\n* 4. Ranking de Profesionales por Atenciones.                   *");
		printf("\n* 5. Cerrar la aplicacion.                                      *");
		printf("\n*****************************************************************");
		printf("\nIngrese una opcion: ");
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
	int contDigitos=0, contMayus=0;	
    int contMinusc=0, contMayusc=0, contNumeros=0;
    bool esta=false;
	bool esta2=false;
    int continuar= 0, longitud, longitud2, i=0, j=1;
    

    FILE *RP = fopen("Profesionales.dat", "a+b");

    if(RP == NULL){
		printf("Error al crear el archivo \n");
		
		exit(1);
	}
    
    printf("\t\t\tGENERE UNA CUENTA: ");
    printf("\n\t\t\t-----------------");
    printf("\n\n\t\tINGRESE LOS DATOS PERSONALES DEL PROFESIONAL: ");
    printf("\n\t\t--------------------------------------------");

    do{
        printf("\n\nINGRESE NOMBRE Y APELLIDO DEL PROFESIONAL: ");
        _flushall();
		gets(profe.ApellidoyNombre);

        printf("\nINGRESE NUMERO DE MATRICULA: ");
		scanf("%d", &profe.IdProfesional);

        printf("\nINGRESE NUMERO DE DNI: ");
        scanf("%d", &profe.Dni);
        
        printf("\nINGRESE EL NUMERO DE TELEFENO: ");
        scanf("%d", &profe.Telefono);
        
        system("cls");
        
        printf("\n\t\tINGRESE USUARIO Y CONTRASENA PARA SU NUEVA CREDENCIAL:");
        printf("\n\t\t------------------------------------------------------");
        
        printf("\n\nINGRESE NOMBRE DE USUARIO: (minimo 6 caracteres y maximo 10 caracteres, la primera letra minuscula, al menos dos letras mayusculas y tres numeros como maximo): ");
        
       
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
	
		if(esta==true){
			printf("\nSU USUARIO SE CREO CON EXITO...!");
		}
	
	 // =========================
	
	
        printf("\n\nINGRESE CONTRASENA (debe tener entre 6 y 32 cacteres, al menos una letra mayuscula, una letra minuscula, un numero, no podra contener nigun caracter de puntuacion, ni acentos, ni espacios, no debera tener mas de 3 caracteres numericos consecutivos, ni debe tener dos caracteres consecutivos que refieran a letras alfabeticamente consecutivas ascendentemente.): ");
	    
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
			printf("\nSU CONTRASE�A SE CREO CON EXITO...!");
		}
    	fseek(RP, 0, SEEK_END);
    	fwrite(&profe,sizeof(Profesionales),1,RP);
        fwrite(&usi,sizeof(Usuarios),1,RP);
        
        printf("\n");
        //system("pause");
        //system("cls");



        printf("\nDESEA CONTINUAR INGRESANDO PROFESIONALES...?\n\nPRESIONE 1 PARA SI Y 0 PARA NO: ");
		scanf("%d", &continuar);

        system("pause");
        system("cls");

    }while(continuar == 1);
	
	
    
    fclose(RP);
    
    getch();
}
/*---------------------------------------------------------------------------------------------------*/
void regUsuarioRecepcionista(){
	
	system("cls");
	system("color 6c");
	
	int continuar= 0;
	
	RL= fopen("Recepcionistas.dat", "ab");

    if(RL == NULL){
		
		printf("Error al crear el archivo \n");
		exit(EXIT_FAILURE);
	}
	
	printf("*******************************");
	printf("\n*\tREGISTRESE:           *");
	printf("\n*\t----------            *");
	printf("\n*******************************");
	
	do{
		printf("\n\nINGRESE NOMBRE Y APELLIDO: ");
		_flushall();
		gets(usi.ApeyNom);
		
		printf("\n\nINGRESE NOMBRE DE USUARIO: ");
		gets(usi.usuario);
		
		printf("\n\nINGRESE CONTRASENA: ");
		gets(usi.contrasena);
		
		fwrite(&usi,sizeof(Usuarios),1,RL);
		
		printf("\n");
        
        system("pause");
        system("cls");

        printf("\nDESEA CONTINUAR INGRESANDO RECEPCIONISTAS...?\n\nPRESIONE 1 PARA SI Y 0 PARA NO: ");
		scanf("%d", &continuar);

        system("pause");
		system("cls");

	}while(continuar==1);
	
	fclose(RL);
	
	getch();	
}
/*---------------------------------------------------------------------------------------*/
void atencionProfesional(){
	
	system("cls");
	system("color 46");
	
	int contarAtenciones=0;
	
	TR= fopen("Turnos.dat", "rb");
	RP= fopen("Profesionales.dat", "rb");
	
	rewind(TR);
	rewind(RP);
	
	fread(&tu, sizeof(Turnos), 1, TR);
	fread(&profe, sizeof(Profesionales), 1, RP);
	
	while(!feof(TR) && !feof(RP)){
		
		if(tu.Fech.D >= 1 && tu.Fech.D <=31)
		
			contarAtenciones= tu.Fech.D + 1;
		
		printf("\nEL PROFESIONAL %s TUVO %d ATENCIONES EN EL MES ACTUAL", profe.ApellidoyNombre, contarAtenciones);
			
		fread(&tu, sizeof(Turnos), 1, TR);
		fread(&profe, sizeof(Profesionales), 1, RP);
	}
	
	fclose(TR);
	fclose(RP);
	
	getch();
}
/*-------------------------------------------------------------------------------*/
void rankingProfesionales(){
	
	system("cls");
	system("color 87");
	
	int mayor=0, i=0;
	
	TR= fopen("Turnos.dat", "rb");
	RP= fopen("Profesionales.dat", "rb");
	
	rewind(TR);
	rewind(RP);
	
	fread(&tu, sizeof(Turnos), 1, TR);
	fread(&profe, sizeof(Profesionales), 1, RP);
	
	while(!feof(TR) && !feof(RP)){
		
		if(tu.IdProfesional==profe.IdProfesional){
			tu.IdProfesional=i;
			mayor=profe.ApellidoyNombre[i];		
		}
			
		fread(&tu, sizeof(Turnos), 1, TR);
		fread(&profe, sizeof(Profesionales), 1, RP);
		
		break;	
	}
	
	fclose(TR);
	fclose(RP);
	
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n+\tRANKING DE PROFESIONALES QUE MAS ATENCIONES REALIZARON       +");
	printf("\n+\t------------------------------------------------------       +");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	
	RP= fopen("Profesionales.dat", "rb");
	
	rewind(RP);
	fread(&profe, sizeof(Profesionales), 1, RP);
	
	while(!feof(TR) && !feof(RP)){
		printf("\n\n%d). %s", i+1, profe.ApellidoyNombre);
		fread(&profe, sizeof(Profesionales), 1, RP);
		
		break;
	}
	fclose(RP);
	
	getch();
}