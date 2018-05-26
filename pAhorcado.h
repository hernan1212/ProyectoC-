#ifndef _PAHORCADO_H_
#define _PAHORCADO_H_
#include "partida.h"

class PAhorcado: public Partida
{
private:
	int PartidasGanadas;
public:
	PAhorcado(const Persona Jugador, Juego j, int PartidasJugadas, int PartidasGanadas);
	PAhorcado(const PAhorcado &p);
	virtual ~PAhorcado();

	int getPGanadas();
	void setPGanadas(int PartidasJugadas);

	virtual void MostrarPartida();
};

#endif