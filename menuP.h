#ifndef _MENUP_H_
#define _MENUP_H_

#include "persona.h"
#include "administrador.h"
#include "usuario.h"
#include "iniReg.h"
#include "partida.h"
#include "juego.h"
#include "pAhorcado.h"
#include "pCalc.h"

#include <vector>

int MenuU(Usuario u);
int MenuA(Administrador a);
void ListaJuegos(vector <Juego> j, int control1);
int Jugar(vector <Juego> j,vector <PAhorcado> p1, vector <PCalc> p2, Persona p, int control1, int control2, int control3);
void PerfilU(Usuario u);
void PerfilA(Administrador a);
//void Estadisticas(pAhorcado* p1, pCalc * p2, int control1, int control2);
int SubirJuego(vector <Juego> j, Persona p, int control1);
void GestionAplicacion(vector <Juego> j, int control1);
bool  is_file_exist(const char *fileName);
#endif