// Written by Christian Lashover

#include <sstream>
#include "BuildQuery.h"
using namespace std;

void BuildQuery::formToSQL() {
    ostringstream query;
    if (GETData.size()) {
        // Do stuff
    }
    
    if (POSTData.size()) {
        query << "insert into Feedback (UserText, Name, Email"
              << ((POSTData.find("inPhone") != POSTData.end()) ? ", Phone" : "")
              << ((POSTData.find("inProduct") != POSTData.end()) ? ", Product" : "")
              << ((POSTData.find("inLocation") != POSTData.end()) ? ", Location" : "")
              << ((POSTData.find("inService") != POSTData.end()) ? ", Service" : "")
              << ((POSTData.find("inEmployee") != POSTData.end()) ? ", Employee" : "")
              << ")" << "values (";
        string inText, inName, inEmail;
        map<string, string>::iterator it;
        it = POSTData.find("inText");
        query << "'" << it->second << "', ";
        it = POSTData.find("inName");
        query << "'" << it->second << "', ";
        it = POSTData.find("inEmail");
        query << "'" << it->second << "'";
        it = POSTData.find("inPhone");
        if (it != POSTData.end())
            query << ", '" << it->second << "'";
        it = POSTData.find("inProduct");
        if (it != POSTData.end())
            query << ", '" << it->second << "'";
        it = POSTData.find("inLocation");
        if (it != POSTData.end())
            query << ", '" << it->second << "'";
        it = POSTData.find("inService");
        if (it != POSTData.end())
            query << ", '" << it->second << "'";
        it = POSTData.find("inEmployee");
        if (it != POSTData.end())
            query << ", '" << it->second << "'";
        query << ");";
    }
    constructedQuery = query.str();
}

// This isn't the final constructor
BuildQuery::BuildQuery(const multimap<string, string>& GETData, const multimap<string, string>& POSTData) {
    this->GETData = GETData;
    this->POSTData = POSTData;
    formToSQL();
}

string BuildQuery::getQuery() const {
    return constructedQuery;
}
