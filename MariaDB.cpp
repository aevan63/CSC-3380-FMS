// Written by Christian Lashover

#include "MariaDB.h"
#include "MariaDBInitializer.h"
using namespace std;

MariaDB::MariaDB() {
    MariaDBInitializer init = MariaDBInitializer();
    conn = init.connect();
}

void MariaDB::query(string query) {
    state = mysql_real_query(conn, query.c_str(), query.length());
}

void MariaDB::close() {
    mysql_close(conn);
}
