using namespace std;
#include "iniReg.h"
//#include "ControlDatos.h"
//#include "MenuP.h"
#include "persona.h"
#include "administrador.h"
#include "usuario.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>



int IniciarSesion()
{
	string aux;
	vector <Usuario> users;
	vector <Administrador> admins;
	Persona pers;

Usuario userspr ("a","a","a","a",3) ;
Administrador adminspr ("a","a","a","a",3, "aaaaaa");
users.push_back(userspr);
admins.push_back(adminspr);

	cout << "Has decidido iniciar sesion," << endl;

	cout <<"Inserte el nick: "<< endl;
	aux=LeerValor(1,14);
	pers.setnick(aux);

	cout <<"Inserte la contrasena: " << endl;
	aux=LeerValor(1,14);
	pers.setcontra(aux);




	//users=LeerUsuariosBin(&control1);
	//admins=LeerAdministradoresBin(&control2);

	for(int i=0;users.size()>i;i++)
	{
		if((users[i].getnick().compare(pers.getnick()))==0&&(users[i].getcontra().compare(pers.getcontra()))==0)
		{
			if(users[i].getbloq())
			{
				cout << "Lo siento, ha sido bloqueado indefinidamente." << endl;
				return 0;
			}
			//return MenuU(users[i]);
			cout<< "funsiona papu!!";
		}
	}
	for(int i=0;admins.size()>i;i++)
	{
		if((admins[i].getnick().compare(pers.getnick()))==0&&(admins[i].getcontra().compare(pers.getcontra()))==0)
		{
			
			//return MenuA(admins[i]);
		}
	}
	
	return -1;
}


int Registrar()
{
	vector <Usuario> users;
	vector <Administrador> admins;
	Persona pers("per","a","a","a",1);

	int opcionRegistro;
	bool bienhecho;
	

	Usuario auxusu("usu","a","a","a",3) ;
	Administrador auxadmin ("adm","a","a","a",3, "aaaaaa");
	
	users.push_back(auxusu);
	admins.push_back(auxadmin);

	//users=LeerUsuariosBin(&control1);
	//admins=LeerAdministradoresBin(&control2);


	cout << "Has decidido registrarte," <<endl;
	cout << "Elige una opcion:\n 1.- Si deseas registrarte como un usuario. \n 2.- Si deseas registrarte como un administrador. "<< endl ;
	opcionRegistro=LeerValorInt(1,2);

	if(opcionRegistro==1)
	{
		Usuario usu ;
		cout << "Has elegido registrarte como un usuario." << endl;

		do
		{
			bienhecho=true;
			cout<<"Inserte el nick del usuario (de 1 a 14 caracteres): "<< endl;
			usu.setnick(LeerValor(1,14));

			for(int i=0;users.size()>i;i++)
			{
				if((usu.getnick().compare(users[i].getnick()))==0)
				{
					cout << "El nick ya existe." << endl;
					bienhecho=false;
				}
			}

			for(int i=0;admins.size()>i;i++)
			{
				if((usu.getnick().compare(admins[i].getnick()))==0)
				{
					cout << "El nick ya existe." << endl;
					bienhecho=false;
				}
			}
		}while(bienhecho==false);

		cout << "Inserte la contrasena del usuario (de 1 a 14 caracteres): "<< endl;
		usu.setcontra(LeerValor(1,14));


		cout << "Inserte el nombre del usuario (de 1 a 14 caracteres): " << endl;
		usu.setnombre(LeerValor(1,14));

		cout << "Inserte el apellido del usuario (de 1 a 14 caracteres): " << endl;
		usu.setapellido(LeerValor(1,14));

		cout << "Inserte la edad del usuario (de 1 a 100 anos): " << endl;
		usu.setedad(LeerValorInt(1,100));
		usu.setbloq(false);

		cout << usu.getedad();

		users.push_back(usu);

		//escribirUsuariosBin(users,control1+1);
		//return MenuU(usu);
		return 0;
	}
	else if(opcionRegistro)
	{
		Administrador admin;
		cout << "Has elegido registrarte como un administrador." << endl;
		
		do
		{
			bienhecho=true;
			cout << "Inserte el nick del administrador (de 1 a 14 caracteres): " << endl;
			admin.setnick(LeerValor(1,14));

			for(int i=0;users.size()>i;i++)
			{
				if(admin.getnick().compare(users[i].getnick())==0)
				{
					cout << "El nick ya existe." << endl;
					bienhecho=false;
				}
			}

			for(int i=0;admins.size()>i;i++)
			{
				if((admin.getnick().compare(admins[i].getnick()))==0)
				{
					cout << "El nick ya existe." << endl;
					bienhecho=false;
				}
			}
		}while(bienhecho==false);
		
		cout << "Inserte la contrasena del administrador (de 1 a 14 caracteres): "<< endl;
		admin.setcontra(LeerValor(1,14));

		cout << "Inserte el nombre del administrador (de 1 a 14 caracteres): " << endl;
		admin.setnombre(LeerValor(1,14));

		cout << "Inserte el apellido del administrador (de 1 a 14 caracteres): " << endl;
		admin.setapellido(LeerValor(1,14));

		cout << "Inserte la edad del administrador (de 1 a 100 anos): " << endl;
		admin.setedad(LeerValorInt(1,100));

		do
		{
			bienhecho=true;
			cout << "Inserte el codigo del administrador (debe tener 5 caracteres): "<< endl ;
			admin.setcod(LeerValor(5,5));

			for(int i=0;admins.size()>i;i++)
			{
				if((admin.getcod().compare(admins[i].getcod()))==0)
				{
					cout << "El codigo de administrador ya existe."<< endl ;
					bienhecho=false;
				}
			}
		}while(bienhecho==false);

		admins.push_back(admin);

		//escribirAdministradoresBin(admins,control2+1);
		//return MenuA(admin);

			return 0;
	}
}

string LeerValor(int i, int s)
{
	string w;
do
{
	getline(cin,w);

if(i>w.size() || w.size()>s)
{
cout << "este campo solo acepta palabra que tinen de " << i << " a " << s << " letras"<< endl;
}

}
while(i>w.size() || w.size()>s);
 
 return w;
}

int LeerValorInt(int i, int s)
{
	int aux;
	string aux2;
	bool control=true;

		do
		{
			getline(cin,aux2);
		try
		{


			aux=stoi(aux2);
			control=true;
			if(aux2.length()!=(to_string(aux).length()))
			{
				cout << "no se admite carcteres no numericos" << endl;
				control=false;
			}

		}
		catch(...)
		{
			cout << "introduce solo numeros comprendidos entre " << i << " y " << s << endl;
			control=false;
		}

		 }while( control==false || aux>s || aux<i);

return aux;
}
