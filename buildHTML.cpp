//Written by Jackie Bowers

#include "buildHTML.h"
#include <iostream>

using namespace std;
buildHTML::buildHTML(const Fastcgipp::Http::Environment& environment()) {
	string line;
	ifstream file;
	file.open(uri);
	if (file.is_open()) {
		while(getline(file,line)) {
			html << line;
		}
	}

}

buildHTML::buildHTML(MYSQL_ROW* stringRES, const Fastcgipp::Http::Environment& environment(), std::string website) {
	this->website =  website+"(.*)";
	uri = tr1::regex_replace(environment().requestUri,this->website,"");
	string line;
	ifstream file;
	file.open(uri);
	if (file.is_open()) {
		while(getline(file,line)) {
			html << line;
		}
	}
}

string buildHTML::fixHTML(string* stringRes) {
	tr1::regex tempR;
	std::basic_string tempS;
	for (int i = 0;i<sizeof(parameters);++i) {
		tempR(uri);
		if (tr1::regex_match(parameters[i], tempR)) {
			++i;
			tempR("(locator = )(.*)");
			if(regex_match(parameters[i],tempR)) {
				tempS = parameters[i];
				tr1::regex_replace(tempS,tempR,"");
				break;
			}
		}
	}
	tr1::regex locator(tempS);
	//obviously needs to be more complicated than just using the first row of the returned values
	tr1::regex_replace(html,locator,stringRes[0]);
	return html;
}

string buildHTML::getHtml() {
	return html;
}

string buildHTML::geturi() {
	return uri;
}

