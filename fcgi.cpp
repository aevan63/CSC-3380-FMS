// Written by Jackie Bowers
//queries an sql database with requests from a webserver with fastcgi and returns an html page to the server

#include <iostream>
#include <fstream>
#include <map>
#include <fastcgi++/request.hpp> // from https://github.com/eddic/fastcgipp
#include <fastcgi++/http.hpp>
#include <mysql.h> // from MariaDB's website
#include "MariaDBInitializer.h"
#include "MariaDB.h"
#include "BuildQuery.h"
#include "BuildHTML.h"


class BuildResponse: public Fastcgipp::Request<char> {
	//with the fastcgi++ library the response method of any request class
	//seems to be called automatically when it is needed by the manager
public:
	BuildResponse():
		//pass max post size to request
		Fastcgipp::Request<char>(std::numeric_limits<size_t>::max())
		{}
private:
	bool response() {
		// using Fastcgipp::Encoding;
		std::string website = "FMS.com"; //placeholder, ofc.
		std::string formName = "productFeedbackForm";
		MariaDB sqlObj = MariaDB();
        BuildQuery queryizer = BuildQuery(environment().gets, environment().posts);
		sqlObj.query(queryizer.getQuery());
		BuildHTML page;
		if (environment().posts.size()) {
			 // page = BuildHTML(environment().posts);
			 out << "<!DOCTYPE html><html><head>";
			 out << "<title>This Is a Website</title>";
			 out << "<script></script>";
			 out << "<link rel=\"stylesheet\" type=\"text/css\" href=\"websiteStyle.css\" />";
			 out << "<head><body><div id=\"background\">";
			 out << "<div id=\"topHeader\"><div id=\"websiteName\">";
			 out << "<h1 style=\"font-size:8vw\">GRANT'S GIZMOS</h1>";
			 out << "</div><div id=\"subtitle\">";
			 out << "<h2 style=\"font-size:3vw\">Are YOU Gonna Need It?</h2></div></div>";
			 out << "<div id=\"innerBody\"><div id=\"navigation\">";
			 out << "<ul style=\"font-size:2vw\">";
			 out << "<li><a href=\"homepg.html\">Home</a></li>";
			 out << "<li><a class=\"active\" href=\"shoppg.html\">Shop</a></li>";
			 out << "<li><a href=\"contactpg.html\">Contact</a></li>";
			 out << "<li><a href=\"aboutpg.html\">About</a></li></ul></div>";
			 out << "<div id=\"main\"><h2>Your feedback has been recieved!</h2>;";
			 multimap<string, string> Postdata = environment().posts;
			 for (multimap<string, string>::iterator it = Postdata.begin(); it!=Postdata.end();++it) {
			    	out << "<h2>" << it->first << ":</h2>";
			    	out << "<h2>" << it->second << ":</h2>";
			    }
			 out << "</div></body></html>";
		     return true;
		}
		else {
			 page = BuildHTML(environment().gets, environment().requestUri, sqlObj.stringRES(), sqlObj.numRows, sqlObj.getNumFields(), website, formName);
		}

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
