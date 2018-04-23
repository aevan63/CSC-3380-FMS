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
#include "BuildQuery.h"


class BuildResponse: public Fastcgipp::Request<char> {
	using Fastcgipp::Encoding;
	//with the fastcgi++ library the response method of any request class
	//seems to be called automatically when it is needed by the manager
	bool response() {
		string website = "FMS.com"; //placeholder, ofc.
		MariaDB sqlObj = MariaDB();
        BuildQuery queryizer = BuildQuery(environment().gets, environment().posts);
		sqlObj.query(queryizer.getQuery());
	    BuildHTML page = BuildHTML(environment().gets, environment().requestUri(), sqlObj.stringRES(), sqlObj.numRows, sqlObj.getNumFields(), website, "productFeedbackForm");

	        // out sends page to server w/ fastcgi++
	    out << page.getHtml();

	    sqlObj.close();
		return true;
	}
};

int main( int argc, char *argv[]) {
         Fastcgipp::Manager<BuildResponse> manager;
         manager.setupSignals();
         manager.listen();
         manager.start();
         manager.join();
         return 0;
}
