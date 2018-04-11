// Written by Christian Lashover

#ifndef MARIADBINITIALIZER_H
#define MARIADBINITIALIZER_H
#include <fstream>
#include <mysql.h>
using namespace std;

class MariaDBInitializer {
private:
    MYSQL* conn;
    const char* host = "localhost";
    const char* user;
    const char* password;
    const char* database;
    unsigned int port;
    const char* sock;
    fstream configFile;
public:
    MariaDBInitializer();
    MYSQL* connect(MYSQL*);
};

#endif
