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
void ListaJuegos(vector <Juego> j, int control1);
int Jugar(vector <Juego> j,vector <PAhorcado> p1, vector <PCalc> p2, Persona p, int control1, int control2, int control3,GestorBD &db);
void PerfilU(Usuario u);
void PerfilA(Administrador a);
//void Estadisticas(pAhorcado* p1, pCalc * p2, int control1, int control2);
int SubirJuego(vector <Juego> j, Persona p, int control1,GestorBD &db);
void GestionAplicacion(vector <Juego> j,GestorBD &db);
bool  is_file_exist(const char *fileName);
#endif