#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include "GestorBD.h"

GestorBD::GestorBD(string dbFile) 
{
    //int result = sqlite3_open("test.sqlite", &db);
    int result = sqlite3_open(dbFile.c_str(), &db);
    if (result != SQLITE_OK) 
    {
      std::cout << "Error opening database" << std::endl;
    }
    // Crate table country
    char sql[] = "CREATE TABLE usuario(nick TEXT, contra TEXT, nombre TEXT, apellido TEXT, edad INT);";
    result = sqlite3_exec(db, sql, 0, 0, NULL);

    if (result != SQLITE_OK) {
      std::cout << "Error executing CREATE" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;    
    }
    
  }
  
  GestorBD::~GestorBD() {
    int result = sqlite3_close(db);
    if (result != SQLITE_OK) {
      std::cout << "Error closing database" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
    }	
  }

  int GestorBD::dropTable() {
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

  int GestorBD::showAllUsers() {
    sqlite3_stmt *stmt;

    char sql[] = "select nick, contra, nombre, apellido, edad from usuario";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (SELECT)" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (SELECT)" << std::endl;

    char nick[100];
    char contra[100];
    char nombre[100];
    char apellido[100];
    int edad;


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Showing usuarios" << std::endl;

    do {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) {
    strcpy(nick, (char *) sqlite3_column_text(stmt, 0));
    strcpy(contra, (char *) sqlite3_column_text(stmt, 0));
    strcpy(nombre, (char *) sqlite3_column_text(stmt, 0));
    strcpy(apellido, (char *) sqlite3_column_text(stmt, 0));
    edad = sqlite3_column_int(stmt, 4);

	std::cout << "nick: " << nick << " contra: " << contra << " nombre: " << nombre << " apellido: " << apellido << " edad: " << edad <<std::endl;
      }
    } while (result == SQLITE_ROW);

    std::cout << std::endl;
    std::cout << std::endl;

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (SELECT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (SELECT)" << std::endl;

    return SQLITE_OK;
  }

  int GestorBD::deleteAllUsers() {
    sqlite3_stmt *stmt;

    char sql[] = "delete from usuario";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (DELETE)" << std::endl;

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

    std::cout << "Prepared statement finalized (DELETE)" << std::endl;

    return SQLITE_OK;
  }

  int GestorBD::insertNewUser(string nick, string contra, string nombre, string apellido, int edad) {
    sqlite3_stmt *stmt;

    char sql[] = "insert into usuario (nick, contra, nombre, apellido, edad) values (?, ?, ?, ?, ?)";
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

    std::cout << "Prepared statement finalized (INSERT)" << std::endl;

    return SQLITE_OK;
  }
