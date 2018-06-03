#include "operaciones.h"




void OrdenarAhorcadoPorPGanadas(vector <PAhorcado> p)
{
	PAhorcado p1;
	int k, i, z;
	for(i=0; i<p.size()-1;i++)
	{
		for(k=i, z=i+1;z<p.size();z++)
		{
			if(p[z].getPGanadas()>p[k].getPGanadas())
			{
				k=z;
			}
		}
		if(k!=i)
		{
			p1=p[i];
			p[i]=p[k];
			p[k]=p1;
		}
	}
}
void OrdenarCalculadoraPorPuntMax(vector <PCalc> p)
{
	PCalc p1;
	int k, i, z;
	for(i=0; i<p.size()-1;i++)
	{
		for(k=i, z=i+1;z<p.size();z++)
		{
			if(p[z].getPMax()>p[k].getPMax())
			{
				k=z;
			}
		}
		if(k!=i)
		{
			p1=p[i];
			p[i]=p[k];
			p[k]=p1;
		}
	}
}

bool compNombre(Juego i, Juego j)	{return(i.getNombre().compare(j.getNombre())<0);}

bool compPrecio(Juego i, Juego j)	{return(i.getPrecio()>j.getPrecio());}

void OrdenarJuegoPorNombre(vector <Juego> &j)	{sort(j.begin(),j.end(),compNombre);}

void OrdenarJuegoPorPrecio(vector <Juego> &j)	{sort(j.begin(),j.end(),compPrecio);}
