#include "usuario.h"
#include <iostream>
#include <string>
using namespace std;

Usuario::Usuario(string nick, string contra, string nombre, string apellido, int edad): Persona(nick, contra, nombre, apellido, edad)
{
	this->bloq = false;
}

Usuario::Usuario(const Usuario &a) : Persona(a)
{
	this->bloq = a.bloq;
}
Usuario::Usuario():Persona()
{
	this-> bloq=false;
}
Usuario::~Usuario(){}

void Usuario::MostrarUsuario()
{
	if(this->bloq)
	{
		cout <<"Nick: " << this->nick << ",\nContrasena: " << this->contra << ",\nNombre: " << this->nombre << ",\nApellido: " << this->apellido << ",\nEdad: " << this->edad <<",\nEste usuario esta bloqueado" << endl;		
	}
	else
	{
		cout <<"Nick: " << this->nick << ",\nContrasena: " << this->contra << ",\nNombre: " << this->nombre << ",\nApellido: " << this->apellido << ",\nEdad: " << this->edad <<",\nEste usuario no esta bloqueado" << endl;		
	
	}
}

bool Usuario::getbloq()
{
	return this-> bloq;

}
void Usuario::setbloq(bool bloq)
{
	 this-> bloq=bloq;
}