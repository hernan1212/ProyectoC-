#ifndef _PCALC_H_
#define _PCALC_H_
#include "partida.h"

class PCalc: public Partida
{
private:
	int PuntMax;
public:
	PCalc(const Persona Jugador, Juego j, int PartidasJugadas, int PuntMax);
	PCalc(const PCalc &p);
	PCalc();
	virtual ~PCalc();

	int getPMax();
	void setPMax(int PuntMax);

	virtual void MostrarPartida();
};

#endif