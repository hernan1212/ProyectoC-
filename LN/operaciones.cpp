#include "operaciones.h"





bool pganadas(PAhorcado i, PAhorcado j)	{return(i.getPGanadas()>j.getPGanadas());}

bool pmax(PCalc i, PCalc j)	{return(i.getPMax()>j.getPMax());}

bool compNombre(Juego i, Juego j)	{return(i.getNombre().compare(j.getNombre())<0);}

bool compPrecio(Juego i, Juego j)	{return(i.getPrecio()>j.getPrecio());}

void OrdenarJuegoPorNombre(vector <Juego> &j)	{sort(j.begin(),j.end(),compNombre);}

void OrdenarJuegoPorPrecio(vector <Juego> &j)	{sort(j.begin(),j.end(),compPrecio);}

void OrdenarAhorcadoPorPGanadas(vector <PAhorcado> &p) {sort(p.begin(),p.end(),pganadas);}

void OrdenarCalculadoraPorPuntMax(vector <PCalc> &p) {sort(p.begin(),p.end(),pmax);}