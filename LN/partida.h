#ifndef _PARTIDA_H_
#define _PARTIDA_H_
#include <string>
#include <iostream>

using namespace std;

	class Partida
	{
	protected:
		string JugadorNick;
		string jName;
		int PartidasJugadas;
	public:
		Partida(string JugadorNick, string jName, int PartidasJugadas);
		Partida(const Partida &p);
		Partida();
		virtual ~Partida();

		string getJugador() const;
		void setJugador(string JugadorNick);

		string getJuego() const;
		void setJuego(string jName);

		int getPJugadas() const;
		void setPJugadas(int PartidasJugadas);

		void jugarPartida();
	};

	ostream& operator<<(ostream& out, const Partida& p);
#endif