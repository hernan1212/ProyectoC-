#ifndef _PERSONA_H_
#define _PERSONA_H_
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
		virtual ~Persona();

		string getnick();
		void setnick(string nick);

		string getcontra();
		void setcontra(string contra);

		string getnombre();
		void setnombre(string nombre);

		string getapellido();
		void setapellido(string apellido);

		int getedad();
		void setedad(int edad);
	};
#endif