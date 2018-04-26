// Written by Jackie Bowers
//queries an sql database with requests from a webserver with fastcgi and returns an html page to the server

#include <iostream>
#include <fstream>
#include <fastcgi++/request.hpp> // from https://github.com/eddic/fastcgipp
#include <fastcgi++/http.hpp>
#include <mysql.h> // from MariaDB's website
#include "MariaDBInitializer.h"
#include "MariaDB.h"
#include "BuildQuery.h"
#include "BuildHTML.h"


class BuildResponse: public Fastcgipp::Request<wchar_t> {
	//with the fastcgi++ library the response method of any request class
	//seems to be called automatically when it is needed by the manager
public:
	BuildResponse():
		//pass max post size to request
		Fastcgipp::Request<wchar_t>(std::numeric_limits<size_t>::max())
		{}
private:
	bool response() {
		using Fastcgipp::Encoding;
		std::string website = "FMS.com"; //placeholder, ofc.
		std::string formName = "productFeedbackForm";
		MariaDB sqlObj = MariaDB();
        BuildQuery queryizer = BuildQuery(environment().gets, environment().posts);
		sqlObj.query(queryizer.getQuery());
	    BuildHTML page = BuildHTML(environment().gets, environment().requestUri, sqlObj.stringRES(), sqlObj.numRows, sqlObj.getNumFields(), website, formName);

	        // out sends page to server w/ fastcgi++
	    out << page.getHtml();

	    sqlObj.close();
		return true;
	}
};

#include <fastcgi++/manager.hpp>
int main() {
         Fastcgipp::Manager<BuildResponse> manager;
         manager.setupSignals();
         manager.listen();
         manager.start();
         manager.join();

         return 0;
}
