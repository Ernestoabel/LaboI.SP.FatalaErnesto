#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria.h"
#include "LinkedList.h"
#include "parser.h"
#include "biblioteca_UTN.h"
#include "salidaDeDatos.h"


int controller_cargarComprasDesdeTexto(LinkedList* pArrayListCompras)
{
	char path[51];
	utn_getCadenaCaracteres(51,path,"\nINGRESE EL NOMBRE DEL ARCHIVO\n","--ERROR--");
	FILE* pComprasFile=fopen(path,"r");
	int retorno=-1;
	if(pComprasFile!=NULL){
		if(parser_eCompraFromText(pComprasFile ,pArrayListCompras)==0){
			printf("\nARCHIVO %s LEIDO CORECTAMENTE\n",path);
			retorno=0;
		}else{
			printf("ERROR AL CARGAR EL ARCHIVO");
		}
	}
	fclose(pComprasFile);
    return retorno;
}
int controller_listarCompras(LinkedList* pArrayListCompras)
{
	int retorno=-1;
	if(pArrayListCompras!=NULL){
		if(mostrarCompras(pArrayListCompras)==0){
		}else{
			printf("\nERROR EN LA FUNCION mostrarCompras\n");
		}
		retorno=0;
	}
    return retorno;
}
int controller_calcularTotalDeCompras(LinkedList* pArrayListCompras)
{
	int retorno=-1;
	if(pArrayListCompras!=NULL){
		if(ll_map(pArrayListCompras,calcularPrecioTotal)==0){
		}else{
			printf("\nERROR EN LA FUNCION\n");
		}
		retorno=0;
	}
    return retorno;
}
LinkedList* controller_crearComprasFiltradasModoTexto(char* path ,
		LinkedList* pArrayListCompras)
{
	FILE* pComprasFILE;
	LinkedList* pArrayListComprasFiltrada;
	int origen;
	if(pArrayListCompras!=NULL){
		if ((pComprasFILE=fopen(path,"w"))==NULL){
			printf("NO SE PUEDE ABRIR EL ARCHIVO");
		}else{
			if(utn_getEntero(&origen,"\nINGRESE EL ORIGEN DE LA COMPRA\n"
					"1.ADMINISTRACION\n2.TALLER\n3.VENTAS\n","\n--ERROR--\n",1,3)==0){
				if(origen==1){
					pArrayListComprasFiltrada=ll_filter (pArrayListCompras,
							filtrarListadoPorAdministracion);
				}else if(origen==2){
					pArrayListComprasFiltrada=ll_filter (pArrayListCompras,
							filtrarListadoPorTaller);
				}else{
					pArrayListComprasFiltrada=ll_filter (pArrayListCompras,
							filtrarListadoPorVentas);
				}
			}else{
				printf("\nERROR EN LA FUNCION utn_getEntero\n");
			}
		}
	}
	fclose(pComprasFILE);
	return pArrayListComprasFiltrada;
}
int controller_ordenarCompras(LinkedList* pArrayListCompras)
{
	int retorno=-1;
	if(pArrayListCompras!=NULL){
		if(ll_sort(pArrayListCompras,ordenarPorDescripcionDeCompra, 0)==0){
		}else{
			printf("\nERROR EN LA FUNCION ll_sort POR DESCRIPCION\n");
		}
		if(mostrarCompras(pArrayListCompras)==0){
		}else{
			printf("\nERROR EN LA FUNCION mostrarCompras\n");
		}
		if(ll_sort(pArrayListCompras,ordenarPorCodigoCompra, 1)==0){
		}else{
			printf("\nERROR EN LA FUNCION ll_sort POR CODIGO\n");
		}
		retorno=0;
	}
	return retorno;
}
int controller_guardarComprasModoTexto(char* path , LinkedList* pArrayListCompras)
{
	FILE* pComprasFILE;
	eCompras* unaCompra;
	int retorno=-1,i;
	char indice[200]={"codigoCompra,descripcion,origen,"
			"precioUnitario,cantidad,totalCompra"};
	char buffer[6][200];
	int tamanio,codigo,origen,cantidad,validarGetter;
	float precUnit,totalCompra;
	if(pArrayListCompras!=NULL){
		tamanio=ll_len(pArrayListCompras);
		retorno=0;
		if ((pComprasFILE=fopen(path,"w"))==NULL){
				printf("No se puede abrir el archivo");
		}else{
			fprintf(pComprasFILE,"%s\n",indice);
			for(i=0;i<tamanio;i++){
				unaCompra= (eCompras*) ll_get(pArrayListCompras,i);
				validarGetter=compra_getCodigoCompra(unaCompra,&codigo);
				if(validarGetter!=0){
					printf("\nERROR EN LA FUNCION compra_getCodigoCompra\n");
				}
				validarGetter=compra_getDescripcion(unaCompra,buffer[1]);
				if(validarGetter!=0){
					printf("\nERROR EN LA FUNCION compra_getDescripcion\n");
				}
				validarGetter=compra_getOrigen(unaCompra,&origen);
				if(validarGetter!=0){
					printf("\nERROR EN LA FUNCION compra_getOrigen\n");
				}
				validarGetter=compra_getPrecioUnitario(unaCompra,&precUnit);
				if(validarGetter!=0){
					printf("\nERROR EN LA FUNCION compra_getPrecioUnitario\n");
				}
				validarGetter=compra_getCantidad(unaCompra,&cantidad);
				if(validarGetter!=0){
					printf("\nERROR EN LA FUNCION compra_getCantidad\n");
				}
				validarGetter=compra_getTotalCompra(unaCompra,&totalCompra);
				if(validarGetter!=0){
					printf("\nERROR EN LA FUNCION compra_getTotalCompra\n");
				}
				itoa(codigo,buffer[0],10);
				itoa(origen,buffer[2],10);
				itoa(precUnit,buffer[3],10);
				itoa(cantidad,buffer[4],10);
				itoa(totalCompra,buffer[5],10);
				fprintf(pComprasFILE,"%s,%s,%s,%s,%s,%s\n",buffer[0],
						buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
			}
			printf("\nARCHIVO %s GUARDADO\n",path);
			fclose(pComprasFILE);
		}
	}
	return retorno;
}
