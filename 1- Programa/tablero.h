
#ifndef TABLERO_H_
#define TABLERO_H_

#include <iostream>

using std::cout;
using std::endl;


/*
 * Esta función se encarga de inicializar con el valor '-'
 * todas los casilleros del tablero
 */
void inicializarTablero(char tablero[10][10]);


/*
 * Esta función revisa si hay espacio disponible para agregar
 * fichas a una columna del tablero.
 */
bool columnaLlena(int columna, char tablero[10][10]);


/*
 * Esta función se encarga de guardar la ultima ficha ingresada en
 * el tablero, buscando la fila que le corresponda en base a la
 * columna elegida por el usuario.
 */
void guardarUltimaFicha(int posicionUltimaFicha[2], char fichaActual, char tablero[10][10]);


/*
 * Esta función se encarga de mostrar el estado del tablero luego de cada jugada.
 */
void mostrarTablero(char tablero[10][10]);


/*
 * Esta funcion verifica si el tablero no se ha llenado.
 */
bool tableroLleno(char tablero[10][10]);


/*
 * Esta función limpia mi hilera de fichas a revisar.
 */
void limpiarHilera(char hilera[10]);


/*
 * Esta funcion hace una copia de la columna donde fue colocada la ultima ficha del tablero
 * a una hilera para poder verificar si hubo 4 en linea.
 */
void copiarHileraVertical(int columnaUltimaFicha, char tablero[10][10], char hilera[10]);


/*
 * Esta funcion hace una copia de la fila donde fue colocada la ultima ficha del tablero
 * a una hilera para poder verificar si hubo 4 en linea.
 */
void copiarHileraHorizontal(int filaUltimaFicha, char tablero[10][10], char hilera[10]);


/*
 * Esta funcion hace una copia de la diagonal creciente tomando como referencia donde fue
 * colocada la ultima ficha del tablero a una hilera para poder verificar si hubo 4 en linea.
 */
void copiarHileraDiagonalCreciente(int posicionUltimaFicha[2], char tablero[10][10], char hilera[10]);


/*
 * Esta funcion hace una copia de la diagonal decreciente tomando como referencia donde fue
 * colocada la ultima ficha del tablero a una hilera para poder verificar si hubo 4 en linea.
 */
void copiarHileraDiagonalDecreciente(int posicionUltimaFicha[2], char tablero[10][10], char hilera[10]);


#endif /* TABLERO_H_ */
