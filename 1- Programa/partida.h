
#ifndef PARTIDA_H_
#define PARTIDA_H_

#include "tablero.h"
#include <string>

using std::string;
using std::cin;


/*
 * Esta función realiza la presentacion del programa y solicita los datos para empezar el juego.
 */
void presentacion(string &jugador1, string &jugador2);


/*
 * Esta función le solicita al jugador que elija donde ingresar su ficha y valida dicha eleccion.
 */
void elegirColumna(int &columnaElegida, char tablero[10][10]);


/*
 * Esta funcion determina si un jugador gano logrando un 4 en linea.
 */
bool hay4EnLinea(char hilera[10], char fichaActual);

/*
 * Esta funcion evalua si alguien gano el juego.
 */
bool ganoAlguien(int ultimaFicha[2], char tablero[10][10], char fichaActual);


/*
 * Esta funcion verifica si termino el juego.
 */
bool terminoElJuego(int ultimaFicha[2], char tablero[10][10], char fichaActual, string jugador);


/*
 * Esta función realiza un cambio de turno si aún continua el juego.
 */
void cambioDeTurno(bool sigueElJuego, string jugador1, string jugador2, string &jugadorActual, char &fichaActual);


#endif /* PARTIDA_H_ */
