
#include "partida.h"


/*
 * Esta función realiza la presentacion del programa y solicita los datos para empezar el juego.
 */
void presentacion(string &jugador1, string &jugador2) {

	// Presentacion del programa
	cout << "Bienvenido al 4 en linea!" << endl << endl;

	// Carga de jugadores.
	cout << "Jugador 1 - Ingrese su nombre: ";
	cin >> jugador1;

	cout << "Jugador 2 - Ingrese su nombre: ";
	cin >> jugador2;
	cout << endl;

} // Fin de la función presentacion.


/*
 * Esta función le solicita al jugador que elija donde ingresar su ficha y valida dicha eleccion.
 */
void elegirColumna(int &columnaElegida, char tablero[10][10]) {
	// Le pido al usuario que elija una columa y valido su decision.
	bool seguir = true;

	do {
		cout << "Ingresa una columna entre 1 y 10: ";
		cin >> columnaElegida;
		cout << endl;

		// Si la columna es invalido le solicito al usuario que ingrese otra.
		if (columnaElegida < 1 || columnaElegida > 10) {
			cout << "Valor invalido, intenta de nuevo." << endl;
			columnaElegida = 0;
		} else {
			// Si la columna es valida verifico si queda lugar en ella.
			columnaElegida--;
			seguir = columnaLlena(columnaElegida, tablero);
		}
	} while (seguir);
} // Fin de la funcion elegirColumna.


/*
 * Esta funcion determina si un jugador gano logrando un 4 en linea.
 */
bool hay4EnLinea(char hilera[10], char fichaActual) {

	// Inicio mi contador de fichas.
	int fichasEncontradas = 0;

	// Cuento la cantidad de fichas consecutivas del jugador actual.
	int i = 0;
	do {
		if (hilera[i] == fichaActual) {
			fichasEncontradas++;
		} else {
			fichasEncontradas = 0;
		}
		i++;
	} while (i < 10 && fichasEncontradas < 4);

	// Retorno el resultado.
	return (fichasEncontradas == 4);
} // Fin de la función hay4EnLinea.


/*
 * Esta funcion evalua si alguien gano el juego.
 */
bool ganoAlguien(int ultimaFicha[2], char tablero[10][10], char fichaActual) {

	// Creo un array hilera donde guardare la fila a revisar.
	char hilera[10];

	copiarHileraVertical(ultimaFicha[1], tablero, hilera);
	if(!hay4EnLinea(hilera, fichaActual)){
		copiarHileraHorizontal(ultimaFicha[0], tablero, hilera);
		if(!hay4EnLinea(hilera, fichaActual)){
			copiarHileraDiagonalCreciente(ultimaFicha, tablero, hilera);
			if(!hay4EnLinea(hilera, fichaActual)){
				copiarHileraDiagonalDecreciente(ultimaFicha, tablero, hilera);
				if(!hay4EnLinea(hilera, fichaActual)){
					return false;
				}
			}
		}
	}
	return true;
} // Fin de la funcion ganoAlguien;


/*
 * Esta funcion verifica si termino el juego.
 */
bool terminoElJuego(int ultimaFicha[2], char tablero[10][10], char fichaActual, string jugador){

	if(!ganoAlguien(ultimaFicha, tablero, fichaActual)){
		if(!tableroLleno(tablero)){
			return false;
		} else {
			cout << "Empataron, ya no hay mas fichas por colocar." << endl;
		}
	} else {
		cout << "¡Felicidades " << jugador << " ganaste!" << endl;
	}
	return true;
} // Fin de la función terminoElJuego.


/*
 * Esta función realiza un cambio de turno si aún continua el juego.
 */
void cambioDeTurno(bool sigueElJuego, string jugador1, string jugador2, string &jugadorActual, char &fichaActual) {
	if (sigueElJuego) {
		if (jugadorActual == jugador1) {
			jugadorActual = jugador2;
			fichaActual = 'O';
		} else {
			jugadorActual = jugador1;
			fichaActual = 'X';
		}
	}
} // Fin de la función cambioDeTurno.
