// Written by Christian Lashover and Jackie Bowers

#include <cstring>
#include "MariaDB.h"
#include "MariaDBInitializer.h"
using namespace std;


MariaDBException::MariaDBException(string message) {
    this->message = message;
}

MariaDB::MariaDB() throw (MariaDBException) {
    MariaDBInitializer init = MariaDBInitializer();
    try {
        conn = init.connect();
    }
    catch (ConnectionError& c) {
        throw MariaDBException(c.getError());
    }
}

void MariaDB::query(string query) throw (MariaDBException) {
    int state = mysql_real_query(conn, query.c_str(), strlen(query.c_str()));
    /*if (state)
     throw MariaDBException("Query " + query + " failed");*/
    queryResult = mysql_store_result(conn);
    if (!queryResult)
        numRows = mysql_affected_rows(conn);
    else
        numRows = mysql_num_rows(queryResult);
}

void MariaDB::close() {
    mysql_free_result(queryResult);
    mysql_close(conn);
}

MYSQL_ROW* MariaDB::stringRES() {
    MYSQL_ROW row;
    int numFields = mysql_num_fields(queryResult);
    MYSQL_ROW* rows = new MYSQL_ROW[numRows];
    while (row = mysql_fetch_row(queryResult) {
        for (int i = 0; i < numFields; ++i) {
            rows[i] = row;
        }
    }
    return rows;
}

int* MariaDB::getNumFields() {
    int numFields[numRows];
    for (int i = 0; i < numRows; i++) {
        numFields[i] = mysql_num_fields(queryResult);
    }
    return numFields;
}

int MariaDB::getNumRows() {
    return numRows;
}
