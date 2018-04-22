// Written by Christian Lashover

#include <string>
#include "LocationFeedback.h"
using namespace std;

LocationFeedback::LocationFeedback() {
    text = name = email = phone = tag = location = service = employee = "";
}

LocationFeedback::LocationFeedback(const string* fields) {
    text = fields[0];
    name = fields[1];
    email = fields[2];
    phone = fields[3];
    tag = fields[4];
    location = fields[5];
    service = fields[6];
    employee = fields[7];
}
