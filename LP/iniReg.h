#ifndef _INIREG_H_
#define _INIREG_H_

#include "../LD/gestorBD.h"
#include "menuP.h"
#include "../LN/persona.h"
#include "../LN/administrador.h"
#include "../LN/usuario.h"

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
	
int IniciarSesion();
int Registrar();
string LeerValor(unsigned int i, unsigned int s);
int LeerValorInt(unsigned int i, unsigned int s);
#endif