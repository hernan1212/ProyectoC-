#ifndef _JUEGO_H_
#define _JUEGO_H_

#include <string>
#include "persona.h"

class Juego
{
private:
	Persona creador;
	string nombre;
	string genero;
	string ejecutable;
	int precio;

public:

	Juego(Persona creador, string nombre, string genero, string ejecutable, int precio);
	Juego(const Juego &j);
	Juego();
	virtual ~Juego();

	Persona getCreador() const;
	void setCreador(Persona creador);

	string getNombre() const;
	void setNombre(string nombre);

	string getGenero() const;
	void setGenero(string genero);

	string getEjecutable() const;
	void setEjecutable(string ejecutable);

	int getPrecio() const;
	void setPrecio(int precio);
};

	ostream& operator<<(ostream& out, const Juego& j);

#endif