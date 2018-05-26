#include <iostream>
#include "pCalc.h"

PCalc::PCalc(const Persona Jugador, Juego j, int PartidasJugadas, int PuntMax):Partida(Jugador, j, PartidasJugadas)
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

int PCalc::getPMax()
{
	return this-> PuntMax;
}
void PCalc::setPMax(int PuntMax)
{
	this-> PuntMax = PuntMax;
}
void PCalc::MostrarPartida()
{
	cout << "Nick de la persona: " << Jugador.getnick() << ",\nNombre del Juego: " << j.getNombre() << ",\nPartidas Jugadas: " << PartidasJugadas << ",\nPuntuación maxima: " << PuntMax << endl;
}