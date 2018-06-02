#ifndef _USUARIO_H_
#define _USUARIO_H_
#include <string>
#include "persona.h"

class Usuario: public Persona
{
private:
	bool bloq;

public:
	Usuario(string nick, string contra, string nombre, string apellido, int edad);
	Usuario(const Usuario &u);
	Usuario();
	virtual ~Usuario();

	bool getbloq() const;
	void setbloq(bool bloq);
};

ostream& operator<<(ostream& out, const Usuario& u);
#endif