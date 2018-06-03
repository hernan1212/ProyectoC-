#include "administrador.h"

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

string Administrador::getcod() const
{
	return this-> cod_administrador;

}
void Administrador::setcod(string cod_administrador)
{
	 this-> cod_administrador=cod_administrador;
}

ostream& operator<<(ostream& out, const Administrador& a)
{
	out <<"Nick: " << a.getnick() << ",\nContrasena: " << a.getcontra() << ",\nNombre: " << a.getnombre() << ",\nApellido: " << a.getapellido() << ",\nEdad: " << a.getedad() <<",\nCodigo de administrador: " << a.getcod() << endl;
	return out;
}