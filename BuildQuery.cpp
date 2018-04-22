// Written by Christian Lashover

#include <sstream>
#include "BuildQuery.h"
using namespace std;

void BuildQuery::formToSQL() {
    ostringstream query;
    bool isLocation = true, isComplaint = true; // Temporary values
    if (GETData.size()) {
        query << "select UserText, Name, Email, Phone, Tag, "
              << ((isLocation) ? "Location, Service, Employee " : "Product ")
              << "from "
              << ((isLocation) ? "LocationFeedback " : "ProductFeedback ")
              << "where IsComlpaint="
              << ((isComplaint) ? "true" : "false")
              << ";";
    }
    
    if (POSTData.size()) {
        query << "insert into "
              << ((isLocation) ? "LocationFeedback " : "ProductFeedback ")
              << "(UserText, Name, Email"
              << ((POSTData.find("inPhone") != POSTData.end()) ? ", Phone" : "");
        if (isLocation) {
            query << ", Location"
                  << ((POSTData.find("inService") != POSTData.end()) ? ", Service" : "")
                  << ((POSTData.find("inEmployee") != POSTData.end()) ? ", Employee" : "");
        }
        else
            query << ", Product";
        query << ", IsComplaint"
              << ")" << "values (";
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
        if (isLocation) {
            it = POSTData.find("inLocation");
            query << ", '" << it->second << "'";
            it = POSTData.find("inService");
            if (it != POSTData.end())
                query << ", '" << it->second << "'";
            it = POSTData.find("inEmployee");
            if (it != POSTData.end())
                query << ", '" << it->second << "'";
        }
        else {
            it = POSTData.find("inProduct");
            query << ", '" << it->second << "'";
        }
        if (isComplaint)
            query << ", true";
        else
            query << ", false";
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
