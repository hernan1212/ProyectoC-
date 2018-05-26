#include <iostream>
#include "pAhorcado.h"

PAhorcado::PAhorcado(const Persona Jugador, Juego j, int PartidasJugadas, int PartidasGanadas):Partida(Jugador, j, PartidasJugadas)
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

int PAhorcado::getPGanadas()
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
void PAhorcado::MostrarPartida()
{
	cout << "Nick de la persona: " << Jugador.getnick() << ",\nNombre del Juego: " << j.getNombre() << ",\nPartidas Jugadas: " << PartidasJugadas << ",\nPartidas Ganadas: " << PartidasGanadas << endl;
}