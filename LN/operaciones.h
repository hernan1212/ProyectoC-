#ifndef _OPERACIONES_H_
#define _OPERACIONES_H_



#include <iostream>
#include <string>
#include <algorithm>

#include "persona.h"
#include "partida.h"
#include "juego.h"
#include "administrador.h"
#include "usuario.h"
#include "pAhorcado.h"
#include "pCalc.h"
#include "../LP/menuP.h"

void OrdenarJuegoPorNombre(vector <Juego> &j);
void OrdenarJuegoPorPrecio(vector <Juego> &j);
void OrdenarAhorcadoPorPGanadas(vector <PAhorcado> &p);
void OrdenarCalculadoraPorPuntMax(vector <PCalc> &p);
bool compPrecio(Juego i, Juego j);
bool compNombre(Juego i, Juego j);
bool compNpganadasombre(PAhorcado i, PAhorcado j);
bool pmax(PCalc i, PCalc j);



#endif