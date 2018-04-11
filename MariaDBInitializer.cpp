// Written by Christian Lashover

#include <fstream>
#include <mysql.h>
using namespace std;

MariaDBInitializer::MariaDBInitializer() {
    conn = mysql_init(NULL);
}

MYSQL* MariaDBInitializer::connect(MYSQL* conn) {
    // Need code to read config file and set config parameters
    // ...
    
    conn = mysql_real_connect(conn, host, user, password, database, port, sock, 0);
    return conn;
}
