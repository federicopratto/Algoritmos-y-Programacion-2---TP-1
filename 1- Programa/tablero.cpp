
#include "tablero.h"


/*
 * Esta función se encarga de inicializar con el valor '-'
 * todas los casilleros del tablero
 */
void inicializarTablero(char tablero[10][10]) {
	for (int fila = 0; fila < 10; fila++) {
		for (int columna = 0; columna < 10; columna++) {
			tablero[fila][columna] = '-';
		}
	}
} // Fin de la función inicializarTablero.


/*
 * Esta función revisa si hay espacio disponible para agregar
 * fichas a una columna del tablero.
 */
bool columnaLlena(int columna, char tablero[10][10]) {
	if (tablero[9][columna] == '-') {
		return false;
	} else {
		cout << "La columna elegida esta llena, selecciona otra." << endl;
		return true;
	}
} // Fin de la función columnaLlena.


/*
 * Esta función se encarga de guardar la ultima ficha ingresada en
 * el tablero, buscando la fila que le corresponda en base a la
 * columna elegida por el usuario.
 */
void guardarUltimaFicha(int posicionUltimaFicha[2], char fichaActual,
		char tablero[10][10]) {

	int filaVacia = 0;
	while (tablero[filaVacia][posicionUltimaFicha[1]] != '-') {
		filaVacia++;
	}

	// Guardo la posicion donde esta la ultima ficha ingresada y la coloco en el tablero.
	posicionUltimaFicha[0] = filaVacia;
	tablero[posicionUltimaFicha[0]][posicionUltimaFicha[1]] = fichaActual;

} // Fin de la funcion guardarUltimaFicha.


/*
 * Esta función se encarga de mostrar el estado del tablero luego de cada jugada.
 */
void mostrarTablero(char tablero[10][10]) {
	// Limpio la pantalla.
	for(int i = 0; i<15; i++){
		cout << endl;
	}
	// Muestro el tablero.
	for (int fila = 9; fila >= 0; fila--) {
		for (int columna = 0; columna < 10; columna++) {
			cout << tablero[fila][columna] << " ";
		}
		cout << endl;
	}
	for(int i = 1; i <= 10; i++){
		cout << i << " " << endl;
	}
	cout << endl;
} // Fin de la funcion mostrarTablero.


/*
 * Esta funcion verifica si el tablero no se ha llenado.
 */
bool tableroLleno(char tablero[10][10]){

	int i = 0;
	bool hayLugar = false;

	// Verifico si alguna columna todavia tiene lugar para almacenar fichas.
	do{
		hayLugar = (tablero[9][i] == '-');
		i++;
	}while(!hayLugar && i<10);

	return !hayLugar;
} // Fin de la función tableroLleno.


/*
 * Esta función limpia mi hilera de fichas a revisar.
 */
void limpiarHilera(char hilera[10]){
	// Relleno mi hilera con '-'
	for(int i=0; i<10; i++){
			hilera[i] = '-';
	}
} // Fin de la función


/*
 * Esta funcion hace una copia de la columna donde fue colocada la ultima ficha del tablero
 * a una hilera para poder verificar si hubo 4 en linea.
 */
void copiarHileraVertical(int columnaUltimaFicha, char tablero[10][10], char hilera[10]){
	// limpio mi hilera.
	limpiarHilera(hilera);

	// relleno mi hilera con las fichas colocadas en el tablero.
	for(int fila = 0 ; fila < 10 ; fila++){
		hilera[fila] = tablero[fila][columnaUltimaFicha];
	}
} // Fin de la funcion.


/*
 * Esta funcion hace una copia de la fila donde fue colocada la ultima ficha del tablero
 * a una hilera para poder verificar si hubo 4 en linea.
 */
void copiarHileraHorizontal(int filaUltimaFicha, char tablero[10][10], char hilera[10]){
	// limpio mi hilera.
	limpiarHilera(hilera);

	// relleno mi hilera con las fichas colocadas en el tablero.
	for(int columna = 0 ; columna < 10 ; columna++){
		hilera[columna] = tablero[filaUltimaFicha][columna];
	}
} // Fin de la funcion.


/*
 * Esta funcion hace una copia de la diagonal creciente tomando como referencia donde fue
 * colocada la ultima ficha del tablero a una hilera para poder verificar si hubo 4 en linea.
 */
void copiarHileraDiagonalCreciente(int posicionUltimaFicha[2], char tablero[10][10], char hilera[10]){
	// limpio mi hilera.
	limpiarHilera(hilera);

	// Le cambio el nombre a mis variables para mas comodidad.
	int &fila = posicionUltimaFicha[0];
	int &columna = posicionUltimaFicha[1];

	// relleno mi hilera con las fichas colocadas en el tablero.
	if(fila <= columna){
		for (int i = 0, j = (columna - fila); j <= 9; i++, j++) {
			hilera[i] = tablero[i][j];
		}
	} else {
		for (int i = (fila - columna), j = 0; i <= 9; i++, j++) {
			hilera[j] = tablero[i][j];
		}
	}
} // Fin de la funcion.


/*
 * Esta funcion hace una copia de la diagonal decreciente tomando como referencia donde fue
 * colocada la ultima ficha del tablero a una hilera para poder verificar si hubo 4 en linea.
 */
void copiarHileraDiagonalDecreciente(int posicionUltimaFicha[2], char tablero[10][10], char hilera[10]){
	// limpio mi hilera.
	limpiarHilera(hilera);

	// Le cambio el nombre a mis variables para mas comodidad.
	int &fila = posicionUltimaFicha[0];
	int &columna = posicionUltimaFicha[1];

	// relleno mi hilera con las fichas colocadas en el tablero.
	if(fila + columna <= 9){
		for (int i = (fila + columna), j = 0; i >= 0; i--, j++) {
			hilera[j] = tablero[i][j];
		}
	} else {
		for (int i = 9, j = (fila + columna - 9); j <= 9; i--, j++) {
			hilera[9-i] = tablero[i][j];
		}
	}
} // Fin de la funcion.
