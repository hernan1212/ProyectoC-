#include "menuP.h"

using namespace std;

//#include "operaciones.h"

int MenuU(Usuario u, GestorBD db)
{
	int opcion;
	int control;
	int controlP1;
	int controlP2;


	vector <Juego> juegos;
	vector <PAhorcado> pa;
	vector <PCalc> pc;

	control=juegos.size();
	controlP1=pa.size();
	controlP2=pc.size();

	do
	{
	cout <<"Bienvenido a aPointlessApplication, eliga lo que desea hacer: \n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Cerrar sesion.\n 7.- Salir.\n";
	opcion=LeerValorInt(1,7);
									

	
		switch(opcion)
		{
			case 1:
				ListaJuegos(juegos,control);
				break;
			case 2:																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																		
				if(Jugar(juegos, pa, pc, u, control, controlP1, controlP2)==1)
				{
					//pa=LeerPartidasBin(&controlP1);
					//pc=LeerPartidasCBin(&controlP2);
				}
				break;
			case 3:
				PerfilU(u);
				break;
			case 4:
				//Estadisticas(pa, pc, controlP1, controlP2);
				break;
			case 5:
				control=SubirJuego(juegos, u, control);
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

int MenuA(Administrador a, GestorBD db)
{
	int opcion;
	int control;
	int controlP1;
	int controlP2;

	

	vector <Juego> juegos;
	vector <PAhorcado> pa;
	vector <PCalc> pc;

	control=juegos.size();
	controlP1=pa.size();
	controlP2=pc.size();

	do
	{
	cout <<"Bienvenido a aPointlessApplication, eliga lo que desea hacer: \n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Gestion de la aplicacion.\n 7.- Cerrar sesion.\n 8.- Salir." << endl;
	opcion=LeerValorInt(1,8);
		switch(opcion)
		{
			case 1:
				ListaJuegos(juegos, control);
				break;
			case 2:
				if(Jugar(juegos, pa, pc, a, control, controlP1, controlP2)==1)
				{
					//pa=LeerPartidasBin(&controlP1);
					//pc=LeerPartidasCBin(&controlP2);
				}
				break;
			case 3:
				PerfilA(a);
				break;
			case 4:
				//Estadisticas(pa, pc, controlP1, controlP2);
				break;
			case 5:
				control=SubirJuego(juegos, a, control);
				break;	
			case 6:
				GestionAplicacion(juegos, control);
				//juegos=LeerJuegosBin(&control);
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

void ListaJuegos(vector <Juego> j, int control1)
{
	int opcion;
	if(control1==0)
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
 		//OrdenarJuegoPorNombre(j, control1);
 	}
 	else
 	{
 		cout <<"Has decidido mostrar los juegos ordenados por precio:" << endl;
		//OrdenarJuegoPorPrecio(j, control1);
 	}
 		for(int i=0;i<control1;i++)
 		{
 			cout <<i+1<<".-";
			cout << j[i] << endl;
 		}
 	}
}
	
int Jugar(vector <Juego> j,vector <PAhorcado> p1, vector <PCalc> p2, Persona p, int control1, int control2, int control3)
{
	int opcion, resultado;
	bool existe=false;

	PAhorcado auxAh;
	PCalc auxPc;
	if(control1==0)
	{
		cout <<"No hay ningun juego introducido en la base de datos." << endl;
	}
	else
	{
	cout << "Eliga uno de los juegos para jugar:" << endl;
	for(int i=0;i<control1;i++)
	{
		cout <<i+1<<".-";
		cout << j[i] << endl;
	}
	opcion=LeerValorInt(1,control1+1);

	for(int i=0;i<control1;i++)
	{
		if(i==(opcion-1))
		{
			if((j[i].getEjecutable().compare("ahorcado.exe"))==0)
			{
			system("cls");
			//Para linux: system("clear"); 
			resultado=system(j[i].getEjecutable().c_str());
			for(int i=0;i<control2;i++)
			{
				if((p1[i].getJugador().compare(p.getnick()))==0)
				{
					p1[i].jugarPartida();
					if(resultado==1)
					{
						p1[i].ganarPartida();
					}
					existe=true;
				}
			}
			if(!existe)
			{
				auxAh.setJugador(p.getnick());
				auxAh.setPJugadas(1);
				auxAh.setPGanadas(resultado);
				auxAh.setJuego(j[i].getNombre());
			}

			system("cls");
			//escribirPartidasBin(p1,control2+1);
			return 1;
			}
			else if((j[i].getEjecutable().compare("CalcHumana.exe"))==0)
			{
			system("cls");
			//Para linux: system("clear"); 
			resultado=system(j[i].getEjecutable().c_str());
			existe=false;
			for(int i=0;i<control3;i++)
			{
				if((p2[i].getJugador().compare(p.getnick()))==0)
				{
					p2[i].jugarPartida();
					if(resultado>p2[i].getPMax())
					{
						p2[i].setPMax(resultado);
					}
					existe=true;
				}
			}
			if(!existe)
			{
				auxPc.setJugador(p.getnick());
				auxPc.setPJugadas(1);
				auxPc.setPMax(resultado);
				auxPc.setJuego(j[i].getNombre());
			}
			system("cls");
			//escribirPartidasCBin(p2,control3+1);
			return 1;
			}
			else
			{
			system("cls");
			//Para linux: system("clear"); 
			system(j[i].getEjecutable().c_str());
			system("cls");
			return 2;
			
		}
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

/*
void Estadisticas(pAhorcado* p1, pCalc * p2, int control1, int control2)
{
	int opcion;
	printf("De que juego desea mostrar estadisticas:\n 1.-Ahorcado.\n 2.-Calculadora Humana.\n");
	while (LeerValorInt(&opcion)==-1||(opcion<1||opcion>2)) 
	{
   		printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.-Ahorcado.\n 2.-Calculadora Humana.\n");       
 	}
 	printf("En proceso. Proximamente.");
/*
 	if(opcion==1)
 	{
 		if(control1==0)
 		{
 			printf("No hay estadisticas de ahorcado");
 		}

 		else
 		{
 		printf("Has elegido mostrar las estadisticas del ahorcado, se ordenaran por partidas ganadas:\n");
 		OrdenarAhorcadoPorPGanadas(p1, control1);
 		for(int i=0;i<control1;i++)
 		{
 			printf("%i.-",i+1);
			MostrarPartidaAhorcado(p1[i]);
 		}
 		}
 	}
 	else
 	{
 		if(control2==0)
 		{
 			printf("No hay estadisticas de calculadora humana");
 		}
 		else
 		{
 		printf("Has elegido mostrar las estadisticas de la calculadora humana, se ordenaran por puntuacion maxima:\n");
		OrdenarCalculadoraPorPuntMax(p2, control2);
		for(int i=0;i<control1;i++)
 		{
 			printf("%i.-",i+1);
			MostrarPartidaCalculadora(p2[i]);
 		}
 		}
 	}
 }
 */


int SubirJuego(vector <Juego> j,  Persona p, int control1)
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

		for(int i=0;control1>i;i++)
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
	ju.setPrecio(LeerValorInt(1,150));

	ju.setCreador(p);
	
	do
	{
		existe=true;
		bienhecho=true;
		cout <<"El ejecutable del juego es:"<< endl;
		ju.setEjecutable(LeerValor(0,4));
		for(int i=0;control1>i;i++)
		{
			if(ju.getEjecutable().compare(j[i].getEjecutable())==0)
			{
				cout <<"La aplicacion ya existe\n"<< endl;
				bienhecho=false;
			}
		}
	
		if(is_file_exist(ju.getEjecutable().c_str()))
		{
			cout <<"La direccion no es correcta"<< endl;
			existe=false;
		}
	

	}while(bienhecho==false||existe==false);

	//j[control1]=ju;
	//escribirJuegosBin(j,control1+1);
	return control1+1;
}

void GestionAplicacion(vector <Juego> j, int control1)
{
	int opcion;
	cout <<"Cual de las opciones de administrador quiere ejecutar:\n 1.-Eliminar juegos de la plataforma.\n 2.-Bloquear/Desbloquear usuarios de la plataforma."<< endl;
	opcion=LeerValorInt(1,2);

 	if(opcion==1)
 	{ 
 		if(control1==0)
 		{
 			cout <<"No hay juegos registrados en la plataforma."<< endl;
 		}
 		else
 		{
 			cout <<"Has decidido borrar un juego de la plataforma, elige un numero de la lista:"<< endl;
 			for(int i=0;i<control1;i++)
			{
				cout <<i+1<<".-";
				cout << j[i] << endl;
			}
			opcion=LeerValorInt(1,control1);
 			opcion--;
 			for(int i=0;i<(control1-1);i++)
 			{
 				if(i >= opcion)
 				{
 					j[i]=j[i+1];
 				}
 				else
 				{
 					j[i]=j[i];
 				}
 			}
 			//escribirJuegosBin(j, control1-1);
 		}
 		

 	}
 	else
 	{
 		Usuario* us;
 		int control2;
 		//us=(Usuario*)malloc(sizeof(Usuario)*30);
 		//us=LeerUsuariosBin(&control2);
 		if(control2==0)
 		{
 			cout <<"No hay usuarios registrados en la plataforma."<< endl;
 		}
 		else
 		{
 			cout << "Has decidido bloquear/desbloquear un usuario de la plataforma, elige un numero de la lista:"<< endl;
 			for(int i=0;i<control2;i++)
			{
				cout <<i+1<<".-";
				cout << us[i] << endl;
			}
			opcion=LeerValorInt(1,control1);
			{
   				cout <<"Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion, eligiendo un numero de la lista:"<< endl;
   				for(int i=0;i<control2;i++)
				{
					cout <<i+1<<".-";
					cout << us[i] << endl;

				}
 			}
 			opcion--;
 			if(us[opcion].getbloq()==true)
 			{
 				us[opcion].setbloq(false);
 			}
 			else
 			{
 				us[opcion].setbloq(true);
 			}
 			//escribirUsuariosBin(us, control2);
 		
 		}
 	}
 }

 bool  is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
 	
