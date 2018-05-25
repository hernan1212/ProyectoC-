#include "persona.h"
#include <iostream>
#include <string>

using namespace std;

Persona::Persona(string nick, string contra, string nombre, string apellido, int edad)
{
	this->nick = nick;
	this->contra = contra;
	this->nombre = nombre;
	this->apellido = apellido;
	this->edad = edad;
}

Persona::Persona(const Persona& p)
{
	this->nick = p.nick;
	this->contra = p.contra;
	this->nombre = p.nombre;
	this->apellido = p.apellido;
	this->edad = p.edad;
}

Persona::~Persona(){}

string Persona::getnick()
{
	return this-> nick;
}
string Persona::getcontra()
{
	return this-> contra;
}
string Persona::getnombre()
{
	return this-> nombre;
}
string Persona::getapellido()
{
	return this-> apellido;
}
int Persona::getedad()
{
	return this-> edad;
}
void Persona::setedad(int edad)
{
	this->edad = edad;
}
void Persona::setnick(string nick)
{
	this->nick = nick;
}
void Persona::setcontra(string contra)
{
	this->contra = contra;
}
void Persona::setnombre(string nombre)
{
	this->nombre = nombre;
}
void Persona::setapellido(string apellido)
{
	this->apellido = apellido;
}

