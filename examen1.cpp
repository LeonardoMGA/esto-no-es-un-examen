//Eliminar siempre y cuando existencia es 0
#include"funciones.h"
typedef struct{
	int cod; //unico
	char des[25];//Desc del articulo
	char fecreg[11];//fecha de regitro
	int exi;//existencia del art
	int codpro; //codigo de proveedor
	bool reg;
	
}Articulo;

Articulo invent[10],invent2[10];

int t =10;

void copy(Articulo *dest, Articulo *dir){
	strcpy(dest->des,dir->des);
	strcpy(dest->fecreg,dir->fecreg);
	dest->cod = dir->cod;
	dest->codpro = dir->codpro;
	dest->exi = dir->exi;
	dest->reg = dir->reg;
}

/*
1 agregar  - si codigo es unico
2 eliminar - si existencia es 0;
3 consultar
	1 especific
	2 general
	3 por proveedor
	4 regresar
4 ordernar
	1 por codigo
	2 por fecha de registro
	3 regresar
*/

FILE *arc;
int init(){	
	if((arc=fopen("C:\\archivos\\tienda.txt","a+b"))!=NULL){
		rewind(arc);
		fread(&invent,sizeof(Articulo),10,arc);
		fclose(arc);
		return 1;
	}else {
		puts("Error de fichero :(");
		return 0;
	}
}

void save(){
	
	if((arc=fopen("C:\\archivos\\tienda.txt","w+"))!=NULL){
		for(int x=0;x<t;x++){
			if(invent[x].reg){
				fwrite(&invent[x],sizeof(Articulo),1,arc);
			}	
		}	
		fclose(arc);
	}
}



int agregar(){
	puts("AGREGAR");
	for(int x=0; x<t;x++){
		if(!invent[x].reg){
			int valid;
			int cod;
			int cont=0;
			do{
				printf("codigo: ");
				scanInt(&cod);
				for(int z=0; z<t;z++,cont++){
					if(cod==invent[z].cod){
						puts("El codigo no es valido");
						getch();
						system("cls");
						break;
					}
					
				}		
			}while(cont<10);
		invent[x].cod=cod;
		printf("Descripcion: ");
		scanAlpha(invent[x].des,24);
		printf("Fecha de registro: ");
		valifec(invent[x].fecreg);
		printf("\nExistencia: ");
		scanInt2(&invent[x].exi);
		printf("Codigo de proveedor: ");
		scanInt(&invent[x].codpro);
		invent[x].reg=true;
		save();
		return 1;
		}
	}
	puts("No hay registros disponibles");
	getch();
	return 0;
}

int del(){
	int cod;
	char op;
	puts("ELIMINAR");
	printf("Ingresa un codigo para eliminar: ");
	scanInt(&cod);
	system("cls");
	for(int x =0 ; x<t ; x++){
		if(invent[x].cod == cod and invent[x].exi==0){
			printf("codigo: %d\n",invent[x].codpro);
			printf("descripcion: %s\n",invent[x].des);
			printf("fecha de registro: %s\n",invent[x].fecreg);
			printf("codigo de proveedor: %d\n",invent[x].codpro);
			printf("existencia: %d\n",invent[x].exi);
			puts("------------------------------------------");
			printf("Desea eliminar(y): ");
			op=getch();
			if(tolower(op)=='y'){
				for(int z=x; z<t;z++){
					copy(&invent[z],&invent[z+1]);
				}
				save();
				return 1;
			}else{
					return 0;
				}
		}
			
	}
	puts("No se encontro un registro");
	getch();
	return 0;
	
}

int especifico(){
	int cod;
	puts("ESPECIFICO");
	printf("Ingresa un codigo para consultar: ");
	scanInt(&cod);
	system("cls");
	for(int x =0 ; x<t ; x++){
		if(invent[x].cod == cod){
			printf("codigo: %d\n",invent[x].cod);
			printf("descripcion: %s\n",invent[x].des);
			printf("fecha de registro: %s\n",invent[x].fecreg);
			printf("codigo de proveedor: %d\n",invent[x].codpro);
			printf("existencia: %d\n",invent[x].exi);
			getch();
			return 1;
		}
	}
	puts("No se encontro un registro");
	getch();
	return 0;
		
}

void general(Articulo *invent){
	printf("codigo\tdescripcion\tfecha de registro\tproveedor\texistencia");
	puts("\n-------------------------------------------------------------------------------");
	
	for(int x=0;x<t;x++){
		if(invent[x].reg==true or invent[x].reg!=NULL){
			printf("%d\t",invent[x].cod);
			printf("%s\t\t",invent[x].des);
			printf("%s\t\t",invent[x].fecreg);
			printf("%d\t\t\t",invent[x].codpro);
			printf("%d\t\t",invent[x].exi);
			puts("\n----------------------------------------------------------------------");
		}
	}
	getch();
}

int proveedor(){
	int cod;
	puts("ESPECIFICO");
	printf("Ingresa un codigo de proveedor para consultar: ");
	scanInt(&cod);
	system("cls");
	for(int x =0 ; x<t ; x++){
		if(invent[x].codpro == cod){
			printf("codigo: %d\n",invent[x].codpro);
			printf("descripcion: %s\n",invent[x].des);
			printf("fecha de registro: %s\n",invent[x].fecreg);
			printf("codigo de proveedor: %d\n",invent[x].codpro);
			printf("existencia: %d\n",invent[x].exi);
			puts("---------------------------------------------");
		}
		
	}
	getch();
	return 0;
}

int consultar(){
	int op;
	while(1){
		system("cls");
		puts("1)Especifico");
		puts("2)General");
		puts("3)Proveedor");
		puts("4)Regresar");
		printf("Ingrese una opcion: ");
		scanInt(&op);
		system("cls");
		switch(op){
			case 1:{
				especifico();
				break;
			}
			case 2:{
				general(invent);
				break;
			}
			case 3:{
				proveedor();
				break;
			}
			case 4:{
				return 0;
				break;
			}
		}
		
	}
}


void xfecha(){
	for(int x=0; x<t; x++){
		for(int z=x;z<t && invent2[z].reg;z++){
			if(strcmp(invent2[x].fecreg,invent2[z].fecreg)>0){
				Articulo aux;
				copy(&aux,&invent2[x]);
				copy(&invent2[x],&invent2[z]);
				copy(&invent2[z],&aux);
			}
		}
	}
}

void xCodigo(){
	for(int x=0; x<t; x++){
		for(int z=x;z<t && invent2[z].reg;z++){
			if(invent2[x].cod>invent2[z].cod){
				Articulo aux;
				copy(&aux,&invent2[x]);
				copy(&invent2[x],&invent2[z]);
				copy(&invent2[z],&aux);
			}
		}
	}
}

int ordenar(){
	int op;
	for(int x=0; x<t ; x++)
		copy(&invent2[x],&invent[x]);
	while(1){
		system("cls");
		puts("1)Por codigo");
		puts("2)Por fecha de registro");
		puts("3)Regresar");
		printf("Ingrese una opcion: ");
		scanInt(&op);
		system("cls");
		switch(op){
			case 1:{
				xCodigo();
				break;
			}
			case 2:{
				xfecha();
				break;
			}
			case 3:{
				return 0;
				break;
			}
		}
		general(invent2);
		
	}
}

int mainMenu(){
	while(1){
		int op;
		system("cls");
		puts("1)Agregar");
		puts("2)Eliminar");
		puts("3)Consultar");
		puts("4)Ordenar");
		puts("5)Salir");
		puts("---------------------------------------");
		printf("Ingrese una opcion: ");
		scanInt(&op);
		system("cls");
		switch(op){
			case 1:{
				agregar();
				break;
			}
			case 2: {
				del();
				break;
			}
			case 3: {
				consultar();
				break;
			}
			case 4:{
				ordenar();
				break;
			}
			case 5: {
				return 0;
				break;
			}
			
		}
	}
	
	
}

main(){
	if(init()){
		mainMenu();
	}
}

