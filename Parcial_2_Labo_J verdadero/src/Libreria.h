#include "LinkedList.h"

#ifndef Libreria_H_INCLUDED
#define Libreria_H_INCLUDED

typedef struct
{
	int codigoCompra;
	char descripcion[51];
	int origen;
	float precioUnitario;
	int cantidad;
	float totalCompra;
}eCompras;

eCompras* compra_new();
eCompras* compra_newParametros(char* codigoCompra,char* descripcion,char* origen,
		char* precioUnitario, char* cantidad, char* totalCompra);
void compra_delete(eCompras* this);
int compra_setCodigoCompra(eCompras* this,int codigoCompra);
int compra_setDescripcion(eCompras* this,char* descripcion);
int compra_setOrigen(eCompras* this,int origen);
int compra_setPrecioUnitario(eCompras* this,float precioUnitario);
int compra_setCantidad(eCompras* this,int cantidad);
int compra_setTotalCompra(eCompras* this,float totalCompra);
int compra_getCodigoCompra(eCompras* this,int* codigoCompra);
int compra_getDescripcion(eCompras* this,char* descripcion);
int compra_getOrigen(eCompras* this,int* origen);
int compra_getPrecioUnitario(eCompras* this,float* precioUnitario);
int compra_getCantidad(eCompras* this,int* cantidad);
int compra_getTotalCompra(eCompras* this,float* totalCompra);
int validarCompraDeOrigen(int origen,char* mensaje);
int filtrarListadoPorAdministracion(void* Element);
int filtrarListadoPorTaller(void* Element);
int filtrarListadoPorVentas(void* Element);
int calcularPrecioTotal(void* Element);
int ordenarPorDescripcionDeCompra(void* unaCompra, void* auxCompra);
int ordenarPorCodigoCompra(void* unaCompra, void* auxCompra);
#endif
