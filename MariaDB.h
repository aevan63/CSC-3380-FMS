// Written by Christian Lashover and Jackie Bowers

#ifndef MARIADB_H
#define MARIADB_H
#include <string>
#include <mysql.h>
using namespace std;

class MariaDBException {
private:
    string message;
public:
    MariaDBException(string);
};

class MariaDB {
private:
    MYSQL* conn;
    int numRows;
public:
    MYSQL_RES* queryResult;
    int getNumRows();
    int* getNumFields();
    MariaDB() throw (MariaDBException);
    void query(string) throw (MariaDBException);
    void close();
    MYSQL_ROW* stringRES();
};

#endif
