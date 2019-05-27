
// Importo las funciones para el inicio del juego.
#include "tablero.h"
#include "partida.h"


// Inicio del bloque principal.
int main() {

	// Presentación del juego y carga de jugadores.
	string jugador1 = "", jugador2 = "";
	presentacion(jugador1, jugador2);


	// Creo é inicializo el tablero y comiendo el juego
	char tablero[10][10];
	inicializarTablero(tablero);
	bool sigueElJuego = true;

	// Indico quien es el jugador actual y cual es su ficha.
	string jugadorActual= jugador1;
	char fichaActual = 'X';
	int posicionUltimaFicha[2];

	mostrarTablero(tablero);

	do{
		posicionUltimaFicha[0] = 0;
		posicionUltimaFicha[1] = 0;
		cout << "Es el turno de " << jugadorActual << " (tu ficha es la '" << fichaActual << "')" << endl;

		// El usuario ingresa una ficha.
		elegirColumna(posicionUltimaFicha[1], tablero);

		// Guardo la ubicacion donde fue ingresada la ultima ficha.
		guardarUltimaFicha(posicionUltimaFicha, fichaActual, tablero);

		// Muestro el tablero por pantalla.
		mostrarTablero(tablero);

		// Verifico si termino el juego.
		sigueElJuego = !terminoElJuego(posicionUltimaFicha, tablero, fichaActual, jugadorActual);

		// Si el juego continua cambio de jugador.
		cambioDeTurno(sigueElJuego, jugador1, jugador2, jugadorActual,fichaActual);

	} while(sigueElJuego); // Fin del juego.
	return 0;
} // Fin del bloque principal.
