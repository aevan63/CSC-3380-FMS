// Written by Jackie Bowers
//queries an sql database with requests from a webserver with fastcgi
//probably doesnt work yet

#include <iostream>
#include <fastcgi++/request.hpp> // from https://github.com/eddic/fastcgipp
#include <fastcgi++/manager.hpp>
#include <mysql.h> // from MariaDB's website
#include <sstream>
#include "MariaDBInitializer.h"

using namespace std;

class Queries: public Fastcgipp::Request<char> {

	//with the fastcgi++ library the response method of any request class
	//seems to be called automatically when it is needed by the manager
	bool response() {
	        using Fastcgipp::Encoding;
       	        MYSQL_RES* result = getQuery();
       	        MYSQL_ROW stringRes = stringRES(result);

		// just using 'out' should send this to the webserver to send to the client. thanks again fastcgi++
		out << "Content-type: text/html\r\n"
	        << "\r\n"
	        << "<html>\n"
	        << "  <head>\n"
	        << "    <title>Hello, World!</title>\n"
	        << "  </head>\n"
		    << "  <body>\n"
	        << "    <h1>" << stringRes[0] << "</h1>\n"
	        << "  </body>\n"
	        << "</html>\n";

		return true;
	}
	MYSQL_ROW stringRES(MYSQL_RES*& result) {
		MYSQL_ROW row;

		while ((row = mysql_fetch_row(result))) {
			unsigned long *lengths;
			lengths = mysql_fetch_lengths(result);
			for(unsigned int i=0; i < mysql_num_fields(result); i++) {
				printf("[%.*s] ", (int) lengths[i],
						row[i] ? row[i] : "NULL");
			}
			printf("\n");
		}
		return row;
	}
	MYSQL_RES* getQuery() {

            // variables for connecting to the database;
			// this is now handled by MariaDBInitializer
	        // To Do: these should be set in a config file; database password should be elsewhere not in plaintext;
	        /*char* user = "testuser";
	        char* password = "";
            char* mySqlSock = "/tmp/mysql/sock";
	        char* db = ""; */
	        char* query;

	        // connect to the database
	        MariaDBInitializer init = MariaDBInitializer();
	        MYSQL* conn = init.connect();
	        if (0)
	        	throw "Connection failed!";
	        else
	        	cout <<"Connection successful\n";

	        // several different kinds of queries we will have to choose between
	        // based on the data supplied by the request
	        // To Do: build all the query factories
	        // To Do: needs dynamic field allocation to deal with tags
	        query = queryFactory.ask(environment().posts);

	        // actually perform the query, save the result
	        MYSQL_RES* result = mysql_real_query(conn, query, strlen((const char*) query));

	        // pretty sure we gotta remember to close the connection to the database before we can return
	        mysql_close(conn);
	        return result;
	}
};

int main( int argc, char *argv[]) {
         Fastcgipp::Manager<Queries> manager;
         manager.setupSignals();
         manager.listen();
         manager.start();
         manager.join();
         return 0;
}
