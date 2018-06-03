#include <iostream>

#include "LN/persona.h"
#include "LN/juego.h"
#include "LP/iniReg.h"

using namespace std;

int main(void)
{
int opcion,resultado;

do
	{
		cout <<"Introduce una opcion que desea hacer y recuerda que si no tienes una cuenta debes registrarte: \n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir." << endl ;

		opcion=LeerValorInt(1,3);
		switch(opcion)
		{
			case 1:
				resultado=IniciarSesion();
				if(resultado==1)
				{
					opcion=3;
				}
				else
				{
					if(resultado==-1)
					{
						cout <<"El usuario o la contrasena no son correctos, intentalo otra vez." << endl;
					}
				}
				break;
			case 2:
				resultado=Registrar();
				if(resultado==1)
				{
					opcion=3;
				}
				break;
			case 3:
				cout << "La aplicacion se cerrara!"<< endl;
				break;
			default:
				cout << "Error! No es un numero o no es un numero adecuado!" << endl;
				break;
		}
	}while(opcion!=3);



	return 0;
}