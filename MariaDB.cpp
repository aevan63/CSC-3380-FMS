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
}

void MariaDB::close() {
    mysql_close(conn);
}

MYSQL_ROW* MariaDB:: stringRES(MYSQL_RES*& result) {
	MYSQL_ROW row;
	MYSQL_ROW* rows = new MYSQL_ROW[mysql_num_rows(MYSQL_RES *result];
	unsigned int i = 0;
	while ((row = mysql_fetch_row(result))) {
		unsigned long *lengths;
		lengths = mysql_fetch_lengths(result);
		for(unsigned int j=0; j < mysql_num_fields(result); j++) {
			rows[i][j] = row[j];
            //for now lets also have it print for testing
			printf("[%.*s] ", (int) lengths[j],
				row[j] ? row[j] : "NULL");			
		}
		printf("\n");
		i++;
	}
	return rows;
}
