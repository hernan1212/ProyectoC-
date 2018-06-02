#ifndef _PAHORCADO_H_
#define _PAHORCADO_H_
#include "partida.h"

class PAhorcado: public Partida
{
private:
	int PartidasGanadas;
public:
	PAhorcado(string JugadorNick, string jName, int PartidasJugadas, int PartidasGanadas);
	PAhorcado(const PAhorcado &p);
	PAhorcado();
	virtual ~PAhorcado();

	int getPGanadas() const;
	void setPGanadas(int PartidasJugadas);

	void ganarPartida();
};

ostream& operator<<(ostream& out, const PAhorcado& pa);

#endif