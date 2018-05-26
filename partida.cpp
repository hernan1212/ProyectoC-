#include <iostream>
#include "partida.h"

Partida::Partida(const Persona Jugador, Juego j, int PartidasJugadas)
{
	this->Jugador = Jugador;
	this->j = j;
	this->PartidasJugadas = PartidasJugadas;
}

Partida::Partida(const Partida &p)
{
	this->Jugador = p.Jugador;
	this->j = p.j;
	this->PartidasJugadas = p.PartidasJugadas;
}

Partida::~Partida()
{
}

Persona Partida::getJugador()
{
	return this-> Jugador;
}

Juego Partida::getJuego()
{
	return this-> j;
}

int Partida::getPJugadas()
{
	return this-> PartidasJugadas;
}

void Partida::setJugador(Persona Jugador)
{
	this->Jugador = Jugador;
}

void Partida::setJuego(Juego j)
{
	this->j = j;
}

void Partida::setPJugadas(int PartidasJugadas)
{
	this->PartidasJugadas = PartidasJugadas;
}

void Partida::MostrarPartida()
{
	cout << "Nick de la persona: " << Jugador.getnick() << ",\nNombre del Juego: " << j.getNombre() << ",\nPartidas Jugadas: " << PartidasJugadas << endl;
}

