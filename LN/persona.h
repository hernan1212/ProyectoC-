#ifndef _PERSONA_H_
#define _PERSONA_H_
#include <iostream>
#include <string>
using namespace std;
	class Persona
	{
	protected:

		string nick;
		string contra;
		string nombre;
		string apellido;

		int edad;

	public:
		Persona(string nick, string contra, string nombre, string apellido, int edad);
		Persona(const Persona &p);
		Persona();
		virtual ~Persona();

		string getnick() const;
		void setnick(string nick);

		string getcontra() const;
		void setcontra(string contra);

		string getnombre() const;
		void setnombre(string nombre);

		string getapellido() const;
		void setapellido(string apellido);

		int getedad() const;
		void setedad(int edad);
	};
#endif