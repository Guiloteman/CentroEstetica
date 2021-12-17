/*La gerencia del centro estético es la encargada de realizar la generación (rergistración) de los
nuevos profesionales que trabajan en el establecimiento, así como también de los empleados
recepcionistas que realizan la registración de los turnos y clientes.
 Es el área encargada de visualizar las atenciones realizadas por los profesionales según el mes
en curso, en este punto se debe obtener un listado u informe que indique por profesional
cuantas atenciones realizo en el mes actual.
 Para incentivar a los Profesionales, la gerencia otorga un bono mensual al que haya
registrado la mayor cantidad de turnos en ese periodo, por lo tanto, una necesidad del
sistema, es indicar cuál es el profesional que debe recibir el bono*/

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

FILE *CL;

char edad, dni[10];

Usuarios usi[100];

Profesionales profe[100];

Clientes cli[100];

//Prototipos de funciones.

void regiPro();

void regiCli();

main(){

    system("color 9f");

    int opc;

    printf("**********************************************************************");
    printf("\n*\tBienvenido al Sistema del Centro de Estetica Misa            *");
    printf("\n**********************************************************************");
    printf("\n");
	
	do{
		printf("\n-----------------------------------------------------------------");
		printf("\n-                  Menu de Opciones                             -");
		printf("\n-----------------------------------------------------------------");
		printf("\n- 1. Registrar Profesional.                                     -");
		printf("\n- 2. Registrar Usuario Recepcionista.                           -");
		printf("\n- 3. Atenciones por Profesional.                                -");
		printf("\n- 4. Ranking de Profesionales por Atenciones.                   -");
		printf("\n- 5. Cerrar la aplicacion.                                      -");
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
			
			regiCli();
			
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
	
	system("cls");

    system("color 1d");

    int continuar= 0, longitud, longitud2, i=0;

    RP= fopen("Profesionales.dat", "r+b");

    if(RP == NULL){
		
		printf("Error al crear el archivo \n");
		
		exit(EXIT_FAILURE);
		
	}
    
    printf("\t\t\tGENERE UNA CUENTA: ");
    
    printf("\n\t\t\t-----------------");

    printf("\n\n\t\tINGRESE LOS DATOS PERSONALES DEL PROFESIONAL: ");
    
    printf("\n\t\t--------------------------------------------");

    do{
    	
    	_flushall();

        printf("\n\nINGRESE NOMBRE Y APELLIDO DEL PROFESIONAL: ");

        gets(profe[i].ApellidoyNombre);

        printf("\n\nINGRESE NUMERO DE MATRICULA: ");

        scanf("%d", &profe[i].IdProfesional);

        printf("\n\nINGRESE NUMERO DE D.N.I.: ");

        scanf("%d", &profe[i].Dni);
        
        printf("\n\nINGRESE EL NUMERO DE TELEFENO: ");
        
        scanf("%d", &profe[i].Telefono);
        
        system("cls");
        
        printf("\n\t\tINGRESE USUARIO Y CONTRASENA PARA SU NUEVA CREDENCIAL:");
        
        printf("\n\t\t------------------------------------------------------");
        
        printf("\n\nINGRESE NOMBRE DE USUARIO (minimo 6 caracteres y maximo 10 caracteres, la primera letra minuscula, al menos tres letras mayusculas y tres numeros): ");
        
        _flushall();
        
        gets(usi[i].usuario);
        
        longitud = strlen(usi[i].usuario);
        
        
           
         	
        	if(longitud >= 6 && longitud <=10){
        	
        		if(usi[i].usuario[0]>=97 && usi[i].usuario[0]<=120){
        		
        			if(usi[i].usuario[i]>=65 && usi[i].usuario[i]<=90){
        			
        				if(usi[i].usuario[i]>=48 && usi[i].usuario[i]<=57){
        				
        					printf("\nSU USUARIO SE CREO CON EXITO...!");
        				
        				}else{
        				
        					printf("ERROR EN LA CONFORMACION DEL USUARIO, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
        				
        				}
        			
        			}else{
        			
        				printf("ERROR EN LA CONFORMACION DEL USUARIO, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
        			
        			}
        		
        		}else{
        		
        			printf("ERROR EN LA CONFORMACION DEL USUARIO, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
        		
        		}
        	
        	}else{
        	
        		printf("ERROR EN LA CONFORMACION DEL USUARIO, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
        	
        	}
        	
    	
        
        
        
        printf("\n\nINGRESE CONTRASENA (debe tener entre 6 y 32 cacteres, al menos una letra mayuscula, una letra minuscula, un numero, no podra contener nigun caracter de puntuacion, ni acentos, ni espacios, no debera tener mas de 3 caracteres numericos consecutivos, ni debe tener dos caracteres consecutivos que refieran a letras alfabeticamente consecutivas ascendentemente.): ");
        
        gets(usi[i].contrasena);
        
        longitud2 = strlen(usi[i].contrasena);
        
        int j=0;
        
        
        	
        	if(longitud2 >= 6 && longitud2 <=32){
        	
        		if(usi[i].contrasena[j]>=97 && usi[i].contrasena[j]<=120){
        		
        			if(usi[i].contrasena[j]>=65 && usi[i].contrasena[j]<=90){
        			
        				if(usi[i].contrasena[j]>=48 && usi[i].contrasena[j]<=50 && usi[i].contrasena[j]>=51 && usi[i].contrasena[j]<=53 && usi[i].contrasena[j]>=54 && usi[i].contrasena[j]<=56 && usi[i].contrasena[j]>=57){
        				
        					if(usi[i].contrasena[j]!=32 && usi[i].contrasena[j]!=46 && usi[i].contrasena[j]!=239 && usi[i].contrasena[j]!=96 && usi[i].contrasena[j]!=44 && usi[i].contrasena[j]!=59 && usi[i].contrasena[j]!=58){
        						
        						printf("SU CONTRASEÑA SE CREO CON EXITO...!");
        	
        					}else{
        						
        						printf("ERROR EN LA CONFORMACION DE LA CONTRASENA, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
        						
        					}
        				
        				}else{
        				
        					printf("ERROR EN LA CONFORMACION DE LA CONTRASENA, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
        				
        				}
        			
        			}else{
        			
        				printf("ERROR EN LA CONFORMACION DE LA CONTRASENA, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
        			
        			}
        		
        		}else{
        		
        			printf("ERROR EN LA CONFORMACION DE LA CONTRASENA, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
        		
        		}
        	
        	}else{
        	
        		printf("ERROR EN LA CONFORMACION DE LA CONTRASENA, NO CUMPLE CON LAS CONDICONES ESTABLECIDAS.");
        	
        	}
        	
        fwrite(&profe,sizeof(Profesionales),1,RP);
        
        fwrite(&usi,sizeof(Usuarios),1,RP);
        
        printf("\n");
        
        system("pause");
        
        system("cls");



        printf("\DESEA CONTINUAR INGRESANDO PROFESIONALES...?\n\nPRESIONE 1 PARA SI Y 0 PARA NO: ");

        scanf("%d", &continuar);

        system("pause");

        system("cls");

    }while(continuar== 1);









    fclose(RP);

}
/*-------------------------------------------------------------------------------------------------*/
void regiCli(){
	
	system("cls");

    system("color 5c");

    int continuar= 0, i=0;

    CL= fopen("Clientes.dat", "r+b");

    if(RP == NULL){
		
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
        
        gets(cli[i].AyN);

        printf("\n\nINGRESE DOMICILIO: ");

        gets(cli[i].Domicilio);

        printf("\n\nINGRESE NUMERO DE D.N.I.: ");

        scanf("%d", &cli[i].dniCliente);
        
        printf("\n\nINGRESE LOCALIDAD: ");
        
        _flushall();
        
        gets(cli[i].localidad);
        
        printf("\nINGRESE FECHA DE NACIMIENTO: ");
        
		printf("\n\tDia: ");
		
		scanf("%d", &cli[i].fechadeNacimiento.dia);
		
		printf("\tMes: ");
		
		scanf("%d", &cli[i].fechadeNacimiento.mes);
		
		do{
			
			printf("\tAnio: ");
			
			scanf("%d", &cli[i].fechadeNacimiento.anio);
			
		}while(cli[i].fechadeNacimiento.anio<1000);
		
		printf("\nINGRESE LA MASA DE SU CUERPO (Kg): ");
		
		scanf("%f", &cli[i].peso);
		
		printf("\nINGRESE EL NUMERO DE TELEFONO: ");
		
		scanf("%d", &cli[i].tel);
        
        system("cls");
        
        printf("\n\t\tINGRESE USUARIO Y CONTRASENA PARA SU NUEVA CREDENCIAL:");
        
        printf("\n\t\t------------------------------------------------------");
        
        printf("\n\nINGRESE NOMBRE DE USUARIO (minimo 6 caracteres y maximo 10 caracteres, la primera letra minuscula, al menos tres letras mayusculas y tres numeros): ");
        
        _flushall();
        
        gets(usi[i].usuario);
        
        printf("\n\nINGRESE CONTRASENA (debe tener entre 6 y 32 cacteres, al menos una letra mayuscula, una letra minuscula, un numero, no podra contener nigun caracter de puntuacion, ni acentos, ni espacios, no debera tener mas de 3 caracteres numericos consecutivos, ni debe tener dos caracteres consecutivos que refieran a letras alfabeticamente consecutivas ascendentemente.): ");
        
        gets(usi[i].contrasena);
        
        fwrite(&cli,sizeof(Clientes),1,RP);
        
        fwrite(&usi,sizeof(Usuarios),1,RP);
        
        printf("\n");
        
        system("pause");
        
        system("cls");



        printf("\DESEA CONTINUAR INGRESANDO PROFESIONALES...?\n\nPRESIONE 1 PARA SI Y 0 PARA NO: ");

        scanf("%d", &continuar);

        system("pause");

        system("cls");

    }while(continuar== 1);









    fclose(RP);

	
	
}
