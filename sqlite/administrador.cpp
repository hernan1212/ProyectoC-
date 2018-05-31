#include "administrador.h"
#include <iostream>
#include <string>
using namespace std;

Administrador::Administrador(string nick, string contra, string nombre, string apellido, int edad, string cod_administrador): Persona(nick, contra, nombre, apellido, edad)
{
	this->cod_administrador = cod_administrador;
}

Administrador::Administrador(const Administrador &a) : Persona(a)
{
	this->cod_administrador = a.cod_administrador;
}
Administrador::Administrador():Persona()
{
	this-> cod_administrador="";
}
Administrador::~Administrador(){}

void Administrador::MostrarAdmin()
{
	cout <<"Nick: " << this->nick << ",\nContrasena: " << this->contra << ",\nNombre: " << this->nombre << ",\nApellido: " << this->apellido << ",\nEdad: " << this->edad <<",\nCodigo de administrador: " << this->cod_administrador << endl;
}

string Administrador::getcod()
{
	return this-> cod_administrador;

}
void Administrador::setcod(string cod_administrador)
{
	 this-> cod_administrador=cod_administrador;
}