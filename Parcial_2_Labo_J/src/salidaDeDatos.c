#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_UTN.h"
#include "LinkedList.h"
#include "Libreria.h"

int menu(void)
{
	int opcion;
	printf("\n============================\n|    COMPRAS DE LIBRERIA   |\n+--------------------------+");
	printf("\n|1.CARGA DE ARCHIVO        |");
	printf("\n|2.IMPRIMIR LISTA          |");
	printf("\n|3.ASIGNAR TOTALES         |");
	printf("\n|4.FILTRAR POR TIPO        |");
	printf("\n|5.MOSTRAR COMPRAS         |");
	printf("\n|6.GUARDAR COMPRAS         |");
	printf("\n|7.SALIR                   |\n============================\n");
	fflush(stdin);
	utn_getEntero(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOPCION NO VALIDA\n",1,7);
	return opcion;
}
int menuListados(void)
{
	int opcion;
	printf("\n===================================================\n"
			"|         MENU LISTADOS                           |\n"
			"+-------------------------------------------------+");
	printf("\n|1.LISTADO DE COMPRAS DE ADMINISTRACION           |");
	printf("\n|2.LISTADO DE COMPRAS DE TALLER                   |");
	printf("\n|3.LISTADO DE COMPRAS DE VENTAS                   |");
	printf("\n|4.VOLVER AL MENU PRINCIPAL                       |\n"
			"===================================================\n");
	fflush(stdin);
	utn_getEntero(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOPCION NO VALIDA\n",1,4);
    return opcion;
}
char continuarCarga(char* mensaje)
{
	int validar;
	char opcion;
	do{
		printf("%s",mensaje);
		fflush(stdin);
		validar=utn_getDosCaracter(&opcion,"\nINGRESE OPCION S/N: ","\n--Error--\nOPCION NO VALIDA\n",'S','N');
	}while(validar!=0);
	return opcion;
}
int mostrarCompras(LinkedList* pArrayListCompras)
{
    int retorno=-1,i,cant,codigoCompra,origen,cantidad,validarGetter;
    char descripcion[51],origenDeCompra[51];
    float precioUnitario,totalCompra;
    eCompras* unaCompra=compra_new();
    if(pArrayListCompras!=NULL && unaCompra!=NULL){
    	cant=ll_len(pArrayListCompras);
    	printf("\n================================================================================================\n");
    	printf("%s%s%s%s%s%s",
    			"|  ID  |"," DESCRIPCION DEL ARTICULO |","    ORIGEN      |"," PRECIO UNITARIO |"," CANTIDAD |"," COMPRA TOTAL |");
    	printf("\n+------+--------------------------+----------------+-----------------+----------+--------------+\n");
    	for(i=0;i<cant;i++){
    		unaCompra= (eCompras*) ll_get(pArrayListCompras,i);
    		validarGetter=compra_getCodigoCompra(unaCompra,&codigoCompra);
    		if(validarGetter!=0){
    			printf("\nERROR EN LA FUNCION compra_getCodigoCompra\n");
    		}
    		validarGetter=compra_getDescripcion(unaCompra,descripcion);
    		if(validarGetter!=0){
    			printf("\nERROR EN LA FUNCION compra_getDescripcion\n");
    		}
    		validarGetter=compra_getOrigen(unaCompra,&origen);
    		if(validarGetter!=0){
    			printf("\nERROR EN LA FUNCION compra_getOrigen\n");
    		}
    		validarGetter=compra_getPrecioUnitario(unaCompra,&precioUnitario);
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
    		validarCompraDeOrigen(origen,origenDeCompra);
    		printf("| %4d | %-24s | %14s | %15.2f | %8d | %12.2f |\n",
    				codigoCompra,descripcion,origenDeCompra,precioUnitario,cantidad,totalCompra);
    	}
    	printf("================================================================================================\n");
        retorno=0;
    }
    return retorno;
}
