#ifndef _PCALC_H_
#define _PCALC_H_
#include "partida.h"

class PCalc: public Partida
{
private:
	int PuntMax;
public:
	PCalc(string JugadorNick, string jName, int PartidasJugadas, int PuntMax);
	PCalc(const PCalc &p);
	PCalc();
	virtual ~PCalc();

	int getPMax() const;
	void setPMax(int PuntMax);
};

ostream& operator<<(ostream& out, const PCalc& pc);


#endif