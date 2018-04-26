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
		//BuildHTML page;
		if (environment().posts.size()) {
			 // page = BuildHTML(environment().posts);
			 out << "Content-Type: text/html; charset=utf-8\r\n\r\n";
			 out << "<html><head>";
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
			out << "Content-Type: text/html; charset=utf-8\r\n\r\n";
		        out << "<html lang=\"en\">";
                        out << "<head><title>Employee Page</title>";
	                out << "<link rel=\"stylesheet\" type=\"text/css\" href=\"Style.css\">";
                        out << "<meta charset=\"UTF-8\">";
                        out << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
                        out << "</head><body><div class=\"header\">";
                        out << "<h1>Feedback Management System</h1>";
                        out << "<h2>Welcome, Employees!</h2>";
                        out << "</div><div class=\"navbar\">";
                        out << "<!--<a href=\"#\" target=\"_blank\">Extra Link</a>-->";
                        out << "<a href=\"https://github.com/aevan63/CSC-3380-FMS\" target=\"_blank\">GitHub</a>";
                        out << "<!--<a href=\"#\">Extra Link</a>--></div>";
			 //page = BuildHTML(environment().gets, environment().requestUri, sqlObj.stringRES(), sqlObj.getNumRows(), sqlObj.getNumFields(), website, formName);
	                out << "<div class=\"main\">";
                        out << "<h2>Feedback Processing</h2>";
                        out << "<h5>Select a feedback type to begin.</h5>";
	                out << "<form action=\"backend.fcgi\" method=\"GET\" name=\"FeedQuery\">";
	                out << "<input list=\"feedback\" name=\"feedback\" placeholder=\"Select Feedback Type\" required>";
                        out << "<datalist id=\"feedback\"><option value=\"Location Compliment\">";
                        out << "<option value=\"Location Complaint\">";
                        out << "<option value=\"Product Compliment\">";
                        out << "<option value=\"Product Complaint\">";
                        out << "</datalist><br><br>";
			out << "<input type=\"text\" name=\"tag\" placeholder=\"Insert tag (optional)\"><br><br>";
                        out << "<input type=\"submit\" value=\"Search\">";
	                out << "</form></div>";
			out << "<h5>List of open feedback matching ";
			multimap<string, string>Getdata = environment().gets;
			for (multimap<string, string>::iterator it = Getdata.begin(); it!=Getdata.end();++it) {
			    	out << "<h2>" << it->second << ":</h2>";
			}
			MYSQL_ROW* rows = sqlObj.stringRES();
			for (int i = 0; i < sqlObj.getNumRows(); ++i) {
				for (int j = 0; j < sqlObj.getNumFields(); ++j) {
					out << "<h1>" << rows[i][j]<< "</h1>";
				}
			}
			out << "</div></html>";
				
		}

	        // out sends page to server w/ fastcgi++
	    //out << page.getHtml();

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
