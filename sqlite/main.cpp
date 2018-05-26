#include <iostream>
#include "gestorBD.h"

int main() {
  GestorBD dbConnector("test.sqlite");

  int result = dbConnector.deleteAllUsers();
    string a;
  cin >> a;
  if (result != SQLITE_OK) {
    std::cout << "Error deleting all users" << std::endl;
    return result;
  }

  result = dbConnector.insertNewUser("a","b","c","d", 0);

  cin >> a;
  if (result != SQLITE_OK) {
    std::cout << "Error inserting new data with id: 200. Already exists" << std::endl;
    return result;
  }

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