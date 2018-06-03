
#include "partida.h"

Partida::Partida(string JugadorNick, string jName, int PartidasJugadas)
{
	this->JugadorNick = JugadorNick;
	this->jName = jName;
	this->PartidasJugadas = PartidasJugadas;
}

Partida::Partida(const Partida &p)
{
	this->JugadorNick = p.JugadorNick;
	this->jName = p.jName;
	this->PartidasJugadas = p.PartidasJugadas;
}
Partida::Partida()
{

this->PartidasJugadas = 0;

}
Partida::~Partida()
{
}

string Partida::getJugador() const
{
	return this-> JugadorNick;
}

string Partida::getJuego() const
{
	return this-> jName;
}

int Partida::getPJugadas() const
{
	return this-> PartidasJugadas;
}

void Partida::setJugador(string JugadorNick)
{
	this->JugadorNick = JugadorNick;
}

void Partida::setJuego(string jName)
{
	this->jName = jName;
}

void Partida::setPJugadas(int PartidasJugadas)
{
	this->PartidasJugadas = PartidasJugadas;
}
void Partida::jugarPartida()
{
	this-> PartidasJugadas++;
}

ostream& operator<<(ostream& out, const Partida& p)
{
	out << "Nick de la persona: " << p.getJugador() << ",\nNombre del Juego: " << p.getJuego() << ",\nPartidas Jugadas: " << p.getPJugadas() <<  endl;
	return out;
}

