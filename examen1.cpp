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

Articulo invent[10];

int t =10;

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
		fwrite(&invent,sizeof(Articulo),10,arc);
		fclose(arc);
	}
}


void agregar(){
	for(int x=0; x)
}


int mainMenu(){
	while(1){
		int op;
		system("cls");
		puts("1)Agregar");
		puts("1)Eliminar");
		puts("1)Consultar");
		puts("1)Ordenar");
		puts("1)Salir");
		puts("---------------------------------------");
		printf("Ingrese una opcion: ");
		scanInt(&op);
		system("cls");
		switch(op){
			case 1:{
				
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

