// Written by Christian Lashover

#include "LocationFeedback.h"
#include "LocationComplaint.h"
#include <string>
using namespace std;

LocationComplaint::LocationComplaint(string text, string email, string phone, string location, string service, string employee) :
LocationFeedback(text, email, phone, location, service, employee) {
    
};
