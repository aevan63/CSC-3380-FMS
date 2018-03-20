// Written by Christian Lashover

#include "LocationFeedback.h"
#include "LocationComplement.h"
#include <string>
using namespace std;

LocationComplement::LocationComplement(string text, string email, string phone, string location, string service, string employee) :
LocationFeedback(text, email, phone, location, service, employee) {
    
};
