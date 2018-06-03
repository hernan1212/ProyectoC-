
#include "pAhorcado.h"

PAhorcado::PAhorcado(string JugadorNick, string jName, int PartidasJugadas, int PartidasGanadas):Partida(JugadorNick, jName, PartidasJugadas)
{
	this->PartidasGanadas = PartidasGanadas;
}

PAhorcado::PAhorcado(const PAhorcado &p):Partida(p)
{
	this->PartidasGanadas = p.PartidasGanadas;
}
PAhorcado::PAhorcado():Partida()
{
this-> PartidasGanadas=0;
}
PAhorcado::~PAhorcado()
{
}

int PAhorcado::getPGanadas() const
{
	return this-> PartidasGanadas;
}
void PAhorcado::setPGanadas(int PartidasGanadas)
{
	this-> PartidasGanadas = PartidasGanadas;
}
void PAhorcado::ganarPartida()
{
	this->PartidasGanadas++;
}

ostream& operator<<(ostream& out, const PAhorcado& pa)
{
	out << (Partida) pa << "Partidas Ganadas: " << pa.getPGanadas() << endl;
	return out;
}