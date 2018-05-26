#ifndef _PARTIDA_H_
#define _PARTIDA_H_
#include "persona.h"
#include "juego.h"

	class Partida
	{
	protected:
		Persona Jugador;
		Juego j;
		int PartidasJugadas;
	public:
		Partida(const Persona Jugador, Juego j, int PartidasJugadas);
		Partida(const Partida &p);
		Partida();
		virtual ~Partida();

		Persona getJugador();
		void setJugador(Persona Jugador);

		Juego getJuego();
		void setJuego(Juego j);

		int getPJugadas();
		void setPJugadas(int PartidasJugadas);

		void jugarPartida();

		virtual void MostrarPartida();
	};
#endif