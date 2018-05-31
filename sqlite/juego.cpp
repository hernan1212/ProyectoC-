#include <iostream>
#include "juego.h"
#include "persona.h"

using namespace std;

Juego::Juego(const Persona creador, string nombre, string genero, string ejecutable, int precio)
{
	this->creador = creador;
	this->nombre = nombre;
	this->genero = genero;
	this->ejecutable = ejecutable;
	this->precio = precio;
}

Juego::Juego(const Juego &j)
{
	this->creador = j.creador;
	this->nombre = j.nombre;
	this->genero = j.genero;
	this->ejecutable = j.ejecutable;
	this->precio = j.precio;
}

Juego::Juego()
{
	this->nombre = "";
	this->genero = "";
	this->ejecutable = "";
	this->precio = 0;
}

Juego::~Juego()
{
}

Persona Juego::getCreador()
{
	return this-> creador;
}
string Juego::getNombre()
{
	return this-> nombre;
}
string Juego::getGenero()
{
	return this-> genero;
}
string Juego::getEjecutable()
{
	return this-> ejecutable;
}
int Juego::getPrecio()
{
	return this-> precio;
}
void Juego::setCreador(Persona creador)
{
	this->creador = creador;
}
void Juego::setNombre(string nombre)
{
	this->nombre = nombre;
}
void Juego::setGenero(string genero)
{
	this->genero = genero;
}
void Juego::setEjecutable(string ejecutable)
{
	this->ejecutable = ejecutable;
}
void Juego::setPrecio(int precio)
{
	this->precio = precio;
}

void Juego::mostrarJuego()
{
	cout << "Nombre: " << this->nombre << ",\nGenero: " << this->genero << ",\nNick del creador: " << this->creador.getnick() << ",\nPrecio: " << this->precio << "euros" << endl;
}