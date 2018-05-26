#ifndef _GESTORBD_H_
#define _GESTORBD_H_

#include <string>
#include "sqlite3.h"

using namespace std;

class GestorBD
{
private:
	sqlite3 *db = NULL;
public:
	GestorBD(string dbFile);
	~GestorBD();

	int dropTable();
	int showAllUsers();
	int deleteAllUsers();
	int insertNewUser(string nick, string contra, string nombre, string apellido, int edad);

};

#endif