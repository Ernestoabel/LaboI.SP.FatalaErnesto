/**
 * @brief -Funcion que se encarga de pedirle un char al usuario y validarlo en un rango
 *
 * @param pResultado -Puntero donde se guarda la posicion de memoria del char
 * @param mensaje -Mensaje para especificar lo pedido al usuario
 * @param mensajeError -Mensaje de error si el usuario no ingresa segun las especificaciones
 * @param minimo -Rango minimo para validar el char ingresado
 * @param maximo -Rango maximo para validar el char ingresado
 * @return -Un entero para validar que la funcion cumplio su objetivo o no
 */
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError, char minimo,char maximo);
/**
 * @brief  -Funcion que se encarga de pedirle un char al usuario y validarlo si es uno u otro
 *
 * @param pResultado -Puntero donde se guarda la posicion de memoria del char
 * @param mensaje -Mensaje para especificar lo pedido al usuario
 * @param mensajeError -Mensaje de error si el usuario no ingresa segun las especificaciones
 * @param minimo -Valor comparativo para validar el char ingresado
 * @param maximo -Valor comparativo para validar el char ingresado
 * @return -Un entero para validar que la funcion cumplio su objetivo o no
 */
int utn_getDosCaracter(char* pResultado,char* mensaje,char* mensajeError, char charUno,char charDos);
/**
 * @brief -Funcion que se encarga de pedirle un array de caracteres al usuario,pasarlo a entero
 *  y validarlo en un rango
 *
 * @param pResultado -Puntero donde se guarda la posicion de memoria del entero
 * @param mensaje -Mensaje para especificar lo pedido al usuario
 * @param mensajeError -Mensaje de error si el usuario no ingresa segun las especificaciones
 * @param minimo -Rango minimo para validar el entero ingresado
 * @param maximo -Rango maximo para validar el entero ingresado
 * @return -Un entero para validar que la funcion cumplio su objetivo o no
 */
int utn_getEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);
/**
 * @brief -Funcion que se encarga de pedirle un array de caracteres al usuario,pasarlo a entero
 *  y validarlo en un rango
 *
 * @param pResultado -Puntero donde se guarda la posicion de memoria y valor del flotante
 * @param mensaje -Mensaje para especificar lo pedido al usuario
 * @param mensajeError -Mensaje de error si el usuario no ingresa segun las especificaciones
 * @param minimo -Rango minimo para validar el flotante ingresado
 * @param maximo -Rango maximo para validar el flotante ingresado
 * @return -Un entero para validar que la funcion cumplio su objetivo o no
 */
int utn_getFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo);
/**
 * @brief -Funcion que se encarga de pedirle un array de caracteres al usuario,pasarlo a flotante
 *  y validar que no exceda el tamanio impuesto
 *
 * @param tamanio -Cantidad de caracteres maximo del array
 * @param pResultado -Puntero donde se guarda la cadena de caracteres
 * @param mensaje -Mensaje para especificar lo pedido al usuario
 * @param mensajeError -Mensaje de error si el usuario no ingresa segun las especificaciones
 * @return -Un entero para validar que la funcion cumplio su objetivo o no
 */
int utn_getCadenaCaracteres(int tamanio,char* pResultado,char* mensaje,char* mensajeError);
/**
 * @brief -Funcion que se encarga de validar que si la cadena que recibe como parametro es solo letras o no.
 *
 * @param pResultado -Puntero por parametro recivido para ser validado
 * @return -Un entero para validar si es solo letra o no
 */
int utn_cadenaSoloLetra(char* pResultado);
/**
 * @brief -Funcion que se encarga de validar si el puntero entero recibido por parametro es anio bisiesto o no
 *
 * @param anio -Puntero por parametro recivido para ser validado
 * @return -Un entero para validar si es anio bisiseto o no
 */
int utn_validarAnioBisiesto(int* anio);
/**
 * @brief -Funcion que valida si la fecha ingresada corresponde al calendario
 *
 * @param ingreso -Puntero entero recivido como parametro para condicionar su validacion
 * @param mes -Entero como mes que sirven para condicionar los dias de ese mes
 * @param anio -Puntero entero recivido como parametro que corresponde al anio,
 *  que sirve para condicionar los dias de febrero en anio bisisesto
 * @return
 */
int utn_validarFechaIngresada(int* ingreso,int* mes,int* anio);
/**
 * @brief -Funcion que se utiliza para dar una pausa en la ejecucion del programa
 *
 */
void utn_pausaPrograma(void);
/**
 * @brief -Funcion que se encarga de pedirle un array de caracteres al usuario,pasarlo a entero short
 *  y validarlo en un rango
 *
 * @param pResultado -Puntero donde se guarda la posicion de memoria y valor del flotante
 * @param mensaje -Mensaje para especificar lo pedido al usuario
 * @param mensajeError -Mensaje de error si el usuario no ingresa segun las especificaciones
 * @param minimo -Rango minimo para validar el flotante ingresado
 * @param maximo -Rango maximo para validar el flotante ingresado
 * @return -Un entero para validar que la funcion cumplio su objetivo o no
 */
int utn_getEnteroShort(short* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);

