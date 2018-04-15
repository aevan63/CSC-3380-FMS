// Written by Christian Lashover

#include <mysql.h>
#include "MariaDBInitializer.h"
using namespace std;

MariaDBInitializer::MariaDBInitializer() {
    conn = mysql_init(0);
}

MYSQL* MariaDBInitializer::connect() throw (ConnectionError) {
    conn = mysql_real_connect(conn, host, user, password, database, port, sock, 0);
    if (!conn)
        throw ConnectionError("Error connecting to database.");
    return conn;
}

ConnectionError::ConnectionError(string message) {
    this->message = message;
}

string ConnectionError::getError() const {
    return message;
}
