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



int IniciarSesion()
{
	string aux;
	vector <Usuario> users;
	vector <Administrador> admins;
	Persona pers("a","a","a","a",1);

Usuario userspr ("a","a","a","a",3) ;
Administrador adminspr ("a","a","a","a",3, "aaaaaa");
users.push_back(userspr);
admins.push_back(adminspr);

	cout << "Has decidido iniciar sesion," << endl;

	cout <<"Inserte el nick: "<< endl;
	aux=LeerValor();
	pers.setnick(aux);

	cout <<"Inserte la contrasena: " << endl;
	aux=LeerValor();
	pers.setcontra(aux);


int wololo =LeerValorInt(0,100);

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

/* 
int Registrar()
{
	Usuario* users;
	Administrador* admins;
	Persona pers;
	int opcionRegistro,control1,control2;
	bool bienhecho;
	
	cout << "Has decidido registrarte," <<endl;
	cout << "Elige una opcion:\n 1.- Si deseas registrarte como un usuario. \n 2.- Si deseas registrarte como un administrador. "<< endl ;
	while(!(cin.fail()==0)||(opcionRegistro<1||opcionRegistro>2))
	{
	}
	//users=LeerUsuariosBin(&control1);
	//admins=LeerAdministradoresBin(&control2);

	if(opcionRegistro==1)
	{
		Usuario usu;
		cout << "Has elegido registrarte como un usuario." << endl;

		do
		{
			bienhecho=true;
			cout<<"Inserte el nick del usuario (de 1 a 14 caracteres): "<< endl;
			if(LeerValor(pers.nick,14)==-1)
			{

				cout << "El nick no es adecuado."<< endl;
				bienhecho=false;
			}
			for(int i=0;control1>i;i++)
			{
				if(strcmp(pers.nick,users[i].pers.nick)==0)
				{
					cout << "El nick ya existe." << endl;
					bienhecho=false;
				}
			}

			for(int i=0;control2>i;i++)
			{
				if(strcmp(pers.nick,admins[i].pers.nick)==0)
				{
					cout << "El nick ya existe." << endl;
					bienhecho=false;
				}
			}
		}while(bienhecho==false);

		cout << "Inserte la contrasena del usuario (de 1 a 14 caracteres): "<< endl;
		while(LeerValor(pers.contra,14)==-1)
		{
			cout << "La contrasena no es adecuada." << endl;
			cout << "Inserte la contrasena del usuario (de 1 a 14 caracteres): " << endl;
		}

		cout << "Inserte el nombre del usuario (de 1 a 14 caracteres): " << endl;
		while(LeerValor(pers.nombre,14)==-1)
		{
			cout << ("El nombre no es adecuado." << endl;
			cout << "Inserte el nombre del usuario (de 1 a 14 caracteres): "<< endl;
		}

		cout << "Inserte el apellido del usuario (de 1 a 14 caracteres): " << endl;
		while(LeerValor(pers.apellido,14)==-1)
		{
			cout << "El apellido no es adecuado." << endl;
			cout << "Inserte el apellido del usuario (de 1 a 14 caracteres): " << endl;
		}

		cout << "Inserte la edad del usuario (de 1 a 100 anos): " << endl;
		while(LeerValorInt(&pers.edad)==-1||pers.edad<1||pers.edad>100)
		{
			cout << "La edad no cumple las condiciones."<< endl;
			cout << "Inserte la edad del usuario (de 1 a 100 anos): "<< endl;
		}
		usu.pers=pers;
		usu.bloq=false;
		users[control1]=usu;
		escribirUsuariosBin(users,control1+1);
		free(users);
		free(admins);
		return MenuU(usu);
	}
	else if(opcionRegistro)
	{
		Administrador admin;
		cout << "Has elegido registrarte como un administrador." << endl;
		
		do
		{
			bienhecho=true;
			cout << "Inserte el nick del administrador (de 1 a 14 caracteres): " << endl;
			if(LeerValor(pers.nick,14)==-1)
			{
				cout << "El nick no es adecuado." << endl;
				bienhecho=false;
			}
			for(int i=0;control1>i;i++)
			{
				if(strcmp(pers.nick,users[i].pers.nick)==0)
				{
					cout << "El nick ya existe." << endl;
					bienhecho=false;
				}
			}

			for(int i=0;control2>i;i++)
			{
				if(strcmp(pers.nick,admins[i].pers.nick)==0)
				{
					cout << "El nick ya existe." << endl;
					bienhecho=false;
				}
			}
		}while(bienhecho==false);
		
		cout << "Inserte la contrasena del administrador (de 1 a 14 caracteres): " << endl;
		while(LeerValor(pers.contra,14)==-1)
		{
			cout << "La contrasena no es adecuada."<< endl ;
			cout << "Inserte la contrasena del administrador (de 1 a 14 caracteres):"<< endl ;
		}
			
		cout << "Inserte el nombre del administrador (de 1 a 14 caracteres):"<< endl ;
		while(LeerValor(pers.nombre,14)==-1)
		{
			cout << "El nombre no es adecuado."<< endl ;
			cout << "Inserte el nombre del administrador (de 1 a 14 caracteres): "<< endl ;
		}
			
		cout << "Inserte el apellido del administrador (de 1 a 14 caracteres):"<< endl ;
		{
			cout << "El apellido no es adecuado."<< endl ;
			cout << "Inserte el apellido del administrador (de 1 a 14 caracteres): "<< endl ;
		}
		
		cout << "Inserte la edad del administrador (de 1 a 100 anos): "<< endl ;
		while(LeerValorInt(&pers.edad)==-1||pers.edad<1||pers.edad>100)
		{
			cout << "La edad no cumple las condiciones."<< endl ;
			cout << "Inserte la edad del administrador (de 1 a 100 anos): "<< endl ;
		}

		do
		{
			bienhecho=true;
			cout << "Inserte el codigo del administrador (debe tener 5 caracteres): "<< endl ;
			if(LeerValor(admin.cod_administrador,5)==-1||strlen(admin.cod_administrador)!=5)
			{
				cout << "El codigo de administrador no cumple las condiciones."<< endl ;
				bienhecho=false;
			}
			for(int i=0;control2>i;i++)
			{
				if(strcmp(admin.cod_administrador,admins[i].cod_administrador)==0)
				{
					cout << "El codigo de administrador ya existe."<< endl ;
					bienhecho=false;
				}
			}
		}while(bienhecho==false);
		admin.pers=pers;
		admins[control2]=admin;
		escribirAdministradoresBin(admins,control2+1);
		free(users);
		free(admins);
		return MenuA(admin);
	}
}
*/
string LeerValor()
{
	string s;
do
{
cin >>s;

if(0>s.size() || s.size()>14)
{
cout << "el tamano es incorrecto, (maximo 14 letras) intentalo de neuvo"<< endl;
}

}
while(0>s.size() || s.size()>14);
 
 return s;
}

int LeerValorInt(int i, int s)
{
	int aux;
		cout << "introduce un numero entre " << i << "y"<< s << endl;
	cin>>aux;


		while(!(cin.fail()==0) || aux>s || aux<i)
		{
			cout << "introduce solo numeros comprendidos entre" << i << " y " << s << endl;
			cin.clear();
			cin.ignore(256,'\n');
			cin>>aux;
		}

return aux;
}
