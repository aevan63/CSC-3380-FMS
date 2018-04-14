// Written by Christian Lashover

#include <mysql.h>
#include "MariaDBInitializer.h"
using namespace std;

MariaDBInitializer::MariaDBInitializer() {
    conn = mysql_init(0);
}

MYSQL* MariaDBInitializer::connect() {
    conn = mysql_real_connect(conn, host, user, password, database, port, sock, 0);
    return conn;
}
