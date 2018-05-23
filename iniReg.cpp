using namespace std;
#include "IniReg.h"
#include "ControlDatos.h"
#include "MenuP.h"
#include "Persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int IniciarSesion()
{
	int control1,control2;	
	Usuario* users;
	Administrador* admins;
	Persona pers;

	cout << "Has decidido iniciar sesion," << endl;
	cout <<"Inserte el nick: "<< endl;
	//LeerValor(pers.nick,14);
	cout <<"Inserte la contrasena: " zz endl;
	//LeerValor(pers.contra,14);
	//users=LeerUsuariosBin(&control1);
	//admins=LeerAdministradoresBin(&control2);
	for(int i=0;control1>i;i++)
	{
		if(strcmp(users[i].pers.nick,pers.nick)==0&&strcmp(users[i].pers.contra,pers.contra)==0)
		{
			if(users[i].bloq)
			{
				cout << "Lo siento, ha sido bloqueado indefinidamente." << endl;
				return 0;
			}
			free(users);
			free(admins);
			return MenuU(users[i]);
		}
	}
	for(int i=0;control2>i;i++)
	{
		if(strcmp(admins[i].pers.nick,pers.nick)==0&&strcmp(admins[i].pers.contra,pers.contra)==0)
		{
			free(users);
			free(admins);
			return MenuA(admins[i]);
		}
	}
	free(users);
	free(admins);
	return -1;
}

int Registrar()
{
	Usuario* users;
	Administrador* admins;
	Persona pers;
	int opcionRegistro,control1,control2;
	bool bienhecho;
	
	cout << "Has decidido registrarte," <<endl;
	cout << "Elige una opcion:\n 1.- Si deseas registrarte como un usuario. \n 2.- Si deseas registrarte como un administrador. "<< endl ;
	while(LeerValorInt(&opcionRegistro)==-1||(opcionRegistro<1||opcionRegistro>2))
	{
		cout << " Te has confundido. Vuelve a elegir una opcion:\n 1.- Si deseas registrarte como un usuario. \n 2.- Si deseas registrarte como un administrador. " << endl;
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

int LeerValor(char * h, int lenMax)
{
	char* line=NULL;
	size_t len = 0;
	ssize_t read;

	while((read = getline(&line, &len, stdin))) 
	{
		if(strlen(line)>(lenMax+1)||strcmp(line,"\n")==0)
		{	
   			return -1;
		}
		else
		{
			sscanf(line, "%s", h);
			return 0;
		}
  	}
}
int LeerValorInt(int* h)
{
	char* line=NULL;
	size_t len = 0;
	ssize_t read;

	while((read = getline(&line, &len, stdin))) 
	{
		if(sscanf(line, "%i", h)==1)
		{	
   			return 0;
		}
		else
		{
			return -1;
		}
  	}
}