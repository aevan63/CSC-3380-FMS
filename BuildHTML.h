//Written by Jackie Bowers

#ifndef GETHTML_H
#define GETHTML_H

#include <iostream>
#include <fstream>
#include <map>
#include <libxml/tree.h>
#include <libxml/HTMLparser.h>
#include <libxml/tree.h>
//#include <libxml++/libxml++.h>
#include <tr1/regex>
#include <mysql.h>
#include <fastcgi++/request.hpp>
#include <fastcgi++/http.hpp>
#include "LocationFeedback.h"
#include "ProductFeedback.h"


using namespace std;


class BuildHTML {
	private:
		string uri;
		string html;
		htmlDocPtr HTMLdoc;
		int insertNum;
		multimap<string, string> GETdata;

	public:
		BuildHTML(const string requestUri, std::string website);

		BuildHTML(const multimap<string, string>& gets, const string requestUri, MYSQL_ROW* stringRes,int numRows,int* numFields, std::string website, std::string feedbackForm);

		htmlNodePtr findInsert(htmlNodePtr root, string matchName);

		void performInsert(htmlNodePtr sibling, xmlChar** newNodes);

		xmlChar** buildFromSQL(MYSQL_ROW* stringRes, int numRows, int* numFields);

		htmlDocPtr getHtml();

		string geturi();
};
#endif
