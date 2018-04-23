//Written by Jackie Bowers

#ifndef GETHTML_H
#define GETHTML_H

#include <iostream>
#include <fstream>
#include <libxml/tree.h>
#include <libxml/HTMLparser.h>
#include <libxml/tree.h>
#include <libxml++/libxml++.h>
#include <tr1/regex>
#include <mysql.h>
#include <fastcgi++/request.hpp>
#include <fastcgi++/http.hpp>
#include "LocationFeedback.h"
#include "ProductFeedback.h"

#endif

using namespace std;


class buildHTML {
	private:
		string uri;
		string html;
		htmlDocPtr HTMLdoc;
		int insertNum;

	public:
		buildHTML(const Fastcgipp::Http::Environment& enviroment(), std::string website);

		buildHTML(MYSQL_ROW* stringRes,int numRows,int* numFields, const Fastcgipp::Http::Environment& environment(), std::string website, std::string feedbackForm);

		htmlNodePtr findInsert(htmlNodePtr root, string matchName);

		void performInsert(htmlNodePtr sibling, xmlChar** newNodes);

		xmlChar** buildFromSQL(MYSQL_ROW* stringRes, int numRows, int* numFields);

		htmlDocPtr getHtml();

		string geturi();
};
