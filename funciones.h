#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>

typedef struct{
	int mn,mx;
}Range;

Range nums = {'0','9'};
Range letras = {'a','z'};


void scanRange(char *cad, int t, Range range){
	int x=0;
	while(1){
		char aux;
		char c=getch();
		aux=tolower(c);
		if(aux>=range.mn && aux<=range.mx && x<t){
			*(cad + x)=c;
			printf("%c",c);
			x++;
		}else if(aux==8 && x>0){
			x--;
			printf("\b \b");
			*(cad + x)=' ';
		}else if(aux==13 and x>0){
			*(cad + x)='\0';
			printf("\n");
			break;	
		}
	}
}


void scanInt(int *retVal){
	int t=9;
	char num[t];
	int x=0;
	while(1){
		char c =getch();
		if(c>='0' && c<='9' && x<t){
			printf("%c",c);
			num[x]=c;
			x++;
		}else if(c==8 && x>0){
			x--;
			printf("\b \b");
			num[x]=' ';
		}else if(c==13 and x>0) {
			//num[x]='\0';
			*retVal = atoi(num);
			printf("\n");
			break;	
		}
		
	}
}

void scanInt2(int *retVal){
	int t=9;
	char num[t];
	int x=0;
	while(1){
		char c =getch();
		if(c>='0' && c<='9' && x<t){
			printf("%c",c);
			num[x]=c;
			x++;
		}else if(c==8 && x>0){
			x--;
			printf("\b \b");
			num[x]=' ';
		}else if(c==13) {
			//num[x]='\0';
			*retVal = atoi(num);
			printf("\n");
			break;	
		}
		
	}
}



void scanAlpha(char *cad,int t){
	
	int x=0;
	while(1){
		char c=getch();
		if((c>='a' && c<='z' || c>='A' && c<='Z' || c==' ' || GetAsyncKeyState(192)==-32767) && x<t){
			*(cad + x)=c;
			printf("%c",c);
			x++;
		}else if(c==8 && x>0){
			x--;
			printf("\b \b");
			*(cad + x)=' ';
		}else if(c==13 and x>0){
			*(cad + x)='\0';
			printf("\n");
			break;		
		}
	}
}

void valifec(char *pfecha)
{	int dia=0, mes=0, anio=0, x=0, c=0, d=0, m=0, a=0, fec=0, bi=0;
	char diac[2], mesc[2], anioc[4];
	do
	{ 	x=d=m=a=0;
		strcpy(diac,"  ");
		strcpy(mesc,"  ");
		strcpy(anioc,"    ");
		do
		{	c=getch();
	    	if(c>=48 && c<=57)
    		{ 	printf("%c",c);
    			if(x<2)
    			{	diac[d]=c;
        			d++;
        		}
				else if (x<5)
				{	mesc[m]=c;
					m++;
				}
				else
				{	anioc[a]=c;
					a++;
				}
				*(pfecha+x)=c;
    	    	x++;
	    	}
	    	if(x==2 || x==5)
	    	{	printf("/");
    	    	*(pfecha+x)='/';
        		x++;        
        	} 
			if(c==8 && x>0)
	    	{	x--;
	    		if(x==2)
	    		{	printf("\b\b  \b\b");
	    			*(pfecha+x)=' ';
	    			x--;
	    			*(pfecha+x)=' ';
	    			d--;
	    		}
	    		else if(x<2)
	    		{	printf("\b \b");
					*(pfecha+x)=' ';
					d--;
				}
	    		else if(x==5)
	    		{	printf("\b\b  \b\b");
	    			*(pfecha+x)=' ';
	    			x--;
					*(pfecha+x)=' ';
					m--;
	    		}
	    		else if(x<5)
	    		{	printf("\b \b");
					*(pfecha+x)=' ';
					m--;
				}
	    		else if(x>5)
	    		{	printf("\b \b");
	    			*(pfecha+x)=' ';
	    			a--;
	    		}
    		}            
		}while(x<10);
		dia=atoi(diac);
		mes=atoi(mesc);
		anio=atoi(anioc);
		bi=0;
		if(anio%4==0 && (anio%100!=0 || anio%400==0))
			bi++;
		if(dia<=31 && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia<=30 && (mes==4 || mes==6 || mes==9 || mes==11) && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia<=28 && mes==2 && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia==29 && mes==2 && anio>=1900 && anio<=2050 && bi==1)
			fec=1;
		else
			for(int y=1;y<=10;y++)
				printf("\b \b");
	}while(fec!=1);
}


