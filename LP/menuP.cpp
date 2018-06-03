#include "menuP.h"

using namespace std;



int MenuU(Usuario u, GestorBD &db)
{
	int opcion;

	vector <Juego> juegos;
	vector <PAhorcado> pa;
	vector <PCalc> pc;
	vector <Partida> partida;

	pc=db.returnPCalc();
	pa=db.returnPAhorcado();
	partida=db.returnPartidas();
	juegos=db.returnJuegos();

	do
	{
	cout <<"Bienvenido a aPointlessApplication, eliga lo que desea hacer: \n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Cerrar sesion.\n 7.- Salir.\n";
	opcion=LeerValorInt(1,7);
	
		switch(opcion)
		{
			case 1:
				ListaJuegos(juegos);
				break;
			case 2:																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																		
				Jugar(juegos, partida, pa, pc, u,db);
				break;
			case 3:
				PerfilU(u);
				break;
			case 4:
				Estadisticas(pa, pc);
				break;
			case 5:
				SubirJuego(juegos, u, db);

				break;			
			case 6:
				cout <<"Se cerrara la sesion." << endl;
				return 0;
				break;
			case 7:
				return 1;
				break;
			default:
   				cout <<"Error! No es un numero o no es un numero adecuado!" << endl;
				break;

		}

	}while(true);
}

int MenuA(Administrador a, GestorBD &db)
{
	int opcion;
	
	vector <Juego> juegos;
	vector <PAhorcado> pa;
	vector <PCalc> pc;
	vector <Partida> partida;

	pc=db.returnPCalc();
	pa=db.returnPAhorcado();
	partida=db.returnPartidas();
	juegos=db.returnJuegos();

	do
	{
	cout <<"Bienvenido a aPointlessApplication, eliga lo que desea hacer: \n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Gestion de la aplicacion.\n 7.- Cerrar sesion.\n 8.- Salir." << endl;
	opcion=LeerValorInt(1,8);
		switch(opcion)
		{
			case 1:
				ListaJuegos(juegos);
				break;
			case 2:
				Jugar(juegos, partida, pa, pc, a, db);
				break;
			case 3:
				PerfilA(a);
				break;
			case 4:
				Estadisticas(pa, pc);
				break;
			case 5:
				SubirJuego(juegos, a, db);
				break;	
			case 6:
				GestionAplicacion(juegos,db);
				break;			
			case 7:
				cout <<"Se cerrara la sesion." << endl;
				return 0;
				break;
			case 8:
				return 1;
				break;
			default:

   				cout <<"Error! No es un numero o no es un numero adecuado!" << endl;
				break;
		}
	}while(true);
}

void ListaJuegos(vector <Juego> &j)
{
	int opcion;
	if(j.size()==0)
	{
		cout <<"No hay ningun juego introducido en la base de datos." << endl;
	}
	else
	{
	cout <<"Como quieres listar los juegos:\n 1.-Ordenar juegos por nombre de juego.\n 2.-Ordenar juegos por precio del juego." << endl;
	opcion=LeerValorInt(1,2);

 	if(opcion==1)
 	{
 		cout <<"Has decidido mostrar los juegos ordenados por nombre:" << endl;
 		OrdenarJuegoPorNombre(j);
 	}
 	else
 	{
 		cout <<"Has decidido mostrar los juegos ordenados por precio:" << endl;
		OrdenarJuegoPorPrecio(j);
 	}
 		for(int i=0;i<j.size();i++)
 		{
 			cout <<i+1<<".-";
			cout << j[i] << endl;
 		}
 	}
}

void Jugar(vector <Juego> &j, vector <Partida> &partida, vector <PAhorcado> &p1, vector <PCalc> &p2, Persona &p, GestorBD &db)
{
	int opcion, resultado;
	bool existe=false;

	if(j.size()==0)
	{
		cout <<"No hay ningun juego introducido en la base de datos." << endl;
	}
	else
	{
	cout << "Eliga uno de los juegos para jugar:" << endl;
	for(int i=0;i<j.size();i++)
	{
		cout <<i+1<<".-";
		cout << j[i] << endl;
	}
	opcion=LeerValorInt(1,j.size());
	opcion--;
	if((j[opcion].getEjecutable().compare("ahorcado.exe"))==0)
	{
		system("cls");
		//Para linux: system("clear"); 
		resultado=system(j[opcion].getEjecutable().c_str());

		for(int i=0;i<p1.size();i++)
		{
			if((p1[i].getJugador().compare(p.getnick()))==0)
			{
				p1[i].jugarPartida();
				if(resultado==1)
				{
					p1[i].ganarPartida();
				}
				db.deletePAhorcado(p1[i].getJugador(),p1[i].getJuego());
				db.insertNewPAhorcado(p1[i].getJugador(),p1[i].getJuego(),p1[i].getPJugadas(),p1[i].getPGanadas());
				existe=true;
				break;
			}
		}
		if(!existe)
		{
			PAhorcado auxAh(p.getnick(),j[opcion].getNombre(),1,resultado);
			p1.push_back(auxAh);
			db.insertNewPAhorcado(p1[p1.size()-1].getJugador(),p1[p1.size()-1].getJuego(),p1[p1.size()-1].getPJugadas(),p1[p1.size()-1].getPGanadas());
		}
		system("cls");
	}
	else if((j[opcion].getEjecutable().compare("CalcHumana.exe"))==0)
	{
		system("cls");
		//Para linux: system("clear"); 
		resultado=system(j[opcion].getEjecutable().c_str());
		existe=false;
		for(int i=0;i<p2.size();i++)
		{
			if((p2[i].getJugador().compare(p.getnick()))==0)
			{
				p2[i].jugarPartida();
				if(resultado>p2[i].getPMax())
				{
					p2[i].setPMax(resultado);
				}
				db.deletePCalc(p2[i].getJugador(),p2[i].getJuego());
				db.insertNewPCalc(p2[i].getJugador(),p2[i].getJuego(),p2[i].getPJugadas(),p2[i].getPMax());
				existe=true;
			}
		}
		if(!existe)
		{
			PCalc auxPc(p.getnick(),j[opcion].getNombre(),1,resultado);
			p2.push_back(auxPc);
			db.insertNewPCalc(p2[p2.size()-1].getJugador(),p2[p2.size()-1].getJuego(),p2[p2.size()-1].getPJugadas(),p2[p2.size()-1].getPMax());
		}
		system("cls");
	}
	else
	{
		system("cls");
		//Para linux: system("clear"); 
		system(j[opcion].getEjecutable().c_str());
		for(int i=0;i<partida.size();i++)
		{
			if((partida[i].getJugador().compare(p.getnick()))==0)
			{
				partida[i].jugarPartida();
				db.deletePartida(partida[i].getJugador(),partida[i].getJuego());
				db.insertNewPartidas(partida[i].getJugador(),partida[i].getJuego(),partida[i].getPJugadas());
				existe=true;
				break;
			}
		}
		if(!existe)
		{
			Partida auxP(p.getnick(),j[opcion].getNombre(),1);
			partida.push_back(auxP);
			db.insertNewPartidas(partida[partida.size()-1].getJugador(),partida[partida.size()-1].getJuego(),partida[partida.size()-1].getPJugadas());
		}	
	}
}
}


void PerfilU(Usuario u)
{
cout << "Este es tu perfil de usuario" << endl;
cout << u << endl;
}
void PerfilA(Administrador a)
{
cout <<"Este es tu perfil de administrador" << endl;
cout << a << endl;
}

void Estadisticas(vector <PAhorcado> &p1, vector <PCalc> &p2)
{
    int opcion;

    if(p1.size()==0&&p2.size()==0)
    {
    	cout << "No hay ninguna partida con estadisticas en la base de datos" << endl;
    }
    else
    {
    cout <<"De que juego desea mostrar estadisticas:\n 1.-Ahorcado.\n 2.-Calculadora Humana."<<endl;
    opcion=LeerValorInt(1,p1.size());
     cout << "En proceso. Proximamente."<<endl;

     if(opcion==1)
     {
         if(p1.size()==0)
         {
             cout <<"No hay estadisticas de ahorcado"<<endl;
         }

         else
         {
         cout <<"Has elegido mostrar las estadisticas del ahorcado, se ordenaran por partidas ganadas:" << endl;
         OrdenarAhorcadoPorPGanadas(p1);
         for(int i=0;i<p1.size();i++)
         {
             cout<< i+1<< ".-"<< endl;
            cout << p1[i] << endl;
         }
         }
     }
     else
     {
         if(p2.size()==0)
         {
             cout <<"No hay estadisticas de calculadora humana"<< endl;
         }
         else
         {
         cout <<"Has elegido mostrar las estadisticas de la calculadora humana, se ordenaran por puntuacion maxima:" << endl;
        OrdenarCalculadoraPorPuntMax(p2);
        for(int i=0;i<p2.size();i++)
         {
             cout <<i+1<<".-"<< endl;
            cout << p2[i] << endl;
         }
         }
     }
 	}
 }


void SubirJuego(vector <Juego> &j,  Persona &p, GestorBD &db)
{
	Juego ju;
	bool bienhecho;
	bool posible;
	bool existe;
	int i;
	fstream f;
	cout <<"Has decidido subir un juego."<< endl;
	do
	{
		bienhecho=true;
		cout <<"El nombre del juego es (de 1 a 14 caracteres):"<< endl;

		ju.setNombre(LeerValor(1,14));

		for(int i=0;j.size()>i;i++)
		{
			if((ju.getNombre().compare(j[i].getNombre()))==0)
			{
				cout <<"El nombre ya existe\n"<< endl;
				bienhecho=false;
			}
		}
	}while(bienhecho==false);

	cout <<"Inserte el genero del juego (de 1 a 14 caracteres): "<< endl;
	ju.setGenero(LeerValor(1,14));

	cout <<"Inserte el precio del juego (de 0 a 150 euros): "<< endl;
	ju.setPrecio(LeerValorInt(0,150));
	ju.setCreador(p);
	
	do
	{
		existe=true;
		bienhecho=true;
		cout <<"El ejecutable del juego es:"<< endl;
		ju.setEjecutable(LeerValor(0,40));
		for(int i=0;j.size()>i;i++)
		{
			if(ju.getEjecutable().compare(j[i].getEjecutable())==0)
			{
				cout <<"La aplicacion ya existe\n"<< endl;
				bienhecho=false;
			}
		}
	
		if(!is_file_exist(ju.getEjecutable().c_str()))
		{
			cout <<"La direccion no es correcta"<< endl;
			existe=false;
		}
	

	}while(bienhecho==false||existe==false);

	j.push_back(ju);
	db.insertNewJuegos(ju.getCreador().getnick(),ju.getNombre(),ju.getGenero(),ju.getEjecutable(), ju.getPrecio());
}

void GestionAplicacion(vector <Juego> &j,GestorBD &db )
{
	int opcion;
	cout <<"Cual de las opciones de administrador quiere ejecutar:\n 1.-Eliminar juegos de la plataforma.\n 2.-Bloquear/Desbloquear usuarios de la plataforma."<< endl;
	opcion=LeerValorInt(1,2);

 	if(opcion==1)
 	{ 
 		if(j.size()==0)
 		{
 			cout <<"No hay juegos registrados en la plataforma."<< endl;
 		}
 		else
 		{
 			cout <<"Has decidido borrar un juego de la plataforma, elige un numero de la lista:"<< endl;
 			for(int i=0;i<j.size();i++)
			{
				cout <<i+1<<".-";
				cout << j[i] << endl;
			}
			opcion=LeerValorInt(1,j.size());
 			opcion--;
 			db.deleteJuego(j[opcion].getNombre());
 		}
 	}
 	else
 	{
 		vector <Usuario> us;
 		us=db.returnUsuarios();

 		if(us.size()==0)
 		{
 			cout <<"No hay usuarios registrados en la plataforma."<< endl;
 		}
 		else
 		{
 			cout << "Has decidido bloquear/desbloquear un usuario de la plataforma, elige un numero de la lista:"<< endl;
 			for(int i=0;i<us.size();i++)
			{
				cout <<i+1<<".-";
				cout << us[i] << endl;
			}
			opcion=LeerValorInt(1,us.size());
 			opcion--;
 			if(us[opcion].getbloq()==true)
 			{
 				us[opcion].setbloq(false);
 			}
 			else
 			{
 				us[opcion].setbloq(true);
 			}
 			db.deleteUsuario(us[opcion].getnick());
 			db.insertNewUser(us[opcion].getnick(),us[opcion].getcontra(),us[opcion].getnombre(),us[opcion].getapellido(),us[opcion].getedad(),us[opcion].getbloq());
 		
 		}
 	}
 }

 bool  is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
 	
