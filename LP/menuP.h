#ifndef _MENUP_H_
#define _MENUP_H_

#include "iniReg.h"
#include "../LD/gestorBD.h"
#include "../LN/persona.h"
#include "../LN/administrador.h"
#include "../LN/usuario.h"
#include "../LN/partida.h"
#include "../LN/juego.h"
#include "../LN/pAhorcado.h"
#include "../LN/pCalc.h"
#include "../LN/operaciones.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int MenuU(Usuario u, GestorBD &db);
int MenuA(Administrador a, GestorBD &db);
void ListaJuegos(vector <Juego> &j);
void Jugar(vector <Juego> &j, vector <Partida> &partida, vector <PAhorcado> &p1, vector <PCalc> &p2, Persona &p, GestorBD &db);
void PerfilU(Usuario u);
void PerfilA(Administrador a);
void Estadisticas(vector <PAhorcado> &p1, vector <PCalc> &p2);
void SubirJuego(vector <Juego> &j, Persona &p, GestorBD &db);
void GestionAplicacion(vector <Juego> &j,GestorBD &db);
bool  is_file_exist(const char *fileName);
#endif