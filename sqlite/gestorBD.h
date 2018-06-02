#ifndef _GESTORBD_H_
#define _GESTORBD_H_

#include <string>
#include <vector>
#include "../usuario.h"
#include "../administrador.h"
#include "../juego.h"
#include "../partida.h"
#include "../pAhorcado.h"
#include "../pCalc.h"
#include "sqlite3.h"

using namespace std;

class GestorBD
{
private:
	sqlite3 *db = NULL;
public:
	GestorBD(string dbFile);
	~GestorBD();

	int dropTable();
	int deleteAllUsers();
	int showAllUsers();
//	int showAllAdmins();
//	int showAllJuegos();
//	int showAllPartidas();
//	int showAllPAhorcado();
//	int showAllPCalc();

	vector <Usuario> returnUsuarios();
	vector <Administrador> returnAdministradores();
	vector <Juego> returnJuegos();
	vector <Partida> returnPartidas();
	vector <PAhorcado> returnPAhorcado();
	vector <PCalc> returnPCalc();

	int insertNewUser(string nick, string contra, string nombre, string apellido, int edad);
	int insertNewAdmins(string nick, string contra, string nombre, string apellido, int edad, string cod_administrador);
	int insertNewJuegos(string nick, string nombre, string genero, string ejecutable, int precio);
	int insertNewPartidas(string nick, string nombre, int PartidasJugadas);
	int insertNewPAhorcad(string nick, string nombre, int PartidasJugadas, int PartidasGanadas);
	int insertNewPCalc(string nick, string nombre, int PartidasJugadas, int PuntMax);

};

#endif