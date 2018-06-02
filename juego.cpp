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

Persona Juego::getCreador() const
{
	return this-> creador;
}
string Juego::getNombre() const
{
	return this-> nombre;
}
string Juego::getGenero() const
{
	return this-> genero;
}
string Juego::getEjecutable() const
{
	return this-> ejecutable;
}
int Juego::getPrecio() const
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

ostream& operator<<(ostream& out, const Juego& j)
{
	out << "Nombre: " << j.getNombre() << ",\nGenero: " << j.getGenero() << ",\nNick del creador: " << j.getCreador().getnick() << ",\nPrecio: " << j.getPrecio() << "euros" << endl;
	return out;
}