// Written by Jackie Bowers
//queries an sql database with requests from a webserver with fastcgi and returns an html page to the server

#include <iostream>
#include <fstream>
#include <fastcgi++/request.hpp> // from https://github.com/eddic/fastcgipp
#include <fastcgi++/manager.hpp>
#include <fastcgi++/http.hpp>
#include <mysql.h> // from MariaDB's website
#include "MariaDBInitializer.h"
#include "MariaDB.h"


class BuildResponse: public Fastcgipp::Request<char> {
	using Fastcgipp::Encoding;
	//with the fastcgi++ library the response method of any request class
	//seems to be called automatically when it is needed by the manager
	bool response() {
		string website = "FMS.com"; //placeholder, ofc.
		MariaDB sqlObj = MariaDB();
		sqlObj.query(BuildQuery(environment()));
	        buildHTML page = BuildHTML(sqlObj.stringRES(), environment(), website);

	        // out sends page to server w/ fastcgi++
	        out << page.fixHTML(page.buildFromSQL());

	        sqlObj.close();
		return true;
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
