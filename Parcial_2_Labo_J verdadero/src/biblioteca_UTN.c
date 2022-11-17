#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError, char minimo,char maximo)
{
    int retorno=-1;
    char buffer;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo){
        printf("%s",mensaje);
        scanf("%c",&buffer);
        if(buffer >= minimo && buffer <= maximo){
        	*pResultado=buffer;
            retorno=0;
        }else{
            printf("%s",mensajeError);

        }
    }
    return retorno;
}
int utn_getDosCaracter(char* pResultado,char* mensaje,char* mensajeError, char charUno,char charDos)
{
    int retorno=-1;
    char buffer;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && charUno!=charDos){
        printf("%s",mensaje);
        scanf("%c",&buffer);
        if(buffer == charUno || buffer == charDos){
			*pResultado=buffer;
			retorno=0;
        }else{
        	printf("%s",mensajeError);
        }
    }
    return retorno;
}
int utn_getEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo)
{
    int retorno=-1,entero;
    char buffer[12];
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo){
		do{
			printf("%s",mensaje);
			fflush(stdin);
			gets(buffer);
			entero=atoi(buffer);
			if(entero >= minimo && entero <= maximo){
				*pResultado=entero;
				retorno=0;
			}else{
				printf("%s",mensajeError);
			}
    	}while(retorno!=0);
    }
    return retorno;
}
int utn_getFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo)
{
	int retorno=-1;
	float flotante;
	char buffer[12];
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo){
    	do{
			printf("%s",mensaje);
			fflush(stdin);
			gets(buffer);
			flotante=atof(buffer);
				if(flotante >= minimo && flotante <= maximo){
					*pResultado=flotante;
					retorno=0;
				}else{
					printf("%s",mensajeError);
				}
    	}while(retorno!=0);
    }
    return retorno;
}
int utn_getCadenaCaracteres(int tamanio,char* buffer,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    if(buffer!=NULL && mensaje!=NULL && mensajeError!=NULL && tamanio>0){
        printf("%s",mensaje);
        fflush(stdin);
        gets(buffer);
        if(strlen(buffer)<=tamanio){
        	retorno=0;
        }else{
        	printf("%s",mensajeError);
        }
    }
    return retorno;
}
int utn_cadenaSoloLetra(char* pResultado)
{
    int i;
    int retorno;
    int numeros=0;
    if(pResultado!=NULL){
        for (i=0;i< strlen(pResultado);i++){
                if(isalpha(*(pResultado+i))==0){
                    numeros++;
                }
            }
        if(numeros>0){
            retorno=0;
            printf("\nINGRESE SOLO LETRAS\n");
        }
        else{
            retorno=1;
        }
    }
    return retorno;
}
int utn_validarAnioBisiesto(int* anio)
{
	int retorno=-1,validar=1904,i;
	if((*anio)>0){
		for(i=0;i<48;i++){
			validar+=4;
			if((*anio)==validar){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int utn_validarFechaIngresada(int* ingreso,int* mes,int* anio)
{
	int retorno=-1,entro=0;

	if((*ingreso)>0){
		if((*ingreso)<=30 && ((*mes)==4 || (*mes)==6 || (*mes)==9 || (*mes)==11)){
			entro=1;
			retorno=0;
		}else if((*ingreso)<=31 && ((*mes)==1 || (*mes)==3 || (*mes)==5 || (*mes)==7 || (*mes)==8 || (*mes)==10 || (*mes)==12)){
			entro=1;
			retorno=0;
		}else if((*ingreso)<=28 && (*mes)==2){
			entro=1;
			retorno=0;
		}else if((*ingreso)<=29 && (*mes)==2 && utn_validarAnioBisiesto(*(&anio))==0){
			entro=1;
			retorno=0;
		}
		if(entro==0){
			printf("\nLA FECHA INGRESADA NO ES VALIDA\n");
		}
	}
	return retorno;
}
void utn_pausaPrograma(void)
{
	printf("\nPRESIONE DOS VECES ENTER PARA CONTINUAR\n");
	while(getchar()!='\n');
	getchar();
}
int utn_getEnteroShort(short* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo)
{
    int retorno=-1,entero;
    char buffer[12];
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo){
		do{
			printf("%s",mensaje);
			fflush(stdin);
			gets(buffer);
			entero=atoi(buffer);
			if(entero >= minimo && entero <= maximo){
				*pResultado=entero;
				retorno=0;
			}else{
				printf("%s",mensajeError);
			}
    	}while(retorno!=0);
    }
    return retorno;
}

