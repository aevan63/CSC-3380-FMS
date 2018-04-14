// Written by Christian Lashover and Jackie Bowers

#include "MariaDB.h"
#include "MariaDBInitializer.h"
using namespace std;

MariaDB::MariaDB() {
    MariaDBInitializer init = MariaDBInitializer();
    conn = init.connect();
}

void MariaDB::query(string query) {
    state = mysql_real_query(conn, query.c_str(), query.length());
    queryResult = mysql_store_result(conn);
}

void MariaDB::close() {
    mysql_close(conn);
}

MYSQL_ROW* MariaDB::stringRES() {
	MYSQL_ROW row;
	int numRows = mysql_num_rows(queryResult);
	MYSQL_ROW* rows = new MYSQL_ROW[numRows];

	for (unsigned int i = 0; i<numRows; ++i) {
		unsigned long *lengths;
		lengths = mysql_fetch_lengths(queryResult);
		for(unsigned int j=0; j < mysql_num_fields(queryResult); ++j) {
			rows[i][j] = row[j];
            //for now lets also have it print for testing
			printf("[%.*s] ", (int) lengths[j],
				row[j] ? row[j] : "NULL");			
		}
		printf("\n");
	}
	return rows;
}
