#include <iostream>
#include "gestorBD.h"

int main() {
  GestorBD dbConnector("test.sqlite");

  string a;
  int result;

 /* result = dbConnector.deleteAllUsers();
  cin >> a;
  if (result != SQLITE_OK) {
    std::cout << "Error deleting all users" << std::endl;
    return result;
  }*/

  result = dbConnector.insertNewUser("c","z","z","z", 0);
  result = dbConnector.insertNewAdmins("b", "q", "q", "q", 0, "q");
  result = dbConnector.insertNewJuegos("c", "j", "j", "j", 0);
  result = dbConnector.insertNewPartidas("b", "f", 0);
  result = dbConnector.insertNewPAhorcad("b", "f", 0, 0);
  result = dbConnector.insertNewPCalc("b", "f", 0, 0);

  cin >> a;
  if (result != SQLITE_OK) {
    std::cout << "Error inserting new data with id: 200. Already exists" << std::endl;
    return result;
  }
  dbConnector.returnAdministradores();
  dbConnector.returnJuegos();
  dbConnector.returnPartidas();
  dbConnector.returnPAhorcado();
  dbConnector.returnPCalc();
  result = dbConnector.showAllUsers();
  cin >> a;
  if (result != SQLITE_OK) {
    std::cout << "Error getting all users" << std::endl;
    return result;
  }

  /*
  result = dbConnector.dropTable();
  if (result != SQLITE_OK) {
    std::cout << "Error droping table" << std::endl;
    return result;
  }
  */

  return 0;
}