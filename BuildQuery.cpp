// Written by Christian Lashover

#include <sstream>
#include "BuildQuery.h"
using namespace std;

void BuildQuery::formToSQL() {
    ostringstream query;
    bool isLocation, isComplaint;
    multimap<string, string>::iterator it;
    
    if (GETData.size()) {
        it = GETData.find("feedback");
        if (it->second == "Location Complaint") {
            isComplaint = true;
            isLocation = true;
        }
        else if (it->second == "Location Compliment") {
            isComplaint = false;
            isLocation = true;
        }
        else if (it->second == "Product Complaint") {
            isComplaint = true;
            isLocation = false;
        }
        else {
            isComplaint = false;
            isLocation = false;
        }
        
        query << "select ID, UserText, Name, Email, Phone, Tag, "
              << ((isLocation) ? "Location, Service, Employee " : "Product ")
              << "from "
              << ((isLocation) ? "LocationFeedback " : "ProductFeedback ")
              << "where IsComlpaint="
              << ((isComplaint) ? "true" : "false");
        it = GETData.find("inTag");
        if (it != GETData.end())
            query << " and Tag='" << it->second << "'";
        query << ";";
    }
    
    else if (POSTData.size()) {
        if (POSTData.find("good-or-bad")->second == "Complaint")
            isComplaint = true;
        else
            isComplaint = false;
        if (POSTData.find("inLocation") != POSTData.end())
            isLocation = true;
        else
            isLocation = false;
        
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
              << ") " << "values (";
        
        it = POSTData.find("inText"); // Name needs to change in HTML or here
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

BuildQuery::BuildQuery(const multimap<string, string>& GETData, const multimap<string, string>& POSTData) {
    this->GETData = GETData;
    this->POSTData = POSTData;
    formToSQL();
}

string BuildQuery::getQuery() const {
    return constructedQuery;
}
