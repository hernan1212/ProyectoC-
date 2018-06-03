
#include "GestorBD.h"

GestorBD::GestorBD(string dbFile) 
{
  int result = sqlite3_open(dbFile.c_str(), &db);
  if (result != SQLITE_OK) 
  {
    std::cout << "Error opening database" << std::endl;
  }
    // Crate table country
    const char * sql= new char();
    sql = "CREATE TABLE usuario(nick TEXT, contra TEXT, nombre TEXT, apellido TEXT, edad INT, bloq INT);";

    result = sqlite3_exec(db, sql, 0, 0, NULL);

    sql = "CREATE TABLE administrador(nick TEXT, contra TEXT, nombre TEXT, apellido TEXT, edad INT, cod_administrador TEXT);";

    result = sqlite3_exec(db, sql, 0, 0, NULL);

    sql = "CREATE TABLE juego(nick TEXT, nombre TEXT, genero TEXT, ejecutable TEXT, precio INT);";

    result = sqlite3_exec(db, sql, 0, 0, NULL);

    sql = "CREATE TABLE partida(nick TEXT, nombre TEXT, PartidasJugadas INT);";

    result = sqlite3_exec(db, sql, 0, 0, NULL);

    sql = "CREATE TABLE pAhorcado(nick TEXT, nombre TEXT, PartidasJugadas INT, PartidasGanadas INT);";

    result = sqlite3_exec(db, sql, 0, 0, NULL);

    sql = "CREATE TABLE pCalc(nick TEXT, nombre TEXT, PartidasJugadas INT, PuntMax Int);";

    result = sqlite3_exec(db, sql, 0, 0, NULL);
  }
  
  GestorBD::~GestorBD() {
    int result = sqlite3_close(db);
  }

  int GestorBD::dropTable() 
  {
    sqlite3_stmt *stmt;

    char sql[] = "DROP TABLE IF EXISTS usuario;";
    int result = sqlite3_exec(db, sql, 0, 0, NULL);

    if (result != SQLITE_OK) {
      std::cout << "Error executing DROP" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }

  vector <Usuario> GestorBD::returnUsuarios()
  {
    sqlite3_stmt *stmt;
    vector <Usuario> usus;

    char sql[] = "select nick, contra, nombre, apellido, edad, bloq from usuario";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (result != SQLITE_OK) 
    {    
      std::cout << sqlite3_errmsg(db) << std::endl;
      return usus;
    }


    char nick[100];
    char contra[100];
    char nombre[100];
    char apellido[100];
    int edad;
    bool bloq;

    do {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) {
    strcpy(nick, (char *) sqlite3_column_text(stmt, 0));
    strcpy(contra, (char *) sqlite3_column_text(stmt, 1));
    strcpy(nombre, (char *) sqlite3_column_text(stmt, 2));
    strcpy(apellido, (char *) sqlite3_column_text(stmt, 3));
    edad = sqlite3_column_int(stmt, 4);
    Usuario u(nick, contra, nombre, apellido, edad);

        if(sqlite3_column_int(stmt, 5)==1)
        {
          u.setbloq(true);
        }
        else
        {
          u.setbloq(false);
        }
    usus.push_back(u);
    }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << sqlite3_errmsg(db) << std::endl;
      return usus;
    }
    return usus;
  }

  vector <Administrador> GestorBD::returnAdministradores()
  {
    sqlite3_stmt *stmt;
    vector <Administrador> admins;

    char sql[] = "select nick, contra, nombre, apellido, edad, cod_administrador from administrador";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

     if (result != SQLITE_OK) {   
      std::cout << sqlite3_errmsg(db) << std::endl;
      return admins;
    }

    char nick[100];
    char contra[100];
    char nombre[100];
    char apellido[100];
    char cod_administrador[100];
    int edad;

    do {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) {
    strcpy(nick, (char *) sqlite3_column_text(stmt, 0));
    strcpy(contra, (char *) sqlite3_column_text(stmt, 1));
    strcpy(nombre, (char *) sqlite3_column_text(stmt, 2));
    strcpy(apellido, (char *) sqlite3_column_text(stmt, 3));
    edad = sqlite3_column_int(stmt, 4);
    strcpy(cod_administrador, (char *) sqlite3_column_text(stmt, 5));
    Administrador a(nick, contra, nombre, apellido, edad, cod_administrador);
    admins.push_back(a);
   }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << sqlite3_errmsg(db) << std::endl;
      return admins;
    }

    return admins;
  }

    vector <Juego> GestorBD::returnJuegos()
  {
    sqlite3_stmt *stmt;
    sqlite3_stmt *stmt2;
    vector <Juego> juegos;
    int result2;

    string sql = "select nick, nombre, genero, ejecutable, precio from juego";

    int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {     
      std::cout << sqlite3_errmsg(db) << std::endl;
      return juegos;
    }

    char nick[100];
    char nombre[100];
    char genero[100];
    char ejecutable[100];
    int precio;
    char nickP[100];
    char contraP[100];
    char nombreP[100];
    char apellidoP[100];
    int edad;

    do {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) {
    strcpy(nick, (char *) sqlite3_column_text(stmt, 0));
    strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
    strcpy(genero, (char *) sqlite3_column_text(stmt, 2));
    strcpy(ejecutable, (char *) sqlite3_column_text(stmt, 3));
    precio = sqlite3_column_int(stmt, 4);



    string aux1("select nick, contra, nombre, apellido, edad from usuario where nick=\"");
    string aux3("\"");
    sql = aux1 + nick + aux3;    
    result2 = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt2, NULL);
    if (result2 != SQLITE_OK) {    
      std::cout << sqlite3_errmsg(db) << std::endl;
      return juegos;
    }
    result2 = sqlite3_step(stmt2);
    if (!(result2 == SQLITE_ROW))
    {
      string aux2("select nick, contra, nombre, apellido, edad from administrador where nick=\"");
      sql = aux2 + nick + aux3;    
      result2 = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt2, NULL);
      if (result2 != SQLITE_OK) {     
        std::cout << sqlite3_errmsg(db) << std::endl;
        return juegos;
      }
    }
    
    strcpy(nickP, (char *) sqlite3_column_text(stmt2, 0));
    strcpy(contraP, (char *) sqlite3_column_text(stmt2, 1));
    strcpy(nombreP, (char *) sqlite3_column_text(stmt2, 2));
    strcpy(apellidoP, (char *) sqlite3_column_text(stmt2, 3));
    edad = sqlite3_column_int(stmt2, 4);
    Persona p(nickP, contraP, nombreP, apellidoP, edad);

    Juego j(p, nombre, genero, ejecutable, precio);
    juegos.push_back(j);
    result2 = sqlite3_finalize(stmt2);
    if (result2 != SQLITE_OK) {
      std::cout << sqlite3_errmsg(db) << std::endl;
      return juegos;
    }  
      }
    } while (result == SQLITE_ROW);


    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << sqlite3_errmsg(db) << std::endl;
      return juegos;
    }

    return juegos;
  }

  vector <Partida> GestorBD::returnPartidas()
  {
    sqlite3_stmt *stmt;
    vector <Partida> partidas;

    char sql[] = "select nick, nombre, PartidasJugadas from partida";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {      
      std::cout << sqlite3_errmsg(db) << std::endl;
      return partidas;
    }

    char nick[100];
    char nombre[100];
    int PartidasJugadas;

    do {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) {
    strcpy(nick, (char *) sqlite3_column_text(stmt, 0));
    strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
    PartidasJugadas = sqlite3_column_int(stmt, 2);
    Partida p(nick, nombre, PartidasJugadas);
    partidas.push_back(p);
    std::cout << p <<std::endl;
      }
    } while (result == SQLITE_ROW);

    std::cout << std::endl;
    std::cout << std::endl;

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << sqlite3_errmsg(db) << std::endl;
      return partidas;
    }

    return partidas;
  }

  vector <PAhorcado> GestorBD::returnPAhorcado()
  {
    sqlite3_stmt *stmt;
    vector <PAhorcado> pAs;

    char sql[] = "select nick, nombre, PartidasJugadas, PartidasGanadas from pAhorcado";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {     
      std::cout << sqlite3_errmsg(db) << std::endl;
      return pAs;
    }

    char nick[100];
    char nombre[100];
    int PartidasJugadas;
    int PartidasGanadas;

    do {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) {
    strcpy(nick, (char *) sqlite3_column_text(stmt, 0));
    strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
    PartidasJugadas = sqlite3_column_int(stmt, 2);
    PartidasGanadas = sqlite3_column_int(stmt, 3);
    PAhorcado pA(nick, nombre, PartidasJugadas, PartidasGanadas);
    pAs.push_back(pA);
    std::cout << pA <<std::endl;
      }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << sqlite3_errmsg(db) << std::endl;
      return pAs;
    }

    return pAs;
  }

  vector <PCalc> GestorBD::returnPCalc()
  {
    sqlite3_stmt *stmt;
    vector <PCalc> pCs;

    char sql[] = "select nick, nombre, PartidasJugadas, PuntMax from pCalc";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {     
      std::cout << sqlite3_errmsg(db) << std::endl;
      return pCs;
    }

    char nick[100];
    char nombre[100];
    int PartidasJugadas;
    int PuntMax;

    do {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) {
    strcpy(nick, (char *) sqlite3_column_text(stmt, 0));
    strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
    PartidasJugadas = sqlite3_column_int(stmt, 2);
    PuntMax = sqlite3_column_int(stmt, 3);
    PCalc pC(nick, nombre, PartidasJugadas, PuntMax);
    pCs.push_back(pC);
    std::cout << pC <<std::endl;
      }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << sqlite3_errmsg(db) << std::endl;
      return pCs;
    }

    return pCs;
  }

  int GestorBD::deleteJuego(string nombre) {
    sqlite3_stmt *stmt;

    string sql= ("delete from juego where nombre=\"" + nombre + "\"").c_str();

    int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error deleting data (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }

  int GestorBD::deleteUsuario(string nick)
  {
   sqlite3_stmt *stmt;

    string sql= ("delete from usuario where nick=\"" + nick + "\"").c_str();

    int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error deleting data (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }
  int GestorBD::deletePartida(string nick, string nombre)
  {
    sqlite3_stmt *stmt;

 string sql= ("delete from partida where nombre=\"" + nombre + "\" &&  nick=\"" + nick + "\"").c_str();

    int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error deleting data (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }
  int GestorBD::deletePAhorcado(string nick, string nombre)
  {
    sqlite3_stmt *stmt;

    string sql= ("delete from pAhorcado where nombre=\"" + nombre + "\" &&  nick=\"" + nick + "\"").c_str();

    int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error deleting data (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }
  int GestorBD::deletePCalc(string nick, string nombre)
  {
    sqlite3_stmt *stmt;

    string sql= ("delete from pCalc where nombre=\"" + nombre + "\" &&  nick=\"" + nick + "\"").c_str();

    int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error deleting data (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }

  int GestorBD::insertNewUser(string nick, string contra, string nombre, string apellido, int edad, bool bloq) 
  {
    sqlite3_stmt *stmt;

    char sql[] = "insert into usuario (nick, contra, nombre, apellido, edad, bloq) values (?, ?, ?, ?, ?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 1, nick.c_str(), nick.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, contra.c_str(), contra.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 3, nombre.c_str(), nombre.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 4, apellido.c_str(), apellido.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_int(stmt, 5, edad);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }
    if(bloq) result = sqlite3_bind_int(stmt, 6, 1);
    else result = sqlite3_bind_int(stmt, 6, 0);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into usuario table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }
  int GestorBD::insertNewAdmins(string nick, string contra, string nombre, string apellido, int edad, string cod_administrador){
    sqlite3_stmt *stmt;

    char sql[] = "insert into administrador (nick, contra, nombre, apellido, edad, cod_administrador) values (?, ?, ?, ?, ?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 1, nick.c_str(), nick.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, contra.c_str(), contra.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 3, nombre.c_str(), nombre.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 4, apellido.c_str(), apellido.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_int(stmt, 5, edad);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 6, cod_administrador.c_str(), cod_administrador.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into usuario table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }

  int GestorBD::insertNewJuegos(string nick, string nombre, string genero, string ejecutable, int precio)
  {
    sqlite3_stmt *stmt;

    char sql[] = "insert into juego (nick, nombre, genero, ejecutable, precio) values (?, ?, ?, ?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 1, nick.c_str(), nick.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, nombre.c_str(), nombre.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 3, genero.c_str(), genero.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 4, ejecutable.c_str(), ejecutable.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_int(stmt, 5, precio);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into usuario table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }

  int GestorBD::insertNewPartidas(string nick, string nombre, int PartidasJugadas)
  {
    sqlite3_stmt *stmt;

    char sql[] = "insert into partida (nick, nombre, PartidasJugadas) values (?, ?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 1, nick.c_str(), nick.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, nombre.c_str(), nombre.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_int(stmt, 3, PartidasJugadas);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into usuario table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }

  int GestorBD::insertNewPAhorcado(string nick, string nombre, int PartidasJugadas, int PartidasGanadas)
  {
    sqlite3_stmt *stmt;

    char sql[] = "insert into pAhorcado (nick, nombre, PartidasJugadas, PartidasGanadas) values (?, ?, ?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 1, nick.c_str(), nick.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, nombre.c_str(), nombre.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_int(stmt, 3, PartidasJugadas);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_int(stmt, 4, PartidasGanadas);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into usuario table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }

  int GestorBD::insertNewPCalc(string nick, string nombre, int PartidasJugadas, int PuntMax)
  {
    sqlite3_stmt *stmt;

    char sql[] = "insert into pCalc (nick, nombre, PartidasJugadas, PuntMax) values (?, ?, ?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (INSERT)" << std::endl;

    result = sqlite3_bind_text(stmt, 1, nick.c_str(), nick.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, nombre.c_str(), nombre.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_int(stmt, 3, PartidasJugadas);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_int(stmt, 4, PuntMax);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into usuario table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
  }