/*
 ============================================================================
 Name        : Parcial_2_Labo_J.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libreria.h"
#include "salidaDeDatos.h"


int main(void) {
	setbuf(stdout,NULL);
	LinkedList* listaCompras = ll_newLinkedList();
	LinkedList* listaComprasFiltrada=NULL;
	int opcionPrincipal;
	char confirmarSalir;
	do{
		opcionPrincipal=menu();
		switch(opcionPrincipal){
			case 1:
				if(controller_cargarComprasDesdeTexto(listaCompras)==0){
				}else{
					printf("\n--ERROR EN LA FUNCION--\n");
				}
				break;
			case 2:
				if(ll_isEmpty(listaCompras)==0){
					if(controller_listarCompras(listaCompras)==0){
					}else{
						printf("--ERROR EN LA FUNCION--");
					}
				}else{
					printf("\nNO SE A CARGADO EL ARCHIVO\n");
				}
				break;
			case 3:
				if(ll_isEmpty(listaCompras)==0){
					if(controller_calcularTotalDeCompras(listaCompras)==0){
						printf("\nCALCULOS REALIZADOS CORRECTAMENTE\n");
					}else{
						printf("--ERROR EN LA FUNCION--");
					}
				}else{
					printf("\nNO SE A CARGADO EL ARCHIVO\n");
				}
				break;
			case 4:
				if(ll_isEmpty(listaCompras)==0){
					listaComprasFiltrada=controller_crearComprasFiltradasModoTexto("compras.csv",listaCompras);
				}else{
					printf("\nNO SE A CARGADO EL ARCHIVO\n");
				}
				break;
			case 5:
				if(ll_isEmpty(listaComprasFiltrada)==0){
					if(controller_ordenarCompras(listaComprasFiltrada)==0){
					}else{
						printf("--ERROR EN LA FUNCION--");
					}
				}else{
					printf("\nNO SE A GENERADO LA LISTA FILTRADA\n");
				}
				break;
			case 6:
				if(ll_isEmpty(listaComprasFiltrada)==0){
					if(controller_guardarComprasModoTexto("compras.csv",listaComprasFiltrada)==0){
					}else{
						printf("--ERROR EN LA FUNCION--");
					}
				}else{
					printf("\nNO SE A GENERADO LA LISTA FILTRADA\n");
				}
				break;
			case 7:
				confirmarSalir=continuarCarga("\nCONFIRME PARA SALIR DEL SISTEMA");
				break;
		}
	}while(confirmarSalir!='S');
	return 0;
}
