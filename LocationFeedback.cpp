// Written by Christian Lashover

#include "LocationFeedback.h"
#include "Feedback.h"
#include <string>
using namespace std;

void LocationFeedback::setSpecificFields(string* fields) {
    location = fields[0];
    service = fields[1];
    employee = fields[2];
}

LocationFeedback::LocationFeedback() : Feedback() {
    location = service = employee = "";
}

LocationFeedback::LocationFeedback(string text, string email, string phone, string location, string service, string employee) :
Feedback(text, email, phone) {
    string* fields = new string[3];
    fields[0] = location;
    fields[1] = service;
    fields[2] = employee;
    setSpecificFields(fields);
    delete [] fields;
}
