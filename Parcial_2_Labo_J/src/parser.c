#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libreria.h"

int parser_eCompraFromText(FILE* pFile , LinkedList* pArrayListCompras)
{
	int retorno=-1,cantidad;
	char bufferCompra[6][200];
	eCompras* unaCompra=NULL;

	if(pFile!=NULL && pArrayListCompras!=NULL){

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferCompra[0],bufferCompra[1],bufferCompra[2],
					bufferCompra[3],bufferCompra[4],bufferCompra[5]);

			while(!feof(pFile))
			{

				cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferCompra[0],bufferCompra[1],
						bufferCompra[2],bufferCompra[3],bufferCompra[4],bufferCompra[5]);
				if(cantidad<6){
					compra_delete(unaCompra);
					unaCompra=NULL;
					retorno=-1;
					break;
				}else{
					unaCompra=compra_newParametros(bufferCompra[0],bufferCompra[1],bufferCompra[2],
							bufferCompra[3],bufferCompra[4],bufferCompra[5]);
					if(unaCompra!=NULL){
						ll_add(pArrayListCompras,(eCompras*)unaCompra);
					}
				retorno=0;
				}
			}

	}
    return retorno;
}
