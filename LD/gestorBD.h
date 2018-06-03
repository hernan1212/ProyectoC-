#ifndef _GESTORBD_H_
#define _GESTORBD_H_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

#include "../LN/usuario.h"
#include "../LN/administrador.h"
#include "../LN/juego.h"
#include "../LN/partida.h"
#include "../LN/pAhorcado.h"
#include "../LN/pCalc.h"
#include "sqlite3.h"

using namespace std;

class GestorBD
{
private:
	sqlite3 *db = NULL;
public:
	GestorBD(string dbFile);
	~GestorBD();

	int deleteJuego(string nombre);
	int deleteUsuario(string nick);
	int deletePartida(string nick, string nombre);
	int deletePAhorcado(string nick, string nombre);
	int deletePCalc(string nick, string nombre);

	vector <Usuario> returnUsuarios();
	vector <Administrador> returnAdministradores();
	vector <Juego> returnJuegos();
	vector <Partida> returnPartidas();
	vector <PAhorcado> returnPAhorcado();
	vector <PCalc> returnPCalc();

	int insertNewUser(string nick, string contra, string nombre, string apellido, int edad, bool bloq);
	int insertNewAdmins(string nick, string contra, string nombre, string apellido, int edad, string cod_administrador);
	int insertNewJuegos(string nick, string nombre, string genero, string ejecutable, int precio);
	int insertNewPartidas(string nick, string nombre, int PartidasJugadas);
	int insertNewPAhorcado(string nick, string nombre, int PartidasJugadas, int PartidasGanadas);
	int insertNewPCalc(string nick, string nombre, int PartidasJugadas, int PuntMax);

};

#endif