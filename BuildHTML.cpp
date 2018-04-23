//Written by Jackie Bowers

#include "BuildHTML.h"
#include <iostream>

using namespace std;
buildHTML::buildHTML(const Fastcgipp::Http::Environment& environment(), std::string website) {
	string   currentLine;
	ifstream preFile;
	uri = (std::string)environment().requestUri;
	tr1::regex r(website+"(.*)");
	string re = "";
	uri = tr1::regex_replace(uri,r,re);
	preFile.open(uri);
	if (preFile.is_open()) {
		while(getline(preFile,currentLine)) {
			html << currentLine;
		}
	}

	insertNum = -1;
	HTMLdoc = htmlReadMemory((char*)html.c_str(), sizeof((char*)html.c_str()), uri.c_str(), "UTF-8", HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
}

buildHTML::buildHTML(MYSQL_ROW* RES, int numRows, int* numFields, const Fastcgipp::Http::Environment& environment(), std::string website, string feedbackForm) {
	string   currentLine;
	string   insert;

	uri = environment().requestUri;
	tr1::regex r(website+"(.*)");
	string re = "";
	uri = tr1::regex_replace(uri,r,re);
	ifstream preFile;
	preFile.open(uri);
	if (preFile.is_open()) {
			while(getline(preFile,currentLine)) {
				html << currentLine;
			}
	}
	/*while (preFile >> currentLine) {
		workingFile = workingFile+currentLine;
	}*/
	// string lines = RES;
	HTMLdoc = htmlReadMemory((char*)html.c_str(), sizeof((char*)html.c_str()), uri.c_str(), "UTF-8", HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
	htmlNodePtr root = xmlDocGetRootElement(HTMLdoc);
	xmlChar** insertStrings = buildFromSQL(RES, numRows, numFields);
	htmlNodePtr insertLocation;


	tr1::regex Feedback = ("(.*)"+feedbackForm+"(.*)");
	if (tr1::regex_match(environment().gets, Feedback)) {
		insertLocation = findInsert(root, feedbackForm);
		performInsert(insertLocation, insertStrings);
	}
}
void buildHTML::performInsert(htmlNodePtr sibling, xmlChar** newNodes) {
	xmlChar* tmpStr;
	char* encoding = "UTF-8";
	// htmlDocPtr tmpDoc;
	htmlNodePtr newNode;
	htmlNodePtr newChildNode;
	int length;
	for (int i = 0; i < insertNum; ++i) {
		tmpStr = newNodes[i];
		//tmpDoc = htmlReadMemory((char*)tmpStr, sizeof((char*)tmpStr), NULL, encoding, 0);
	    //newNode = xmlDocCopyNode(xmlDocGetRootElement(tmpDoc), parent->doc,1);
		// xmlFreeDoc(tmpDoc);
		newNode = xmlNewNode(0, BAD_CAST "p");
		newChildNode = xmlNewText( BAD_CAST tmpStr);
		xmlAddChild(newNode, newChildNode);
		xmlAddPrevSibling(sibling, newNode);
	}
}

htmlNodePtr buildHTML::findInsert(htmlNodePtr root, string matchName) {
	htmlNodePtr tmpNode = root;
	while(tmpNode != NULL) {
		if(!xmlStrcmp(tmpNode->name, (const xmlChar*)matchName.c_str())) {
			return tmpNode;
		}
		tmpNode = tmpNode->next;
	}
	if (tmpNode->children == NULL) {
		return nullptr;
	}
	return (findInsert(tmpNode->children, matchName));
}


xmlChar** buildHTML::buildFromSQL(MYSQL_ROW* stringRes, int numRows, int* numFields) {
	xmlChar* tempString;
    xmlChar* htmlRes[numRows];
    htmlDocPtr tmpDoc;
    insertNum = numRows;
	for (int i = 0; i < numRows; ++i) {
		tempString = new xmlChar[(sizeof(stringRes[i])+10)/sizeof(stringRes[i][0])];
		for(int j = 0; j < numFields[i]; ++j) {
			tempString += stringRes[i][j];
		}
		htmlRes[i] = tempString;
	    delete[] tempString;
	}
	return htmlRes;
}

htmlDocPtr buildHTML::getHtml() {
	return HTMLdoc;
}

string buildHTML::geturi() {
	return uri;
}
