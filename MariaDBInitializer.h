// Written by Christian Lashover

#ifndef MARIADBINITIALIZER_H
#define MARIADBINITIALIZER_H
#include <string>
#include <mysql.h>
using namespace std;

class ConnectionError {
private:
    string message;
public:
    ConnectionError(string);
    string getError() const;
};

class MariaDBInitializer {
private:
    MYSQL* conn;
    const char* host = "";
    const char* user = "localhost";
    const char* password = "";
    const char* database = "testdb";
    unsigned int port = 15510;
    const char* sock = "/tmp/mysql/sock";
public:
    MariaDBInitializer();
    MYSQL* connect() throw (ConnectionError);
};

#endif
