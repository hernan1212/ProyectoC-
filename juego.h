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

	Persona getCreador();
	void setCreador(Persona creador);

	string getNombre();
	void setNombre(string nombre);

	string getGenero();
	void setGenero(string genero);

	string getEjecutable();
	void setEjecutable(string ejecutable);

	int getPrecio();
	void setPrecio(int precio);

	void mostrarJuego();


};

#endif