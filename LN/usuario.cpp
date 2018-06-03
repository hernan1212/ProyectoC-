#include "usuario.h"

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

bool Usuario::getbloq() const
{
	return this-> bloq;

}
void Usuario::setbloq(bool bloq)
{
	 this-> bloq=bloq;
}

ostream& operator<<(ostream& out, const Usuario& u)
{
	if(u.getbloq())
	{
		out <<"Nick: " << u.getnick() << ",\nContrasena: " << u.getcontra() << ",\nNombre: " << u.getnombre() << ",\nApellido: " << u.getapellido() << ",\nEdad: " << u.getedad() <<",\nEste usuario esta bloqueado" << endl;			
	}
	else
	{
		out <<"Nick: " << u.getnick() << ",\nContrasena: " << u.getcontra() << ",\nNombre: " << u.getnombre() << ",\nApellido: " << u.getapellido() << ",\nEdad: " << u.getedad() <<",\nEste usuario no esta bloqueado" << endl;		
	}
	return out;
}