#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria.h"
int compra_setCodigoCompra(eCompras* this,int codigoCompra)
{
	int retorno=-1;
	if(this!=NULL){
		this->codigoCompra=codigoCompra;
		retorno=0;
	}
	return retorno;
}
int compra_setDescripcion(eCompras* this,char* descripcion)
{
	int retorno=-1;
	if(this!=NULL){
		strcpy(this->descripcion,descripcion);
		retorno=0;
	}
	return retorno;
}
int compra_setOrigen(eCompras* this,int origen)
{
	int retorno=-1;
	if(this!=NULL){
		this->origen=origen;
		retorno=0;
	}
	return retorno;
}
int compra_setPrecioUnitario(eCompras* this,float precioUnitario)
{
	int retorno=-1;
	if(this!=NULL){
		this->precioUnitario=precioUnitario;
		retorno=0;
	}
	return retorno;
}
int compra_setCantidad(eCompras* this,int cantidad)
{
	int retorno=-1;
	if(this!=NULL){
		this->cantidad=cantidad;
		retorno=0;
	}
	return retorno;
}
int compra_setTotalCompra(eCompras* this,float totalCompra)
{
	int retorno=-1;
	if(this!=NULL){
		this->totalCompra=totalCompra;
		retorno=0;
	}
	return retorno;
}
int compra_getCodigoCompra(eCompras* this,int* codigoCompra)
{
	int retorno=-1;
	if(this!=NULL){
		*codigoCompra=this->codigoCompra;
		retorno=0;
	}
	return retorno;
}
int compra_getDescripcion(eCompras* this,char* descripcion)
{
	int retorno=-1;
	if(this!=NULL){
		strcpy(descripcion,this->descripcion);
		retorno=0;
	}
	return retorno;
}
int compra_getOrigen(eCompras* this,int* origen)
{
	int retorno=-1;
	if(this!=NULL){
		*origen=this->origen;
		retorno=0;
	}
	return retorno;
}
int compra_getPrecioUnitario(eCompras* this,float* precioUnitario)
{
	int retorno=-1;
	if(this!=NULL){
		*precioUnitario=this->precioUnitario;
		retorno=0;
	}
	return retorno;
}
int compra_getCantidad(eCompras* this,int* cantidad)
{
	int retorno=-1;
	if(this!=NULL){
		*cantidad=this->cantidad;
		retorno=0;
	}
	return retorno;
}
int compra_getTotalCompra(eCompras* this,float* totalCompra)
{
	int retorno=-1;
	if(this!=NULL){
		*totalCompra=this->totalCompra;
		retorno=0;
	}
	return retorno;
}
eCompras* compra_new()
{
	return (eCompras*) calloc(1,sizeof(eCompras));
}
void compra_delete(eCompras* this)
{
	free(this);
}
eCompras* compra_newParametros(char* codigoCompra,char* descripcion,char* origen,
		char* precioUnitario, char* cantidad, char* totalCompra)
{
	eCompras* unaCompra;
	unaCompra=compra_new();
	if(unaCompra !=NULL){
		if(compra_setCodigoCompra(unaCompra,atoi(codigoCompra))!=0 ||
			compra_setDescripcion(unaCompra,descripcion)!=0 ||
			compra_setOrigen(unaCompra,atoi(origen))!=0 ||
			compra_setPrecioUnitario(unaCompra,atof(precioUnitario))!=0 ||
			compra_setCantidad(unaCompra,atoi(cantidad))!=0 ||
			compra_setTotalCompra(unaCompra,atoi(totalCompra))!=0){
			compra_delete(unaCompra);
			unaCompra=NULL;
		}
	}
	return unaCompra;
}
int validarCompraDeOrigen(int origen,char* mensaje)
{
	int retorno=-1;
	if(origen >0 && origen < 4){
		if(origen==1){
			strcpy(mensaje,"ADMINISTRACION");
		}else if(origen==2){
			strcpy(mensaje,"TALLER");
		}else{
			strcpy(mensaje,"VENTAS");
		}
		retorno=0;
	}
	return retorno;
}
int filtrarListadoPorAdministracion(void* Element)
{
	int retorno=0;
	if(Element!=NULL){

		if(((eCompras*) Element)->origen==1){
			retorno=1;
		}
	}
	return retorno;
}
int filtrarListadoPorTaller(void* Element)
{
	int retorno=0;
	if(Element!=NULL){

		if(((eCompras*) Element)->origen==2){
			retorno=1;
		}
	}
	return retorno;
}
int filtrarListadoPorVentas(void* Element)
{
	int retorno=0;
	if(Element!=NULL){

		if(((eCompras*) Element)->origen==3){
			retorno=1;
		}
	}
	return retorno;
}
int calcularPrecioTotal(void* Element)
{
	int retorno=-1;
	if(Element!=NULL){
		compra_setTotalCompra(((eCompras*)Element),((eCompras*)Element)->cantidad * ((eCompras*)Element)->precioUnitario);
		retorno=0;
	}
	return retorno;
}
int ordenarPorDescripcionDeCompra(void* unaCompra, void* auxCompra)
{
    int retorno=0;
    char primeraDescripcion[51],segundaDescripcion[51];
    if(unaCompra!=NULL && auxCompra!=NULL){
    	compra_getDescripcion(unaCompra,primeraDescripcion);
    	compra_getDescripcion(auxCompra,segundaDescripcion);
        if(strcmp(primeraDescripcion,segundaDescripcion)>0){
            retorno=1;
        }else if(strcmp(primeraDescripcion,segundaDescripcion)<0){
        	retorno=-1;
        }
    }
    return retorno;
}
int ordenarPorCodigoCompra(void* unaCompra, void* auxCompra)
{
    int retorno=0,primerCodigo,segundoCodigo;
    if(unaCompra!=NULL && auxCompra!=NULL){
    	compra_getCodigoCompra(unaCompra,&primerCodigo);
    	compra_getCodigoCompra(auxCompra,&segundoCodigo);
        if(primerCodigo>segundoCodigo){
            retorno=1;
        }else if(primerCodigo<segundoCodigo){
        	retorno=-1;
        }
    }
    return retorno;
}
