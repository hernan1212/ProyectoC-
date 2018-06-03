#ifndef _ADMINISTRADOR_H_
#define _ADMINISTRADOR_H_
#include <iostream>
#include <string>
#include "persona.h"

class Administrador: public Persona
{
private:
	string cod_administrador;

public:
	Administrador(string nick, string contra, string nombre, string apellido, int edad, string cod_administrador);
	Administrador(const Administrador &a);
	Administrador();
	virtual ~Administrador();

	string getcod() const;
	void setcod(string cod_administrador);
};

ostream& operator<<(ostream& out, const Administrador& a);
#endif