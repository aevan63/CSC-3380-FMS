//Written by Jackie Bowers

#include "BuildHTML.h"
#include <iostream>

using namespace std;
BuildHTML::BuildHTML(const multimap<string, string>& gets, const string requestUri, std::string website) {
	string   currentLine;
	ifstream preFile;
	ostringstream htmlStream;
	uri = requestUri;
	tr1::regex r(website+"(.*)");
	string re = "";
	uri = tr1::regex_replace(uri,r,re);
	preFile.open(uri);
	if (preFile.is_open()) {
		while(getline(preFile,currentLine)) {
			htmlStream << currentLine;
		}
	}
	html = htmlStream.str();
	insertNum = -1;
	HTMLdoc = htmlReadMemory((char*)html.c_str(), sizeof((char*)html.c_str()), uri.c_str(), "UTF-8", HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
}

BuildHTML::BuildHTML(const multimap<string, string>& gets, const string requestUri, MYSQL_ROW* RES, int numRows, int* numFields, std::string website, string feedbackForm) {
	string   currentLine;
	string   insert;
	ostringstream htmlStream;
    GETdata = gets;
	uri = requestUri;
	tr1::regex r(website+"(.*)");
	string re = "";
	multimap<string, string>::iterator it;
	uri = tr1::regex_replace(uri,r,re);
	ifstream preFile;
	preFile.open(uri);
	if (preFile.is_open()) {
			while(getline(preFile,currentLine)) {
				htmlStream << currentLine;
			}
	}
	html = htmlStream.str();

	/*while (preFile >> currentLine) {
		workingFile = workingFile+currentLine;
	}*/
	// string lines = RES;
	HTMLdoc = htmlReadMemory((char*)html.c_str(), sizeof((char*)html.c_str()), uri.c_str(), "UTF-8", HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
	htmlNodePtr root = xmlDocGetRootElement(HTMLdoc);
	xmlChar** insertStrings = buildFromSQL(RES, numRows, numFields);
	htmlNodePtr insertLocation;

	it = GETdata.find(feedbackForm);
	string feedback = it->second;
	insertLocation = findInsert(root, feedback);
	performInsert(insertLocation, insertStrings);
}
void BuildHTML::performInsert(htmlNodePtr sibling, xmlChar** newNodes) {
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

htmlNodePtr BuildHTML::findInsert(htmlNodePtr root, string matchName) {
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


xmlChar** BuildHTML::buildFromSQL(MYSQL_ROW* stringRes, int numRows, int* numFields) {
	ostringstream tmpStream;
	xmlChar* tempString;
    xmlChar* htmlRes[numRows];
    htmlDocPtr tmpDoc;
    insertNum = numRows;
	for (int i = 0; i < numRows; ++i) {
		tempString = new xmlChar[(sizeof(stringRes[i])+10)/sizeof(stringRes[i][0])];
		for(int j = 0; j < numFields[i]; ++j) {
			tmpStream << stringRes[i][j];
		}
		htmlRes[i] = tempString;
	    delete[] tempString;
	}
	tempString = (xmlChar*)tmpStream.str().c_str();
	return htmlRes;
}

htmlDocPtr BuildHTML::getHtml() {
	return HTMLdoc;
}

string BuildHTML::geturi() {
	return uri;
}
