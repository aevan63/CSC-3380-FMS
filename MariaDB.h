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
    MYSQL_RES* queryResult;
public:
    int numRows;
    MariaDB() throw (MariaDBException);
    void query(string) throw (MariaDBException);
    void close();
    MYSQL_ROW* stringRES() const;
};

#endif
