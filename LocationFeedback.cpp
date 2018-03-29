// Written by Christian Lashover

#include <string>
#include "LocationFeedback.h"
using namespace std;

LocationFeedback::LocationFeedback() {
    text = email = phone = tag = location = service = employee = "";
}

LocationFeedback::LocationFeedback(const string* fields) {
    text = fields[0];
    email = fields[1];
    phone = fields[2];
    tag = fields[3];
    location = fields[4];
    service = fields[5];
    employee = fields[6];
}
