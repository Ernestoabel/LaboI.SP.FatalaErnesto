#include "Libreria.h"

/**
 * @brief -Funcion que permite la impresion de opciones de un menu principal
 * , con un retorno entero que valida la opcion de un switch
 *
 * @return -Entero validado para la utilizacion en el switch
 */
int menu(void);
/**
 * @brief -Funcion que se encarga de preguntar y validar la interrupcion de un bucle
 *
 * @param mensaje -Mensaje impreso con las especificacion para continuar o no con el bucle
 * @return -Char para validar la interrupcion del bucle donde se llamo a la funcion
 */
char continuarCarga(char* mensaje);
/**
 * @brief -Funcion que se encarga imprimir el listado de compras cargadas
 *
 * @param pArrayListCompras LinkedList a ser impresa
 * @param condicion para imprimir los datos de la LinkedList

 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int mostrarCompras(LinkedList* pArrayListCompras);
