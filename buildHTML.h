//Written by Jackie Bowers

#ifndef GETHTML_H
#define GETHTML_H

#include <iostream>
#include <fstream>
#include <tr1/regex>
#include <mysql.h>
#include <fastcgi++/request.hpp>
#include <fastcgi++/http.hpp>
#include "LocationFeedback.h"
#include "ProductFeedback.h"
std::string* parameters = configParse();
#endif

inline std::string* configParse(){
	ifstream config;
	config.open("FMS_Fcgi.conf");
	std::string* ruleList = new string[10]; //or something, prolly not 10 lol
	//do some stuff
	return ruleList;
}

using namespace std;
class buildHTML {
	private:
		tr1::regex website;
		string uri;
		string html;



	public:
		buildHTML(const Fastcgipp::Http::Environment& enviroment());
		buildHTML(MYSQL_ROW* stringRes, const Fastcgipp::Http::Environment& environment(), std::string website);
		string fixHTML(string* stringRes);
		string getHtml();
		string geturi();
};
