#ifndef _ADMINISTRADOR_H_
#define _ADMINISTRADOR_H_
#include <string>
#include "persona.h"

class Administrador: public Persona
{
private:
	string cod_administrador;

public:
	Administrador(string nick, string contra, string nombre, string apellido, int edad, string cod_administrador);
	Administrador(const Administrador &a);
	virtual ~Administrador();

	void MostrarAdmin();
};
#endif