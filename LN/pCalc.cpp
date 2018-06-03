
#include "pCalc.h"

PCalc::PCalc(string JugadorNick, string jName, int PartidasJugadas, int PuntMax):Partida(JugadorNick, jName, PartidasJugadas)
{
	this->PuntMax = PuntMax;
}

PCalc::PCalc(const PCalc &p):Partida(p)
{
	this->PuntMax = p.PuntMax;
}
 PCalc::PCalc():Partida()
{

	this->PuntMax=0;
}
PCalc::~PCalc()
{
}

int PCalc::getPMax() const
{
	return this-> PuntMax;
}
void PCalc::setPMax(int PuntMax)
{
	this-> PuntMax = PuntMax;
}

ostream& operator<<(ostream& out, const PCalc& pc)
{
	out << (Partida) pc << ",\nPuntuación maxima: " << pc.getPMax() << endl;
	return out;
}