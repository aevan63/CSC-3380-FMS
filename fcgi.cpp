//queries an sql database with requests from a webserver with fastcgi
//probably doesnt work yet

#include <iostream>
#include <fastcgi++/request.hpp> // from https://github.com/eddic/fastcgipp
#include <fastcgi++/manager.hpp>
#include <mysql.h> // from MariaDB's website

using namespace std;

class Queries: public Fastcgipp::Request<char> {

	//with the fastcgi++ library the response method of any request class
	//seems to be called automatically when it is needed by the manager
	bool response() {
		using Fastcgipp::Encoding;

		//
		MYSQL_RES* result = getQuery();
		 out << "Content-type: text/html\r\n"
		 << "\r\n"
		 << "<html>\n"
		 << "  <head>\n"
		 << "    <title>Hello, World!</title>\n"
		 << "  </head>\n"
		 << "  <body>\n"
		 << "    <h1>" + *result + "</h1>\n"
		 << "  </body>\n"
		 << "</html>\n";

		 return true;
	}
	MYSQL_RES* getQuery() {

		// variables for connecting to the database; note that the username and password are associated with the database
		// To Do: these should be set in a config file; database password should be elsewhere not in plaintext;
		char* user = "testuser";
	    char* password = "";
		char* mySqlSock = "/tmp/mysql/sock";
		char* db = "";
		char* query;

		// connect to the database
		MYSQL* conn = mysql_init ( NULL );
		mysql_real_connect ( conn, "localhost", user, password, db, 0, mySqlSock , 0);

		// several different kinds of queries we will have to choose between
		// based on the data supplied by the request
		// To Do: build all the query factories
	    query = queryFactory.ask(environment().posts);

	    // actually perform the query, save the result
	    MYSQL_RES* result = mysql_real_query(conn, query, strlen((const char*) query));

	    // pretty sure we gotta remember to close the connection to the database before we can return
	    mysql_close(conn);
	    return result;
	}
}

int main( int argc, char *argv[]) {
	Fastcgipp::Manager<Queries> manager;
	manager.setupSignals();
	manager.listen();
	manager.start();
	manager.join();
    return 0;
}
