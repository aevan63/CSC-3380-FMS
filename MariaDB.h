// Written by Christian Lashover and Jackie Bowers

#ifndef MARIADB_H
#define MARIADB_H
#include <string>
#include <mysql.h>
using namespace std;

class MariaDB {
private:
    MYSQL* conn;
    MYSQL_RES* queryResult;
    int state;
public:
    MariaDB();
    void query(string);
    void close();
    MYSQL_ROW* stringRES(MYSQL_RES*& result);
};

#endif
